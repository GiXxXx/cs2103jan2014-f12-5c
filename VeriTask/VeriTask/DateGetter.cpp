#include "DateGetter.h"


DateGetter::DateGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


DateGetter::~DateGetter(void){
}

string DateGetter::Tokenize(){
	string Date = LargeDate, keyword;
	unsigned int indicator = zero;

	if(command == Add || command == Edit){
		while(Date == LargeDate && indicator <= TwoUnit){

			keyword = OnAndBy.substr(indicator, TwoUnit);

			Date = GetDateFromDate(*uncategorizedInfo, keyword);

			if(Date == LargeDate){
			Date = GetDateFromWeek(*uncategorizedInfo, keyword);
			}
    
	        indicator += TwoUnit;
		}
	}

/*	if(command == Add && Date == LargeDate){
		char date[8];
	    time_t localTime;
	    struct tm timeNow;

	    localTime = time(NULL);
	    localtime_s(&timeNow,&localTime);

	    strftime(date, sizeof(date), "%Y%m%A%d",&timeNow);

		Date = DateConverter(timeNow.tm_year + 1900, timeNow.tm_mon + 1, timeNow.tm_mday);
	}
	*/
	return Date;
}


string DateGetter::GetDateFromDate(string &Input, string keyword){
	string Date = LargeDate, tempDate, elementOne, elementTwo, elementThree;
	unsigned int position, startPos = start, positionOne, positionTwo;

	do{
		position = Input.find(keyword, startPos);

		if(position != string::npos){
			tempDate = Input.substr(position + ThreeUnit);

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
			tempDate = Input.substr(position + ThreeUnit);

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
        	    	chopInfo(Input, position, size + ThreeUnit);
        	    	break;
        		}
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

void DateGetter::ChangeToLowerCase(string &input){
	for(unsigned int i = 0; i < input.size(); i++){
		if(input[i] >= A && input[i] <= Z){
			input[i] = input[i] - (A - a); 
		}
	}

	return;
}