#include "curses.h"
#include "ncextra.h"
#include <string.h>
#include <iostream>

//to be used with ncextra.h
//int row, int col/*


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


float * intartest(std::string *ar, int num)
{
	
	char Word[10][10] = {};
	float x[num];
	for (int i = 0; i< num; i++)
	{
		clear();
		mvprintw(row/2,(col-strlen(ar[i].c_str()))/2,"%s: ",ar[i].c_str());
		//getch(Word[i]);
		getstr(Word[i]);
		clear();
		try
		{
		x[i] = std::stof(Word[i]);
		
		}
		catch(...)
		{
		error();
		return 0;
		}
	}
	
	return x;
}

int add()
{
	std::string questions[] = {"what is x", "what is y"};
	float *z  = intartest(questions, 2);
	float y = z[0]+z[1];
	mvprintw(row/2,(col)/2,"%f",y);
	getch();
	return 0;
}

int mania()
{
	add();
	

	

	return 0;
}
