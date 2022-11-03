#include "printcenter.h"
#include <stdarg.h>


int printcenter (const char *format, ...)
{
	int done = 0;
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	done = vsprintf (buffer,format, args);
  	perror (buffer);
  	va_end (args);
	std::string in = buffer;
	mvprintw(row/2,(col-done)/2,"%s",in.c_str()); //print string to center of screen
	return done;
}
//		mvprintw(row/2-7+i, (col-strlen(askev[i])-11)/2, "Press %i to %s",i,askev[i] );

int printcenter (int ver, int hoz, const char *format, ...)
{
	int done = 0;
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	done = vsprintf (buffer,format, args);
  	perror (buffer);
  	va_end (args);
	std::string in = buffer;
	mvprintw(row/2-ver,(col-done)/2-hoz,"%s",in.c_str()); //print string to center of screen
	return done;
}
