#include "DateGetter.h"


DateGetter::DateGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


DateGetter::~DateGetter(void){
}

string DateGetter::Tokenize(){
	string Date = LargeDate, tempDateOne = "no date", keyword = OnAndBy;
	unsigned int position, startPos = 0, indicator = 0, PositionOfSlash = 2, PositionOfMonth = 3, PositionOfYear = 6;
	unsigned int KeywordSize = 2, DateSize = 10, YearSize = 4, MonthDaySize = 2, WeekSize = 3, NextWeekSize = 8;
	unsigned int sizeOne = 13, sizeTwo = 6, sizeThree = 11;

	string tempDateTwo = tempDateOne, tempDateThree = tempDateOne;

	while(Date == LargeDate && indicator <= KeywordSize){

	if((command == Add || command == Edit)){
		do{
			position = (*uncategorizedInfo).find(keyword.substr(indicator, KeywordSize), startPos);

			if(position != string::npos && position + KeywordSize + unit < (*uncategorizedInfo).size() - unit){
				unsigned int maxSize = (*uncategorizedInfo).substr(position + KeywordSize + unit).size();

				if(DateSize <= maxSize){
					tempDateOne = (*uncategorizedInfo).substr(position + KeywordSize + unit, DateSize);

					if((tempDateOne.substr(PositionOfSlash,unit)) == slash && (tempDateOne.substr(PositionOfSlash + PositionOfSlash + unit,unit)) == slash){
						tempDateOne = tempDateOne.substr(PositionOfYear,YearSize) + tempDateOne.substr(PositionOfMonth,MonthDaySize) + tempDateOne.substr(start, MonthDaySize);
					}
				}

				if(WeekSize <= maxSize){
					tempDateTwo = (*uncategorizedInfo).substr(position + KeywordSize + unit, WeekSize);
					tempDateTwo = Tokenizer::GetDateFromWeek(tempDateTwo);
				}

				if(NextWeekSize <= maxSize){
				    tempDateThree = (*uncategorizedInfo).substr(position + KeywordSize + unit, NextWeekSize);
					tempDateThree = Tokenizer::GetDateFromWeek(tempDateThree);
				}

				if(Tokenizer::ifNumber(tempDateOne)){
					Date = tempDateOne;
					Tokenizer::chopInfo((*uncategorizedInfo), position, sizeOne);
					break;
				}
				else if(Tokenizer::ifNumber(tempDateTwo)){
					Date = tempDateTwo;
					Tokenizer::chopInfo((*uncategorizedInfo), position, sizeTwo);
					break;
				}
				else if(Tokenizer::ifNumber(tempDateThree)){
					Date = tempDateThree;
					Tokenizer::chopInfo((*uncategorizedInfo), position, sizeThree);
					break;
				}
			}

			startPos = position + unit;

		 }while(position != string::npos);
	}

	indicator += KeywordSize;
	}

	if(command == Add && Date == LargeDate){
		char date[8];
	    time_t localTime;
	    struct tm timeNow;

	    localTime = time(NULL);
	    localtime_s(&timeNow,&localTime);

	    strftime(date, sizeof(date), "%Y%m%A%d",&timeNow);

		Date = DateConverter(timeNow.tm_year + 1900, timeNow.tm_mon + 1, timeNow.tm_mday);
	}

	return Date;
}