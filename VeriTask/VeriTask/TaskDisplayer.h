#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "DataStorage.h"
#include "Command.h"

using namespace std;

class TaskDisplayer: public Command {
public:
	TaskDisplayer(void);
	~TaskDisplayer(void);
	void executeCommand(Identifier, DataStorage &, TextUI);	
};

