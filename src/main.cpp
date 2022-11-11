/*BRBergman's formula claculator*/
#include "maths.h" 
#include "ncextra.h"
#include "combinetext.h"
#include "printnc.h"

bool init = false;
int row, col;		// to store the number of rows and the number of colums of the screen. 

int sttover()
{
	std::vector<std::string> normal{"Enter A: ","Enter B: ", "Enter C: "};
	std::vector<float> x = getvecvars(normal);
	std::vector<double> ans = standardtovertex(x[0],x[1],x[2]);
	printnccenter("The vertex point is: (%f,%f)",ans[0],ans[1]);
	return 0;
}

int intercept()
{
	std::vector<std::string> normal{"Enter M: ","Enter X: ", "Enter B: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("Y is: %f",slopeintercept(x[0],x[1],x[2]));
	return 0;
}

int csar()
{
	std::vector<std::string> normal{"Enter Radius: ","Enter Angle: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("The Area is: %f", csaria(x[0],x[1]));
	return 0;
}  

int mid()
{
	std::vector<std::string> normal{"Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	std::vector<float> x = getvecvars(normal);
	std::vector<double> y = midpoint(x[0],x[1],x[2],x[3]);
	printnccenter("The Midpoint Coordinant is: (%f,%f)",y[0],y[1]);
	return 0;
}

int circumph(bool area)	//if true does area if false does circumphrince
{
	std::vector<std::string> normal{"Enter the Radius: "};
	std::vector<float> x = getvecvars(normal);
	double cases;
	if (area)
	{
		cases = carea(x[0]);
		printnccenter("The area is: %f",cases);
	}
	else
	{
		cases = circ(x[0]);
		printnccenter("The circumference is: %f",cases);
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
	printnccenter(tri[cheiftr(x[0],x[1],x[2])].c_str());
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
		printnccenter("The Distance Is: %f",y);
	}
	else
	{
		y = slope(x[0],x[1],x[2],x[3]);
		printnccenter("The Slope Is: %f",y);
	}
	return 0;
}

int pythag()
{
	std::vector<std::string> normal{"Enter Leg: ","Enter Leg: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("Hypotonuse Value: %f",pythagorean(x[0],x[1])); //try putting this in getvecvars 
	return 0;
}

int revpythag()
{
	std::vector<std::string> normal{"Enter Leg: ","Enter Hypotonuse: "};
	std::vector<float> x = getvecvars(normal);
	printnccenter("Leg Value: %f",reversepythagorean(x[0],x[1]));
	return 0;
}



int main()
{
	if (!init)
	{
		initscr();
		init = true;
		getmaxyx(stdscr,row,col);
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
			sttover();
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