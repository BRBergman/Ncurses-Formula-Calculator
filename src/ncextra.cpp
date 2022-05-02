#include <ncurses.h>
#include "ncextra.h"
#include <string.h>
#include <iostream>

//to be used with ncextra.h



int error(int row, int col)
{
	const char mesg[] = "There is an error. One or more of the values you entered is not valid. Press any key to continue.";
	clear();
	mvprintw(row/2,(col-strlen(mesg)-2)/2,"%s",mesg);
	getch();
	return 1;
}

