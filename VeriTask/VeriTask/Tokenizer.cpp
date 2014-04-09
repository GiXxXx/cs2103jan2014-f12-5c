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
		oldInfo = oldInfo.substr(start, position) + oldInfo.substr(position + size);
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

void Tokenizer::ChangeToLowerCase(string &input){
	for(unsigned int i = 0; i < input.size(); i++){
		if(input[i] >= A && input[i] <= Z){
			input[i] = input[i] - (A - a); 
		}
	}

	return;
}

string Tokenizer::changeWordToNumber(string input){
	int first = zero, second = zero;
	unsigned int position = input.find_first_of(space);
	string elementOne, elementTwo;

	if(position == string::npos){
		elementOne = input;
		elementTwo = space;
	}
	else{
		elementOne = input.substr(start, position);
		elementTwo = input.substr(position + OneUnit);
	}

	if(elementTwo == space){
		for(int i = zero; i < TenUnit; i++){
			if(elementOne == ones[i]){
				first = i;

				if(first == zero){
					first = TenUnit * TenUnit;
				}

				break;
			}
		}
	}
	else{
		for(int i = zero; i < TenUnit + TenUnit; i++){
			if(elementOne == tens[i]){
				first = i * TenUnit;
				break;
			}
		}

		for(int i = zero; i < TenUnit; i++){
    		if(elementTwo == ones[i]){
    			second = i;
				break;
			}
		}
	}

	if(elementOne == astring && elementTwo == space){
		first = OneUnit;
	}

	int result = first + second;

	ostringstream out;

	out << result;

	return out.str();
}

string Tokenizer::Tokenize(){
	return *uncategorizedInfo;
}