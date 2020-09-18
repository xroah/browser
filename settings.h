#include<gtk/gtk.h>

#ifndef SETTINGS_H_
#define SETTINGS_H_

GtkDialog* settings_dialog_new(GtkWindow *);
void handle_response(GtkWidget *, int, gpointer);

#endif // SETTINGS_H_
