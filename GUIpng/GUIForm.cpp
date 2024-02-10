//  GUIForm.cpp
//  Project-02
//
//  Created by Aquon Bovell on 04/02/2024.
//  Student ID: 417002174

#pragma warning(disable : 4996)
#pragma comment(lib, "shell32.lib")

#pragma managed(push, off)
	#define generic GenericFromFreeTypeLibrary
		#include "pngwriter.h"
	#undef generic
#pragma managed(pop)

#include "GUIForm.h"
using namespace GUIpng;

[STAThread]

int Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUIForm form;
	Application::Run(% form);
	return 0;
}


