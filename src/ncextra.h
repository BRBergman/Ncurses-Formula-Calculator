#ifndef NCEXTRA_H
#define NCEXTRA_H
#include <iostream>
//to be used with ncextra.cpp

int main();

extern int row,col;  

int error();

int ask();

float * getvars(std::string *ar, int num);

void printcenter(std::string in);

void printcenter(char in[]);

#endif