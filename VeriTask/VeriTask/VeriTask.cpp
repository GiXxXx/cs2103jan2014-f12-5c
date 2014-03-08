#include "VeriTask.h"
#include <vector>

using namespace std;

//VeriTask() { 

  //set taskListToDisplay and copy everything from file to taskList[]

//}


void VeriTask::addTask(Task &taskToAdd(getEvent(), getDate, getStartTime, GetEndTime,) { // requires Identifier
	if (_taskList.empty()) {
		_taskList.push_back(taskToAdd);
	} else {
		for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) {
			if (i->getSequenceNum() > taskToAdd.getSequenceNum())
			{
				_taskList.insert(taskToAdd, i);
				break;
			}
		}
	}
}

void VeriTask::deleteTask(int taskNumToDelete) {      // modify the code after integration
	double sequenceNumToDelete = _taskListToDisplay[taskNumToDelete-1].getSequenceNum;

	for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) { //replace it with of function called searchTaskID
		if ((*i).getSequenceNum = sequenceNumToDelete) {
			_taskList.erase(i);
			break;
		}
	}
}

void VeriTask::editTask(string taskInfo, int taskNumToEdit) {
	double sequenceNumToEdit = _taskListToDisplay[taskNumToEdit-1].getSequenceNum();

	for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) {
		if ((*i).getSequenceNum = sequenceNumToEdit) {
			// set task with taskInfo depending on Identifier

		}
	}
}

// vector<Task> showTask();

vector<Task> VeriTask::searchTask(string keyword) {
	vector<Task> taskListFound;	

	for (vector<Task>::iterator i=_taskList.begin(); i<_taskList.end(); i++) {
		string tempEvent = (*i).getEvent();
		string tempDate = (*i).getDate();
		string tempStartTime = (*i).getStartTime();
		string tempEndTime = (*i).getEndTime();
		if ((tempEvent.find(keyword)!=string::npos)||
			(tempDate.find(keyword)!=string::npos) ||
			(tempStartTime.find(keyword)!=string::npos) ||
			(tempEndTime.find(keyword)!=string::npos)) {
			taskListFound.push_back((*i));
		}
	}
	return taskListFound;
}


void VeriTask::markTask(string status, int taskNumToMark) {
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
}

void undoCommand();

void VeriTask::Undo() {
	/* every time a function is made, an extra marker data attribute in myVeriTask should be updated to reflect that function.
	No change for SEARCH and SHOW. 

	implement a single-queue item counter in Identifier. if undo is being called a 2nd time, undo the undo and say so.
	disallow repeated undo & redo.

	make a copy of the object that is being called.

	if input is "undo", the object should be overwritten with the made copy. 
	
	show the undone change.*/
}


int main() {

//	VeriTask myVeriTask;

	return 0;
}