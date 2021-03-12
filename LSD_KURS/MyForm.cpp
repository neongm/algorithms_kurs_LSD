#include "MyForm.h"  // для доступа к нашему основному классу
#include <Windows.h>
using namespace LSDKURS;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}