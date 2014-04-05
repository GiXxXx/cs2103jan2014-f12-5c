#include "PrimeGenerator.h"


PrimeGenerator::PrimeGenerator(){
}


PrimeGenerator::~PrimeGenerator(void){
}

void PrimeGenerator:: setString(string &userInput){
	_inputStr = userInput;
}

string PrimeGenerator:: getResultString(){
	string resultStr = _inputStr+" what the fuck";
	return resultStr;
}


