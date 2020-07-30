#include "tab.h"
#include <stdlib.h>

Tab* create_tab()
{
    Tab *tab = malloc(sizeof(Tab));
    tab->header = tab_header_new();
    tab->web_view = webkit_web_view_new();

    return tab;
}
