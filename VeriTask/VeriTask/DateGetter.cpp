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
	if(Month == jan || Month == Jan || Month == January || Month == january || Month == JAN || Month == JANUARY){
		Month = one;
	}
	else if(Month == feb || Month == Feb || Month == February || Month == february || Month == FEB || Month == FEBRUARY){
		Month = two;
	}
	else if(Month == mar || Month == Mar || Month == March || Month == march || Month == MAR || Month == MARCH){
		Month = three;
	}
	else if(Month == apr || Month == Apr || Month == April || Month == april || Month == APR || Month == APRIL){
		Month = four;
	}
	else if(Month == may || Month == May || Month == MAY){
		Month = five;
	}
	else if(Month == jun || Month == Jun || Month == June || Month == june || Month == JUN || Month == JUNE){
		Month = six;
	}
	else if(Month == jul || Month == Jul || Month == July || Month == july || Month == JUL || Month == JULY){
		Month = seven;
	}
	else if(Month == aug || Month == Aug || Month == August || Month == august || Month == AUG || Month == AUGUST){
		Month = eight;
	}
	else if(Month == sep || Month == Sep || Month == September || Month == september || Month == SEP || Month == SEPTEMBER){
		Month = nine;
	}
	else if(Month == octo || Month == Oct || Month == October || Month == october || Month == OCT || Month == OCTOBER){
		Month = ten;
	}
	else if(Month == nov || Month == Nov || Month == November || Month == november || Month == NOV || Month == NOVEMBER){
		Month = eleven;
	}
	else if(Month == dece || Month == Dec || Month == December || Month == december || Month == DEC || Month == DECEMBER){
		Month = twelve;
	}

	return;
}

void DateGetter::WeekConvertor(string &Week){
	if(Week == mon || Week == Mon || Week == MON || Week == monday || Week == Monday || Week == MONDAY){
		Week = Zero;
	}
	else if(Week == tue || Week == Tue || Week == TUE || Week == tuesday || Week == Tuesday || Week == TUESDAY){
		Week = one;
	}
	else if(Week == wed || Week == Wed || Week == WED || Week == wednesday || Week == Wednesday || Week == WEDNESDAY){
		Week = two;
	}
	else if(Week == thu || Week == Thu || Week == THU || Week == thursday || Week == Thursday || Week == THURSDAY){
		Week = three;
	}
	else if(Week == fri || Week == Fri || Week == FRI || Week == friday || Week == Friday || Week == FRIDAY){
		Week = four;
	}
	else if(Week == sat || Week == Sat || Week == SAT || Week == saturday || Week == Saturday || Week == SATURDAY){
		Week = five;
	}
	else if(Week == sun || Week == Sun || Week == SUN || Week == sunday || Week == Sunday || Week == SUNDAY){
		Week = six;
	}
	return;
}