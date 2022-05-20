/*BRBergman's formula claculator*/
//#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <ncurses.h>
#include <iostream>
#include "maths.h"
#include <string.h>
#include "ncextra.h"

int row, col;		/* to store the number of rows and the number of colums of the screen */

int csar()
{
	const char *mesg[] = {"Enter Radious","Enter Angle"};
	

	char Word[2][10] = {};

	
	for (int i = 0; i < 2; i++)
	{
		
		clear();
		mvprintw(row/2,(col-strlen(mesg[i]))/2,"%s: ",mesg[i]);
		//getch(Word[i]);
		getstr(Word[i]);
		
	} 
	float fx1,fy1;
	try
	{
		fx1 = std::stof(Word[0]);
		fy1 = std::stof(Word[1]);
	}//const std::exception& e
	catch(...)
	{
		error();
		return 0;
	}
	beep();
	clear();
	mvprintw(row/2,(col-strlen(mesg[1]))/2,"The Area is: %f", csaria(fx1,fy1));
	getch();

	return 0;
}



int mid()
{
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
	double first = midpoint(fx1,fx2);
	double second = midpoint(fy1,fy2);

	mvprintw(row/2,((col/3)),"the midpoint is: X%f, Y%f",first,second);
	getch();
	return 0;
}


int circumph(bool area)	//if true does area if false does circumphrince
{
	
	const char *mesg[] = {"Enter the Radious: ", "The circumference is: ", "The area is: " };
	clear();
	char str[20];
	mvprintw(row/2,(col-strlen(mesg[0]))/2,"%s",mesg[0]);
	getstr(str);
	float rade;
	try
	{
		rade = std::stof(str);
	}
	catch(...)
	{
		error();
		return 0;
	}
	clear();
	beep();
	double cases;
	if (area)
	{
		cases = carea(rade);
		mvprintw(row/2,(col-strlen(mesg[2]))/2,"%s%f",mesg[2],cases);
	}
	else
	{
		cases = circ(rade);
		mvprintw(row/2,(col-strlen(mesg[1]))/2,"%s%f",mesg[1],cases);
		
	}
	
	 
	
	
	getch();
	clear();
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

	float AF,BF,CF;

	try
	{
		AF = std::stof(Word[0]);
		BF = std::stof(Word[1]);
		CF = std::stof(Word[2]);

	}
	catch(...)
	{
		error();
		return 0;
	}

	int cases = cheiftr(AF,BF,CF);

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

//char mesg[3][10] = {"Enter A: ","Enter B: ", "Enter C: "}; /* message to be appeared on the screen */

int pythag(bool rev)
{
	//true for inverse 
	std::string normal[] = {"Enter A: ","Enter B: "};
	float *x = getvars(normal,2);
	
	clear();
	beep();
	if (rev)
	{
		mvprintw(row/2, (col)/2, "Value %f",reversepythagorean(x[0],x[1])  );
	}
	else
	{
		mvprintw(row/2, (col)/2, "A: %f",pythagorean(x[0],x[1])  );
	}
 	getch();
	return 0;
}



int main()
{


	

	initscr();	 					/* start the curses mode */
	getmaxyx(stdscr,row,col); 		/* get the number of rows and columns */
	//mania();
	int num = ask();
	
	
	switch (num)
	{
		case 0:
			clear();
			endwin();
			return 0;
		case 1:
			pythag(false);
			break;
		case 2:
			pythag(true);
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
			circumph(false);
			break;
		case 7:
			circumph(true);
			break;
		case 8:
			mid();
			break;
		case 9:
			csar();
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