/**
 *  GenieWiki is a simple WikiWiki implementation using Genie programming language.
 *  GenieWiki was inspired by DidiWiki.
 *  GenieWiki Copyright 2013 Torsten Herrmann <the.ilmenau@googlemail.com>
 * 
 *  GenieWiki was inspired by DidiWiki.
 *  DidiWiki Copyright 2004 Matthew Allum <mallum@o-hand.com>
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
uses 
	WikiText
	Soup
	
show_version : bool = false
port : int
home : string


const VERSION : string = "0.2.0"
const DEFAULT_PORT : int = 8001

const options : array of OptionEntry = {
	{"version", 'v', 0, OptionArg.NONE, ref show_version, "Show application's version", null}, 
	{"port", 'p', 0, OptionArg.INT, ref port, "Port to listen for", null}, 
	{"home", 'h', 0, OptionArg.STRING, ref home, "Wiki's home directory", null}, 
	{null}
}

	
/**
 * Main entry point to Wiki server
 */
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
	if home is null 
		home=Environment.get_home_dir() + "/.didiwiki"
	
	stdout.printf("GenieWiki is starting ...\n")
	stdout.printf("Wiki directory = %s\n", home)
	stdout.printf("Listening on port %d ...\n", port)
	
	var exists = FileUtils.test(home, FileTest.EXISTS)
	var isdir = FileUtils.test(home, FileTest.IS_DIR)
	
	if not ( exists && isdir ) 
		stderr.printf("init: Cannot open Wiki directory: %s - Abort\n", home)
		return
	
	// create a webserver instance
	var server = new Soup.Server (Soup.SERVER_PORT, port);
	
	// define HTTP request handler methods
	server.add_handler ("/", default_handler);
	server.add_handler ("/Index", index_handler);
	server.add_handler ("/Search", search_handler);
	server.add_handler ("/Create", create_handler);
	server.add_handler ("/Changes", changes_handler);
	server.add_handler ("/WikiHelp", help_handler);
	server.add_handler ("/styles.css", styles_handler);
	server.add_handler ("/favicon.ico", favicon_handler);
	
	// add authentication domain
	auth_domain : AuthDomainBasic = new AuthDomainBasic( 
		AUTH_DOMAIN_REALM, "GenieWiki", 
		AUTH_DOMAIN_ADD_PATH, "/",
		AUTH_DOMAIN_BASIC_AUTH_CALLBACK, auth_callback)
	server.add_auth_domain(auth_domain)
	
	// start server process
	server.run ()

def auth_callback (domain : AuthDomain, msg : Message, username: string, password : string) : bool
	
	var filepath = "%s/permission/.login.txt".printf(home)
	
	// check user name and password
	return verify_credentials (filepath, username, password)
