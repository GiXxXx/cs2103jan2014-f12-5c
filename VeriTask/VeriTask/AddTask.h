#ifndef HEADER_ADDTASK_
#define HEADER_ADDTASK_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "DataStorage.h"
#include "Command.h"

using namespace std;

class AddTask:public Command {
public:
	void executeCommand(Identifier, DataStorage &, TextUI);	
};

#endif