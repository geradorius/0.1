#pragma once

namespace gui_winforms {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    // using namespace System::Data; // Pašalinta, nes nenaudojama ir sukelia klaidą
    using namespace System::Drawing;

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
        }
    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private:
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::Windows::Forms::ToolStripMenuItem^ fileMenu;
        System::Windows::Forms::ToolStripMenuItem^ openMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ saveMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ selectResultMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ keyMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ aboutMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ exitMenuItem;
        System::Windows::Forms::TextBox^ textBox1;
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->fileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->openMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->saveMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->selectResultMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->keyMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->aboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->exitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->menuStrip1->SuspendLayout();
            this->SuspendLayout();
            // 
            // menuStrip1
            // 
            this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
                this->fileMenu, this->keyMenuItem, this->aboutMenuItem, this->exitMenuItem });
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(800, 24);
            this->menuStrip1->TabIndex = 0;
            this->menuStrip1->Text = L"menuStrip1";
            // 
            // fileMenu
            // 
            this->fileMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
                this->openMenuItem, this->saveMenuItem, this->selectResultMenuItem });
            this->fileMenu->Name = L"fileMenu";
            this->fileMenu->Text = L"Failas";
            // 
            // openMenuItem
            // 
            this->openMenuItem->Name = L"openMenuItem";
            this->openMenuItem->Text = L"Atidaryti...";
            this->openMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openMenuItem_Click);
            // 
            // saveMenuItem
            // 
            this->saveMenuItem->Name = L"saveMenuItem";
            this->saveMenuItem->Text = L"I\u0161saugoti...";
            this->saveMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveMenuItem_Click);
            // 
            // selectResultMenuItem
            // 
            this->selectResultMenuItem->Name = L"selectResultMenuItem";
            this->selectResultMenuItem->Text = L"Pasirinkti rezultat\u0173 fail\u0105...";
            this->selectResultMenuItem->Click += gcnew System::EventHandler(this, &MainForm::selectResultMenuItem_Click);
            // 
            // keyMenuItem
            // 
            this->keyMenuItem->Name = L"keyMenuItem";
            this->keyMenuItem->Text = L"Raktas";
            this->keyMenuItem->Enabled = false;
            // 
            // aboutMenuItem
            // 
            this->aboutMenuItem->Name = L"aboutMenuItem";
            this->aboutMenuItem->Text = L"Apie";
            this->aboutMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutMenuItem_Click);
            // 
            // exitMenuItem
            // 
            this->exitMenuItem->Name = L"exitMenuItem";
            this->exitMenuItem->Text = L"U\u017Edaryti";
            this->exitMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitMenuItem_Click);
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(12, 40);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
            this->textBox1->Size = System::Drawing::Size(776, 398);
            this->textBox1->TabIndex = 1;
            this->textBox1->WordWrap = false;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 450);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->menuStrip1);
            this->MainMenuStrip = this->menuStrip1;
            this->Name = L"MainForm";
            this->Text = L"VVK Student\u0173 duomen\u0173 valdymas";
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    private:
        System::Void openMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void saveMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void selectResultMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void aboutMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void exitMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
