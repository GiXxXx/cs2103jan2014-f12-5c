#include "Command.h"

void Command::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI) {
}


/*
class AddTask: public VeriTask{
public:
	void executeCommand(Identifier infoIdentifier) {
		bool isAdded = false;
		string date = infoIdentifier.getDate();
		string startTime = infoIdentifier.getStartTime();
		string endTime = infoIdentifier.getEndTime();
		string event = infoIdentifier.getEvent();
		Task taskToAdd(event, date, startTime, endTime);

		for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) {
		if ((*i).getID() > taskToAdd.getID()) {
				_taskList.insert(i, taskToAdd);
				isAdded=true;
				break;
			}
		}

		if (!isAdded) {
		_taskList.push_back(taskToAdd);
		}
	}
}; 

class DeleteTask: public VeriTask{
public:
	void executeCommand(Identifier infoIdentifier) {
		int taskNum=infoIdentifier.getTaskNumber();
		double taskIDToDelete = _taskListToDisplay[taskIDToDelete-1].getID();
	
		for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) { 
			if ((*i).getID() == taskIDToDelete) {
			_taskList.erase(i);
			break;
		    }
	    }
	}
};

class EditTask: public VeriTask {
public:
	void executeCommand(Identifier infoIdentifier) {
		int TaskNum=infoIdentifier.getTaskNumber();
		double taskIDToDelete = _taskListToDisplay[taskIDToDelete-1].getID();
		
		for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) { 
			if ((*i).getID() == taskIDToDelete) {
			_taskList.erase(i);
			break;
		    }
	    }
		
		bool isAdded = false;
		string date = infoIdentifier.getDate();
		string startTime = infoIdentifier.getStartTime();
		string endTime = infoIdentifier.getEndTime();
		string event = infoIdentifier.getEvent();
		Task taskToAdd(event, date, startTime, endTime);

		for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) {
		if ((*i).getID() > taskToAdd.getID()) {
				_taskList.insert(i, taskToAdd);
				isAdded=true;
				break;
			}
		}
		if (!isAdded) {
		_taskList.push_back(taskToAdd);
		}
	}
};


class SearchTask: public VeriTask {
public:
    void executeCommand(Identifier infoIdentifier) {
		string keyword=infoIdentifier.getKeyword();

		for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) {
			string tempDate = (*i).getDate();
		    string tempStartTime = (*i).getStartTime();
		    string tempEndTime = (*i).getEndTime();
		    string tempEvent = (*i).getEvent();
			if ((tempEvent.find(keyword)!=string::npos)||
			(tempDate.find(keyword)!=string::npos) ||
			(tempStartTime.find(keyword)!=string::npos) ||
			(tempEndTime.find(keyword)!=string::npos)) {
			    _taskListToDisplay.push_back((*i));
		    }
		}

		if (_taskListToDisplay.empty()) {
		cout << "There are no tasks!\n";
		} else {
			for (unsigned int i=0; i<_taskListToDisplay.size(); i++) {
		     cout << i+1 << ". "
			 << _taskListToDisplay[i].getEvent() << " " 
			 << _taskListToDisplay[i].getDate() << " "
			 << _taskListToDisplay[i].getStartTime() << " "
			 << _taskListToDisplay[i].getEndTime() << " "
			 // add print status;
			 << endl;
			}
	      }
	}
};

class MarkTask: public VeriTask {
public:
	void executeCommand(Identifier infoIdentifier) {
		string status=infoIdentifier.getStatus();
	    int taskNum=infoIdentifier.getTaskNumber();
	    double TaskIDToMark = _taskListToDisplay[taskNum-1].getID();

		for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) {
			if ((*i).getID() == TaskIDToMark) {
			    i->setStatus(status);
			    break;
			}
		}
	}
};



//void VeriTask::undoCommand() {
	/* every time a function is made, an extra marker data attribute in myVeriTask should be updated to reflect that function.
	No change for SEARCH and SHOW. 

	implement a single-queue item counter in Identifier. if undo is being called a 2nd time, undo the undo and say so.
	disallow repeated undo & redo.

	make a copy of the object that is being called.

	if input is "undo", the object should be overwritten with the made copy. 
	
	show the undone change.*/
//

/*class Operation {
private:
	VeriTask* operation;
public:
	void pushCommand(string Command, Identifier infoIdentifier) {
	if (Command == ADD_COMMAND) {
		operation = new AddTask;
		operation->executeCommand(infoIdentifier);
	}
	if (Command == DELETE_COMMAND) {
		operation = new DeleteTask;
		operation->executeCommand(infoIdentifier);
	}
	if (Command == EDIT_COMMAND) {
		operation = new EditTask;
		operation->executeCommand(infoIdentifier);
	}
	if (Command == SEARCH_COMMAND) {
		operation = new SearchTask;
		operation->executeCommand(infoIdentifier);
	}
	if (Command == MARK_COMMAND) {
		operation = new MarkTask;
		operation->executeCommand(infoIdentifier);
	}
}
};*/



