#include "stdafx.h"
#include "iostream"
#include "string"
#include "Char.h"


Char::Char()
{

}


Char::~Char()
{

}

Char::Char(char value)
{
	this->value = value;
}

void Char::setValue(char value)
{
	this->value = value;
}

char Char::getValue()
{
	return this->value;
}

std::string Char::typeValue()
{
	return "char"; //returns "char" as a string because the attribute of this class is a char variable
}

std::string Char::toString()
{
	return std::string(1, value);//returns the value of the char attribute in string format
}
