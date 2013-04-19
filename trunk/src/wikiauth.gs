/**
 * Wiki authentication handling
 * Use similar method like htpasswd
 */
 
uses GLib
 
struct Credentials
	username : string
	token : string

/**
 * Stores user credentials 
 */
def store_credentials ( filepath : string, username : string, password : string ) : bool

	content : string
	
	var token = get_secure_token (username, password)	
	var credentials = get_user_credentials (filepath, username)

	try
		FileUtils.get_contents (filepath, out content)
		if credentials.username is username
			content = content.replace (credentials.token, token)
		else
			content += "%s %s\n".printf (username, token)
		
		FileUtils.set_contents (filepath, content)
		
	except e : FileError
		stderr.printf("%s\n", e.message)
		return false

	return true

/**
 * Returns all credentials
 */
def list_credentials ( filepath : string ) : list of string
	var cred_list = new list of string
	var file = File.new_for_path(filepath)
	if file.query_exists()
		try 
			var dis = new DataInputStream (file.read ())
			line : string
			while (line = dis.read_line (null)) is not null
				var c = parse_credentials (line)
				if c is not null
					cred_list.add(c.username)
		except e : Error
			stderr.printf("%s\n", e.message)
				
	return cred_list
	
/**
 * Deletes user credentials
 */
def delete_credentials ( filepath : string, username : string ) : bool
	content : string
	try 
		FileUtils.get_contents (filepath, out content)
		var credentials = get_user_credentials (filepath, username)
		if credentials.username is username
			content = content.replace ( "%s %s".printf(credentials.username, credentials.token), "" )
		else
			return false
		FileUtils.set_contents (filepath, content)
	except e : Error
		stderr.printf("%s\n", e.message)
		return false
	
	return true

/**
 * Verifies username and password against htpasswd file
 */
def verify_credentials ( filepath : string, username : string, password : string ) : bool

	var credentials = get_user_credentials (filepath, username)
	return credentials.username is username && credentials.token is get_secure_token (username, password)

/**
 * Returns credentials entry for a user
 */
def private get_user_credentials ( filepath : string, username : string ) : Credentials
	
	file : File = File.new_for_path (filepath)
	var credentials = Credentials() { username="", token="" }
	if file.query_exists()
		try 
			var dis = new DataInputStream (file.read ())
			line : string
			while ((line = dis.read_line (null)) != null) 
				var c = parse_credentials (line)
				if c is not null && c.username is username
					credentials = c
					break
		except e : Error
			stderr.printf("%s\n", e.message)
				
	return credentials

/**
 * Returns credentials from  a line in password file
 */
def private parse_credentials (line : string ) : Credentials?
	var parts = line.split(" ")
	if parts.length == 2
		var c = Credentials() { 
			username = parts[0], token = parts[1]
		}
		return c
	return null
	
/**
 * Creates secure token for user with password
 */
def private get_secure_token( username : string, password : string) : string
	checksum : Checksum = new Checksum (ChecksumType.SHA256);
	var secure = "%s%s".printf(username, password)
	checksum.update(secure.data, secure.length)
	return checksum.get_string()
