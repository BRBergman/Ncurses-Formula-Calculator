/*BRBergman's formula claculator*/
#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <iostream>
#include "maths.h"
int row, col;



//add trys and catches to all the pages 
int error()
{
	const char mesg[] = "There is an error. One or more of the values you entered is not valid. Press any key to continue.";
	clear();
	mvprintw(row/2,(col-strlen(mesg)-2)/2,"%s",mesg);
	getch();
	return 0;
}
int ask()
{
	
	clear();
	// add new part here to show up 
	char* askev[] = {"press 0 to quit",
	"press 1 to do the pythagorean theorum ",
	"press 2 to do the inverse pythagorean theorum",
	"press 3 to do the distance formula",
	"press 4 to do the slope formula", 
	"press 5 to classify a triangle",
	"press 6 to check the circumference of a circle",
	
	NULL};
	
	for (int i = 0; askev[i] != NULL; i++ )
	{
		mvprintw(row/2-2+i, (col-strlen(askev[i]))/2, "%s",askev[i] );
		mvprintw(row/2+1+i,col/2-1, " ");
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


int circumph()
{
	const char *mesg[] = {"What is the Diamiter? ", "The circumference is: " };
	clear();
	char str[20];
	mvprintw(row/2,(col-strlen(mesg[0]))/2,"%s",mesg[0]);
	getstr(str);
	float diam;
	try
	{
		diam = std::stof(str);
	}
	catch(...)
	{
		error();
	}
	
	double cases = circ(diam);

	beep();
	mvprintw(row/2,(col-strlen(mesg[1]))/2,"%s%f",mesg[1],cases);
	getch();
	return 0;
}

int classifytri()
{
	clear();
	const char *mesg[] = {"Enter A","Enter B","Enter C"};
	const char *tri[] = {"It's not a triangle","It's a right triangle","It's an obtuse triangle","It's an accute triangle"};
	
	
	char Word[4][10] = {};

	
	for (int i = 0; i < 3; i++)
	{
		
		clear();
		mvprintw(row/2,(col-strlen(mesg[i]))/2,"%s: ",mesg[i]);
		//getch(Word[i]);
		getstr(Word[i]);
		
	} 

	float AI;
	float BI;
	float CI;

	try
	{
		AI = std::stof(Word[0]);
		BI = std::stof(Word[1]);
		CI = std::stof(Word[2]);

	}
	catch(...)
	{
		error();
		return 0;
	}

	int cases = cheiftr(AI,BI,CI);

	beep();
	mvprintw(row/2,(col-strlen(tri[cases]))/2,"%s",tri[cases]);


	getch();
	return 0;
}




int slop(bool dist)
{
	//true distance formula false slope formula
	clear();
	const char *mesg[] = {"Enter X1","Enter Y1","Enter X2","Enter Y2"};
	

	char Word[4][10] = {};

	
	for (int i = 0; i < 4; i++)
	{
		
		clear();
		mvprintw(row/2,(col-strlen(mesg[i]))/2,"%s: ",mesg[i]);
		//getch(Word[i]);
		getstr(Word[i]);
		
	} 
	float fx1,fy1,fx2,fy2;
	try
	{
		fx1 = std::stof(Word[0]);
		fy1 = std::stof(Word[1]);
		fx2 = std::stof(Word[2]);
		fy2 = std::stof(Word[3]);
	}//const std::exception& e
	catch(...)
	{
		error();
		return 0;
	}
	clear();
	beep();
	if (dist)
	{
		
		mvprintw(row/2,col/2,"%f",distance(fx1,fy1,fx2,fy2) );
	}
	else
	{
		mvprintw(row/2,col/2,"%f",slope(fx1,fy1,fx2,fy2) );
	}

	getch();
 	
	return 0;
}

int pythag()
{
	clear();
 	const char mesg[]="Enter A: ";		/* message to be appeared on the screen */
 	const char mesg2[] = "Enter B: ";
 	char str[80];
 	char str2[80];
					
 	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
	getstr(str);
	clear();
 	mvprintw(row/2,(col-strlen(mesg2))/2,"%s",mesg2);	/* print the message at the center of the screen */
	getstr(str2);
	float a;
	float b;
	try
	{
		a = std::stof(str);
		b = std::stof(str2);
	}//const std::exception& e
	catch(...)
	{
		error();
		return 0;
	}


	clear();
	beep();
 	mvprintw(row/2, (col-strlen(mesg2))/2, "C: %f",pythagorean(a,b)  );
 	
	
 	mvprintw(LINES - 2, col-12, "A: %f", a);
	mvprintw(LINES - 1, col-12, "B: %f", b);
	
 	getch();
 	

 return 0;
}

int revpythag()
{
	clear();
 	const char mesg[]="Enter B: ";		/* message to be appeared on the screen */
 	const char mesg2[] = "Enter C: ";
 	char str[80];
 	char str2[80];
					
 	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
	getstr(str);
	clear();
 	mvprintw(row/2,(col-strlen(mesg2))/2,"%s",mesg2);	/* print the message at the center of the screen */
	getstr(str2);
	float b;
	float c;
	try
	{
		b = std::stof(str);
		c = std::stof(str2);
	}//const std::exception& e
	catch(...)
	{
		error();
		return 0;
	}
	
	clear();
	beep();
 	mvprintw(row/2, (col-strlen(mesg2))/2, "A: %f",reversepythagorean(b,c)  );
	
	
 	mvprintw(LINES - 2, col-12, "B: %f", b);
	mvprintw(LINES - 1, col-12, "C: %f", c);
	
 	getch();
 	

 return 0;
}


int main()
{
	  					/* to store the number of rows and the number of colums of the screen */

	std::cout << cheiftr(3,4,5);
	initscr();	 					/* start the curses mode */
	getmaxyx(stdscr,row,col); 		/* get the number of rows and columns */
	int num = ask();

	
	switch (num)
	{
		case 0:
			clear();
			endwin();
			return 0;
		case 1:
			pythag();
			break;
		case 2:
			revpythag();
			break;
		case 3:
			slop(true);
			break;
		case 4:
			slop(false);
			break;
		case 5:
			classifytri();
			break;
		case 6:
			circumph();
			break;
		default:
		clear();
		endwin();
		return 0 ;
	}
	
	clear();
	
	main();
	
	endwin();
	return 0;
}