#include "Header.h"
using namespace std;

void Task::Mark(string status) {
	//see about declaring these strings in class VeriTask later
	string str1 = "done";
	string str2 = "undone";
	string str3 = "cannot be done"; //maybe accept "can't be done" or "cannot do" etc?

	//implement tolower() later

	//use switchcase later
	if (status.compare(str1) == 0) {
	}
	else
		if (status.compare(str2) == 0) {
		} 
		else
			if (status.compare(str3) == 0) {
			}
			else {
				cout << "Error in recognising input\n";
			}
}

int main() {

	VeriTask myVeriTask;

	return 0;
}