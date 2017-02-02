#include "stdafx.h"
#include "iostream"
#include "string"
#include "Int.h"


Int::Int()
{

}

Int::~Int()
{
}

Int::Int(int value)
{
	this->value = value;
}

void Int::setValue(int value)
{
	this->value = value;
}
int Int::getValue()
{
	return this->value;
}
std::string Int::typeValue()
{
	/*
		returns, in string format ,the name of the specific type of the attribute of this class
	*/
	if (value > -32768 && value < 32767)
		return "short int";
	if(value < 0)
		return "signed int";
	if(value > 0)
		return "unsigned int";
}

std::string Int::toString()
{
	return std::to_string(value);//returns the value of the attribute in string format
}
