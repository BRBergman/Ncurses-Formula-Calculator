#ifndef PRINTCENTER_H
#define PRINTCENTER_H
#include <ncurses.h>
#include <iostream>
#include <stdarg.h>
#include "ncextra.h"
//print a message to the center of the screen, returns length 
int printcenter (const char *format, ...);


#endif