#pragma once

#include "Identifier.h"
#include "VeriTask.h"
#include <vector>
#include <string.h>
#include <msclr/marshal_cppstd.h>
#include <cliext\vector>
#include "TextUI.h"

namespace UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for VeriTaskUI
	/// </summary>
	public ref class VeriTaskUI : public System::Windows::Forms::Form{
	private:
		Identifier* _newIdentifier;
		VeriTask* _TaskManager;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  IndexCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  StatusCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DateCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  StartCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EndCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EventCol;
	private: System::Windows::Forms::TextBox^  textBox2;

			 TextUI* _operationReport;

	public:
		VeriTaskUI(void)
		{
			InitializeComponent();
            DataStorage dataStorage;
			_newIdentifier = new Identifier; 
			_TaskManager = new VeriTask(dataStorage);
			_operationReport = new TextUI;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VeriTaskUI()
		{
			if (components)
			{
				delete components;
				delete _newIdentifier;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->IndexCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StatusCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DateCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StartCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EndCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EventCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(22, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"I want to:";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(194, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 37);
			this->label2->TabIndex = 1;
			this->label2->Text = L"VeriTask";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox1->Location = System::Drawing::Point(25, 93);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox1->Size = System::Drawing::Size(485, 21);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &VeriTaskUI::textBox1_TextChanged);
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &VeriTaskUI::textBox1_KeyDown);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(22, 199);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 15);
			this->label3->TabIndex = 3;
			this->label3->Text = L"My VeriTasks";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::InactiveBorder;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Sunken;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->IndexCol, 
				this->StatusCol, this->DateCol, this->StartCol, this->EndCol, this->EventCol});
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ControlLight;
			this->dataGridView1->Location = System::Drawing::Point(25, 216);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(485, 217);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &VeriTaskUI::dataGridView1_CellContentClick);
			// 
			// IndexCol
			// 
			this->IndexCol->HeaderText = L"Index";
			this->IndexCol->Name = L"IndexCol";
			this->IndexCol->ReadOnly = true;
			this->IndexCol->Width = 50;
			// 
			// StatusCol
			// 
			this->StatusCol->HeaderText = L"Status";
			this->StatusCol->Name = L"StatusCol";
			this->StatusCol->ReadOnly = true;
			this->StatusCol->Width = 70;
			// 
			// DateCol
			// 
			this->DateCol->HeaderText = L"Date";
			this->DateCol->Name = L"DateCol";
			this->DateCol->ReadOnly = true;
			// 
			// StartCol
			// 
			this->StartCol->HeaderText = L"Start Time";
			this->StartCol->Name = L"StartCol";
			this->StartCol->ReadOnly = true;
			this->StartCol->Width = 150;
			// 
			// EndCol
			// 
			this->EndCol->HeaderText = L"End Time";
			this->EndCol->Name = L"EndCol";
			this->EndCol->ReadOnly = true;
			this->EndCol->Width = 150;
			// 
			// EventCol
			// 
			this->EventCol->HeaderText = L"Event";
			this->EventCol->Name = L"EventCol";
			this->EventCol->ReadOnly = true;
			this->EventCol->Width = 1000;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(435, 182);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 21);
			this->button1->TabIndex = 5;
			this->button1->Text = L"GO!";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &VeriTaskUI::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Location = System::Drawing::Point(24, 115);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox2->Size = System::Drawing::Size(485, 51);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &VeriTaskUI::textBox2_TextChanged);
			// 
			// VeriTaskUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 460);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"VeriTaskUI";
			this->Text = L"VeriTaskUI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyCode == Keys::Enter)
				  button1->PerformClick();
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			  //get input string and pass to identifier from testbox
				 std::string unmanagedInputString = marshal_as<std::string>(textBox1->Text);//convert managed string to native
				 _newIdentifier->Identify(unmanagedInputString);							//pass input to identifier
				  textBox1->Text = "";

				  DataStorage dataStorage;
				  _TaskManager->pushCommand(_newIdentifier->GetCommand(), *_newIdentifier, *_operationReport, dataStorage);
				 
				 //display the task in dataGridView after each operation

				 DataStorage AllStorage = dataStorage;

				 std::vector<Task> TaskVectorToDisplay = AllStorage.retrieveTaskListToDisplay();

				 int vecSize = TaskVectorToDisplay.size();
				 
				 //clear the previoue data
				 for(int i=0;i<vecSize;i++){
					 dataGridView1->Rows->Clear();
				 }
				 //print updated data
				 for(int taskIndex = 0;taskIndex<vecSize;taskIndex++){
					 dataGridView1->Rows->Add();
					 dataGridView1->Rows[taskIndex]->Cells[0]->Value = (taskIndex+1).ToString();
					 for(int cellIndex = 1;cellIndex<=6;cellIndex++){
						 if(cellIndex == 1){
							String^ managedStatus = gcnew String(TaskVectorToDisplay.at(taskIndex).getStatus().c_str());
							dataGridView1->Rows[taskIndex]->Cells[cellIndex]->Value = managedStatus;
						 }
						 if(cellIndex == 2){
							 String^ managedDate = gcnew String(TaskVectorToDisplay.at(taskIndex).getDate().c_str());
							 dataGridView1->Rows[taskIndex]->Cells[cellIndex]->Value = managedDate;
						 }
						 else if(cellIndex == 3){
							 String^ managedStartTime = gcnew String(TaskVectorToDisplay.at(taskIndex).getStartTime().c_str());
							 dataGridView1->Rows[taskIndex]->Cells[cellIndex]->Value = managedStartTime;
						 }
						 else if(cellIndex == 4){
							String^ managedEndTime = gcnew String(TaskVectorToDisplay.at(taskIndex).getEndTime().c_str());
							dataGridView1->Rows[taskIndex]->Cells[cellIndex]->Value = managedEndTime;
						 }
						 else if(cellIndex == 5){
		//					 MessageBox::Show(gcnew String(TaskVectorToDisplay.at(taskIndex).getEvent().c_str()));
							String^ managedEvent = gcnew String(TaskVectorToDisplay.at(taskIndex).getEvent().c_str());
							dataGridView1->Rows[taskIndex]->Cells[cellIndex]->Value = managedEvent;
						 }
					 }
				 }
		 }
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			  textBox2->Text = "add, delete, edit, search, mark, undo";
			 if (textBox1->Text != "") {
			 
			 std::string unmanagedInputString = marshal_as<std::string>(textBox1->Text);//convert managed string to native
			 _newIdentifier->Identify(unmanagedInputString); //pass input to identifier
			 
			 string str1 = "Command: " + _newIdentifier->GetCommand();
			 string str2 = "Date: " + _newIdentifier->GetDate() + " Event: " + _newIdentifier->GetEvent()
				            + " StartTime: " + _newIdentifier->GetStartTime()+ " EtartTime: " + _newIdentifier->GetEndTime();
			
			 textBox2->Text = gcnew String((str1 + "\r\n" + str2).c_str());
			 } else {
			       textBox2->Text = "add, delete, edit, search, mark, undo";
			 }
		 }
};
}
