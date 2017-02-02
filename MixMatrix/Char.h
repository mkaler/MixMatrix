#pragma once
#include "Base.h"
class Char : public Base //inherits base
{
	private:
		char value;
	public:
		Char();
		~Char();
		Char(char value);
		void setValue(char value);
		char getValue();
		/*
			inherited member functions
		*/
		std::string typeValue();
		std::string toString();
};

