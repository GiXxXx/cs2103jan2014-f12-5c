#include "VeriTask.h"
#include "Identifier.h"
#include "TextUI.h"
#include <iostream>
#include <queue>

const string EXIT = "exit";

using namespace std;

int main() {
	VeriTask TaskManager;
	string UserInput;
	Identifier temp;
	TextUI textUI;

	textUI.printWelcomeMessage();

	do {
		getline(cin, UserInput);
		Identifier InfoIdentifier;
		InfoIdentifier.Identify(UserInput);
		temp = InfoIdentifier;
		TaskManager.pushCommand(InfoIdentifier.GetCommand(), InfoIdentifier, textUI);
	} while (temp.GetCommand() != EXIT);
	
	return 0;
}