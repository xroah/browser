#include<gtk/gtk.h>

#ifndef TITLE_BAR_H_
#define TITLE_BAR_H_

typedef struct
{
    GtkWidget *search_input;
    GtkWidget *bar;
} TitleBar;

void window_destroy(GtkWidget *, gpointer);
TitleBar* title_bar_new(GtkWidget *);

#endif // TITLE_BAR_H_
