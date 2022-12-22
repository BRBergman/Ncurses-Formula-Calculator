#include "printnc.h"
#include <stdarg.h>
int printncrow,printnccol;

int wprintnccenter (WINDOW *win, const char *format, ...)
{
	getmaxyx(win,printncrow,printnccol);
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvwprintw(win,printncrow/2,(printnccol-done)/2,"%s",in.c_str()); //print string to center of screen
	return done;
}
//		mvprintw(row/2-7+i, (col-strlen(askev[i])-11)/2, "Press %i to %s",i,askev[i] );

int wprintnccenter (WINDOW *win, int ver, int hoz, const char *format, ...)
{
	getmaxyx(win,printncrow,printnccol);
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvwprintw(win,printncrow/2-ver,(printnccol-done)/2-hoz,"%s",in.c_str()); //print string to center of screen
	return done;
}

int printnc (WINDOW *win, int ver, int hoz, const char *format, ...)
{
	getmaxyx(win,printncrow,printnccol);
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvwprintw(win,ver,hoz,"%s",in.c_str()); //print string to center of screen
	return done;
}
int printnc (WINDOW *win, int ver, const char *format, ...)
{
	getmaxyx(win,printncrow,printnccol);
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvwprintw(win,ver,0,"%s",in.c_str()); //print string to center of screen
	return done;
}

int printnc (WINDOW *win, const char *format, ...)
{
	getmaxyx(win,printncrow,printnccol);
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvwprintw(win,0,0,"%s",in.c_str()); //print string to center of screen
	return done;
}