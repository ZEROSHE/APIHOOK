// TEST.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "windows.h"
#include "strsafe.h"


int main()
{
	/*
	WCHAR szCurrentDirectory[MAX_PATH];
	DWORD dwCurDirPathLen;
	dwCurDirPathLen = GetCurrentDirectoryW(MAX_PATH, szCurrentDirectory);
	if (dwCurDirPathLen == 0)
	{
		printf("��ȡ��ǰĿ¼����\n");
		return 0;
	}
	OutputDebugStringW(szCurrentDirectory);
	OutputDebugStringW(L"\n");
	*/

	/*
	HANDLE hSemaphoreStatus;
	//hSemaphoreStatus = OpenSemaphore(SYNCHRONIZE, FALSE, L"APIHOOK_Monitor_Semaphore_Status");
	hSemaphoreStatus = CreateSemaphore(NULL, 0, 1, L"APIHOOK_Monitor_Semaphore_Status");
	if (!hSemaphoreStatus)
	{
		printf("fuck\n");
		system("PAUSE");
	}
	ReleaseSemaphore(hSemaphoreStatus, 1, NULL);
	CloseHandle(hSemaphoreStatus);
	hSemaphoreStatus = NULL;
	*/

	HANDLE hWriteMailslot = NULL;
	hWriteMailslot = CreateFile(L"\\\\.\\mailslot\\APIHOOK\\Monitor\\Log", 
		GENERIC_WRITE, 
		FILE_SHARE_READ, 
		NULL, 
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (INVALID_HANDLE_VALUE == hWriteMailslot)
	{
		OutputDebugString(L"FUCK!!!!\n");
		return 0;
	}
	for (int j=0;j<5;j++)
	{
		SIZE_T a;
		DWORD b,c;
		StringCbLength(L"��úǺ�\r\n", MAX_PATH, &a);
		WriteFile(hWriteMailslot, L"��úǺ�\r\n", a, &b, NULL);
		Sleep(100);
	}
    return 0;
}

