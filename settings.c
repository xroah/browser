#include "settings.h"

void handle_response(GtkWidget *dialog, int response_id, gpointer uesr_data)
{
    switch(response_id)
    {
    case GTK_RESPONSE_OK:

        break;
    case GTK_RESPONSE_CANCEL:
        break;
    }

    gtk_window_close((GtkWindow *)dialog);
}

GtkDialog* settings_dialog_new(GtkWindow *parent)
{
    GtkBuilder *builder = gtk_builder_new_from_file("./ui/settings.glade");
    GtkWindow *dialog = (GtkWindow *)gtk_builder_get_object(builder, "settings-dialog");
    GtkCssProvider *style = gtk_css_provider_new();

    gtk_css_provider_load_from_path(style, "./css/settings.css", NULL);
    gtk_style_context_add_provider_for_screen(
        gtk_widget_get_screen((GtkWidget *) dialog),
        (GtkStyleProvider *) style,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
    gtk_window_set_transient_for(dialog, parent);
    g_signal_connect(dialog, "response", G_CALLBACK(handle_response), NULL);

    return (GtkDialog *) dialog;
}
