#include "TextUI.h"

void TextUI::printWelcomeMessage() {
	cout << "Welcome to VeriTask!\n"
		 << "The following functions are supported: add, delete, edit, search, mark, undo.\n";
};

void TextUI::printAddConfirmation() {
	cout << "Task added!\n";
}

void TextUI::printDeleteConfirmation() {
	cout << "Task deleted!\n";
}

void TextUI::printEditConfirmation() {
	cout << "Task edited!\n";
}

void TextUI::printMarkConfirmation() {
	cout << "Task marked!\n";
}

void TextUI::printSearchConfirmationYes() {
	cout << "Tasks found!\n";
}

void TextUI::printSearchConfirmationNo() {
	cout << "Tasks not found!\n";
}



void TextUI::printTask(DataStorage &_dataStorage) {
	vector<Task> taskList = _dataStorage.retrieveTaskList();
	if (taskList.empty()) {
		cout << "There are no tasks!\n";
	} else {
	for (unsigned int i=0; i<taskList.size(); i++) {
		cout << i+1 << ". "
			 << taskList[i].getEvent() << " " 
			 << taskList[i].getDate() << " "
			 << taskList[i].getStartTime() << " "
			 << taskList[i].getEndTime() << " "
			 << taskList[i].getStatus() << " "
			 << endl;
	}
	}
}

void TextUI::printTaskToDisplay(DataStorage &_dataStorage) {
	vector<Task> taskListToDisplay = _dataStorage.retrieveTaskListToDisplay();
	if (taskListToDisplay.empty()) {
		cout << "No match!\n";
	} else {
	for (unsigned int i=0; i<taskListToDisplay.size(); i++) {
		cout << i+1 << ". "
			 << taskListToDisplay[i].getEvent() << " " 
			 << taskListToDisplay[i].getDate() << " "
			 << taskListToDisplay[i].getStartTime() << " "
			 << taskListToDisplay[i].getEndTime() << " "
			 << taskListToDisplay[i].getStatus() << " "
			 << endl;
	}
	}
}