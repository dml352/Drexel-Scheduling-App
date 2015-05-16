/***
Unit test for the Course class
@Author: Duc Le
@Date: 5/15/2015
@Version One
***/

#include <iostream>
#include <vector>
#include <sstream>
#include "Course.h"
#include "instructionType.h"
using namespace std;

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

	  cout << "Course Code: " << check.getCourseCode() << endl;
	  cout << "Number of instructionType: " << check.numInstr() << endl;
	  //test inspector
	  for (int i = 0; i < check.numInstr(); i++)
	  {
		  cout << check.getInstrType(i) << ": " << endl;
		  vector< vector<int> > time =
			  check.getTimeList(check.getInstrType(i));
		  cout << "Start time: ";
		  for (int j = 0; j < time[0].size(); j++)
			  cout << time[0][j] << " ";
		  cout << endl;
		  cout << "End time: ";
		  for (int k = 0; k < time[1].size(); k++)
			  cout << time[1][k] << " ";
		  cout << endl;
		  vector<string> CRN = check.getListCRN(i);
		  cout << "CRN List: ";
		  for (int m = 0; m < CRN.size(); m++)
		  	  cout << CRN[m] << " ";
		  cout << endl;
	  }
}


