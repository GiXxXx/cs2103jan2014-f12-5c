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
#include "resource.h"
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
		
		TEST_METHOD(testAdd) {
			string TestUserInput = "add stargazing session on 31/05/2011 from 19.30 to 22.00";
			DataStorage _TestdataStorage;
			Identifier TestInfoIdentifier;

			TestInfoIdentifier.Identify(TestUserInput);

			//check that data structure has had one task added
			size_t vectorsize = 1;
			Assert::AreEqual((_TestdataStorage.retrieveTaskList()).size(), vectorsize);

			//checking that data members are initialised correctly for a timed task
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str1 = "stargazing session";
			Assert::AreSame(test1.getEvent(), str1);

			string str2 = "31/05/2011";
			Assert::AreSame(test1.getDate(), str2);

			string str3 = "19.30";
			Assert::AreSame(test1.getStartTime(), str3);

			string str4 = "22.00";
			Assert::AreSame(test1.getEndTime(), str4);

			size_t index = 0;
			Assert::AreEqual(test1.getStatus().size(), index);

			Assert::AreEqual(test1.getID(), 20110531.19302200);

			//check that task has been added in correct order, comparing 2 timed tasks
			string TestUserInput2 = "add birthday party on 01/03/2011 from 08.00 to 17.00";
			TestInfoIdentifier.Identify(TestUserInput2);
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str5 = "birthday party";
			Assert::AreSame(test2.getEvent(), str5);

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