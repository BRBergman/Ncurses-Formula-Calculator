#ifndef NCEXTRA_H
#define NCEXTRA_H
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <string>
#include "maths_typedefs.h"
//to be used with ncextra.cpp

 

//functions

int main();
int error();
int ask();
//print strings and return inputs as a float vector
std::vector<float> wgetvecvars(WINDOW *scr, std::vector<std::string> ar);
//print strings and return inputs as a float vector
std::vector<float> wgetfancyvars(WINDOW *scr, std::vector<std::string> strin); 

//defines

#define strto(out,strin,fletter) try {out=0+std::sto ## fletter(strin);}catch(...){out=0;}

#define getfancyvars(strin) wgetfancyvars(stdscr,strin)

#define getvecvars(strin) wgetvecvars(stdscr,strin)

#define casebreak(num,func) case num: func; break

#define arrsize(arr) sizeof(arr)/sizeof(arr[0])

#endif