#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String ^> ^)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    gui_winforms::MainForm form;
    Application::Run(%form);
    return 0;
}