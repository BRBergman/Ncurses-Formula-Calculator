#ifndef MATHS_H
#define MATHS_H
#include <string>
#include <vector>
//to be used with maths.cpp

double distance(float x1,float y1,float x2,float y2);

double slope(float x1,float y1,float x2,float y2);

double pythagorean(float a, float b);

double reversepythagorean(float b, float c);

double quadperm(float x1,float y1,float x2,float y2, float x3,float y3,float x4,float y4);

int cheiftr(float a, float b, float c);

double circ(float rad);

double carea(float rad);

std::vector<double> midpoint(float x1,float y1,float x2,float y2);

double csaria(float radious, float angle);

double slopeintercept(float m, float x, float b);

std::vector<double> standardtovertex(float a, float b, float c);






#endif