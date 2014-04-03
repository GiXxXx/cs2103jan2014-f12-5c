#include "stdafx.h"
#include "CppUnitTest.h"

#include "AddTask.h"
#include "Command.h"
#include "CommandGetter.h"
#include "DataStorage.h"
#include "DateGetter.h"
#include "DeleteTask.h"
#include "EditTask.h"
#include "EndTimeGetter.h"
#include "EventGetter.h"
#include "Identifier.h"
#include "KeywordGetter.h"
#include "MarkTask.h"
//#include "resource.h"
#include "SearchTask.h"
#include "StartTimeGetter.h"
#include "StatusGetter.h"
#include "Task.h"
#include "TaskNumGetter.h"
#include "TextUI.h"
#include "Tokenizer.h"
#include "VeriTask.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2 {		
	TEST_CLASS(UnitTest1) {
	public:
		
		TEST_METHOD(testAddTimedTask) {
			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			Identifier TestInfoIdentifier;
			VeriTask TaskManager;
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
		
			DataStorage _TestdataStorage = TaskManager.getDataStorage();
			
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());

			//check that attributes have been initialised correctly for timed tasks

			string str1 = "20110531";
			Assert::AreEqual(test1.getDate(), str1);

			string str2 = "1930";
			Assert::AreEqual(test1.getStartTime(), str2);

			string str3 = "2200";
			Assert::AreEqual(test1.getEndTime(), str3);

			string str4 = "stargazing session ";
			Assert::AreEqual(test1.getEvent(), str4);

			Assert::AreEqual(test1.getID(), 20110531.19302200);
			
			//check that task has been added in correct order, comparing 2 timed tasks
			string TestUserInput2 = "add birthday party on 01/03/2011 from 08.00 to 17.00";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str5 = "birthday party";
			Assert::AreEqual(test2.getEvent(), str5);

			//check that task has been added in correct order, comparing timed & deadline tasks
			string TestUserInput3 = "add settle accounts by 01/04/2014";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test3 =*((_TestdataStorage.retrieveTaskList()).end());
			string str6 = "settle accounts";
			Assert::AreEqual(test3.getEvent(), str6);

			//check that task has been added in correct order, comparing timed & floating tasks
			string TestUserInput3 = "add arrange music score";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test4 =*((_TestdataStorage.retrieveTaskList()).end());
			string str7 = "arrange music score";
			Assert::AreEqual(test4.getEvent(), str7);
		}
		
		TEST_METHOD(testAddDeadlineTask) {
			string TestUserInput = "add see sunrise by 19/05/2011";
			Identifier TestInfoIdentifier;
			VeriTask TaskManager;
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;

			//check that attributes have been initialised correctly for deadline tasks

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
		
			DataStorage _TestdataStorage = TaskManager.getDataStorage();
			
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());

			string str1 = "20110519";
			Assert::AreEqual(test1.getDate(), str1);

			string str2 = "9999";
			Assert::AreEqual(test1.getStartTime(), str2);

			string str3 = "9999";
			Assert::AreEqual(test1.getEndTime(), str3);

			string str4 = "see sunrise ";
			Assert::AreEqual(test1.getEvent(), str4);

			Assert::AreEqual(test1.getID(), 20110519.99999999);
			
			//check that task has been added in correct order, comparing 2 deadline tasks
			string TestUserInput2 = "add see sunset by 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str5 = "see sunset";
			Assert::AreEqual(test2.getEvent(), str5);	

			//check that task has been added in correct order, comparing deadline & floating tasks
			string TestUserInput3 = "add watch Ghibli";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);

			string TestUserInput4 = "add see sunset by 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);

			_TestdataStorage = TaskManager.getDataStorage();
			Task test3 =*((_TestdataStorage.retrieveTaskList()).end());
			string str6 = "watch Ghibli";
			Assert::AreEqual(test3.getEvent(), str6);
		} 

		TEST_METHOD(testAddFloatingTask) {
			string TestUserInput = "add move house";
			Identifier TestInfoIdentifier;
			VeriTask TaskManager;
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;

			//check that attributes have been initialised correctly for deadline tasks

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
		
			DataStorage _TestdataStorage = TaskManager.getDataStorage();
			
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());

			string str1 = "move house";
			Assert::AreEqual(test1.getEvent(), str1);

			string str2 = "    ";
			Assert::AreEqual(test1.getStartTime(), str2);
			Assert::AreEqual(test1.getEndTime(), str2);
			string str3 = "        ";
			Assert::AreEqual(test1.getDate(), str3);

			Assert::AreEqual(test1.getID(), 99999999.999999991);

//to-do: check for initialisation of 2nd floating task ID
			
			//check that task has been added in correct order, comparing deadline to floating
			string TestUserInput2 = "add see sunset by 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str4 = "see sunset";
			Assert::AreEqual(test2.getEvent(), str4);			

			//check that task has been added in correct order, comparing 2 floating tasks
			string TestUserInput3 = "add shift furniture";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test3 =*((_TestdataStorage.retrieveTaskList()).end());
			string str5 = "shift furniture";
			Assert::AreEqual(test2.getEvent(), str5);
		
		}

		TEST_METHOD(testEditTimedTask) {
			//floating task can be changed to deadline and timed task, but other type changes are not allowed

			//initialise task
			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			Identifier TestInfoIdentifier;
			VeriTask TaskManager;
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
		
			DataStorage _TestdataStorage = TaskManager.getDataStorage();

			//edit timed task attributes
			string TestUserInput2 = "edit sunset";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test2 =*((_TestdataStorage.retrieveTaskListToDisplay()).begin());
			string str1 = "sunset";
			Assert::AreEqual(test2.getEvent(), str1);

			string TestUserInput3 = "edit on 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str2 = "01/03/2011";
			Assert::AreEqual(test2.getDate(), str2);

			string TestUserInput4 = "edit from 12:00";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str3 = "1200";
			Assert::AreEqual(test2.getStartTime(), str3);

			string TestUserInput5 = "edit at 19:00";
			TestInfoIdentifier.Identify(TestUserInput5);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str4 = "1900";
			Assert::AreEqual(test2.getStartTime(), str4);

			string TestUserInput7 = "edit to 03:00";
			TestInfoIdentifier.Identify(TestUserInput7);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str7 = "0300";
			Assert::AreEqual(test2.getEndTime(), str7);

			//test edit of multiple attributes and unordered data attribute input
			string TestUserInput6 = "edit fireworks from 1700";
			TestInfoIdentifier.Identify(TestUserInput6);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str5 = "1700";
			Assert::AreEqual(test2.getStartTime(), str5);
			string str6 = "fireworks";
			Assert::AreEqual(test2.getEvent(), str6);

			string TestUserInput6 = "edit to 2359 on 19/05/2011 movies";
			TestInfoIdentifier.Identify(TestUserInput6);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str7 = "2359";
			Assert::AreEqual(test2.getEndTime(), str7);
			string str8 = "movies";
			Assert::AreEqual(test2.getEvent(), str8);
			string str9 = "19/05/2011";
			Assert::AreEqual(test2.getDate(), str9);
		
		}

		TEST_METHOD(testEditDeadlineTask) {
	
			//initialise task
			string TestUserInput = "add grow up by 11/04/2014";
			Identifier TestInfoIdentifier;
			VeriTask TaskManager;
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
		
			DataStorage _TestdataStorage = TaskManager.getDataStorage();

			//edit deadline task attributes
			string TestUserInput2 = "edit be mugger";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test2 =*((_TestdataStorage.retrieveTaskListToDisplay()).begin());
			string str1 = "be mugger";
			Assert::AreEqual(test2.getEvent(), str1);

			string TestUserInput3 = "edit on 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str2 = "01/03/2011";
			Assert::AreEqual(test2.getDate(), str2);

			string TestUserInput4 = "edit by 31/03/2011 pass exam";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str3 = "pass exam";
			Assert::AreEqual(test2.getEvent(), str3);
			string str4 = "31/03/2011";
			Assert::AreEqual(test2.getDate(), str4);
		}

		TEST_METHOD(testEditFloatingTask) {
			//floating task can be changed to deadline and timed task, but other type changes are not allowed

			//initialise task
			string TestUserInput = "add complete drawing";
			Identifier TestInfoIdentifier;
			VeriTask TaskManager;
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
		
			DataStorage _TestdataStorage = TaskManager.getDataStorage();

			//edit task attributes
			string TestUserInput2 = "edit update portfolio";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test2 =*((_TestdataStorage.retrieveTaskListToDisplay()).begin());
			string str1 = "update portfolio";
			Assert::AreEqual(test2.getEvent(), str1);

			//add date to floating task; change to deadline task
			string TestUserInput3 = "edit on 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str2 = "01/03/2011";
			Assert::AreEqual(test2.getDate(), str2);

			//add date & time to floating task, change to timed task
			string TestUserInput5 = "add buy pencil";
			TestInfoIdentifier.Identify(TestUserInput5);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test3 =*((_TestdataStorage.retrieveTaskListToDisplay()).end());

			string TestUserInput4 = "edit from 12:00 to 15:00 on 17/03/2010";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			string str3 = "1200";
			Assert::AreEqual(test3.getStartTime(), str3);
			string str4 = "1500";
			Assert::AreEqual(test3.getEndTime(), str4);
			string str5 = "17/03/2010";
			Assert::AreEqual(test3.getDate(), str4);

		}

		TEST_METHOD(testMark) {
				
		}

		TEST_METHOD(testDelete) {
				
		}

		TEST_METHOD(testSearch) {
			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			Identifier TestInfoIdentifier;
			VeriTask TaskManager;
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
		
			DataStorage _TestdataStorage = TaskManager.getDataStorage();
			
			//negative search
			string TestUserInput2 = "search sunset";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();

			Assert::IsTrue((_TestdataStorage.retrieveTaskListToDisplay()).empty());	

			//positive search
			string TestUserInput3 = "search stargazing";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();

			Task test2 =*((_TestdataStorage.retrieveTaskListToDisplay()).begin());
			string str1 = "stargazing session";
			Assert::AreEqual(test2.getEvent(), str1);
		}
		
		TEST_METHOD(testUndo) {
				
		}

		TEST_METHOD(testIdentifier) {
				
		}
	};
}