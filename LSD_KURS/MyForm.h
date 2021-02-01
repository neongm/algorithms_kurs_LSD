#pragma once
#include <vector>
#include <string>
#include "radix.h" // sorting algorithm itself
#include "random_generator.h"  
#include "converters.h" // for custom-made converters that makes my life better
#include <chrono> // for timing

namespace LSDKURS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	std::vector<int> GL_VEC;            // defining some useful values
	int RAND_RANGE_MIN;
	int RAND_RANGE_MAX;
	int RAND_ARRAY_SIZE;
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:                                  

	private: System::Windows::Forms::Button^ run_sort;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ fill_array_button;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::ListBox^ listBox1;
	public:

	public:
		;
		MyForm(void)
		{
			InitializeComponent();
		};

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ DEBUG_BOX;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ rand_array_size_field;


	private: System::Windows::Forms::NumericUpDown^ rand_range_max_field;

	private: System::Windows::Forms::NumericUpDown^ rand_range_min_field;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->fill_array_button = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->run_sort = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->rand_array_size_field = (gcnew System::Windows::Forms::NumericUpDown());
			this->rand_range_max_field = (gcnew System::Windows::Forms::NumericUpDown());
			this->rand_range_min_field = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->DEBUG_BOX = (gcnew System::Windows::Forms::ListBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_array_size_field))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_range_max_field))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_range_min_field))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(0, -1);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(789, 403);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->fill_array_button);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Controls->Add(this->run_sort);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4);
			this->tabPage1->Size = System::Drawing::Size(781, 374);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L" метод LSD";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 68);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 16);
			this->label4->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(7, 39);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(326, 26);
			this->button4->TabIndex = 3;
			this->button4->Text = L"вывести массив";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// fill_array_button
			// 
			this->fill_array_button->Location = System::Drawing::Point(7, 7);
			this->fill_array_button->Name = L"fill_array_button";
			this->fill_array_button->Size = System::Drawing::Size(159, 26);
			this->fill_array_button->TabIndex = 2;
			this->fill_array_button->Text = L"заполнить массив";
			this->fill_array_button->UseVisualStyleBackColor = true;
			this->fill_array_button->Click += gcnew System::EventHandler(this, &MyForm::fill_array_button_Click);
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(339, 7);
			this->listBox1->MultiColumn = true;
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(435, 356);
			this->listBox1->TabIndex = 1;
			// 
			// run_sort
			// 
			this->run_sort->Enabled = false;
			this->run_sort->Location = System::Drawing::Point(172, 7);
			this->run_sort->Name = L"run_sort";
			this->run_sort->Size = System::Drawing::Size(161, 26);
			this->run_sort->TabIndex = 0;
			this->run_sort->Text = L"отсортировать";
			this->run_sort->UseVisualStyleBackColor = true;
			this->run_sort->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4);
			this->tabPage2->Size = System::Drawing::Size(781, 374);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"уравнение св€зи";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button6);
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Controls->Add(this->button3);
			this->tabPage3->Controls->Add(this->rand_array_size_field);
			this->tabPage3->Controls->Add(this->rand_range_max_field);
			this->tabPage3->Controls->Add(this->rand_range_min_field);
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Controls->Add(this->label2);
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Controls->Add(this->button2);
			this->tabPage3->Controls->Add(this->button1);
			this->tabPage3->Controls->Add(this->DEBUG_BOX);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(781, 374);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"панель отладки";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button5->Location = System::Drawing::Point(615, 270);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(160, 28);
			this->button5->TabIndex = 10;
			this->button5->Text = L"fill array";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(615, 304);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(160, 29);
			this->button3->TabIndex = 9;
			this->button3->Text = L"run sort (untimed)";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// rand_array_size_field
			// 
			this->rand_array_size_field->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->rand_array_size_field->Location = System::Drawing::Point(615, 121);
			this->rand_array_size_field->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->rand_array_size_field->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->rand_array_size_field->Name = L"rand_array_size_field";
			this->rand_array_size_field->Size = System::Drawing::Size(158, 23);
			this->rand_array_size_field->TabIndex = 8;
			this->rand_array_size_field->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// rand_range_max_field
			// 
			this->rand_range_max_field->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->rand_range_max_field->Location = System::Drawing::Point(613, 76);
			this->rand_range_max_field->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { -1, 0, 0, 0 });
			this->rand_range_max_field->Name = L"rand_range_max_field";
			this->rand_range_max_field->Size = System::Drawing::Size(160, 23);
			this->rand_range_max_field->TabIndex = 7;
			// 
			// rand_range_min_field
			// 
			this->rand_range_min_field->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->rand_range_min_field->Location = System::Drawing::Point(613, 27);
			this->rand_range_min_field->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { -6, 0, 0, 0 });
			this->rand_range_min_field->Name = L"rand_range_min_field";
			this->rand_range_min_field->Size = System::Drawing::Size(160, 23);
			this->rand_range_min_field->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(614, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"RAND_ARRAY_SIZE";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(614, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(138, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"RAND_RANGE_MAX";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(614, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(133, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"RAND_RANGE_MIN";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(613, 150);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 29);
			this->button2->TabIndex = 2;
			this->button2->Text = L"send consts";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(615, 339);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"clear debug values";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// DEBUG_BOX
			// 
			this->DEBUG_BOX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DEBUG_BOX->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->DEBUG_BOX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DEBUG_BOX->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DEBUG_BOX->ForeColor = System::Drawing::SystemColors::Window;
			this->DEBUG_BOX->FormattingEnabled = true;
			this->DEBUG_BOX->ItemHeight = 15;
			this->DEBUG_BOX->Location = System::Drawing::Point(6, 6);
			this->DEBUG_BOX->Name = L"DEBUG_BOX";
			this->DEBUG_BOX->Size = System::Drawing::Size(603, 345);
			this->DEBUG_BOX->TabIndex = 0;
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button6->Location = System::Drawing::Point(615, 236);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(160, 28);
			this->button6->TabIndex = 11;
			this->button6->Text = L"clear array";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(789, 399);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(500, 400);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_array_size_field))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_range_max_field))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_range_min_field))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
		// debug box handlers
		void dh(std::string message) { DEBUG_BOX -> Items -> Insert(DEBUG_BOX -> Items -> Count, cs(message)); }
		void dh(String^ message) { DEBUG_BOX -> Items -> Insert(DEBUG_BOX -> Items -> Count, message); }
		void dh_clear() { DEBUG_BOX -> Items -> Clear(); }
		// debug box handlers end

		void vec_to_listbox(const std::vector<int>& vec) {              // it uses gloval variable
			listBox1->Items->Clear();
			for (size_t i = 0; i < vec.size(); i++)
				listBox1->Items->Insert(listBox1->Items->Count, cs(s(listBox1->Items->Count) + ": " + s(vec.at(i))));
		}

		void global_vec_clear() {	GL_VEC.clear();	dh("global_vec_clear()");	verify(); }
		void global_vec_fill()  {	rnd::fill_random_integers(GL_VEC, RAND_ARRAY_SIZE, RAND_RANGE_MIN, RAND_RANGE_MAX); dh("global_vec_fill()"); 	verify();	}
		void global_vec_show()  {	vec_to_listbox(GL_VEC); dh("global_vec_show()"); }
		void global_vec_sort()  {	Radix(GL_VEC); dh("global_vec_sort()");}

		void verify() {
			run_sort -> Enabled = (GL_VEC.size() != 0);
			button4 -> Enabled = (GL_VEC.size() != 0);
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {  // CLEAR THE DEBUG BOX
		dh_clear();
	}


private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {        // ONLOAD EVENT
	dh("MyForm_Load event");

	// setting constants 
	RAND_RANGE_MIN = 0;
	rand_range_min_field->Value = RAND_RANGE_MIN;
	dh("RAND_RANGE_MIN set to "+s(RAND_RANGE_MIN));

	RAND_RANGE_MAX = 1000;
	rand_range_max_field->Value = RAND_RANGE_MAX;
	dh("RAND_RANGE_MAX set to " + s(RAND_RANGE_MAX));

	RAND_ARRAY_SIZE = 12000;
	rand_array_size_field->Value = RAND_ARRAY_SIZE;
	dh("RAND_ARRAY_SIZE set to " + s(RAND_ARRAY_SIZE));
}



private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {      // SEND CONSTS EVENT

	if (RAND_RANGE_MIN != decToInt(rand_range_min_field->Value)) 
	{
		RAND_RANGE_MIN = decToInt(rand_range_min_field->Value);
		dh("RAND_RANGE_MIN set to " + s(RAND_RANGE_MIN));
	}

	if (RAND_RANGE_MAX != decToInt(rand_range_max_field->Value))
	{
		RAND_RANGE_MAX = decToInt(rand_range_max_field->Value);
		dh("RAND_RANGE_MAX set to " + s(RAND_RANGE_MAX));
	}

	if (RAND_ARRAY_SIZE != decToInt(rand_array_size_field->Value))
	{
		RAND_ARRAY_SIZE = decToInt(rand_array_size_field->Value);
		dh("RAND_ARRAY_RANGE set to " + s(RAND_ARRAY_SIZE));
	}
}

	   void run_test()
	   {                           // 0 - main array read, 1 - main array write, 2 - auxiliary array read, 3 - auxiliary array write
		   dh("array size: " + s(RAND_ARRAY_SIZE));
		   dh("minimum: " + s(RAND_RANGE_MIN));
		   dh("maximum: " + s(RAND_RANGE_MAX));

		   auto begin = std::chrono::steady_clock::now();
		   auto c = RadixCount(GL_VEC);
		   auto end = std::chrono::steady_clock::now();
		   auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

		   dh("main array reads:" + c[0]);
		   dh("main array writes:" + c[1]);
		   dh("auxiliary array writes:" + c[3]);
		   dh("TOTAL SORTING TIME: " + s(elapsed_ms) + " ms"); 

		   label4->Text = cs("длительность последней сортировки: " + s(elapsed_ms) + " ms");
	   }

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)   // RUN SORT BUTTON
{  
	dh(""); dh("run sort event");
	if (GL_VEC.size() != 0) run_test();
	else dh("error: GL_VEC is empty");
}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e)  // RUN SORT UNDER DEBUG BUTTON
{
	dh(""); dh("run sort debug event");
	if (GL_VEC.size() != 0) global_vec_sort();
	else dh("error: GL_VEC is empty");
}
private: System::Void fill_array_button_Click(System::Object^ sender, System::EventArgs^ e) {
	global_vec_fill();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	global_vec_show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	global_vec_fill();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	global_vec_clear();
}
};
}
