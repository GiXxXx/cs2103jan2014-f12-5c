#pragma once

#include "Identifier.h"
#include "VeriTask.h"
#include "TextUI.h"
#include <vector>
#include <string.h>
#include <msclr/marshal_cppstd.h>
#include <cliext\vector>


namespace UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for VeriTaskGUI
	/// </summary>
	public ref class VeriTaskGUI : public System::Windows::Forms::Form
	{
	private: 
		Identifier *newIdentifier;
		DataStorage *dataStorage;
		VeriTask* taskManager;

	    private: bool *_dragging;
		private: Point *_offset;
		private: Point *_start_point;

	private: 
		System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::Button^  closeButton;
	private: System::Windows::Forms::Button^  minimizeButton;
	private: System::Windows::Forms::Label^  VeriTaskTitle;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

			 TextUI* textUI;

	public:
		VeriTaskGUI(void)
		{
			InitializeComponent();

			_dragging = new bool(false);
			_start_point = new Point(0, 0);
			
			newIdentifier = new Identifier;
			taskManager = new VeriTask;
			textUI = new TextUI; 
			dataStorage = new DataStorage ;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VeriTaskGUI()
		{
			if (components)
			{
				delete components;
				delete newIdentifier;
			//	delete dataStorage;
				delete taskManager;
				delete textUI;
			}
		}
	private: System::Windows::Forms::ListView^  taskSheet;
	protected: 

	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::TextBox^  commandBox;

	private: System::Windows::Forms::TextBox^  feedbackBox;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VeriTaskGUI::typeid));
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->taskSheet = (gcnew System::Windows::Forms::ListView());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->commandBox = (gcnew System::Windows::Forms::TextBox());
			this->feedbackBox = (gcnew System::Windows::Forms::TextBox());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->minimizeButton = (gcnew System::Windows::Forms::Button());
			this->VeriTaskTitle = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"No.";
			this->columnHeader1->Width = 33;
			// 
			// taskSheet
			// 
			this->taskSheet->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->taskSheet->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->columnHeader1, this->columnHeader2, 
				this->columnHeader3, this->columnHeader4});
			this->taskSheet->Font = (gcnew System::Drawing::Font(L"SketchFlow Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->taskSheet->FullRowSelect = true;
			this->taskSheet->GridLines = true;
			this->taskSheet->Location = System::Drawing::Point(85, 96);
			this->taskSheet->Name = L"taskSheet";
			this->taskSheet->Size = System::Drawing::Size(393, 364);
			this->taskSheet->TabIndex = 0;
			this->taskSheet->UseCompatibleStateImageBehavior = false;
			this->taskSheet->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Event";
			this->columnHeader2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->columnHeader2->Width = 212;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Date";
			this->columnHeader3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->columnHeader3->Width = 64;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Time";
			this->columnHeader4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->columnHeader4->Width = 81;
			// 
			// commandBox
			// 
			this->commandBox->BackColor = System::Drawing::SystemColors::Window;
			this->commandBox->Font = (gcnew System::Drawing::Font(L"SketchFlow Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->commandBox->Location = System::Drawing::Point(85, 488);
			this->commandBox->Name = L"commandBox";
			this->commandBox->Size = System::Drawing::Size(393, 20);
			this->commandBox->TabIndex = 1;
			this->commandBox->TextChanged += gcnew System::EventHandler(this, &VeriTaskGUI::commandBox_TextChanged);
			this->commandBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &VeriTaskGUI::commandBox_KeyDown);
			// 
			// feedbackBox
			// 
			this->feedbackBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->feedbackBox->Font = (gcnew System::Drawing::Font(L"SketchFlow Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackBox->Location = System::Drawing::Point(85, 509);
			this->feedbackBox->Multiline = true;
			this->feedbackBox->Name = L"feedbackBox";
			this->feedbackBox->Size = System::Drawing::Size(393, 64);
			this->feedbackBox->TabIndex = 2;
			// 
			// closeButton
			// 
			this->closeButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->closeButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->closeButton->FlatAppearance->BorderSize = 0;
			this->closeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"closeButton.Image")));
			this->closeButton->Location = System::Drawing::Point(463, 19);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(23, 21);
			this->closeButton->TabIndex = 3;
			this->closeButton->UseVisualStyleBackColor = false;
			this->closeButton->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VeriTaskGUI::closeButton_MouseClick);
			// 
			// minimizeButton
			// 
			this->minimizeButton->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->minimizeButton->FlatAppearance->BorderSize = 0;
			this->minimizeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minimizeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"minimizeButton.Image")));
			this->minimizeButton->Location = System::Drawing::Point(436, 19);
			this->minimizeButton->Name = L"minimizeButton";
			this->minimizeButton->Size = System::Drawing::Size(24, 21);
			this->minimizeButton->TabIndex = 4;
			this->minimizeButton->UseVisualStyleBackColor = false;
			this->minimizeButton->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VeriTaskGUI::minimizeButton_MouseClick);
			// 
			// VeriTaskTitle
			// 
			this->VeriTaskTitle->AutoSize = true;
			this->VeriTaskTitle->BackColor = System::Drawing::Color::White;
			this->VeriTaskTitle->Font = (gcnew System::Drawing::Font(L"SketchFlow Print", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->VeriTaskTitle->Location = System::Drawing::Point(171, 37);
			this->VeriTaskTitle->Name = L"VeriTaskTitle";
			this->VeriTaskTitle->Size = System::Drawing::Size(218, 51);
			this->VeriTaskTitle->TabIndex = 5;
			this->VeriTaskTitle->Text = L"VeriTask";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"SketchFlow Print", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(83, 463);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 11);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Undone - Black";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"SketchFlow Print", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(184, 463);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 11);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Done - Grey";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"SketchFlow Print", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(265, 463);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 11);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Overdue - Red";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"SketchFlow Print", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(355, 463);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(123, 11);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Cannot be done - Blue";
			// 
			// VeriTaskGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(532, 621);
			this->ControlBox = false;
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->VeriTaskTitle);
			this->Controls->Add(this->closeButton);
			this->Controls->Add(this->feedbackBox);
			this->Controls->Add(this->commandBox);
			this->Controls->Add(this->taskSheet);
			this->Controls->Add(this->minimizeButton);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"VeriTaskGUI";
			this->Text = L"VeriTaskGUI";
			this->Load += gcnew System::EventHandler(this, &VeriTaskGUI::VeriTaskGUI_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VeriTaskGUI::VeriTaskGUI_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VeriTaskGUI::VeriTaskGUI_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VeriTaskGUI::VeriTaskGUI_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void VeriTaskGUI_Load(System::Object^  sender, System::EventArgs^  e) {
				// this->SetStyle(System::Windows::Forms::ControlStyles::SupportsTransparentBackColor, true);
               //  this->BackColor = System::Drawing::Color::Transparent;
				 feedbackBox->Text = "add, delete, edit, search, mark, display, undo";
				 vector<Task> TaskVectorToDisplay = dataStorage->retrieveTaskListToDisplay();
				 unsigned int itemNum = TaskVectorToDisplay.size();
				 for (unsigned int taskIndex=0; taskIndex< itemNum; taskIndex++) {
					 String^ index =(taskIndex+1).ToString(); 
					 ListViewItem^ newTask = gcnew ListViewItem(index);
					 newTask->SubItems->Add(gcnew String(TaskVectorToDisplay[taskIndex].getEvent().c_str()));
					 newTask->SubItems->Add(gcnew String(TaskVectorToDisplay[taskIndex].getDate().c_str()));
				     string startTime = TaskVectorToDisplay[taskIndex].getStartTime();
					 string endTime = TaskVectorToDisplay[taskIndex].getEndTime();
					 string status = TaskVectorToDisplay[taskIndex].getStatus();
					 string str;
					 if (endTime == "    ") {
						 str = startTime;
					 } else {
						 str = startTime + "-" + endTime;
					 }
					 newTask->SubItems->Add(gcnew String(str.c_str()));

					 if (status == UnDone) {
						 newTask->ForeColor = Color::Black;
					 }
					 if (status == Done) {
						 newTask->ForeColor = Color::Blue;
					 }
					 if (status == CannotBeDone) {
						 newTask->ForeColor = Color::Yellow;
					 }
					 if (status == overdue) {
						 newTask->ForeColor = Color::DarkRed;
					 }

					 taskSheet->Items->Add(newTask);
				 }
		 }

    private: System::Void commandBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if(e->KeyCode == Keys::Enter) {
				 if (commandBox->Text == "exit") {
					 this->Close();
				 }

				 vector<Task> TaskVectorToDisplay = dataStorage->retrieveTaskListToDisplay();
				 unsigned int itemNum = TaskVectorToDisplay.size();
				 for (unsigned int i = 0; i < TaskVectorToDisplay.size(); i++){
					 taskSheet->Items->Clear();
				 }

				 std::string unmanagedInputString = marshal_as<std::string>(commandBox->Text);
			     newIdentifier->Identify(unmanagedInputString); 
				 std::string command = newIdentifier->GetCommand();
				 taskManager->pushCommand(command, *newIdentifier, *textUI, *dataStorage);
				 TaskVectorToDisplay = dataStorage->retrieveTaskListToDisplay();
				 itemNum = TaskVectorToDisplay.size();
				 for (unsigned int taskIndex=0; taskIndex< itemNum; taskIndex++) {
					 String^ index =(taskIndex+1).ToString(); 
					 ListViewItem^ newTask = gcnew ListViewItem(index);
					 newTask->SubItems->Add(gcnew String(TaskVectorToDisplay[taskIndex].getEvent().c_str()));
					 newTask->SubItems->Add(gcnew String(TaskVectorToDisplay[taskIndex].getDate().c_str()));
				     string startTime = TaskVectorToDisplay[taskIndex].getStartTime();
					 string endTime = TaskVectorToDisplay[taskIndex].getEndTime();
					 string status = TaskVectorToDisplay[taskIndex].getStatus();
					 string str;
					 if (endTime == "    ") {
						 str = startTime;
					 } else {
						 str = startTime + "-" + endTime;
					 }
					 newTask->SubItems->Add(gcnew String(str.c_str()));

					 if (status == UnDone) {
						 newTask->ForeColor = Color::Black;
					 }
					 if (status == Done) {
						 newTask->ForeColor = Color::Gray;
					 }
					 if (status == CannotBeDone) {
						 newTask->ForeColor = Color::Blue;
					 }
					 if (status == overdue) {
						 newTask->ForeColor = Color::DarkRed;
					 }

					 taskSheet->Items->Add(newTask);
					
				 }
				 commandBox->Text = "";
		}
	}


    private: System::Void commandBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 feedbackBox->Text = "add, delete, edit, search, mark, display, undo, redo, exit";
			 
			 if (taskSheet->Text == "") {
			 feedbackBox->Text = "add, delete, edit, search, mark, display, undo, redo, exit";
			 }

			 std::string unmanagedInputString = marshal_as<std::string>(commandBox->Text);
			 newIdentifier->Identify(unmanagedInputString); 
			 
			 if (newIdentifier->GetCommand() == "add") {
			 
			 string str1 = "Command: " + newIdentifier->GetCommand();
			 string str2 = "Date: " + newIdentifier->GetDate() + " StartTime: " + newIdentifier->GetStartTime()+ " EndTime: " + newIdentifier->GetEndTime(); 
			 string str3 = "Event: " + newIdentifier->GetEvent();
			
			 feedbackBox->Text = gcnew String((str1 + "\r\n" + str2 + "\r\n" + str3).c_str());
			 } 
			 
			 if (newIdentifier->GetCommand() == "delete") {
			 string str1 = "Command: " + newIdentifier->GetCommand();
			 string str2 = "Task Number: " + newIdentifier->GetTaskNum();
			 feedbackBox->Text = gcnew String((str1 + "\r\n" + str2).c_str());
			 }

			 if (newIdentifier->GetCommand() == "search") {
			 string str1 = "Command: " + newIdentifier->GetCommand();
			 string str2 = "Keyword: " + newIdentifier->GetKeyword();
			 feedbackBox->Text = gcnew String((str1 + "\r\n" + str2).c_str());
			 }

			 if (newIdentifier->GetCommand() == "mark") {
			 
			 string str1 = "Command: " + newIdentifier->GetCommand();
			 string str2 = "Task Number: " + newIdentifier->GetTaskNum();
			 string str3 = "Status: " + newIdentifier->GetStatus();
			 feedbackBox->Text = gcnew String((str1 + "\r\n" + str2+ "\r\n" + str3).c_str());
			 }

			 if (newIdentifier->GetCommand() == "edit") {
			 
			 string str1 = "Command: " + newIdentifier->GetCommand();
			 string str2 = "Task Number: " + newIdentifier->GetTaskNum();
			 string str3 = "Date Modification: " + newIdentifier->GetDate() + "StartTime Modification: " + newIdentifier->GetStartTime() + " EndTime Modification: " + newIdentifier->GetEndTime();
			 string str4 = "Event Modification: " + newIdentifier->GetEvent();
			 feedbackBox->Text = gcnew String((str1 + "\r\n" + str2 + "\r\n" + str3 + "\r\n" + str4).c_str());
			 }
			 
			 if (newIdentifier->GetCommand() == "display") {
			 
			 string str1 = "Command: " + newIdentifier->GetCommand();
			 string str2 = "Task Condition: " + newIdentifier->GetStatus();
			 string str3 = "Date of task to be displayed: " + newIdentifier->GetDate();
			 feedbackBox->Text = gcnew String((str1 + "\r\n" + str2 + "\r\n" + str3).c_str());
			 }
			 
			 if (newIdentifier->GetCommand() == "undo") {
			 
			 string str1 = "Command: " + newIdentifier->GetCommand();
			 feedbackBox->Text = gcnew String(str1.c_str());
			 }

			 if (newIdentifier->GetCommand() == "redo") {
			 
			 string str1 = "Command: " + newIdentifier->GetCommand();
			 feedbackBox->Text = gcnew String(str1.c_str());
			 }

			 if (newIdentifier->GetCommand() == "exit") {
			 
			 string str1 = "Command: " + newIdentifier->GetCommand();
			 feedbackBox->Text = gcnew String(str1.c_str());
			 }
	}


private: System::Void closeButton_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 this->Close();
}
private: System::Void minimizeButton_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 this->WindowState = FormWindowState::Minimized;
}
private: System::Void VeriTaskGUI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 *_dragging = true;
			 _start_point = new Point(-e->X, -e->Y);
}
private: System::Void VeriTaskGUI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 *_dragging = false;
}
private: System::Void VeriTaskGUI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (*_dragging) {
				 Point mousePosition = Control::MousePosition;
				 mousePosition.Offset(_start_point->X, _start_point->Y);
				 this->Location = mousePosition;
			 }
}

};
}
