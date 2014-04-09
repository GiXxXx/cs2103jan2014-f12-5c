#include "StatusGetter.h"


StatusGetter::StatusGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


StatusGetter::~StatusGetter(){
}

string StatusGetter::Tokenize(){
	string status = NoStatus, temp = status;
	int wordCount = zero, indicator = zero, sizeOne = TenUnit + FiveUnit, sizeTwo = TwoUnit * sizeOne - OneUnit, sizeThree = TenUnit + OneUnit;
	unsigned int positionOne = zero;
	unsigned int positionTwo = zero;
	unsigned int startPos = zero;

	while(positionOne != string::npos && startPos != string::npos){
		positionOne = (*uncategorizedInfo).find_first_not_of(space, startPos);

		if(positionOne != string::npos){
	    	positionTwo = (*uncategorizedInfo).find_first_of(space, positionOne);
		}

		if(positionTwo != string::npos && positionOne != string::npos){
			wordCount++;
			temp = (*uncategorizedInfo).substr(positionOne, positionTwo);
		}

		startPos = positionTwo;
	}

	if(wordCount == zero){
		status = emptyString;
	}

	if(wordCount > OneUnit){
		for(int i = zero; i < sizeOne; i++){
			if(temp.find(MultiWordStatus[i]) != string::npos){
				if(i <= TenUnit + OneUnit){
					status = Done;
				}
				else if(i <= TenUnit + NineUnit){
					status = UnDone;
				}
				else if(i < sizeOne){
					status = CannotBeDone;
				}
			}
		}
	}

	if(wordCount == OneUnit || (status != Done && status != UnDone && status != CannotBeDone)){
		for(int i = zero; i < sizeTwo; i++){
			if(temp.find(OneWordStatus[i]) != string::npos){
				if(i < SixUnit){
					status = UnDone;
				}
				else if(i < TenUnit){
					status = Done;
				}
				else if(i < sizeTwo){
					status = CannotBeDone;
				}
			}
		}
	}

	if(command == Display && (status != overdue || status != all)){
		for(int i = zero; i < sizeThree; i++){
			if(temp.find(overdueStatus[i]) != string::npos){
				if(i <= SevenUnit){
		    		status = overdue;
				}
				else if(i < sizeThree){
					status = all;
				}
			}
		}
	}
	
	if(command == Mark || command == Display){
		if(status == Done || status == UnDone || status == CannotBeDone || status == overdue || status == all) {
			status = status;
		}
	}
	else{
		status = emptyString;
	}

   	return status;
}

