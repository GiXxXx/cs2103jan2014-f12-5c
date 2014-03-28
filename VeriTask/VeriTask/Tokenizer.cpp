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
	string Time = LargeTime, tempTime;
	unsigned int TimeSize = 5, MinSize =2;
	unsigned int position, startPos = start, size = keyword.size() + TimeSize + OneUnit;

	if((*uncategorizedInfo).size() > size)
		do{
			position = test.find(keyword, startPos);

			if(position != string::npos){
				unsigned int maxSize = test.substr(position + keyword.size() +OneUnit).size();

				if(TimeSize <= maxSize){
					tempTime = test.substr(position + keyword.size() + OneUnit, TimeSize);

				if((tempTime.substr(MinSize,OneUnit)) == colon){
					tempTime = tempTime.substr(start, MinSize) + tempTime.substr(start + MinSize + OneUnit, MinSize);

				    if(isNumber(tempTime)){
						Time = tempTime;
						chopInfo((*uncategorizedInfo), position, size);
					    break;
					}
				}
			}
			}

			startPos = position + OneUnit;

		 }while(position != string::npos);

	return Time;
}

void Tokenizer::ChangeDoubleDigit(string &Number){
	if(isNumber(Number)){
		if(std::stoi(Number) < 10){
			Number = Zero + Number;
		}
	}

	return;
}


string Tokenizer::Tokenize(){
	return *uncategorizedInfo;
}