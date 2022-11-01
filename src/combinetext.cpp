#include "combinetext.h"
#include <stdarg.h>

std::string combinetext (const char *format, ...)
{
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	vsprintf (buffer,format, args);
  	perror (buffer);
  	va_end (args);
	std::string in = buffer;
	return in;
}
