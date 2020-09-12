#include<gtk/gtk.h>

#ifndef SETTINGS_H_
#define SETTINGS_H_

GtkWidget* settings_dialog_new(void);
void handle_response(GtkWidget *, int, gpointer);

#endif // SETTINGS_H_
