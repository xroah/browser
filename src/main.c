#include <ncurses.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    initscr();
    printw("Hello world! \n");
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    int c;

    while(c = getch()) {
        if (c == 'q') {
            break;
        }

        clear();

        switch(c) {
            case KEY_UP:
                printw("\nArrow up\n");
                break;
            case KEY_DOWN:
                printw("\nArrow down\n");
                break;
            case KEY_LEFT:
                printw("\nArrow left\n");
                break;
            case KEY_RIGHT:
                printw("\nArrow right\n");
                break;
            default:
                printw("\nOther keys\n");
        }
    }

    endwin();

    return 0;
}
