#pragma once

/*
	An interface to be applied on the Abstract Base class, so that all the inherited
	class would have to implement the member functions "typeValue" and "toString"
*/
class InterfaceType
{
	public:
		 ~InterfaceType();
		virtual std::string typeValue() = 0;//returns the name of the type of an attribute
		virtual std::string toString() = 0;//returns the value of an attribute in format string
};

