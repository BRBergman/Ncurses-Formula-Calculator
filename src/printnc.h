#ifndef PRINTNC_H
#define PRINTNC_H
#include <ncurses.h>
#include <iostream>
#include <stdarg.h>
#include "ncextra.h"
//print a message to the center of the screen, returns length 
int printnccenter (const char *format, ...);
//print a message to the center of the screen, add offset from middle, returns length
int printnccenter (int ver, int hoz, const char *format, ...);

int printnc (int ver, int hoz, const char *format, ...);


#endif