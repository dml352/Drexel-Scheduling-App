#include <sstream>
#include <vector>
#include <iostream>
#include "Course.h"
#include "instructionType.h"
#include "sched.h"
using namespace std;

bool schedule(vector<string> &finalSched, vector<instructionType> &courseList, int tracker)
{
	if (tracker >= courseList.size())		//successfully scheduling all course
		return true;
	instructionType *current = &courseList[tracker];
	for (int i = 0; i < current -> getSize(); i++)			//iterate through the available time slots.
	{
		int start = current -> getStart(i);
		int end = current -> getEnd(i);
		if (schedable(finalSched, start, end))
		{
			putInSched(finalSched, start, end, current -> getName());
			bool check = schedule(finalSched, courseList, tracker + 1);
			if (!check)
				reset(finalSched, start, end);				// backtrack to before the if statement.
			else return true;			
		}
	}
	return false;
}

void putInSched(vector<string> &finalSched, int start, int end, string name)
{
	for (int i = start; i <= end; i++)
		finalSched[i] = name;
}

bool schedable(vector<string> &finalSched, int start, int end)
{
	for (int i = start; i <= end; i++)
		if (finalSched[i] != "0")
			return false;
	return true;
}

void reset(vector<string> &finalSched, int start, int end)
{
	for (int i = start; i <= end; i++)
		finalSched[i] = "0";
}

vector<instructionType> breakDown(vector<Course> &courseList)
{
	vector<instructionType> theList = vector<instructionType>();
	for (int i = 0; i < courseList.size(); i++)
	{
		for (int j = 0; j < courseList[i].numInstr(); j++)
		{
			instructionType k = instructionType(j, &(courseList[i]));
			theList.push_back(k);
		}
	}
	return theList;
}

int main()
{
	vector<Course> test = vector<Course>();
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
	test.push_back(check);
	vector<instructionType> theFruit = breakDown(test);
	for (int i = 0; i < theFruit.size(); i++)
	{
		instructionType testing = theFruit[i];
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

	//the grand test:
	cout << endl << "The scheduling test: " << endl;
	vector<string> finalSched = vector<string>(200, "0");
	schedule(finalSched, theFruit, 0);
	for (int i = 0; i < finalSched.size(); i++)
	{
		cout << finalSched[i] << endl;
	}
	cout << endl;
	}
}
