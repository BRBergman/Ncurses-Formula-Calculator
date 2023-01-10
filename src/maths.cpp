#include <cmath>
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

int cheiftr(float a, float b, float c)
{
	//check if triangle
	if(c >= (a+b))
	{
		//not a triangle
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

std::vector<double> midpoint(float x1,float y1,float x2,float y2)
{
	//returns x and y
	std::vector<double> ans{(x1+x2)/2,(y1+y2)/2};
	return ans;
}

double csaria(float radious, float angle)
{
	//cylander section angle 
	double top = angle*(M_PI*pow(radious,2));
	return top/360;
}

double slopeintercept(float m, float x, float b)
{
	double calc =(m*x)+b;
	return calc;
}

//make standard to vertex and vertex to standard
//y = a(x)^2 + bx + c 	| standard
//y = a (x - h)^2 + k	| vertex
//xv = h = -b/(2*a)
//yv = k = a(h)^2 + bh + c 

std::vector<double> standardtovertex(float a, float b, float c)
{
	float h = (b*-1)/(2*a);
	float k1 =a*(pow(h,2));
	float k2 =(b*h);
	float k = k1+k2+c;
	std::vector<double> hk{h,k};	
	return hk;
}

//quadratic formula
// -b+-sqrt(b^2-4ac)
//			/2a
// make case for if b = 0; might already work, idk

std::vector<float> quadraticformula(float a, float b, float c)
{
	std::vector<float> rerun;		//default no sol
	float discriminant = std::sqrt(pow(b,2)-(4*a*c));
	if (discriminant>0)				//two sol
	{
		rerun.resize(2);
		rerun[0] = ((b*-1)+discriminant)/(a*2);
		rerun[1] = ((b*-1)-discriminant)/(a*2);
	}
	else if (discriminant == 0)		//one sol
	{
		rerun.resize(1);
		rerun[0] = (b*-1)/(2*a);
	}
	return rerun;
}

float findapoly(std::vector<xzero> xintercepts)
{
	float a = 1;
	size_t size=xintercepts.size();
	for (size_t i = 0; i < size; i++)
	{
		if (xintercepts[i].doesbounce == true)
		{
			xintercepts[i].value *= xintercepts[i].value;
		}
		a *= xintercepts[i].value;
	}
	return a;
}