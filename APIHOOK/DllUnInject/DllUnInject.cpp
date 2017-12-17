// DllUnInject.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	HANDLE hSemaphoreStatus;

	//hSemaphoreStatus = OpenSemaphore(SYNCHRONIZE, FALSE, L"APIHOOK_Monitor_Semaphore_Status");
	hSemaphoreStatus = CreateSemaphore(NULL, 0, 1, L"APIHOOK_Monitor_Semaphore_Status");
	if (!hSemaphoreStatus)
	{
		printf("CreateSemaphore ERROR\n");
		return 0;
	}
	ReleaseSemaphore(hSemaphoreStatus, 1, NULL);
	CloseHandle(hSemaphoreStatus);
	hSemaphoreStatus = NULL;

    return 0;
}

