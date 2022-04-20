#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <iostream>
#include "maths.h"



int ask(int row, int col)
{
	
	clear();
	// add new part here to show up 
	const char* askev[] = {"press 0 to quit",
	"press 1 to do the pythagorean theorum ",
	"press 2 to do the inverse pythagorean theorum",
	"press 3 to do the distance formula",
	"press 4 to do the slope formula", 
	"press 5 to classify a triangle",
	
	
	NULL};
	
	for (int i = 0; askev[i] != NULL; i++ )
	{
		mvprintw(row/2-1+i, (col-strlen(askev[i]))/2, "%s",askev[i] );
		mvprintw(row/2+2+i,col/2-1, " ");
	}

	//mvprintw(row-3, (col/2-1) , " ");
	
	
	char numin[10];
	getstr(numin);
	int num = std::stoi(numin);
 	
	
	return num;
}

int askagain(int row, int col)
{
	

}


int classifytri(int row, int col)
{
	clear();
	char mesg[] = "Enter A";
	char mesg2[] = "Enter B";
	char mesg3[] = "Enter C";
	char right[] = "It's a right triangle";
	char obtuse[] = "It's an obtuse triangle";
	char accute[] = "It's an accute triangle";
	char no[] = "It's not a triangle";
	

	char A[80],B[80],C[80];
	
	clear();
	mvprintw(row/2,(col-strlen(mesg))/2,"%s: ",mesg);
	getstr(A);
	clear();
	mvprintw(row/2,(col-strlen(mesg2))/2,"%s: ",mesg2);
	getstr(B);
	clear();
	mvprintw(row/2,(col-strlen(mesg3))/2,"%s: ",mesg3);
	getstr(C);
	clear();
	
	float AI = std::stof(A);
	float BI = std::stof(B);
	float CI = std::stof(C);

	int cases = cheiftr(AI,BI,CI);

	printf("a%f, b%f, c%f, out%i",AI,BI,CI,cases);


	switch (cases)
	{
	case 0:
		mvprintw(row/2,(col-strlen(no))/2,"%s",no);
		break;
	case 1:
		//right
		mvprintw(row/2,(col-strlen(right))/2,"%s",right);
		break;
	case 2:
		//obtuce
		mvprintw(row/2,(col-strlen(obtuse))/2,"%s",obtuse);
		break;
	case 3:
		// acute
		mvprintw(row/2,(col-strlen(accute))/2,"%s",accute);
		break;
	}
	getch();
 	
	return 0;
}


int slop(int row, int col)
{
	clear();
	char mesg[] = "Enter X";
	char mesg2[] = "Enter Y";
	char x1[80],y1[80],x2[80],y2[80];
	
	clear();
	mvprintw(row/2,(col-strlen(mesg))/2,"%s1: ",mesg);
	getstr(x1);
	clear();
	mvprintw(row/2,(col-strlen(mesg))/2,"%s1: ",mesg2);
	getstr(y1);
	clear();
	mvprintw(row/2,(col-strlen(mesg))/2,"%s2: ",mesg);
	getstr(x2);
	clear();
	mvprintw(row/2,(col-strlen(mesg))/2,"%s2: ",mesg2);
	getstr(y2);
	clear();

	float fx1,fy1,fx2,fy2;
	fx1 = std::stof(x1);
	fy1 = std::stof(y1);
	fx2 = std::stof(x2);
	fy2 = std::stof(y2);
	beep();
	mvprintw(row/2,col/2,"%f",slope(fx1,fy1,fx2,fy2) );

	getch();
 	
	return 0;

}

int dist(int row, int col)
{
	clear();
	char mesg[] = "Enter X";
	char mesg2[] = "Enter Y";
	char x1[80],y1[80],x2[80],y2[80];
	
	clear();
	mvprintw(row/2,(col-strlen(mesg))/2,"%s1: ",mesg);
	getstr(x1);
	clear();
	mvprintw(row/2,(col-strlen(mesg))/2,"%s1: ",mesg2);
	getstr(y1);
	clear();
	mvprintw(row/2,(col-strlen(mesg))/2,"%s2: ",mesg);
	getstr(x2);
	clear();
	mvprintw(row/2,(col-strlen(mesg))/2,"%s2: ",mesg2);
	getstr(y2);
	clear();

	float fx1,fy1,fx2,fy2;
	fx1 = std::stof(x1);
	fy1 = std::stof(y1);
	fx2 = std::stof(x2);
	fy2 = std::stof(y2);
	beep();
	mvprintw(row/2,col/2,"%f",distance(fx1,fy1,fx2,fy2) );

	getch();
 	
	return 0;

}
 
int pythag(int row, int col)
{
	clear();
 	char mesg[]="Enter A: ";		/* message to be appeared on the screen */
 	char mesg2[] = "Enter B: ";
 	char str[80];
 	char str2[80];
					
 	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
	getstr(str);
	clear();
 	mvprintw(row/2,(col-strlen(mesg2))/2,"%s",mesg2);	/* print the message at the center of the screen */
	getstr(str2);
	float a = std::stof(str);
	float b = std::stof(str2);
	
	clear();
	beep();
 	mvprintw(row/2, (col-strlen(mesg2))/2, "C: %f",pythagorean(a,b)  );
 	
	
 	mvprintw(LINES - 2, col-12, "A: %f", a);
	mvprintw(LINES - 1, col-12, "B: %f", b);
	
 	getch();
 	

 return 0;
}

int revpythag(int row, int col)
{
	clear();
 	char mesg[]="Enter B: ";		/* message to be appeared on the screen */
 	char mesg2[] = "Enter C: ";
 	char str[80];
 	char str2[80];
					
 	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
	getstr(str);
	clear();
 	mvprintw(row/2,(col-strlen(mesg2))/2,"%s",mesg2);	/* print the message at the center of the screen */
	getstr(str2);
	float b = std::stof(str);
	float c = std::stof(str2);
	
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
	int row, col;  					/* to store the number of rows and the number of colums of the screen */
	
	std::cout << cheiftr(3,4,5);
	initscr();	 					/* start the curses mode */
	getmaxyx(stdscr,row,col); 		/* get the number of rows and columns */
	int num = ask(row,col);

	
	switch (num)
	{
		case 0:
			clear();
			endwin();
			return 0;
		case 1:
			pythag(row,col);
			break;
		case 2:
			revpythag(row,col);
			break;
		case 3:
			dist(row,col);
			break;
		case 4:
			slop(row,col);
			break;
		case 5:
			classifytri(row,col);
			break;
		default:
		return 0 ;
	}
	
	clear();
	
	
	
    
	main();

	
	
	
	
	endwin();
	return 0;
}
