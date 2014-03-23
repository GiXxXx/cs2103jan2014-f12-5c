#include "Identifier.h"
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

const string number = "0123456789";
const string slash = "/";
const string colon = ":";
const string space = " ";
const string Mark = "mark";
const string Add = "add";
const string Delete = "delete";
const string Edit = "edit";
const string Undo = "undo";
const string Done = "done";
const string Search = "search";
const string UnDone = "undone";
const string CannotBeDone = "cannot be done";
const string LargeDate = "99999999";
const string LargeTime = "9999";
const string OnAndBy = "onby";
const string at = "at";
const string to = "to";
const string from = "from";
const string by = "by";
const string monday = "Mon";
const string tuesday = "Tue";
const string thursday = "thu";
const string wednesday = "wed";
const string friday = "fri";
const string saturday = "sat";
const string sunday = "sun";
const string NextMonday = "next Mon";
const string NextTuesday = "next Tue";
const string NextWednesday = "next Wed";
const string NextThursday = "next Thu";
const string NextFriday = "next Fri";
const string NextSaturday = "next Sat";
const string NextSunday = "next Sun";
const signed int start = 0;
const signed int unit = 1;
const int zero = 0;

/*because only the relavent attribute will be filled, denpending on the command given,
 *some attributes are given a initial value. this is to make it easy for display.
 *for example, when display all the tasks on the screen, it will be like the following:
 *          number        date          start        end        event         status
 *             1      2014/03/10        13:10       14:10       sleep           0
 *             2      2014/03/11                                study           0
 *             3                                                submit V0.1     0
 *
 * @jiacheng,during the meeting we discussed about how to display the existing tasks when opening the programme,
 * i think maybe it is better not to use the Identifier to go through all saved information because it is time consuming
 * and it also requires another constructor for the Identifier class, one for userInput, one for getline from the txt file.
 * therefore, i thougt it might be better to design like this, where information are saved in a standard format(shown above),
 * in this case, you could just copy one whole line of the txt file and display it.
 */
Identifier::Identifier(string userInput){
	_userInput = userInput; 

	//assert(_userInput.find(" ")!=string::npos); //ensure that >1 word in user input

	int position = _userInput.find_first_of(space) + 1; 

	uncategorizedInfo = _userInput.substr(position);
}

/* sorry, still used the chopInfo method in this version. It's quite hard to handle the iterator method,
 * i will make necessary changes after this deadline
 */
void Identifier::chopInfo(string &oldInfo, int position, int size){
	unsigned int EndPos = position + start + size;

	if(EndPos < oldInfo.size()){
		oldInfo = oldInfo.substr(start, position) + oldInfo.substr(position + unit + size);
	}

	else{
		oldInfo = oldInfo.substr(start, position);
	}
	return;
}

string Identifier::getCommand(){
	string Command = _userInput.substr(start,_userInput.find_first_of(space));
	return Command;
}

string Identifier::getDate(){
	string Date = LargeDate, tempDateOne = "no date", keyword = OnAndBy;
	int position, startPos = 0, indicator = 0, PositionOfSlash = 2, PositionOfMonth = 3, PositionOfYear = 6;
	int KeywordSize = 2, DateSize = 10, YearSize = 4, MonthDaySize = 2, WeekSize = 3, NextWeekSize = 8;
	unsigned int sizeOne = 13, sizeTwo = 6, sizeThree = 11;

	string tempDateTwo = tempDateOne, tempDateThree = tempDateOne;

	while(Date == LargeDate && indicator <= KeywordSize){

	if((getCommand() == Add || getCommand() == Edit)){
		do{
			position = uncategorizedInfo.find(keyword.substr(indicator, KeywordSize), startPos);

			if(position != string::npos && position + KeywordSize + unit < uncategorizedInfo.size() - unit){
				signed int maxSize = uncategorizedInfo.substr(position + KeywordSize + unit).size();

				if(DateSize <= maxSize){
					tempDateOne = uncategorizedInfo.substr(position + KeywordSize + unit, DateSize);

					if((tempDateOne.substr(PositionOfSlash,unit)) == slash && (tempDateOne.substr(PositionOfSlash + PositionOfSlash + unit,unit)) == slash){
						tempDateOne = tempDateOne.substr(PositionOfYear,YearSize) + tempDateOne.substr(PositionOfMonth,MonthDaySize) + tempDateOne.substr(start, MonthDaySize);
					}
				}

				if(WeekSize <= maxSize){
					tempDateTwo = uncategorizedInfo.substr(position + KeywordSize + unit, WeekSize);
					tempDateTwo = GetDateFromWeek(tempDateTwo);
				}

				if(NextWeekSize <= maxSize){
				    tempDateThree = uncategorizedInfo.substr(position + KeywordSize + unit, NextWeekSize);
					tempDateThree = GetDateFromWeek(tempDateThree);
				}

				if(ifNumber(tempDateOne)){
					Date = tempDateOne;
					chopInfo(uncategorizedInfo, position, sizeOne);
					break;
				}
				else if(ifNumber(tempDateTwo)){
					Date = tempDateTwo;
					chopInfo(uncategorizedInfo, position, sizeTwo);
					break;
				}
				else if(ifNumber(tempDateThree)){
					Date = tempDateThree;
					chopInfo(uncategorizedInfo, position, sizeThree);
					break;
				}
			}

			startPos = position + unit;

		 }while(position != string::npos);
	}

	indicator += KeywordSize;
	}

	return Date;
}

string Identifier::getStartTime(){
	string StartTime, tempTime;

	if(getCommand() == Add || getCommand() == Edit){
		StartTime = getTime(uncategorizedInfo, from);
	}

	return StartTime;
}

string Identifier::getEndTime(){
	string EndTime;
	if(getCommand() == Add || getCommand() == Edit){
		EndTime = getTime(uncategorizedInfo, at);

		if(EndTime == LargeTime)
			EndTime = getTime(uncategorizedInfo, by);

		if(EndTime == LargeTime)
			EndTime = getTime(uncategorizedInfo, to);
		}

	return EndTime;
}

string Identifier::getEvent(){
	string Event = space;
	if(getCommand() == Add || getCommand() == Edit){
		Event = uncategorizedInfo;
	}
	return Event;
}

int Identifier::getTaskNumber(){
	int TaskNumber = 0, position = start, size = unit;
	if(getCommand() == Edit){
		TaskNumber =  std::stoi(uncategorizedInfo.substr(position,size));
		chopInfo(uncategorizedInfo, position, size);
	}
	else if(getCommand() == Delete){
		TaskNumber = std::stoi(uncategorizedInfo);
	}
	return TaskNumber;
}

string Identifier::getKeyword(){
	string Keyword;
	if(getCommand() == Search){
		Keyword = uncategorizedInfo;
	}
	return Keyword;
}

/*this function is not used right now, but i think it might be a good idea.
 *this function extract all possible attributes for a ADD operation,
 *by writing similar function like this one, we can have less work in writing the TASK class,
 *since we only need to call one function to get all necessary information for the current operation.
 *besides, the code for Identifier class can also be simplified.
 *however, this requires the Task class to be able to access the private attributes of the Identifier class,
 *therefore, maybe we should consider using inherient classes.
 */
void Identifier::getAddEditInfo(){
	getTaskNumber();
	getDate();
	getStartTime();
	getEndTime();
	getEvent();
}	

bool Identifier::ifNumber(string test){
	unsigned int matchCount = 0;
	bool isNumber = false;

	for(unsigned int i = 0; i < test.size(); i++){
		for(unsigned int j = 0; j < 10; j++){
			if(test[i] == number[j]){
				matchCount++;
			}
		}
	}
	
	if(matchCount == test.size()){
		isNumber = true;
	}

	return isNumber;
}

string Identifier::getTime(string test, string keyword){
	string Time = LargeTime, tempTime;
	int TimeSize = 5, MinSize =2;
	unsigned int position, startPos = start, size = keyword.size() + TimeSize + unit;

	if(size < uncategorizedInfo.size())
		do{
			position = test.find(keyword, startPos);

			if(position != string::npos){
				signed int maxSize = test.substr(position + keyword.size() + unit).size();

				if(TimeSize <= maxSize){
					tempTime = test.substr(position + keyword.size() + unit, TimeSize);

				if((tempTime.substr(MinSize,unit)) == colon){
					tempTime = tempTime.substr(start, MinSize) + tempTime.substr(start + MinSize + unit, MinSize);

				    if(ifNumber(tempTime)){
						Time = tempTime;
						chopInfo(uncategorizedInfo, position, size);
					    break;
					}
				}
			}
			}

			startPos = position + unit;

		 }while(position != string::npos);

	return Time;
}

string Identifier::getStatus(){
	string status;
	if(getCommand() == Mark){
		status = uncategorizedInfo;
	}

	if(status == Done || status == UnDone || status == CannotBeDone) {
		return status;
	} 

	else
		return "error";
}

string Identifier::GetDateFromWeek(string test){
	char buffer[100]={0};
	time_t now;
	struct tm timenow;
	time_t localTime;
	int taskDayOfWeek;

	if(test == monday){
		taskDayOfWeek = 0;
	}
	else if(test == tuesday){
		taskDayOfWeek = 1;
	}
	else if(test == wednesday){
		taskDayOfWeek = 2;
	}
	else if(test == thursday){
		taskDayOfWeek = 3;
	}
	else if(test == friday){
		taskDayOfWeek = 4;
	}
	else if(test == saturday){
		taskDayOfWeek = 5;
	}
	else if(test == sunday){
		taskDayOfWeek = 6;
	}
	else if(test == NextMonday){
		taskDayOfWeek = 7;
	}
	else if(test == NextTuesday){
		taskDayOfWeek = 8;
	}
	else if(test == NextWednesday){
		taskDayOfWeek = 9;
	}
	else if(test == NextThursday){
		taskDayOfWeek = 10;
	}
	else if(test == NextFriday){
		taskDayOfWeek = 11;
	}
	else if(test == NextSaturday){
		taskDayOfWeek = 12;
	}
	else if(test == NextSunday){
		taskDayOfWeek = 13;
	}
	else{
		return test;
	}

	localTime = time(NULL);
	localtime_s(&timenow,&localTime);

	strftime(buffer, 100, "%Y-%m-%A-%d",&timenow);
	//puts(buffer);
	int currentDayOfWeek = (timenow.tm_wday+6)%7;
	int currentYear = timenow.tm_year+1900;
	int currentMonth = timenow.tm_mon+1;
	int currentday = timenow.tm_mday;
	int currentTotalDay = timenow.tm_yday;
	
	//enum aWeek {sunday,tuesday,wednesday,thursday,friday,saturday,monday};
	
	int taskDay;
	int taskMonth = currentMonth;
	int taskYear = currentYear;

	taskDay = currentday + taskDayOfWeek-currentDayOfWeek;

	if((currentMonth ==1||currentMonth==3||currentMonth==5||currentMonth==7||currentMonth==8
		||currentMonth==10||currentMonth==12) && taskDay>31){
				taskDay = taskDay - 31;
				++taskMonth;
	}
	else if((currentMonth==4||currentMonth==6||currentMonth==9||currentMonth==11) && taskDay>30){
		taskDay = taskDay - 30;
		++taskMonth;
	}
	else if(currentMonth ==2 && currentYear%4==0 && taskDay>29){
		taskDay = taskDay - 29;
		++taskMonth;
		}
	else if(currentMonth ==2 && currentYear%4!=0 && taskDay>28){
		taskDay = taskDay - 28;
		++taskMonth;
	}

	if(taskMonth>12){
		taskMonth = taskMonth - 12;
		++taskYear;
	}

	ostringstream outstr;

	outstr << taskYear;

	if(taskMonth < 10){
		outstr << zero;
	}

	outstr << taskMonth;

	if(taskDay < 10){
		outstr << zero;
	}

	outstr << taskDay;

	return outstr.str();	
}

