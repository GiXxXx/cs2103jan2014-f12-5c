#include "VeriTask.h"
#include "Identifier.h"
#include <iostream>
#include <queue>

const string EXIT = "exit";

using namespace std;

int main() {
	VeriTask TaskManager;
	string UserInput;
	Identifier temp;
	TextUI welcomeMessage;

	welcomeMessage.printWelcomeMessage();

	do {
		getline(cin, UserInput);
		Identifier InfoIdentifier;
		InfoIdentifier.Identify(UserInput);
		temp = InfoIdentifier;
		TaskManager.pushCommand(InfoIdentifier.GetCommand(), InfoIdentifier);
	} while (temp.GetCommand() != EXIT);
	
	return 0;
}