#include "src/window.h"

void activate(GtkApplication *, gpointer);

void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window = create_window(app);
	load_page(window, NULL, webkit_uri_request_new("https://bing.com"));
}

int main(int argc, char *argv[])
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("x.browser", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run(G_APPLICATION (app), argc, argv);
	g_object_unref(app);

	return status;
}
