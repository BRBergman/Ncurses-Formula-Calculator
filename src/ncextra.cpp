#include <ncurses.h>
#include "ncextra.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "printcenter.h"


int error()
{
	const char mesg[] = "There is an error. The value you entered is not valid. Press any key to continue.";
	clear();
	printcenter(mesg);
	getch();
	main();
	return 1;
}

int ask()
{
	clear();
	// add new part here to show up 
	const char* askev[] = {"quit",
	"do the pythagorean theorem",
	"do the inverse pythagorean theorem",
	"do the distance formula",
	"do the slope formula", 
	"classify a triangle",
	"check the circumference of a circle",
	"check the area of a circle",
	"preform the midpoint formula",
	"find the area of a certan section of a circle",
	
	
	NULL};
	
	for (int i = 0; askev[i] != NULL; i++ )
	{
		mvprintw(row/2-6+i, (col-strlen(askev[i])-11)/2, "Press %i to %s",i,askev[i] );
		mvprintw(row/2-2+i,col/2-1, " ");
	}
	char numin[10];
	getstr(numin);
	int num;
	 
 	try
	{
		num = std::stoi(numin);
	}
	catch(...)
	{
		num = 0;
	}
	return num;
}


float * getvars(std::string ar[], int length)//get string array and int of length
{
	char Word[10][10]; 	//create string array to assign values to
	float x[length];
	for (int i = 0; i< length; i++)
	{
		clear();
		printcenter(ar[i]); 
		getstr(Word[i]);	//assign value to the variable (think of it as ncurses cin)
		try
		{
			x[i] = std::stof(Word[i]); // turn the string we got into a float 
		}
		catch(...)
		{
			error();
		}
	}
	return x; //return a pointer to the array of floats
}


//ex on how to use getvars()
int add()
{
	std::string questions[] = {"what is x", "what is y"};
	float *z  = getvars(questions, 2);
	float y = z[0]+z[1];
	mvprintw(row/2,(col)/2,"%f",y);
	getch();
	return 0;
}