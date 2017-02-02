#pragma once
#include "Base.h"
#include "vector"

class PolymorphicMatrix
{
	private:
		int rows;
		int cols;
		/*
		 a vector of vector that has pointers of abstract class Base as its type. It represents a matrix
		*/
		std::vector< std::vector<Base*> > mat;
		/*
			takes user input
		*/
		std::string takeInput(std::string message);
		/*
		returns the central value of the matrix
		*/
		bool hasCentre();
		/*
			figures out the appropriate type of the input value
		*/
		template<typename T>
		bool figureType(std::string input, T type);
	public:
		PolymorphicMatrix();
		~PolymorphicMatrix();
		PolymorphicMatrix(int rows, int cols);
		void setMatValue();
		void setRows(int rows);
		void setCols(int cols);
		int getRows();
		int getCols();
		/*
		prints all the values and the types of the values of the matrix
		*/
		void print();
		/*
		returns the central value of the matrix
		*/
		std::string centreValue();
		/*
		returns the type of the central value of the matrix
		*/
		std::string centreType();
		
	
};

