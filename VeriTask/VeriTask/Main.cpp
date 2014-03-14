#include "VeriTask.h"
#include "Identifier.h"
#include <iostream>

const string EXIT = "exit";

using namespace std;

int main() {
	VeriTask TaskManager;
	string UserInput;
	Identifier temp(UserInput);

	do {
		getline(cin, UserInput);
		Identifier InfoIdentifier(UserInput);
		temp = InfoIdentifier;
		TaskManager.executeCommand(InfoIdentifier.getCommand(), InfoIdentifier);
	} while (temp.getCommand() != EXIT);
	

	return 0;
}