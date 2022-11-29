/*BRBergman's formula claculator*/
#include "maths.h" 
#include "ncextra.h"
#include "printnc.h"

bool init = false;
int row, col;		// to store the number of rows and the number of colums of the screen. 

void quadform()
{
	std::vector<std::string> normal{"Enter A: ","Enter B: ", "Enter C: "};
	std::vector<float> x = getvecvars(normal);
	std::vector<float> quad = quadraticformula(x[0],x[1],x[2]);
	switch (quad.size())
	{
		case 2:
			printnccenter("The Points Are: %f, %f",quad[0],quad[1]);
			break;
		case 1:
			printnccenter("The Points Is: %f",quad[0]);		
			break;
		default:
			printnccenter("There Are No Real Points");
			break;
	}
	return;	
}

void sttover()
{
	std::vector<std::string> normal{"Enter A: ","Enter B: ", "Enter C: "};
	std::vector<float> x = getvecvars(normal);
	std::vector<double> ans = standardtovertex(x[0],x[1],x[2]);
	printnccenter("The vertex point is: (%f,%f)",ans[0],ans[1]);
	return;
}

void intercept()
{
	std::vector<std::string> normal{"Enter M: ","Enter X: ", "Enter B: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("Y is: %f",slopeintercept(x[0],x[1],x[2]));
	return;
}

void csar()
{
	std::vector<std::string> normal{"Enter Radius: ","Enter Angle: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("The Area is: %f", csaria(x[0],x[1]));
	return;
}  

void mid()
{
	std::vector<std::string> normal{"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	std::vector<float> x = getvecvars(normal);
	std::vector<double> y = midpoint(x[0],x[1],x[2],x[3]);
	printnccenter("The Midpoint Coordinant is: (%f,%f)",y[0],y[1]);
	return;
}

void circumph()
{
	std::vector<std::string> normal{"Enter the Radius: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("The circumference is: %f",circ(x[0]));
	return;
}

void cylarea()
{
	std::vector<std::string> normal{"Enter the Radius: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("The area is: %f",carea(x[0]));
	return;
}

void classifytri()
{
	std::string tri[] = {"It's not a triangle",
	"It's a right triangle",
	"It's an obtuse triangle",
	"It's an accute triangle"};
	std::vector<std::string> normal{"Enter A: ","Enter B: ","Enter C: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter(tri[cheiftr(x[0],x[1],x[2])].c_str());
	return;
}

void dist()
{
	std::vector<std::string> normal{"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("The Distance Is: %f",distance(x[0],x[1],x[2],x[3]));
	return;
}

void slop()
{
	std::vector<std::string> normal{"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("The Slope Is: %f",slope(x[0],x[1],x[2],x[3]));
	return;
}

void pythag()
{
	std::vector<std::string> normal{"Enter Leg: ","Enter Leg: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("Hypotonuse Value: %f",pythagorean(x[0],x[1])); //try putting this in getvecvars 
	return;
}

void revpythag()
{
	std::vector<std::string> normal{"Enter Leg: ","Enter Hypotonuse: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("Leg Value: %f",reversepythagorean(x[0],x[1]));
	return;
}



int main()
{
	
	if (!init)
	{
		initscr();
		getmaxyx(stdscr,row,col);
		init = true;
	}		
	int num = ask();
	switch (num)
	{
		case 1:
			pythag();
			break;
		case 2:
			revpythag();
			break;
		case 3:
			dist();
			break;
		case 4:
			slop();
			break;
		case 5:
			classifytri();
			break;
		case 6:
			circumph();
			break;
		case 7:
			cylarea();
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
			sttover();
			break;
		case 12:
			quadform();
			break;
		default:
			endwin();
			return 0 ;
	}
	getch();
	clear();
	main();	
	return 0;
}