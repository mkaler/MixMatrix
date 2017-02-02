#include "stdafx.h"
#include "iostream"
#include "string"
#include "String.h"



String::String()
{
}

String::String(std::string value)
{
	this->value = value;
}
void String::setValue(std::string value) 
{
	this->value = value;
}
std::string String::getValue() 
{
	return this->value;
}

std::string String::typeValue()
{
	return "String";
}

std::string String::toString()
{
	return value;
}

String::~String()
{
}
