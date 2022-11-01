#ifndef NCEXTRA_H
#define NCEXTRA_H
#include <iostream>
#include <vector>
#include <cstring>
//to be used with ncextra.cpp

int answer();

extern int row,col;  

int error();

int ask();

//print strings and return inputs as a float vector
std::vector<float> getvecvars(std::vector<std::string> ar);

#endif