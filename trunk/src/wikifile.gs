/**
 * wikifile.gs - handles file operations
 */

uses WikiParse

class WikiFile : Object
	
	prop page : string
	
	construct (pagename : string)
		page = pagename
	
	/**
	 * Gets the associated file for the page
	 */
	def private inline get_file() : File
		var filepath = "%s/%s".printf(home, page)
		return File.new_for_path(filepath)
		
	/**
	 * Stores wiki text to file
	 */
	def store_text ( text : string ) 
		var file = get_file()
		stdout.printf("store_text(): %s\n", file.get_path())
		try 
			FileUtils.set_contents(file.get_path(), text)
		except e : GLib.Error
			stderr.printf("store_text(): %s\n", e.message)
	
	def delete_file ()
		if exists()
			try
				var file = get_file()
				file.delete()
			except e : Error
				stdout.printf("delete_file(): %s\n", e.message)
		


	/**
	 * Check file existense
	 */
	def inline exists() : bool
		return get_file().query_exists()
	
	def inline get_content() : string
		text : string
		try 
			// get wiki text from file
			FileUtils.get_contents (get_file().get_path(), out text)
		except e : FileError
			stdout.printf("get_content() - Error: %s\n", e.message)
			text = ""
		return text is null ? "" : text
	
	/**
	 * Wiki syntax parser
	 */	
	def as_html (): string? 
		var file = get_file()
		
		if ! file.query_exists()
			return null
		
		html : string = ""
		
		// get wiki text from file
		var text = get_content()
		isotext : string
		try 
			// wikiparse handles ISO-8859 encoded text
			isotext = GLib.convert(text, text.length, "ISO-8859-15", "UTF-8")
		except e : ConvertError
			isotext = text
			stderr.printf("Cannot convert to ISO-8859-15: %s\n", e.message)
		
		if text.length > 0
			var xml = wikiparse_do_parse(isotext)
			html = create_html(xml)
			//message("-------- Text --------\n%s\n".printf(text))
			message("-------- XML --------\n%s\n".printf(xml))
			//message("-------- HTML --------\n%s\n".printf(html))
		
		return html
