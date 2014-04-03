#ifndef HEADER_DELETETASK_
#define HEADER_DELETETASK_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Command.h"

using namespace std;

class DeleteTask:public Command {
public:
	void executeCommand(Identifier, DataStorage &, TextUI, File);	
};

#endif