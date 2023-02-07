#include <cmath>
#include "maths.h"
#include <iostream>
#include <numeric>
#include <algorithm>

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
	double c2 = pow(c,2);
	double a2b2 = pow(a,2) + pow(b,2);
	if (c2 > a2b2)
	{
		//obtuse
		return 2;
	}
	else if (c2 < a2b2)
	{
		//accute
		return 3;
	}
	else // (c2 == a2+b2) done last because compairing floats can be wonky 
	{
		//right
		return 1;
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
	return (angle*M_PI*pow(radious,2))/360;
}

double slopeintercept(float m, float x, float b)
{
	return (m*x)+b;
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

bool compareByLength(const exponantf a, const exponantf b) //goes large to small 
{return a.exponant > b.exponant;}
//make sorting algorythm then add like terms
//here is something, no idea if it works
std::vector<exponantf> addliketermsf(std::vector<exponantf> in)
{	
	size_t size = in.size();
	std::vector<exponantf> x;
	std::sort(in.begin(),in.end(),compareByLength);
	x.resize(1);
	x[0]= in[0];
	//printf("%d\n",x[0].exponant);
	for (size_t i = 1; i < size; i++)
	{
		if (x[x.size()-1].exponant==in[i].exponant)
		{
			x[x.size()-1].coefficent+= in[i].coefficent;
		}
		else
		{
			x.resize(x.size()+1);
			x[x.size()-1] = in[i];
		}
		
	}
	return x;
}

//multiply value and add exponant
std::vector<exponantf> multiplyquadraticequasions(const std::vector<exponantf> first, const std::vector<exponantf> second)
{
	exponantf temp;
	std::vector<exponantf> x;
	for (size_t i = 0; i < first.size(); i++)
	{
		for (size_t f = 0; f < second.size(); f++)
		{
			temp.coefficent = first[i].coefficent *second[f].coefficent;
			temp.exponant = first[i].exponant +second[f].exponant;
			x.push_back(temp);
		}
	}
	return addliketermsf(x);
}

float xforquadratic(const std::vector<exponantf>in, float x)
{
	float rerun = 0;
	for (size_t i = 0; i < in.size(); i++)
	{
		if (in[i].exponant == 0)
		{
			rerun+= in[i].coefficent;
		}
		else
		{
			rerun += in[i].coefficent * pow(x,in[i].exponant);
		}
	}
	return rerun;
}

std::vector<exponantf> syntheticdevision(int zero, std::vector<exponantf> exin)
{
	std::sort(exin.begin(),exin.end(),compareByLength);
	size_t size = exin.size();
	std::vector<exponantf> numbers(size);
	numbers[0].coefficent = exin[0].coefficent;
	for (size_t i = 1; i < size; i++)
	{
		numbers[i].coefficent = exin[i].coefficent+(numbers[i-1].coefficent*zero);
	}
	for (size_t i = 0; i < size; i++)
	{
		numbers[i].exponant = exin[i].exponant -1;
	}
	return numbers; //put the answer into the quadratic formula
}