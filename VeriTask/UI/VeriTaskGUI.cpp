#include "VeriTaskGUI.h"

using namespace System; 
using namespace System::Windows::Forms;

[STAThread] int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	UI::VeriTaskGUI mainWindow;
	Application::Run(%mainWindow);
}