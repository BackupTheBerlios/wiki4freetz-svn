init
	// public int encode_entities (char[] outdata, out int outlen, char[] indata, out int inlen, char quote_char = '\0')
	
	var outdata = "".to_utf8()
	var indata = "über möglich maßlos Ärger".to_utf8()
	outlen : int
	inlen : int
	
	Html.encode_entities(outdata, out outlen, indata, out inlen)
	
	stdout.printf("HTML-Text: %s\n", (string) outdata)
	
	var encoded_uri = "das+ist+ein+Absatz"
	stdout.printf("Encoded: %s\nDecoded: %s\n", encoded_uri, Uri.unescape_string(encoded_uri))
