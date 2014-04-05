#include "TimeGetter.h"


TimeGetter::TimeGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


TimeGetter::~TimeGetter(){
}

string TimeGetter::Tokenize(){
	string time, tempTime;
	unsigned int indicator = zero;

	if(command == Add || command == Edit){
		time = getTime(*uncategorizedInfo, from);

		while(time == LargeTime && indicator < EightUnit){
			time = getTime(*uncategorizedInfo, preposition[indicator]);
		    indicator++;
		}
	}

	return time;
}

string TimeGetter::getTime(string test, string keyword){
	string Time = LargeTime, tempTime, checker;
	unsigned int position, startPos = start, sizeOne, sizeTwo;
	int hourStandard = zero;

		do{
			position = test.find(keyword, startPos);

			if(position != string::npos){
				cout << "hehe1 = " <<  test<<endl;
				cout << "hehe2 = " <<keyword<< "asdsd= " << position <<endl;
				cout << "hehe3 = " << keyword<<endl;
				tempTime = test.substr(position + keyword.size() + OneUnit);
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

				if(tempTime.size() >= FourUnit){
       				if((tempTime.substr(OneUnit,OneUnit)) == colon || tempTime.substr(OneUnit,OneUnit) == dot){
        				tempTime = tempTime.substr(start, OneUnit) + tempTime.substr(start + TwoUnit, TwoUnit);
	        		}

   	    			if((tempTime.substr(TwoUnit,OneUnit)) == colon || tempTime.substr(TwoUnit,OneUnit) == dot){
	       				tempTime = tempTime.substr(start, TwoUnit) + tempTime.substr(start + ThreeUnit, TwoUnit);
	        		}
				}

			    if(isNumber(tempTime)){
					if(tempTime.size() <= TwoUnit){
						tempTime = tempTime + Zero + Zero;
					}

					Time = tempTime;

					if(hourStandard == zero){
							chopInfo((*uncategorizedInfo), position, sizeOne + keyword.size() + OneUnit);
					}

					if(hourStandard == OneUnit){
						if(Time.size() < FourUnit){
							Time = Zero + Time;
						}
						chopInfo((*uncategorizedInfo), position, sizeTwo + keyword.size() + OneUnit);
					}

					if(hourStandard == TwoUnit){
						int TimeNumber = std::stoi(tempTime);
						TimeNumber = hourAdder + TimeNumber;
						stringstream in;
						in << TimeNumber;
						Time = in.str();
						chopInfo((*uncategorizedInfo), position, sizeTwo + keyword.size() + OneUnit);
					}

				    break;
				}
			}
			
			startPos = position + OneUnit;

		 }while(position != string::npos);

	return Time;
}

void Tokenizer::ChangeDoubleDigit(string &Number){
	if(isNumber(Number)){
		if(std::stoi(Number) < 10 && Number.size() == OneUnit){
			Number = Zero + Number;
		}
	}

	return;
}