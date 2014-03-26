#ifndef HEADER_TEXTUI_
#define HEADER_TEXTUI_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TextUI {
private:

public:
	TextUI();
	void printWelcomeMessage();
	void printAddConfirmation();
	void printDeleteConfirmation();
	void printEditConfirmation();
	void printMarkConfirmation();
	void printSearchResult();
};

#endif