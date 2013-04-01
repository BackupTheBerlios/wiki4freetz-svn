/**
 *  GenieWiki is a port of GenieWiki to Genie programming language.
 *  GenieWiki Copyright 2013 Torsten Herrmann <the.ilmenau@googlemail.com>
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

namespace WikiText

	const WIKIHEADER : string =  """
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<!-- WIKIEHEADER -->
<html xmlns="http://www.w3.org/1999/xhtml"> 
<head> 
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" /> 
<link rel="SHORTCUT ICON" href="favicon.ico" /> 
<link media="all" href="styles.css" rel="STYLESHEET" type="text/css" /> 
<title>%s</title> 
</head> 
<body>
"""
	const WIKIFOOTER : string =  "</body></html>"
 
	const EDITHEADER : string =  """
<!-- EDITHEADER -->
<div id="header">
<form method="get" action="Search"> 
<table border="0" width="100%%"> 
<tr> 
<td align="left" ><strong>%s</strong> 
 ( <a href=%s?Edit title="Edit this wiki page contents. [alt-j]" accesskey="j">Edit</a> |  
<a href=%s?Delete title="Delete page. [alt-d]" accesskey="d">Delete</a> ) </td> 
<td align="right" > 
<a href="WikiHome" title="Visit Wiki home page. [alt-z]" accesskey="z">Home</a> | 
<a href="Index" title="List all pages in the wiki. [alt-i]" accesskey="i" >Index</a> | 
<a href="Changes" title="List recent changes in the wiki. [alt-r]" accesskey="r" >Changes</a> | 
<a href="Create" title="Create a new wiki page by title. [alt-c]" accesskey="c">New</a> | 
<a href="WikiHelp" title="Get help on wiki usage and formatting.">Help</a>  
<input type="text" name="expr" size="15" title="Enter text to search for and press return." /> </td> 
</tr> 
</table> 
</form> 
</div> 
<div id="wikidata">
"""
 
	const PAGEHEADER : string =  """
<!-- PAGEHEADER -->
<div id="header"> 
<form method="get" action="Search"> 
<table border="0" width="100%%"> 
<tr> 
<td align="left" ><strong>%s</strong> %s</td> 
<td align="right" > 
<a href="WikiHome" title="Visit Wiki home page. [alt-z]" accesskey="z">Home</a> | 
<a href="Index" title="List all pages in the wiki. [alt-i]" accesskey="i" >Index</a> | 
<a href="Changes" title="List recent changes in the wiki. [alt-r]" accesskey="r" >Changes</a> | 
<a href="Create" title="Create a new wiki page by title. [alt-c]" accesskey="c">New</a> |  
<a href="WikiHelp" title="Get help on wiki usage and formatting.">Help</a>  
<input type="text" name="expr" size="15" title="Enter text to search for and press return." /> </td> 
</tr> 
</table> 
</form> 
</div> 
<div id="wikidata"> 
"""
 
	const PAGEFOOTER : string =  """
<!-- PAGEFOOTER -->
</div><div id="footer">GenieWiki inspired by DidiWiki, Version:  %s</div>
"""
 
	const SHORTHELP : string =  """
<!-- SHORTHELP -->
<div id="header"> 
<table border="0" width="100%%"> 
<tr> 
<td align="left" > =H1 ==H2 ===H3 | bold | /italic/ | _underscore_ | -strikethrough- | highlight | "quote | 
[link] | * list | ** sublist | # ordered | ---- | {{toc}} | {{private}}</td> 
</tr> 
</table> 
</div> 
<div id="wikidata"> 
"""
 
	const LOGINFORM : string = """
<!-- LOGINFORM -->
<h1>Login</h1> 
<p><a href="NewAccount">New user? Please create a new account.</a></p> 
<form method=POST action="Login"> 
<table border="0" width="100%%"> 
<tr> 
<td align="right">User name:</td> 
<td align="left"><input type="text" name="username" /></td> 
</tr><tr> 
<td align="right">Password:</td> 
<td align="left"><input type="password" name="password" /></td> 
</tr><tr> 
<td></td><td align="left"><input type="submit" value="Login" /></td> 
</tr></table> 
</form> 
"""
 
	const NEWLOGINFORM : string = """
<!-- NEWLOGINFORM -->
<h1>Create a new Account</h1> 
<p>Please choose your user name, your password and enter a valid email address.<br> 
You will receive your validation code on your email</p> 
<form method=POST action="Login"> 
<table border="0" width="100%%"> 
<tr> 
<td align="right">User name:</td> 
<td align="left"><input type="text" name="username" /></td> 
</tr><tr> 
<td align="right">Password:</td> 
<td align="left"><input type="password" name="password" /></td> 
</tr><tr> 
<td align="right">Your Email:</td> 
<td align="left"><input type="text" name="email" /></td> 
</tr><tr> 
<td align="left" colspan=2><br>A validation code will be returned by mail.<br><br></td> 
</tr><tr> 
<td align="right">Validation Code:</td> 
<td align="left"><input type="text" name="code" /></td> 
</tr><tr> 
</tr><tr> 
<td></td><td align="left"><input type="submit" value="Process it" /></td> 
</tr></table> 
<input type="hidden" name="newaccount" value="on" />  
</form>
""" 
 
	const CHGPWDFORM : string = """
<!-- GHGPWDFORM -->
<form method=POST action="Login"> 
<table border="0" width="100%%"> 
<tr> 
<td align="right">Old password:</td> 
<td align="left"><input type="password" name="password" /></td> 
</tr><tr> 
<td align="right">New password:</td> 
<td align="left"><input type="password" name="newpassword" /></td> 
</tr><tr> 
<td align="right">Reenter your password:</td> 
<td align="left"><input type="password" name="newpasswordbis" /></td> 
</tr><tr> 
</tr><tr> 
<td></td><td align="left"><input type="submit" value="Login" /></td> 
</tr></table> 
</form> 
"""
 
	const LOGINFO : string = """
<!-- LOGINFO -->
<h1>Login Information</h1> 
<form method=POST action="Login"> 
<table border="0" width="100%%"> 
<tr> 
<td align="right">IP Address:</td><td>%s</td> 
</tr><tr> 
<td align="right">Login name:</td><td>%s</td> 
</tr><tr> 
<td></td><td align="left"><input type="submit" name="logoff" value="Log Off" /></td> 
</tr><td span=2><br>Change your password:<br></td><tr> 
<td align="right">Old password:</td> 
<td align="left"><input type="password" name="password" /></td> 
</tr><tr> 
<td align="right">New password:</td> 
<td align="left"><input type="password" name="newpassword" /></td> 
</tr><tr> 
<td align="right">Reenter your password:</td> 
<td align="left"><input type="password" name="newpasswordbis" /></td> 
</tr><tr> 
<td></td><td align="left"><input type="submit" name="chgpwd" value="Change Password" /></td> 
</tr><tr> 
</tr><td span=2><br><a href="javascript:javascript:history.go(-1)">Return to the previous page.</a></td><tr> 
</tr></table> 
</form> 
"""
 
	const CREATEFORM : string = """
<!-- CREATEFORM -->
<form method=POST action="Create"> 
<input type="text" name="title" /> 
<p><input type="submit" value="Create" /></p> 
</form> 
"""
 
	const EDITFORM : string = """
<!-- EDIT FORM -->
<form method=POST action="%s?Edit" name="editform"> 
<textarea name="wikitext" rows="20" cols="80" wrap="virtual">%s</textarea> 
<p><input type="submit" name="save" value="Save" title="[alt-k]" accesskey="k"> 
<input type="submit" name="preview" value="Preview" title="[alt-p]" accesskey="p"> 
<input type="submit" name="cancel" value="Cancel" title="[alt-c]" accesskey="c"></p> 
</form> 
<script language="JavaScript"> 
<!-- 
/* Give the textarea focus ...less mouse usage but may annoy people ?*/  
document.editform.wikitext.focus() 
document.editform.wikitext.scrollTop = document.editform.wikitext.scrollHeight; 
//--> 
</script> 
"""
 
	const EDITPREVIEW : string = """
<!-- EDITPREVIEW -->
<div id=header><strong>Preview:</strong></div>
"""
 
	const DELETEFORM : string = """
<!-- DELETEFORM -->
<form method=POST action="%s?delete" name="deleteform"> 
Are you really sure you want to delete the page <strong>%s</strong>? 
<p><input type="submit" name="confirm" Value="OK"> 
<input type="submit" name="cancel" value="Cancel">
</form>
"""
 
	const HOMETEXT  : string = """
<!-- HOMETEXT -->
[images/GenieWiki.png] 
== Welcome to GenieWiki inspired by DidiWiki ==
''GenieWiki'' is a fork of ''DidiWiki'' with nearly full support of ''MediaWiki'' syntax. 
GenieWiki is a small and simple [http://en.wikipedia.org/wiki/Wiki WikiWikiWeb] implementation.
The implementation was inspired by ''DidiWiki''.
GenieWiki is fast and does not require webserver, database mng and php interpreter. 
For an example of how a !GenieWiki entry looks in text form you can [?Edit edit] this page. Also see WikiHelp for infomation on usage and formatting rules. Use The WikiSandbox to experiment. 
/!GenieWiki / is written by [mailto://thpost@gmx.net Torsten Herrmann] in 2013 and released under [http://www.gnu.org GNU] [http://www.gnu.org/copyleft/gpl.html GPL].  
Matthew Allum is the original author of ''!DidiWiki'' (2004)
"""
 
	const HELPTEXT  : string =  """
=Quick Guide
Top toolbar usage
* [?edit Edit] Allows you to edit pages ( see below for rules )
* [?delete Delete] Allows you to delete pages
* [WikiHome Home] Takes you to the wiki front page
* [Index Index] List all the pages in the wiki
* [Changes Changes] Lists the pages changed by date
* [Create New] Creates a new wiki page by title
* [WikiHelp Help] Takes you to this help page
Use the text entry box to perform a very simple keyword search on the
Wiki contents. Hit return to activate the search.
Use the WikiSandbox to practice formatting.
----
=Formatting rules
=Top Level Heading
  =Top Level Heading (H1)
==Second Level Heading
  ==Second Level Heading (H2)
More levels
  === (H3), ==== (H4) etc
----
The horizontal lines in this page are made with 4 or more dashes:
 ---- Horizonal line
----
Paragraphs are separated by an empty line
Like this. Another paragraph.
 Paragraphs are separated by a blank line.
 Like this. Another paragraph.
----
*Bold text*, /italic text/, _underscore text_ and -strikethrough-.
  *Bold text*, /italic text/, _underscore text_ and -strikethrough-.
/*Combination of bold and italics*/
  /*Combination of bold and italics*/
----
{B}Text color{B}
 {B}Text color{B}
(Y)Background color(Y)
 (Y)Background color(Y)
Colors: {B}B blue{B}  {C}C cyan{C}  {G}G green{G}  {P}P pink{P}  {R}R red{R}  {Y}Y yellow{Y}
Colors: (B)B blue(B)  (C)C cyan(C)  (G)G green(G)  (P)P pink(P)  (R)R red(R)  (Y)Y yellow(Y)
----
Highlight
 Highlight
-----
WikiLinks are formed by two or more words in /camelcase/.
 WikiLinks are formed by two or more words in /camelcase/.
External links begin with http://, like http://www.freepan.org
 External links begin with http://, like http://www.freepan.org
Forced wiki [links] are a alphanumeric string surrounded by square brackets.
 Forced wiki [links] are a alphanumeric string surrounded by square brackets.
Named http links have text with an !http:// link inside, like [http://www.freepan.org FreePAN]
 Named http links have text with an !http:// link inside, like [http://www.freepan.org FreePAN]
Sometimes !WordsShouldNotMakeAWikiLink so put a "! " beforehand.
 Sometimes !WordsShouldNotMakeAWikiLink so put a "! " beforehand.
Same thing with !http://foobar.com
 Same thing with !http://foobar.com
Open external links in new tags:
 {{wwwlink=new_tag}} opens external link in a new tag
 {{wwwlink=current_tag}} opens external link in a current tag
----
Links to images display the image:
 Pictures size and border: {{width=100 height=50 border=2}}
 Return to the default width, height and border: {{picture=default}}
{{width=100 height=50 border=1}}
http://www.google.com/images/logo.gif
 http://www.google.com/images/logo.gif
Picture http links have picture with an !http:// link inside, like [http://www.google.com/images/logo.gif http://www.google.com]
 Picture http links have picture with an !http:// link inside, like [http://www.google.com/images/logo.gif http://www.google.com]
----
 Video youtube, videomotion, veoh, vimeo, flash... embedded:
 youtube=http://www.youtube.com/v/---adress--- 
 dailymotion=http://www.dailymotion.com/swf/---adress--- 
 vimeo=http://..... veoh=http://..... flash=http://.....
 line starts with youtube... and terminate the adress with a space
----
Unordered lists begin with a "* ". The number of asterisks determines the level:
* foo
* bar
** boom
** bam
* baz
  * foo
  * bar
  ** boom
  ** bam
  * baz
Ordered lists work the same, but use a "#"
----
Tables begin the line with a "|" and before every new column after.
| row:1,col:1 | row:1,col:2
| row:2,col:1 | row:2,col:2
 | row:1,col:1 | row:1,col:2
 | row:2,col:1 | row:2,col:2
---
Quotation begins with "
 "I had a monumental idea this morning, but I didn't like it
"I had a monumental idea this morning, but I didn't like it
----
Expand text
 {{expand}}  or  {{expand=your label here}}
 text, links, images
 {{-expand}}
{{expand}}
text, links: http://www.google.com
{{-expand}}
Imbricated
 {{expand}}
 Some text
 {{expand}}
 More text
 {{-expand}}
 {{-expand}}
{{expand}}
Some text
{{expand}}
More text
{{-expand}}
{{-expand}}
----
Collapse text, can be imbricated too.
 {{collapse}}  or  {{collapse=your label here}}
 text, links, images
 {{-collapse}}
{{collapse}}
text, links: http://www.google.com
{{-collapse}}
----
Install:
The file styles.css must be copied in ./didiwiki or in the home directory of didiwiki.
----
Simple form: ToDo list
 {{entry}} or {{entry tiny/small/medium/large/huge date}}
 !{{data}}   (remove ! before this tag)
 Entries are added in the page after the tag data
 {{delete}} deletes the selected field
 {{save}} saves the checked fields
{{entry}}
{{data}}
{{delete}}{{save}}
----
 Table of contents {{toc}} can be between collapse or expand
{{collapse=Table of contents}}{{toc}}{{-collapse}}
----
<Inline> <html> <is> <escaped>.
----
Lines prefixed with a space are unformatted ( Like examples on this page )
----
 There is a `keyword` in this line.
There is a `keyword` in this line.
----
 Define a private zone in the page with {{private}}
 Login is required to show after this tag
{{private}}
 This text is hidded if you are not logged!
----
"""

	const STYLESHEET : string =  """
body { 
  font-family: Verdana, Arial, Helvetica, sans-serif; 
  font-size: 90%;   
  color: #333333; 
  margin: 2px; 
  padding: 2px; 
} 
#header { 
	font-size: 90%; 
	background-color: lightblue; /* #eef */
	border: 1px solid gray; 	/* #aaa */
	font-family: Verdana, Arial, Helvetica, sans-serif; 
	padding: 5px; 
	margin-bottom:20px; 
} 
#header input { 
	margin:0px; 
	padding: 0; 
	background-color: White; 
	border: 1px solid #aaaaaa; 
	font-size: 90%; 
} 
#footer { 
	font-size: 10px; 
	color: #ddd; 
	margin-top:40px; 
	width: 100%; 
	text-align: center; 
} 
table.wikitable { background-color: #fff; border: 1px solid #aaa; } 
table.wikitable td { background-color: #fff; border: 1px solid #aaa; } 
pre { 
	font-family: monospace; 
	background-color: #eee; 
	padding: 2px; 
	padding-left: 10px; 
	margin-left: 20px; 
	margin-right: 20px; 
} 
hr { 
 height: 1px; 
 color: #aaaaaa; 
 background-color: #aaaaaa; 
 border: 0; 
 margin: 0.2em 5px 0.2em 5px; 
} 
form { 
	border: none; 
	margin: 0; 
} 
textarea { 
	border: 1px solid #aaaaaa; 
	color: Black; 
	background-color: white; 
	width: 100%; 
	padding: 0.1em; 
	overflow: auto; 
} 
input { 
	margin-top:1px; 
	padding: 0 0.4em !important; 
	background-color: White; 
	border: 1px solid #aaaaaa; 
} 
a, ulink{ 
   color: #333; 
   text-decoration:none; 
   border-bottom: 1px #333 dotted; 
   display: inline; 
 } 
a:hover { 
   color: #333; 
   text-decoration: None; 
   border-bottom: 1px #000 solid; 
   } 
a:visited { 
   color: #333; 
}
"""
