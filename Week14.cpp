// Joe Epperson, IV
// jee4cf@umsystem.edu
// 4/26/2021
// Lab 14

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template <typename T>
void Add(T firstInput, T secondInput)
{
	T joinedValue;
	joinedValue = firstInput + secondInput;
	cout << joinedValue << endl;
}

template <typename T>
void Count(vector<T> usrInput)
{
	// Creating a struct so that every value has a counter
	struct Values
	{
		T value;
		int counter;
	};
	vector<Values> countedItems;
	Values tempStruct;

	// Counting through the values in the vector from the input file
	for (int i = 0; i < (usrInput.size()); ++i)
	{
		// Assigning a temporary value for the current value in the vector
		T tempVal;
		tempVal = usrInput.at(i);

		// Checking if the temporary value is already in the vector of countedItems, and if it is adding a counter, if not, creating a new value
		if (countedItems.size() > 0)
		{
			for (int j = 0; j < countedItems.size(); ++j)
			{
				if (tempVal == (countedItems.at(j).value))
				{
					(countedItems.at(j).counter) += 1;
					break;
				}
				else if (j == (countedItems.size() - 1))
				{
					tempStruct.value = tempVal;
					tempStruct.counter = 1;
					countedItems.push_back(tempStruct);
					break;
				}
			}
		}
		else
		{
			tempStruct.value = tempVal;
			tempStruct.counter = 1;
			countedItems.push_back(tempStruct);
		}
	}

	// Going through the counted items vector and outputting the correct value with the correct count
	for (int i = 0; i < (countedItems.size()); ++i)
	{
		cout << (countedItems.at(i).value) << "  =  " << (countedItems.at(i).counter) << endl;
	}
	cout << endl;
}

int main()
{
	int firstInt, secondInt;
	double firstDouble, secondDouble;
	string firstString, secondString;


	// Getting the user input for integer values
	cout << "Part (A)" << endl;
	cout << "Enter first integer number: ";
	cin >> firstInt;
	cout << "Enter second integer number: ";
	cin >> secondInt;
	cout << endl;

	// Getting the user input for double values
	cout << "Enter first double number: ";
	cin >> firstDouble;
	cout << "Enter second double number: ";
	cin >> secondDouble;
	cout << endl;

	// Getting the user input for string values
	cout << "Enter first string: ";
	cin >> firstString;
	cout << "Enter second string: ";
	cin >> secondString;
	cout << endl;

	// Adding the values for integers, doubles, and strings
	cout << "addition of integers = ";
	Add(firstInt, secondInt);

	cout << "addition of doubles = ";
	Add(firstDouble, secondDouble);

	cout << "addition of strings = ";
	Add(firstString, secondString);
	cout << endl;

	cout << "Part (B)" << endl << endl;

	ifstream intFile, doubleFile, stringFile;
	vector<int> intValues;
	vector<double> doubleValues;
	vector<string> stringValues;

	// Opening the integers.txt file and storing all values into the int vector
	intFile.open("integers.txt");
	while (!intFile.eof())
	{
		if (intFile.good())
		{
			int tempVal;
			intFile >> tempVal;
			intValues.push_back(tempVal);
		}
	}
	intFile.close();

	// Opening the doubles.txt file and storing all values into the double vector
	doubleFile.open("doubles.txt");
	while (!doubleFile.eof())
	{
		if (doubleFile.good())
		{
			double tempVal;
			doubleFile >> tempVal;
			doubleValues.push_back(tempVal);
		}
	}
	doubleFile.close();

	// Opening the doubles.txt file and storing all values into the double vector
	stringFile.open("strings.txt");
	while (!stringFile.eof())
	{
		if (stringFile.good())
		{
			string tempVal;
			stringFile >> tempVal;
			stringValues.push_back(tempVal);
		}
	}
	stringFile.close();

	// Using the Count function with the values from the input files to count the occurrences of all values.
	cout << "Integers -- count" << endl;
	Count(intValues);

	cout << "Double -- count" << endl;
	Count(doubleValues);

	cout << "String -- count" << endl;
	Count(stringValues);

	return 0;
}