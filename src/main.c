#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>

int main (int argc, char *argv[])
{
    setlocale(LC_ALL, "zh_CN.UTF-8");

    initscr();

    printw("嘿嘿! \n");

    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int c;

    while((c = getch())) {
        if (c == 'q') {
            break;
        }

        clear();

        switch(c) {
            case KEY_UP:
                printw("Arrow up\n");
                break;
            case KEY_DOWN:
                printw("Arrow down\n");
                break;
            case KEY_LEFT:
                printw("Arrow left\n");
                break;
            case KEY_RIGHT:
                printw("Arrow right\n");
                break;
            default:
                printw("Other keys\n");
        }
    }

    endwin();

    return 0;
}
