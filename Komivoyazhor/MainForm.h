#pragma once
#include <string>

namespace Komivoyazhor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	
	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_uzel;
	protected:




	protected:

	protected:






	private: System::Windows::Forms::Panel^ panel_uzlov;

	private: System::Windows::Forms::RadioButton^ rb_addUzel;
	private: System::Windows::Forms::Panel^ panel_menu;

	private: System::Windows::Forms::RadioButton^ rb_deleteUzel;
	private: System::Windows::Forms::RadioButton^ btn_RedactVesRebro;
	private: System::Windows::Forms::RadioButton^ rb_offRebro;
	private: System::Windows::Forms::RadioButton^ rb_deleteRebro;
	private: System::Windows::Forms::RadioButton^ rb_addRebro;
	private: System::Windows::Forms::Label^ label_rebra;
	private: System::Windows::Forms::TextBox^ tb_vecRebra;

	private: System::Windows::Forms::Label^ label_DlinaPuti;
	private: System::Windows::Forms::Label^ label_resultat;



	private: System::Windows::Forms::Button^ btn_output_result;
	private: System::Windows::Forms::Panel^ panel_dialogWithPilzovatel;

	private: System::Windows::Forms::Button^ btn_input;
	private: System::Windows::Forms::TextBox^ TB_input;
	private: System::Windows::Forms::Label^ label_consol;

























	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label_uzel = (gcnew System::Windows::Forms::Label());
			this->panel_uzlov = (gcnew System::Windows::Forms::Panel());
			this->rb_addUzel = (gcnew System::Windows::Forms::RadioButton());
			this->panel_menu = (gcnew System::Windows::Forms::Panel());
			this->tb_vecRebra = (gcnew System::Windows::Forms::TextBox());
			this->btn_RedactVesRebro = (gcnew System::Windows::Forms::RadioButton());
			this->rb_offRebro = (gcnew System::Windows::Forms::RadioButton());
			this->rb_deleteRebro = (gcnew System::Windows::Forms::RadioButton());
			this->rb_addRebro = (gcnew System::Windows::Forms::RadioButton());
			this->label_rebra = (gcnew System::Windows::Forms::Label());
			this->rb_deleteUzel = (gcnew System::Windows::Forms::RadioButton());
			this->label_DlinaPuti = (gcnew System::Windows::Forms::Label());
			this->label_resultat = (gcnew System::Windows::Forms::Label());
			this->btn_output_result = (gcnew System::Windows::Forms::Button());
			this->panel_dialogWithPilzovatel = (gcnew System::Windows::Forms::Panel());
			this->btn_input = (gcnew System::Windows::Forms::Button());
			this->TB_input = (gcnew System::Windows::Forms::TextBox());
			this->label_consol = (gcnew System::Windows::Forms::Label());
			this->panel_menu->SuspendLayout();
			this->panel_dialogWithPilzovatel->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_uzel
			// 
			this->label_uzel->AutoSize = true;
			this->label_uzel->Font = (gcnew System::Drawing::Font(L"Arial Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_uzel->Location = System::Drawing::Point(3, 1);
			this->label_uzel->Name = L"label_uzel";
			this->label_uzel->Size = System::Drawing::Size(220, 27);
			this->label_uzel->TabIndex = 5;
			this->label_uzel->Text = L"Действия с узлами";
			// 
			// panel_uzlov
			// 
			this->panel_uzlov->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_uzlov->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel_uzlov->Location = System::Drawing::Point(299, 14);
			this->panel_uzlov->Name = L"panel_uzlov";
			this->panel_uzlov->Size = System::Drawing::Size(720, 673);
			this->panel_uzlov->TabIndex = 7;
			this->panel_uzlov->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel_uzlov_Paint);
			this->panel_uzlov->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel_uzlov_MouseClick);
			// 
			// rb_addUzel
			// 
			this->rb_addUzel->AutoSize = true;
			this->rb_addUzel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->rb_addUzel->Location = System::Drawing::Point(25, 41);
			this->rb_addUzel->Name = L"rb_addUzel";
			this->rb_addUzel->Size = System::Drawing::Size(105, 23);
			this->rb_addUzel->TabIndex = 9;
			this->rb_addUzel->Text = L"Добавить";
			this->rb_addUzel->UseVisualStyleBackColor = true;
			// 
			// panel_menu
			// 
			this->panel_menu->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_menu->Controls->Add(this->tb_vecRebra);
			this->panel_menu->Controls->Add(this->btn_RedactVesRebro);
			this->panel_menu->Controls->Add(this->rb_offRebro);
			this->panel_menu->Controls->Add(this->rb_deleteRebro);
			this->panel_menu->Controls->Add(this->rb_addRebro);
			this->panel_menu->Controls->Add(this->label_rebra);
			this->panel_menu->Controls->Add(this->rb_deleteUzel);
			this->panel_menu->Controls->Add(this->rb_addUzel);
			this->panel_menu->Controls->Add(this->label_uzel);
			this->panel_menu->Location = System::Drawing::Point(12, 12);
			this->panel_menu->Name = L"panel_menu";
			this->panel_menu->Size = System::Drawing::Size(257, 384);
			this->panel_menu->TabIndex = 10;
			// 
			// tb_vecRebra
			// 
			this->tb_vecRebra->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->tb_vecRebra->ForeColor = System::Drawing::Color::DarkGray;
			this->tb_vecRebra->Location = System::Drawing::Point(25, 279);
			this->tb_vecRebra->Name = L"tb_vecRebra";
			this->tb_vecRebra->Size = System::Drawing::Size(181, 26);
			this->tb_vecRebra->TabIndex = 18;
			this->tb_vecRebra->Text = L"Введите вес ребра";
			this->tb_vecRebra->Enter += gcnew System::EventHandler(this, &MainForm::tb_vecRebra_Enter);
			this->tb_vecRebra->Leave += gcnew System::EventHandler(this, &MainForm::tb_vecRebra_Leave);
			// 
			// btn_RedactVesRebro
			// 
			this->btn_RedactVesRebro->AutoSize = true;
			this->btn_RedactVesRebro->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btn_RedactVesRebro->Location = System::Drawing::Point(25, 216);
			this->btn_RedactVesRebro->Name = L"btn_RedactVesRebro";
			this->btn_RedactVesRebro->Size = System::Drawing::Size(181, 23);
			this->btn_RedactVesRebro->TabIndex = 17;
			this->btn_RedactVesRebro->Text = L"Редактировать вес";
			this->btn_RedactVesRebro->UseVisualStyleBackColor = true;
			// 
			// rb_offRebro
			// 
			this->rb_offRebro->AutoSize = true;
			this->rb_offRebro->Checked = true;
			this->rb_offRebro->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->rb_offRebro->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->rb_offRebro->Location = System::Drawing::Point(25, 341);
			this->rb_offRebro->Name = L"rb_offRebro";
			this->rb_offRebro->Size = System::Drawing::Size(147, 23);
			this->rb_offRebro->TabIndex = 16;
			this->rb_offRebro->TabStop = true;
			this->rb_offRebro->Text = L"Отключить все";
			this->rb_offRebro->UseVisualStyleBackColor = true;
			// 
			// rb_deleteRebro
			// 
			this->rb_deleteRebro->AutoSize = true;
			this->rb_deleteRebro->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->rb_deleteRebro->Location = System::Drawing::Point(25, 187);
			this->rb_deleteRebro->Name = L"rb_deleteRebro";
			this->rb_deleteRebro->Size = System::Drawing::Size(93, 23);
			this->rb_deleteRebro->TabIndex = 15;
			this->rb_deleteRebro->Text = L"Удалить";
			this->rb_deleteRebro->UseVisualStyleBackColor = true;
			// 
			// rb_addRebro
			// 
			this->rb_addRebro->AutoSize = true;
			this->rb_addRebro->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->rb_addRebro->Location = System::Drawing::Point(25, 158);
			this->rb_addRebro->Name = L"rb_addRebro";
			this->rb_addRebro->Size = System::Drawing::Size(105, 23);
			this->rb_addRebro->TabIndex = 14;
			this->rb_addRebro->Text = L"Добавить";
			this->rb_addRebro->UseVisualStyleBackColor = true;
			this->rb_addRebro->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rb_addRebro_CheckedChanged);
			// 
			// label_rebra
			// 
			this->label_rebra->AutoSize = true;
			this->label_rebra->Font = (gcnew System::Drawing::Font(L"Arial Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_rebra->Location = System::Drawing::Point(3, 117);
			this->label_rebra->Name = L"label_rebra";
			this->label_rebra->Size = System::Drawing::Size(214, 27);
			this->label_rebra->TabIndex = 13;
			this->label_rebra->Text = L"Действия ребрами";
			// 
			// rb_deleteUzel
			// 
			this->rb_deleteUzel->AutoSize = true;
			this->rb_deleteUzel->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->rb_deleteUzel->Location = System::Drawing::Point(25, 70);
			this->rb_deleteUzel->Name = L"rb_deleteUzel";
			this->rb_deleteUzel->Size = System::Drawing::Size(93, 23);
			this->rb_deleteUzel->TabIndex = 10;
			this->rb_deleteUzel->Text = L"Удалить";
			this->rb_deleteUzel->UseVisualStyleBackColor = true;
			// 
			// label_DlinaPuti
			// 
			this->label_DlinaPuti->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_DlinaPuti->Font = (gcnew System::Drawing::Font(L"Arial Black", 14.25F, System::Drawing::FontStyle::Bold));
			this->label_DlinaPuti->Location = System::Drawing::Point(12, 425);
			this->label_DlinaPuti->Name = L"label_DlinaPuti";
			this->label_DlinaPuti->Size = System::Drawing::Size(257, 142);
			this->label_DlinaPuti->TabIndex = 12;
			this->label_DlinaPuti->Text = L"Длина самого короткого пути:";
			// 
			// label_resultat
			// 
			this->label_resultat->AutoSize = true;
			this->label_resultat->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_resultat->Location = System::Drawing::Point(93, 506);
			this->label_resultat->Name = L"label_resultat";
			this->label_resultat->Size = System::Drawing::Size(63, 22);
			this->label_resultat->TabIndex = 0;
			this->label_resultat->Text = L"ответ";
			// 
			// btn_output_result
			// 
			this->btn_output_result->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_output_result->Location = System::Drawing::Point(12, 587);
			this->btn_output_result->Name = L"btn_output_result";
			this->btn_output_result->Size = System::Drawing::Size(257, 47);
			this->btn_output_result->TabIndex = 15;
			this->btn_output_result->Text = L"Получить результат";
			this->btn_output_result->UseVisualStyleBackColor = true;
			// 
			// panel_dialogWithPilzovatel
			// 
			this->panel_dialogWithPilzovatel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_dialogWithPilzovatel->Controls->Add(this->btn_input);
			this->panel_dialogWithPilzovatel->Controls->Add(this->label_consol);
			this->panel_dialogWithPilzovatel->Controls->Add(this->TB_input);
			this->panel_dialogWithPilzovatel->Location = System::Drawing::Point(1025, 12);
			this->panel_dialogWithPilzovatel->Name = L"panel_dialogWithPilzovatel";
			this->panel_dialogWithPilzovatel->Size = System::Drawing::Size(329, 675);
			this->panel_dialogWithPilzovatel->TabIndex = 16;
			// 
			// btn_input
			// 
			this->btn_input->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_input->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_input->Location = System::Drawing::Point(3, 625);
			this->btn_input->Name = L"btn_input";
			this->btn_input->Size = System::Drawing::Size(323, 47);
			this->btn_input->TabIndex = 17;
			this->btn_input->Text = L"Ввод";
			this->btn_input->UseVisualStyleBackColor = true;
			// 
			// TB_input
			// 
			this->TB_input->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->TB_input->BackColor = System::Drawing::SystemColors::Window;
			this->TB_input->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TB_input->Location = System::Drawing::Point(3, 447);
			this->TB_input->Multiline = true;
			this->TB_input->Name = L"TB_input";
			this->TB_input->Size = System::Drawing::Size(323, 172);
			this->TB_input->TabIndex = 16;
			// 
			// label_consol
			// 
			this->label_consol->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label_consol->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label_consol->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_consol->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_consol->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_consol->Location = System::Drawing::Point(3, 2);
			this->label_consol->Name = L"label_consol";
			this->label_consol->Size = System::Drawing::Size(323, 442);
			this->label_consol->TabIndex = 15;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1359, 730);
			this->Controls->Add(this->panel_dialogWithPilzovatel);
			this->Controls->Add(this->btn_output_result);
			this->Controls->Add(this->label_resultat);
			this->Controls->Add(this->label_DlinaPuti);
			this->Controls->Add(this->panel_menu);
			this->Controls->Add(this->panel_uzlov);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Графы";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel_menu->ResumeLayout(false);
			this->panel_menu->PerformLayout();
			this->panel_dialogWithPilzovatel->ResumeLayout(false);
			this->panel_dialogWithPilzovatel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void Komivoyazhor::MainForm::panel_uzlov_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void Komivoyazhor::MainForm::AddGrafs(int x, int y);
	private: System::Void Komivoyazhor::MainForm::AddLocationGrafs(int x, int y);
	private: System::Void Komivoyazhor::MainForm::AddLocationLines(int x, int y, int indexGraf1, int indexGraf2);
	private: System::Void Komivoyazhor::MainForm::TextOnGrafs(int x, int y, int NumGrafs);
	private: System::Void Komivoyazhor::MainForm::panel_uzlov_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void Komivoyazhor::MainForm::AddLines(int indexGraf1, int indexGraf2, int vecRebra);
	private: System::Void Komivoyazhor::MainForm::TextOnLines(int x1, int y1, int x2, int y2, int indexGraf1, int indexGraf2, int vecRebra);
	private: System::Void Komivoyazhor::MainForm::btnGraf_MouseClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void tb_vecRebra_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void tb_vecRebra_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Komivoyazhor::MainForm::btnLine_MouseClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Komivoyazhor::MainForm::deleteLine(int indexGraf1, int indexGraf2, int indexLine);
	private: System::Void Komivoyazhor::MainForm::deleteGraf(int x, int y, int indexGrafDelete);
	private: System::Void rb_addRebro_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
};
}
