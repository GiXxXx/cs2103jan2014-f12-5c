#ifndef HEADER_SEARCHTASK_
#define HEADER_SEARCHTASK_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Command.h"

using namespace std;

class SearchTask:public Command {
public:
	void executeCommand(Identifier, DataStorage &, TextUI, File);	
};

#endif