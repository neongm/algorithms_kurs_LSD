#pragma once
#include <vector>
#include <string>
#include "radix.h" // sorting algorithm itself
#include "random_generator.h"  
#include "converters.h" // for custom-made converters that makes my life better
#include <chrono> // for timing
#include "benchmark_result.h"
#include "correlation_coef.h"

std::vector<int> GL_VEC;            // defining some useful values
std::vector<benchmark_result> GL_RESULTS;
int RAND_RANGE_MIN;
int RAND_RANGE_MAX;
int RAND_ARRAY_SIZE;
analysis::calculate GL_ANALYZER;

size_t DH_AUTOCLEAR_LIMIT = 200;

namespace LSDKURS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Panel^ results_panel;
	private: System::Windows::Forms::Panel^ panel1;


	private: System::Windows::Forms::DataVisualization::Charting::Chart^ main_result_graph;

	private: System::Windows::Forms::DataGridView^ main_data_table;




	private: System::Windows::Forms::Button^ calculate_the_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ elements_amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ elements_amount_squared;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ elements_amount_multiplied_by_time;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ LABEL_coefficient_of_determination;

	private: System::Windows::Forms::Label^ LABEL_coefficient_of_correlation;
	private: System::Windows::Forms::Label^ LABEL_mid_quad_deviation_x;
	private: System::Windows::Forms::CheckBox^ check_box_autoclear;
	private: System::Windows::Forms::Label^ label_main_array_read;


	private: System::Windows::Forms::Label^ label_swaps;

	private: System::Windows::Forms::Label^ label_comparisons;
	private: System::Windows::Forms::Label^ label_main_array_writes;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label_equasion;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel3;









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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label_main_array_writes = (gcnew System::Windows::Forms::Label());
			this->label_main_array_read = (gcnew System::Windows::Forms::Label());
			this->label_swaps = (gcnew System::Windows::Forms::Label());
			this->label_comparisons = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->fill_array_button = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->run_sort = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->results_panel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->LABEL_mid_quad_deviation_x = (gcnew System::Windows::Forms::Label());
			this->LABEL_coefficient_of_determination = (gcnew System::Windows::Forms::Label());
			this->LABEL_coefficient_of_correlation = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->calculate_the_table = (gcnew System::Windows::Forms::Button());
			this->main_result_graph = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->main_data_table = (gcnew System::Windows::Forms::DataGridView());
			this->elements_amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->elements_amount_squared = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->elements_amount_multiplied_by_time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->check_box_autoclear = (gcnew System::Windows::Forms::CheckBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
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
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label_equasion = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->results_panel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_result_graph))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_data_table))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_array_size_field))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_range_max_field))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_range_min_field))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
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
			this->tabControl1->Size = System::Drawing::Size(981, 561);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label_main_array_writes);
			this->tabPage1->Controls->Add(this->label_main_array_read);
			this->tabPage1->Controls->Add(this->label_swaps);
			this->tabPage1->Controls->Add(this->label_comparisons);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->fill_array_button);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Controls->Add(this->run_sort);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4);
			this->tabPage1->Size = System::Drawing::Size(973, 532);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L" метод LSD";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label_main_array_writes
			// 
			this->label_main_array_writes->AutoSize = true;
			this->label_main_array_writes->Location = System::Drawing::Point(11, 164);
			this->label_main_array_writes->Name = L"label_main_array_writes";
			this->label_main_array_writes->Size = System::Drawing::Size(46, 16);
			this->label_main_array_writes->TabIndex = 8;
			this->label_main_array_writes->Text = L"label7";
			// 
			// label_main_array_read
			// 
			this->label_main_array_read->AutoSize = true;
			this->label_main_array_read->Location = System::Drawing::Point(11, 148);
			this->label_main_array_read->Name = L"label_main_array_read";
			this->label_main_array_read->Size = System::Drawing::Size(46, 16);
			this->label_main_array_read->TabIndex = 7;
			this->label_main_array_read->Text = L"label7";
			// 
			// label_swaps
			// 
			this->label_swaps->AutoSize = true;
			this->label_swaps->Location = System::Drawing::Point(11, 132);
			this->label_swaps->Name = L"label_swaps";
			this->label_swaps->Size = System::Drawing::Size(46, 16);
			this->label_swaps->TabIndex = 6;
			this->label_swaps->Text = L"label6";
			// 
			// label_comparisons
			// 
			this->label_comparisons->AutoSize = true;
			this->label_comparisons->Location = System::Drawing::Point(11, 116);
			this->label_comparisons->Name = L"label_comparisons";
			this->label_comparisons->Size = System::Drawing::Size(46, 16);
			this->label_comparisons->TabIndex = 5;
			this->label_comparisons->Text = L"label5";
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
			this->listBox1->Size = System::Drawing::Size(627, 500);
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
			this->tabPage2->Controls->Add(this->results_panel);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4);
			this->tabPage2->Size = System::Drawing::Size(973, 532);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"уравнение св€зи";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// results_panel
			// 
			this->results_panel->Controls->Add(this->panel2);
			this->results_panel->Controls->Add(this->panel1);
			this->results_panel->Location = System::Drawing::Point(0, 0);
			this->results_panel->Name = L"results_panel";
			this->results_panel->Size = System::Drawing::Size(973, 532);
			this->results_panel->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Location = System::Drawing::Point(3, 391);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(963, 138);
			this->panel2->TabIndex = 3;
			// 
			// LABEL_mid_quad_deviation_x
			// 
			this->LABEL_mid_quad_deviation_x->AutoSize = true;
			this->LABEL_mid_quad_deviation_x->Location = System::Drawing::Point(3, 58);
			this->LABEL_mid_quad_deviation_x->Name = L"LABEL_mid_quad_deviation_x";
			this->LABEL_mid_quad_deviation_x->Size = System::Drawing::Size(370, 16);
			this->LABEL_mid_quad_deviation_x->TabIndex = 4;
			this->LABEL_mid_quad_deviation_x->Text = L"—редн€€ квадратическа€ ошибка объЄма выборки X: - ";
			// 
			// LABEL_coefficient_of_determination
			// 
			this->LABEL_coefficient_of_determination->AutoSize = true;
			this->LABEL_coefficient_of_determination->Location = System::Drawing::Point(3, 42);
			this->LABEL_coefficient_of_determination->Name = L"LABEL_coefficient_of_determination";
			this->LABEL_coefficient_of_determination->Size = System::Drawing::Size(329, 16);
			this->LABEL_coefficient_of_determination->TabIndex = 3;
			this->LABEL_coefficient_of_determination->Text = L"—овокупный коэффициент детерминации R^2: - ";
			// 
			// LABEL_coefficient_of_correlation
			// 
			this->LABEL_coefficient_of_correlation->AutoSize = true;
			this->LABEL_coefficient_of_correlation->Location = System::Drawing::Point(3, 26);
			this->LABEL_coefficient_of_correlation->Name = L"LABEL_coefficient_of_correlation";
			this->LABEL_coefficient_of_correlation->Size = System::Drawing::Size(290, 16);
			this->LABEL_coefficient_of_correlation->TabIndex = 2;
			this->LABEL_coefficient_of_correlation->Text = L"ѕарный коэффициент коррел€ции X и Y: - ";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->main_data_table);
			this->panel1->Controls->Add(this->main_result_graph);
			this->panel1->Controls->Add(this->calculate_the_table);
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(964, 382);
			this->panel1->TabIndex = 1;
			// 
			// calculate_the_table
			// 
			this->calculate_the_table->Location = System::Drawing::Point(7, 345);
			this->calculate_the_table->Name = L"calculate_the_table";
			this->calculate_the_table->Size = System::Drawing::Size(465, 30);
			this->calculate_the_table->TabIndex = 2;
			this->calculate_the_table->Text = L"заполненить таблицу и построить график";
			this->calculate_the_table->UseVisualStyleBackColor = true;
			this->calculate_the_table->Click += gcnew System::EventHandler(this, &MyForm::calculate_the_table_Click);
			// 
			// main_result_graph
			// 
			chartArea1->Name = L"ChartArea1";
			this->main_result_graph->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->main_result_graph->Legends->Add(legend1);
			this->main_result_graph->Location = System::Drawing::Point(-1, -1);
			this->main_result_graph->Name = L"main_result_graph";
			this->main_result_graph->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Excel;
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"врем€";
			this->main_result_graph->Series->Add(series1);
			this->main_result_graph->Size = System::Drawing::Size(473, 344);
			this->main_result_graph->TabIndex = 0;
			this->main_result_graph->Text = L"график";
			// 
			// main_data_table
			// 
			this->main_data_table->AllowUserToAddRows = false;
			this->main_data_table->AllowUserToDeleteRows = false;
			this->main_data_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->main_data_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->elements_amount,
					this->time, this->elements_amount_squared, this->elements_amount_multiplied_by_time
			});
			this->main_data_table->GridColor = System::Drawing::SystemColors::ButtonHighlight;
			this->main_data_table->Location = System::Drawing::Point(478, 3);
			this->main_data_table->Name = L"main_data_table";
			this->main_data_table->ReadOnly = true;
			this->main_data_table->RowHeadersWidth = 60;
			this->main_data_table->Size = System::Drawing::Size(481, 372);
			this->main_data_table->TabIndex = 0;
			this->main_data_table->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// elements_amount
			// 
			this->elements_amount->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->elements_amount->FillWeight = 10;
			this->elements_amount->HeaderText = L"кол-во элементов (X)";
			this->elements_amount->Name = L"elements_amount";
			this->elements_amount->ReadOnly = true;
			this->elements_amount->Width = 141;
			// 
			// time
			// 
			this->time->HeaderText = L"врем€ (Y)";
			this->time->Name = L"time";
			this->time->ReadOnly = true;
			// 
			// elements_amount_squared
			// 
			dataGridViewCellStyle1->NullValue = L"-";
			this->elements_amount_squared->DefaultCellStyle = dataGridViewCellStyle1;
			this->elements_amount_squared->FillWeight = 1000;
			this->elements_amount_squared->HeaderText = L"X^2";
			this->elements_amount_squared->Name = L"elements_amount_squared";
			this->elements_amount_squared->ReadOnly = true;
			// 
			// elements_amount_multiplied_by_time
			// 
			this->elements_amount_multiplied_by_time->HeaderText = L"X*Y";
			this->elements_amount_multiplied_by_time->Name = L"elements_amount_multiplied_by_time";
			this->elements_amount_multiplied_by_time->ReadOnly = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->check_box_autoclear);
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
			this->tabPage3->Size = System::Drawing::Size(973, 532);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"панель отладки";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// check_box_autoclear
			// 
			this->check_box_autoclear->AutoSize = true;
			this->check_box_autoclear->Checked = true;
			this->check_box_autoclear->CheckState = System::Windows::Forms::CheckState::Checked;
			this->check_box_autoclear->Location = System::Drawing::Point(807, 368);
			this->check_box_autoclear->Name = L"check_box_autoclear";
			this->check_box_autoclear->Size = System::Drawing::Size(86, 20);
			this->check_box_autoclear->TabIndex = 12;
			this->check_box_autoclear->Text = L"autoclear";
			this->check_box_autoclear->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button6->Location = System::Drawing::Point(807, 394);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(160, 28);
			this->button6->TabIndex = 11;
			this->button6->Text = L"clear array";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button5->Location = System::Drawing::Point(807, 428);
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
			this->button3->Location = System::Drawing::Point(807, 462);
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
			this->rand_array_size_field->Location = System::Drawing::Point(807, 121);
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
			this->rand_range_max_field->Location = System::Drawing::Point(805, 76);
			this->rand_range_max_field->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { -1, 0, 0, 0 });
			this->rand_range_max_field->Name = L"rand_range_max_field";
			this->rand_range_max_field->Size = System::Drawing::Size(160, 23);
			this->rand_range_max_field->TabIndex = 7;
			// 
			// rand_range_min_field
			// 
			this->rand_range_min_field->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->rand_range_min_field->Location = System::Drawing::Point(805, 27);
			this->rand_range_min_field->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { -6, 0, 0, 0 });
			this->rand_range_min_field->Name = L"rand_range_min_field";
			this->rand_range_min_field->Size = System::Drawing::Size(160, 23);
			this->rand_range_min_field->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(806, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"RAND_ARRAY_SIZE";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(806, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(138, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"RAND_RANGE_MAX";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(806, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(133, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"RAND_RANGE_MIN";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(805, 150);
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
			this->button1->Location = System::Drawing::Point(807, 497);
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
			this->DEBUG_BOX->Size = System::Drawing::Size(795, 495);
			this->DEBUG_BOX->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->LABEL_coefficient_of_correlation);
			this->panel3->Controls->Add(this->LABEL_mid_quad_deviation_x);
			this->panel3->Controls->Add(this->LABEL_coefficient_of_determination);
			this->panel3->Location = System::Drawing::Point(3, 15);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(469, 105);
			this->panel3->TabIndex = 5;
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->label_equasion);
			this->panel4->Controls->Add(this->label5);
			this->panel4->Location = System::Drawing::Point(479, 15);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(479, 105);
			this->panel4->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(4, 28);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(122, 16);
			this->label5->TabIndex = 0;
			this->label5->Text = L"уравнение св€зи:";
			// 
			// label_equasion
			// 
			this->label_equasion->AutoSize = true;
			this->label_equasion->Location = System::Drawing::Point(122, 28);
			this->label_equasion->Name = L"label_equasion";
			this->label_equasion->Size = System::Drawing::Size(13, 16);
			this->label_equasion->TabIndex = 1;
			this->label_equasion->Text = L"-";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(983, 561);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(500, 400);
			this->Name = L"MyForm";
			this->Text = L" урсова€ работа";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->results_panel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_result_graph))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_data_table))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_array_size_field))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_range_max_field))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rand_range_min_field))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		
		// debug box handlers
		void dh(std::string message) { DEBUG_BOX -> Items -> Insert(DEBUG_BOX -> Items -> Count, cs(message)); }
		void dh(String^ message) { DEBUG_BOX -> Items -> Insert(DEBUG_BOX -> Items -> Count, message); }
		void dh_clear() { DEBUG_BOX -> Items -> Clear(); }
		// debug box handlers end

		void dh_autoclear() 
		{
			if (check_box_autoclear->Checked == true)
			{
				if (DEBUG_BOX->Items->Count > DH_AUTOCLEAR_LIMIT) dh_clear();
			}
		}

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
			dh_autoclear();

			dh("array size: " + s(RAND_ARRAY_SIZE));
			dh("minimum: " + s(RAND_RANGE_MIN));
			dh("maximum: " + s(RAND_RANGE_MAX));

			auto begin = std::chrono::steady_clock::now();
			auto c = RadixCount(GL_VEC);
			auto end = std::chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

			label_main_array_read->Text = cs("чтений из основного массива:" + c[0]);
			dh("main array reads:" + c[0]);
			label_main_array_writes->Text = cs("записей в основной массив:" + c[1]);
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

		private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		}

		private: System::Void calculate_the_table_Click(System::Object^ sender, System::EventArgs^ e)  // DATA FOR TABLE
		{ 
			//std::vector<size_t> elems_amount = { 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000 };
			std::vector<size_t> elems_amount = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000 };
			GL_ANALYZER.reset();
			size_t time;
			size_t rand_array_size_temp = RAND_ARRAY_SIZE;

			dh_autoclear();

			for (auto count : elems_amount)
			{
				RAND_ARRAY_SIZE = count;  // resizing target vector
				dh("RAND_ARRAY_SIZE = " + s(count));
				global_vec_fill();

				// start
				auto begin = std::chrono::steady_clock::now();

				Radix(GL_VEC); // SORT

				auto end = std::chrono::steady_clock::now();
				time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
				GL_ANALYZER.add_result(RAND_ARRAY_SIZE, time);
				// end

				dh("sorted "+s(GL_ANALYZER.get_values_x().back())+" in "+s(GL_ANALYZER.get_values_y().back()+"ms"));
			}
			RAND_ARRAY_SIZE = rand_array_size_temp;

			GL_ANALYZER.update_all();
			dh("fill_the_table();");
			fill_the_table(); 
			dh("draw_graph();");
			draw_graph();
		}

		void fill_the_table() 
		{
			main_data_table->Rows->Clear(); 
			size_t row = 0;
			for (size_t i = 0; i < GL_ANALYZER.get_results_amount(); i++)
			{
				main_data_table->Rows->Add();
				main_data_table->Rows[row]->Cells[0]->Value = GL_ANALYZER.get_value_x_at(i);
				main_data_table->Rows[row]->Cells[1]->Value = GL_ANALYZER.get_value_y_at(i);
				main_data_table->Rows[row]->Cells[2]->Value = GL_ANALYZER.get_value_x_squared_at(i);
				main_data_table->Rows[row]->Cells[3]->Value = GL_ANALYZER.get_value_x_to_y_at(i);
				row++;
			}
		}

		void draw_graph() 
		{
			main_result_graph->Series["врем€"]->Points->Clear();

			for (size_t i = 0; i < GL_ANALYZER.get_results_amount(); i++)
			{
				main_result_graph->Series["врем€"]->Points->AddXY(GL_ANALYZER.get_value_x_at(i), GL_ANALYZER.get_value_y_at(i));
			}
			output_analysis();
		}
		
		void output_analysis()  
		{
			LABEL_coefficient_of_correlation->Text = cs("ѕарный коэффициент коррел€ции ’ и Y: " + s(GL_ANALYZER.get_coefficent_of_correlation()));
			dh("coefficent_of_correlation " + s(GL_ANALYZER.get_coefficent_of_correlation()));

			LABEL_coefficient_of_determination->Text = cs("—овокупный коэффициент детерминации R^2: " + s(GL_ANALYZER.get_coefficent_of_determination()));
			dh("coefficent_of_determination " + s(GL_ANALYZER.get_coefficent_of_determination()));
			
			LABEL_mid_quad_deviation_x->Text = cs("—редн€€ квадратическа€ ошибка объЄма выборки X: " + s(GL_ANALYZER.get_mid_quad_deviation_x()));
			dh("mid_quad_deviation_x " + s(GL_ANALYZER.get_mid_quad_deviation_x()));
			dh("a1 " + s(GL_ANALYZER.get_a1()));
			dh("a0 " + s(GL_ANALYZER.get_a0()));
		}
	};
	
}
