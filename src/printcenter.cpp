#include "printcenter.h"
#include "combinetext.h"

void printcenter(std::string in)
{
	mvprintw(row/2,(col-strlen(in.c_str()))/2,"%s",in.c_str()); //print string to center of screen
	return;
}
void printcenter(char in[])
{
	mvprintw(row/2,(col-strlen(in))/2,"%s",in); //print char[] to center of screen
	return;
}
void printcenter(float in)
{
	int conv = std::to_string(in).length();
	mvprintw(row/2,(col-conv)/2,"%d",in); //print float to center of screen
	return;
}
void printcenter(double in)
{
	int conv = std::to_string(in).length();
	mvprintw(row/2,(col-conv)/2,"%d",in); //print double to center of screen
	return;
}
void printcenter(int in)
{
	int conv = std::to_string(in).length();
	mvprintw(row/2,(col-conv)/2,"%i",in); //print int to center of screen
	return;
}

void printcenter(std::string text, int equasion)
{
	std::string in = text + std::to_string(equasion);
	int conv = in.length();
	mvprintw(row/2,(col-conv)/2,"%i",in); //print int to center of screen
	return;
}

void printcenter(char text[] , int equasion)
{
	std::string in = text + std::to_string(equasion);
	int conv = in.length();
	mvprintw(row/2,(col-conv)/2,"%i",in); //print int to center of screen
	return;
}

void printcenter(std::string text, float equasion)
{
	std::string in = text + std::to_string(equasion);
	int conv = in.length();
	mvprintw(row/2,(col-conv)/2,"%i",in); //print int to center of screen
	return;
}

void printcenter(char text[] , float equasion)
{
	std::string in = text + std::to_string(equasion);
	int conv = in.length();
	mvprintw(row/2,(col-conv)/2,"%i",in); //print int to center of screen
	return;
}

void printcenter(std::string text, double equasion)
{
	std::string in = text + std::to_string(equasion);
	int conv = in.length();
	mvprintw(row/2,(col-conv)/2,"%i",in); //print int to center of screen
	return;
}

void printcenter(char text[] , double equasion)
{
	std::string in = text + std::to_string(equasion);
	int conv = in.length();
	mvprintw(row/2,(col-conv)/2,"%i",in); //print int to center of screen
	return;
}
