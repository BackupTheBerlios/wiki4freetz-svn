uses
	Xml

def create_html( xml : string ) : string?
	// Parse the document from path
	doc : Xml.Doc* = Parser.read_doc (xml, null, "ISO-8859-1")
	if doc is null
		stderr.printf ("create_html: Error reading XML\n")
		return null

	// Get the root node. notice the dereferencing operator -> instead of .
	root : Xml.Node* = doc->get_root_element ()
	if root is null
		// Free the document manually before returning
		delete doc
		stderr.printf ("The xml string is empty\n")
		return null

	return parse_node(root)

def private parse_node ( node : Xml.Node* ) : string

	sb : StringBuilder = new StringBuilder()

	// Loop over the passed node's children
	child : Xml.Node* = node->children
	
	while  (child = child->next) is not null
	
		// Spaces between tags are also nodes, discard them
		if child->type is not ElementType.ELEMENT_NODE
			continue
		
		case child->name
			when "heading"
				var level = get_heading_level(child)
				sb.append_printf("<h%s>%s%s</h%s>\n", level, parse_node(child), child->get_content(), level)
			when "paragraph"
				sb.append_printf("<p>%s%s</p>\n", parse_node(child), child->get_content())
			when "list"
				var li = is_numbered_list(child) ? "<ol>\n%s%s</ol>" : "<ul>\n%s%s</ul>"
				sb.append_printf(li, parse_node(child), child->get_content())
			when "listitem"
				sb.append_printf("<li>%s%s</li>\n", parse_node(child), child->get_content())
			when "italics"
				sb.append_printf("<i>%s%s</i>", parse_node(child), child->get_content())
			when "bold"
				sb.append_printf("<b>%s%s</b>", parse_node(child), child->get_content())
			when "preblock"
				sb.append_printf("<pre>%s</pre>\n", parse_node(child))
			when "preline"
				sb.append_printf("%s\n", child->get_content())

			default
				stdout.printf("Unhandled node: %s\n", child->name)

		// Followed by its children nodes
		sb.append (parse_node (child))

	return sb.str
	

def private is_numbered_list (node : Xml.Node*) : bool
	var props = parse_properties( node )
	return props is not null && props["type"] is "numbered"


def private get_heading_level (node : Xml.Node*) : string
	var d = parse_properties(node)
	level : string = d["level"] is null ? "1" : d["level"]
	return level
	
def private parse_properties (node : Xml.Node*) : dict of string, string
	var d = new dict of string,string
	// Loop over the passed node's properties (attributes)
	p : Xml.Attr* = node->properties
	while p is not null
		attr_name : string = p->name
		// Notice the ->children which points to a Node*
		// (Attr doesn't feature content)
		attr_content : string = p->children->content
		d[attr_name] = attr_content
		p = p->next	// go next
	return d
		
	
	
