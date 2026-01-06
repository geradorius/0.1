#include "MainForm.h"
#include <fstream>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;

namespace gui_winforms {
    System::Void MainForm::openMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        OpenFileDialog^ ofd = gcnew OpenFileDialog();
        if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            std::ifstream fin(marshal_as<std::string>(ofd->FileName));
            std::string line, content;
            while (std::getline(fin, line)) {
                content += line + "\r\n";
            }
            textBox1->Text = gcnew String(content.c_str());
        }
    }
    System::Void MainForm::saveMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        SaveFileDialog^ sfd = gcnew SaveFileDialog();
        if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            std::ofstream fout(marshal_as<std::string>(sfd->FileName));
            std::string content = marshal_as<std::string>(textBox1->Text);
            fout << content;
        }
    }
    System::Void MainForm::selectResultMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        OpenFileDialog^ ofd = gcnew OpenFileDialog();
        if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            MessageBox::Show("Pasirinktas rezultatų failas: " + ofd->FileName, "Rezultatai");
        }
    }
    System::Void MainForm::aboutMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageBox::Show(L"VVK Student\u0173 duomen\u0173 valdymo programa\nAutorius: Arnas Liudvinavi\u010dius\nOrganizacija: VVK", L"Apie");
    }
    System::Void MainForm::exitMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }
}
