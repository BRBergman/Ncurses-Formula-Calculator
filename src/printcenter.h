#ifndef PRINTCENTER_H
#define PRINTCENTER_H
#include <ncurses.h>
#include <iostream>
#include "ncextra.h"
//print a message to the center of the screen
void printcenter(std::string in);
//print a message to the center of the screen
void printcenter(char in[]);
//print a message to the center of the screen
void printcenter(float in);
//print a message to the center of the screen
void printcenter(double in);
//print a message to the center of the screen
void printcenter(int in);
//print a message to the center of the screen
void printcenter(std::string text, int equasion);
//print a message to the center of the screen
//void printcenter(char text[] , int equasion);
//print a message to the center of the screen
void printcenter(std::string text, float equasion);
//print a message to the center of the screen
//void printcenter(char text[] , float equasion);
//print a message to the center of the screen
void printcenter(std::string text, double equasion);
//print a message to the center of the screen
//void printcenter(char text[] , double equasion);



#endif