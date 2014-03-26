#ifndef HEADER_TEXTUI_
#define HEADER_TEXTUI_
#include <iostream>
#include <vector>
#include <string>
#include "DataStorage.h"
using namespace std;

class TextUI {
private:

public:
	void printWelcomeMessage();
	void printAddConfirmation();
	void printDeleteConfirmation();
	void printEditConfirmation();
	void printMarkConfirmation();
	void printSearchResult();
	void printTask(DataStorage &);
};

#endif