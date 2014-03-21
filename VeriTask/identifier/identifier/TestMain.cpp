#include <iostream>
#include "Identifier.h"
#include <string>

using namespace std;

int main(){
	cout << "please input content" << endl;
	for(int i = 0; i <5;i++){
		Identifier myTest;
		cout << "the information are as follows" << endl;
		cout << "command: " << myTest.getCommand()<<endl;
		cout << "tasknum: " << myTest.getTaskNumber() << endl;
		cout << "date   : " << myTest.getDate()<<endl;
		cout << "start  : " << myTest.getStartTime()<<endl;
		cout << "end    : " << myTest.getEndTime() << endl;
		cout << "event  : " << myTest.getEvent() << endl;
		cout << "keyword: " << myTest.getKeyword() << endl;
	}
	return 0;
}