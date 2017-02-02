#pragma once
#include "Base.h"
class String : public Base
{
	private:
		std::string value;
	public:
		String();
		String(std::string value);
		~String();
		void setValue(std::string value);
		std::string getValue();
		/*
		inherited member functions
		*/
		std::string typeValue();
		std::string toString();
};

