#ifndef HEADER_MARKTASK_
#define HEADER_MARKTASK_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Command.h"

using namespace std;

class MarkTask:public Command {
public:
	void executeCommand(Identifier, DataStorage &);	
};

#endif