#pragma warning(disable : 4996)
#pragma comment(lib, "shell32.lib")

#pragma managed(push, off)
	#define generic GenericFromFreeTypeLibrary
		#include "pngwriter.h"
	#undef generic
#pragma managed(pop)

#include "PicForm1.h"
using namespace PicMan;

[STAThread]

int Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PicForm form;
	Application::Run(% form);
	return 0;
}

