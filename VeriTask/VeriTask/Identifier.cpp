#include "Identifier.h"
#include <string>

using namespace std;

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
	uncategorizedInfo = _userInput.substr(_userInput.find_first_of(' ')+1);
}

/* sorry, still used the chopInfo method in this version. It's quite hard to handle the iterator method,
 * i will make necessary changes after this deadline
 */
string Identifier::chopInfo(string &oldInfo){
	string updatedInfo = oldInfo.substr(oldInfo.find_first_of(' ')+1);
	return updatedInfo;
}

string Identifier::getCommand(){
	string Command = _userInput.substr(0,_userInput.find_first_of(' '));
	return Command;
}

string Identifier::getDate(){
	string Date;
	if(getCommand() == "add" || getCommand() =="edit"){
		if(!floatingTask()){
			Date = uncategorizedInfo.substr(0,uncategorizedInfo.find_first_of(' '));
			uncategorizedInfo = chopInfo(uncategorizedInfo);
		}
	}
	return Date;
}

string Identifier::getStartTime(){
	string StartTime;
	if(getCommand() == "add" || getCommand() =="edit"){
		if(timedTask()){
			StartTime = uncategorizedInfo.substr(0,uncategorizedInfo.find_first_of(' '));
			uncategorizedInfo = chopInfo(uncategorizedInfo);
		}
	}
	return StartTime;
}

string Identifier::getEndTime(){
	string EndTime;
	if(getCommand() == "add" || getCommand() =="edit"){
		if(timedTask()){
			EndTime = uncategorizedInfo.substr(0,uncategorizedInfo.find_first_of(' '));
			uncategorizedInfo = chopInfo(uncategorizedInfo);
		}
	}
	return EndTime;
}

string Identifier::getEvent(){
	string Event;
	if(getCommand() == "add" || getCommand() =="edit"){
		Event = uncategorizedInfo;
	}
	return Event;
}

int Identifier::getTaskNumber(){
	int TaskNumber; 
	if(getCommand() == "edit"){
		TaskNumber =  std::stoi(uncategorizedInfo.substr(0,uncategorizedInfo.find_first_of(' ')));
		uncategorizedInfo = chopInfo(uncategorizedInfo);
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
	getDate();
	getStartTime();
	getEndTime();
	getEvent();
}	

/* the following two function checks whether the task is floating or timed or deadline,
 * to make things simple, i just used the magic number (e.g. 8 and 4) here since we have a fixed input format.
 * another thought about the time & date attributes, i doubt whether they can be converted into integer, 
 * because an integer can not be in the form like 0830.
 */
bool Identifier::floatingTask(){
	if(uncategorizedInfo.size() < 8){
		return true;
	}
	else if(uncategorizedInfo.substr(0,uncategorizedInfo.find_first_of(' ')).size() < 8){
		return true;
	}
	else{
		for(int i=0;i<8;i++){
			if(!(isdigit(uncategorizedInfo.at(i)) || !uncategorizedInfo.at(i) == ' ')){
				return true;
			}
		}
	}
	return false;
}

bool Identifier::timedTask(){
	if(uncategorizedInfo.size() < 4){
		return false;
	}
	else if(uncategorizedInfo.substr(0,uncategorizedInfo.find_first_of(' ')).size() < 4){
		return false;
	}
	else{
		for(int i=0;i<4;i++){
			if(!(isdigit(uncategorizedInfo.at(i)) || !uncategorizedInfo.at(i) == ' ' )){
				return false;
			}
		}
	}
	return true;
}