/**
 * Handles response
 */

uses
	WikiText

namespace StatusCode 
	const FILE_NOT_FOUND : string = "HTTP/1.1 404 Not Found\n"
	const OK : string = "HTTP/1.1 200 OK\n"
	const ERROR : string = "HTTP/1.1 500 Internal Server Error\n"
	const AUTH_REQ : string = "HTTP/1.1 401 Unauthorized"


exception IOError 
	FILE_NOT_FOUND
	FILE_NO_READ_PERMISSION
	FILE_IS_LOCKED
    
class RequestHandler

	prop req : Request
	
	/* use xdd -i favicon.ico to generate */
	FaviconData : array of uchar = {
	  0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x10, 0x10, 0x02, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0xb0, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x28, 0x00,
	  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00,
	  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xee, 0x00, 0xff, 0xff,
	  0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xba, 0xab, 0x00, 0x00, 0x92, 0xab,
	  0x00, 0x00, 0xaa, 0x9b, 0x00, 0x00, 0xbb, 0xaf, 0x00, 0x00, 0xba, 0xab,
	  0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x8d, 0x1b,
	  0x00, 0x00, 0xb5, 0x6b, 0x00, 0x00, 0xb5, 0x6b, 0x00, 0x00, 0xb7, 0x6f,
	  0x00, 0x00, 0x8d, 0x1b, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	}

	const FaviconDataLen : uint  = 198
	

	construct ( req : Request )
		self.req = req

	/**
	 * Creates a reponse based on request
	 */
	def get_response () : Response

		// create response struct
		var resp = Response()
		
		// init default response values
		resp.status_code = StatusCode.OK
		resp.content_type = "text/html"
		resp.data = new array of uint8[0]

		/*
		if not is_loggedin()
			resp.status_code = StatusCode.AUTH_REQ
			return resp
		*/

		if req.path is "/" || req.object is null || req.object.length is 0
			resp.data = get_page("WikiHome").data
			return resp

		// set page to handle
		var page = req.object 
		
		case page
			when "favicon.ico"
				resp.data = FaviconData
				resp.content_type="image/ico"
			when "styles.css"
				resp.content_type = "text/css"
				resp.data = STYLESHEET.data
			when "Index"
				resp.data = get_index().data
			when "Create"
				if req.args["title"] is not null
					resp.data = edit_page(req.args["title"]).data
				else
					resp.data = new_page_form().data
			when "Search"
				resp.data = get_search(req.args["expr"]).data
			default
				case req.query
					when "Edit"		// decide to store or display form
						resp.data = handle_edit(page).data
					when "Delete"
						new WikiFile(page).delete_file()
						resp.data = get_page("WikiHome").data
					default
						resp.data = get_page(page).data
		
		//stdout.printf("get_response(): Response= %s\n", (string) resp.data)
		
		return resp
	
	/*
	def private is_loggedin() : bool
		return false
	*/
	
	/**
	 * Handles 'Edit' functions
	 */
	def private handle_edit ( page : string ) : string	
		
		if req.args["save"] is not null
			stdout.printf("handle_edit(): Save page %s\n", page)
			var wikitext = req.args["wikitext"]
			create_page(page, wikitext)
			return get_page(page)
		
		if req.args["cancel"] is not null
			return exists_page(page) ? get_page(page) : get_page("WikiHome")
		
		return edit_page(page)
	
	
	def private get_search ( expr : string ) : string
	
		if expr is null || expr.length is 0
			return get_index()
			
		sb : StringBuilder = new StringBuilder()
		sb.append("<table><tr>")
		cnt : int = 0
		
		// convert expression to ignore case
		var search = expr.casefold()
		
		try
			var files = get_files()
			file_info : FileInfo
			while (file_info = files.next_file()) is not null
				var name = file_info.get_name()
				if name is "styles.css" 
					continue
				if name.casefold() is search || new WikiFile(name).get_content().casefold().contains(search)
					sb.append_printf("<td>%d.</td><td><a href=\"%s\">%s</a></td>\n", ++cnt, name, name)
				if cnt % 3 is 0
					sb.append("</tr></tr>")
		except e : Error
			stderr.printf("get_index: %s\n", e.message)
		
		sb.append("</tr></table>")
		return get_header("Search - %s".printf(expr)) + sb.str + get_footer()
		
	
	def private get_files () : FileEnumerator raises Error
		var directory = File.new_for_path(home)
		return directory.enumerate_children (FileAttribute.STANDARD_NAME, 0)
		
	
	/**
	 * creates an index of available wiki pages
	 */
	def private get_index() : string
		sb : StringBuilder = new StringBuilder()
		sb.append("<table><tr>")
		cnt : int = 0
		try
			var files = get_files()
			file_info : FileInfo
			while (file_info = files.next_file()) is not null
				var name = file_info.get_name()
				if file_info.get_file_type () == FileType.DIRECTORY || name is "styles.css" 
					continue
				sb.append_printf("<td>%d.</td><td><a href=\"%s\">%s</a></td>\n", ++cnt, name, name)
				if cnt % 3 is 0
					sb.append("</tr></tr>")
		except e : Error
			stderr.printf("get_index: %s\n", e.message)
		
		sb.append("</tr></table>")
		return get_header("Index") + sb.str + get_footer()
	
	// check existence of page
	def private inline exists_page ( page : string ) : bool
		return new WikiFile(page).exists()
	/**
	 * Creates a wiki page
	 */
	def private inline create_page(page : string, wikitext : string)
		var file = new WikiFile(page)
		file.store_text(wikitext)
	
	/**
	 * Sends new page form
	 */
	def private new_page_form() : string
		return get_header("Create new page") + CREATEFORM + get_footer()
	
	/**
	 * Send edit page form
	 */
	def private edit_page ( page : string ) : string
		stdout.printf("edit_page: %s\n", page)
		var file = new WikiFile(page)
		var content = file.get_content()
		stdout.printf("edit_page: content = %s\n", content)
		return get_edit_header(page) + EDITFORM.printf(page, content) + get_footer()
		
	/**
	 * Creates WikiHome/ WikiHelp if necessary
	 */
	def private create_default_pages( page : string)
		var file = new WikiFile (page)
		if not file.exists()
			case page
				when "WikiHome"
					file.store_text(HOMETEXT)
				when "WikiHelp"
					file.store_text(HELPTEXT)
		
	/**
	 * Gets wiki page from file
	 */
	def private get_page ( page : string ) : string 
		stdout.printf("get_page(): page = %s\n", page)
		content : string = ""
		var file = new WikiFile (page)
		
		if not file.exists()
			if page is "WikiHome" || page is "WikiHelp" && not file.exists()
				// creates WikiHome or WikiHelp
				create_default_pages(page)
			else
				return edit_page(page)
	
		// Handles missing pages
		content=file.as_html()
			
		return get_edit_header(page) + content + get_footer()
	
	// produce edit page header
	def private inline get_edit_header ( title : string ) : string
		stdout.printf("get_edit_header(): title=%s\n", title)
		return WIKIHEADER.printf( title ) + EDITHEADER.printf(title, title, title)
	
	// produce page header
	def private inline get_header ( title : string ) : string
		stdout.printf("get_header(): title=%s\n", title)		
		return WIKIHEADER.printf( title ) + PAGEHEADER.printf(title, "Edit")
	
	// produce page footer
	def private inline get_footer () : string
		return PAGEFOOTER.printf(VERSION) + WIKIFOOTER

