/***
  Unit test for instructionType class
	@Author: Duc Le
	@Date: 5/15/2015
	@Version One;
***/
#include <sstream>
#include <iostream>
#include "instructionType.h"
#include "Course.h"
using namespace std;

class instructionType;
class Course;

int main()
{
	Course* dummy = NULL;
	vector<int> start = vector<int>();
	for (int i = 0; i < 51; i = i + 10)
		start.push_back(i);

	vector<int> end = vector<int>();
	for (int i = 4; i < 55; i = i + 10)
		end.push_back(i);

	vector<string> CRN = vector<string>();
	for (int i = 1000; i < 6500; i = i + 1000)
	{
		stringstream convert;
		convert << i;
		string s = convert.str();
		CRN.push_back(s);
		convert.str("");
	}
	instructionType testing = instructionType("CS265Lab", start, end, CRN,
			dummy);

	 for (int i = 100; i < 200; i = i + 10)
	 {
		 testing.addStartTime(i);
		 testing.addEndTime(i + 4);
	 }


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
