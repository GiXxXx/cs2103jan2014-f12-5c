/* This is my thought about the Identifier class.
 * the private attribute contains every info we need, in the form of string.
 * 1. since i am lazy and the deadline is coming, is still used the chop-the -string method, since it is easy for me...
 *	  however, i only chop the uncategorizedInfo, the complete string is stored in _userInput and it is never to be modified.
 *	  i could add another function getUserInput to acces the original userInput at any time.
 *	  therefore, i donot think this will cause too much trouble.
 * 2.  in this design ,most of the public functions do not need to take in values to do the job. not sure whether it is a good practice.
 * 3. please ignore the main function, it is just for testing purpose.
 */

#ifndef HEADER_IDENTIFIER_
#define HEADER_IDENTIFIER_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

using namespace std;

class Identifier {

private:
	string _userInput;
	string uncategorizedInfo;

public:
	Identifier(string);
	string getCommand();
	void chopInfo(string &, int, int);
	string getDate();
	string getStartTime();
	string getEndTime();
	string getEvent();
	int getTaskNumber();	
	string getKeyword();
	bool floatingTask();
	bool timedTask();
	void getAddEditInfo();
	bool ifNumber(string);
	string getTime(string, string);
	string markStatus(string);
};

#endif