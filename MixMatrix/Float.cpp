#include "stdafx.h"
#include "iostream"
#include "string"
#include "Float.h"
#include "iomanip"
#include "sstream"



Float::Float()
{

}
Float::~Float()
{
}
Float::Float(float value)
{
	this->value = value;
}

void Float::setValue(float value)
{
	this->value = value;
}

float Float::getValue()
{
	return this->value;
}

std::string Float::typeValue() {
	return "float";//returns "float" as a string because the attribute of this class is a char variable
}

std::string Float::toString()
{
	/*
		specifying a format to represt the float attribute
	*/
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << value; //only 2 digits are allowed after the point
	std::string ret;
	stream >> ret;
	return ret;//returns the value of the float attribute in string format
}
