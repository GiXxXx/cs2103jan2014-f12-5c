#include "VeriTask.h"
#include "Identifier.h"
#include "TextUI.h"
#include "File.h"
#include <iostream>
#include <queue>

const string EXIT = "exit";

using namespace std;

int main() {
	File* file;
	file = new File;
	VeriTask TaskManager(*file);
	string UserInput;
	Identifier InfoIdentifier;
	TextUI textUI;

	textUI.printWelcomeMessage();

	do {
		getline(cin, UserInput);
		InfoIdentifier.Identify(UserInput);
		TaskManager.pushCommand(InfoIdentifier.GetCommand(), InfoIdentifier, textUI, *file);
	} while (InfoIdentifier.GetCommand() != EXIT);
	
	return 0;
}