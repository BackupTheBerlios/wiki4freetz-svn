/**
 *  GenieWiki is a port of CiWiki to Genie programming language.
 *  GenieWiki Copyright 2013 Torsten Herrmann <the.ilmenau@googlemail.com>
 * 
 *  CiWiki is a fork of DidiWiki - a small lightweight wiki engine. 
 *  DidiWiki Copyright 2004 Matthew Allum <mallum@o-hand.com>
 *  CiWiki Copyright 2010 Jean-Pierre Redonnet <inphilly@gmail.com>
 * 
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

/*
 * Build: valac -c --pkg gio-2.0 --pkg gee-1.0 --pkg libxml-2.0 wiki.gs wikihandler.gs wikitext.gs wikifile.gs
 */	
uses Gee
 
show_version : bool = false
auto_login : bool = false
listen : string
port : int
home : string
restore : bool
sendmail : bool

const VERSION : string = "0.1.0"
const DEFAULT_PORT : int = 8001
const DEFAULT_DIR : string = "/home/the/.didiwiki"

const options : array of OptionEntry = {
	{"version", 'v', 0, OptionArg.NONE, ref show_version, "Show application's version", null}, 
	{"autologin", 'a', 0, OptionArg.NONE, ref auto_login, "Flag to login local users automatically", null}, 
	{"listen", 'l', 0, OptionArg.STRING, ref show_version, "IP-Range to listen for", null}, 
	{"port", 'p', 0, OptionArg.INT, ref show_version, "Port to listen for", null}, 
	{"home", 'h', 0, OptionArg.STRING, ref show_version, "Wiki's home directory", null}, 
	{"restore", 'r', 0, OptionArg.NONE, ref show_version, "Restore Wiki help file", null}, 
	{"sendmail", 's', 0, OptionArg.NONE, ref show_version, "Enables send mail functionality", null}, 
	{null}
}	

init

	try
		var opt_context = new OptionContext ("- Genie Wiki")
		opt_context.set_help_enabled (true)
		opt_context.add_main_entries (options, null)
		opt_context.parse (ref args)
		
	except e:OptionError
		stdout.printf ("%s\n", e.message)
		stdout.printf ("Run '%s --help' to see a full list of available command line options.\n", args[0])	
		

	if show_version
		stdout.printf ("GenieWiki - version %s\n\n", VERSION)
		return
	
	if port==0 do port=DEFAULT_PORT
	if home is null do home=DEFAULT_DIR
	
	stdout.printf("GenieWiki is starting ...\n")
	stdout.printf("Wiki directory = %s\n", home)
	
	var exists = FileUtils.test(home, FileTest.EXISTS)
	var isdir = FileUtils.test(home, FileTest.IS_DIR)
	
	if not ( exists && isdir ) 
		stderr.printf("init: Cannot open Wiki directory: %s - Abort\n", home)
		return
	
	// create a webserver instance
	var ws = new WebServer( (uint16) port, home)
	ws.run()



/** 
 * Struct to request information 
 */
struct Request
	full_request : string
	path : string
	query : string
	object : string
	action : string
	val : string
	args : new dict of string,string

/**
 * Struct to hold reponse data
 */
struct Response
	status_code : string
	content_type : string
	text : string 
	data : array of uint8
	
/**
 * A simple web server implementation
 */
class WebServer	: Object

	prop private base_dir : string
	prop private port : uint16
	
	/**
	 * Constructs a web server object
	 */
	construct ( port : uint16, dir : string )
		base_dir = dir
		self.port = port
	
	
	/**
	 * Send response to HTTP client
	 */	
	def serve_response(response : Response, dos : DataOutputStream)
		try 
			var data = response.data 
			
			// write header to out stream
			dos.put_string(response.status_code)
			dos.put_string("Server: GenieWiki\n")
			dos.put_string("Content-Type: %s\n".printf(response.content_type))
			dos.put_string("Content-Length: %d\n".printf(data.length))
			if response.status_code is StatusCode.AUTH_REQ
				dos.put_string("WWW-Authenticate: Basic Realm=\"Geniewiki\"\n")
			dos.put_string("\n") 	// header end !!
			
			 written : long = 0
			 while written < data.length
				//stdout.printf("Response data: %s\n", data[written:data.length])
				written += dos.write (data[written:data.length])
			
		except e : Error
			stderr.printf("serve_response: %s\n", e.message);
	
	def get_request ( data : string ) : Request
	
		stdout.printf("get_request() - line: %s\n", data)
	
		var r = Request()
		r.args = new dict of string, string
		var parts = data.split(" ")

		if parts.length == 1
			return r

		r.full_request = parts[1]
		parts = r.full_request.split("?")
		r.path = parts[0]
		r.query = parts[1]
		
		if r.query is null do r.query=""

		// get the object and action
		parts = r.path.split("/")

		if parts.length > 1
			r.object = parts[1]
			if r.object is null do r.object=""

		if parts.length > 2
			r.action = parts[2]
			if r.action is null do r.action=""

		if parts.length > 3
			r.val = Uri.unescape_string(parts[3])
			if r.val is null do r.val = ""

		// split the query if it exists
		if r.query is not ""
			parts = r.query.split("&")
			for part in parts
				var query_parts = part.split ("=")
				if query_parts.length==2
					r.args[query_parts[0]] = Uri.unescape_string(query_parts[1])

		// handle post parameter
		if data.has_prefix("POST") && data.contains("\r\n\r\n")
			var post_params = data.split("\r\n\r\n")[1]
			parts = post_params.split("&")
			for part in parts
				var key_value = part.split ("=")
				if key_value.length==2
					r.args[key_value[0]] = Uri.unescape_string(key_value[1])
					
		stdout.printf("--------- Request-Data: %s\n%s\n--------------------------\n", 
			new DateTime.now_local().to_string(), data)
		debug(r)
		
		return r
	
	// Request: full_request, path, query, object, action val
	def private debug ( req : Request)
		var time = new DateTime.now_local().to_string()
		var sb = new StringBuilder()
		for entry in req.args.entries
			sb.append_printf("- %s=%s\n", entry.key, entry.value)
		stdout.printf("----------- REQUEST: %s -------------\npath=%s \n query=%s\n" + 
			"object=%s\n action=%s\nParameter:\n%s\n----------- EOF: %s\n", 
			time , req.path, req.query, req.object, req.action, sb.str, time)

	/**
	 * Start server process
	 */
	def run ()
	
		tss : ThreadedSocketService = new ThreadedSocketService(100)
		ia : InetAddress = new InetAddress.any(SocketFamily.IPV4)
		isaddr : InetSocketAddress = new InetSocketAddress(ia, port)
		try
			tss.add_address(isaddr, SocketType.STREAM, SocketProtocol.TCP, null, null);
		except e : Error
			stderr.printf("run: %s\n", e.message)
			return
		// add connection handler
		tss.run.connect( connection_handler )
	
		var ml = new MainLoop()
		tss.start()		// start listening
		stdout.printf(@"Serving on port $port\n");
		ml.run()


	/**
	 * Connection handler method.
	 */	
	def connection_handler( connection : SocketConnection ) : bool
		data : string = ""
		var buf  = new array of uint8 [1024]
		size : size_t = 0
		var request = Request()
		
		//get data input and output streams for the connection
		var dis = new DataInputStream( connection.input_stream )
		var dos = new DataOutputStream( connection.output_stream )
		
		try
			while (size = dis.read(buf)) >= 0
				data += (string) buf[0:size]
				if size < 1024 do break
			request = get_request(data)
		except e : Error
			stderr.printf("connection_handler: %s\n", e.message);
		
		//build a response based on the request
		var rh = new RequestHandler(request)
		serve_response( rh.get_response(), dos )
		return false
		
