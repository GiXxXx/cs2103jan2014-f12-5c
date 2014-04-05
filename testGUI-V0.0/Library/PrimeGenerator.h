#pragma once

#include<vector>
#include<algorithm>
#include<exception>
#include<string>

using namespace std;

class PrimeGenerator{
private: 
	string _inputStr;

public:
	PrimeGenerator(void);

	~PrimeGenerator(void);
	void setString(string &userInput);
	string getResultString();
};
