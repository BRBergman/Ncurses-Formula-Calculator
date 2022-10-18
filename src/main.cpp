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
int sciencetonormal()
{
	//std::string normal[] = {"Enter the Number","Enter the Exponant"};
	std::vector<std::string> testtext{"Enter the Number: ","Enter the Exponant: "};
	std::vector<float> test = getvecvars(testtext);
	//float *x = getvars(normal, 2);
	//double y = scitonum(x[0],x[1]);
	double y = scitonum(test[0],test[1]);
	printcenter(combinetext("Your Number is: ",y));
	return 0;
}
int intercept()
{
	std::string normal[] = {"Enter M: ","Enter X: ", "Enter B: "};
	float *x = getvars(normal, 3);
	mvprintw(row/2,((col/3)),"Y is: %f",slopeintercept(x[0],x[1],x[2]));
	return 0;
}

int csar()
{
	std::string normal[] =  {"Enter Radious: ","Enter Angle: "};
	float *x = getvars(normal,2);
	mvprintw(row/2,((col/3)),"The Area is: ", csaria(x[0],x[1]));
	return 0;
}  

int mid()
{
	std::string normal[] =  {"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	float *f = getvars(normal,4);
	double x = midpoint(f[0],f[2]);
	double y = midpoint(f[1],f[3]);
	mvprintw(row/2,((col/3)),"The Midpoint Coordinant is: (%f,%f)",x,y);
	return 0;
}

int circumph(bool area)	//if true does area if false does circumphrince
{
	std::string normal[] =  {"Enter the Radious: ", "The circumference is: ", "The area is: " };
	float *x = getvars(normal,1);
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
	std::string normal[] = {"Enter A: ","Enter B: ","Enter C: "};
	const char *tri[] = {"It's not a triangle",
	"It's a right triangle","It's an obtuse triangle",
	"It's an accute triangle"};
	float *x = getvars(normal,3);
	int cases = cheiftr(x[0],x[1],x[2]);
	std::string y = tri[cases];
	printcenter(y);
	return 0;
}

int slop(bool dist) //true distance formula false slope formula   
{
	clear();
	std::string normal[] = {"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	float *x = getvars(normal,4);
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
	std::string normal[] = {"Enter X: ","Enter Y: "};
	float *x = getvars(normal,2);
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

int main()
{
	clear();
	initscr();	 					/* start the curses mode */
	getmaxyx(stdscr,row,col); 		/* get the number of rows and columns */
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
		case 11:
			sciencetonormal();
			break;
		default:
		clear();
		endwin();
		return 0 ;
	}
	getch();
	clear();
	main();
	endwin();
	return 0;
}