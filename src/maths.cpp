#include <cmath>
#include <string>
#include "maths.h"
#include <iostream>
//to be used with maths.h




double distance(float x1,float y1,float x2,float y2)
{
	//distance formula
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double slope(float x1,float y1,float x2,float y2)
{
	//slope formula
	return (y2-y1)/(x2-x1);
}


double pythagorean(float a, float b)
{
	//a2+b2=c2
	return std::sqrt(pow(a,2)+pow(b,2));
}

double reversepythagorean(float b, float c)
{	
	//c2-b2=a2
	return std::sqrt(pow(c,2) - pow(b,2));
}

double quadperm(float x1,float y1,float x2,float y2, float x3,float y3,float x4,float y4)
{
	//top and bottom
	double d1 = distance(x1,y1,x2,y2);
	double d2 = distance(x3,y3,x4,y4);
	//sides
	double d3 = distance(x2,y2,x3,y3);
	double d4 = distance(x4,y4,x1,y1);

	return (d1+d2+d3+d4);
}

int cheiftr(float a, float b, float c)
{
	// make a case on output so that is does the good
	if(c >= (a+b))
	{
		return 0;
	}
	double a2 = pow(a,2);
	double b2 = pow(b,2);
	double c2 = pow(c,2);
	if (c2 == a2+b2)
	{
		//right
		return 1;
	}
	if (c2 > a2+b2)
	{
		//obtuse
		return 2;
	}
	if (c2 < a2+b2)
	{
		//accute
		return 3;
	}
	
	return 0;
}
double circ(float rad)
{
	return M_PI*(rad*2);
}

double carea(float rad)
{
	return M_PI*pow(rad, 2);
}

double midpoint(float one, float two)
{
	//do twice to get x and y

	return (one+two)/2;
}
 
double csaria(float radious, float angle)
{
	double top = angle*(M_PI*pow(radious,2));

	return top/360;
}

double slopeintercept(float m, float x, float b)
{
	double calc =(m*x)+b;
	return calc;
}

double scitonum(double num, double ex)
{
	double f = num*pow(10,ex);
	return f;
}