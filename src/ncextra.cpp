#include <ncurses.h>
#include "ncextra.h"
#include <string.h>
#include <iostream>

//to be used with ncextra.h
//int row, int col


int error()
{
	const char mesg[] = "There is an error. One or more of the values you entered is not valid. Press any key to continue.";
	clear();
	mvprintw(row/2,(col-strlen(mesg)-2)/2,"%s",mesg);
	getch();
	return 1;
}

int ask()
{
	
	clear();
	// add new part here to show up 
	const char* askev[] = {"press 0 to quit",
	"press 1 to do the pythagorean theorem ",
	"press 2 to do the inverse pythagorean theorem",
	"press 3 to do the distance formula",
	"press 4 to do the slope formula", 
	"press 5 to classify a triangle",
	"press 6 to check the circumference of a circle",
	"press 7 to check the area of a circle",
	"press 8 to preform the midpoint formula",
	"press 9 to find the area of a certan section of a circle",
	
	NULL};
	
	for (int i = 0; askev[i] != NULL; i++ )
	{
		mvprintw(row/2-6+i, (col-strlen(askev[i]))/2, "%s",askev[i] );
		mvprintw(row/2-2+i,col/2-1, " ");
	}
	char numin[10];
	getstr(numin);
	int num;
	 
 	try
	{
		num = std::stoi(numin);
	}//const std::exception& e
	catch(...)
	{
		num = 0;
	}
	return num;
}




