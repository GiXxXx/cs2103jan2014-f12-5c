#include "File.h"
const string name = "data";

File::File(void){
	filename = name;
}


File::~File(void){
}

void File::AccessFile(list<Task> TaskList){
	string TaskString;
	Task Task;
	string date, StartTime, EndTime, Event;
	double SequenceNumber;
	string Number;
	int status;
	string StatusString;
	ifstream read(filename.c_str());

	while(getline(read, date)){
		Task.SetDate(date);
		getline(read, StartTime);
		Task.SetStartTime(StartTime);
		getline(read, EndTime);
		Task.SetEndTime(EndTime);
		getline(read, Event);
		Task.SetEvent(Event);
		getline(read, Number);
		TryParse(Number, SequenceNumber);
		Task.SetSeqenceNumber(SequenceNumber);
		getline(read, StatusString);
		TryParse(StatusString, status);
		Task.SetStatus(status);
		TaskList.push_back(Task);
	}

	read.close();
}

void File::SaveFile(list<Task> TaskList){
	string date, StartTime, EndTime, Event;
	double SequenceNumber;
	int status;

	ofstream write(filename.c_str());

	while(!TaskList.empty()){
		Task task = *(TaskList.front());
		date = task.GetDate();
		StartTime = task.GetStartTime();
		EndTime = task.GetEndTime();
		Event = task.GetEvent();
		SequenceNumber = task.GetSequenceNumber();
		status = task.GetStatus();
		TaskList.pop_front();

		write << date << endl << StartTime << endl << EndTime << endl << Event << endl << SequenceNumber << endl << status << endl;
	}

	write.close();
}
