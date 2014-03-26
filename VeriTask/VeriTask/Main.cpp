#include "VeriTask.h"
#include "Identifier.h"
#include <iostream>
#include <queue>

const string EXIT = "exit";

using namespace std;

int main() {
	VeriTask TaskManager;
	string UserInput;
	Identifier temp(UserInput);
	TextUI welcomeMessage;

	welcomeMessage.printWelcomeMessage();

	do {
		getline(cin, UserInput);
		Identifier InfoIdentifier(UserInput);
		temp = InfoIdentifier;
		TaskManager.pushCommand(InfoIdentifier.getCommand(), InfoIdentifier);
	} while (temp.getCommand() != EXIT);
	
	return 0;
}