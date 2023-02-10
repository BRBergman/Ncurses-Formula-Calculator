#ifndef MATHS_H
#define MATHS_H
#include <string>
#include <vector>
#include "maths_typedefs.h" 
//to be used with maths.cpp

double distance(point one, point two);

double slope(point one, point two);

double pythagorean(float a, float b);

double reversepythagorean(float b, float c);

int cheiftr(float a, float b, float c);

double circ(float rad);

double carea(float rad);

std::vector<double> midpoint(point one,point two);

double csaria(float radious, float angle);

double slopeintercept(float m, float x, float b);

std::vector<double> standardtovertex(float a, float b, float c);

std::vector<float> quadraticformula(float a, float b, float c);

bool compareByLength(const exponantf a, const exponantf b); //goes large to small 

std::vector<exponantf> addliketermsf(std::vector<exponantf> in);

std::vector<exponantf> multiplyquadraticequasions(const std::vector<exponantf> first, const std::vector<exponantf> second);

std::vector<exponantf> syntheticdevision(int zero, std::vector<exponantf> exin);

#endif