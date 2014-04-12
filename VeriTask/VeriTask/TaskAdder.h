//@author A0101039X

/**
* This class is used to perform Add command from the user.
* It adds the task the user entered to the storage. It is the 
* child class of Operation class for command pattern. 
* Sample usage:
* TaskAdder taskAdder;
* taskAdder.executeCommand(infoIdentifier, dataStorage);
*/

#pragma once

#include <string>
#include "Operation.h"
#include "DataStorage.h"

using namespace std;

//const string UNDONE = "undone";

class TaskAdder:public Operation {
public:
	TaskAdder(void);

	//This method is used to perform addition of tasks into
	//our storage, dataStorage.
	//Pre-req: information passer (infoIndentifier) and dataStorage
	//Post-req: nil
	void executeCommand(Identifier, DataStorage&);	
};
