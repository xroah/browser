#ifndef WINDOW_H_
#define WINDOW_H_

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include "topbar.h"
#include "headerbar.h"
#include "tab.h"

GtkWindow* create_window(GtkApplication *);
void init_style(GtkWidget *win);

#endif // WINDOW_H_
