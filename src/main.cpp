/*BRBergman's formula claculator*/
#include <ncurses.h>
#include <iostream>
#include "maths.h"
#include <string.h>
#include "ncextra.h"
#include "invert.h"
#include "combinetext.h"
#include "printcenter.h"



int row, col;		/* to store the number of rows and the number of colums of the screen 
(i know its a global variable but like deal with it)*/

int intercept()
{
	std::vector<std::string> normal{"Enter M: ","Enter X: ", "Enter B: "};
	std::vector<float> x = getvecvars(normal);
	printcenter(combinetext("Y is: ",slopeintercept(x[0],x[1],x[2])));
	return 0;
}
int csar()
{
	std::vector<std::string> normal{"Enter Radius: ","Enter Angle: "};
	std::vector<float> x = getvecvars(normal);
	mvprintw(row/2,((col/3)),"The Area is: ", csaria(x[0],x[1]));
	return 0;
}  

int mid()
{
	std::vector<std::string> normal{"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	std::vector<float> f = getvecvars(normal);
	double x = midpoint(f[0],f[2]);
	double y = midpoint(f[1],f[3]);
	mvprintw(row/2,((col/3)),"The Midpoint Coordinant is: (%f,%f)",x,y);
	return 0;
}

int circumph(bool area)	//if true does area if false does circumphrince
{
	std::vector<std::string> normal{"Enter the Radius: ", "The circumference is: ", "The area is: " };
	std::vector<float> x = getvecvars(normal);
	double cases;
	if (area)
	{
		cases = carea(x[0]);
		mvprintw(row/2,(col)/3+4,"%s%f",normal[2].c_str(),cases);
	}
	else
	{
		cases = circ(x[0]);
		mvprintw(row/2,(col)/3+4,"%s%f",normal[1].c_str(),cases);
	}
	return 0;
}

int classifytri()
{
	clear();
	std::string tri[] = {"It's not a triangle",
	"It's a right triangle",
	"It's an obtuse triangle",
	"It's an accute triangle"};
	std::vector<std::string> normal{"Enter A: ","Enter B: ","Enter C: "};
	std::vector<float> x = getvecvars(normal);
	printcenter(tri[cheiftr(x[0],x[1],x[2])]);
	return 0;
}

int slop(bool dist) //true distance formula false slope formula   
{
	clear();
	std::vector<std::string> normal{"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	std::vector<float> x = getvecvars(normal);
	double y = 0;
	if (dist)
	{
		y = distance(x[0],x[1],x[2],x[3]);
		printcenter(combinetext("The Distance Is: ",y));
	}
	else
	{
		y = slope(x[0],x[1],x[2],x[3]);
		printcenter(combinetext("The Slope Is: ",y));
	}
	return 0;
}

int pythag(bool rev) //true for inverse
{
	std::vector<std::string> normal{"Enter Leg: ","Enter Leg: "};
	if (rev)
	{
		normal[1] = "Enter Hypotinuse: ";
	}
	std::vector<float> x = getvecvars(normal);
	double y = 0;
	if (rev)
	{
		y = reversepythagorean(x[0],x[1]);
		printcenter(combinetext("Leg Value: ",y));
	}
	else
	{
		y = pythagorean(x[0],x[1]);
		printcenter(combinetext("Hypotonuse Value: ",y));
	}
	return 0;
}
int answer()
{
	clear();
	int num;
	try
	{
		num = ask();
	}
	catch(...)
	{
		num = 0;
	}
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
		case 10:
			intercept();
			break;
		default:
		clear();
		endwin();
		return 0 ;
	}
	getch();
	clear();
	answer();
	return 0;
}

int main()
{
	initscr();	 					/* start the curses mode */
	getmaxyx(stdscr,row,col); 		/* get the number of rows and columns */
	answer();
	endwin();
	return 0;
}