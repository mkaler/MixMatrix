// MixMatrix.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "sstream"
#include "PolymorphicMatrix.h"
#include "vector"
#include "stdexcept"

/*
displays the message and returns the value entred by the user
*/
int takeInputInt(std::string message)
{

	int in;
	std::string temp;
	std::cout << message;
	while (std::getline(std::cin, temp))
	{
		std::stringstream stringStream(temp);
		if (stringStream >> in)
			if (stringStream.eof() && (in > 1 && in < 100 ))
				break;
		std::cout <<"This value can not be accepted." << std::endl <<"Please retry:" ;
	}
	std::cin.clear();
	return in;
}
//displays a message
void startMes() 
{
	std::cout<< "\t"<<"\t"<< "Matrix of various data types" << std::endl<<std::endl<<std::endl;
}
//displays a message
void sizeMes(const int rows, const int cols) 
{
	std::cout << "\t" << "\t" << "Size of the matrix: " << rows << " rows X "
		<< cols << " coloumns" << std::endl << std::endl;
}
int main()
{

	int rows, cols;
	startMes();//displays a message
	rows = takeInputInt("Write the number of the rows(greater than 1): ");
	cols = takeInputInt("Write the number of the coloumns (greater than 1): ");
	system("cls");
	startMes();
	/*
		an object of class PolymorphicMatrix gets istantiated
	*/
	PolymorphicMatrix *mat = new PolymorphicMatrix(rows, cols);
	sizeMes(rows, cols);
	/*
		setMatValue fills the matrix with the user input
	*/
	mat->setMatValue();
	std::cout << "\t" << "The matrix in format VALUE(TYPE):	" << std::endl;
	/*
		the whole matrix gets printed
	*/
	mat->print();
	/*
		the central value and the data type gets displayed
	*/
	try
	{
		std::cout<<"The value in the centre is "<<mat->centreValue()<<" of type "<<mat->centreType()<<std::endl;
		mat->centreValue();
	}
	catch (std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	delete mat;
    return 0;
	system("pause");
}

