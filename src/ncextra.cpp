#include "ncextra.h"
#include "printcenter.h"

//use if the user messes something up
int error()
{
	std::string mesg = "There is an error. The value you entered is not valid. Press any key to continue.";
	clear();
	printcenter(mesg.c_str());
	getch();
	return 1;
}

int ask()
{
	clear();
	// add new part here to show up 
	std::string askev[] = {"quit",
	"do the pythagorean theorem",
	"do the inverse pythagorean theorem",
	"do the distance formula",
	"do the slope formula", 
	"classify a triangle",
	"check the circumference of a circle",
	"check the area of a circle",
	"preform the midpoint formula",
	"find the area of a certan section of a circle",
	"find the y intercept of a line",
	"get the vertex from a standard form equasion"};

	int size = sizeof(askev)/sizeof(askev[0]);
	for (int i = 0; i < size; i++ )
	{
		printcenter(7-i,0,"Press %i to %s",i,askev[i].c_str());
		printcenter(5-i,-1,"");
	}
	char numin[10];
	getstr(numin);
	int num;
 	try
	{
		num = std::stoi(numin);
	}
	catch(...)
	{
		num = 0;
	}
	return num;
}

std::vector<float> getvecvars(std::vector<std::string> ar) //String vector in float vector out
{
	int length = ar.size(); //get size of input vector
	std::vector<float> x(length);	//the float vector that we return
	char word[20];					//char array to get inputs from
	for (int i = 0; i< length; i++)
	{
		clear();
		printcenter(ar[i].c_str()); //print a message to the center of the screen
		getstr(word);				//assign value to the variable "word" (think of it as ncurses cin)
		try
		{
			x[i] = std::stof(word); // turn the string in "word" into a float 
		}
		catch(...)					//uh oh something went wrong
		{
			error();
			break;
		}
	}
	clear();
	beep();
	return x;
}