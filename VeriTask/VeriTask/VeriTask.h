#ifndef HEADER_VERITASK_
#define HEADER_VERITASK_
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Command.h"
#include "AddTask.h"
#include "DeleteTask.h"
#include "EditTask.h"
#include "SearchTask.h"
#include "MarkTask.h"
#include "TextUI.h"

using namespace std;

class VeriTask {
private:
	vector<Command*> commandList;
	vector<DataStorage> undoList;
	DataStorage _dataStorage;
	TextUI textUI;
public:
	VeriTask();
	~VeriTask();
	void pushCommand(string, Identifier); 
	
};
#endif