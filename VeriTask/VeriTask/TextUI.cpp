#include "TextUI.h"

void TextUI::printWelcomeMessage() {
	cout << "Welcome to VeriTask!\n"
		 << "The following functions are supported: add, delete, edit, search, mark.\n";
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