#include <math.h>
#include "Matrix.h"
#include "Figure.h"
#include "Transform.h"
#include <fstream>
#include <sstream>
#include <string>
#include "MyForm.h"



 using namespace System;
 using namespace System::Windows::Forms;

[STAThreadAttribute]
 void Main(array<String^> ^ args) {
	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 Martyshin::MyForm form;
	 Application::Run(% form);
	
}
