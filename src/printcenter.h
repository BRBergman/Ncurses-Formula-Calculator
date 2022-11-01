#ifndef PRINTCENTER_H
#define PRINTCENTER_H
#include <ncurses.h>
#include <iostream>
#include <stdarg.h>
#include "ncextra.h"
//print a message to the center of the screen
//void printcenter(std::string in);
void princenter (const char *format, ...);
//print a message to the center of the screen
void printcenter(char in[]);
//print a message to the center of the screen
void printcenter(float in);
//print a message to the center of the screen
void printcenter(double in);
//print a message to the center of the screen
void printcenter(int in);
//print a message to the center of the screen

void printcenter(char text[] , float equasion);
void printcenter(std::string text , float equasion);

void printcenter(char text[] , int equasion);
void printcenter(std::string text , int equasion);

void printcenter(char text[] , double equasion);
void printcenter(std::string text , double equasion);




#endif