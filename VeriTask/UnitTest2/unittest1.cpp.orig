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
			File filename;
			VeriTask TaskManager(filename);
			TextUI textUI;
			DataStorage _TestdataStorage = TaskManager.getDataStorage();
			
			//DEBUG
			Assert::IsTrue(_TestdataStorage.retrieveTaskList().empty());
			
			TestInfoIdentifier.Identify(TestUserInput);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			
			//DEBUG
			Assert::IsFalse(_TestdataStorage.retrieveTaskList().empty());
			//declaration
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());

			//check that attributes have been initialised correctly for timed tasks

			string str1 = "20110531";
			Assert::AreEqual(test1.getDate(), str1);

			string str2 = "1930";
			Assert::AreEqual(test1.getStartTime(), str2);

			string str3 = "2200";
			Assert::AreEqual(test1.getEndTime(), str3);

			string str4 = "stargazing session";
			Assert::AreEqual(test1.getEvent(), str4);

			unsigned long long ID1 = 2011053119302200;
			Assert::AreEqual(test1.getID(), ID1);
			
			//check that task has been added in correct order, comparing 2 timed tasks
			string TestUserInput2 = "add birthday party on 01/03/2011 from 08.00 to 17.00";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str5 = "birthday party";
			Assert::AreEqual(test2.getEvent(), str5);

			//check that task has been added in correct order, comparing timed & deadline tasks
			string TestUserInput3 = "add settle accounts by 01/04/2014";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
		
			Task test3 =*((_TestdataStorage.retrieveTaskList()).end());
			string str6 = "settle accounts";
			Assert::AreEqual(test3.getEvent(), str6);

			//check that task has been added in correct order, comparing timed & floating tasks
			string TestUserInput4 = "add arrange music score";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			
			Task test4 =*((_TestdataStorage.retrieveTaskList()).end());
			string str7 = "arrange music score";
			Assert::AreEqual(test4.getEvent(), str7);
		}
		
		TEST_METHOD(testAddDeadlineTask) {
			string TestUserInput = "add see sunrise by 19/05/2011";
			Identifier TestInfoIdentifier;
			File filename;
			VeriTask TaskManager(filename);
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;

			//check that attributes have been initialised correctly for deadline tasks

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
		
			DataStorage _TestdataStorage = TaskManager.getDataStorage();
			
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());

			string str1 = "20110519";
			Assert::AreEqual(test1.getDate(), str1);

			string str2 = "    ";
			Assert::AreEqual(test1.getStartTime(), str2);

			string str3 = "    ";
			Assert::AreEqual(test1.getEndTime(), str3);

			string str4 = "see sunrise";
			Assert::AreEqual(test1.getEvent(), str4);

			//don't test ID first
			/* unsigned long long ID2 = 2011051999999999;
			Assert::AreEqual(test1.getID(), ID2); */
			
			//check that task has been added in correct order, comparing 2 deadline tasks
			string TestUserInput2 = "add see sunset by 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str5 = "see sunset";
			Assert::AreEqual(test2.getEvent(), str5);	

			//check that task has been added in correct order, comparing deadline & floating tasks
			string TestUserInput3 = "add watch Ghibli";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);

			string TestUserInput4 = "add see midnight by 19/03/2011";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);

			Task test3 =*((_TestdataStorage.retrieveTaskList()).end());
			string str6 = "watch Ghibli";
			Assert::AreEqual(test3.getEvent(), str6);
		} 

		TEST_METHOD(testAddFloatingTask) {
			string TestAFT = "add move house";
			Identifier TestInfoIdentifier1;
			File filenameAFT;
			VeriTask TaskManager1(filenameAFT);
			TestInfoIdentifier1.Identify(TestAFT);
			TextUI textUI;

			//check that attributes have been initialised correctly for deadline tasks

			TaskManager1.pushCommand(TestInfoIdentifier1.GetCommand(), TestInfoIdentifier1, textUI, filenameAFT);
		
			DataStorage _TestdataStorage = TaskManager1.getDataStorage();
			
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());

			string str1 = "move house";
			Assert::AreEqual(test1.getEvent(), str1);

			string str2 = "    ";
			Assert::AreEqual(test1.getStartTime(), str2);
			Assert::AreEqual(test1.getEndTime(), str2);
			string str3 = "        ";
			Assert::AreEqual(test1.getDate(), str3);

			unsigned long long ID3 = 99999999999999991;
			Assert::AreEqual(test1.getID(), ID3);

//to-do: check for initialisation of 2nd floating task ID
			
			//check that task has been added in correct order, comparing deadline to floating
			string TestUserInput2 = "add see sunset by 01/03/2011";
			TestInfoIdentifier1.Identify(TestUserInput2);
			TaskManager1.pushCommand(TestInfoIdentifier1.GetCommand(), TestInfoIdentifier1, textUI, filenameAFT);
			
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str4 = "see sunset";
			Assert::AreEqual(test2.getEvent(), str4);			

			//check that task has been added in correct order, comparing 2 floating tasks
			string TestUserInput3 = "add shift furniture";
			TestInfoIdentifier1.Identify(TestUserInput3);
			TaskManager1.pushCommand(TestInfoIdentifier1.GetCommand(), TestInfoIdentifier1, textUI, filenameAFT);
			
			Task test3 =*((_TestdataStorage.retrieveTaskList()).end());
			string str5 = "shift furniture";
			Assert::AreEqual(test2.getEvent(), str5);
		
		}

		TEST_METHOD(testEditTimedTask) {
			//floating task can be changed to deadline and timed task, but other type changes are not allowed

			//initialise task
			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			Identifier TestETTIdentifier;
			File filenameETT;
			VeriTask TaskManagerETT(filenameETT);
			TestETTIdentifier.Identify(TestUserInput);
			TextUI textUI;
			DataStorage _TestdataStorageETT = TaskManagerETT.getDataStorage();

			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI,filenameETT);
		
			//edit timed task attributes
			string TestUserInput2 = "edit 1 sunset";
			TestETTIdentifier.Identify(TestUserInput2);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, filenameETT);
			
			Task test2 =*((_TestdataStorageETT.retrieveTaskList()).begin());
			string str1 = "sunset";
			Assert::AreEqual(test2.getEvent(), str1);

			string TestUserInput3 = "edit 1 on 01/03/2011";
			TestETTIdentifier.Identify(TestUserInput3);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI,filenameETT);
			string str2 = "20110301";
			Assert::AreEqual(test2.getDate(), str2);

			string TestUserInput4 = "edit 1 from 12:00";
			TestETTIdentifier.Identify(TestUserInput4);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, filenameETT);
			string str3 = "1200";
			Assert::AreEqual(test2.getStartTime(), str3);

			string TestUserInput5 = "edit 1 at 19:00";
			TestETTIdentifier.Identify(TestUserInput5);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, filenameETT);
			string str4 = "1900";
			Assert::AreEqual(test2.getStartTime(), str4);

			string TestUserInput7 = "edit 1 to 03:00";
			TestETTIdentifier.Identify(TestUserInput7);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, filenameETT);
			string str7 = "0300";
			Assert::AreEqual(test2.getEndTime(), str7);

			//test edit of multiple attributes and unordered data attribute input
			string TestUserInput6 = "edit 1 fireworks from 1700";
			TestETTIdentifier.Identify(TestUserInput6);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, filenameETT);
			string str5 = "1700";
			Assert::AreEqual(test2.getStartTime(), str5);
			string str6 = "fireworks";
			Assert::AreEqual(test2.getEvent(), str6);

			string TestUserInput8 = "edit 1 to 2359 on 19/05/2011 movies";
			TestETTIdentifier.Identify(TestUserInput8);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, filenameETT);
			string str10 = "2359";
			Assert::AreEqual(test2.getEndTime(), str10);
			string str8 = "movies";
			Assert::AreEqual(test2.getEvent(), str8);
			string str9 = "20110519";
			Assert::AreEqual(test2.getDate(), str9);
		
		}

		TEST_METHOD(testEditDeadlineTask) {
	
			//initialise task
			string TestUserInput = "add grow up by 11/04/2014";
			Identifier TestInfoIdentifier;
			File filename;
			VeriTask TaskManager(filename);
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;
			DataStorage _TestdataStorage = TaskManager.getDataStorage();

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);

			//edit deadline task attributes
			string TestUserInput2 = "edit 1 be mugger";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str1 = "be mugger";
			Assert::AreEqual(test2.getEvent(), str1);

			string TestUserInput3 = "edit 1 on 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			string str2 = "20110301";
			Assert::AreEqual(test2.getDate(), str2);

			string TestUserInput4 = "edit 1 by 31/03/2011 pass exam";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			string str3 = "pass exam";
			Assert::AreEqual(test2.getEvent(), str3);
			string str4 = "20110331";
			Assert::AreEqual(test2.getDate(), str4);
		}

		TEST_METHOD(testEditFloatingTask) {
			//floating task can be changed to deadline and timed task, but other type changes are not allowed

			//initialise task
			string TestUserInput = "add complete drawing";
			Identifier TestInfoIdentifier;
			File filename;
			VeriTask TaskManager(filename);
			TestInfoIdentifier.Identify(TestUserInput);
			TextUI textUI;
			DataStorage _TestdataStorage = TaskManager.getDataStorage();

			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);

			//edit task attributes
			string TestUserInput2 = "edit 1 update portfolio";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str1 = "update portfolio";
			Assert::AreEqual(test2.getEvent(), str1);

			//add date to floating task; change to deadline task
			string TestUserInput3 = "edit 1 on 01/03/2011";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			string str2 = "20110301";
			Assert::AreEqual(test2.getDate(), str2);

			//add date & time to floating task, change to timed task
			string TestUserInput5 = "add buy pencil";
			TestInfoIdentifier.Identify(TestUserInput5);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
		
			Task test3 =*((_TestdataStorage.retrieveTaskListToDisplay()).end());

			string TestUserInput4 = "edit 1 from 12:00 to 15:00 on 17/03/2010";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			string str3 = "1200";
			Assert::AreEqual(test3.getStartTime(), str3);
			string str4 = "1500";
			Assert::AreEqual(test3.getEndTime(), str4);
			string str5 = "20100317";
			Assert::AreEqual(test3.getDate(), str4);

		}

		TEST_METHOD(testMark) {
			string testMark = "add complete drawing";
			Identifier TestMarkIdentifier;
			File filenameMark;
			VeriTask TaskManagerMark(filenameMark);
			TestMarkIdentifier.Identify(testMark);
			TextUI textUIMark;
			DataStorage _TestdataStoreMark = TaskManagerMark.getDataStorage();

			TaskManagerMark.pushCommand(TestMarkIdentifier.GetCommand(), TestMarkIdentifier, textUIMark, filenameMark);
				
			Task test2Mark =*((_TestdataStoreMark.retrieveTaskList()).begin());

			string testMark2 = "mark 1 done";
			TaskManagerMark.pushCommand(TestMarkIdentifier.GetCommand(), TestMarkIdentifier, textUIMark, filenameMark);
			string testMarkStatus = "done";
			Assert::AreEqual(test2Mark.getStatus(), testMarkStatus);

			string testMark3 = "mark 1 cannot be done";
			TaskManagerMark.pushCommand(TestMarkIdentifier.GetCommand(), TestMarkIdentifier, textUIMark, filenameMark);
			string testMarkStatus2 = "cannot be done";
			Assert::AreEqual(test2Mark.getStatus(), testMarkStatus2);
		}

		TEST_METHOD(testDelete) {
			string testDel = "add complete drawing";
			Identifier TestDelIdentifier;
			File filenameDel;
			VeriTask TaskManagerDel(filenameDel);
			TestDelIdentifier.Identify(testDel);
			TextUI textUIDel;
			DataStorage _TestdataStoreDel = TaskManagerDel.getDataStorage();

			Assert::IsTrue((_TestdataStoreDel.retrieveTaskList()).empty());  //begin with empty data store

			TaskManagerDel.pushCommand(TestDelIdentifier.GetCommand(), TestDelIdentifier, textUIDel, filenameDel);
			Assert::IsFalse((_TestdataStoreDel.retrieveTaskList()).empty()); //task has been added

			string testDel = "delete 1";
			TaskManagerDel.pushCommand(TestDelIdentifier.GetCommand(), TestDelIdentifier, textUIDel, filenameDel);

			Assert::IsTrue((_TestdataStoreDel.retrieveTaskList()).empty()); //task has been deleted
		}

		TEST_METHOD(testSearch) {
			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			Identifier TestInfoIdentify;
			File filenameS;
			VeriTask TaskManagerS(filenameS);
			TestInfoIdentify.Identify(TestUserInput);
			TextUI textUI;

			DataStorage _TestdataStorageS = TaskManagerS.getDataStorage();
			//DEBUG
			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());
			
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);
		
			//negative search
			string TestUserInput2 = "search sunset";
			TestInfoIdentify.Identify(TestUserInput2);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);

			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());	

			//positive search
			string TestUserInput3 = "search stargazing ";
			TestInfoIdentify.Identify(TestUserInput3);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);
			//DEBUG
			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());
		/*	Task testS =*((_TestdataStorageS.retrieveTaskListToDisplay()).begin());
			string str1S = "stargazing session";
			Assert::AreEqual(testS.getEvent(), str1S); */
		}
		
		TEST_METHOD(testUndo) {
				
		}

		/*TEST_METHOD(testIdentifier) {
				
		} */
	};
}