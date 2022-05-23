/*BRBergman's formula claculator*/
#include <ncurses.h>
#include <iostream>
#include "maths.h"
#include <string.h>
#include "ncextra.h"

int row, col;		/* to store the number of rows and the number of colums of the screen */

int csar()
{
	std::string normal[] =  {"Enter Radious: ","Enter Angle: "};
	
	float *x = getvars(normal,2);
	beep();
	clear();
	mvprintw(row/2,(col)/2,"The Area is: %f", csaria(x[0],x[1]));
	getch();
	return 0;
}  

int mid()
{
	std::string normal[] =  {"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	
	float *x = getvars(normal,4);

	clear();
	beep();
	double first = midpoint(x[0],x[2]);
	double second = midpoint(x[1],x[3]);

	mvprintw(row/2,((col/3)),"the midpoint is: X%f, Y%f",first,second);
	getch();
	return 0;
}

int circumph(bool area)	//if true does area if false does circumphrince
{
	
	std::string normal[] =  {"Enter the Radious: ", "The circumference is: ", "The area is: " };
	float *x = getvars(normal,1);
	clear();
	beep();
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
	getch();
	clear();
	return 0;
}

int classifytri()
{
	clear();
	std::string normal[] = {"Enter A: ","Enter B: ","Enter C: "};
	const char *tri[] = {"It's not a triangle","It's a right triangle","It's an obtuse triangle","It's an accute triangle"};
	
	float *x = getvars(normal,3);

	int cases = cheiftr(x[0],x[1],x[2]);
	beep();
	mvprintw(row/2,(col-strlen(tri[cases]))/2,"%s",tri[cases]);
	getch();
	return 0;
}

int slop(bool dist) //true distance formula false slope formula   
{
	clear();
	std::string normal[] = {"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	float *x = getvars(normal,4);

	clear();
	beep();
	if (dist)
	{
		
		mvprintw(row/2,col/2,"%f",distance(x[0],x[1],x[2],x[3]) );
	}
	else
	{
		mvprintw(row/2,col/2,"%f",slope(x[0],x[1],x[2],x[3]) );
	}

	getch();
	return 0;
}

int pythag(bool rev)
{
	//true for inverse 
	std::string normal[] = {"Enter X: ","Enter Y: "};
	float *x = getvars(normal,2);
	
	clear();
	beep();
	if (rev)
	{
		mvprintw(row/2, (col)/3, "Leg Value: %f",reversepythagorean(x[0],x[1])  );
	}
	else
	{
		mvprintw(row/2, (col)/3, "Hypotonuse Value: %f",pythagorean(x[0],x[1])  );
	}
 	getch();
	return 0;
}

int main()
{
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