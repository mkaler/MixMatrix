#pragma once
#include "Base.h"
class Int : public Base
{
	private:
		int value;
	public:
		Int();
		~Int();
		Int(int value);
		void setValue(int val);
		int getValue();
		/*
		inherited member functions
		*/
		std::string typeValue();
		std::string toString();
};

