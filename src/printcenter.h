#ifndef PRINTCENTER_H
#define PRINTCENTER_H
#include <ncurses.h>
#include <iostream>
#include <stdarg.h>
#include "ncextra.h"
//print a message to the center of the screen, returns length 
int printcenter (const char *format, ...);
//print a message to the center of the screen, add offset from middle, returns length
int printcenter (int ver, int hoz, const char *format, ...);


#endif