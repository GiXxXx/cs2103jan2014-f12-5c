/*#include "File.h"
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
	string Status;
	ifstream read(filename.c_str());

	while(getline(read, date)){
		task.setDate(date);
		getline(read, StartTime);
		task.setStartTime(StartTime);
		getline(read, EndTime);
		task.setEndTime(EndTime);
		getline(read, Event);
		task.setEvent(Event);
		getline(read, Number);
		SequenceNumber = std::stoi(Number);
		task.setSeqenceNum(SequenceNumber);
		getline(read, Status);
		task.setStatus(Status);
		TaskList.push_back(task);
	}

	read.close();
}

void File::SaveFile(list<Task> TaskList){
	string date, StartTime, EndTime, Event;
	double SequenceNumber;
	string status;

	ofstream write(filename.c_str());

	while(!TaskList.empty()){
		Task task = (TaskList.front());
		date = task.getDate();
		StartTime = task.getStartTime();
		EndTime = task.getEndTime();
		Event = task.getEvent();
		SequenceNumber = task.getSequenceNum();
		status = task.getStatus();
		TaskList.pop_front();

		write << date << endl << StartTime << endl << EndTime << endl << Event << endl << SequenceNumber << endl << status << endl;
	}

	write.close();
}
*/