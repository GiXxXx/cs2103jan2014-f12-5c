#include "PrimeGeneratorGUI.h"
#include "PrimeGenerator.h"

using namespace System; 
using namespace System::Windows::Forms;


[STAThread] void main(array<String^>^ args) { 
	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false);

	UI::PrimeGeneratorGUI mainWindow; 
	Application::Run(%mainWindow);
}
