#include "File.h"
const string name = "data";

File::File(void){
	filename = name;
}


File::~File(void){
}

void File::AccessFile(list<Task> TaskList){
	string TaskString;
	Task task;
	string date, StartTime, EndTime, Event;
	double SequenceNumber;
	string Number;
	int status;
	string StatusString;
	ifstream read(filename.c_str());

	while(getline(read, date)){
		task.SetDate(date);
		getline(read, StartTime);
		task.SetStartTime(StartTime);
		getline(read, EndTime);
		task.SetEndTime(EndTime);
		getline(read, Event);
		task.SetEvent(Event);
		getline(read, Number);
		TryParse(Number, SequenceNumber);
		task.SetSeqenceNumber(SequenceNumber);
		getline(read, StatusString);
		TryParse(StatusString, status);
		task.SetStatus(status);
		TaskList.push_back(task);
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
