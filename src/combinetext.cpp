#include <iostream>
#include "combinetext.h"
std::string combinetext(char text[] , float equasion)
{
	std::string combined = text + std::to_string(equasion);
	return combined;
}

std::string combinetext(std::string text , float equasion)
{
	std::string combined = text + std::to_string(equasion);
	return combined;
}

std::string combinetext(char text[] , int equasion)
{
	std::string combined = text + std::to_string(equasion);
	return combined;
}

std::string combinetext(std::string text , int equasion)
{
	std::string combined = text + std::to_string(equasion);
	return combined;
}

std::string combinetext(char text[] , double equasion)
{
	std::string combined = text + std::to_string(equasion);
	return combined;
}
std::string combinetext(std::string text , double equasion)
{
	std::string combined = text + std::to_string(equasion);
	return combined;
}
