#ifndef HEADER_IDENTIFIER_
#define HEADER_IDENTIFIER_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

const string number = "0123456789";
const string slash = "/";
const string colon = ":";
const string dot = ".";
const string dash = "-";
const string space = " ";
const string Mark = "mark";
const string Add = "add";
const string Delete = "delete";
const string Edit = "edit";
const string Undo = "undo";
const string Done = "done";
const string Search = "search";
const string UnDone = "undone";
const string CannotBeDone = "cannot be done";
const string NoStatus = "no status";
const string LargeDate = "        ";
const string LargeTime = "    ";
const string OnAndBy = "onby";
const string at = "at";
const string to = "to";
const string from = "from";
const string by = "by";
const string monday = "monday";
const string tuesday = "tuesday";
const string thursday = "thursday";
const string wednesday = "wednesday";
const string friday = "friday";
const string saturday = "saturday";
const string sunday = "sunday";
const string Monday = "Monday";
const string Tuesday = "Tuesday";
const string Wednesday = "Wednesday";
const string Thursday = "Thursday";
const string Friday = "Friday";
const string Saturday = "Saturday";
const string Sunday = "Sunday";
const string MONDAY = "MONDAY";
const string TUESDAY = "TUESDAY";
const string THURSDAY = "THURSDAY";
const string WEDNESDAY = "WEDNESDAY";
const string FRIDAY = "FRIDAY";
const string SATURDAY = "SATURDAY";
const string SUNDAY = "SUNDAY";
const string Mon = "Mon";
const string Tue = "Tue";
const string Wed = "Wed";
const string Thu = "Thu";
const string Fri = "Fri";
const string Sat = "Sat";
const string Sun = "Sun";
const string mon = "mon";
const string tue = "tue";
const string wed = "wed";
const string thu = "thu";
const string fri = "fri";
const string sat = "sat";
const string sun = "sun";
const string MON = "MON";
const string TUE = "TUES";
const string THU = "THU";
const string WED = "WED";
const string FRI = "FRI";
const string SAT = "SAT";
const string SUN = "SUN";
const string Next = "next";
const string This = "this";
const string Zero = "0";
const string one = "1";
const string two = "2";
const string three = "3";
const string four = "4";
const string five = "5";
const string six = "6";
const string seven = "7";
const string eight = "8";
const string nine = "9";
const string ten = "10";
const string eleven = "11";
const string twelve = "12";
const string jan = "jan";
const string january = "january";
const string January = "January";
const string JANUARY = "JANUARY";
const string JAN = "JAN";
const string Jan = "Jan";
const string feb = "feb";
const string Feb = "Feb";
const string FEB = "FEB";
const string february = "february";
const string February = "February";
const string FEBRUARY = "FEBRUARY";
const string mar = "mar";
const string Mar = "Mar";
const string MAR = "MAR";
const string march = "march";
const string March = "March";
const string MARCH = "MARCH";
const string apr = "apr";
const string Apr = "Apr";
const string APR = "APR";
const string april = "april";
const string April = "April";
const string APRIL = "APRIL";
const string may = "may";
const string May = "May";
const string MAY = "MAY";
const string jun = "jun";
const string Jun = "Jun";
const string JUN = "JUN";
const string june = "june";
const string June = "June";
const string JUNE = "JUNE";
const string jul = "jul";
const string Jul = "Jul";
const string JUL = "JUL";
const string july = "july";
const string July = "July";
const string JULY = "JULY";
const string aug = "aug";
const string Aug = "Aug";
const string AUG = "AUG";
const string august = "august";
const string August = "August";
const string AUGUST = "AUGUST";
const string sep = "sep";
const string Sep = "Sep";
const string SEP = "SEP";
const string september = "september";
const string September = "September";
const string SEPTEMBER = "SEPTEMBER";
const string octo = "oct";
const string Oct = "Oct";
const string OCT = "OCT";
const string october = "october";
const string October = "October";
const string OCTOBER = "OCTOBER";
const string nov = "nov";
const string Nov = "Nov";
const string NOV = "NOV";
const string november = "november";
const string November = "November";
const string NOVEMBER = "NOVEMBER";
const string dece = "dec";
const string Dec = "Dec";
const string DEC = "DEC";
const string december = "december";
const string December = "December";
const string DECEMBER = "DECEMBER";
const string Spaces = "                    ";
const unsigned int start = 0;
const unsigned int OneUnit = 1;
const unsigned int TwoUnit = 2;
const unsigned int ThreeUnit = 3;
const unsigned int FourUnit = 4;
const unsigned int FiveUnit = 5;
const unsigned int SixUnit = 6;
const unsigned int SevenUnit = 7;
const unsigned int EightUnit = 8;
const unsigned int NineUnit = 9;
const unsigned int TenUnit = 10;
const int zero = 0;

class Tokenizer{

protected:
	string *uncategorizedInfo;

public:
	Tokenizer(string&);
	~Tokenizer();
	void chopInfo(string&, int, int);
	bool isNumber(string);
	void ChangeDoubleDigit(string&);
	string getTime(string, string);
	string GetDateFormatTwo(string);
	virtual string Tokenize();
};

#endif