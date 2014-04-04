#include "VeriTaskUI.h"
#include "VeriTask.h"
#include "Identifier.h"

using namespace System; 
using namespace System::Windows::Forms;

[STAThread] void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	UI::VeriTaskUI mainWindow;
	Application::Run(%mainWindow);
}

