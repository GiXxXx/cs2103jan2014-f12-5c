#include "TimeGetter.h"


TimeGetter::TimeGetter(string& uncategorizedInfo, string Command) :Tokenizer(uncategorizedInfo), command(Command){
}


TimeGetter::~TimeGetter(){
}

string TimeGetter::Tokenize(){
	string time = LargeTime, tempTime;
	unsigned int indicator = zero;

	if (command == Add || command == Edit){
		unsigned int posOne = (*uncategorizedInfo).find_first_not_of(space);
		unsigned int posTwo = (*uncategorizedInfo).find_first_of(space, posOne);

		if (posOne != string::npos){
			string checker = (*uncategorizedInfo).substr(posOne, posTwo - posOne);

			if (isNumber(checker) && checker.size() == FourUnit){
				time = checker;
				chopInfo(*uncategorizedInfo, posOne, checker.size());
			}
		}

		while (time == LargeTime && indicator < NineUnit){
			time = getTime(*uncategorizedInfo, preposition[indicator]);

			indicator++;
		}

		indicator = zero;

		while (time == LargeTime && indicator < NineUnit){
			time = getTimeFromMorning(*uncategorizedInfo, preposition[indicator]);

			indicator++;
		}
	}

	if (time == LargeTime && command == Edit){
		string checker = (*uncategorizedInfo).substr(start, FourUnit);
		if (isNumber(checker) && checker.size() == FourUnit){
			time = checker;
			*uncategorizedInfo = (*uncategorizedInfo).substr(FourUnit);
		}
	}

	return time;
}

string TimeGetter::getTime(string Input, string keyword){
	string Time = LargeTime, tempTime, checker, duplicate = Input;
	unsigned int position, startPos = start, sizeOne, sizeTwo;
	int hourStandard = zero;

	ChangeToLowerCase(duplicate);

	do{
		position = duplicate.find(keyword, startPos);

		if (position != string::npos){
			tempTime = duplicate.substr(position + keyword.size());
			sizeOne = tempTime.find_first_of(punctuationSet);
			sizeTwo = tempTime.find_first_of(punctuationSet, sizeOne + OneUnit);

			checker = tempTime.substr(sizeOne + OneUnit, sizeTwo - sizeOne - OneUnit);

			if (checker == pmOne || checker == pmTwo || checker == pmThree){
				hourStandard = TwoUnit;
			}

			if (checker == amOne || checker == amTwo || checker == amThree){
				hourStandard = OneUnit;
			}

			tempTime = tempTime.substr(start, sizeOne);

			if (isNumber(tempTime) && hourStandard == zero){
				tempTime = emptyString;
			}

			string apm[SixUnit] = { amOne, amTwo, amThree, pmOne, pmTwo, pmThree };
			unsigned int indicator = zero;

			while (!isNumber(tempTime) && indicator < SixUnit){
				unsigned int newPosition = tempTime.find(apm[indicator]);

				if (newPosition != string::npos){
					string temp = tempTime.substr(start, newPosition);
					temp = convertToTime(temp);

					if (isNumber(temp)){
						tempTime = temp;
						if (indicator < ThreeUnit){
							hourStandard = OneUnit;
						}
						else{
							hourStandard = TwoUnit;
						}

						sizeTwo = sizeOne;
						break;
					}
					tempTime = temp;
				}

				indicator++;
			}

			tempTime = convertToTime(tempTime);

			if (hourStandard == zero){
				sizeTwo = sizeOne;
				}

			if (isNumber(tempTime) && tempTime.size() == FourUnit && stoi(tempTime) < 2400){
				Time = tempTime;

				if (hourStandard == OneUnit || hourStandard == zero){
					if (hourStandard == OneUnit && (stoi(tempTime) >= 1200 && stoi(tempTime) < 1300)){
						int TimeNumber = stoi(tempTime) - 1200;
						ostringstream ss;
						if (TimeNumber < TenUnit){
							ss << zero << zero << zero << TimeNumber;
						}
						else{
							ss << zero << zero << TimeNumber;
						}
						Time = ss.str();
					}
					chopInfo((*uncategorizedInfo), position, sizeTwo + keyword.size());
					break;
				}

				if (hourStandard == TwoUnit && stoi(tempTime) < 1200){
					int TimeNumber = std::stoi(tempTime);
					TimeNumber = hourAdder + TimeNumber;
					ostringstream ss;
					ss << TimeNumber;
					Time = ss.str();
					chopInfo((*uncategorizedInfo), position, sizeTwo + keyword.size());
					break;
				}
			}
		}

		startPos = position + OneUnit;

	} while (position != string::npos);

	return Time;
}

string TimeGetter::getTimeFromMorning(string Input, string keyword){
	string Time = LargeTime, tempTime, checker, duplicate = Input;
	unsigned int position, startPos = start, sizeOne;
	int hourStandard = zero, indicator = zero;

	ChangeToLowerCase(duplicate);

	do{
		position = duplicate.find(keyword, startPos);

		if (position != string::npos){
			tempTime = duplicate.substr(position + keyword.size());

			while (Time == LargeTime && indicator < SevenUnit){
				sizeOne = tempTime.find(NoonStatus[indicator]);

				if (sizeOne != string::npos){
					Time = correspondingTime[indicator];
					chopInfo(*uncategorizedInfo, position, position + NoonStatus[indicator].size() - OneUnit);
					break;
				}

				indicator++;
			}
		}

		startPos = position + OneUnit;

	} while (position != string::npos);

	indicator = zero;
	sizeOne = string::npos;

	if (Time == LargeTime && position == string::npos && keyword == at){
		while (Time == LargeTime && indicator < SevenUnit){
			sizeOne = duplicate.find(NoonStatus[indicator]);

			if (sizeOne != string::npos){
				int checkerOne = duplicate.find(This);
				int checkerTwo = duplicate.find(Next);
				int checkerThree = duplicate.find(The);
				int checker = zero;

				Time = correspondingTime[indicator];

				if (checkerOne != string::npos && sizeOne - checkerOne == FiveUnit){
					sizeOne = checkerOne;
					checker = FourUnit;
				}

				if (checkerTwo != string::npos && sizeOne - checkerTwo == FiveUnit){
					sizeOne = checkerTwo;
					checker = FourUnit;
				}

				if (checkerThree != string::npos && sizeOne - checkerThree == FourUnit){
					sizeOne = checkerThree;
					checker = ThreeUnit;
				}

				if (checker != zero)
				{
					chopInfo(*uncategorizedInfo, sizeOne, checker + NoonStatus[indicator].size());
					break;
				}
				else{
					chopInfo(*uncategorizedInfo, sizeOne, NoonStatus[indicator].size() - OneUnit);
					break;
				}
			}

			indicator++;
		}
	}

	return Time;
}

string TimeGetter::convertToTime(string tempTime){
	int position = tempTime.find(colon);
	string hour = emptyString, minute = emptyString;

	if (position == string::npos) {
		position = tempTime.find(dot);
	}

	if (position != string::npos) {
		hour = tempTime.substr(start, position - start);
		minute = tempTime.substr(position + OneUnit);
	}

	if (isNumber(hour) && isNumber(minute) && hour != emptyString && minute != emptyString){
		if (hour.size() == OneUnit){
			hour = Zero + hour;
		}

		if (minute.size() == OneUnit){
			minute = minute + Zero;
		}

		tempTime = hour + minute;
	}

	if (isNumber(tempTime) && tempTime.size() <= TwoUnit && std::stoi(tempTime) <= 12){
		if (tempTime.size() == OneUnit){
			tempTime = Zero + tempTime + Zero + Zero;
		}
		else{
			tempTime = tempTime + Zero + Zero;
		}
	}

	return tempTime;
}
