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
#include "timeSlot.h"
using namespace std;

#ifndef _Course_
#define _Course_
class Course
{
private:
	string courseCode;		// the courseCode must specify the category. 
													
	vector<string> instrType;				// the list of instruction types (lab, lec, rec, ...). instructionType is a type that holds the name	
													// and the list of start and end time of it.
	vector< vector<int> > startTime;				// each row of this vector will hold the available start time each instruction type 
													// (lab, lecture, recitation, ...). They will correspond to their index in instrType
	vector< vector<int> > endTime;					// this is the vector of endtimes, corresponding to the startTime vector above.
	vector< vector<string> > listCRN;		// the list that will be use to query back into the database for more information.

public:
	//Constructor
	Course();
	Course(const Course & mirror);  // copy constructor
	
	//inspector
	vector< vector<int> > getTimeList(string instrType);  // return the list of the available time for a given instruction type.
	int numInstr() const;
	string getCourseCode() const;
	string getCourseName() const;
	
	 
	//Mutator
	void setCourseCode(string first);
	void setCourseName(string name);
	void addInstrType(string instructionType);		//add another timeSlot and allocate memory for its components.
	void addTime(string instructionType, int start, int end, string CRN);	// add 1 more slot for an already existed instructionType.
	
	//Destructor
	~Course();

};
#endif