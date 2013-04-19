/**
* File 	 : gwpasswd
* Author : <the.ilmenau@googlemail.com>
* Desc   : Manage user files for basic authentication
* 
* Synopsis: 
* 
* 	gwpasswd passwdfile username password
* 	gwpasswd [ -D ] passwdfile username
* 	gwpasswd -l passwdfile
*/

uses Gee

delete_user : bool = false
list_user : bool = false

const options : array of OptionEntry = {
	{"delete", 'd', 0, OptionArg.NONE, ref delete_user, "Delete user from password file", null}, 
	{"list", 'l', 0, OptionArg.NONE, ref list_user, "List users in password file", null}, 
	{null}
}

init
	var sb = new StringBuilder()
	sb.append("Parameter:\n")
	sb.append("\tfilename\tname of password file\n")
	sb.append("\t[username]\tname of user\n")
	sb.append("\t[password]\tnew password for user\n")
	sb.append("\nExamples:\n")
	sb.append("\tgwpasswd <filename> <username> <password>\n")
	sb.append("\tgwpasswd -l <filename>\n")
	sb.append("\tgwpasswd -d <filename> <username>\n")

	var opt_context = new OptionContext ("- Password management for Genie Wiki")
	opt_context.set_description(sb.str)
	opt_context.set_help_enabled (true)
	opt_context.add_main_entries (options, null)
	
	try
		opt_context.parse (ref args)
		
	except e:OptionError
		stdout.printf ("%s\n", e.message)
		stdout.printf ("Run '%s --help' to see a full list of available command line options.\n", args[0])	
	
	if delete_user
		if args.length==3
			if not delete_credentials ( args[1], args[2] )
				stdout.printf("Could not delete user: %s from file: %s\n", args[1], args[2])
		else
			stdout.printf(opt_context.get_help (true, null))
	
	if list_user
		if args.length==2
			users : list of string = list_credentials ( args[1] )
			for s in users
				stdout.printf ("%s\n", s)
		else
			stdout.printf(opt_context.get_help (true, null))
	
	if not delete_user && not list_user
		if args.length==4
			if not store_credentials ( args[1], args[2], args[3] )
				stdout.printf ("Could not store user: %s with password: %s in file: %s\n", args[2], args[3], args[1])
		else
			stdout.printf(opt_context.get_help (true, null))
