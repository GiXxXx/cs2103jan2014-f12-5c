//@author A0101039X

/**
* This class is used to perform Delete command from the user.
* It deletes the selected task the user chooses from the storage. 
* It is the child class of Operation class for command pattern. 
* Sample usage:
* TaskDeleter taskDeleter;
* taskDeleter.executeCommand(infoIdentifier, dataStorage);
*/

#pragma once

#include <vector>
#include "Operation.h"

using namespace std;

class TaskDeleter:public Operation {
public:
	TaskDeleter(void);

	//This method is used to perform deletion of tasks from
	//our storage, dataStorage.
	//Pre-req: information passer (infoIndentifier) and dataStorage
	//Post-req: nil
	void executeCommand(Identifier, DataStorage&);	
};
