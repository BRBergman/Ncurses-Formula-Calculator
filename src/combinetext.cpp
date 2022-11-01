#include <iostream>
#include "combinetext.h"

std::string combinetext (const char *format, ...)
{
	int done = 0;
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	done = vsprintf (buffer,format, args);
  	perror (buffer);
  	va_end (args);
	std::string in = buffer;
	return in;
}
