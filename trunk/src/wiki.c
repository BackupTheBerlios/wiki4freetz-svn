/* wiki.c generated by valac 0.16.1, the Vala compiler
 * generated from wiki.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gio/gio.h>

#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define TYPE_WEB_SERVER (web_server_get_type ())
#define WEB_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_WEB_SERVER, WebServer))
#define WEB_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_WEB_SERVER, WebServerClass))
#define IS_WEB_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_WEB_SERVER))
#define IS_WEB_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_WEB_SERVER))
#define WEB_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_WEB_SERVER, WebServerClass))

typedef struct _WebServer WebServer;
typedef struct _WebServerClass WebServerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_REQUEST (request_get_type ())
typedef struct _Request Request;

#define TYPE_RESPONSE (response_get_type ())
typedef struct _Response Response;
typedef struct _WebServerPrivate WebServerPrivate;
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))

#define TYPE_REQUEST_HANDLER (request_handler_get_type ())
#define REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_REQUEST_HANDLER, RequestHandler))
#define REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_REQUEST_HANDLER, RequestHandlerClass))
#define IS_REQUEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_REQUEST_HANDLER))
#define IS_REQUEST_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_REQUEST_HANDLER))
#define REQUEST_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_REQUEST_HANDLER, RequestHandlerClass))

typedef struct _RequestHandler RequestHandler;
typedef struct _RequestHandlerClass RequestHandlerClass;
#define _request_handler_unref0(var) ((var == NULL) ? NULL : (var = (request_handler_unref (var), NULL)))

struct _Request {
	gchar* full_request;
	gchar* path;
	gchar* query;
	gchar* object;
	gchar* action;
	gchar* val;
};

struct _Response {
	gchar* status_code;
	gchar* content_type;
	gchar* text;
	guint8* data;
	gint data_length1;
};

struct _WebServer {
	GObject parent_instance;
	WebServerPrivate * priv;
};

struct _WebServerClass {
	GObjectClass parent_class;
};

struct _WebServerPrivate {
	const gchar* _base_dir;
	guint16 _port;
};


extern gboolean show_version;
gboolean show_version = FALSE;
extern gboolean auto_login;
gboolean auto_login = FALSE;
extern gchar* listen;
gchar* listen = NULL;
extern gint port;
gint port = 0;
extern gchar* home;
gchar* home = NULL;
extern gboolean restore;
gboolean restore = FALSE;
extern gboolean sendmail;
gboolean sendmail = FALSE;
static gpointer web_server_parent_class = NULL;

#define VERSION "0.1.0"
#define DEFAULT_PORT 8001
#define DEFAULT_DIR "/tmp/wiki"
#define FaviconDataLen ((guint) 198)
void _vala_main (gchar** args, int args_length1);
WebServer* web_server_new (guint16 port, const gchar* dir);
WebServer* web_server_construct (GType object_type, guint16 port, const gchar* dir);
GType web_server_get_type (void) G_GNUC_CONST;
void web_server_run (WebServer* self);
GType request_get_type (void) G_GNUC_CONST;
Request* request_dup (const Request* self);
void request_free (Request* self);
void request_copy (const Request* self, Request* dest);
void request_destroy (Request* self);
GType response_get_type (void) G_GNUC_CONST;
Response* response_dup (const Response* self);
void response_free (Response* self);
void response_copy (const Response* self, Response* dest);
void response_destroy (Response* self);
static guint8* _vala_array_dup1 (guint8* self, int length);
#define WEB_SERVER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_WEB_SERVER, WebServerPrivate))
enum  {
	WEB_SERVER_DUMMY_PROPERTY
};
static void web_server_set_base_dir (WebServer* self, const gchar* value);
static void web_server_set_port (WebServer* self, guint16 value);
void web_server_serve_response (WebServer* self, Response* response, GDataOutputStream* dos);
static guint8* _vala_array_dup2 (guint8* self, int length);
#define STATUS_CODE_AUTH_REQ "HTTP/1.1 401 Unauthorized"
void web_server_get_request (WebServer* self, const gchar* line, Request* result);
static guint16 web_server_get_port (WebServer* self);
gboolean web_server_connection_handler (WebServer* self, GSocketConnection* connection);
static gboolean _web_server_connection_handler_g_threaded_socket_service_run (GThreadedSocketService* _sender, GSocketConnection* connection, GObject* source_object, gpointer self);
RequestHandler* request_handler_new (Request* req);
RequestHandler* request_handler_construct (GType object_type, Request* req);
gpointer request_handler_ref (gpointer instance);
void request_handler_unref (gpointer instance);
GParamSpec* param_spec_request_handler (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_request_handler (GValue* value, gpointer v_object);
void value_take_request_handler (GValue* value, gpointer v_object);
gpointer value_get_request_handler (const GValue* value);
GType request_handler_get_type (void) G_GNUC_CONST;
void request_handler_get_response (RequestHandler* self, Response* result);
static const gchar* web_server_get_base_dir (WebServer* self);
static void web_server_finalize (GObject* obj);
static void _vala_web_server_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_web_server_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);

const guchar FaviconData[198] = {(guchar) 0x00, (guchar) 0x00, (guchar) 0x01, (guchar) 0x00, (guchar) 0x01, (guchar) 0x00, (guchar) 0x10, (guchar) 0x10, (guchar) 0x02, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0xb0, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x16, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x28, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x10, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x20, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x01, (guchar) 0x00, (guchar) 0x01, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x40, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x02, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0xff, (guchar) 0xff, (guchar) 0xee, (guchar) 0x00, (guchar) 0xff, (guchar) 0xff, (guchar) 0x00, (guchar) 0x00, (guchar) 0xff, (guchar) 0xff, (guchar) 0x00, (guchar) 0x00, (guchar) 0xba, (guchar) 0xab, (guchar) 0x00, (guchar) 0x00, (guchar) 0x92, (guchar) 0xab, (guchar) 0x00, (guchar) 0x00, (guchar) 0xaa, (guchar) 0x9b, (guchar) 0x00, (guchar) 0x00, (guchar) 0xbb, (guchar) 0xaf, (guchar) 0x00, (guchar) 0x00, (guchar) 0xba, (guchar) 0xab, (guchar) 0x00, (guchar) 0x00, (guchar) 0xff, (guchar) 0xff, (guchar) 0x00, (guchar) 0x00, (guchar) 0xff, (guchar) 0xff, (guchar) 0x00, (guchar) 0x00, (guchar) 0x8d, (guchar) 0x1b, (guchar) 0x00, (guchar) 0x00, (guchar) 0xb5, (guchar) 0x6b, (guchar) 0x00, (guchar) 0x00, (guchar) 0xb5, (guchar) 0x6b, (guchar) 0x00, (guchar) 0x00, (guchar) 0xb7, (guchar) 0x6f, (guchar) 0x00, (guchar) 0x00, (guchar) 0x8d, (guchar) 0x1b, (guchar) 0x00, (guchar) 0x00, (guchar) 0xff, (guchar) 0xff, (guchar) 0x00, (guchar) 0x00, (guchar) 0xff, (guchar) 0xff, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00, (guchar) 0x00};
const GOptionEntry options[8] = {{"version", 'v', 0, G_OPTION_ARG_NONE, &show_version, "Show application's version", NULL}, {"autologin", 'a', 0, G_OPTION_ARG_NONE, &auto_login, "Flag to login local users automatically", NULL}, {"listen", 'l', 0, G_OPTION_ARG_STRING, &show_version, "IP-Range to listen for", NULL}, {"port", 'p', 0, G_OPTION_ARG_INT, &show_version, "Port to listen for", NULL}, {"home", 'h', 0, G_OPTION_ARG_STRING, &show_version, "Wiki's home directory", NULL}, {"restore", 'r', 0, G_OPTION_ARG_NONE, &show_version, "Restore Wiki help file", NULL}, {"sendmail", 's', 0, G_OPTION_ARG_NONE, &show_version, "Enables send mail functionality", NULL}, {NULL}};

void _vala_main (gchar** args, int args_length1) {
	gboolean _tmp7_;
	gint _tmp9_;
	const gchar* _tmp10_;
	FILE* _tmp12_;
	FILE* _tmp13_;
	const gchar* _tmp14_;
	gint _tmp15_;
	const gchar* _tmp16_;
	WebServer* _tmp17_;
	WebServer* ws;
	WebServer* _tmp18_;
	GError * _inner_error_ = NULL;
	{
		GOptionContext* _tmp0_;
		GOptionContext* opt_context;
		_tmp0_ = g_option_context_new ("- Genie Wiki");
		opt_context = _tmp0_;
		g_option_context_set_help_enabled (opt_context, TRUE);
		g_option_context_add_main_entries (opt_context, options, NULL);
		g_option_context_parse (opt_context, &args_length1, &args, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_option_context_free0 (opt_context);
			if (_inner_error_->domain == G_OPTION_ERROR) {
				goto __catch0_g_option_error;
			}
			_g_option_context_free0 (opt_context);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_g_option_context_free0 (opt_context);
	}
	goto __finally0;
	__catch0_g_option_error:
	{
		GError* e = NULL;
		FILE* _tmp1_;
		GError* _tmp2_;
		const gchar* _tmp3_;
		FILE* _tmp4_;
		gchar** _tmp5_;
		gint _tmp5__length1;
		const gchar* _tmp6_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp1_ = stdout;
		_tmp2_ = e;
		_tmp3_ = _tmp2_->message;
		fprintf (_tmp1_, "%s\n", _tmp3_);
		_tmp4_ = stdout;
		_tmp5_ = args;
		_tmp5__length1 = args_length1;
		_tmp6_ = _tmp5_[0];
		fprintf (_tmp4_, "Run '%s --help' to see a full list of available command line options.\n", _tmp6_);
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp7_ = show_version;
	if (_tmp7_) {
		FILE* _tmp8_;
		_tmp8_ = stdout;
		fprintf (_tmp8_, "GenieWiki - version %s\n\n", VERSION);
		return;
	}
	_tmp9_ = port;
	if (_tmp9_ == 0) {
		port = DEFAULT_PORT;
	}
	_tmp10_ = home;
	if (_tmp10_ == NULL) {
		gchar* _tmp11_;
		_tmp11_ = g_strdup (DEFAULT_DIR);
		_g_free0 (home);
		home = _tmp11_;
	}
	_tmp12_ = stdout;
	fprintf (_tmp12_, "GenieWiki is starting ...\n");
	_tmp13_ = stdout;
	_tmp14_ = home;
	fprintf (_tmp13_, "Wiki directory = %s\n", _tmp14_);
	_tmp15_ = port;
	_tmp16_ = home;
	_tmp17_ = web_server_new ((guint16) _tmp15_, _tmp16_);
	ws = _tmp17_;
	_tmp18_ = ws;
	web_server_run (_tmp18_);
	_g_object_unref0 (ws);
}


int main (int argc, char ** argv) {
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
}


void request_copy (const Request* self, Request* dest) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	gchar* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_;
	const gchar* _tmp10_;
	gchar* _tmp11_;
	_tmp0_ = (*self).full_request;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 ((*dest).full_request);
	(*dest).full_request = _tmp1_;
	_tmp2_ = (*self).path;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 ((*dest).path);
	(*dest).path = _tmp3_;
	_tmp4_ = (*self).query;
	_tmp5_ = g_strdup (_tmp4_);
	_g_free0 ((*dest).query);
	(*dest).query = _tmp5_;
	_tmp6_ = (*self).object;
	_tmp7_ = g_strdup (_tmp6_);
	_g_free0 ((*dest).object);
	(*dest).object = _tmp7_;
	_tmp8_ = (*self).action;
	_tmp9_ = g_strdup (_tmp8_);
	_g_free0 ((*dest).action);
	(*dest).action = _tmp9_;
	_tmp10_ = (*self).val;
	_tmp11_ = g_strdup (_tmp10_);
	_g_free0 ((*dest).val);
	(*dest).val = _tmp11_;
}


void request_destroy (Request* self) {
	_g_free0 ((*self).full_request);
	_g_free0 ((*self).path);
	_g_free0 ((*self).query);
	_g_free0 ((*self).object);
	_g_free0 ((*self).action);
	_g_free0 ((*self).val);
}


Request* request_dup (const Request* self) {
	Request* dup;
	dup = g_new0 (Request, 1);
	request_copy (self, dup);
	return dup;
}


void request_free (Request* self) {
	request_destroy (self);
	g_free (self);
}


GType request_get_type (void) {
	static volatile gsize request_type_id__volatile = 0;
	if (g_once_init_enter (&request_type_id__volatile)) {
		GType request_type_id;
		request_type_id = g_boxed_type_register_static ("Request", (GBoxedCopyFunc) request_dup, (GBoxedFreeFunc) request_free);
		g_once_init_leave (&request_type_id__volatile, request_type_id);
	}
	return request_type_id__volatile;
}


static guint8* _vala_array_dup1 (guint8* self, int length) {
	return g_memdup (self, length * sizeof (guint8));
}


void response_copy (const Response* self, Response* dest) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	guint8* _tmp6_;
	gint _tmp6__length1;
	guint8* _tmp7_;
	gint _tmp7__length1;
	_tmp0_ = (*self).status_code;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 ((*dest).status_code);
	(*dest).status_code = _tmp1_;
	_tmp2_ = (*self).content_type;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 ((*dest).content_type);
	(*dest).content_type = _tmp3_;
	_tmp4_ = (*self).text;
	_tmp5_ = g_strdup (_tmp4_);
	_g_free0 ((*dest).text);
	(*dest).text = _tmp5_;
	_tmp6_ = (*self).data;
	_tmp6__length1 = (*self).data_length1;
	_tmp7_ = (_tmp6_ != NULL) ? _vala_array_dup1 (_tmp6_, _tmp6__length1) : ((gpointer) _tmp6_);
	_tmp7__length1 = _tmp6__length1;
	(*dest).data = (g_free ((*dest).data), NULL);
	(*dest).data = _tmp7_;
	(*dest).data_length1 = _tmp7__length1;
}


void response_destroy (Response* self) {
	_g_free0 ((*self).status_code);
	_g_free0 ((*self).content_type);
	_g_free0 ((*self).text);
	(*self).data = (g_free ((*self).data), NULL);
}


Response* response_dup (const Response* self) {
	Response* dup;
	dup = g_new0 (Response, 1);
	response_copy (self, dup);
	return dup;
}


void response_free (Response* self) {
	response_destroy (self);
	g_free (self);
}


GType response_get_type (void) {
	static volatile gsize response_type_id__volatile = 0;
	if (g_once_init_enter (&response_type_id__volatile)) {
		GType response_type_id;
		response_type_id = g_boxed_type_register_static ("Response", (GBoxedCopyFunc) response_dup, (GBoxedFreeFunc) response_free);
		g_once_init_leave (&response_type_id__volatile, response_type_id);
	}
	return response_type_id__volatile;
}


/**
 * Constructs a web server object
 */
WebServer* web_server_construct (GType object_type, guint16 port, const gchar* dir) {
	WebServer * self = NULL;
	const gchar* _tmp0_;
	guint16 _tmp1_;
	g_return_val_if_fail (dir != NULL, NULL);
	self = (WebServer*) g_object_new (object_type, NULL);
	_tmp0_ = dir;
	web_server_set_base_dir (self, _tmp0_);
	_tmp1_ = port;
	web_server_set_port (self, _tmp1_);
	return self;
}


WebServer* web_server_new (guint16 port, const gchar* dir) {
	return web_server_construct (TYPE_WEB_SERVER, port, dir);
}


/**
 * Send response to HTTP client
 */
static guint8* _vala_array_dup2 (guint8* self, int length) {
	return g_memdup (self, length * sizeof (guint8));
}


void web_server_serve_response (WebServer* self, Response* response, GDataOutputStream* dos) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (response != NULL);
	g_return_if_fail (dos != NULL);
	{
		Response _tmp0_;
		guint8* _tmp1_;
		gint _tmp1__length1;
		guint8* _tmp2_;
		gint _tmp2__length1;
		guint8* data;
		gint data_length1;
		gint _data_size_;
		GDataOutputStream* _tmp3_;
		Response _tmp4_;
		const gchar* _tmp5_;
		GDataOutputStream* _tmp6_;
		GDataOutputStream* _tmp7_;
		Response _tmp8_;
		const gchar* _tmp9_;
		gchar* _tmp10_ = NULL;
		gchar* _tmp11_;
		GDataOutputStream* _tmp12_;
		guint8* _tmp13_;
		gint _tmp13__length1;
		gchar* _tmp14_ = NULL;
		gchar* _tmp15_;
		Response _tmp16_;
		const gchar* _tmp17_;
		GDataOutputStream* _tmp19_;
		glong written;
		_tmp0_ = *response;
		_tmp1_ = _tmp0_.data;
		_tmp1__length1 = _tmp0_.data_length1;
		_tmp2_ = (_tmp1_ != NULL) ? _vala_array_dup2 (_tmp1_, _tmp1__length1) : ((gpointer) _tmp1_);
		_tmp2__length1 = _tmp1__length1;
		data = _tmp2_;
		data_length1 = _tmp2__length1;
		_data_size_ = data_length1;
		_tmp3_ = dos;
		_tmp4_ = *response;
		_tmp5_ = _tmp4_.status_code;
		g_data_output_stream_put_string (_tmp3_, _tmp5_, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			data = (g_free (data), NULL);
			goto __catch1_g_error;
		}
		_tmp6_ = dos;
		g_data_output_stream_put_string (_tmp6_, "Server: GenieWiki\n", NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			data = (g_free (data), NULL);
			goto __catch1_g_error;
		}
		_tmp7_ = dos;
		_tmp8_ = *response;
		_tmp9_ = _tmp8_.content_type;
		_tmp10_ = g_strdup_printf ("Content-Type: %s\n", _tmp9_);
		_tmp11_ = _tmp10_;
		g_data_output_stream_put_string (_tmp7_, _tmp11_, NULL, &_inner_error_);
		_g_free0 (_tmp11_);
		if (_inner_error_ != NULL) {
			data = (g_free (data), NULL);
			goto __catch1_g_error;
		}
		_tmp12_ = dos;
		_tmp13_ = data;
		_tmp13__length1 = data_length1;
		_tmp14_ = g_strdup_printf ("Content-Length: %d\n", _tmp13__length1);
		_tmp15_ = _tmp14_;
		g_data_output_stream_put_string (_tmp12_, _tmp15_, NULL, &_inner_error_);
		_g_free0 (_tmp15_);
		if (_inner_error_ != NULL) {
			data = (g_free (data), NULL);
			goto __catch1_g_error;
		}
		_tmp16_ = *response;
		_tmp17_ = _tmp16_.status_code;
		if (g_strcmp0 (_tmp17_, STATUS_CODE_AUTH_REQ) == 0) {
			GDataOutputStream* _tmp18_;
			_tmp18_ = dos;
			g_data_output_stream_put_string (_tmp18_, "WWW-Authenticate: Basic realm=\"insert realm\"\n", NULL, &_inner_error_);
			if (_inner_error_ != NULL) {
				data = (g_free (data), NULL);
				goto __catch1_g_error;
			}
		}
		_tmp19_ = dos;
		g_data_output_stream_put_string (_tmp19_, "\n", NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			data = (g_free (data), NULL);
			goto __catch1_g_error;
		}
		written = (glong) 0;
		while (TRUE) {
			glong _tmp20_;
			guint8* _tmp21_;
			gint _tmp21__length1;
			GDataOutputStream* _tmp22_;
			guint8* _tmp23_;
			gint _tmp23__length1;
			glong _tmp24_;
			guint8* _tmp25_;
			gint _tmp25__length1;
			gssize _tmp26_ = 0L;
			gssize _tmp27_;
			glong _tmp28_;
			_tmp20_ = written;
			_tmp21_ = data;
			_tmp21__length1 = data_length1;
			if (!(_tmp20_ < ((glong) _tmp21__length1))) {
				break;
			}
			_tmp22_ = dos;
			_tmp23_ = data;
			_tmp23__length1 = data_length1;
			_tmp24_ = written;
			_tmp25_ = data;
			_tmp25__length1 = data_length1;
			_tmp26_ = g_output_stream_write ((GOutputStream*) _tmp22_, _tmp23_ + _tmp24_, (gsize) (_tmp25__length1 - _tmp24_), NULL, &_inner_error_);
			_tmp27_ = _tmp26_;
			if (_inner_error_ != NULL) {
				data = (g_free (data), NULL);
				goto __catch1_g_error;
			}
			_tmp28_ = written;
			written = _tmp28_ + _tmp27_;
		}
		data = (g_free (data), NULL);
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError* e = NULL;
		FILE* _tmp29_;
		GError* _tmp30_;
		const gchar* _tmp31_;
		gchar* _tmp32_;
		gchar* _tmp33_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp29_ = stderr;
		_tmp30_ = e;
		_tmp31_ = _tmp30_->message;
		_tmp32_ = g_strconcat (_tmp31_, "\n", NULL);
		_tmp33_ = _tmp32_;
		fprintf (_tmp29_, "%s", _tmp33_);
		_g_free0 (_tmp33_);
		_g_error_free0 (e);
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


void web_server_get_request (WebServer* self, const gchar* line, Request* result) {
	Request r = {0};
	const gchar* _tmp0_;
	gchar** _tmp1_;
	gchar** _tmp2_ = NULL;
	gchar** parts;
	gint parts_length1;
	gint _parts_size_;
	gchar** _tmp3_;
	gint _tmp3__length1;
	gchar** _tmp4_;
	gint _tmp4__length1;
	const gchar* _tmp5_;
	gchar* _tmp6_;
	Request _tmp7_;
	const gchar* _tmp8_;
	gchar** _tmp9_;
	gchar** _tmp10_ = NULL;
	gchar** _tmp11_;
	gint _tmp11__length1;
	const gchar* _tmp12_;
	gchar* _tmp13_;
	gchar** _tmp14_;
	gint _tmp14__length1;
	const gchar* _tmp15_;
	gchar* _tmp16_;
	Request _tmp17_;
	const gchar* _tmp18_;
	Request _tmp20_;
	const gchar* _tmp21_;
	gchar** _tmp22_;
	gchar** _tmp23_ = NULL;
	gchar** _tmp24_;
	gint _tmp24__length1;
	gchar** _tmp31_;
	gint _tmp31__length1;
	gchar** _tmp38_;
	gint _tmp38__length1;
	g_return_if_fail (self != NULL);
	g_return_if_fail (line != NULL);
	memset (&r, 0, sizeof (Request));
	_tmp0_ = line;
	_tmp2_ = _tmp1_ = g_strsplit (_tmp0_, " ", 0);
	parts = _tmp2_;
	parts_length1 = _vala_array_length (_tmp1_);
	_parts_size_ = parts_length1;
	_tmp3_ = parts;
	_tmp3__length1 = parts_length1;
	if (_tmp3__length1 == 1) {
		*result = r;
		parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
		return;
	}
	_tmp4_ = parts;
	_tmp4__length1 = parts_length1;
	_tmp5_ = _tmp4_[1];
	_tmp6_ = g_strdup (_tmp5_);
	_g_free0 (r.full_request);
	r.full_request = _tmp6_;
	_tmp7_ = r;
	_tmp8_ = _tmp7_.full_request;
	_tmp10_ = _tmp9_ = g_strsplit (_tmp8_, "?", 0);
	parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
	parts = _tmp10_;
	parts_length1 = _vala_array_length (_tmp9_);
	_parts_size_ = parts_length1;
	_tmp11_ = parts;
	_tmp11__length1 = parts_length1;
	_tmp12_ = _tmp11_[0];
	_tmp13_ = g_strdup (_tmp12_);
	_g_free0 (r.path);
	r.path = _tmp13_;
	_tmp14_ = parts;
	_tmp14__length1 = parts_length1;
	_tmp15_ = _tmp14_[1];
	_tmp16_ = g_strdup (_tmp15_);
	_g_free0 (r.query);
	r.query = _tmp16_;
	_tmp17_ = r;
	_tmp18_ = _tmp17_.query;
	if (_tmp18_ == NULL) {
		gchar* _tmp19_;
		_tmp19_ = g_strdup ("");
		_g_free0 (r.query);
		r.query = _tmp19_;
	}
	_tmp20_ = r;
	_tmp21_ = _tmp20_.path;
	_tmp23_ = _tmp22_ = g_strsplit (_tmp21_, "/", 0);
	parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
	parts = _tmp23_;
	parts_length1 = _vala_array_length (_tmp22_);
	_parts_size_ = parts_length1;
	_tmp24_ = parts;
	_tmp24__length1 = parts_length1;
	if (_tmp24__length1 > 1) {
		gchar** _tmp25_;
		gint _tmp25__length1;
		const gchar* _tmp26_;
		gchar* _tmp27_;
		Request _tmp28_;
		const gchar* _tmp29_;
		_tmp25_ = parts;
		_tmp25__length1 = parts_length1;
		_tmp26_ = _tmp25_[1];
		_tmp27_ = g_strdup (_tmp26_);
		_g_free0 (r.object);
		r.object = _tmp27_;
		_tmp28_ = r;
		_tmp29_ = _tmp28_.object;
		if (_tmp29_ == NULL) {
			gchar* _tmp30_;
			_tmp30_ = g_strdup ("");
			_g_free0 (r.object);
			r.object = _tmp30_;
		}
	}
	_tmp31_ = parts;
	_tmp31__length1 = parts_length1;
	if (_tmp31__length1 > 2) {
		gchar** _tmp32_;
		gint _tmp32__length1;
		const gchar* _tmp33_;
		gchar* _tmp34_;
		Request _tmp35_;
		const gchar* _tmp36_;
		_tmp32_ = parts;
		_tmp32__length1 = parts_length1;
		_tmp33_ = _tmp32_[2];
		_tmp34_ = g_strdup (_tmp33_);
		_g_free0 (r.action);
		r.action = _tmp34_;
		_tmp35_ = r;
		_tmp36_ = _tmp35_.action;
		if (_tmp36_ == NULL) {
			gchar* _tmp37_;
			_tmp37_ = g_strdup ("");
			_g_free0 (r.action);
			r.action = _tmp37_;
		}
	}
	_tmp38_ = parts;
	_tmp38__length1 = parts_length1;
	if (_tmp38__length1 > 3) {
		gchar** _tmp39_;
		gint _tmp39__length1;
		const gchar* _tmp40_;
		gchar* _tmp41_ = NULL;
		Request _tmp42_;
		const gchar* _tmp43_;
		_tmp39_ = parts;
		_tmp39__length1 = parts_length1;
		_tmp40_ = _tmp39_[3];
		_tmp41_ = g_uri_unescape_string (_tmp40_, NULL);
		_g_free0 (r.val);
		r.val = _tmp41_;
		_tmp42_ = r;
		_tmp43_ = _tmp42_.val;
		if (_tmp43_ == NULL) {
			gchar* _tmp44_;
			_tmp44_ = g_strdup ("");
			_g_free0 (r.val);
			r.val = _tmp44_;
		}
	}
	*result = r;
	parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
	return;
}


/**
 * Start server process
 */
static gboolean _web_server_connection_handler_g_threaded_socket_service_run (GThreadedSocketService* _sender, GSocketConnection* connection, GObject* source_object, gpointer self) {
	gboolean result;
	result = web_server_connection_handler (self, connection);
	return result;
}


void web_server_run (WebServer* self) {
	GThreadedSocketService* _tmp0_;
	GThreadedSocketService* tss;
	GInetAddress* _tmp1_;
	GInetAddress* ia;
	GInetAddress* _tmp2_;
	guint16 _tmp3_;
	GInetSocketAddress* _tmp4_;
	GInetSocketAddress* isaddr;
	GThreadedSocketService* _tmp10_;
	GMainLoop* _tmp11_;
	GMainLoop* ml;
	GThreadedSocketService* _tmp12_;
	FILE* _tmp13_;
	guint16 _tmp14_;
	gchar* _tmp15_ = NULL;
	gchar* _tmp16_;
	gchar* _tmp17_ = NULL;
	gchar* _tmp18_;
	GMainLoop* _tmp19_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = (GThreadedSocketService*) g_threaded_socket_service_new (100);
	tss = _tmp0_;
	_tmp1_ = g_inet_address_new_any (G_SOCKET_FAMILY_IPV4);
	ia = _tmp1_;
	_tmp2_ = ia;
	_tmp3_ = self->priv->_port;
	_tmp4_ = (GInetSocketAddress*) g_inet_socket_address_new (_tmp2_, _tmp3_);
	isaddr = _tmp4_;
	{
		GThreadedSocketService* _tmp5_;
		GInetSocketAddress* _tmp6_;
		_tmp5_ = tss;
		_tmp6_ = isaddr;
		g_socket_listener_add_address ((GSocketListener*) _tmp5_, (GSocketAddress*) _tmp6_, G_SOCKET_TYPE_STREAM, G_SOCKET_PROTOCOL_TCP, NULL, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
		}
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError* e = NULL;
		FILE* _tmp7_;
		GError* _tmp8_;
		const gchar* _tmp9_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp7_ = stderr;
		_tmp8_ = e;
		_tmp9_ = _tmp8_->message;
		fprintf (_tmp7_, "%s\n", _tmp9_);
		_g_error_free0 (e);
		_g_object_unref0 (isaddr);
		_g_object_unref0 (ia);
		_g_object_unref0 (tss);
		return;
	}
	__finally2:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (isaddr);
		_g_object_unref0 (ia);
		_g_object_unref0 (tss);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp10_ = tss;
	g_signal_connect_object (_tmp10_, "run", (GCallback) _web_server_connection_handler_g_threaded_socket_service_run, self, 0);
	_tmp11_ = g_main_loop_new (NULL, FALSE);
	ml = _tmp11_;
	_tmp12_ = tss;
	g_socket_service_start ((GSocketService*) _tmp12_);
	_tmp13_ = stdout;
	_tmp14_ = self->priv->_port;
	_tmp15_ = g_strdup_printf ("%hu", _tmp14_);
	_tmp16_ = _tmp15_;
	_tmp17_ = g_strconcat ("Serving on port ", _tmp16_, "\n", NULL);
	_tmp18_ = _tmp17_;
	fprintf (_tmp13_, "%s", _tmp18_);
	_g_free0 (_tmp18_);
	_g_free0 (_tmp16_);
	_tmp19_ = ml;
	g_main_loop_run (_tmp19_);
	_g_main_loop_unref0 (ml);
	_g_object_unref0 (isaddr);
	_g_object_unref0 (ia);
	_g_object_unref0 (tss);
}


/**
 * Connection handler method.
 */
gboolean web_server_connection_handler (WebServer* self, GSocketConnection* connection) {
	gboolean result = FALSE;
	gchar* first_line = NULL;
	gsize size;
	Request request = {0};
	GSocketConnection* _tmp0_;
	GInputStream* _tmp1_;
	GInputStream* _tmp2_;
	GDataInputStream* _tmp3_;
	GDataInputStream* dis;
	GSocketConnection* _tmp4_;
	GOutputStream* _tmp5_;
	GOutputStream* _tmp6_;
	GDataOutputStream* _tmp7_;
	GDataOutputStream* dos;
	Request _tmp18_;
	RequestHandler* _tmp19_;
	RequestHandler* rh;
	Response _tmp20_ = {0};
	Response _tmp21_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (connection != NULL, FALSE);
	size = (gsize) 0;
	memset (&request, 0, sizeof (Request));
	_tmp0_ = connection;
	_tmp1_ = g_io_stream_get_input_stream ((GIOStream*) _tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_data_input_stream_new (_tmp2_);
	dis = _tmp3_;
	_tmp4_ = connection;
	_tmp5_ = g_io_stream_get_output_stream ((GIOStream*) _tmp4_);
	_tmp6_ = _tmp5_;
	_tmp7_ = g_data_output_stream_new (_tmp6_);
	dos = _tmp7_;
	{
		gsize _tmp8_ = 0UL;
		gchar* _tmp9_ = NULL;
		gchar* _tmp10_;
		const gchar* _tmp11_;
		Request _tmp12_ = {0};
		_tmp9_ = g_data_input_stream_read_line (dis, &_tmp8_, NULL, &_inner_error_);
		size = _tmp8_;
		_tmp10_ = _tmp9_;
		if (_inner_error_ != NULL) {
			goto __catch3_g_error;
		}
		_g_free0 (first_line);
		first_line = _tmp10_;
		_tmp11_ = first_line;
		web_server_get_request (self, _tmp11_, &_tmp12_);
		request_destroy (&request);
		request = _tmp12_;
	}
	goto __finally3;
	__catch3_g_error:
	{
		GError* e = NULL;
		FILE* _tmp13_;
		GError* _tmp14_;
		const gchar* _tmp15_;
		gchar* _tmp16_;
		gchar* _tmp17_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp13_ = stderr;
		_tmp14_ = e;
		_tmp15_ = _tmp14_->message;
		_tmp16_ = g_strconcat (_tmp15_, "\n", NULL);
		_tmp17_ = _tmp16_;
		fprintf (_tmp13_, "%s", _tmp17_);
		_g_free0 (_tmp17_);
		_g_error_free0 (e);
	}
	__finally3:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (dos);
		_g_object_unref0 (dis);
		request_destroy (&request);
		_g_free0 (first_line);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	_tmp18_ = request;
	_tmp19_ = request_handler_new (&_tmp18_);
	rh = _tmp19_;
	request_handler_get_response (rh, &_tmp20_);
	_tmp21_ = _tmp20_;
	web_server_serve_response (self, &_tmp21_, dos);
	response_destroy (&_tmp21_);
	result = FALSE;
	_request_handler_unref0 (rh);
	_g_object_unref0 (dos);
	_g_object_unref0 (dis);
	request_destroy (&request);
	_g_free0 (first_line);
	return result;
}


static const gchar* web_server_get_base_dir (WebServer* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_base_dir;
	result = _tmp0_;
	return result;
}


static void web_server_set_base_dir (WebServer* self, const gchar* value) {
	const gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_base_dir = _tmp0_;
}


static guint16 web_server_get_port (WebServer* self) {
	guint16 result;
	guint16 _tmp0_;
	g_return_val_if_fail (self != NULL, 0U);
	_tmp0_ = self->priv->_port;
	result = _tmp0_;
	return result;
}


static void web_server_set_port (WebServer* self, guint16 value) {
	guint16 _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_port = _tmp0_;
}


static void web_server_class_init (WebServerClass * klass) {
	web_server_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (WebServerPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_web_server_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_web_server_set_property;
	G_OBJECT_CLASS (klass)->finalize = web_server_finalize;
}


static void web_server_instance_init (WebServer * self) {
	self->priv = WEB_SERVER_GET_PRIVATE (self);
}


static void web_server_finalize (GObject* obj) {
	WebServer * self;
	self = WEB_SERVER (obj);
	G_OBJECT_CLASS (web_server_parent_class)->finalize (obj);
}


/**
 * A simple web server implementation
 */
GType web_server_get_type (void) {
	static volatile gsize web_server_type_id__volatile = 0;
	if (g_once_init_enter (&web_server_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (WebServerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) web_server_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (WebServer), 0, (GInstanceInitFunc) web_server_instance_init, NULL };
		GType web_server_type_id;
		web_server_type_id = g_type_register_static (G_TYPE_OBJECT, "WebServer", &g_define_type_info, 0);
		g_once_init_leave (&web_server_type_id__volatile, web_server_type_id);
	}
	return web_server_type_id__volatile;
}


static void _vala_web_server_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	WebServer * self;
	self = WEB_SERVER (object);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_web_server_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	WebServer * self;
	self = WEB_SERVER (object);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



