/***
Course object will contains all the information of a course, including the name, code, department, and a vector of timeSlot
It will only contains the information. The scheduling algorithm will be in a separate file for better debugging.
@Author: Duc Minh Le
@Date: 4/19/2015
@Version Two.
***/

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
using namespace std;

/***
string courseCode;		// the courseCode must specify the category. 
													
	vector<string> instrType;				// the list of instruction types (lab, lec, rec, ...). instructionType is a type that holds the name	
													// and the list of start and end time of it.
	vector< vector<int> > startTime;				// each row of this vector will hold the available start time each instruction type 
													// (lab, lecture, recitation, ...). They will correspond to their index in instrType
	vector< vector<int> > endTime;					// this is the vector of endtimes, corresponding to the startTime vector above.
	vector< vector<string> > listCRN;
**/
//Constructor
Course::Course()
{
	instrType = vector<string>();
	startTime = vector< vector<int> >();
	endTime = vector< vector<int> >();
	listCRN = vector< vector<string> >();
}
	
//inspector
vector< vector<int> > Course::getTimeList(string instructionType)  // return the list of the available time for a given instruction type.
																	// the returned vector will have a vector of start and a vector of end time.
{
	vectoc< vector<int> > out = vector< vector<int> >();
	for (int i = 0; i < instrType.size(); i++)
	{
		if (instrType[i] == instructionType)
		{
			out.push_back(startTime[i]);
			out.push_back(endTime[i]);
			break;
		}
	}
	return out;
}

int Course::numInstr() const
{
	return instrType.size();
}

string Course::getCourseCode() const
{
	return courseCode;
}

string Course::getCourseName() const
{
	return courseName;
}
	 
//Mutator
void Course::setCourseCode(string first)
{
	courseCode = first;
}

void Course::setCourseName(string name)
{
	courseName = name;
}

void Course::addInstrType(string instructionType)
{
	instrType.push_back(instructionType);	// insert the new instruction type, then allocate the space for starttime and endtime vectors.
	startTime.push_back(vector<int>());
	endTime.push_back(vector<int>());
	listCRN.push_back(vector<string>());
}

void Course::addTime(string instructionType, int start, int end, string CRN)
{
	//insert a new start and end time pair for an already existed instructiontype.
	for (int i = 0; i < instrType.size(); i++)
	{
		if (instrType[i] == instructionType)
		{
			startTime[i].push_back(start);
			endTime[i].push_back(end);
			listCRN[i].push_back(CRN);
			break;
		}
	}
}
	
	//Destructor
	~Course(){};
}