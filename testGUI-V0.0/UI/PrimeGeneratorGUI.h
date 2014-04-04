//statusstrip display error message, vld check memory leak


#pragma once
#include "PrimeGenerator.h"
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
	/// Summary for PrimeGeneratorGUI
	/// </summary>
	public ref class PrimeGeneratorGUI : public System::Windows::Forms::Form{
	private: 
		PrimeGenerator* _myGenerator;
	public:
		PrimeGeneratorGUI(void){
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_myGenerator = new PrimeGenerator();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PrimeGeneratorGUI(){
			if (components){
				delete _myGenerator;
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  listBox1;

	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PrimeGeneratorGUI::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Location = System::Drawing::Point(12, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Your Task";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Location = System::Drawing::Point(15, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"blahblah";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(657, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Click += gcnew System::EventHandler(this, &PrimeGeneratorGUI::textBox1_Click);
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &PrimeGeneratorGUI::textBox1_TextChanged);
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PrimeGeneratorGUI::textBox1_KeyDown);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(686, 49);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PrimeGeneratorGUI::button1_Click);
			this->button1->Enter += gcnew System::EventHandler(this, &PrimeGeneratorGUI::button1_Click);
			this->button1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PrimeGeneratorGUI::button1_KeyDown);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->Location = System::Drawing::Point(12, 109);
			this->listBox1->Name = L"listBox1";
			this->listBox1->ScrollAlwaysVisible = true;
			this->listBox1->Size = System::Drawing::Size(749, 225);
			this->listBox1->TabIndex = 0;
			// 
			// PrimeGeneratorGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(876, 385);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"PrimeGeneratorGUI";
			this->Text = L"PrimeGeneratorGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 std::string managedInputString = marshal_as<std::string>(textBox1->Text);
				 _myGenerator->setString(managedInputString);
				 textBox1->Text = "";
			 
			std::string myStdString = _myGenerator->getResultString();
			//cliext::vector<String^>^ myCliVector = gcnew cliext::vector<String^>;
			
			int size = myStdString.size();				//convert std::vector to cliext::vector
			/*myCliVector->reserve(size);
			std::string::iterator itStd = myStdString.begin();
			
			for(;itStd!=myStdString.end();itStd++){		//convert std::string to managed string and copy to cliext::vector
				String^ managedStr = gcnew String((*itStd).c_str());
				myCliVector->push_back(managedStr);
			}

			if(myCliVector == nullptr){
				String^ title = "error";
				MessageBox::Show("Fuuuuuck",title,MessageBoxButtons:: OK);
			}
			*/
			String^ managedResultString = gcnew String(myStdString.c_str());
			listBox1->Items->Add(managedResultString);
			/*else if(myCliVector!= nullptr){
				for(int i=1;i<= size;i++){
						String^ indexStr = i.ToString();
						listBox1->Items->Add(indexStr + myCliVector->at(i-1));
					}
				}*/
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox1_Click(System::Object^  sender, System::EventArgs^  e) {


		 }
private: System::Void button1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 
		 }
private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			  if(e->KeyCode == Keys::Enter)
				  button1->PerformClick();
		 }

};
}
