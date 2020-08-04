#include "src/window.h"
#include "src/global.h"

void activate(GtkApplication *, gpointer);

void activate(GtkApplication *app, gpointer user_data)
{
	create_window(app);
}

int main(int argc, char *argv[])
{
	GtkApplication *application;
	int status;

	application = gtk_application_new("x.browser", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(application, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run(G_APPLICATION (application), argc, argv);
	g_object_unref(application);

	return status;
}
