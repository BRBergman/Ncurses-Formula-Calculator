#include <iostream>
#include <string.h>
#include <vector>
std::vector<std::string> getvechvars(std::vector<std::string> ar)
{
	
	std::cout << ar.size();
	std::cout << ar[0];
	return ar;
}


int sain()
{
	
	std::vector<std::string> i;
	i.push_back("hello");
	i.push_back("bello");
	
	
	getvechvars(i);
	
	return 0;
}