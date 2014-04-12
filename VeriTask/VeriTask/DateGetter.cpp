//@author A0101568J

#include "DateGetter.h"
#include <exception>


DateGetter::DateGetter(string& uncategorizedInfo, string Command) :Tokenizer(uncategorizedInfo), _command(Command) { 
}


DateGetter::~DateGetter(void) {
}

string DateGetter::tokenize() {
	string Date = EMPTY_DATE;
	string keyword;
	string save = *_uncategorizedInfo;
	unsigned int indicator = ZERO;

	if (_command == ADD || _command == EDIT || _command == DISPLAY) {
		//if the command word is display, add a preposition to the
		//beginning of the string for retrieveing date
		if (_command == DISPLAY) {
			unsigned int position = (*_uncategorizedInfo).find_first_not_of(PUNCTUATION_SET);

			if (position != string::npos) {
				*_uncategorizedInfo = (*_uncategorizedInfo).substr(position);
				*_uncategorizedInfo = BY + *_uncategorizedInfo;
			}
		}

		unsigned int posOne = (*_uncategorizedInfo).find_first_not_of(PUNCTUATION_SET);
		unsigned int posTwo = (*_uncategorizedInfo).find_first_of(PUNCTUATION_SET, posOne);

		//for rigid format input
		//if the first eight char is eight digits, return it as date
		//and chop the string
		if (posOne != string::npos) {
			string checker = (*_uncategorizedInfo).substr(posOne, posTwo - posOne);

			if (isNumber(checker) && checker.size() == EIGHT_UNIT) {
				Date = checker;
				chopInfo(*_uncategorizedInfo, posOne, checker.size());
			}
		}

		while (Date == EMPTY_DATE && indicator < NINE_UNIT) {

			keyword = PREPOSITION[indicator];

			Date = getDateFromDate(*_uncategorizedInfo, keyword);

			if (Date == EMPTY_DATE) {
				Date = getDateFromWeek(*_uncategorizedInfo, keyword);
			}

			if (Date == EMPTY_DATE) {
				Date = getDateFromNumberOfDays(*_uncategorizedInfo, keyword);
			}

			if (Date == EMPTY_DATE) {
				Date = getDateFromTomorrow(*_uncategorizedInfo, keyword);
			}

			if (Date == EMPTY_DATE) {
				Date = getDateFromFestival(*_uncategorizedInfo, keyword);
			}

			//if a date is rerieved when the preposition is before
			//or after, do increment or decrement
			Date = getDateForBeforeAfter(Date, keyword);

			if (Date != EMPTY_DATE) {
				break;
			}

			indicator += ONE_UNIT;
		}

		//if the command is display and afterall no date is retrieved
		//remove the preposition "by" added at the beginning
		if (Date == EMPTY_DATE && _command == DISPLAY) {
			*_uncategorizedInfo = (*_uncategorizedInfo).substr(FOUR_UNIT);
			string checker = (*_uncategorizedInfo).substr(START, EIGHT_UNIT);

			if (isNumber(checker) && checker.size() == EIGHT_UNIT) {
				Date = checker;
				*_uncategorizedInfo = (*_uncategorizedInfo).substr(EIGHT_UNIT);
			}
		}

		if (isNumber(Date) && Date.size() <= NINE_UNIT && stoi(Date) > MAX_DATE) {
			*_uncategorizedInfo = save;
		}

//		if (Date == EMPTY_DATE && _command == EDIT) {
//			string checker = (*_uncategorizedInfo).substr(START, EIGHT_UNIT);
//
//			if (isNumber(checker) && checker.size() == EIGHT_UNIT) {
//				Date = checker;
//				*_uncategorizedInfo = (*_uncategorizedInfo).substr(EIGHT_UNIT);
//			}
//		}
	}

	return Date;
}


string DateGetter::getDateFromDate(string &Input, string keyword) {
	string Date = EMPTY_DATE;
	string tempDate;
	string elementOne;
	string elementTwo;
	string elementThree;
	string duplicate = Input;
	unsigned int position;
	unsigned int startPos = START;
	unsigned int positionOne;
	unsigned int positionTwo;

	changeToLowerCase(duplicate);

	do {
		position = duplicate.find(keyword, startPos);

		if (position != string::npos) {
			tempDate = duplicate.substr(position + keyword.size());

			positionOne = tempDate.find_first_of(SLASH);
			positionTwo = tempDate.find_last_of(SLASH);

			if (positionOne == string::npos || positionTwo == string::npos || positionOne == positionTwo) {
				positionOne = tempDate.find_first_of(DOT);
				positionTwo = tempDate.find_last_of(DOT);
			}

			if (positionOne == string::npos || positionTwo == string::npos || positionOne == positionTwo) {
				positionOne = tempDate.find_first_of(DASH);
				positionTwo = tempDate.find_last_of(DASH);
			}

			if (positionOne == string::npos || positionTwo == string::npos || positionOne == positionTwo) {
				positionOne = tempDate.find_first_of(SPACE);
				positionTwo = tempDate.find_first_of(SPACE, positionOne + ONE_UNIT);
			}

			//if formate like 2014-11-22, 2014/11/22, 22 11 2014..is detected, get all the numbers as elements
			if (positionOne != string::npos && positionTwo != string::npos && positionOne != positionTwo) {
				elementOne = tempDate.substr(START, positionOne);
				elementTwo = tempDate.substr(positionOne + ONE_UNIT, positionTwo - positionOne - ONE_UNIT);
				elementThree = tempDate.substr(positionTwo + ONE_UNIT, FOUR_UNIT);

				unsigned int endPos = tempDate.find_first_of(SPACE);

				if (!isNumber(elementTwo)) {
					convertMonth(elementTwo);
				}

				if (!isNumber(elementThree)) {
					elementThree = tempDate.substr(positionTwo + ONE_UNIT, TWO_UNIT);
				}

				if (!isNumber(elementThree)) {
					elementThree = tempDate.substr(positionTwo + ONE_UNIT, ONE_UNIT);
				}

				changeDoubleDigit(elementOne);
				changeDoubleDigit(elementTwo);
				changeDoubleDigit(elementThree);

				if (elementOne.size() == FOUR_UNIT) {
					tempDate = elementOne + elementTwo + elementThree;
				}

				if (elementThree.size() == FOUR_UNIT) {
					tempDate = elementThree + elementTwo + elementOne;
				}

				//after convert the numbers to the date format
				//check whether the date is the correct format type
				//if yes, return date and chop original string
				//if no, return empty date and no chop
				if (isNumber(tempDate)) {
					Date = tempDate;
					chopInfo((*_uncategorizedInfo), position, endPos + keyword.size());
					break;
				}
			}

			startPos = position + ONE_UNIT;
		}
	} while (position != string::npos);

	return Date;
}

string DateGetter::getDateFromWeek(string &Input, string keyword) {
	char buffer[100] = { 0 };
	time_t localTime;
	struct tm timenow;
	int taskDayOfWeek = ZERO;
	unsigned int positionOne;
	unsigned int positionTwo;
	unsigned int position;
	unsigned int startPos = START;
	unsigned int size;
	string week = EMPTY_STRING, tempDate;
	string Date = EMPTY_DATE;
	string duplicate = Input;

	changeToLowerCase(duplicate);

	do {
		position = duplicate.find(keyword, startPos);

		if (position != string::npos) {
			tempDate = duplicate.substr(position + keyword.size());

			positionOne = tempDate.find_first_of(PUNCTUATION_SET);
			week = tempDate.substr(START, positionOne);
			size = positionOne;

			//case when not typing the week alone like on friday
			//but like on this friday, on next friday
			if (week == NEXT) {
				positionOne = positionOne + ONE_UNIT;
				positionTwo = tempDate.find_first_of(PUNCTUATION_SET, positionOne);
				size = positionTwo;
				week = tempDate.substr(positionOne, positionTwo - positionOne);
				taskDayOfWeek = SEVEN_UNIT;
			}

			if (week == THIS_STRING) {
				positionOne = positionOne + ONE_UNIT;
				positionTwo = tempDate.find_first_of(PUNCTUATION_SET, positionOne);
				size = positionTwo;
				week = tempDate.substr(positionOne, positionTwo - positionOne);
			}

			//by this week, in this week
			//the deadline will be the sunday
			if (week == WEEK || week == WEEKS) {
				week = SUN;
			}
		}

		//situation whn user haveno preposition
		//sample typing:go home and have dinner this friday
		if (week == EMPTY_STRING && keyword == AT && position == string::npos) {
			startPos = ZERO;
			do {
				position = duplicate.find(SPACE + THIS_STRING, startPos);

				if (position != string::npos) {
					taskDayOfWeek = ZERO;
				}
				else if (position == string::npos) {
					position = duplicate.find(SPACE + NEXT, startPos);
					taskDayOfWeek = SEVEN_UNIT;
				}

				if (position != string::npos) {
					int begin = position + SIX_UNIT;
					int end = duplicate.find_first_of(SPACE, begin);
					week = duplicate.substr(begin, end - begin);

					string checker = week;
					convertWeek(checker);

					if (isNumber(checker)) {
						keyword = EMPTY_STRING;
						size = week.size() + SIX_UNIT;
						break;
					}
				}

				startPos = position + SIX_UNIT;

			} while (position != string::npos);
		}

		//get the date when items like friday, this friday is identified
		if (!isNumber(week) && week != EMPTY_STRING) {

			convertWeek(week);

			if (isNumber(week)) {
				taskDayOfWeek = taskDayOfWeek + stoi(week);
				localTime = time(NULL);
				localtime_s(&timenow, &localTime);

				strftime(buffer, 100, "%Y-%m-%A-%d", &timenow);

				int currentDayOfWeek = (timenow.tm_wday + SIX_UNIT) % SEVEN_UNIT;
				int currentYear = timenow.tm_year + YEAR_ADDER;
				int currentMonth = timenow.tm_mon + ONE_UNIT;
				int currentday = timenow.tm_mday;
				int currentTotalDay = timenow.tm_yday;
				int taskDay;
				int taskMonth = currentMonth;
				int taskYear = currentYear;

				taskDay = currentday + taskDayOfWeek - currentDayOfWeek;

				if ((currentMonth == ONE_UNIT || currentMonth == THREE_UNIT || 
					currentMonth == FIVE_UNIT || currentMonth == SEVEN_UNIT || 
					currentMonth == EIGHT_UNIT || currentMonth == TEN_UNIT || 
					currentMonth == TEN_UNIT+ TWO_UNIT) && taskDay > MONTH_DAYS) {
					taskDay = taskDay - MONTH_DAYS;
					++taskMonth;
					} else if ((currentMonth == FOUR_UNIT || currentMonth == SIX_UNIT ||
				    currentMonth == NINE_UNIT || currentMonth == TEN_UNIT + ONE_UNIT)
					&& taskDay > TEN_UNIT * THREE_UNIT) {
					taskDay = taskDay - TEN_UNIT * THREE_UNIT;
		     			++taskMonth;
			    	} else if (currentMonth == TWO_UNIT && currentYear % FOUR_UNIT == ZERO
						&& taskDay > TEN_UNIT * THREE_UNIT - ONE_UNIT) {
						taskDay = taskDay - (TEN_UNIT * THREE_UNIT - ONE_UNIT);
						++taskMonth;
					} else if (currentMonth == TWO_UNIT && currentYear % FOUR_UNIT != ZERO 
						&& taskDay > TEN_UNIT * THREE_UNIT - TWO_UNIT) {
						taskDay = taskDay - (TEN_UNIT * THREE_UNIT - TWO_UNIT);
						++taskMonth;
					}

					if (taskMonth > TEN_UNIT + TWO_UNIT) {
						taskMonth = taskMonth - (TEN_UNIT + TWO_UNIT);
						++taskYear;
					}

					Date = convertToDate(taskYear, taskMonth, taskDay);
					chopInfo(Input, position, size + keyword.size());
					break;
				}
			}

			startPos = position + ONE_UNIT;

	} while (position != string::npos && Date == EMPTY_DATE);

	return Date;
}

string DateGetter::getDateFromTomorrow(string& Input, string keyword) {
	string Date = EMPTY_DATE;
	string tempDate;
	string duplicate = Input;

	unsigned int position, startPos = START;
	unsigned int positionOne;
	unsigned int positionTwo;
	unsigned int indicator = ZERO;
	unsigned int size;
	string description[SEVEN_UNIT] = { THE_DAY_AFTER_TOMORROW, THE_DAY_AFTER_TMR, 
		                               DAY_AFTER_TOMORROW, DAY_AFTER_TMR,
									   TOMORROW, TMR, TODAY };

	changeToLowerCase(duplicate);

	//exclude the case for after the day after tomorrow
	if (keyword == AFTER) {
		indicator = FOUR_UNIT;
	}

	do {
		position = duplicate.find(keyword, startPos);

		if (position != string::npos) {
			tempDate = duplicate.substr(position + keyword.size());

			while (Date == EMPTY_DATE && indicator < SEVEN_UNIT) {
				positionOne = tempDate.find(description[indicator]);

				if (positionOne != string::npos) {
					size = description[indicator].size();

					//if immediately after the keyword, words like "today", "tomorrow" are
					//found, convert to date and chop original string
					if (positionOne == ZERO && tempDate.find_first_of(PUNCTUATION_SET) == size) {
						Date = convertDateFromDescription(description[indicator], SPACE);
						chopInfo(Input, position, description[indicator].size() + keyword.size());
						break;
					}
				}

				indicator++;
			}

			startPos = position + ONE_UNIT;
		}

	} while (position != string::npos && Date == EMPTY_DATE);

	indicator = ZERO;

	//when no keyword is identified and no date found
	//try to find "today", "the day afer..." alone
	while (Date == EMPTY_DATE && indicator < SEVEN_UNIT && keyword == AT) {
		positionOne = duplicate.find(description[indicator]);

		if (positionOne == ZERO) {
			Date = convertDateFromDescription(description[indicator], SPACE);
			chopInfo(Input, positionOne, description[indicator].size());
			break;
		} else {
			positionTwo = duplicate.rfind(description[indicator]);

			if (positionTwo != string::npos) {
				string checker = duplicate.substr(positionTwo + description[indicator].size()
					+ ONE_UNIT, TEN_UNIT);

				//if there are two words indicating date found, make the word
				//appear first or last as the top priority when identify the date
				if (checker == TEN_SPACES && positionOne != START) {
					Date = convertDateFromDescription(description[indicator], SPACE);
					chopInfo(Input, positionTwo, description[indicator].size());
					break;
				} else {
					Date = convertDateFromDescription(description[indicator], SPACE);
					chopInfo(Input, positionOne, description[indicator].size());
					break;
				}
			}
		}

		indicator++;
	}

	return Date;
}

string DateGetter::getDateFromNumberOfDays(string& Input, string keyword) {
	string Date = EMPTY_DATE;
	string tempDate;
	string element;
	string number;
	string duplicate = Input;

	unsigned int position;
	unsigned int startPos = START;
	unsigned int positionOne;
	unsigned int indicator = ZERO;

	string description[EIGHT_UNIT] = { DAYS, DAY, MONTH, MONTHS,
		                               YEAR, YEARS, WEEK, WEEKS };

	string descriptionTwo[SIX_UNIT] = { SPACE + THIS_STRING + SPACE + WEEK, 
		                                SPACE + THIS_STRING + SPACE + MONTH,
		                                SPACE + THIS_STRING + SPACE + YEAR,
										SPACE + NEXT + SPACE + WEEK,
										SPACE + NEXT + SPACE + MONTH,
										SPACE + NEXT + SPACE + YEAR, };

	changeToLowerCase(duplicate);

	do {
		position = duplicate.find(keyword, startPos);

		if (position != string::npos) {
			while (Date == EMPTY_DATE && indicator < EIGHT_UNIT) {
				tempDate = duplicate.substr(position);
				positionOne = tempDate.find(description[indicator]);

				if (positionOne != string::npos && positionOne != ZERO 
					&& tempDate.substr(positionOne - ONE_UNIT, ONE_UNIT) == SPACE) {
					tempDate = tempDate.substr(keyword.size(), 
						positionOne - ONE_UNIT - keyword.size());

					number = tempDate;

					//situation when there is no digit between eg. in three days
					//instead of in 3 days, convert the word to digit
					//return zero if the word is nbot representing a number
					if (!isNumber(tempDate) && tempDate != THIS_STRING && tempDate != NEXT) {
						number = changeWordToNumber(tempDate);
					}

					if (number != ZERO_STRING) {
						Date = convertDateFromDescription(description[indicator], number);
						chopInfo(Input, position, keyword.size() + ONE_UNIT + 
							tempDate.size() + description[indicator].size());
						break;
					}
				}

				indicator++;
			}

			startPos = position + ONE_UNIT;
		}

	} while (position != string::npos);

	//when no date is identified at the end
	//directly find the keywords
	//eg. this year, this week
	if (Date == EMPTY_DATE && keyword == AT) {
		for (int i = ZERO; i < SIX_UNIT; i++) {
			position = duplicate.find(descriptionTwo[i]);

			if (position != string::npos) {
				string temp = descriptionTwo[i].substr(SIX_UNIT);
				number = descriptionTwo[i].substr(ONE_UNIT, FOUR_UNIT);
				Date = convertDateFromDescription(temp, number);
				chopInfo(*_uncategorizedInfo, position, descriptionTwo[i].size());
			}
		}
	}

	return Date;
}

string DateGetter::getDateFromFestival(string &Input, string keyword) {
	string Date = EMPTY_DATE;
	string tempDate;
	string element;
	string number;
	string duplicate = Input;
	string dateAdder;
	string dummyString = DUMMY;
	unsigned int position;
	unsigned int startPos = START;
	unsigned int positionOne;
	unsigned int positionTwo;
	unsigned int indicator = ZERO;
	unsigned int size = TEN_UNIT + TEN_UNIT + THREE_UNIT;

	changeToLowerCase(duplicate);

	dateAdder = getDateFromTomorrow(dummyString, BY);
	dateAdder = dateAdder.substr(START, FOUR_UNIT);

	do {
		position = duplicate.find(keyword, startPos);

		if (position != string::npos) {
			while (Date == EMPTY_DATE && indicator < size) {
				tempDate = duplicate.substr(position);
				positionOne = tempDate.find(FESTIVAL[indicator]);

				if (positionOne != string::npos) {
					if (positionOne == keyword.size()) {
						Date = dateAdder + FESTIVAL_DATE[indicator];
						chopInfo(Input, position, keyword.size() + FESTIVAL[indicator].size());
						break;
					} else {
						positionTwo = keyword.size();
						tempDate = tempDate.substr(positionTwo, 
							       positionOne - positionTwo - ONE_UNIT);

						//situations when input have
						//this national day, the national day, next national day, the next.. 
						if (tempDate == THIS_STRING || tempDate == THE) {
							Date = dateAdder + FESTIVAL_DATE[indicator];
							chopInfo(Input, position, keyword.size() + ONE_UNIT
								     + tempDate.size() + FESTIVAL[indicator].size());
							break;
						} else if (tempDate == NEXT || tempDate == THE + NEXT) {
							Date = dateAdder + FESTIVAL_DATE[indicator];
							int dateNumber = stoi(Date);
							dateNumber = dateNumber + TEN_THOUSAND;

							ostringstream out;
							out << dateNumber;
							Date = out.str();

							chopInfo(Input, position, keyword.size() + 
								     ONE_UNIT + tempDate.size() + 
									 FESTIVAL[indicator].size());
							break;
						}
					}
				}

				indicator++;
			}

			startPos = position + ONE_UNIT;
		}

	} while (position != string::npos);

	return Date;
}

string DateGetter::getDateForBeforeAfter(string Date, string keyword) {
	if (Date != EMPTY_DATE && (keyword == BEFORE || keyword == AFTER)) {
		string year = Date.substr(START, FOUR_UNIT);
		string month = Date.substr(FOUR_UNIT, TWO_UNIT);
		string day = Date.substr(SIX_UNIT, TWO_UNIT);

		struct tm timeNow;
		time_t local = time(NULL);
		localtime_s(&timeNow, &local);

		timeNow.tm_year = stoi(year) - YEAR_ADDER;
		timeNow.tm_mon = stoi(month) - ONE_UNIT;
		timeNow.tm_mday = stoi(day);

		if (keyword == BEFORE) {
			timeNow.tm_mday--;
		} else {
			timeNow.tm_mday++;
		}

		time_t newTime = mktime(&timeNow);
		localtime_s(&timeNow, &newTime);

		Date = convertToDate(timeNow.tm_year + YEAR_ADDER,
			                 timeNow.tm_mon + ONE_UNIT,
							 timeNow.tm_mday);
	}

	return Date;
}

string DateGetter::convertToDate(int year, int month, int day) {
	ostringstream outstr;

	outstr << year;

	if (month < TEN_UNIT) {
		outstr << ZERO;
	}

	outstr << month;

	if (day < TEN_UNIT) {
		outstr << ZERO;
	}

	outstr << day;

	return outstr.str();
}

void DateGetter::convertMonth(string &Month) {
	changeToLowerCase(Month);

	if (Month == JAN || Month == JANUARY) {
		Month = ONE_UNIT;
	} else if (Month == FEB || Month == FEBRUARY) {
		Month = TWO_UNIT;
	} else if (Month == MAR || Month == MARCH) {
		Month = THREE_UNIT;
	} else if (Month == APR || Month == APRIL) {
		Month = FOUR_UNIT;
	} else if (Month == MAY) {
		Month = FIVE_UNIT;
	} else if (Month == JUN || Month == JUNE) {
		Month = SIX_UNIT;
	} else if (Month == JUL || Month == JULY) {
		Month = SEVEN_UNIT;
	} else if (Month == AUG || Month == AUGUST) {
		Month = EIGHT_UNIT;
	} else if (Month == SEP || Month == SEPTEMBER) {
		Month = NINE_UNIT;
	} else if (Month == OCT || Month == OCTOBER) {
		Month = TEN_UNIT;
	} else if (Month == NOV || Month == NOVEMBER) {
		Month = ELEVEN;
	} else if (Month == DEC || Month == DECEMBER) {
		Month = TWELVE;
	}

	return;
}

void DateGetter::convertWeek(string &Week) {
	changeToLowerCase(Week);

	if (Week == MON || Week == MONDAY) {
		Week = ZERO_STRING;
	} else if (Week == TUE || Week == TUESDAY) {
		Week = ONE_STRING;
	} else if (Week == WED || Week == WEDNESDAY) {
		Week = TWO_STRING;
	} else if (Week == THU || Week == THURSDAY) {
		Week = THREE_STRING;
	} else if (Week == FRI || Week == FRIDAY) {
		Week = FOUR_STRING;
	} else if (Week == SAT || Week == SATURDAY) {
		Week = FIVE_STRING;
	} else if (Week == SUN || Week == SUNDAY) {
		Week = SIX_STRING;
	}

	return;
}

string DateGetter::convertDateFromDescription(string description, string descriptionTwo) {
	int adder = ZERO;

	try {
		if (descriptionTwo.size() > NINE_UNIT) {
			throw descriptionTwo;
		}
	} catch (string e) {
		descriptionTwo = EMPTY_STRING;
	}

	if (isNumber(descriptionTwo) && descriptionTwo.size() != ZERO) {
		adder = stoi(descriptionTwo);
	}

	//decide which kind of days set to be added
	//eg. if add weeks, seven days together will
	//be the base adding unit
	if (description == DAY || description == DAYS) {
		adder = adder * ONE_UNIT;
	} else if (description == WEEK || description == WEEKS) {
		adder = adder * SEVEN_UNIT;
	} else if (description == MONTH || description == MONTHS) {
		adder = adder * TEN_UNIT * THREE_UNIT;
	} else if (description == YEAR || description == YEARS) {
		adder = adder * YEAR_DAYS;
	} else if (description == TMR || description == TOMORROW) {
		adder = adder + ONE_UNIT;
	} else if (description == THE_DAY_AFTER_TMR || description == THE_DAY_AFTER_TOMORROW
		        || description == DAY_AFTER_TMR || description == DAY_AFTER_TOMORROW) {
		adder = adder + TWO_UNIT;
	}

	time_t local = time(NULL);
	struct tm timeNow;
	localtime_s(&timeNow, &local);
	timeNow.tm_mday += adder;
	time_t newTime = mktime(&timeNow);
	localtime_s(&timeNow, &newTime);

	//if the format is on this year, by this year
	//return the last day of the year as deadline
	if (description == YEAR || description == YEARS) {
		if (descriptionTwo == THIS_STRING) {
			timeNow.tm_mday = MONTH_DAYS;
			timeNow.tm_mon = YEAR_MONTHS;
		} else if (descriptionTwo == NEXT) {
			timeNow.tm_mday = MONTH_DAYS;
			timeNow.tm_mon = YEAR_MONTHS;
			timeNow.tm_year += ONE_UNIT;
		}
	} else if (description == MONTH || description == MONTHS) {
		if (descriptionTwo == THIS_STRING) {
			int temp = timeNow.tm_mon;

			while (timeNow.tm_mon == temp) {
				timeNow.tm_mday++;
				newTime = mktime(&timeNow);
				localtime_s(&timeNow, &newTime);
			}

			timeNow.tm_mday--;
			newTime = mktime(&timeNow);
			localtime_s(&timeNow, &newTime);

		} else if (descriptionTwo == NEXT) {
			int temp = timeNow.tm_mon + ONE_UNIT;

			while (timeNow.tm_mon <= temp) {
				timeNow.tm_mday++;
				newTime = mktime(&timeNow);
				localtime_s(&timeNow, &newTime);
			}

			timeNow.tm_mday--;
			newTime = mktime(&timeNow);
			localtime_s(&timeNow, &newTime);
		}
	}

	int Year = timeNow.tm_year + YEAR_ADDER;
	int Month = timeNow.tm_mon + ONE_UNIT;
	int Day = timeNow.tm_mday;

	string Date = convertToDate(Year, Month, Day);

	return Date;
}