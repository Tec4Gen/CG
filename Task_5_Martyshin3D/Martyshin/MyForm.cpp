#include <math.h>
#include "Matrix.h"
#include "Transform.h"
#include <string>
#include "Clip.h"
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
