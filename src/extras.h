#include <iostream>



void somespace()
{
	std::cout << "\n \n ----------------------------------\n \n \n";
}

void spacer(int times = 1)
{
    while (times>0)
    {
       times--;
       std::cout << "\n";
    }
}

