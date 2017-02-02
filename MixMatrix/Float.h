#pragma once
#include "Base.h"
class Float : public Base
{
	private:
		float value;
	public:
		Float();
		Float(float value);
		~Float();
		float getValue();
		void setValue(float value);
		/*
		inherited member functions
		*/
		std::string typeValue();
		std::string toString();
};

