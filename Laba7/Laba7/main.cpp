#include "pch.h"
#include "myForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::Run(gcnew TruncatedConeForm());
}
