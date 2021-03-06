/* wikihandler.c generated by valac 0.16.1, the Vala compiler
 * generated from wikihandler.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gobject/gvaluecollector.h>


#define TYPE_REQUEST_HANDLER (request_handler_get_type ())
#define REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_REQUEST_HANDLER, RequestHandler))
#define REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_REQUEST_HANDLER, RequestHandlerClass))
#define IS_REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_REQUEST_HANDLER))
#define IS_REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_REQUEST_HANDLER))
#define REQUEST_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_REQUEST_HANDLER, RequestHandlerClass))

typedef struct _RequestHandler RequestHandler;
typedef struct _RequestHandlerClass RequestHandlerClass;
typedef struct _RequestHandlerPrivate RequestHandlerPrivate;

#define TYPE_REQUEST (request_get_type ())
typedef struct _Request Request;

#define TYPE_RESPONSE (response_get_type ())
typedef struct _Response Response;
#define _g_free0(var) (var = (g_free (var), NULL))

#define TYPE_WIKI_FILE (wiki_file_get_type ())
#define WIKI_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_WIKI_FILE, WikiFile))
#define WIKI_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_WIKI_FILE, WikiFileClass))
#define IS_WIKI_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_WIKI_FILE))
#define IS_WIKI_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_WIKI_FILE))
#define WIKI_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_WIKI_FILE, WikiFileClass))

typedef struct _WikiFile WikiFile;
typedef struct _WikiFileClass WikiFileClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _ParamSpecRequestHandler ParamSpecRequestHandler;

typedef enum  {
	IO_ERROR_FILE_NOT_FOUND,
	IO_ERROR_FILE_NO_READ_PERMISSION,
	IO_ERROR_FILE_IS_LOCKED
} IOError;
#define IO_ERROR io_error_quark ()
struct _RequestHandler {
	GTypeInstance parent_instance;
	volatile int ref_count;
	RequestHandlerPrivate * priv;
};

struct _RequestHandlerClass {
	GTypeClass parent_class;
	void (*finalize) (RequestHandler *self);
};

struct _Request {
	gchar* full_request;
	gchar* path;
	gchar* query;
	gchar* object;
	gchar* action;
	gchar* val;
};

struct _RequestHandlerPrivate {
	Request _req;
};

struct _Response {
	gchar* status_code;
	gchar* content_type;
	gchar* text;
	guint8* data;
	gint data_length1;
};

struct _ParamSpecRequestHandler {
	GParamSpec parent_instance;
};


static gpointer request_handler_parent_class = NULL;

#define STATUS_CODE_FILE_NOT_FOUND "HTTP/1.1 404 Not Found\n"
#define STATUS_CODE_OK "HTTP/1.1 200 OK\n"
#define STATUS_CODE_ERROR "HTTP/1.1 500 Internal Server Error\n"
#define STATUS_CODE_AUTH_REQ "HTTP/1.1 401 Unauthorized"
GQuark io_error_quark (void);
gpointer request_handler_ref (gpointer instance);
void request_handler_unref (gpointer instance);
GParamSpec* param_spec_request_handler (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_request_handler (GValue* value, gpointer v_object);
void value_take_request_handler (GValue* value, gpointer v_object);
gpointer value_get_request_handler (const GValue* value);
GType request_handler_get_type (void) G_GNUC_CONST;
GType request_get_type (void) G_GNUC_CONST;
Request* request_dup (const Request* self);
void request_free (Request* self);
void request_copy (const Request* self, Request* dest);
void request_destroy (Request* self);
#define REQUEST_HANDLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_REQUEST_HANDLER, RequestHandlerPrivate))
enum  {
	REQUEST_HANDLER_DUMMY_PROPERTY
};
RequestHandler* request_handler_new (Request* req);
RequestHandler* request_handler_construct (GType object_type, Request* req);
void request_handler_set_req (RequestHandler* self, Request* value);
GType response_get_type (void) G_GNUC_CONST;
Response* response_dup (const Response* self);
void response_free (Response* self);
void response_copy (const Response* self, Response* dest);
void response_destroy (Response* self);
void request_handler_get_response (RequestHandler* self, Response* result);
static gboolean request_handler_is_loggedin (RequestHandler* self);
static void request_handler_debug (RequestHandler* self);
void request_handler_get_req (RequestHandler* self, Request* result);
static guint8* _vala_array_dup3 (guint8* self, int length);
#define WIKI_TEXT_STYLESHEET "\n" \
"body { \n" \
"  font-family: Verdana, Arial, Helvetica, sans-serif; \n" \
"  font-size: 90%;   \n" \
"  color: #333333; \n" \
"  margin: 2px; \n" \
"  padding: 2px; \n" \
"} \n" \
"#header { \n" \
"\tfont-size: 90%; \n" \
"\tbackground-color: #eef; \n" \
"\tborder: 1px solid #aaa; \n" \
"\tfont-family: Verdana, Arial, Helvetica, sans-serif; \n" \
"\tpadding: 5px; \n" \
"\tmargin-bottom:20px; \n" \
"} \n" \
"#header input { \n" \
"\tmargin:0px; \n" \
"\tpadding: 0; \n" \
"\tbackground-color: White; \n" \
"\tborder: 1px solid #aaaaaa; \n" \
"\tfont-size: 90%; \n" \
"} \n" \
"#footer { \n" \
"\tfont-size: 10px; \n" \
"\tcolor: #ddd; \n" \
"\tmargin-top:40px; \n" \
"\twidth: 100%; \n" \
"\ttext-align: center; \n" \
"} \n" \
"table.wikitable { background-color: #fff; border: 1px solid #aaa; } \n" \
"table.wikitable td { background-color: #fff; border: 1px solid #aaa; }" \
" \n" \
"pre { \n" \
"\tfont-family: monospace; \n" \
"\tbackground-color: #eee; \n" \
"\tpadding: 2px; \n" \
"\tpadding-left: 10px; \n" \
"\tmargin-left: 20px; \n" \
"\tmargin-right: 20px; \n" \
"} \n" \
"hr { \n" \
" height: 1px; \n" \
" color: #aaaaaa; \n" \
" background-color: #aaaaaa; \n" \
" border: 0; \n" \
" margin: 0.2em 5px 0.2em 5px; \n" \
"} \n" \
"form { \n" \
"\tborder: none; \n" \
"\tmargin: 0; \n" \
"} \n" \
"textarea { \n" \
"\tborder: 1px solid #aaaaaa; \n" \
"\tcolor: Black; \n" \
"\tbackground-color: white; \n" \
"\twidth: 100%; \n" \
"\tpadding: 0.1em; \n" \
"\toverflow: auto; \n" \
"} \n" \
"input { \n" \
"\tmargin-top:1px; \n" \
"\tpadding: 0 0.4em !important; \n" \
"\tbackground-color: White; \n" \
"\tborder: 1px solid #aaaaaa; \n" \
"} \n" \
"a, ulink{ \n" \
"   color: #333; \n" \
"   text-decoration:none; \n" \
"   border-bottom: 1px #333 dotted; \n" \
"   display: inline; \n" \
" } \n" \
"a:hover { \n" \
"   color: #333; \n" \
"   text-decoration: None; \n" \
"   border-bottom: 1px #000 solid; \n" \
"   } \n" \
"a:visited { \n" \
"   color: #333; \n" \
"}\n"
static guint8* _vala_array_dup4 (guint8* self, int length);
static guint8* request_handler_get_page (RequestHandler* self, const gchar* page, int* result_length1, GError** error);
static void request_handler_create_default_pages (RequestHandler* self, const gchar* page);
WikiFile* wiki_file_new (const gchar* pagename);
WikiFile* wiki_file_construct (GType object_type, const gchar* pagename);
GType wiki_file_get_type (void) G_GNUC_CONST;
gboolean wiki_file_exists (WikiFile* self);
void wiki_file_store_text (WikiFile* self, const gchar* text);
#define WIKI_TEXT_HOMETEXT "\n" \
"<!-- HOMETEXT -->\n" \
"[images/ciwiki.png] \n" \
"==Welcome to !CiWiki alias !DidiWiki \n" \
"/!CiWiki / is a fork of /!DidiWiki / with several new features added. " \
"\n" \
"CiWiki is a small and simple [http://en.wikipedia.org/wiki/Wiki WikiWi" \
"kiWeb] implementation \n" \
"Ideal for personal note-taking, to do lists, and any other uses you ca" \
"n think of. \n" \
"CiWiki is fast and does not require webserver, database mng and php in" \
"terpreter. \n" \
"For an example of how a !CiWiki entry looks in text form you can [?edi" \
"t edit] this page. Also see WikiHelp for infomation on usage and forma" \
"tting rules. Use The WikiSandbox to experiment. \n" \
"The zipped homepage is here: [files/index.zip] \n" \
"/!CiWiki / is written by [mailto://inphilly@gmail.com Jean-Pierre Redo" \
"nnet] and released under [http://www.gnu.org GNU] [http://www.gnu.org/" \
"copyleft/gpl.html GPL].  \n" \
"Matthew Allum is the original author of /!DidiWiki (2004)\n"
#define WIKI_TEXT_HELPTEXT "\n" \
"=Quick Guide\n" \
"Top toolbar usage\n" \
"* [?edit Edit] Allows you to edit pages ( see below for rules )\n" \
"* [?delete Delete] Allows you to delete pages\n" \
"* [WikiHome Home] Takes you to the wiki front page\n" \
"* [Index Index] List all the pages in the wiki\n" \
"* [Changes Changes] Lists the pages changed by date\n" \
"* [Create New] Creates a new wiki page by title\n" \
"* [WikiHelp Help] Takes you to this help page\n" \
"Use the text entry box to perform a very simple keyword search on the\n" \
"Wiki contents. Hit return to activate the search.\n" \
"Use the WikiSandbox to practice formatting.\n" \
"----\n" \
"=Formatting rules\n" \
"=Top Level Heading\n" \
"  =Top Level Heading (H1)\n" \
"==Second Level Heading\n" \
"  ==Second Level Heading (H2)\n" \
"More levels\n" \
"  === (H3), ==== (H4) etc\n" \
"----\n" \
"The horizontal lines in this page are made with 4 or more dashes:\n" \
" ---- Horizonal line\n" \
"----\n" \
"Paragraphs are separated by an empty line\n" \
"Like this. Another paragraph.\n" \
" Paragraphs are separated by a blank line.\n" \
" Like this. Another paragraph.\n" \
"----\n" \
"*Bold text*, /italic text/, _underscore text_ and -strikethrough-.\n" \
"  *Bold text*, /italic text/, _underscore text_ and -strikethrough-.\n" \
"/*Combination of bold and italics*/\n" \
"  /*Combination of bold and italics*/\n" \
"----\n" \
"{B}Text color{B}\n" \
" {B}Text color{B}\n" \
"(Y)Background color(Y)\n" \
" (Y)Background color(Y)\n" \
"Colors: {B}B blue{B}  {C}C cyan{C}  {G}G green{G}  {P}P pink{P}  {R}R " \
"red{R}  {Y}Y yellow{Y}\n" \
"Colors: (B)B blue(B)  (C)C cyan(C)  (G)G green(G)  (P)P pink(P)  (R)R " \
"red(R)  (Y)Y yellow(Y)\n" \
"----\n" \
"Highlight\n" \
" Highlight\n" \
"-----\n" \
"WikiLinks are formed by two or more words in /camelcase/.\n" \
" WikiLinks are formed by two or more words in /camelcase/.\n" \
"External links begin with http://, like http://www.freepan.org\n" \
" External links begin with http://, like http://www.freepan.org\n" \
"Forced wiki [links] are a alphanumeric string surrounded by square bra" \
"ckets.\n" \
" Forced wiki [links] are a alphanumeric string surrounded by square br" \
"ackets.\n" \
"Named http links have text with an !http:// link inside, like [http://" \
"www.freepan.org FreePAN]\n" \
" Named http links have text with an !http:// link inside, like [http:/" \
"/www.freepan.org FreePAN]\n" \
"Sometimes !WordsShouldNotMakeAWikiLink so put a \"! \" beforehand.\n" \
" Sometimes !WordsShouldNotMakeAWikiLink so put a \"! \" beforehand.\n" \
"Same thing with !http://foobar.com\n" \
" Same thing with !http://foobar.com\n" \
"Open external links in new tags:\n" \
" {{wwwlink=new_tag}} opens external link in a new tag\n" \
" {{wwwlink=current_tag}} opens external link in a current tag\n" \
"----\n" \
"Links to images display the image:\n" \
" Pictures size and border: {{width=100 height=50 border=2}}\n" \
" Return to the default width, height and border: {{picture=default}}\n" \
"{{width=100 height=50 border=1}}\n" \
"http://www.google.com/images/logo.gif\n" \
" http://www.google.com/images/logo.gif\n" \
"Picture http links have picture with an !http:// link inside, like [ht" \
"tp://www.google.com/images/logo.gif http://www.google.com]\n" \
" Picture http links have picture with an !http:// link inside, like [h" \
"ttp://www.google.com/images/logo.gif http://www.google.com]\n" \
"----\n" \
" Video youtube, videomotion, veoh, vimeo, flash... embedded:\n" \
" youtube=http://www.youtube.com/v/---adress--- \n" \
" dailymotion=http://www.dailymotion.com/swf/---adress--- \n" \
" vimeo=http://..... veoh=http://..... flash=http://.....\n" \
" line starts with youtube... and terminate the adress with a space\n" \
"----\n" \
"Unordered lists begin with a \"* \". The number of asterisks determine" \
"s the level:\n" \
"* foo\n" \
"* bar\n" \
"** boom\n" \
"** bam\n" \
"* baz\n" \
"  * foo\n" \
"  * bar\n" \
"  ** boom\n" \
"  ** bam\n" \
"  * baz\n" \
"Ordered lists work the same, but use a \"#\"\n" \
"----\n" \
"Tables begin the line with a \"|\" and before every new column after.\n" \
"| row:1,col:1 | row:1,col:2\n" \
"| row:2,col:1 | row:2,col:2\n" \
" | row:1,col:1 | row:1,col:2\n" \
" | row:2,col:1 | row:2,col:2\n" \
"---\n" \
"Quotation begins with \"\n" \
" \"I had a monumental idea this morning, but I didn't like it\n" \
"\"I had a monumental idea this morning, but I didn't like it\n" \
"----\n" \
"Expand text\n" \
" {{expand}}  or  {{expand=your label here}}\n" \
" text, links, images\n" \
" {{-expand}}\n" \
"{{expand}}\n" \
"text, links: http://www.google.com\n" \
"{{-expand}}\n" \
"Imbricated\n" \
" {{expand}}\n" \
" Some text\n" \
" {{expand}}\n" \
" More text\n" \
" {{-expand}}\n" \
" {{-expand}}\n" \
"{{expand}}\n" \
"Some text\n" \
"{{expand}}\n" \
"More text\n" \
"{{-expand}}\n" \
"{{-expand}}\n" \
"----\n" \
"Collapse text, can be imbricated too.\n" \
" {{collapse}}  or  {{collapse=your label here}}\n" \
" text, links, images\n" \
" {{-collapse}}\n" \
"{{collapse}}\n" \
"text, links: http://www.google.com\n" \
"{{-collapse}}\n" \
"----\n" \
"Install:\n" \
"The file styles.css must be copied in ./didiwiki or in the home direct" \
"ory of didiwiki.\n" \
"----\n" \
"Simple form: ToDo list\n" \
" {{entry}} or {{entry tiny/small/medium/large/huge date}}\n" \
" !{{data}}   (remove ! before this tag)\n" \
" Entries are added in the page after the tag data\n" \
" {{delete}} deletes the selected field\n" \
" {{save}} saves the checked fields\n" \
"{{entry}}\n" \
"{{data}}\n" \
"{{delete}}{{save}}\n" \
"----\n" \
" Table of contents {{toc}} can be between collapse or expand\n" \
"{{collapse=Table of contents}}{{toc}}{{-collapse}}\n" \
"----\n" \
"<Inline> <html> <is> <escaped>.\n" \
"----\n" \
"Lines prefixed with a space are unformatted ( Like examples on this pa" \
"ge )\n" \
"----\n" \
" There is a `keyword` in this line.\n" \
"There is a `keyword` in this line.\n" \
"----\n" \
" Define a private zone in the page with {{private}}\n" \
" Login is required to show after this tag\n" \
"{{private}}\n" \
" This text is hidded if you are not logged!\n" \
"----\n"
gchar* wiki_file_as_html (WikiFile* self, GError** error);
static inline gchar* request_handler_get_header (RequestHandler* self, const gchar* title);
static inline gchar* request_handler_get_page_header (RequestHandler* self, const gchar* title);
static inline gchar* request_handler_get_page_footer (RequestHandler* self);
#define WIKI_TEXT_WIKIFOOTER "</body></html>"
static guint8* _vala_array_dup5 (guint8* self, int length);
#define WIKI_TEXT_PAGEHEADER "\n" \
"<!-- PAGEHEADER -->\n" \
"<div id=\"header\"> \n" \
"<form method=\"get\" action=\"Search\"> \n" \
"<table border=\"0\" width=\"100%%\"> \n" \
"<tr> \n" \
"<td align=\"left\" ><strong>%s</strong> %s</td> \n" \
"<td align=\"right\" > \n" \
"<a href=\"WikiHome\" title=\"Visit Wiki home page. [alt-z]\" accesskey" \
"=\"z\">Home</a> | \n" \
"<a href=\"Index\" title=\"List all pages in the wiki. [alt-i]\" access" \
"key=\"i\" >Index</a> | \n" \
"<a href=\"Changes\" title=\"List recent changes in the wiki. [alt-r]\"" \
" accesskey=\"r\" >Changes</a> | \n" \
"<a href=\"Create\" title=\"Create a new wiki page by title. [alt-c]\" " \
"accesskey=\"c\">New</a> |  \n" \
"<a href=\"WikiHelp\" title=\"Get help on wiki usage and formatting.\">" \
"Help</a>  \n" \
"<input type=\"text\" name=\"expr\" size=\"15\" title=\"Enter text to s" \
"earch for and press return.\" /> </td> \n" \
"</tr> \n" \
"</table> \n" \
"</form> \n" \
"</div> \n" \
"<div id=\"wikidata\"> \n"
#define WIKI_TEXT_WIKIHEADER "\n" \
"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"htt" \
"p://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n" \
"<!-- WIKIEHEADER -->\n" \
"<html xmlns=\"http://www.w3.org/1999/xhtml\"> \n" \
"<head> \n" \
"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"" \
" /> \n" \
"<link rel=\"SHORTCUT ICON\" href=\"favicon.ico\" /> \n" \
"<link media=\"all\" href=\"styles.css\" rel=\"STYLESHEET\" type=\"text" \
"/css\" /> \n" \
"<title>%s</title> \n" \
"</head> \n" \
"<body>\n"
#define WIKI_TEXT_PAGEFOOTER "\n" \
"<!-- PAGEFOOTER -->\n" \
"</div><div id=\"footer\">CiWiki alias DidiWiki, Version:  %s</div>\n"
#define VERSION "0.1.0"
static void request_handler_finalize (RequestHandler* obj);

extern const guchar FaviconData[198];

GQuark io_error_quark (void) {
	return g_quark_from_static_string ("io_error-quark");
}


RequestHandler* request_handler_construct (GType object_type, Request* req) {
	RequestHandler* self = NULL;
	Request _tmp0_;
	g_return_val_if_fail (req != NULL, NULL);
	self = (RequestHandler*) g_type_create_instance (object_type);
	_tmp0_ = *req;
	request_handler_set_req (self, &_tmp0_);
	return self;
}


RequestHandler* request_handler_new (Request* req) {
	return request_handler_construct (TYPE_REQUEST_HANDLER, req);
}


/**
 * Creates a reponse based on request
 */
static guint8* _vala_array_dup3 (guint8* self, int length) {
	return g_memdup (self, length * sizeof (guint8));
}


static guint8* string_get_data (const gchar* self, int* result_length1) {
	guint8* result;
	guint8* res;
	gint res_length1;
	gint _res_size_;
	gint _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	guint8* _tmp3_;
	gint _tmp3__length1;
	guint8* _tmp4_;
	gint _tmp4__length1;
	g_return_val_if_fail (self != NULL, NULL);
	res = (guint8*) self;
	res_length1 = -1;
	_res_size_ = res_length1;
	_tmp0_ = strlen (self);
	_tmp1_ = _tmp0_;
	res_length1 = (gint) _tmp1_;
	_tmp2_ = res_length1;
	_tmp3_ = res;
	_tmp3__length1 = res_length1;
	_tmp4_ = _tmp3_;
	_tmp4__length1 = _tmp3__length1;
	if (result_length1) {
		*result_length1 = _tmp4__length1;
	}
	result = _tmp4_;
	return result;
}


static guint8* _vala_array_dup4 (guint8* self, int length) {
	return g_memdup (self, length * sizeof (guint8));
}


void request_handler_get_response (RequestHandler* self, Response* result) {
	Response resp = {0};
	gchar* _tmp0_;
	gchar* _tmp1_;
	guint8* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	Request _tmp5_;
	const gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* page;
	const gchar* _tmp8_;
	const gchar* _tmp10_;
	const gchar* _tmp11_;
	GQuark _tmp13_ = 0U;
	static GQuark _tmp12_label0 = 0;
	static GQuark _tmp12_label1 = 0;
	Response _tmp20_;
	guint8* _tmp21_;
	gint _tmp21__length1;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	memset (&resp, 0, sizeof (Response));
	_tmp0_ = g_strdup (STATUS_CODE_OK);
	_g_free0 (resp.status_code);
	resp.status_code = _tmp0_;
	_tmp1_ = g_strdup ("text/html");
	_g_free0 (resp.content_type);
	resp.content_type = _tmp1_;
	_tmp2_ = g_new0 (guint8, 0);
	resp.data = (g_free (resp.data), NULL);
	resp.data = _tmp2_;
	resp.data_length1 = 0;
	_tmp3_ = request_handler_is_loggedin (self);
	if (!_tmp3_) {
		gchar* _tmp4_;
		_tmp4_ = g_strdup (STATUS_CODE_AUTH_REQ);
		_g_free0 (resp.status_code);
		resp.status_code = _tmp4_;
		*result = resp;
		return;
	}
	request_handler_debug (self);
	_tmp5_ = self->priv->_req;
	_tmp6_ = _tmp5_.object;
	_tmp7_ = g_strdup (_tmp6_);
	page = _tmp7_;
	_tmp8_ = page;
	if (g_strcmp0 (_tmp8_, "") == 0) {
		gchar* _tmp9_;
		_tmp9_ = g_strdup ("WikiHome");
		_g_free0 (page);
		page = _tmp9_;
	}
	_tmp10_ = page;
	_tmp11_ = _tmp10_;
	_tmp13_ = (NULL == _tmp11_) ? 0 : g_quark_from_string (_tmp11_);
	if (_tmp13_ == ((0 != _tmp12_label0) ? _tmp12_label0 : (_tmp12_label0 = g_quark_from_static_string ("favicon.ico")))) {
		switch (0) {
			default:
			{
				{
					gchar* _tmp14_;
					guint8* _tmp15_;
					gint _tmp15__length1;
					_tmp14_ = g_strdup ("image/ico");
					_g_free0 (resp.content_type);
					resp.content_type = _tmp14_;
					_tmp15_ = (FaviconData != NULL) ? _vala_array_dup3 (FaviconData, G_N_ELEMENTS (FaviconData)) : ((gpointer) FaviconData);
					_tmp15__length1 = G_N_ELEMENTS (FaviconData);
					resp.data = (g_free (resp.data), NULL);
					resp.data = _tmp15_;
					resp.data_length1 = _tmp15__length1;
				}
				break;
			}
		}
	} else if (_tmp13_ == ((0 != _tmp12_label1) ? _tmp12_label1 : (_tmp12_label1 = g_quark_from_static_string ("styles.css")))) {
		switch (0) {
			default:
			{
				{
					gchar* _tmp16_;
					guint8* _tmp17_;
					gint _tmp17__length1;
					guint8* _tmp18_;
					gint _tmp18__length1;
					guint8* _tmp19_;
					gint _tmp19__length1;
					_tmp16_ = g_strdup ("text/css");
					_g_free0 (resp.content_type);
					resp.content_type = _tmp16_;
					_tmp17_ = string_get_data (WIKI_TEXT_STYLESHEET, &_tmp17__length1);
					_tmp18_ = _tmp17_;
					_tmp18__length1 = _tmp17__length1;
					_tmp19_ = (_tmp18_ != NULL) ? _vala_array_dup4 (_tmp18_, _tmp18__length1) : ((gpointer) _tmp18_);
					_tmp19__length1 = _tmp18__length1;
					resp.data = (g_free (resp.data), NULL);
					resp.data = _tmp19_;
					resp.data_length1 = _tmp19__length1;
				}
				break;
			}
		}
	}
	_tmp20_ = resp;
	_tmp21_ = _tmp20_.data;
	_tmp21__length1 = _tmp20_.data_length1;
	if (_tmp21__length1 == 0) {
		{
			const gchar* _tmp22_;
			gint _tmp23_ = 0;
			guint8* _tmp24_ = NULL;
			guint8* _tmp25_;
			gint _tmp25__length1;
			gint __tmp25__size_;
			_tmp22_ = page;
			_tmp24_ = request_handler_get_page (self, _tmp22_, &_tmp23_, &_inner_error_);
			_tmp25_ = _tmp24_;
			_tmp25__length1 = _tmp23_;
			__tmp25__size_ = _tmp25__length1;
			if (_inner_error_ != NULL) {
				goto __catch4_g_error;
			}
			resp.data = (g_free (resp.data), NULL);
			resp.data = _tmp25_;
			resp.data_length1 = _tmp25__length1;
		}
		goto __finally4;
		__catch4_g_error:
		{
			const gchar* _tmp26_;
			gchar* _tmp27_ = NULL;
			gchar* _tmp28_;
			FILE* _tmp29_;
			g_clear_error (&_inner_error_);
			_inner_error_ = NULL;
			_tmp26_ = page;
			_tmp27_ = g_strdup_printf ("WikiPage >%s< not found.", _tmp26_);
			_g_free0 (resp.text);
			resp.text = _tmp27_;
			_tmp28_ = g_strdup (STATUS_CODE_FILE_NOT_FOUND);
			_g_free0 (resp.status_code);
			resp.status_code = _tmp28_;
			_tmp29_ = stderr;
			fprintf (_tmp29_, "No content found\n");
		}
		__finally4:
		if (_inner_error_ != NULL) {
			_g_free0 (page);
			response_destroy (&resp);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	*result = resp;
	_g_free0 (page);
	return;
}


static gboolean request_handler_is_loggedin (RequestHandler* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	result = FALSE;
	return result;
}


/**
 * Creates WikiHome/ WikiHelp if necessary
 */
static void request_handler_create_default_pages (RequestHandler* self, const gchar* page) {
	gboolean _tmp0_ = FALSE;
	const gchar* _tmp1_;
	gboolean _tmp3_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (page != NULL);
	_tmp1_ = page;
	if (g_strcmp0 (_tmp1_, "WikiHome") == 0) {
		_tmp0_ = TRUE;
	} else {
		const gchar* _tmp2_;
		_tmp2_ = page;
		_tmp0_ = g_strcmp0 (_tmp2_, "WikiHelp") == 0;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		const gchar* _tmp4_;
		WikiFile* _tmp5_;
		WikiFile* file;
		WikiFile* _tmp6_;
		gboolean _tmp7_ = FALSE;
		_tmp4_ = page;
		_tmp5_ = wiki_file_new (_tmp4_);
		file = _tmp5_;
		_tmp6_ = file;
		_tmp7_ = wiki_file_exists (_tmp6_);
		if (!_tmp7_) {
			const gchar* _tmp8_;
			const gchar* _tmp9_;
			GQuark _tmp11_ = 0U;
			static GQuark _tmp10_label0 = 0;
			static GQuark _tmp10_label1 = 0;
			_tmp8_ = page;
			_tmp9_ = _tmp8_;
			_tmp11_ = (NULL == _tmp9_) ? 0 : g_quark_from_string (_tmp9_);
			if (_tmp11_ == ((0 != _tmp10_label0) ? _tmp10_label0 : (_tmp10_label0 = g_quark_from_static_string ("WikiHome")))) {
				switch (0) {
					default:
					{
						{
							WikiFile* _tmp12_;
							_tmp12_ = file;
							wiki_file_store_text (_tmp12_, WIKI_TEXT_HOMETEXT);
						}
						break;
					}
				}
			} else if (_tmp11_ == ((0 != _tmp10_label1) ? _tmp10_label1 : (_tmp10_label1 = g_quark_from_static_string ("WikiHelp")))) {
				switch (0) {
					default:
					{
						{
							WikiFile* _tmp13_;
							_tmp13_ = file;
							wiki_file_store_text (_tmp13_, WIKI_TEXT_HELPTEXT);
						}
						break;
					}
				}
			}
		}
		_g_object_unref0 (file);
	}
}


static guint8* _vala_array_dup5 (guint8* self, int length) {
	return g_memdup (self, length * sizeof (guint8));
}


static guint8* request_handler_get_page (RequestHandler* self, const gchar* page, int* result_length1, GError** error) {
	guint8* result = NULL;
	gchar* _tmp0_;
	gchar* content;
	const gchar* _tmp1_;
	WikiFile* _tmp2_;
	WikiFile* file;
	WikiFile* _tmp3_;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp6_ = FALSE;
	WikiFile* _tmp7_;
	gboolean _tmp8_ = FALSE;
	gboolean _tmp13_;
	const gchar* _tmp15_;
	gchar* _tmp16_ = NULL;
	gchar* _tmp17_;
	const gchar* _tmp18_;
	gchar* _tmp19_ = NULL;
	gchar* _tmp20_;
	gchar* _tmp21_;
	gchar* _tmp22_;
	const gchar* _tmp23_;
	gchar* _tmp24_;
	gchar* _tmp25_;
	gchar* _tmp26_ = NULL;
	gchar* _tmp27_;
	gchar* _tmp28_;
	gchar* _tmp29_;
	gchar* _tmp30_;
	gchar* _tmp31_;
	gchar* _result_;
	const gchar* _tmp32_;
	guint8* _tmp33_;
	gint _tmp33__length1;
	guint8* _tmp34_;
	gint _tmp34__length1;
	guint8* _tmp35_;
	gint _tmp35__length1;
	guint8* _tmp36_;
	gint _tmp36__length1;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (page != NULL, NULL);
	_tmp0_ = g_strdup ("");
	content = _tmp0_;
	_tmp1_ = page;
	_tmp2_ = wiki_file_new (_tmp1_);
	file = _tmp2_;
	_tmp3_ = file;
	_tmp4_ = wiki_file_exists (_tmp3_);
	if (!_tmp4_) {
		const gchar* _tmp5_;
		_tmp5_ = page;
		request_handler_create_default_pages (self, _tmp5_);
	}
	_tmp7_ = file;
	_tmp8_ = wiki_file_exists (_tmp7_);
	if (!_tmp8_) {
		_tmp6_ = TRUE;
	} else {
		WikiFile* _tmp9_;
		gchar* _tmp10_ = NULL;
		gchar* _tmp11_;
		const gchar* _tmp12_;
		_tmp9_ = file;
		_tmp10_ = wiki_file_as_html (_tmp9_, &_inner_error_);
		_tmp11_ = _tmp10_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == IO_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_object_unref0 (file);
				_g_free0 (content);
				return NULL;
			} else {
				_g_object_unref0 (file);
				_g_free0 (content);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
		_g_free0 (content);
		content = _tmp11_;
		_tmp12_ = content;
		_tmp6_ = _tmp12_ == NULL;
	}
	_tmp13_ = _tmp6_;
	if (_tmp13_) {
		GError* _tmp14_;
		_tmp14_ = g_error_new_literal (IO_ERROR, IO_ERROR_FILE_NOT_FOUND, "Requested page could not be found.");
		_inner_error_ = _tmp14_;
		if (_inner_error_->domain == IO_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (file);
			_g_free0 (content);
			return NULL;
		} else {
			_g_object_unref0 (file);
			_g_free0 (content);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp15_ = page;
	_tmp16_ = request_handler_get_header (self, _tmp15_);
	_tmp17_ = _tmp16_;
	_tmp18_ = page;
	_tmp19_ = request_handler_get_page_header (self, _tmp18_);
	_tmp20_ = _tmp19_;
	_tmp21_ = g_strconcat (_tmp17_, _tmp20_, NULL);
	_tmp22_ = _tmp21_;
	_tmp23_ = content;
	_tmp24_ = g_strconcat (_tmp22_, _tmp23_, NULL);
	_tmp25_ = _tmp24_;
	_tmp26_ = request_handler_get_page_footer (self);
	_tmp27_ = _tmp26_;
	_tmp28_ = g_strconcat (_tmp25_, _tmp27_, NULL);
	_tmp29_ = _tmp28_;
	_tmp30_ = g_strconcat (_tmp29_, WIKI_TEXT_WIKIFOOTER, NULL);
	_tmp31_ = _tmp30_;
	_g_free0 (_tmp29_);
	_g_free0 (_tmp27_);
	_g_free0 (_tmp25_);
	_g_free0 (_tmp22_);
	_g_free0 (_tmp20_);
	_g_free0 (_tmp17_);
	_result_ = _tmp31_;
	_tmp32_ = _result_;
	_tmp33_ = string_get_data (_tmp32_, &_tmp33__length1);
	_tmp34_ = _tmp33_;
	_tmp34__length1 = _tmp33__length1;
	_tmp35_ = (_tmp34_ != NULL) ? _vala_array_dup5 (_tmp34_, _tmp34__length1) : ((gpointer) _tmp34_);
	_tmp35__length1 = _tmp34__length1;
	_tmp36_ = _tmp35_;
	_tmp36__length1 = _tmp35__length1;
	if (result_length1) {
		*result_length1 = _tmp36__length1;
	}
	result = _tmp36_;
	_g_free0 (_result_);
	_g_object_unref0 (file);
	_g_free0 (content);
	return result;
}


static inline gchar* request_handler_get_page_header (RequestHandler* self, const gchar* title) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	_tmp0_ = title;
	_tmp1_ = g_strdup_printf (WIKI_TEXT_PAGEHEADER, _tmp0_, "Edit");
	result = _tmp1_;
	return result;
}


static inline gchar* request_handler_get_header (RequestHandler* self, const gchar* title) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (title != NULL, NULL);
	_tmp0_ = title;
	_tmp1_ = g_strdup_printf (WIKI_TEXT_WIKIHEADER, _tmp0_);
	result = _tmp1_;
	return result;
}


static inline gchar* request_handler_get_page_footer (RequestHandler* self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup_printf (WIKI_TEXT_PAGEFOOTER, VERSION);
	result = _tmp0_;
	return result;
}


static void request_handler_debug (RequestHandler* self) {
	FILE* _tmp0_;
	Request _tmp1_;
	const gchar* _tmp2_;
	Request _tmp3_;
	const gchar* _tmp4_;
	Request _tmp5_;
	const gchar* _tmp6_;
	Request _tmp7_;
	const gchar* _tmp8_;
	Request _tmp9_;
	const gchar* _tmp10_;
	g_return_if_fail (self != NULL);
	_tmp0_ = stdout;
	_tmp1_ = self->priv->_req;
	_tmp2_ = _tmp1_.path;
	_tmp3_ = self->priv->_req;
	_tmp4_ = _tmp3_.query;
	_tmp5_ = self->priv->_req;
	_tmp6_ = _tmp5_.object;
	_tmp7_ = self->priv->_req;
	_tmp8_ = _tmp7_.action;
	_tmp9_ = self->priv->_req;
	_tmp10_ = _tmp9_.val;
	fprintf (_tmp0_, "[REQUEST: path=%s, query=%s, object=%s, action=%s, val=%s]\n", _tmp2_, _tmp4_, _tmp6_, _tmp8_, _tmp10_);
}


void request_handler_get_req (RequestHandler* self, Request* result) {
	Request _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_req;
	*result = _tmp0_;
	return;
}


void request_handler_set_req (RequestHandler* self, Request* value) {
	Request _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = *value;
	self->priv->_req = _tmp0_;
}


static void value_request_handler_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_request_handler_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		request_handler_unref (value->data[0].v_pointer);
	}
}


static void value_request_handler_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = request_handler_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_request_handler_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_request_handler_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		RequestHandler* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = request_handler_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_request_handler_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	RequestHandler** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = request_handler_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_request_handler (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecRequestHandler* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_REQUEST_HANDLER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_request_handler (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_REQUEST_HANDLER), NULL);
	return value->data[0].v_pointer;
}


void value_set_request_handler (GValue* value, gpointer v_object) {
	RequestHandler* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_REQUEST_HANDLER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_REQUEST_HANDLER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		request_handler_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		request_handler_unref (old);
	}
}


void value_take_request_handler (GValue* value, gpointer v_object) {
	RequestHandler* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_REQUEST_HANDLER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_REQUEST_HANDLER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		request_handler_unref (old);
	}
}


static void request_handler_class_init (RequestHandlerClass * klass) {
	request_handler_parent_class = g_type_class_peek_parent (klass);
	REQUEST_HANDLER_CLASS (klass)->finalize = request_handler_finalize;
	g_type_class_add_private (klass, sizeof (RequestHandlerPrivate));
}


static void request_handler_instance_init (RequestHandler * self) {
	self->priv = REQUEST_HANDLER_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void request_handler_finalize (RequestHandler* obj) {
	RequestHandler * self;
	self = REQUEST_HANDLER (obj);
}


GType request_handler_get_type (void) {
	static volatile gsize request_handler_type_id__volatile = 0;
	if (g_once_init_enter (&request_handler_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_request_handler_init, value_request_handler_free_value, value_request_handler_copy_value, value_request_handler_peek_pointer, "p", value_request_handler_collect_value, "p", value_request_handler_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (RequestHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) request_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RequestHandler), 0, (GInstanceInitFunc) request_handler_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType request_handler_type_id;
		request_handler_type_id = g_type_register_fundamental (g_type_fundamental_next (), "RequestHandler", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&request_handler_type_id__volatile, request_handler_type_id);
	}
	return request_handler_type_id__volatile;
}


gpointer request_handler_ref (gpointer instance) {
	RequestHandler* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void request_handler_unref (gpointer instance) {
	RequestHandler* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		REQUEST_HANDLER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



