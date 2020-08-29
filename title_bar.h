#include<gtk/gtk.h>

#ifndef TITLE_BAR_H_
#define TITLE_BAR_H_

typedef struct
{
    GtkWidget *search_input;
    GtkWidget *bar;
    GtkWidget *search_btn;
    GtkWidget *settings_btn;
} TitleBar;

void window_destroy(GtkWidget *, gpointer);
TitleBar* title_bar_new(GtkWidget *);
gboolean handle_search(GtkWidget *, gpointer);
gboolean handle_settings(GtkWidget *, gpointer);

#endif // TITLE_BAR_H_
