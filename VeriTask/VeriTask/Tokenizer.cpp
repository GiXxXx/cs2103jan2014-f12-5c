#include "Tokenizer.h"

Tokenizer::Tokenizer(string &userInput) :uncategorizedInfo(&userInput){ 
}

Tokenizer::~Tokenizer(){
}

void Tokenizer::chopInfo(string &oldInfo, int position, int size){
	unsigned int EndPos = position + size;

	if(EndPos < oldInfo.size()){
		oldInfo = oldInfo.substr(start, position) + oldInfo.substr(position + unit + size);
	}

	else{
		oldInfo = oldInfo.substr(start, position);
	}
	return;
}

bool Tokenizer::ifNumber(string test){
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

string Tokenizer::getTime(string test, string keyword){
	string Time = LargeTime, tempTime;
	int TimeSize = 5, MinSize =2;
	unsigned int position, startPos = start, size = keyword.size() + TimeSize + unit;

	if((*uncategorizedInfo).size() > size)
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
						chopInfo((*uncategorizedInfo), position, size);
					    break;
					}
				}
			}
			}

			startPos = position + unit;

		 }while(position != string::npos);

	return Time;
}

string Tokenizer::GetDateFromWeek(string test){
	char buffer[100]={0};
	time_t localTime;
	struct tm timenow;
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

	string Date = DateConverter(taskYear, taskMonth, taskDay);
    
	return Date;
}

string Tokenizer::DateConverter(int year, int month, int day){
	ostringstream outstr;

	outstr << year;

	if(month < 10){
		outstr << zero;
	}

	outstr << month;

	if(day < 10){
		outstr << zero;
	}

	outstr << day;

	return outstr.str();	
}


string Tokenizer::Tokenize(){
	return *uncategorizedInfo;
}