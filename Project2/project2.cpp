//Author:		Yao Yao, yjy5094, 16.09 Oct. 13
//Class:		CMPSC 121
//Project:		02

/*******************************************************************\
*Academic Integrity Affidavit:                                      *
*                                                                   *
*I certify that, this program code is my work. Others may have      *
*assisted me with planning and concepts, but the code was written,  *
*solely, by me.                                                     *
*                                                                   *
*I understand that submitting code which is totally or partially    *
*the product of other individuals is a violation of the Academic    *
*Integrity Policy and accepted ethical precepts. Falsified          *
*execution results are also results of improper activities. Such    *
*violations may result in ero credit for the assignment, reduced    *
*credit for the assignment, or course failure.                      *
\*******************************************************************/
//Sources of logic assistance:121 Study Group: Yao Yao

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void printHeader(string);
void printItem(string, int, double, double);
void printTotal(double);
double calValue(int, double);
double calTotal(double, double);					//define subjects.

ofstream fout;										//create stream output to the file.

void printHeader(string pdate)						//output the headers.
{
	fout << "Invoice date: " << pdate << endl
		<< endl
		<< "Item\tQuantity Unit\tPrice\tTotal Price" << endl
		<< endl;
}

void printItem(string pitem, int punit, double pprice, double pvalue)		//output the item details.
{
	fout << pitem << "\t\t" << punit
		<< "\t" << pprice << "\t" << pvalue << endl;
}

void printTotal(double ptotal)												//output the total values.
{
	fout << "Total ------------------------- " << ptotal << endl
		<< endl;
}

double calValue(int cunit, double cprice)									//calculate the values of items and return the values.
{
	double cvalue;
	cvalue = cunit * cprice;
	return cvalue;
}

double calTotal(double ctotal, double cvalue)								//calculate the total values of items and return the values.
{
	ctotal += cvalue;
	return ctotal;
}

int main()
{
	ifstream fin;
	string date, item, name;
	int unit, count;
	double price, value, total;				//define variables.

	fout.open("output.txt");
	fin.open("input.txt");					//open the input file and output file.

	cout << fixed << setprecision(2);		//set precision.

	while (fin >> count >> date)			//input the data.
	{
		total = 0;
		printHeader(date);

		for (int i = 0; i < count; i++)
		{
			fin >> item >> name >> unit >> price;		//input the data.

			value = calValue(unit, price);
			total = calTotal(total, value);				//calculate the data.

			printItem(item, unit, price, value);		//output the data.
		}
		printTotal(total);								//output the total values of items.
	}

	fin.close();
	fout.close();										//close the input and output files.

	return 0;
}