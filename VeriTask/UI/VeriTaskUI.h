#pragma once

#include "Identifier.h"
#include "VeriTask.h"
#include <vector>
#include <string.h>
#include <msclr/marshal_cppstd.h>
#include <cliext\vector>
#include "TextUI.h"
#include "File.h"

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

			 TextUI* _operationReport;

	public:
		VeriTaskUI(void)
		{
			InitializeComponent();
            File A;
			_newIdentifier = new Identifier; 
			_TaskManager = new VeriTask(A);
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VeriTaskUI::typeid));
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(22, 109);
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
			this->label2->Font = (gcnew System::Drawing::Font(L"AR BLANCA", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(194, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 39);
			this->label2->TabIndex = 1;
			this->label2->Text = L"VeriTask";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox1->Location = System::Drawing::Point(25, 127);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox1->Size = System::Drawing::Size(485, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &VeriTaskUI::textBox1_KeyDown);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(22, 216);
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
			this->dataGridView1->Location = System::Drawing::Point(25, 234);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(485, 235);
			this->dataGridView1->TabIndex = 4;
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
			this->button1->Location = System::Drawing::Point(435, 166);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"GO!";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &VeriTaskUI::button1_Click);
			// 
			// VeriTaskUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(532, 498);
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

				  File A;
				  _TaskManager->pushCommand(_newIdentifier->GetCommand(), *_newIdentifier, *_operationReport, A);
				 
				 //display the task in dataGridView after each operation

				 DataStorage AllStorage = _TaskManager->getDataStorage();
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
	};
}
