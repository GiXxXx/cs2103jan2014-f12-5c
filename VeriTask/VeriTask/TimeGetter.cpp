//@author A0101568J

#include "TimeGetter.h"


TimeGetter::TimeGetter(string& uncategorizedInfo, string Command) :Tokenizer(uncategorizedInfo), _command(Command) {
}


TimeGetter::~TimeGetter() {
}

string TimeGetter::tokenize() {
	string time = EMPTY_TIME;
	string tempTime;
	unsigned int indicator = ZERO;

	if (_command == ADD || _command == EDIT) {
		unsigned int posOne = (*_uncategorizedInfo).find_first_not_of(PUNCTUATION_SET);
		unsigned int posTwo = (*_uncategorizedInfo).find_first_of(PUNCTUATION_SET, posOne);

		//get thr time from rigid input
		//eg. 1330 go home
		if (posOne != string::npos) {
			string checker = (*_uncategorizedInfo).substr(posOne, posTwo - posOne);

			if (isNumber(checker) && checker.size() == FOUR_UNIT) {
				time = checker;
				chopInfo(*_uncategorizedInfo, posOne, checker.size());
			}
		}

		while (time == EMPTY_TIME && indicator < NINE_UNIT) {
			time = getTime(*_uncategorizedInfo, PREPOSITION[indicator]);

			indicator++;
		}

		indicator = ZERO;

		while (time == EMPTY_TIME && indicator < NINE_UNIT) {
			time = getTimeFromMorning(*_uncategorizedInfo, PREPOSITION[indicator]);

			indicator++;
		}
	}

//	if (time == EMPTY_TIME && _command == EDIT) {
//		string checker = (*_uncategorizedInfo).substr(START, FOUR_UNIT);
//		if (isNumber(checker) && checker.size() == FOUR_UNIT) {
//			time = checker;
//			*_uncategorizedInfo = (*_uncategorizedInfo).substr(FOUR_UNIT);
//		}
//	}

	return time;
}

string TimeGetter::getTime(string Input, string keyword) {
	string Time = EMPTY_TIME;
	string tempTime;
	string checker;
	string duplicate = Input;
	unsigned int position;
	unsigned startPos = START;
	unsigned sizeOne;
	unsigned sizeTwo;
	int hourStandard = ZERO;

	changeToLowerCase(duplicate);

	do {
		position = duplicate.find(keyword, startPos);

		if (position != string::npos) {
			tempTime = duplicate.substr(position + keyword.size());
			sizeOne = tempTime.find_first_of(PUNCTUATION_SET);
			sizeTwo = tempTime.find_first_of(PUNCTUATION_SET, sizeOne + ONE_UNIT);

			checker = tempTime.substr(sizeOne + ONE_UNIT, sizeTwo - sizeOne - ONE_UNIT);

			//check the hourStandard:12-hour or 24-hour
			//when input is like 7 pm, 8 pm(with a space between)
			if (checker == PM_ONE || checker == PM_TWO || checker == PM_THREE) {
				hourStandard = TWO_UNIT;
			} else if (checker == AM_ONE || checker == AM_TWO || checker == AM_THREE) {
				hourStandard = ONE_UNIT;
			}

			//get the numbers in front of the am, pm
			tempTime = tempTime.substr(START, sizeOne);

			if (isNumber(tempTime) && hourStandard == ZERO) {
				tempTime = EMPTY_STRING;
			}

			//following to check the hour standard for
			//8pm 7am(no space)
			string apm[SIX_UNIT] = { AM_ONE, AM_TWO, AM_THREE, 
				                     PM_ONE, PM_TWO, PM_THREE };

			unsigned int indicator = ZERO;

			while (!isNumber(tempTime) && indicator < SIX_UNIT) {
				unsigned int newPosition = tempTime.find(apm[indicator]);

				if (newPosition != string::npos) {
					string temp = tempTime.substr(START, newPosition);
					temp = convertToTime(temp);

					if (isNumber(temp)) {
						tempTime = temp;
						if (indicator < THREE_UNIT) {
							hourStandard = ONE_UNIT;
						} else {
							hourStandard = TWO_UNIT;
						}

						sizeTwo = sizeOne;
						break;
					}
					tempTime = temp;
				}

				indicator++;
			}

			tempTime = convertToTime(tempTime);

			if (hourStandard == ZERO) {
				sizeTwo = sizeOne;
				}

			//convert the thing infront of am, pm to hours. e.g 7 am to 0700
			if (isNumber(tempTime) && tempTime.size() == FOUR_UNIT && stoi(tempTime) < HOUR_ADDER) {
				Time = tempTime;

				if (hourStandard == ONE_UNIT || hourStandard == ZERO) {
					if (hourStandard == ONE_UNIT && (stoi(tempTime) >= HOUR_ADDER && stoi(tempTime) < ONE_PM)) {
						int TimeNumber = stoi(tempTime) - HOUR_ADDER;
						ostringstream ss;

						if (TimeNumber < TEN_UNIT) {
							ss << ZERO << ZERO << ZERO << TimeNumber;
						} else {
							ss << ZERO << ZERO << TimeNumber;
						}
						Time = ss.str();
					}
					chopInfo((*_uncategorizedInfo), position, sizeTwo + keyword.size());
					break;
				}

				if (hourStandard == TWO_UNIT && stoi(tempTime) < HOUR_ADDER) {
					int TimeNumber = std::stoi(tempTime);
					TimeNumber = HOUR_ADDER + TimeNumber;
					ostringstream ss;
					ss << TimeNumber;
					Time = ss.str();
					chopInfo((*_uncategorizedInfo), position, sizeTwo + keyword.size());
					break;
				}
			}
		}

		startPos = position + ONE_UNIT;

	} while (position != string::npos);

	return Time;
}

string TimeGetter::getTimeFromMorning(string Input, string keyword) {
	string Time = EMPTY_TIME;
	string tempTime;
	string checker;
	string duplicate = Input;
	unsigned int position, startPos = START, sizeOne;
	int hourStandard = ZERO, indicator = ZERO;

	changeToLowerCase(duplicate);

	do {
		position = duplicate.find(keyword, startPos);

		if (position != string::npos) {
			tempTime = duplicate.substr(position + keyword.size());

			while (Time == EMPTY_TIME && indicator < SEVEN_UNIT) {
				sizeOne = tempTime.find(NOON_STATUS[indicator]);

				if (sizeOne != string::npos) {
					Time = CORRESPONDING_TIME[indicator];
					chopInfo(*_uncategorizedInfo, position, position + 
						     NOON_STATUS[indicator].size() - ONE_UNIT);
					break;
				}

				indicator++;
			}
		}

		startPos = position + ONE_UNIT;

	} while (position != string::npos);

	indicator = ZERO;
	sizeOne = string::npos;

	//when there is no prepositions identified
	//e.g today morning
	if (Time == EMPTY_TIME && position == string::npos && keyword == AT) {
		while (Time == EMPTY_TIME && indicator < SEVEN_UNIT) {
			sizeOne = duplicate.find(NOON_STATUS[indicator]);

			//for the cases this morning
			if (sizeOne != string::npos) {
				int checkerOne = duplicate.find(THIS_STRING);
				int checkerTwo = duplicate.find(NEXT);
				int checkerThree = duplicate.find(THE);
				int checker = ZERO;

				Time = CORRESPONDING_TIME[indicator];

				if (checkerOne != string::npos && sizeOne - checkerOne == FIVE_UNIT) {
					sizeOne = checkerOne;
					checker = FOUR_UNIT;
				}

				if (checkerTwo != string::npos && sizeOne - checkerTwo == FIVE_UNIT) {
					sizeOne = checkerTwo;
					checker = FOUR_UNIT;
				}

				if (checkerThree != string::npos && sizeOne - checkerThree == FOUR_UNIT) {
					sizeOne = checkerThree;
					checker = THREE_UNIT;
				}

				if (checker != ZERO)
				{
					chopInfo(*_uncategorizedInfo, sizeOne, checker + NOON_STATUS[indicator].size());
					break;
				} else {
					chopInfo(*_uncategorizedInfo, sizeOne, NOON_STATUS[indicator].size() - ONE_UNIT);
					break;
				}
			}

			indicator++;
		}
	}

	return Time;
}

string TimeGetter::convertToTime(string tempTime) {
	int position = tempTime.find(COLON);
	string hour = EMPTY_STRING;
	string minute = EMPTY_STRING;

	if (position == string::npos) {
		position = tempTime.find(DOT);
	}

	if (position != string::npos) {
		hour = tempTime.substr(START, position - START);
		minute = tempTime.substr(position + ONE_UNIT);
	}

	if (isNumber(hour) && isNumber(minute) 
		&& hour != EMPTY_STRING && minute != EMPTY_STRING) {
		if (hour.size() == ONE_UNIT) {
			hour = ZERO_STRING + hour;
		}

		if (minute.size() == ONE_UNIT) {
			minute = minute + ZERO_STRING;
		}

		tempTime = hour + minute;
	}

	//when only a pure number striung is inputed
	//convert to time: eg. 8 to 0800
	if (isNumber(tempTime) && tempTime.size() <= TWO_UNIT && std::stoi(tempTime) <= 12) {
		if (tempTime.size() == ONE_UNIT) {
			tempTime = ZERO_STRING + tempTime + ZERO_STRING + ZERO_STRING;
		} else {
			tempTime = tempTime + ZERO_STRING + ZERO_STRING;
		}
	}

	return tempTime;
}
