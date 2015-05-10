/**
This script holds the information about the instructionType objects (helper objects for the scheduling algorithm)

Duc Le
5/1/2015
Version One

**/

#include <vector>
#include <iostream>
#include "instructionType.h"

using namespace std;

/***
string name; //CS265Lab, CS265Lecture, ...
		vector<int> startTime;
		vector<int> endTime;
		vector<string> CRN;
		Course* original;
***/

instructionType::instructionType()
{
	name = "";
	startTime = vector<int>();
	endTime = vector<int>();
	CRN = vector<string>();
	original = NULL;
}

instructionType::instructionType(int index, Course *mother)
{
	name = mother -> getCourseCode() + *mother.instrType[i];
	vector< vector<int> > time = mother -> getTimeList(*mother.instrType[i]);
	startTime = time[0];
	endTime = time[1];
	CRN = *mother.listCRN(index);
	original = mother;
}

int instructionType::getSize() const
{
	return startTime.size();
}

string instructionType::getName() const
{
	return name;
}

int instructionType::getStart(int index) const
{
	return startTime[index];
}

int instructionType::getEnd(int index) const
{
	return endTime[index];
}

string instructionType::getCRN(int index) const
{
	return listCRN[index];
}

Course* getMaster() const
{
	return original;
}

void instructionType::addStartTime(int x)
{
	startTime.push_back(x);
}

void instructionType::addEndTime(int x)
{
	endTime.push_back(x);
}

void instructionType::addCRN(string x)
{
	CRN.push_back(x);
}



