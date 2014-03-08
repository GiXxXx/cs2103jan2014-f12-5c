#ifndef HEADER_IDENTIFIER_
#define HEADER_IDENTIFIER_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Task.h"

using namespace std;

class Identifier {

private:
	string _Operation;
	int _Deadline;
	double _StartTime;
	double _EndTime;
	string _Details;
	int _Status;

public:
	Identifier();

};

#endif