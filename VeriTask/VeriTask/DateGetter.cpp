#include "DateGetter.h"


DateGetter::DateGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


DateGetter::~DateGetter(void){
}

string DateGetter::Tokenize(){
	string Date = LargeDate, keyword;
	unsigned int indicator = zero;

	if(command == Add || command == Edit || command == Display){
		if(command == Display){
			unsigned int position = (*uncategorizedInfo).find_first_not_of(space);
			*uncategorizedInfo = (*uncategorizedInfo).substr(position);
			*uncategorizedInfo = by + *uncategorizedInfo;
		}

		while(Date == LargeDate && indicator <= EightUnit){

			keyword = preposition[indicator];

			Date = GetDateFromDate(*uncategorizedInfo, keyword);

			if(Date == LargeDate){
			Date = GetDateFromWeek(*uncategorizedInfo, keyword);
			}
			
			if(Date == LargeDate){
			Date = GetDateFromDescriptionOne(*uncategorizedInfo, keyword);
			}

			if(Date == LargeDate){
			Date = GetDateFromDescriptionTwo(*uncategorizedInfo, keyword);
			}
    
	        indicator += OneUnit;
		}

		if(Date == LargeDate && command == Display){
			*uncategorizedInfo = (*uncategorizedInfo).substr(FourUnit);
		}
	}

	return Date;
}


string DateGetter::GetDateFromDate(string &Input, string keyword){
	string Date = LargeDate, tempDate, elementOne, elementTwo, elementThree;
	unsigned int position, startPos = start, positionOne, positionTwo;

	do{
		position = Input.find(keyword, startPos);

		if(position != string::npos){
			tempDate = Input.substr(position + keyword.size());

	    	positionOne = tempDate.find_first_of(slash);
	    	positionTwo = tempDate.find_last_of(slash);

    		if(positionOne == string::npos || positionTwo == string::npos || positionOne == positionTwo){
	    		positionOne = tempDate.find_first_of(dot);
    		    positionTwo = tempDate.find_last_of(dot);
    		}

    		if(positionOne == string::npos || positionTwo == string::npos || positionOne == positionTwo){
	    		positionOne = tempDate.find_first_of(dash);
    		    positionTwo = tempDate.find_last_of(dash);
    		}

	    	if(positionOne == string::npos || positionTwo == string::npos || positionOne == positionTwo){
    			positionOne = tempDate.find_first_of(space);
	    	    positionTwo = tempDate.find_first_of(space, positionOne + OneUnit);
    		}
		
    		if(positionOne != string::npos && positionTwo != string::npos && positionOne != positionTwo){
	    		elementOne = tempDate.substr(start, positionOne); 
	    	    elementTwo = tempDate.substr(positionOne + OneUnit, positionTwo - positionOne - OneUnit);
	    	    elementThree = tempDate.substr(positionTwo + OneUnit, FourUnit);

	
        		if(!isNumber(elementTwo)){
		 			MonthConvertor(elementTwo);
	        	}

         		if(!isNumber(elementThree)){
	         		elementThree = tempDate.substr(positionTwo + OneUnit,TwoUnit);
        		}

	        	if(!isNumber(elementThree)){
        			elementThree = tempDate.substr(positionTwo + OneUnit, OneUnit);
        		}

        		ChangeDoubleDigit(elementOne);
        		ChangeDoubleDigit(elementTwo);
        		ChangeDoubleDigit(elementThree);
 		
	        	if(elementOne.size() == FourUnit){
        			tempDate = elementOne + elementTwo + elementThree;
        		}
	
        		if(elementThree.size() == FourUnit){
        			tempDate = elementThree + elementTwo + elementOne;
    	    	}

				if(isNumber(tempDate)){
        			Date = tempDate;
        			chopInfo((*uncategorizedInfo), position, elementThree.size() + FourUnit + positionTwo);
        			break;
	        	}
    		}
			
			startPos = position + OneUnit;
		}
	}while(position != string::npos);

	return Date;
}

string DateGetter::GetDateFromWeek(string &Input, string keyword){
	char buffer[100]={0};
	time_t localTime;
	struct tm timenow;
	int taskDayOfWeek = zero;
	unsigned int positionOne, positionTwo, position, startPos = start;
	unsigned int size;
	string week, tempDate;
	string Date = LargeDate;

	do{
		position = Input.find(keyword, startPos);

		if(position != string::npos){
			tempDate = Input.substr(position + keyword.size());

        	positionOne = tempDate.find_first_of(space);
        	week = tempDate.substr(start, positionOne);
        	size = positionOne ;

        	if(week == Next){
     		positionOne = positionOne + OneUnit;
    		positionTwo = tempDate.find_first_of(space, positionOne);
     		size = positionTwo;
    		week = tempDate.substr(positionOne, positionTwo - positionOne);
    		taskDayOfWeek = std::stoi(seven);
        	}

        	if(week == This){
        		positionOne = positionOne + OneUnit;
        		positionTwo = tempDate.find_first_of(space, positionOne);
        		size = positionTwo;
        		week = tempDate.substr(positionOne, positionTwo - positionOne);
        	}

			if(week == Week || week == Weeks){
				week = sun;
			}

			if(!isNumber(week)){

            	WeekConvertor(week);

            	if(isNumber(week)){
            		taskDayOfWeek = taskDayOfWeek + std::stoi(week);
            		localTime = time(NULL);
            	    localtime_s(&timenow,&localTime);

            	    strftime(buffer, 100, "%Y-%m-%A-%d",&timenow);

                	int currentDayOfWeek = (timenow.tm_wday+6)%7;
                	int currentYear = timenow.tm_year+1900;
                 	int currentMonth = timenow.tm_mon+1;
                	int currentday = timenow.tm_mday;
                	int currentTotalDay = timenow.tm_yday;
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
  
                	Date = DateConverter(taskYear, taskMonth, taskDay);
        	    	chopInfo(Input, position, size + keyword.size());
        	    	break;
        		}
  			}
			
			startPos = position + OneUnit;
		}
	}while(position != string::npos);

	return Date;
}

string DateGetter::GetDateFromDescriptionTwo(string& Input, string keyword){
	string Date = LargeDate, tempDate;
	unsigned int position, startPos = start, positionOne, positionTwo, indicator = zero, size;
	string description[SevenUnit] = {theDayAfterTomorrow, theDayAfterTmr, dayAfterTomorrow, dayAfterTmr, tomorrow, tmr, today};

	do{
		position = Input.find(keyword, startPos);

		if(position != string::npos){
			tempDate = Input.substr(position + keyword.size());

			while(Date == LargeDate && indicator < SevenUnit){
				positionOne = tempDate.find(description[indicator]);
	    	    
				if(positionOne != string::npos){
					size = description[indicator].size();
					if(positionOne == zero && tempDate.find_first_of(space) == size){
						Date = DateConvertorFromDescription(description[indicator], space);
						chopInfo(Input, position, description[indicator].size() + keyword.size());
						break;
					}
				}

				indicator++;
			}
    	
			startPos = position + OneUnit;
		}

	}while(position != string::npos && Date != LargeDate);

	indicator = zero;

	while(Date == LargeDate && indicator < SevenUnit && keyword == at){
		positionOne = Input.find(description[indicator]);

		if(positionOne == zero){
			Date = DateConvertorFromDescription(description[indicator], space);
			chopInfo(Input, positionOne, description[indicator].size());
			break;
		}
		else{
			positionTwo = Input.rfind(description[indicator]);

	   		if(positionTwo != string::npos){
				string checker = Input.substr(positionTwo + description[indicator].size() + OneUnit, TenUnit);
	
				if(checker == tenSpaces){
               		Date = DateConvertorFromDescription(description[indicator], space);
               		chopInfo(Input, positionTwo, description[indicator].size());
           			break;
	       		}
				else{
					Date = DateConvertorFromDescription(description[indicator], space);
	        		chopInfo(Input, positionOne, description[indicator].size());
	        		break;
				}
			}
	   	}

		indicator++;
	}

	return Date;
}

string DateGetter::GetDateFromDescriptionOne(string& Input, string keyword){
	string Date = LargeDate, tempDate, element, number;
	unsigned int position, startPos = start, positionOne, positionTwo, indicator = zero;
	const string description[EightUnit] = {days, day, months, month, years, year, Week, Weeks};

	do{
		position = Input.find(keyword, startPos);

		if(position != string::npos){
			while(Date == LargeDate && indicator < EightUnit){
				tempDate = Input.substr(position);
				positionOne = tempDate.find(description[indicator]);
	    	    
				if(positionOne != string::npos){
					positionTwo = keyword.size();
					tempDate = tempDate.substr(positionTwo, positionOne - positionTwo - OneUnit);
	
					number = tempDate;

					if(!isNumber(tempDate) && tempDate != This && tempDate != Next){
    					number = changeWordToNumber(tempDate);
					}

					if(number != Zero){
		    			Date = DateConvertorFromDescription(description[indicator], number);
						chopInfo(Input, position, keyword.size() + OneUnit + tempDate.size() + description[indicator].size());
						break;
		    		}
				}

				indicator++;
			}
    	
			startPos = position + OneUnit;
		}

		}while(position != string::npos);

	return Date;
}
	

string DateGetter::DateConverter(int year, int month, int day){
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

void DateGetter::MonthConvertor(string &Month){
	ChangeToLowerCase(Month);

	if(Month == jan || Month == january){
		Month = one;
	}
	else if(Month == feb || Month == february){
		Month = two;
	}
	else if(Month == mar || Month == march){
		Month = three;
	}
	else if(Month == apr || Month == april){
		Month = four;
	}
	else if(Month == may){
		Month = five;
	}
	else if(Month == jun || Month == june){
		Month = six;
	}
	else if(Month == jul || Month == july){
		Month = seven;
	}
	else if(Month == aug || Month == august){
		Month = eight;
	}
	else if(Month == sep || Month == september){
		Month = nine;
	}
	else if(Month == octo || Month == october){
		Month = ten;
	}
	else if(Month == nov || Month == november){
		Month = eleven;
	}
	else if(Month == dece || Month == december){
		Month = twelve;
	}

	return;
}

void DateGetter::WeekConvertor(string &Week){
	ChangeToLowerCase(Week);

	if(Week == mon || Week == monday){
		Week = Zero;
	}
	else if(Week == tue || Week == tuesday){
		Week = one;
	}
	else if(Week == wed || Week == wednesday){
		Week = two;
	}
	else if(Week == thu || Week == thursday){
		Week = three;
	}
	else if(Week == fri || Week == friday){
		Week = four;
	}
	else if(Week == sat || Week == saturday){
		Week = five;
	}
	else if(Week == sun || Week == sunday){
		Week = six;
	}
	return;
}

string DateGetter::DateConvertorFromDescription(string description, string descriptionTwo){
		int adder = zero;

		if(isNumber(descriptionTwo)){
			adder = std::stoi(descriptionTwo);
		}

		if(description == day || description == days){
			adder = adder * OneUnit;
		}

		if(description == Week || description == Weeks){
			adder = adder * SevenUnit;
		}

		if(description == month || description == months){
			adder = adder * TenUnit * ThreeUnit;
		}

		if(description == year || description == years){
			adder = adder * yearDays;
		}

		if(description == tmr || description == tmr){
			adder = adder * OneUnit;
		}

		if(description == theDayAfterTmr || description == theDayAfterTomorrow || description == dayAfterTmr || description == dayAfterTomorrow){
			adder = adder * TwoUnit;
		}

		time_t local = time(NULL);
		struct tm *timeNow = NULL;
		localtime_s(timeNow, &local);
		timeNow->tm_mday += adder;
		time_t newTime = mktime(timeNow);
		localtime_s(timeNow, &newTime);

		if(description == year || description == years){
			if(descriptionTwo == This){
    			timeNow->tm_mday = monthDay;
	    		timeNow->tm_mon = yearMonth;
			}
			else if(descriptionTwo == Next){
				timeNow->tm_mday = monthDay;
	    		timeNow->tm_mon = yearMonth;
				timeNow->tm_year += OneUnit;
			}
		}

		if(description == month || description == months){
			if(descriptionTwo == This){
				int temp = timeNow->tm_mon;

		        while(timeNow->tm_mon == temp){
	    			timeNow->tm_mday++;
	    	        newTime = mktime(timeNow);
    	        	localtime_s(timeNow, &newTime);
    			}

	    		timeNow->tm_mday--;
    		    newTime = mktime(timeNow);
     	        localtime_s(timeNow, &newTime);

    			}
    			else if(descriptionTwo == Next){
					int temp = timeNow->tm_mon + OneUnit;

					while(timeNow->tm_mon <= temp){
	    			timeNow->tm_mday++;
	    	        newTime = mktime(timeNow);
    	        	localtime_s(timeNow, &newTime);
    		    	}

	        		timeNow->tm_mday--;
        		    newTime = mktime(timeNow);
         	        localtime_s(timeNow, &newTime);
	    		}
		}

		int Year = timeNow->tm_year + yearAdder;
		int Month = timeNow->tm_mon + OneUnit;
		int Day = timeNow->tm_mday;

		string Date = DateConverter(Year, Month, Day);

		return Date;
	}