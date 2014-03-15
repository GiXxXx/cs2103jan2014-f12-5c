#include "Identifier.h"
#include <string>

using namespace std;

const string number = "0123456789";
const string slash = "/";
const string colon = ":";
/*because only the relavent attribute will be filled, denpending on the command given,
 *some attributes are given a initial value. this is to make it easy for display.
 *for example, when display all the tasks on the screen, it will be like the following:
 *          number        date          start        end        event         status
 *             1      2014/03/10        13:10       14:10       sleep           0
 *             2      2014/03/11                                study           0
 *             3                                                submit V0.1     0
 *
 * @jiacheng,during the meeting we discussed about how to display the existing tasks when opening the programme,
 * i think maybe it is better not to use the Identifier to go through all saved information because it is time consuming
 * and it also requires another constructor for the Identifier class, one for userInput, one for getline from the txt file.
 * therefore, i thougt it might be better to design like this, where information are saved in a standard format(shown above),
 * in this case, you could just copy one whole line of the txt file and display it.
 */
Identifier::Identifier(string userInput){
	_userInput = userInput; 
	int position = _userInput.find_first_of(" ") + 1; 
	uncategorizedInfo = _userInput.substr(position);
}

/* sorry, still used the chopInfo method in this version. It's quite hard to handle the iterator method,
 * i will make necessary changes after this deadline
 */
void Identifier::chopInfo(string &oldInfo, int position, int size){
	unsigned int EndPos = position + 1 + size;

	if(EndPos < oldInfo.size()){
		oldInfo = oldInfo.substr(0, position) + oldInfo.substr(position + 1 + size);
	}

	else{
		oldInfo = oldInfo.substr(0, position);
	}
	return;
}

string Identifier::getCommand(){
	string Command = _userInput.substr(0,_userInput.find_first_of(' '));
	return Command;
}

string Identifier::getDate(){
	string Date = "30000000", tempDate, keywordOne = "onby";
	unsigned int position, startPos = 0, size = 13, indicator = 0;

	while(Date == "30000000" && indicator < 3){

	if((getCommand() == "add" || getCommand() =="edit") && size < uncategorizedInfo.size()){
		do{
			position = uncategorizedInfo.find(keywordOne.substr(indicator, 2), startPos);

			if(position != string::npos){
				tempDate = uncategorizedInfo.substr(position + 3, 10);

				if((tempDate.substr(2,1)) == slash && (tempDate.substr(5,1)) == slash){
					tempDate = tempDate.substr(6,4) + tempDate.substr(3,2) + tempDate.substr(0,2);

				    if(ifNumber(tempDate)){
						Date = tempDate;
						chopInfo(uncategorizedInfo, position, size);
					    break;
					}
				}
			}

			startPos = position + 1;

		 }while(position != string::npos);
	}

	indicator += 2;
	}

	return Date;
}

string Identifier::getStartTime(){
	string StartTime, tempTime, keyword = "from";

	if(getCommand() == "add" || getCommand() =="edit"){
		StartTime = getTime(uncategorizedInfo, keyword);
	}

	return StartTime;
}

string Identifier::getEndTime(){
	string EndTime, keywordOne = "at", keywordTwo = "by", keywordThree = "to";
	if(getCommand() == "add" || getCommand() =="edit"){
		EndTime = getTime(uncategorizedInfo, keywordOne);

		if(EndTime == "3000")
			EndTime = getTime(uncategorizedInfo, keywordTwo);

		if(EndTime == "3000")
			EndTime = getTime(uncategorizedInfo, keywordThree);
		}

	return EndTime;
}

string Identifier::getEvent(){
	string Event = " ";
	if(getCommand() == "add" || getCommand() =="edit"){
		Event = uncategorizedInfo;
	}
	return Event;
}

int Identifier::getTaskNumber(){
	int TaskNumber = 0, position = 0, size = 1;
	if(getCommand() == "edit"){
		TaskNumber =  std::stoi(uncategorizedInfo.substr(position,size));
		chopInfo(uncategorizedInfo, position, size);
	}
	else if(getCommand() == "delete"){
		TaskNumber = std::stoi(uncategorizedInfo);
	}
	return TaskNumber;
}

string Identifier::getKeyword(){
	string Keyword;
	if(getCommand() == "search"){
		Keyword = uncategorizedInfo;
	}
	return Keyword;
}

/*this function is not used right now, but i think it might be a good idea.
 *this function extract all possible attributes for a ADD operation,
 *by writing similar function like this one, we can have less work in writing the TASK class,
 *since we only need to call one function to get all necessary information for the current operation.
 *besides, the code for Identifier class can also be simplified.
 *however, this requires the Task class to be able to access the private attributes of the Identifier class,
 *therefore, maybe we should consider using inherient classes.
 */
void Identifier::getAddEditInfo(){
	getTaskNumber();
	getDate();
	getStartTime();
	getEndTime();
	getEvent();
}	

bool Identifier::ifNumber(string test){
	unsigned int matchCount = 0;
	bool isNumber = false;

	for(unsigned int i = 0; i < test.size(); i++){
		for(unsigned int j = 0; j < 10; j++){
			if(test[i] == number[j]){
				matchCount++;
			}
		}
	}
	
	if(matchCount == test.size()){
		isNumber = true;
	}

	return isNumber;
}

string Identifier::getTime(string test, string keyword){
	string Time = "3000", tempTime;
	unsigned int position, startPos = 0, size = keyword.size() + 6;

	if(size < uncategorizedInfo.size())
		do{
			position = test.find(keyword, startPos);

			if(position != string::npos){
				tempTime = test.substr(position + keyword.size() + 1, 5);

				if((tempTime.substr(2,1)) == colon){
					tempTime = tempTime.substr(0,2) + tempTime.substr(3,2);

				    if(ifNumber(tempTime)){
						Time = tempTime;
						chopInfo(uncategorizedInfo, position, size);
					    break;
					}
				}
			}

			startPos = position + 1;

		 }while(position != string::npos);

	return Time;
}

string Identifier::markStatus(string test){
	string status;
	if(getCommand() == "mark"){
		status = uncategorizedInfo;
	}
	
	if(status == "done" || status == "undone" || "cannot be done")
		return status;

	else{
		return "error";
}
	