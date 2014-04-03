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

			string str2 = "9999";
			Assert::AreEqual(test1.getStartTime(), str2);
			string str3 = "9999";
			Assert::AreEqual(test1.getEndTime(), str3);

			Assert::AreEqual(test1.getID(), 99999999.99999999);
			
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

		TEST_METHOD(testEdit) {
				
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