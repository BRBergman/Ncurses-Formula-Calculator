#ifndef NCEXTRA_H
#define NCEXTRA_H
#include <iostream>
//to be used with ncextra.cpp

int main();

extern int row,col;  

int error();

int ask();

int mania();

float * getvars(std::string *ar, int num);


#endif