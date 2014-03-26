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

			//check that attributes have been initialised correctly for timed tasks

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
		
			DataStorage _TestdataStorage = TaskManager.getDataStorage();
			
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());

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
			string str5 = "20110301";
			Assert::AreEqual(test2.getDate(), str5);			
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

			//haven't decided what to return for getStartTime() and getEndTime() for deadlines

			string str4 = "see sunrise ";
			Assert::AreEqual(test1.getEvent(), str4);

			Assert::AreEqual(test1.getID(), 20110519.99999999);
			
			//check that task has been added in correct order, comparing 2 timed tasks
			string TestUserInput2 = "add see sunset by 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI);
			_TestdataStorage = TaskManager.getDataStorage();
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str5 = "20110301";
			Assert::AreEqual(test2.getDate(), str5);			
		}

		TEST_METHOD(testEdit) {
				
		}

		
		TEST_METHOD(testMark) {
				
		}

		TEST_METHOD(testDelete) {
				
		}

		TEST_METHOD(testSearch) {
				
		}

		TEST_METHOD(testUndo) {
				
		}

		TEST_METHOD(testIdentifier) {
				
		}
	};
}