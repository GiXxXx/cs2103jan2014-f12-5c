//@author A0101039X

/**
* This class manages all the logic in our software. It takes in information 
* identifer, and based on different commands, it will perform relevant operation.
* Sample usage:
* VeriTask veriTask;
* VerTask.doCommand(infoIdentifier, dataStorage);
*/

#pragma once

#include <vector>
#include <string>
#include "Operation.h"
#include "TaskAdder.h"
#include "TaskDeleter.h"
#include "TaskEditer.h"
#include "TaskSearcher.h"
#include "TaskMarker.h"
#include "TaskDisplayer.h"

using namespace std;

class VeriTask {
private:
	vector<DataStorage> _undoList;
	vector<DataStorage> _redoList;
	int _commandCount; //keep track of many steps of undo can perform
	Operation* _newOperation;

	//this private method performs Undo
	//Pre-req: dataStorage
	//Post-req: nil
	void _undoCommand(DataStorage &dataStorage) {
		_redoList.push_back(dataStorage);
		dataStorage = _undoList.back();
		_undoList.pop_back();
		_commandCount--;
	}

	//this private method performs Redo
	//Pre-req: dataStorage
	//Post-req: nil
	void _redoCommand(DataStorage &dataStorage) {
		_undoList.push_back(dataStorage);
		dataStorage = _redoList.back();
		_redoList.pop_back();
		_commandCount++;
	}

	
public:
	VeriTask();
	~VeriTask();
    
	//this method performs operations according to the command
	//that user inputs
	//Pre-req: user command, information identifier, datastorage
	//Post-req: nil
	void doCommand(string, Identifier, DataStorage&); 
};