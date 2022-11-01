#include "printcenter.h"
#include "combinetext.h"
#include <stdarg.h>


void printcenter(std::string in)
{
	mvprintw(row/2,(col-strlen(in.c_str()))/2,"%s",in.c_str()); //print string to center of screen
	return;
}
void printcenter(char in[])
{
	mvprintw(row/2,(col-strlen(in))/2,"%s",in); //print char[] to center of screen
	return;
}
void printcenter(float in)
{
	int conv = std::to_string(in).length();
	mvprintw(row/2,(col-conv)/2,"%d",in); //print float to center of screen
	return;
}
void printcenter(double in)
{
	int conv = std::to_string(in).length();
	mvprintw(row/2,(col-conv)/2,"%d",in); //print double to center of screen
	return;
}
void printcenter(int in)
{
	int conv = std::to_string(in).length();
	mvprintw(row/2,(col-conv)/2,"%i",in); //print int to center of screen
	return;
}
void printcenter(char text[] , float equasion)
{
	printcenter(combinetext(text,equasion));
	return;
}
void printcenter(std::string text , float equasion)
{
	printcenter(combinetext(text,equasion));
	return;
}
void printcenter(char text[] , int equasion)
{
	printcenter(combinetext(text,equasion));
	return;
}
void printcenter(std::string text , int equasion)
{
	printcenter(combinetext(text,equasion));
	return;
}
void printcenter(char text[] , double equasion)
{
	printcenter(combinetext(text,equasion));
	return;
}
void printcenter(std::string text , double equasion)
{
	printcenter(combinetext(text,equasion));
	return;
}

void princenter (const char *format, ...)
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
	return;
}
