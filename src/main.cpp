/*BRBergman's formula claculator*/
#include "maths.h" 
#include "ncextra.h"
#include "printnc.h"
#include "maths_typedefs.h"


bool init = false;
void syntheticdiv()
{
	//test one enter 3 for degree and then 6,41,31, and 6 for numbers, and then -6 for zero
	clear();
	printnccenter("What is the degree? ");
	char buffer[25];
	wgetstr(stdscr,buffer);
	int degree = 0; 
	strto(degree,buffer,i);
	clear();
	std::vector<exponantf> g(degree+1);
	for (int i = 0; i < degree+1; i++)
	{
		wprintnccenter(stdscr,-i,0,"x^%i: ",degree-i);
		wgetstr(stdscr,buffer);
		strto(g[i].coefficent,buffer,f);
		g[i].exponant = degree - i;
	}
	clear();
	printnccenter("What is the known zero? ");
	clear();
	wgetstr(stdscr,buffer);
	strto(degree,buffer,i);//reusing and overwriting degree int.
	std::vector<exponantf> f(syntheticdevision(degree,g));
	std::vector<float> guh (quadraticformula(f[0].coefficent,f[1].coefficent,f[2].coefficent));
	printnccenter("%f|%f\n",guh[0],guh[1]);
	return;
}

void quadform()
{
	std::vector<std::string> normal{"Quadratic Formula","Enter A: ","Enter B: ", "Enter C: "};
	std::vector<float> x = getfancyvars(normal);
	std::vector<float> quad = quadraticformula(x[0],x[1],x[2]);
	switch (quad.size())
	{
		casebreak(2,printnccenter("The Points Are: %f, %f",quad[0],quad[1]));
		casebreak(1,printnccenter("The Points Is: %f",quad[0]));
		default: printnccenter("There Are No Real Points"); break;
	}
	return;	
}

void sttover()
{
	std::vector<std::string> normal{"Get The Vertex Point From Standard Form","Enter A: ","Enter B: ", "Enter C: "};
	std::vector<float> x = getfancyvars(normal);
	std::vector<double> ans = standardtovertex(x[0],x[1],x[2]);
	printnccenter("The vertex point is: (%f,%f)",ans[0],ans[1]);
	return;
}

void intercept()
{
	std::vector<std::string> normal{"Find The Y Intercept","Enter M: ","Enter X: ", "Enter B: "};
	std::vector<float> x = getfancyvars(normal);
	printnccenter("Y is: %f",slopeintercept(x[0],x[1],x[2]));
	return;
}

void csar()
{
	std::vector<std::string> normal{"Find Area of A Specific Section of a Cylander","Enter Radius: ","Enter Angle: "};
	std::vector<float> x = getfancyvars(normal);
	printnccenter("The Area is: %f", csaria(x[0],x[1]));
	return;
}  

void mid()
{
	std::vector<std::string> normal{"Find the Midpoint","Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	std::vector<float> x = getfancyvars(normal);
	std::vector<double> y = midpoint({x[0],x[1]},{x[2],x[3]});
	printnccenter("The Midpoint Coordinant is: (%f,%f)",y[0],y[1]);
	return;
}

void circumph()
{
	std::vector<std::string> normal{"FInd The Circumference","Enter the Radius: "};
	std::vector<float> x = getfancyvars(normal);
	printnccenter("The Circumference is: %f",circ(x[0]));
	return;
}

void cylarea()
{
	std::vector<std::string> normal{"Find The Area of a Cylinder","Enter the Radius: "};
	std::vector<float> x = getfancyvars(normal);
	printnccenter("The Area is: %f",carea(x[0]));
	return;
}

void classifytri()
{
	std::string tri[] = {"It's not a triangle",
	"It's a right triangle",
	"It's an obtuse triangle",
	"It's an accute triangle"};
	std::vector<std::string> normal{"Classify a Triangle","Enter A: ","Enter B: ","Enter C: "};
	std::vector<float> x = getfancyvars(normal);
	printnccenter(tri[cheiftr(x[0],x[1],x[2])].c_str());
	return;
}

void dist()
{
	std::vector<std::string> normal{"Distance Formula","Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	std::vector<float> x = getfancyvars(normal);
	printnccenter("The Distance Is: %f",distance(x[0],x[1],x[2],x[3]));
	return;
}

void slop()
{
	std::vector<std::string> normal{"Slope Formula","Enter X1: ","Enter Y1: ","Enter X2: ","Enter Y2: "};
	std::vector<float> x = getfancyvars(normal);
	printnccenter("The Slope Is: %f",slope(x[0],x[1],x[2],x[3]));
	return;
}

void pythag()
{
	std::vector<std::string> normal = {"Pythagorean Theorum, Find the Hypotonuse ","Enter Leg #1: ","Enter Leg #2: "};
	std::vector<float> x = getfancyvars(normal);
	printnccenter("Hypotonuse Value: %f",pythagorean(x[0],x[1]));  
	return;
}

void revpythag()
{
	std::vector<std::string> normal {"Pythagorean Theorum, Find the Leg #2 ","Enter Leg #1: ","Enter Leg Hypotonuse: "};
	std::vector<float> x = getfancyvars(normal);
	printnccenter("Leg Value: %f",reversepythagorean(x[0],x[1]));
	return;
}



int main()
{	
	if (!init)
	{
		initscr();
		init = true;
	}		
	switch (ask())
	{
		casebreak(1,pythag());
		casebreak(2,revpythag());
		casebreak(3,dist());
		casebreak(4,slop());
		casebreak(5,classifytri());
		casebreak(6,circumph());
		casebreak(7,cylarea());
		casebreak(8,mid());
		casebreak(9,csar());
		casebreak(10,intercept());
		casebreak(11,sttover());
		casebreak(12,quadform());
		casebreak(13,syntheticdiv());
		default: endwin(); return 0;
	}
	getch();
	clear();
	main();	
	return 0;
}