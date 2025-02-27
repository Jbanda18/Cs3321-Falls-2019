#pragma once
#include "Students.h"
#include<iostream>
#include<string>
#include<fstream>
#include<msclr/marshal_cppstd.h>

namespace LMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		int adminFile(string username, string password);
		int studentFile(string studentUser, string studentPass);
		int userFile(string studentUser, string studentPass);
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^ button1;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(94, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(94, 127);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Username";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 134);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(20, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(252, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Learning Management System";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(94, 174);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 37);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click_1);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String ^ userRaw = textBox1->Text;
		String ^ passwordRaw = textBox2->Text;

		string username = msclr::interop::marshal_as<std::string>(userRaw);
		string password = msclr::interop::marshal_as<std::string>(passwordRaw);

		int checkLogin = adminFile(username, password);

		if (checkLogin == 1)
		{
			MessageBox::Show("Admin access granted");
		}
		else
			MessageBox::Show("Incorrect username or password");
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String ^ userRaw = textBox1->Text;
		String ^ passwordRaw = textBox2->Text;

		string studentUser = msclr::interop::marshal_as<std::string>(userRaw);
		string studentPass = msclr::interop::marshal_as<std::string>(passwordRaw);

		int checkLogin = studentFile(studentUser, studentPass);

		if (checkLogin == 1)
		{
			MessageBox::Show("Student access granted");
			this->Hide();
			Students^ studentWindow = gcnew Students;
			studentWindow->ShowDialog();
		}
		else
			MessageBox::Show("Incorrect username or password");
	}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {

	String^ userRaw = textBox1->Text;
	String^ passwordRaw = textBox2->Text;

	string Username = msclr::interop::marshal_as<std::string>(userRaw);
	string Password = msclr::interop::marshal_as<std::string>(passwordRaw);

	int userLogin = userFile(Username, Password);

	cout << userLogin;
	if (userLogin == 2)
	{
		MessageBox::Show("Admin access granted");
		///////Open Admin Page code here
	}
	else if (userLogin == 1)
	{
		MessageBox::Show("Student access granted");
		this->Hide();
		Students^ studentWindow = gcnew Students;
		studentWindow->ShowDialog();
	}
	else
		MessageBox::Show("Incorrect username or password");
};
};
}
