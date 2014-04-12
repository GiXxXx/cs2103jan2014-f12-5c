//@author A0101039X

/**
* This is a class that records all necessary information for a task.
* It alos contains methods to modify and retrieve the information.
* Sample usage:
* Task task;
* task.retrieveTaskID();
*/

#include <string>
#include <ctime>

using namespace std;

const string EMPTY_DATES = "        ";
const string EMPTY_TIMES = "    ";

const int TWO_POSITION = 2;
const int SIX_POSITION = 6;

const int LARGE_DATE = 999999;
const int LARGE_TIME = 9999;

const unsigned long long int THIRTEEN_ZEROS = 10000000000000;
const unsigned long long int NINE_ZEROS = 1000000000;
const unsigned long long int FIVE_ZEROS = 100000;

const int FOUR_ZEROS = 10000;
const int TWO_ZEROS = 100;

const int ONE_NINE_ZERO_ZERO = 1900;
const int ONE = 1;

const string DONE_STATUS = "done";
const string OVERDUE_STATUS = "overdue";

class Task {

private:
	string _event;
	string _date;
	string _startTime;
	string _endTime;
	string _status;
	//this is the running index; it will increase by one each time a new task is created
	//so that tasks with same date and time will have different IDs based on sequence of
	//entering
	int _index;
	unsigned long long _ID;

	//this private function is used calculate the task ID for each task.
	//Pre-req: date, startTime, endTime, index
	//Post-req: task ID
	unsigned long long int _calculateTaskID (string date, string startTime, string endTime, int index) {
		unsigned long long ID;
		unsigned long long int date_Int;
		unsigned long long int startTime_Int;
		unsigned long long int endTime_Int;
		
		//if there is no date, set it to be 999999, so that it will be sorted
		//to the back as floating task.
		if (date == EMPTY_DATES) {
			date_Int = LARGE_DATE;
		} else {
			date_Int = stoi(date.substr(TWO_POSITION, SIX_POSITION));
		}
		
		//if there is no time, set it to be 9999
		if (startTime == EMPTY_TIMES) {
			startTime_Int = LARGE_TIME;
		} else {
			startTime_Int = stoi(startTime);
		}
	
		if (endTime == EMPTY_TIMES) {
			endTime_Int = LARGE_TIME;
		} else {
			endTime_Int = stoi(endTime);
		}

		//ID is made of 19 digits. The first 6 digits are in the form YYMMDD, next 8 digits
		//are start time followed by end time, the last 5 digits are for running index.
		ID = date_Int * THIRTEEN_ZEROS + startTime_Int * NINE_ZEROS  + endTime_Int * FIVE_ZEROS + index;
		return ID;
	}

	//this private function is used to check whether a task is overdue
	//Pre-req: date, start time, end time, status
	//Post-req: nil
	void _checkOverdue (string date, string startTime, string endTime, string status) {
		struct tm timeNow;
		time_t localTime = time(NULL);
		localtime_s(&timeNow, &localTime);

		//get local time
		int localYear = timeNow.tm_year + ONE_NINE_ZERO_ZERO;
		int localMonth = timeNow.tm_mon + ONE;
		int localDate = timeNow.tm_mday;
		int localHour = timeNow.tm_hour;
		int localMin = timeNow.tm_min;
	    
		//check whether a task is overdue
		//if a task is not marked as done and has passed deadline, then it's overdue
		if ((date != EMPTY_DATES) && (status != DONE_STATUS)) {
			if (localYear * FOUR_ZEROS + localMonth * TWO_ZEROS + localDate > stoi(date)) {
				status = OVERDUE_STATUS;
			} else if (localYear * FOUR_ZEROS + localMonth * TWO_ZEROS + localDate == stoi(date)) {
				//deadline task is overdue if time now is later than deadline
				if ((startTime != EMPTY_TIMES) && (endTime == EMPTY_TIMES)) {
					if ((localHour * TWO_ZEROS + localMin) > stoi(startTime)) {
					status = OVERDUE_STATUS;
					}
				}
				
				//duration task is marked as overdue if time now is later than end time
				//of the task
				if ((startTime != EMPTY_TIME) && (endTime != EMPTY_TIME)) {
					if ((localHour * 100 + localMin) > stoi(endTime)) {
						status = OVERDUE_STATUS;
					}
				}
			}
		}
	}

public:
	Task(string event, string date, string startTime, string endTime, string status, int index);
	
	inline string getEvent();
	inline string getDate();
	inline string getStartTime();
	inline string getEndTime();
	inline string getStatus();
	inline unsigned long long getID();
	inline int getIndex();

	inline void setEvent(string event);
	inline void setDate(string date);
	inline void setStartTime(string startTime);
	inline void setEndTime(string endTime);
	inline void setStatus(string status);
	inline void setID(unsigned long long ID);
};
