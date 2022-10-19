#ifndef NCEXTRA_H
#define NCEXTRA_H
#include <iostream>
#include <vector>
//to be used with ncextra.cpp

int main();

extern int row,col;  

int error();

int ask();

std::vector<float> getvecvars(std::vector<std::string> ar);

void printcenter(std::string in);

void printcenter(char in[]);

void printcenter(float in);

void printcenter(double in);

void printcenter(int in);



#endif