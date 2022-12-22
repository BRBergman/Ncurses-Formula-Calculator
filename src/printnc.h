#ifndef PRINTNC_H
#define PRINTNC_H
#include <ncurses.h>
#include <iostream>
#include <stdarg.h>
#include "ncextra.h"

//THIS IS WHERE THE FUNCTIONS GO

//print a message to the center of the screen, returns length 
int wprintnccenter (WINDOW *win, const char *format, ...);
//print a message to the center of the screen, add offset from middle, returns length
int wprintnccenter (WINDOW *win, int ver, int hoz, const char *format, ...);
//prints message to the left of the screen, ver to go down, hoz to go to the side
int wprintnc (WINDOW *win, int ver, int hoz, const char *format, ...);
//prints message to the left of the screen, ver to go down
int wprintnc (WINDOW *win, int ver, const char *format, ...);
//prints message to top left of the screen
int wprintnc (WINDOW *win, const char *format, ...);
//print a message to the center of stdscr


//THIS IS WHERE THE DEFINES GO


//Formatting: (ver_offset,hoz_ofset,"text %i",8) and ("text %i",8)
#define printnccenter(...) wprintnccenter(stdscr,__VA_ARGS__);

//Formatting: (ver,hoz,"text %i",8) and (ver,"text %i",8) and ("text %i",8)
#define printnc(...) wprintnc(stdscr,__VA_ARGS__);

#endif