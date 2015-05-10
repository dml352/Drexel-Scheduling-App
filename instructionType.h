/**
This script holds the information about the instructionType objects (helper objects for the scheduling algorithm)

Duc Le
5/1/2015
Version One

**/

#include <vector>
#include <iostream>
using namespace std;

#ifndef _instr_
#define _instr_

class instructionType
{
	private:
		string name; //CS265Lab, CS265Lecture, ...
		vector<int> startTime;
		vector<int> endTime;
		vector<string> CRN;
		Course* original;    //pointer to the original course object, which contains more miscellanous information (department, ...)
	public:
		//Constructor
		instructionType();
		instructionType(const instructionType & mirror);
		instructionType(int index, Course *mother);				// this will be the mainly used constructor, breaking the Course object into instructionType.
		
		//Inspector
		string getName() const;
		int size() const;			//return the number of available sections in the object.
		int getStart(int index) const; 	//inspect the time vectors
		int getEnd(int index) const;
		int getCRN(int index) const;
		Course* getMaster() const;
		
		//Mutator
		void addStartTime(int x);
		void addEndTime(int y);
		void addCRN(string s);
		
		//Destructor
		~instructionType();
		
};

#endif