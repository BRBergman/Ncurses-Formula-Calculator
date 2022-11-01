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

int example()
{
	int num1 = 5;
	float num2 = 67.25;
	std::string test = combinetext("hello %d this is a test %f yuh",num1,num2);
	
	std::cout << test;
	return 0;
}
