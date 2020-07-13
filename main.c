#include "src/window.h"

void activate(GtkApplication *, gpointer);

void activate(GtkApplication *app, gpointer user_data)
{
	create_window(app, NULL);
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
