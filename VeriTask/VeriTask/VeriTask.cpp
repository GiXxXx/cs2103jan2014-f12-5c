#include "VeriTask.h"
#include <vector>

using namespace std;

//VeriTask() {

//}


void VeriTask::addTask(Task &taskToAdd(getEvent(), getDate, getStartTime, GetEndTime,) {
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

void deleteTask(vector<Task>, int) {
	haha

}

void editTask(int, string) {


}

vector<Task> showTask();

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


void undoCommand();
void markTask(int, int);

void VeriTask::Delete() {
	// this function is to delete an unwanted task

}

void VeriTask::Undo() {
	/* every time a function is made, an extra marker data attribute in myVeriTask should be updated to reflect that function.
	No change for SEARCH and SHOW. 

	implement a single-queue item counter in Identifier. if undo is being called a 2nd time, undo the undo and say so.
	disallow repeated undo & redo.

	make a copy of the object that is being called.

	if input is "undo", the object should be overwritten with the made copy. 
	
	show the undone change.*/
}

void VeriTask::Mark(string status) {
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

int main() {

//	VeriTask myVeriTask;

	return 0;
}