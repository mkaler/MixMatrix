#include "stdafx.h"
#include "iostream"
#include "string"
#include <vector>
#include "Base.h"
#include "sstream"
#include "PolymorphicMatrix.h"
#include "Int.h"
#include "Float.h"
#include "String.h"
#include "Char.h"
#include "memory"
#include "stdexcept"


/*
	Parameters : a string called input and a generic template called type
	the input string represents the input value entered by the user
	the generic template type represents a primitive type
	returns true if the input entred by the user is compatibile with the data type that the template holds
*/
template<typename T>
bool PolymorphicMatrix::figureType(std::string input, T type)
{
	int i;
	std::stringstream stream(input);
	if (stream >> type)
		if (stream.eof())
			return true;
	return false;
}


PolymorphicMatrix::PolymorphicMatrix()
{

}

PolymorphicMatrix::~PolymorphicMatrix()
{
}

PolymorphicMatrix::PolymorphicMatrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
}

/*
	parameters: a string called message
	the string "message" gets displayed on the screen
	returns the input given by the user in string format
*/
std::string PolymorphicMatrix::takeInput(std::string message) {
	std::string temp;
	std::cout << message <<": ";
	getline(std::cin, temp);
	std::cin.clear();
	return temp;
}
/*
	parameters: none
	this member function takes the user input and assigns it to the compataibile data type variable
	the data type variable then gets added to the metrix sequentially
*/
void PolymorphicMatrix::setMatValue()
{

	int in = 0;
	float fl = 0.0f;
	char ch;
	std::string st;

	int index = 0; //the current number of rows

	std::vector<Base*> tempArr;// to store a single row of the matrix

	while(index < rows){
		
		while(tempArr.size() < (unsigned)cols)//ends when a coloumn has been completed
		{

			std::string input = takeInput("Write a value to put in the matrix");//user input
			std::stringstream streamTemp(input);
			Base *tempSin;// to store a single element
			/*
				during the series of these conditional statements, the user input
				gets assinged to a data type and then according to that data type
				an Object of the approriate derived class gets istantiated and added to the matrix
				of the Base class.
			*/
			if (figureType<int>(input, in)) {
				streamTemp >> in;
				tempSin = new Int(in);
			}
			else if (figureType<float>(input, fl)) {
				streamTemp >> fl;
				tempSin = new Float(fl);
			}
			else
				if (figureType<std::string>(input, st)) {
					streamTemp >> st;
					if (st.size() == 1)
						tempSin = new Char(st.at(0));
					else 
						tempSin = new String(st);
				}

			//the istantiated object gets added to a coloumn of the matrix
			tempArr.push_back(tempSin);
		}
		//tempArr at this point, is a complete coloumn of the matrix, so it gets added to the matrix
		mat.push_back(tempArr);
		//tempArr gets cleared so it can be used again for the next coloumn
		tempArr.clear();
		index++;//the current number of coloumn gets incremented
	}

}

void PolymorphicMatrix::setRows(int rows)
{
	this->rows = rows;
}

void PolymorphicMatrix::setCols(int cols)
{
	this->cols = cols;
}

int PolymorphicMatrix::getRows()
{
	return rows;
}

int PolymorphicMatrix::getCols()
{
	return cols;
}
/*
prints all the values and the types of the values of the matrix
*/
void PolymorphicMatrix::print()
{
	std::cout << "\t";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << mat[i][j]->toString() << "(" << mat[i][j]->typeValue() << ")" <<"\t";
		}
		std::cout << std::endl << std::endl <<"\t";
	}
}
/*
	returns true if the matrix has a centre
*/
bool PolymorphicMatrix::hasCentre()
{
	if ((rows % 2 != 0 && cols % 2 != 0))
		return true;
	return false;
}
/*
	returns the central value of the matrix
*/
std::string PolymorphicMatrix::centreValue()
{
	if (hasCentre())
		return mat[rows / 2][cols / 2]->toString();
	else
		throw  std::runtime_error("The matrix does not have a centre");

}
/*
returns the type of the central value of the matrix
*/
std::string PolymorphicMatrix::centreType()
{
	if (hasCentre())
		return mat[(int)(rows / 2)][(int)(cols / 2)]->typeValue();
	else
		throw std::runtime_error("The matrix does not have a centre");
}
