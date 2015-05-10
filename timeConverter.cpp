/*****
Time Converter, converting the time string of TMS into weekly timeSlot

Duc Le
4/30/2015
Version One

*****/

#include <vector>
#include <string>
#include <sstream>
#include "timeConverter.h"
using namespace std;

vector<int> timeConverter::timeConvert(string day, string hour)
{
	vector<int> time = vector<int>();
	int weekDay;
	string whichHalfStart = hour.substr(6,2);
	string startHour = hour.substr(0,2);
	string startHalf = hour.substr(3,2);
	string whichHalfEnd = hour.substr(17,2);
	string endHour = hour.substr(11,2);
	string endHalf = hour.substr(14,2);
	
	int start, end, halfHour;
	int baseHour = 0;
	int morningStart = 8;
	int afternoonStart = 0;
	if (whichHalfStart == "pm")
	{
		baseHour = 8;		// number of morning 30-minute slots.
	}
	halfHour = 0;
	int temp;
	stringstream(startHalf) >> temp;
	if (temp > 30)
		halfHour = 1;
	if (whichHalfStart == "am")
	{
		stringstream(startHour) >> temp;
		start = 2 * (temp - morningStart) + halfHour;
	}
	else if (whichHalfStart == "pm")
	{
		stringstream(startHour) >> temp;
		start = baseHour + 2 * (temp % 12) + halfHour;		// we take the remainder by 12, so that the 12pm will obey the same 
																				// rule as 1pm, 2pm, ...
	}
	
	if (whichHalfEnd == "pm")
	{
		baseHour = 8;		// number of morning 30-minute slots.
	}
	halfHour = 0;
	stringstream(endHalf) >> temp;
	if (temp > 30)
		halfHour = 1;
	if (whichHalfEnd == "am")
	{
		stringstream(endHour) >> temp;
		end = 2 * (temp - morningStart) + halfHour;
	}
	else if (whichHalfEnd == "pm")
	{
		stringstream(endHour) >> temp;
		end = baseHour + 2 * (temp % 12) + halfHour;		// we take the remainder by 12, so that the 12pm will obey the same 
																				// rule as 1pm, 2pm, ...
	}
	
	//Note: end will indicate the timeSlot at the start of the end hour.
		if (day ==  "M")
			weekDay = 0;
		else if (day == "T")
			weekDay = 1;
		else if (day == "W")
			weekDay = 2;
		else if (day == "R")
			weekDay = 3;
		else if (day == "F")
			weekDay = 4;

	int slotPerday = 16;
	start = start + weekDay * slotPerday;
	end = end + weekDay * slotPerday;
	vector<int> out = vector<int>();
	out.push_back(start);
	out.push_back(end);
	return out;
}
