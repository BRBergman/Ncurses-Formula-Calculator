#ifndef NCEXTRA_H
#define NCEXTRA_H
#include <iostream>
#include <vector>
#include <cstring>
#include <ncurses.h>
#include <string>
//to be used with ncextra.cpp

extern int row,col;  

int answer();

int error();

int ask();

//print strings and return inputs as a float vector
std::vector<float> getvecvars(std::vector<std::string> ar);

#endif