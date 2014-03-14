#include "VeriTask.h"
#include <vector>

using namespace std;

VeriTask::VeriTask() { 

  //set taskListToDisplay and copy everything from file to taskList[]

}

CommandType VeriTask::determineCommand(string Command) {
	if (Command == ADD_COMMAND) {
		return ADD;
	}
	if (Command == DELETE_COMMAND) {
		return DELETE;
	}
	if (Command == EDIT_COMMAND) {
		return EDIT;
	}
	if (Command == SEARCH_COMMAND) {
		return SEARCH;
	}
	if (Command == MARK_COMMAND) {
		return MARK;
	}
	return INVALID;
}

void VeriTask::doCommand(CommandType Command, Identifier infoIdentifier) {
	switch (Command) {
	case ADD: {
		string Event, Date, StartTime, EndTime;
		Date = infoIdentifier.getDate();
		StartTime = infoIdentifier.getStartTime();
		EndTime = infoIdentifier.getEndTime();
		Event = infoIdentifier.getEvent();
		Task taskToAdd(Event, Date, StartTime, EndTime);
		VeriTask::addTask(taskToAdd);
			  }
			  break;
	case DELETE: {
		int TaskNumToDelete=(infoIdentifier.getTaskNumber());
		VeriTask::deleteTask(TaskNumToDelete);
				 }
				 break;
	case EDIT: {
		int TaskNumToEdit=infoIdentifier.getTaskNumber();
		VeriTask::deleteTask(TaskNumToEdit);
		string Event, Date, StartTime, EndTime;
		Date = infoIdentifier.getDate();
		StartTime = infoIdentifier.getStartTime();
		EndTime = infoIdentifier.getEndTime();
		Event = infoIdentifier.getEvent();
		Task taskToAdd(Event, Date, StartTime, EndTime);
		VeriTask::addTask(taskToAdd);
	//	VeriTask::editTask(TaskInfo, taskNumToEdit);
			   }   
			   break; 
	case SEARCH: {
		string Keyword=infoIdentifier.getKeyword();
		VeriTask::searchTask(Keyword);
				 }
				 break;
/*	case MARK: {
		string Status;
		int TaskNumToMark;
		VeriTask::markTask(Status, TaskNumToMark);
			   }
			   break; */
	case INVALID: {
		cout << ERROR_MESSAGE << endl;
				  }
				  break;
	default: return;
	};
}

void VeriTask::executeCommand(string Command, Identifier infoIdentifier) {
	CommandType UserCommand = VeriTask::determineCommand(Command);
	VeriTask::doCommand(UserCommand, infoIdentifier);
}

void VeriTask::addTask(Task taskToAdd) {
	bool isAdded=false;
	for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) {
		if ((*i).getSequenceNum() > taskToAdd.getSequenceNum()) {
				_taskList.insert(i, taskToAdd);
				isAdded=true;
				break;
			}
		}
	if (!isAdded) {
		_taskList.push_back(taskToAdd);
	}
	printTask();
}

void VeriTask::deleteTask(int taskNumToDelete) {  
	// modify the code after integration
	double sequenceNumToDelete = _taskListToDisplay[taskNumToDelete-1].getSequenceNum();
	
	for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) { //replace it with of function called searchTaskID
		if ((*i).getSequenceNum() == sequenceNumToDelete) {
			_taskList.erase(i);
			break;
		}
	}
	printTask();
}

/*void VeriTask::editTask(string taskInfo, int taskNumToEdit) {
	VeriTask::deleteTask(taskNumToEdit);
	
	VeriTask::addTask(
	double sequenceNumToEdit = _taskListToDisplay[taskNumToEdit-1].getSequenceNum();

	for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) {
		if ((*i).getSequenceNum = sequenceNumToEdit) {
			// set task with taskInfo depending on Identifier

		}
	}
} */

// vector<Task> showTask();

void VeriTask::searchTask(string keyword) {
	_taskListToDisplay.clear();	

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

/*void VeriTask::markTask(string status, int taskNumToMark) {
	//see about declaring these strings in class VeriTask later
	string str1 = "done";
	string str2 = "undone";
	string str3 = "cannot be done"; //maybe accept "can't be done" or "cannot do" etc?

	//implement status.tolower() later for keyboard flexibility

	//use switchcase later
	if (status.compare(str1) == 0) {
		//getStatus(); mark to 0. getSequenceNum();
		//implement ENUM later?
	}
	else
		if (status.compare(str2) == 0) {
		} 
		else
			if (status.compare(str3) == 0) {
			}
			else {
				cout << "Error in recognising input\n";
			}
} */

//void VeriTask::undoCommand() {
	/* every time a function is made, an extra marker data attribute in myVeriTask should be updated to reflect that function.
	No change for SEARCH and SHOW. 

	implement a single-queue item counter in Identifier. if undo is being called a 2nd time, undo the undo and say so.
	disallow repeated undo & redo.

	make a copy of the object that is being called.

	if input is "undo", the object should be overwritten with the made copy. 
	
	show the undone change.*/
//}

void VeriTask::printTask() {
	if (_taskList.empty()) {
		cout << "There are no tasks!\n";
	} else {
	for (unsigned int i=0; i<_taskList.size(); i++) {
		cout << i+1 << ". "
			 << _taskList[i].getEvent() << " " 
			 << _taskList[i].getDate() << " "
			 << _taskList[i].getStartTime() << " "
			 << _taskList[i].getEndTime() << " "
			 // add print status;
			 << endl;
	}
	}
}
