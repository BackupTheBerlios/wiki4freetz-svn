uses
	Xml

def create_html( xml : string ) : string?
	// Parse the document from path
	doc : Xml.Doc* = Parser.parse_doc (xml)
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

	var sb = new StringBuilder()
	parse_node(root, sb)

	return sb.str

/**
 * Parses XML node recursive
 */
def private parse_node ( node : Xml.Node*, sb : StringBuilder )

	// start end end tag for HTML output
	tags : array of string = {"", ""}
	
	do_childs : bool = true
	attrs : string = ""
		
	case node->name
		when "heading"
			var level = node->get_prop("level")
			tags[0] = "\n<h%s>".printf(level)
			tags[1] = "</h%s>\n".printf(level)
		when "paragraph"
			tags = {"<p>", "</p>\n"}
		when "list"
			if node->get_prop("type") is "numbered"
				tags = {"<ol>", "</ol>\n"}
			else
				tags = {"<ul>", "</ul>\n"}
		when "listitem"
			tags = {"<li>", "</li>\n"}
		when "italics"
			tags = {"<i>", "</i>"}
		when "bold"
			tags = {"<b>", "</b>"}
		when "preblock"
			tags = {"<pre>", "</pre>\n"}
		when "preline"
			sb.append_printf("%s\n", node->get_content())
		when "table"
			get_attrs(node, ref attrs)
			tags = {"<table%s>\n".printf(attrs), "</table>\n"}
		when "tablerow"
			get_attrs(node, ref attrs)
			tags = {"<tr%s>\n".printf(attrs), "</tr>\n"}
		when "tablecell"
			get_attrs(node, ref attrs)
			tags = {"<td%s>".printf(attrs), "</td>"}
		when "tablehead"
			get_attrs(node, ref attrs)
			tags = {"<th%s>".printf(attrs), "</th>"}
		when "attrs"
			do_childs = false
		when "link"
			internal_link(node, sb)
			do_childs = false
		when "article"
			tags = {"", ""}
		when "extension"
			case node->get_prop("name")
				when "strike"
					tags = {"<s>", "</s>"}
		default
			tags = {"", ""}
			message ("Unhandled node: %s".printf(node->name))
	
	// write start tag
	sb.append(tags[0])
	child : Xml.Node* = node->children
	
	while do_childs && child is not null
	
		// Spaces between tags are also nodes, discard them
		if child->type is ElementType.ELEMENT_NODE
			parse_node (child, sb)	// parse children
		if child->type is ElementType.TEXT_NODE
			var txt = child->get_content()
			transform_text(ref txt)
			sb.append(txt)
		child = child->next
		
	// write end tag
	sb.append(tags[1])

def get_attrs( node : Xml.Node*, ref attrs : string) : string
	child : Xml.Node* = node->children
	while  child is not null
		case child->name
			when "attrs"
				get_attrs(child, ref attrs)
			when "attr"
				attrs += " %s=\"%s\"".printf(child->get_prop("name"), child->get_content())
		child = child->next
	return attrs
	
def internal_link ( node : Xml.Node*, sb : StringBuilder )
	child : Xml.Node* = node->children
	target : string = ""
	text : string = ""
	while  child is not null
		if child->type is ElementType.ELEMENT_NODE
			case child->name
				when "linktarget"
					target = child->get_content()
				when "linkoption"
					text = child->get_content()
		child = child->next
	sb.append_printf("<a href=\"%s\">%s</a>", target, text.length == 0 ? target : text)
	
def private transform_text(ref txt : string)
	while txt.replace("----", "<hr/>") is not txt
		txt = txt.replace("----", "<hr/>")
	p1 : int = txt.index_of("[")
	p2 : int = txt.index_of("]", p1)
	if p2 > 0
		var target = txt[p1+1:p2]
		p1 = target.index_of(" ")
		if p1 > 1
			txt = "<a href=\"%s\">%s</a>".printf(target[0:p1], target[p1:target.length])
		else
			txt = "<a href=\"%s\">%s</a>".printf(target, target)

