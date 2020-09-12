#include "settings.h"

void handle_response(GtkWidget *dialog, int response_id, gpointer uesr_data)
{
    switch(response_id) {
        case GTK_RESPONSE_OK:

            break;
        case GTK_RESPONSE_CANCEL:
            break;
    }

    gtk_widget_destroy(dialog);
}

GtkWidget* settings_dialog_new()
{
    GtkBuilder *builder = gtk_builder_new_from_file("./ui/settings.glade");
    GtkWidget *dialog = (GtkWidget *)gtk_builder_get_object(builder, "settings-dialog");
    GtkCssProvider *style = gtk_css_provider_new();

    gtk_css_provider_load_from_path(style, "./css/settings.css", NULL);
    gtk_style_context_add_provider_for_screen(
        gtk_widget_get_screen(dialog),
        (GtkStyleProvider *) style,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
    g_signal_connect(dialog, "response", G_CALLBACK(handle_response), NULL);

    return dialog;
}
