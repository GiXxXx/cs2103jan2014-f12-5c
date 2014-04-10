#include "stdafx.h"
#include "CppUnitTest.h"
//@author A0101540A
#include "AddTask.h"
#include "Command.h"
#include "CommandGetter.h"
#include "DataStorage.h"
#include "DateGetter.h"
#include "DeleteTask.h"
#include "EditTask.h"
#include "EventGetter.h"
#include "Identifier.h"
#include "KeywordGetter.h"
#include "MarkTask.h"
#include "SearchTask.h"
#include "StatusGetter.h"
#include "Task.h"
#include "TaskNumGetter.h"
#include "TextUI.h"
#include "TimeGetter.h"
#include "Tokenizer.h"
#include "VeriTask.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2 {		

	TEST_CLASS(UnitTest1) {
	public:

		//@author A0100008H
		TEST_METHOD(testMonthConverter) {
			string testUserInput = "a test string for DateGetter methods";
			string testCommand = "add";
			DateGetter testDateGetter(testUserInput,testCommand );
			//test MonthConverter for different input of January
			string testMonthJan1 = "january";
			string expectedMonthOutputJan = "1";
			testDateGetter.MonthConvertor(testMonthJan1);
			Assert::AreEqual(expectedMonthOutputJan,testMonthJan1);

			string testMonthJan2 = jan;
			testDateGetter.MonthConvertor(testMonthJan2);
			Assert::AreEqual(expectedMonthOutputJan,testMonthJan2);

			//test MonthConvertor for different input of August
			string testMonthAug1 = "august";
			string expectedMonthOutputAug = "8";
			testDateGetter.MonthConvertor(testMonthAug1);
			Assert::AreEqual(expectedMonthOutputAug,testMonthAug1);

			string testMonthAug2 = aug;
			testDateGetter.MonthConvertor(testMonthAug2);
			Assert::AreEqual(expectedMonthOutputAug,testMonthAug2);
			testDateGetter.~DateGetter();
		}

		TEST_METHOD(testWeekConvertor) {
			string testUserInput = "a test string for DateGetter methods";
			string testCommand = "add";
			DateGetter testDateGetter(testUserInput,testCommand );

			//test WeekConvertor for Monday
			string expectedWeekOutputMon = "0";
			string testWeekMon1 = "Monday";
			testDateGetter.WeekConvertor(testWeekMon1);
			Assert::AreEqual(expectedWeekOutputMon,testWeekMon1);

			string testWeekMon2 = "mon";
			testDateGetter.WeekConvertor(testWeekMon2);
			Assert::AreEqual(expectedWeekOutputMon,testWeekMon2);

			//test WeekConvertor for Thursday
			string expectedWeekOutputThu = "3";
			string testWeekThu1 = "thursday";
			testDateGetter.WeekConvertor(testWeekThu1);
			Assert::AreEqual(expectedWeekOutputThu,testWeekThu1);

			string testWeekThu2 = "thu";
			testDateGetter.WeekConvertor(testWeekThu2);
			Assert::AreEqual(expectedWeekOutputThu,testWeekThu2);

			testDateGetter.~DateGetter();
		}

		TEST_METHOD(testGetDateForBeforeAfter) {
			string testUserInput = "a test string for DateGetter methods";
			string testCommand = "add";
			DateGetter testDateGetter(testUserInput,testCommand );

			//test before the first day of a year
			string testDate1 = "20150101";
			string expectedOutputDate1 = "20141231";
			testDateGetter.GetDateForBeforeAfter(testDate1, before);
			Assert::AreEqual(expectedOutputDate1,testDate1);

			//test before someday in the middle of a year
			string testDate2 = "20140719";
			string expectedOutputDate2 = "20140718";
			testDateGetter.GetDateForBeforeAfter(testDate2, before);
			Assert::AreEqual(expectedOutputDate2,testDate2);

			//test after last day of a year
			string testDate3 = "20151231";
			string expectedOutputDate3 = "20160101";
			testDateGetter.GetDateForBeforeAfter(testDate3, after);
			Assert::AreEqual(expectedOutputDate3,testDate3);

			testDateGetter.~DateGetter();
		}

		TEST_METHOD(testDateConverter) {
			string testUserInput = "a test string for DateGetter methods";
			string testCommand = "add";
			DateGetter testDateGetter(testUserInput,testCommand);

			string actualOutput1 = testDateGetter.DateConverter(2015,11,15);
			string expectedOutput1 = "20151115";
			Assert::AreEqual(expectedOutput1,actualOutput1);

			string actualOutput2 = testDateGetter.DateConverter(2016, 4, 7);
			string expectedOutput2 = "20160407";
			Assert::AreEqual(expectedOutput2,actualOutput2);

			testDateGetter.~DateGetter();
		}

		TEST_METHOD(testGetDateFromDate) {
			//test a input with slash
			string testUserInput1 = "a test string for DateGetter methods: go home on 2014/05/05";
			string testCommand = "add";
			DateGetter testDateGetter1(testUserInput1,testCommand);

			string actualOutputDate1 = testDateGetter1.GetDateFromDate(testUserInput1, on);
			string expectedOutputDate1 = "20140505";
			Assert::AreEqual(expectedOutputDate1,actualOutputDate1);
			testDateGetter1.~DateGetter();

			//test a more flexible input
			string testUserInput2 = "a test string for DateGetter methods: go home on 07 May 2014";
			DateGetter testDateGetter2(testUserInput2,testCommand);

			string actualOutputDate2 = testDateGetter2.GetDateFromDate(testUserInput2, on);
			string expectedOutputDate2 = "20140507";
			Assert::AreEqual(expectedOutputDate2,actualOutputDate2);
			testDateGetter1.~DateGetter();
		}

		TEST_METHOD(testGetDateFromWeek) {
			//expected output for this test is subject to change in time
			string testUserInput1 = "a test string for DateGetter methods: go home on Sunday";
			string testCommand = "add";
			DateGetter testDateGetter1(testUserInput1,testCommand);

			string actualOutputDate1 = testDateGetter1.GetDateFromWeek(testUserInput1, on);
			string expectedOutputDate1 = "20140413";
			Assert::AreEqual(expectedOutputDate1,actualOutputDate1);

			string testUserInput2 = "a test string for DateGetter methods: go home on next Monday";
			DateGetter testDateGetter2(testUserInput2,testCommand);
			string actualOutputDate2 = testDateGetter2.GetDateFromWeek(testUserInput2, on);
			string expectedOutputDate2 = "20140414";
			Assert::AreEqual(expectedOutputDate2,actualOutputDate2);

			testDateGetter1.~DateGetter();
			testDateGetter2.~DateGetter();
		}

		TEST_METHOD(testDateConvertFromDescription) {
			string testUserInput1 = "a test string for DateGetter methods";
			string testCommand = "add";
			DateGetter testDateGetter1(testUserInput1,testCommand);

			string actualOutputDate1 = testDateGetter1.DateConvertorFromDescription(dayAfterTmr, space);
			string expectedOutputDate1 = "20140411";
			Assert::AreEqual(expectedOutputDate1,actualOutputDate1);

			//assume as 30 days
			string actualOutputDate2 = testDateGetter1.DateConvertorFromDescription(month, "2");
			string expectedOutputDate2 = "20140608";
			Assert::AreEqual(expectedOutputDate2,actualOutputDate2);

			testDateGetter1.~DateGetter();
		}
		
		TEST_METHOD(testGetDateFromDescriptionOne) {
			//expected output for this test is subject to change in time
			string testUserInput1 = "a test string for DateGetter methods: finish revision by 2 weeks";
			string testCommand = "add";
			DateGetter testDateGetter1(testUserInput1,testCommand);

			string actualOutputDate1 = testDateGetter1.GetDateFromDescriptionOne(testUserInput1, by);
			string expectedOutputDate1 = "20140423";
			Assert::AreEqual(expectedOutputDate1,actualOutputDate1);


			string testUserInput2 = "a test string for DateGetter methods: finish revision in one month";
			DateGetter testDateGetter2(testUserInput2,testCommand);

			string actualOutputDate2 = testDateGetter2.GetDateFromDescriptionOne(testUserInput2, in);
			string expectedOutputDate2 = "20140509";
			Assert::AreEqual(expectedOutputDate2,actualOutputDate2);

			testDateGetter1.~DateGetter();
			testDateGetter2.~DateGetter();
		}

		TEST_METHOD(testGetDateFromDescriptionTwo) {
			//expected output for this test is subject to change in time
			string testUserInput1 = "a test string for DateGetter methods: finish revision on tomorrow";
			string testCommand = "add";
			DateGetter testDateGetter1(testUserInput1,testCommand);

			string actualOutputDate1 = testDateGetter1.GetDateFromDescriptionTwo(testUserInput1, on);
			string expectedOutputDate1 = "20140410";
			Assert::AreEqual(expectedOutputDate1,actualOutputDate1);


			string testUserInput2 = "a test string for DateGetter methods: finish revision after tomorrow";
			//string testCommand = "add";
			DateGetter testDateGetter2(testUserInput2,testCommand);

			string actualOutputDate2 = testDateGetter2.GetDateFromDescriptionTwo(testUserInput2, after);
			string expectedOutputDate2 = "20140410";
			Assert::AreEqual(expectedOutputDate2,actualOutputDate2);

			testDateGetter1.~DateGetter();
			testDateGetter2.~DateGetter();
		}

		TEST_METHOD(testGetDateFromFestival) {
			//test with national day
			string testUserInput1 = "a test string for DateGetter methods: watch celebration on national day with family";
			string testCommand = "add";
			DateGetter testDateGetter1(testUserInput1,testCommand);

			string actualOutputDate1 = testDateGetter1.GetDateFromFestival(testUserInput1, on);
			string expectedOutputDate1 = "20140809";
			Assert::AreEqual(expectedOutputDate1,actualOutputDate1);

			//test with christmas day
			string testUserInput2 = "a test string for DateGetter methods: prepare gifts by xmas day";
			DateGetter testDateGetter2(testUserInput2,testCommand);

			string actualOutputDate2 = testDateGetter2.GetDateFromFestival(testUserInput2, by);
			string expectedOutputDate2 = "20141225";
			Assert::AreEqual(expectedOutputDate2,actualOutputDate2);

			testDateGetter1.~DateGetter();
			testDateGetter2.~DateGetter();
		}

		TEST_METHOD(testDateGetterTokneize) {
			//test a normal case where date info exists
			string testUserInput1 = " a test string for TimeGetter methods: before 2014/04/10, v0.4 for CS2103 must be finshied";
			string testCommand = "add";
			DateGetter testDateGetter1(testUserInput1, testCommand);

			string actualOutputDate1 = testDateGetter1.Tokenize();
			string expectedOutputDate1 = "20140409";
			Assert::AreEqual(expectedOutputDate1,actualOutputDate1);

			//test a case where no date info available
			string testUserInput2 = " a test string for TimeGetter methods: send the proposal before 21:00";
			DateGetter testDateGetter2(testUserInput2,testCommand);
			
			string actualOutputDate2 = testDateGetter2.Tokenize();
			string expectedOutputDate2 = "        ";
			Assert::AreEqual(expectedOutputDate2,actualOutputDate2);

			testDateGetter1.~DateGetter();
			testDateGetter2.~DateGetter();
		}

		//test TimeGetter.h , 3 tests with multiple cases each.
		TEST_METHOD(testGetTime) {
			//test a normal case with standard time format
			string testUserInput1 = "a test string for TimeGetter methods: submit assignment by 12:00";
			string testCommand = "add";
			TimeGetter testTimeGetter1(testUserInput1, testCommand);

			string actualOutputTime1 = testTimeGetter1.getTime(testUserInput1, by);
			string expectedOutputTime1 = "1200";
			Assert::AreEqual(expectedOutputTime1,actualOutputTime1);

			//test a normal case with abbreiviated format
			string  testUserInput2 = "a test string for TimeGetter methods: submit assignment by 8pm";
			TimeGetter testTimeGetter2(testUserInput2,testCommand);

			string actualOutputTime2 = testTimeGetter2.getTime(testUserInput2,by);
			string expectedOutputTime2 = "2000";
			Assert::AreEqual(expectedOutputTime2,actualOutputTime2);

			//test a case with no time info available
			string  testUserInput3 = "a test string for TimeGetter methods: do not forget to do buy gift for mom's birthday";
			TimeGetter testTimeGetter3(testUserInput3,testCommand);

			string actualOutputTime3 = testTimeGetter3.getTime(testUserInput3,by);
			string expectedOutputTime3 = "    ";
			Assert::AreEqual(expectedOutputTime3,actualOutputTime3);
			
			testTimeGetter1.~TimeGetter();
			testTimeGetter2.~TimeGetter();
			testTimeGetter3.~TimeGetter();
		}

		TEST_METHOD(testConvertToTime) {
			string testUserInput1 = "a test string for TimeGetter methods";
			string testCommand = "add";
			TimeGetter testTimeGetter(testUserInput1, testCommand);

			string actualOutputTime1 = testTimeGetter.convertToTime("2014");
			string expectedOutputTime1 = "2014";
			Assert::AreEqual(expectedOutputTime1, actualOutputTime1);

			string actualOutputTime2 = testTimeGetter.convertToTime("20:14");
			string expectedOutputTime2 = "2014";
			Assert::AreEqual(expectedOutputTime2, actualOutputTime2);

			string actualOutputTime3 = testTimeGetter.convertToTime("8");
			string expectedOutputTime3 = "0800";
			Assert::AreEqual(expectedOutputTime3, actualOutputTime3);
			/*
			string actualOutputTime6 = testTimeGetter.convertToTime("9:10");
			string expectedOutputTime6 = "0910";
			Assert::AreEqual(expectedOutputTime6, actualOutputTime6);
			*/
			testTimeGetter.~TimeGetter();

		}

		TEST_METHOD(testTimeGetterTokenize) {
			string testUserInput1 = "a test string for TimeGetter methods: set up unit test by 10p.m today";
			string testCommand = "add";
			TimeGetter testTimeGetter1(testUserInput1, testCommand);

			string actualOutPutTime1 = testTimeGetter1.Tokenize();
			string expectedOutputTime1 = "2200";
			Assert::AreEqual(expectedOutputTime1, actualOutPutTime1);

			string testUserInput2 = "a test string for TimeGetter methods: set up unit test by 22:00";
			TimeGetter testTimeGetter2(testUserInput2,testCommand);

			string actualOutPutTime2 = testTimeGetter2.Tokenize();
			string expectedOutputTime2 = "2200";
			Assert::AreEqual(expectedOutputTime2,actualOutPutTime2);

			testTimeGetter1.~TimeGetter();
			testTimeGetter2.~TimeGetter();
		}
		
		//test CommandGetter.h
		TEST_METHOD(testCommandGetterTokenize) {
			//test command add
			string testUserInput1 = "add have a meeting tonight";
			CommandGetter testCommandGetter1(testUserInput1);

			string actualCommand1 = testCommandGetter1.Tokenize();
			string expectedCommand1 = Add;
			Assert::AreEqual(expectedCommand1, actualCommand1);

			//test command search
			string testUserInput2 = "search apply for hostel";
			CommandGetter testCommandGetter2(testUserInput2);

			string actualCommand2 = testCommandGetter2.Tokenize();
			string expectedCommand2 = Search;
			Assert::AreEqual(expectedCommand2,actualCommand2);

			//test command edit
			string testUserInput3 = "edit 2 go home by 3pm";
			CommandGetter testCommandGetter3(testUserInput3);

			string actualCommand3 = testCommandGetter3.Tokenize();
			string expectedCommand3 = Edit;
			Assert::AreEqual(expectedCommand3,actualCommand3);

			//test command mark
			string testUserInput4 = "mark 1 done";
			CommandGetter testCommandGetter4(testUserInput4);

			string actualCommand4 = testCommandGetter4.Tokenize();
			string expectedCommand4 = Mark;
			Assert::AreEqual(expectedCommand4,actualCommand4);

			//test command delete
			string testUserInput5 = "delete 5";
			CommandGetter testCommandGetter5(testUserInput5);

			string actualCommand5 = testCommandGetter5.Tokenize();
			string expectedCommand5 = Delete;
			Assert::AreEqual(expectedCommand5,actualCommand5);

			testCommandGetter1.~CommandGetter();
			testCommandGetter2.~CommandGetter();
			testCommandGetter3.~CommandGetter();
			testCommandGetter4.~CommandGetter();
			testCommandGetter5.~CommandGetter();
		}

		//test EventGetter.h
		TEST_METHOD(testEventGetterTokenize) {
			//test with unwanted spaces
			string testUserInput1 = "   go home, take a shower, and do my homework!";
			EventGetter testEventGetter1(testUserInput1, Add);
			
			string actualEvent1 = testEventGetter1.Tokenize();
			string expectedEvent1 = "go home, take a shower, and do my homework!";
			Assert::AreEqual(expectedEvent1,actualEvent1);

			//test with unwanted symbols 
			string testUserInput2 = "   ,,.go home, take a shower, and do my homework!";
			EventGetter testEventGetter2(testUserInput2, Add);
			
			string actualEvent2 = testEventGetter2.Tokenize();
			string expectedEvent2 = "go home, take a shower, and do my homework!";
			Assert::AreEqual(expectedEvent2,actualEvent2);

			testEventGetter1.~EventGetter();
			testEventGetter2.~EventGetter();
		}

		//test keywordGetter.h
		TEST_METHOD(testKeywordGetterTokenize) {
			string testUserInput = "   myKey";
			KeywordGetter testKeywordGetter(testUserInput, Search);

			string actualKeyword = testKeywordGetter.Tokenize();
			string expectedKeyword = "myKey";
			Assert::AreEqual(expectedKeyword,actualKeyword);
			testKeywordGetter.~KeywordGetter();
		}

		//test statusGetter.h
		TEST_METHOD(testStatusGetterTokenize) {
			//with mark done
			string testUserInput1 = "   done";
			StatusGetter testStatusGetter1(testUserInput1, Mark);

			string actualKeyword1 = testStatusGetter1.Tokenize();
			string expectedKeyword1 = "done";
			Assert::AreEqual(expectedKeyword1,actualKeyword1);

			//with mark cannot done
			string testUserInput2 = "   cannot be done";
			StatusGetter testStatusGetter2(testUserInput2, Mark);

			string actualKeyword2 = testStatusGetter2.Tokenize();
			string expectedKeyword2 = "cannot be done";
			Assert::AreEqual(expectedKeyword2,actualKeyword2);
			
			testStatusGetter1.~StatusGetter();
			testStatusGetter2.~StatusGetter();
		}

		//test TaskNumGetter.h
		TEST_METHOD(testTaskNumGetterTokenize) {
			string testUserInput1 = "   4";
			TaskNumGetter testTaskNumGetter1(testUserInput1, Mark);

			string actualKeyword1 = testTaskNumGetter1.Tokenize();
			string expectedKeyword1 = "4";
			Assert::AreEqual(expectedKeyword1,actualKeyword1);
		}

		//test tokenizer.h
		TEST_METHOD(testchopInfo) {
			string testUserInput = "a test string for Tokenizer.h methods";
			Tokenizer testTokenizer(testUserInput);
			int midPosition = 2;
			
			//test when within input size
			int size1 = 7;
			string testString = "a string to test the chopinfo method";
			testTokenizer.chopInfo(testString, midPosition, size1);
			string expectedInfo1 = "a to test the chopinfo method";
			Assert::AreEqual(expectedInfo1,testString);

			//test when beyond input size
			int size2 = 100;
			testTokenizer.chopInfo(testString, midPosition, size2);
			string expectedInfo2 = "a ";
			Assert::AreEqual(expectedInfo2,testString);

			testTokenizer.~Tokenizer();
		}
		TEST_METHOD(testIsNumber) {
			string testUserInput = "a test string for Tokenizer.h methods";
			Tokenizer testTokenizer(testUserInput);
			//test using a number
			string testNumber1 = "2014";
			Assert::IsTrue(testTokenizer.isNumber(testNumber1));

			//test using a non-number
			string testNumber2 = "Non-number";
			Assert::IsFalse(testTokenizer.isNumber(testNumber2));

			testTokenizer.~Tokenizer();
		}
		TEST_METHOD(testChangeDoubleDigit) {
			string testUserInput = "a test string for Tokenizer.h methods";
			Tokenizer testTokenizer(testUserInput);

			//test with a single digit number
			string testNumber1 = "5";
			string expectedNumber1 = "05";
			testTokenizer.ChangeDoubleDigit(testNumber1);
			Assert::AreEqual(expectedNumber1,testNumber1);

			//test with multiple digit number
			string testNumber2 = "100";
			string expectedNumber2 = "100";
			testTokenizer.ChangeDoubleDigit(testNumber2);
			Assert::AreEqual(expectedNumber2,testNumber2);

			testTokenizer.~Tokenizer();
		}

		TEST_METHOD(testChangeToLowerCase) {
			string testUserInput = "a test string for Tokenizer.h methods";
			Tokenizer testTokenizer(testUserInput);

			//test with all upper case
			string testString1 = "THIS IS A UPPER-CASE STRING.";
			testTokenizer.ChangeToLowerCase(testString1);
			string expectedString1 = "this is a upper-case string.";
			Assert::AreEqual(expectedString1,testString1);

			//test will mix
			string testString2 = "THis Is a MIXED-CASE STrInG.";
			testTokenizer.ChangeToLowerCase(testString2);
			string expectedString2 = "this is a mixed-case string.";
			Assert::AreEqual(expectedString2,testString2);

			testTokenizer.~Tokenizer();
		}
		
		//@author A0101540A
		TEST_METHOD(testAddTimedTask) {
			//integration test for the addition of a timed task, using Identifier class
			//tests for correct initialisation of Task member attributes
			//tests correct order of two timed tasks in data storage
			//tests correct order of timed task and deadline task in data storage
			//tests correct order of timed task and floating task in data storage

			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			Identifier TestInfoIdentifier;
	     	DataStorage _TestdataStorage("testAddTimedTask.txt");
			VeriTask TaskManager(_TestdataStorage);
			TextUI textUI;
						
			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue(_TestdataStorage.retrieveTaskList().empty()); 
			
			TestInfoIdentifier.Identify(TestUserInput);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
			
			//post-condition: data storage no longer empty after add
			Assert::IsFalse(_TestdataStorage.retrieveTaskList().empty());
			
			//check that member data attributes are initialised correctly for timed task
			Task test1 = ((_TestdataStorage.retrieveTaskList()).front());

			string str1 = "20110531";
			Assert::AreEqual(test1.getDate(), str1);

			string str2 = "1930";
			Assert::AreEqual(test1.getStartTime(), str2);

			string str3 = "2200";
			Assert::AreEqual(test1.getEndTime(), str3);

			string str4 = "stargazing session";
			Assert::AreEqual(test1.getEvent(), str4);

			unsigned long long ID1 = 2011053119302200000;
			Assert::AreEqual(ID1, test1.getID());
			
			//check that task has been added in correct order, comparing 2 timed tasks
			string TestUserInput2 = "add birthday party on 01/03/2011 from 08:00 to 17:00";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
			
			Task test2 = ((_TestdataStorage.retrieveTaskList()).front());
			string str5 = "birthday party";
			Assert::AreEqual(str5, test2.getEvent());

			//check that task has been added in correct order, comparing timed & deadline tasks
			string TestUserInput3 = "add settle accounts by 01/04/2014";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
		
			Task test3 = ((_TestdataStorage.retrieveTaskList()).back());
			string str6 = "settle accounts";
			Assert::AreEqual(str6, test3.getEvent());

			//check that task has been added in correct order, comparing timed & floating tasks
			string TestUserInput4 = "add arrange music score";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);

			string TestUserInput5 = "add finish rearrangement by 02/04/2014 from 08:00 to 12:00";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
			
			Task test4 = ((_TestdataStorage.retrieveTaskList()).back());
			string str7 = "arrange music score";
			Assert::AreEqual(str7, test4.getEvent());

			TaskManager.~VeriTask();
		}
		
		TEST_METHOD(testAddDeadlineTask) {
			//integration test for the addition of a deadline task, using Identifier class
			//tests for correct initialisation of Task member attributes
			//tests correct order of two deadline tasks in data storage
			//tests correct order of deadline task and floating task in data storage

			string InputADT = "add see sunrise by 19/05/2011";
	
			Identifier IdentifierADT;
	     	DataStorage _TestdataStorage("testAddDeadlineTask.txt");
			VeriTask TaskManager(_TestdataStorage);
			TextUI textUI;

			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue(_TestdataStorage.retrieveTaskList().empty()); 

			IdentifierADT.Identify(InputADT);
			TaskManager.pushCommand(IdentifierADT.GetCommand(), IdentifierADT, textUI, _TestdataStorage);
	
			//post-condition: data storage no longer empty after add
			Assert::IsFalse(_TestdataStorage.retrieveTaskList().empty());

			Task test1 = ((_TestdataStorage.retrieveTaskList()).front());

			//check that attributes have been initialised correctly for deadline tasks
			string str1 = "20110519";
			Assert::AreEqual(str1, test1.getDate());

			string str2 = "    ";
			Assert::AreEqual(str2, test1.getStartTime());

			string str3 = "    ";
			Assert::AreEqual(str3, test1.getEndTime());

			string str4 = "see sunrise";
			Assert::AreEqual(str4, test1.getEvent());

			//don't test ID first
			/* unsigned long long ID2 = 2011051999999999;
			Assert::AreEqual(test1.getID(), ID2); */
			
			//check that task has been added in correct order, comparing 2 deadline tasks
			string InputADT2 = "add see sunset by 01/03/2011";
			IdentifierADT.Identify(InputADT2);
			TaskManager.pushCommand(IdentifierADT.GetCommand(), IdentifierADT, textUI, _TestdataStorage);
			
			Task test2 = ((_TestdataStorage.retrieveTaskList()).front());
			string str5 = "see sunset";
			Assert::AreEqual(str5, test2.getEvent());	

			//check that task has been added in correct order, comparing deadline & floating tasks
			string InputADT3 = "add watch Ghibli";
			IdentifierADT.Identify(InputADT3);
			TaskManager.pushCommand(IdentifierADT.GetCommand(), IdentifierADT, textUI, _TestdataStorage);

			string InputADT4 = "add see midnight by 19/03/2011";
			IdentifierADT.Identify(InputADT4);
			TaskManager.pushCommand(IdentifierADT.GetCommand(), IdentifierADT, textUI, _TestdataStorage);

			Task test3 = ((_TestdataStorage.retrieveTaskList()).back());
			string str6 = "watch Ghibli";
			Assert::AreEqual(str6, test3.getEvent());

			TaskManager.~VeriTask();
		} 

		TEST_METHOD(testAddFloatingTask) {
			//integration test for the addition of a floating task, using Identifier class
			//tests for correct initialisation of Task member attributes
			//tests correct order of two floating tasks in data storage

			string TestAFT = "add move house";
			Identifier TestInfoIdentifier1;
	     	DataStorage _TestdataStorage("testAddFloatingTask.txt");
			VeriTask TaskManager1(_TestdataStorage);
			TextUI textUI;
			
			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue(_TestdataStorage.retrieveTaskList().empty()); 

			TestInfoIdentifier1.Identify(TestAFT);
			TaskManager1.pushCommand(TestInfoIdentifier1.GetCommand(), TestInfoIdentifier1, textUI, _TestdataStorage);
		
			//post-condition: data storage no longer empty after add
			Assert::IsFalse(_TestdataStorage.retrieveTaskList().empty());
			
			//check that attributes have been initialised correctly for floating tasks
			Task test1 = ((_TestdataStorage.retrieveTaskList()).front());

			string str1 = "move house";
			Assert::AreEqual(test1.getEvent(), str1);

			string str2 = "    ";
			Assert::AreEqual(test1.getStartTime(), str2);
			Assert::AreEqual(test1.getEndTime(), str2);
			string str3 = "        ";
			Assert::AreEqual(test1.getDate(), str3);

			unsigned long long ID3 = 9999999999999999000;
			Assert::AreEqual(test1.getID(), ID3);

			//to-do: check for initialisation of 2nd floating task ID
			
			//check that task has been added in correct order, comparing 2 floating tasks
			string TestAFT2 = "add shift furniture";
			TestInfoIdentifier1.Identify(TestAFT2);
			TaskManager1.pushCommand(TestInfoIdentifier1.GetCommand(), TestInfoIdentifier1, textUI, _TestdataStorage);
			
			Task test2 = ((_TestdataStorage.retrieveTaskList()).back());
			string str5 = "shift furniture";
			Assert::AreEqual(test2.getEvent(), str5);

			TaskManager1.~VeriTask();
		}

		TEST_METHOD(testSearch) {
			//integration test for search, using Identifier class and Add class
			//search only by event description
			//empty search
			//negative search
			//positive search: single result, multiple results

			Identifier TestInfoIdentify;
	     	DataStorage _TestdataStorageS("testSearch.txt");
			VeriTask TaskManagerS(_TestdataStorageS);
			TextUI textUI;
			
			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue((_TestdataStorageS.retrieveTaskList().empty()));
			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());

			//empty search
			string emptysearch = "search growlithe";
			TestInfoIdentify.Identify(emptysearch);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);
			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());
		
			//add first task
			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			TestInfoIdentify.Identify(TestUserInput);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);

			//check that data storage no longer empty upon add
			Assert::IsFalse((_TestdataStorageS.retrieveTaskList()).empty());

			//negative search
			string NegSearch1 = "search sunset";
			TestInfoIdentify.Identify(NegSearch1);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);

			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());

			string NegSearch2 = "search 23/05/2011";
			TestInfoIdentify.Identify(NegSearch1);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);

			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());

			string NegSearch3 = "search 19:00";
			TestInfoIdentify.Identify(NegSearch1);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);

			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());

			//positive search: single result
			string PosSearch1 = "search stargazing";
			TestInfoIdentify.Identify(PosSearch1);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);
			Assert::IsFalse((_TestdataStorageS.retrieveTaskListToDisplay()).empty());
			Task testS = ((_TestdataStorageS.retrieveTaskListToDisplay()).front());
			string str1S = "stargazing session";
			Assert::AreEqual(testS.getEvent(), str1S); 

			//positive search: multiple results
			string PS1 = "add chorale training on 31/07/2011 from 19:30 to 22:00";
			TestInfoIdentify.Identify(PS1);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);
			string PS2 = "add track training on 01/07/2011 from 19:30 to 22:00";
			TestInfoIdentify.Identify(PS2);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);
			string PS3 = "add finish training by 31/07/2012";
			TestInfoIdentify.Identify(PS3);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);
			string PS4 = "add baking on 31/06/2011";
			TestInfoIdentify.Identify(PS4);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);
			string PosSearch2 = "search training";
			TestInfoIdentify.Identify(PosSearch2);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, _TestdataStorageS);
			
			unsigned int vectorsize = 3;
			Assert::AreEqual(vectorsize, _TestdataStorageS.retrieveTaskListToDisplay().size()); 

			TaskManagerS.~VeriTask();
		}
		
		TEST_METHOD(testEditTimedTask) {
			//integration test for editing a timed task, using Identifier, Add and Search classes
			//Note: floating task can be changed to deadline and timed task, and all other type changes are allowed

			//initialise task
			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			Identifier TestETTIdentifier;
	     	DataStorage _TestdataStorageETT("testEditTimedTask.txt");
			VeriTask TaskManagerETT(_TestdataStorageETT);
			TextUI textUI;

			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue((_TestdataStorageETT.retrieveTaskList().empty()));
			Assert::IsTrue((_TestdataStorageETT.retrieveTaskListToDisplay()).empty());

			TestETTIdentifier.Identify(TestUserInput);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI,_TestdataStorageETT);
			
			//check that data storage no longer empty upon add
			Assert::IsFalse((_TestdataStorageETT.retrieveTaskList()).empty());

			string SearchCommand = "search stargazing";
			TestETTIdentifier.Identify(SearchCommand);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, _TestdataStorageETT);

			//ensure positive search
			Assert::IsFalse((_TestdataStorageETT.retrieveTaskListToDisplay()).empty());

			//edit timed task attributes
			string TestUserInput2 = "edit 1 sunset";
			TestETTIdentifier.Identify(TestUserInput2);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, _TestdataStorageETT);
			
			Task test2 = ((_TestdataStorageETT.retrieveTaskListToDisplay()).front());
			string str1 = "sunset";
			Assert::AreEqual(test2.getEvent(), str1);

			string TestUserInput3 = "edit 1 on 01/03/2011";
			TestETTIdentifier.Identify(TestUserInput3);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, _TestdataStorageETT);
			string str2 = "20110301";
			Task test3 = ((_TestdataStorageETT.retrieveTaskListToDisplay()).front());
			Assert::AreEqual(test3.getDate(), str2);

			string TestUserInput4 = "edit 1 from 12:00";
			TestETTIdentifier.Identify(TestUserInput4);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, _TestdataStorageETT);
			string str3 = "1200";
			Task test4 = ((_TestdataStorageETT.retrieveTaskListToDisplay()).front());
			Assert::AreEqual(test4.getStartTime(), str3);

			string TestUserInput5 = "edit 1 at 19:00";
			TestETTIdentifier.Identify(TestUserInput5);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, _TestdataStorageETT);
			string str4 = "1900";
			Task test5 = ((_TestdataStorageETT.retrieveTaskListToDisplay()).front());
			Assert::AreEqual(test5.getStartTime(), str4);

			string TestUserInput7 = "edit 1 from 19:30 to 03:00";
			TestETTIdentifier.Identify(TestUserInput7);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, _TestdataStorageETT);
			string str7 = "0300";
			Task test6 = ((_TestdataStorageETT.retrieveTaskListToDisplay()).front());
			Assert::AreEqual(test6.getEndTime(), str7);

			//test edit of multiple attributes and unordered data attribute input
			string TestUserInput6 = "edit 1 fireworks from 17:00";
			TestETTIdentifier.Identify(TestUserInput6);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, _TestdataStorageETT);
			Task test7 = ((_TestdataStorageETT.retrieveTaskListToDisplay()).front());
			string str5 = "1700";
			Assert::AreEqual(test7.getStartTime(), str5);
			string str6 = "fireworks";
			Assert::AreEqual(test7.getEvent(), str6);

			string TestUserInput8 = "edit 1 from 17:00 to 2359 on 19/05/2011 movies";
			TestETTIdentifier.Identify(TestUserInput8);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, _TestdataStorageETT);
			Task test8 = ((_TestdataStorageETT.retrieveTaskListToDisplay()).front());
			string str10 = "2359";
			Assert::AreEqual(test8.getEndTime(), str10);
			string str8 = "movies";
			Assert::AreEqual(test8.getEvent(), str8);
			string str9 = "20110519";
			Assert::AreEqual(test8.getDate(), str9);

			TaskManagerETT.~VeriTask();
		}

		TEST_METHOD(testEditDeadlineTask) {
			//integration test for editing a deadline task, using Identifier, Add and Search classes
			//initialise task
			string TestUserInput = "add grow up by 11/04/2014";
			
			Identifier TestInfoIdentifier;
	     	DataStorage _TestdataStorage("testEditDeadlineTask.txt");
			VeriTask TaskManager(_TestdataStorage);
			TextUI textUI;

			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue((_TestdataStorage.retrieveTaskList().empty()));
			Assert::IsTrue((_TestdataStorage.retrieveTaskListToDisplay()).empty());

			TestInfoIdentifier.Identify(TestUserInput);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);

			//ensure successful add
			Assert::IsFalse((_TestdataStorage.retrieveTaskList().empty()));

			//search to access Task to be edited
			string SearchCommand = "search grow up";
			TestInfoIdentifier.Identify(SearchCommand);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);

			//ensure positive search
			Assert::IsFalse((_TestdataStorage.retrieveTaskListToDisplay()).empty());

			//edit deadline task attributes
			string TestUserInput2 = "edit 1 be mugger";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
			
			Task test2 = ((_TestdataStorage.retrieveTaskList()).front());
			string str1 = "be mugger";
			Assert::AreEqual(test2.getEvent(), str1);

			string TestUserInput3 = "edit 1 on 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
			string str2 = "20110301";
			Task test3 = ((_TestdataStorage.retrieveTaskList()).front());
			Assert::AreEqual(test3.getDate(), str2);

			string TestUserInput4 = "edit 1 by 31/03/2011 pass exam";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
			Task test4 = ((_TestdataStorage.retrieveTaskList()).front());
			string str3 = "pass exam";
			Assert::AreEqual(test4.getEvent(), str3);
			string str4 = "20110331";
			Assert::AreEqual(test4.getDate(), str4);

			TaskManager.~VeriTask();
		}

		TEST_METHOD(testEditFloatingTask) {
			//integration test for editing a floating task, using Identifier, Add and Search classes
			//floating task can be changed to deadline and timed task, and other type changes are allowed

			//initialise task
			string TestUserInput = "add complete drawing";
			Identifier TestInfoIdentifier;
	     	DataStorage _TestdataStorage("testEditFloatingTask.txt");
			VeriTask TaskManager(_TestdataStorage);
			TextUI textUI;

			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue((_TestdataStorage.retrieveTaskList().empty()));
			Assert::IsTrue((_TestdataStorage.retrieveTaskListToDisplay()).empty());
			
			TestInfoIdentifier.Identify(TestUserInput);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);

			//ensure successful add
			Assert::IsFalse((_TestdataStorage.retrieveTaskList().empty()));

			//search to access Task to be edited
			string SearchCommand = "search complete";
			TestInfoIdentifier.Identify(SearchCommand);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);

			//ensure positive search
			Assert::IsFalse((_TestdataStorage.retrieveTaskListToDisplay()).empty());
			
			//edit task attributes
			string TestUserInput2 = "edit 1 update portfolio";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
			
			Task test2 = ((_TestdataStorage.retrieveTaskListToDisplay()).front());
			string str1 = "update portfolio";
			Assert::AreEqual(test2.getEvent(), str1);

			//add date to floating task; change to deadline task
			string TestUserInput3 = "edit 1 on 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
			string str2 = "20110301";
			Task test3 = ((_TestdataStorage.retrieveTaskListToDisplay()).front());
			Assert::AreEqual(test3.getDate(), str2);

			//add date & time to floating task, change to timed task
			string TestUserInput5 = "add buy pencil";
			TestInfoIdentifier.Identify(TestUserInput5);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
		
			//search to access Task to be edited
			string SearchCommand2 = "search buy";
			TestInfoIdentifier.Identify(SearchCommand2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);

			//ensure positive search
			Assert::IsFalse((_TestdataStorage.retrieveTaskListToDisplay()).empty());
			
			//ensure accurate search
			Task test6 = ((_TestdataStorage.retrieveTaskListToDisplay()).front());
			string str6 = "buy pencil";
			Assert::AreEqual(test6.getEvent(), str6);

			string TestUserInput4 = "edit 1 from 12:00 to 15:00 on 17/03/2010";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, _TestdataStorage);
			Task test4 = ((_TestdataStorage.retrieveTaskListToDisplay()).front());
			string str5 = "20100317";
			Assert::AreEqual(test4.getDate(), str5);
			string str3 = "1200";
			Assert::AreEqual(test4.getStartTime(), str3);
			string str4 = "1500";
			Assert::AreEqual(test4.getEndTime(), str4);		

			TaskManager.~VeriTask();

		}

		TEST_METHOD(testMark) {
			//integration test for mark, using Identifier, Add and Search classes
			string testMark = "add complete drawing";
			Identifier TestMarkIdentifier;
	     	DataStorage _TestdataStoreMark("testMark.txt");
			VeriTask TaskManagerMark(_TestdataStoreMark);
			TextUI textUIMark;

			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue((_TestdataStoreMark.retrieveTaskList().empty()));
			Assert::IsTrue((_TestdataStoreMark.retrieveTaskListToDisplay()).empty());

			TestMarkIdentifier.Identify(testMark);
			TaskManagerMark.pushCommand(TestMarkIdentifier.GetCommand(), TestMarkIdentifier, textUIMark, _TestdataStoreMark);
				
			//ensure successful add
			Assert::IsFalse((_TestdataStoreMark.retrieveTaskList().empty()));

			//search to access Task to be edited
			string SearchCommand = "search drawing";
			TestMarkIdentifier.Identify(SearchCommand);
			TaskManagerMark.pushCommand(TestMarkIdentifier.GetCommand(), TestMarkIdentifier, textUIMark, _TestdataStoreMark);

			//ensure positive search
			Assert::IsFalse((_TestdataStoreMark.retrieveTaskListToDisplay()).empty());

			string testMark2 = "mark 1 done";
			TestMarkIdentifier.Identify(testMark2);
			TaskManagerMark.pushCommand(TestMarkIdentifier.GetCommand(), TestMarkIdentifier, textUIMark, _TestdataStoreMark);
			string testMarkStatus = "done";
			Task test2Mark = ((_TestdataStoreMark.retrieveTaskListToDisplay()).front());
			Assert::AreEqual(test2Mark.getStatus(), testMarkStatus);

			string testMark3 = "mark 1 cannot be done";
			TestMarkIdentifier.Identify(testMark3);
			TaskManagerMark.pushCommand(TestMarkIdentifier.GetCommand(), TestMarkIdentifier, textUIMark, _TestdataStoreMark);
			Task test3Mark = ((_TestdataStoreMark.retrieveTaskListToDisplay()).front());
			string testMarkStatus2 = "cannot be done";
			Assert::AreEqual(test3Mark.getStatus(), testMarkStatus2);

			TaskManagerMark.~VeriTask();
		}

		TEST_METHOD(testDelete) {
			//integration test for delete function, using Identifier, Add and Search classes
			//checks for deletion of a single task
			//checks for deletion of first task in storage vector
			//checks for deletion of second task in storage vector
			//checks for deletion of a task located in middle of data storage vector
			//checks for deletion of second last task in data storage vector
			//checks for deletion of task at end of data storage vector

			string testDel = "add complete drawing";
			Identifier TestDelIdentifier;
	     	DataStorage _TestdataStoreDel("testDelete.txt");
			VeriTask TaskManagerDel(_TestdataStoreDel);
			TextUI textUIDel;

			//precondition: begin with empty data store
			Assert::IsTrue((_TestdataStoreDel.retrieveTaskList()).empty());  
			Assert::IsTrue((_TestdataStoreDel.retrieveTaskListToDisplay()).empty()); 

			TestDelIdentifier.Identify(testDel);
			TaskManagerDel.pushCommand(TestDelIdentifier.GetCommand(), TestDelIdentifier, textUIDel, _TestdataStoreDel);
			
			//check that task has been added
			Assert::IsFalse((_TestdataStoreDel.retrieveTaskList()).empty()); 

			//deletion of a single task
			string testDel2 = "delete 1";
			TestDelIdentifier.Identify(testDel2);
			TaskManagerDel.pushCommand(TestDelIdentifier.GetCommand(), TestDelIdentifier, textUIDel, _TestdataStoreDel);

			//post-condition: task has been deleted
			Assert::IsTrue((_TestdataStoreDel.retrieveTaskList()).empty()); 

			TaskManagerDel.~VeriTask();
		}

		
		TEST_METHOD(testUndo) {
			//integration test for Undo, using Identifier, Add, Search, Edit, Mark and Delete
			//tests single undo on each operation
			//tests multiple undo

			Identifier undoIdentifier;
	     	DataStorage _undoData("testUndo.txt");
			VeriTask undoVeriTask(_undoData);
			TextUI undoUI;
			string undoKeyword = "undo"; 

			//precondition: begin with empty data store
			Assert::IsTrue((_undoData.retrieveTaskList()).empty());  
			Assert::IsTrue((_undoData.retrieveTaskListToDisplay()).empty()); 

			//test undo for Add
			string undo1 = "add expand vocal range";
			undoIdentifier.Identify(undo1);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			//ensure successful add
			Assert::IsFalse((_undoData.retrieveTaskList()).empty());  

			undoIdentifier.Identify(undoKeyword);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			//ensure successful post-condition after undo
			Assert::IsTrue((_undoData.retrieveTaskList()).empty());  

			//re-add
			undoIdentifier.Identify(undo1);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			//ensure successful add
			Assert::IsFalse((_undoData.retrieveTaskList()).empty());  

			//test Undo for Edit
			//search to retrieve task
			string undoSearch1 = "search vocal range";
			undoIdentifier.Identify(undoSearch1);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			//ensure successful search
			Assert::IsFalse((_undoData.retrieveTaskListToDisplay()).empty());
			//ensure accurate search
			Task test1 = ((_undoData.retrieveTaskListToDisplay()).front());
			string str1 = "expand vocal range";
			Assert::AreEqual(test1.getEvent(), str1);

			string edit0 = "edit 1 expand vocal range and strengthen chest voice";
			undoIdentifier.Identify(edit0);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			Task test0 = ((_undoData.retrieveTaskListToDisplay()).front());
			//ensure successful edit
			string str0 = "expand vocal range and strengthen chest voice";
			Assert::AreEqual(test0.getEvent(), str0);

			undoIdentifier.Identify(undoKeyword);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			//ensure successful post-condition after undo
			Task test00 = ((_undoData.retrieveTaskListToDisplay()).front());
			string str00 = "expand vocal range";
			Assert::AreEqual(test00.getEvent(), str00);

			string edit1 = "edit 1 from 12:00 to 15:00 on 17/03/2010";
			undoIdentifier.Identify(edit1);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			Task test2 = ((_undoData.retrieveTaskListToDisplay()).front());
			//ensure successful edit
			string str2 = "20100317";
			Assert::AreEqual(test2.getDate(), str2);

			undoIdentifier.Identify(undoKeyword);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			//ensure successful post-condition after undo
			Task test3 = ((_undoData.retrieveTaskListToDisplay()).front());
			string str3 = "    ";
			Assert::AreEqual(test3.getStartTime(), str3);
			Assert::AreEqual(test3.getEndTime(), str3);
			string str4 = "        ";
			Assert::AreEqual(test3.getDate(), str4);
				
			string edit2 = "edit 1 by 18/03/2011";
			undoIdentifier.Identify(edit2);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			Task test4 = ((_undoData.retrieveTaskListToDisplay()).front());
			//ensure successful edit
			string str5 = "201110318";
			Assert::AreEqual(test4.getDate(), str5);
			undoIdentifier.Identify(undoKeyword);
			undoVeriTask.pushCommand(undoIdentifier.GetCommand(), undoIdentifier, undoUI, _undoData);
			//ensure successful post-condition after undo
			Task test5 = ((_undoData.retrieveTaskListToDisplay()).front());
			Assert::AreEqual(test5.getDate(), str4);

			//test Undo for Mark
		}

	};
}