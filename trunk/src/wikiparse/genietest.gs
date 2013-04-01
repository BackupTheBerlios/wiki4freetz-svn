uses 
	WikiParse
	Xml

indent : int = 0

init
	try
		filename : string = "test.txt"
		txt : string
		FileUtils.get_contents (filename, out txt)
		var result = wikiparse_do_parse( txt )
		stdout.printf("\nOutput by genie:\n%s\n", result)
		xml2html(result)
	except e : FileError
		stderr.printf ("%s\n", e.message)

def private xml2html(xml : string)

	// Parse the document from path
	doc : Xml.Doc* = Parser.parse_doc (xml)
	if doc is null
		stderr.printf ("Error reading XML\n")
		return

	// Get the root node. notice the dereferencing operator -> instead of .
	root : Xml.Node* = doc->get_root_element ()
	if root is null
		// Free the document manually before returning
		delete doc
		stderr.printf ("The xml string is empty\n")
		return

	print_indent ("XML document", "GenieTest", '-')

	// Print the root node's name
	print_indent ("Root node", root->name)

	// Let's parse those nodes
	parse_node (root)
	
	// Free the document
	delete doc
		

def private parse_node ( node : Xml.Node*)
	indent++
	// Loop over the passed node's children
	child : Xml.Node* = node->children
	
	while  (child = child->next) is not null
	
		// Spaces between tags are also nodes, discard them
		if child->type is not ElementType.ELEMENT_NODE
			continue
		
		case child->name
			when "paragraph"
				write("<p>%s</p>".printf(child->get_content()))
			when "list"
				write("<ul>%s</ul>".printf(child->get_content()))

		/*
		node_name : string = child->name
		node_content : string = child->get_content ()
		print_indent (node_name, node_content)

		// Now parse the node's properties (attributes) ...
		parse_properties (child)

		// Followed by its children nodes
		parse_node (child)
		*/
	
	indent--

def private write ( s : string ) 
	stdout.printf("%s\n", s);

def private parse_properties (node : Xml.Node*) 
	// Loop over the passed node's properties (attributes)
	p : Xml.Attr* = node->properties
	while p is not null
		attr_name : string = p->name

		// Notice the ->children which points to a Node*
		// (Attr doesn't feature content)
		attr_content : string = p->children->content
		print_indent (attr_name, attr_content, '|')

		// go next
		p = p->next

                

def private print_indent (node : string, content : string,  token : char = '+') 
	insstr : string = string.nfill (indent * 2, ' ')
	stdout.printf ("%s%c%s: %s\n", insstr, token, node, content)
