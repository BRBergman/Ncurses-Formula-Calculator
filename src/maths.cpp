#include <cmath>
#include "maths.h"
#include <iostream>
#include "combinetext.h"
#include <numeric>
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

std::vector<double> midpoint(float x1,float y1,float x2,float y2)
{
	//do twice to get x and y
	std::vector<double> ans{(x1+x2)/2,(y1+y2)/2};
	return ans;
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





std::string factor(int a, int b, int c)
{
	//enter in standard form
	int mul =a*c;
	int num[2];
	int dis;
	//step 1 get factored values |ex: 16 1,16;2,8;3, (done for positives,idk about negatives)
	//see if factors of mul added together are = to b
	for(int i = 1; i <= abs(mul); ++i) 
	{
		if (mul % i == 0)
		{
			dis = mul/i;
			if (i+dis == abs(b))
			{
				num[0] = i;
				if (b<0)
				{
					num[1] = dis*-1;
				}
				else
				{
					num[1] = dis;
				}
			}
		}
	}


	/*
	int ab = std::gcd(abs(a),abs(num[0]));
	int bc = std::gcd(abs(c),abs(num[1]));
	if(num[0] <0 && a <0)
	{
		ab*=-1;
	}
	if(num[1] <0 && c <0)
	{
		bc*=-1;
	}
	
	int faca = num[0]/ab;
	int facb = num[1]/bc;
	*/
	//printf("%d,%d,%d\n%d|%d\n(%dx+%d)(%dx+%d)\n",a,b,c,num[0],num[1],ab,bc,facb,faca);
	printf("%d,%d\n",num[0],num[1]);
	//				18,		-2
	int gcfa;
	int gcfc;
	int ax;
	int bx;
	if (b>0)
	{
		gcfa = num[0]/std::gcd(a,num[0]);
		gcfc = c/std::gcd(c,num[1]);
		ax = abs(a/std::gcd(a,num[0]));
		bx = abs(num[1]/std::gcd(c,num[1]));
		if(num[0] <0 && a <0)
		{
			gcfa*=-1;
		}
		if(num[1] <0 && c <0)
		{
			gcfc*=-1;
		}
		if (gcfa != gcfc)
		{
			//error
		}
	}
	else
	{


	}
	


	std::cout << gcfa <<gcfc << ax << bx<< std::endl;
    return "rerun" ;
}