/**
Test the construction of instructionType objects, using Course pointers to 
extract information.

@Author: Duc Le
@Date: 5/15/2015
@Version One

***/

#include "instructionType.h"
#include "Course.h"
#include <vector>
#include <sstream>
using namespace std;

class Course;
class instructionType;

int main()
{
	Course check = Course();
	check.setCourseCode("PHYS201");

	check.addInstrType("Lecture");
	check.addInstrType("Lab");
	check.addInstrType("Recitation");

	for (int i = 0; i < 50; i = i + 10)
	{
		stringstream convert;
		convert << (100 * i);
		string s = convert.str();
		convert.str("");
		check.addTime("Lecture", i, i + 4, s);
	}

	 for (int i = 60; i < 110; i = i + 10)
	 {
		 stringstream convert;
		 convert << (100 * i);
		 string s = convert.str();
		 convert.str("");
		 check.addTime("Lab", i, i + 4, s);
	 }

	  for (int i = 100; i < 150; i = i + 10)
	  {
		  stringstream convert;
		  convert << (100 * i);
		  string s = convert.str();
		  convert.str("");
		  check.addTime("Recitation", i, i + 4, s);
	  }

	instructionType testing = instructionType(0, &check);
	//now, we test the inspector
	cout << "The size of the time vectors: " << testing.getSize() << endl;
	cout << "The name: " << testing.getName() << endl;
	cout << "The starting time vector: ";
	for (int i = 0; i < testing.getSize(); i++)
	{
		cout << testing.getStart(i) << " ";
	}
	cout << endl;
	cout << "The ending time vector: ";
	for (int i = 0; i < testing.getSize(); i++)
	{
		cout << testing.getEnd(i) << " ";
	}
	cout << endl;
	cout << "The CRN List: " << endl;
	for (int i = 0; i < testing.getSize(); i++)
	{
		cout << testing.getCRN(i) << endl;
	}
	cout << endl;
}
