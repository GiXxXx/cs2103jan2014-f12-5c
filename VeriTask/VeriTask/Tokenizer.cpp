#include "Tokenizer.h"

Tokenizer::Tokenizer(string &userInput){ 
	string temp = userInput;
	uncategorizedInfo = &userInput;
	*uncategorizedInfo = temp + Spaces;
}

Tokenizer::~Tokenizer(){
}

void Tokenizer::chopInfo(string &oldInfo, int position, int size){
	unsigned int EndPos = position + size;

	if(EndPos < oldInfo.size()){
		oldInfo = oldInfo.substr(start, position) + oldInfo.substr(position + OneUnit + size);
	}

	else{
		oldInfo = oldInfo.substr(start, position);
	}
	return;
}

bool Tokenizer::isNumber(string test){
	unsigned int matchCount = 0;
	bool result = false;
	
	for(unsigned int i = 0; i < test.size(); i++){
		for(unsigned int j = 0; j < 10; j++){
			if(test[i] == number[j]){
				matchCount++;
			}
		}
	}
	
	if(matchCount == test.size() && matchCount != zero){
		result = true;
	}

	return result;
}

string Tokenizer::getTime(string test, string keyword){
	string Time = LargeTime, tempTime, checker;
	unsigned int position, startPos = start, sizeOne, sizeTwo;
	int hourStandard = zero;

		do{
			position = test.find(keyword, startPos);

			if(position != string::npos){
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


string Tokenizer::Tokenize(){
	return *uncategorizedInfo;
}