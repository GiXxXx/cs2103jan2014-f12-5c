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
			//unit test for the addition of a timed task
			//tests for correct initialisation of Task member attributes
			//tests correct order of two timed tasks in data storage
			//tests correct order of timed task and deadline task in data storage
			//tests correct order of timed task and floating task in data storage

			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			Identifier TestInfoIdentifier;
			File filename;
			VeriTask TaskManager(filename);
			TextUI textUI;
			DataStorage _TestdataStorage = TaskManager.getDataStorage();
			
			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue(_TestdataStorage.retrieveTaskList().empty()); 
			
			TestInfoIdentifier.Identify(TestUserInput);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			
			//post-condition: data storage no longer empty after add
			Assert::IsFalse(_TestdataStorage.retrieveTaskList().empty());
			
			//check that member data attributes are initialised correctly for timed task
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());

			string str1 = "20110531";
			Assert::AreEqual(test1.getDate(), str1);

			string str2 = "1930";
			Assert::AreEqual(test1.getStartTime(), str2);

			string str3 = "2200";
			Assert::AreEqual(test1.getEndTime(), str3);

			string str4 = "stargazing session";
			Assert::AreEqual(test1.getEvent(), str4);

			unsigned long long ID1 = 2011053119302200;
			Assert::AreEqual(ID1, test1.getID());
			
			//check that task has been added in correct order, comparing 2 timed tasks
			string TestUserInput2 = "add birthday party on 01/03/2011 from 08:00 to 17:00";
			TestInfoIdentifier.Identify(TestUserInput2);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str5 = "birthday party";
			Assert::AreEqual(str5, test2.getEvent());

			//check that task has been added in correct order, comparing timed & deadline tasks
			string TestUserInput3 = "add settle accounts by 01/04/2014";
			TestInfoIdentifier.Identify(TestUserInput3);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
		
			Task test3 =*((_TestdataStorage.retrieveTaskList()).end());
			string str6 = "settle accounts";
			Assert::AreEqual(str6, test3.getEvent());

			//check that task has been added in correct order, comparing timed & floating tasks
			string TestUserInput4 = "add arrange music score";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);

			string TestUserInput5 = "add finish rearrangement by 02/04/2014 from 08:00 to 12:00";
			TestInfoIdentifier.Identify(TestUserInput4);
			TaskManager.pushCommand(TestInfoIdentifier.GetCommand(), TestInfoIdentifier, textUI, filename);
			
			Task test4 =*((_TestdataStorage.retrieveTaskList()).end());
			string str7 = "arrange music score";
			Assert::AreEqual(str7, test4.getEvent());
		}
		
		TEST_METHOD(testAddDeadlineTask) {
			//unit test for the addition of a deadline task
			//tests for correct initialisation of Task member attributes
			//tests correct order of two deadline tasks in data storage
			//tests correct order of deadline task and floating task in data storage

			string InputADT = "add see sunrise by 19/05/2011";
			Identifier IdentifierADT;
			File filename;
			VeriTask TaskManager(filename);
			IdentifierADT.Identify(InputADT);
			TextUI textUI;
			DataStorage _TestdataStorage = TaskManager.getDataStorage();
			Task test1 =*((_TestdataStorage.retrieveTaskList()).begin());

			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue(_TestdataStorage.retrieveTaskList().empty()); 

			TaskManager.pushCommand(IdentifierADT.GetCommand(), IdentifierADT, textUI, filename);
	
			//post-condition: data storage no longer empty after add
			Assert::IsFalse(_TestdataStorage.retrieveTaskList().empty());

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
			TaskManager.pushCommand(IdentifierADT.GetCommand(), IdentifierADT, textUI, filename);
			
			Task test2 =*((_TestdataStorage.retrieveTaskList()).begin());
			string str5 = "see sunset";
			Assert::AreEqual(str5, test2.getEvent());	

			//check that task has been added in correct order, comparing deadline & floating tasks
			string InputADT3 = "add watch Ghibli";
			IdentifierADT.Identify(InputADT3);
			TaskManager.pushCommand(IdentifierADT.GetCommand(), IdentifierADT, textUI, filename);

			string InputADT4 = "add see midnight by 19/03/2011";
			IdentifierADT.Identify(InputADT4);
			TaskManager.pushCommand(IdentifierADT.GetCommand(), IdentifierADT, textUI, filename);

			Task test3 =*((_TestdataStorage.retrieveTaskList()).end());
			string str6 = "watch Ghibli";
			Assert::AreEqual(str6, test3.getEvent());
		} 

		TEST_METHOD(testAddFloatingTask) {
			//unit test for the addition of a floating task
			//tests for correct initialisation of Task member attributes
			//tests correct order of two floating tasks in data storage

			string TestAFT = "add move house";
			Identifier TestInfoIdentifier1;
			File filenameAFT;
			VeriTask TaskManager1(filenameAFT);
			TestInfoIdentifier1.Identify(TestAFT);
			TextUI textUI;
			DataStorage _TestdataStorage = TaskManager1.getDataStorage();
			
			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue(_TestdataStorage.retrieveTaskList().empty()); 

			TaskManager1.pushCommand(TestInfoIdentifier1.GetCommand(), TestInfoIdentifier1, textUI, filenameAFT);
		
			//post-condition: data storage no longer empty after add
			Assert::IsFalse(_TestdataStorage.retrieveTaskList().empty());
			
			//check that attributes have been initialised correctly for floating tasks
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
			
			//check that task has been added in correct order, comparing 2 floating tasks
			string TestAFT2 = "add shift furniture";
			TestInfoIdentifier1.Identify(TestAFT2);
			TaskManager1.pushCommand(TestInfoIdentifier1.GetCommand(), TestInfoIdentifier1, textUI, filenameAFT);
			
			Task test2 =*((_TestdataStorage.retrieveTaskList()).end());
			string str5 = "shift furniture";
			Assert::AreEqual(test2.getEvent(), str5);
		}

		TEST_METHOD(testSearch) {
			//unit test for search
			//empty search
			//negative search: using each data attribute, using multiple attribute combinations
			//positive search: using each data attribute, using multiple attribute combinations
			//positive search: single result, multiple results
			//multiple attribute search treats multiple attributes as multiple AND conditions

			Identifier TestInfoIdentify;
			File filenameS;
			VeriTask TaskManagerS(filenameS);
			TextUI textUI;
			DataStorage _TestdataStorageS = TaskManagerS.getDataStorage();
			
			//pre-condition: empty data storage upon program initialisation
			Assert::IsTrue((_TestdataStorageS.retrieveTaskList().empty()));
			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());

			//empty search
			string emptysearch = "search growlithe";
			TestInfoIdentify.Identify(emptysearch);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);
			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());
		
			//add first task
			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			TestInfoIdentify.Identify(TestUserInput);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);

			//check that data storage no longer empty upon add
			Assert::IsFalse((_TestdataStorageS.retrieveTaskListToDisplay()).empty());

			//negative search
			string NegSearch1 = "search sunset";
			TestInfoIdentify.Identify(NegSearch1);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);

			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());

			string NegSearch2 = "search 23/05/2011";
			TestInfoIdentify.Identify(NegSearch1);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);

			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());

			string NegSearch3 = "search 19:00";
			TestInfoIdentify.Identify(NegSearch1);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);

			Assert::IsTrue((_TestdataStorageS.retrieveTaskListToDisplay()).empty());

			//positive search: single result
			string PosSearch1 = "search stargazing";
			TestInfoIdentify.Identify(PosSearch1);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);
			Task testS =*((_TestdataStorageS.retrieveTaskListToDisplay()).begin());
			string str1S = "stargazing session";
			Assert::AreEqual(testS.getEvent(), str1S); 

			string PosSearch2 = "search 31/05/2011";
			TestInfoIdentify.Identify(PosSearch2);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);
			Task testS =*((_TestdataStorageS.retrieveTaskListToDisplay()).begin());
			string str1S = "stargazing session";
			Assert::AreEqual(testS.getEvent(), str1S);

			string PosSearch3 = "search 19:30";
			TestInfoIdentify.Identify(PosSearch3);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);
			Task testS =*((_TestdataStorageS.retrieveTaskListToDisplay()).begin());
			string str1S = "stargazing session";
			Assert::AreEqual(testS.getEvent(), str1S);

			string PosSearch3 = "search 22:00";
			TestInfoIdentify.Identify(PosSearch3);
			TaskManagerS.pushCommand(TestInfoIdentify.GetCommand(), TestInfoIdentify, textUI, filenameS);
			Task testS =*((_TestdataStorageS.retrieveTaskListToDisplay()).begin());
			string str1S = "stargazing session";
			Assert::AreEqual(testS.getEvent(), str1S);
		}
		
		TEST_METHOD(testEditTimedTask) {
			//Note: floating task can be changed to deadline and timed task, but other type changes are not allowed

			//initialise task
			string TestUserInput = "add stargazing session on 31/05/2011 from 19:30 to 22:00";
			Identifier TestETTIdentifier;
			File filenameETT;
			VeriTask TaskManagerETT(filenameETT);
			TextUI textUI;
			DataStorage _TestdataStorageETT = TaskManagerETT.getDataStorage();

			TestETTIdentifier.Identify(TestUserInput);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI,filenameETT);
			
			string SearchCommand = "search stargazing";
			TestETTIdentifier.Identify(SearchCommand);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI,filenameETT);

			//edit timed task attributes
			string TestUserInput2 = "edit 1 sunset";
			TestETTIdentifier.Identify(TestUserInput2);
			TaskManagerETT.pushCommand(TestETTIdentifier.GetCommand(), TestETTIdentifier, textUI, filenameETT);
			
			Task test2 =*((_TestdataStorageETT.retrieveTaskListToDisplay()).begin());
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
			string TestUserInput6 = "edit 1 fireworks from 17:00";
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
			TestMarkIdentifier.Identify(testMark2);
			TaskManagerMark.pushCommand(TestMarkIdentifier.GetCommand(), TestMarkIdentifier, textUIMark, filenameMark);
			string testMarkStatus = "done";
			Assert::AreEqual(test2Mark.getStatus(), testMarkStatus);

			string testMark3 = "mark 1 cannot be done";
			TestMarkIdentifier.Identify(testMark3);
			TaskManagerMark.pushCommand(TestMarkIdentifier.GetCommand(), TestMarkIdentifier, textUIMark, filenameMark);
			string testMarkStatus2 = "cannot be done";
			Assert::AreEqual(test2Mark.getStatus(), testMarkStatus2);
		}

		TEST_METHOD(testDelete) {
			//unit test for delete function
			//checks for deletion of a single task
			//checks for deletion of first task in storage vector
			//checks for deletion of second task in storage vector
			//checks for deletion of a task located in middle of data storage vector
			//checks for deletion of second last task in data storage vector
			//checks for deletion of task at end of data storage vector

			string testDel = "add complete drawing";
			Identifier TestDelIdentifier;
			File filenameDel;
			VeriTask TaskManagerDel(filenameDel);
			TestDelIdentifier.Identify(testDel);
			TextUI textUIDel;
			DataStorage _TestdataStoreDel = TaskManagerDel.getDataStorage();

			//precondition: begin with empty data store
			Assert::IsTrue((_TestdataStoreDel.retrieveTaskList()).empty());  
			Assert::IsTrue((_TestdataStoreDel.retrieveTaskListToDisplay()).empty()); 

			TaskManagerDel.pushCommand(TestDelIdentifier.GetCommand(), TestDelIdentifier, textUIDel, filenameDel);
			
			//check that task has been added
			Assert::IsFalse((_TestdataStoreDel.retrieveTaskList()).empty()); 

			//deletion of a single task
			string testDel2 = "delete 1";
			TestDelIdentifier.Identify(testDel2);
			TaskManagerDel.pushCommand(TestDelIdentifier.GetCommand(), TestDelIdentifier, textUIDel, filenameDel);

			//post-condition: task has been deleted
			Assert::IsTrue((_TestdataStoreDel.retrieveTaskList()).empty()); 
		}

		
		TEST_METHOD(testUndo) {
				
		}

	};
}