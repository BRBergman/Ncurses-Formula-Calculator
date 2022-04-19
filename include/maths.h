#include <cmath>
#include <iostream>
#include <string>

//defines


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

	 
int quadrilateral (	float x1,float y1,float x2,float y2, float x3,float y3,float x4,float y4)
{
	//checks if a four sided shape is a parallelogram
	//top and bottom 
	double d1 = distance(x1,y1,x2,y2);
	double d2 = distance(x3,y3,x4,y4);
	
	
	

	//top and bottom
	double s1 = slope(x1,y1,x2,y2);
	double s2 = slope(x3,y3,x4,y4);
	
	
	
	

	if (d1 == d2 && s1 == s2)
	{
		//parallelogram
		return 1;
	}

	
	return 0;
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

double midseg(float s1,float s2)
{
	return (s1+s2)/2;
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
int angles(int sides)
{
	return (sides-2) * 180;

}

int cheiftr(float a, float b, float c)
{
	// make a case on output so that is does the good
	if(a+b <= c);
	{
		return 0;
	}
	double a2 = pow(a,2);
	double b2 = pow(b,2);
	double c2 = pow(c,2);
	if (c2 = a2+b2)
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
	
	
	

}