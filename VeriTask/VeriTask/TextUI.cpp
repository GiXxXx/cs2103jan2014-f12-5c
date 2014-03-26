#include "TextUI.h"

TextUI::TextUI() {

}

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