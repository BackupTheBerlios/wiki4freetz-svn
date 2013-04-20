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

/*
 * HTTP request handler methods
 */ 
 
// serves styles.css
def styles_handler (server : Soup.Server, msg : Soup.Message, path : string, 
					query : GLib.HashTable?, client : Soup.ClientContext)
	msg.set_response ("text/css", Soup.MemoryUse.COPY, STYLESHEET.data);

// services favicon.ico
def favicon_handler (server : Soup.Server, msg : Soup.Message, path : string, 
					query : GLib.HashTable?, client : Soup.ClientContext)
	msg.set_response ("image/x-icon", Soup.MemoryUse.COPY, FaviconData);

// Index
def index_handler (server : Soup.Server, msg : Soup.Message, path : string, 
					query : GLib.HashTable?, client : Soup.ClientContext)
	msg.set_response ("text/html", Soup.MemoryUse.COPY, get_index(false, null).data);

// Search
def search_handler (server : Soup.Server, msg : Soup.Message, path : string, 
					query : GLib.HashTable?, client : Soup.ClientContext)
	var response_text = get_index(true, get_param(query, "expr"))
	msg.set_response ("text/html", Soup.MemoryUse.COPY, response_text.data);

def help_handler (server : Soup.Server, msg : Soup.Message, path : string, 
					query : GLib.HashTable?, client : Soup.ClientContext)
	var response_text = get_header("WikiHelp") + HELPTEXT + get_footer()
	msg.set_response ("text/html", Soup.MemoryUse.COPY, response_text.data);
	
// TODO: list recent changes
def changes_handler (server : Soup.Server, msg : Soup.Message, path : string, 
					query : GLib.HashTable?, client : Soup.ClientContext)
	msg.set_response ("text/html", Soup.MemoryUse.COPY, get_index(false, null).data);
	
/**
 * Handles default Wiki request to serve pages
 */
def default_handler (server : Soup.Server, msg : Soup.Message, path : string, 
					query : GLib.HashTable?, client : Soup.ClientContext)

	var page = path.length==1 ? "WikiHome" : path[1:path.length]
	response_text : string = ""
	
	//request_info("default_handler()", msg, path, query)
	
	// handles ?<Query>
	case msg.uri.get_query()
		when "Edit"
			if msg.method is "POST"
				case get_post_action (msg)
					when "save"
						var wikitext = get_post_param(msg, "wikitext")
						create_page(page, wikitext)
						response_text = get_page(page)
					when "cancel"
						response_text = exists_page(page) ? get_page(page) : get_page("WikiHome")
					when "preview"
						response_text = "preview not implemented yet."
					default
						response_text = edit_page(page)
			else
				response_text =  edit_page(page)
		when "Delete"
			new WikiFile(page).delete_file()
			response_text = get_page("WikiHome")
		default
			response_text = get_page(page)
	
	msg.set_response ("text/html", Soup.MemoryUse.COPY, response_text.data);


// Create
def create_handler (server : Soup.Server, msg : Soup.Message, path : string, 
					query : GLib.HashTable?, client : Soup.ClientContext)
	request_info("create_ ..()", msg, path, query)
	response_text : string = ""
	if msg.method is "POST"
		var title = get_post_param(msg, "title")
		create_page(title, "")
		response_text = edit_page(title)
	else
		response_text = new_page_form()
		
	msg.set_response ("text/html", Soup.MemoryUse.COPY, response_text.data);
	
def private get_post_param ( msg : Soup.Message, key : string ) : string
	var ht = get_post_params (msg)
	return get_param(ht, key)

def private get_post_action ( msg : Soup.Message ) : string
	var ht = get_post_params (msg)
	buttons : array of string = {"save", "preview", "cancel"}
	btn : string = ""
	
	for b in buttons
		if get_param(ht, b) is not null
			btn = b
			break
	return btn
	
// only for debugging
def private request_info (callBy : string, msg : Soup.Message, path : string, query : GLib.HashTable?)
	message("\n Request Info - %s: %s\n Method: %s\n Query: %s\n POST Params: %s\n".printf(
		callBy, path, msg.method, msg.uri.get_query(), (string) msg.request_body.data))
	
/**
 * Gets a parameter from query part of HTTP request
 */
def private get_param ( query : GLib.HashTable?, key : string ) : string?
	
	if query is null
		return null
		
	ht : GLib.HashTable of string, string = query
	return ht.get(key)

/**
 * Gets POST parameter from message body
 */
def private inline get_post_params ( msg : Soup.Message ) : GLib.HashTable
	return Soup.Form.decode((string) msg.request_body.flatten().data)
	
/**
 * Search for expr contained in files name or content
 */
def private get_index ( do_search : bool, expr : string? ) : string
	
	sb : StringBuilder = new StringBuilder()
	cnt : int = 0
	
	// convert expression to ignore case
	var search = do_search && expr is not null ? expr.casefold() : ""
	
	sb.append("<table><tr>")
	
	try 
		var files = File.new_for_path(home).enumerate_children (FileAttribute.STANDARD_NAME, 0)
		file_info : FileInfo
		while (file_info = files.next_file()) is not null
			var name = file_info.get_name()
			if file_info.get_file_type () == FileType.DIRECTORY || name is "styles.css" 
				continue
			if expr is "" || name.casefold() is search || new WikiFile(name).get_content().casefold().contains(search)
				sb.append_printf("<td>%d.</td><td><a href=\"%s\">%s</a></td>\n", ++cnt, name, name)
			if cnt % 7 is 0
				sb.append("</tr><tr>")
	except e : Error
		stderr.printf("%s\n", e.message)
	
	sb.append("</tr></table>")
	var header = do_search ? get_header("Search - %s".printf(expr)) : get_header("Index")
	return header + sb.str + get_footer()
	

/** 
 * Check existence of page
 */
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
	//stdout.printf("edit_page: content = %s\n", content)
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
	
	var file = new WikiFile (page)
	
	if not file.exists()
		if page is "WikiHome" || page is "WikiHelp" && not file.exists()
			// creates WikiHome or WikiHelp
			create_default_pages(page)
		else
			return edit_page(page)

	return get_edit_header(page) + file.as_html() + get_footer()

// produce edit page header
def private inline get_edit_header ( title : string ) : string
	return WIKIHEADER.printf( title ) + EDITHEADER.printf(title, title, title)

// produce page header
def private inline get_header ( title : string ) : string
	return WIKIHEADER.printf( title ) + PAGEHEADER.printf(title, "Edit")

// produce page footer
def private inline get_footer () : string
	return PAGEFOOTER.printf(VERSION) + WIKIFOOTER

