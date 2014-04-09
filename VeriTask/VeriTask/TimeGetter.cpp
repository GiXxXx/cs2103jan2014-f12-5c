#include "TimeGetter.h"


TimeGetter::TimeGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


TimeGetter::~TimeGetter(){
}

string TimeGetter::Tokenize(){
	string time = LargeTime, tempTime;
	unsigned int indicator = zero;

	if(command == Add || command == Edit){
		unsigned int posOne = (*uncategorizedInfo).find_first_not_of(space);
		unsigned int posTwo = (*uncategorizedInfo).find_first_of(space, posOne);

		if(posOne != string::npos){
	    	string checker = (*uncategorizedInfo).substr(posOne, posTwo - posOne);

    		if(isNumber(checker) && checker.size() == FourUnit){
	    		time = checker;
		    	chopInfo(*uncategorizedInfo, posOne, checker.size());
	    	}
		}

		while(time == LargeTime && indicator < NineUnit){
			time = getTime(*uncategorizedInfo, preposition[indicator]);

		    indicator++;
		}
	}

	return time;
}

string TimeGetter::getTime(string Input, string keyword){
	string Time = LargeTime, tempTime, checker, duplicate = Input;
	unsigned int position, startPos = start, sizeOne, sizeTwo;
	int hourStandard = zero;

	ChangeToLowerCase(duplicate);

	do{
		position = duplicate.find(keyword, startPos);

		if(position != string::npos){
			tempTime = duplicate.substr(position + keyword.size());
			sizeOne = tempTime.find_first_of(space);
			sizeTwo = tempTime.find_first_of(space, sizeOne + OneUnit); 
					
			checker = tempTime.substr(sizeOne + OneUnit, sizeTwo - sizeOne - OneUnit);

			if(checker == pmOne || checker == pmTwo || checker == pmThree){
				hourStandard = TwoUnit;
			}

			if(checker == amOne || checker == amTwo || checker == amThree){
				hourStandard = OneUnit;
			}

			tempTime = tempTime.substr(start, sizeOne);

			string apm[SixUnit] = {amOne, amTwo, amThree, pmOne, pmTwo, pmThree};
	    	unsigned int indicator = zero;

			while(!isNumber(tempTime) && indicator < SixUnit){
    			unsigned int newPosition = tempTime.find(apm[indicator]);

	   			if(newPosition != string::npos){
					string temp = tempTime.substr(start, newPosition);
				
					if(isNumber(temp)){
						tempTime = temp;
						if(indicator < ThreeUnit){
			    			hourStandard = OneUnit;
		    			}
		    			else{
		    				hourStandard = TwoUnit;
			    			}

							sizeTwo = sizeOne;
							break;
						}
					}

					indicator++;
				}

				if(hourStandard == zero){
					sizeTwo = sizeOne;
				}

				tempTime = convertToTime(tempTime);

				if(isNumber(tempTime)){
					Time = tempTime;

					if(hourStandard == OneUnit || hourStandard == zero){
	   	    			chopInfo((*uncategorizedInfo), position, sizeTwo + keyword.size());
	    				break;
	   	    		}

	   	    		if(hourStandard == TwoUnit){
		        		int TimeNumber = std::stoi(tempTime);
	    	   			TimeNumber = hourAdder + TimeNumber;
		      			stringstream in;
	    	   			in << TimeNumber;
	    	   			Time = in.str();
	    	   			chopInfo((*uncategorizedInfo), position, sizeTwo + keyword.size());
	    				break;
	    	   		}
	    	  	}
	    	}

	    	startPos = position + OneUnit;
		
		}while(position != string::npos);	

	return Time;
}

string TimeGetter::convertToTime(string tempTime){
	int position = tempTime.find(colon);
	string hour, minute;
	
	if (position == string::npos) {
		position = tempTime.find(dot);
	}

	if(position != string::npos) {
		hour = tempTime.substr(start, position - start);
		minute = tempTime.substr(position + OneUnit);
	}
				
   if(isNumber(hour) && isNumber(minute)){
	   if(hour.size() == OneUnit){
		   hour = Zero + hour ;
    	}
	   
	   if (minute.size() == OneUnit){
		   minute = minute + Zero;
	   }

	   tempTime = hour + minute;
   }

   return tempTime;
}

