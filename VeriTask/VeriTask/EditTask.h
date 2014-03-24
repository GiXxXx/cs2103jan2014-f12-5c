#ifndef HEADER_EDITTASK_
#define HEADER_EDITTASK_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Command.h"

using namespace std;

class EditTask:public Command {
public:
	void executeCommand(Identifier, DataStorage &);	
};

#endif