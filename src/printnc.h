#ifndef PRINTNC_H
#define PRINTNC_H
#include <ncurses.h>
#include <iostream>
#include <stdarg.h>
#include "ncextra.h"
//print a message to the center of the screen, returns length 
int wprintnccenter (WINDOW *win, const char *format, ...);
//print a message to the center of the screen, add offset from middle, returns length
int wprintnccenter (WINDOW *win, int ver, int hoz, const char *format, ...);
//prints message to the left of the screen, ver to go down, hoz to go to the side
int printnc (WINDOW *win, int ver, int hoz, const char *format, ...);
//prints message to the left of the screen, ver to go down
int printnc (WINDOW *win, int ver, const char *format, ...);
//prints message to top left of the screen
int printnc (WINDOW *win, const char *format, ...);
//print a message to the center of stdscr
#define printnccenter(...) wprintnccenter(stdscr,__VA_ARGS__);


#endif