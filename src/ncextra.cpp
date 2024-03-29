#include "ncextra.h"
#include "printnc.h"
#include "combinetext.h"

//use if the user messes something up
int error()
{
	clear();
	wprintnccenter(stdscr,2,0,"There is an error. The value you entered is not valid.");
	wprintnccenter(stdscr,1,0,"It has been replaced with a zero.");
	wprintnccenter(stdscr,-1,0,"Press any key to continue.");
	getch();
	return 1;
}
int asks(std::vector<std::string> askev)
{
	clear();

	size_t size = askev.size();
	for (size_t i = 0; i < size; i++ )
	{
		wprintnccenter(stdscr,7-i,0,"Press %i to %s",i,askev[i].c_str());
		wprintnccenter(stdscr,5-i,-1,"");
	}
	char numin[10];
	getstr(numin);
	int num;
	strto(num,numin,i);
	return num;
}

std::vector<float> wgetvecvars(WINDOW * scr,std::vector<std::string> ar) //String vector in float vector out
{
	size_t length = ar.size(); 			//get size of input vector
	std::vector<float> x(length);		//the float vector that we return
	char word[20];						//char array to get inputs from
	for (size_t i = 0; i< length; i++)
	{
		clear();
		wprintnccenter(scr,ar[i].c_str()); 	//print a message to the center of the screen
		wgetstr(scr,word);					//assign value to the variable "word" (think of it as ncurses cin)
		strto(x[i],word,f);
	}
	clear();
	return x;
}


//todo: make function that will go from one spot to enter text to another by pressing enter(9) or tab(10)

//take vector for the elements we want to change the formant from elements[2] to element1,element1, etc

std::vector<float> wgetfancyvars(WINDOW *scr, std::vector<std::string> strin)
{
	clear();
	size_t length = strin.size();
	char in[10];
	wprintnccenter(scr,1,0,strin[0].c_str());
	std::vector<float> x;
	x.resize(length-1);
	for (size_t i = 1; i < length; i++)
	{
		wprintnccenter(scr,-i,0,strin[i].c_str());
		wgetstr(scr,in);
		strto(x[i-1],in,f);
	}
	return x;
}



