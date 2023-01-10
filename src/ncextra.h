#ifndef NCEXTRA_H
#define NCEXTRA_H
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <string>
#include "maths_typedefs.h"
//to be used with ncextra.cpp

extern int row,col;  

int main();

int error();

int ask();

#define strto(out,strin,fletter) try {out=0+std::sto ## fletter(strin);}catch(...){out=0;}

//print strings and return inputs as a float vector
std::vector<float> wgetvecvars(std::vector<std::string> ar);

std::vector<float> wgetfancyvars(WINDOW *scr, std::vector<std::string> strin);

std::vector<float> getfancyvars(std::vector<std::string> strin);

std::vector<float> getvecvars(std::vector<std::string> strin);



#endif