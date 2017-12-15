// TEST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"


int main()
{
	WCHAR szCurrentDirectory[MAX_PATH];
	DWORD dwCurDirPathLen;
	dwCurDirPathLen = GetCurrentDirectoryW(MAX_PATH, szCurrentDirectory);
	if (dwCurDirPathLen == 0)
	{
		printf("获取当前目录错误。\n");
		return 0;
	}
	OutputDebugStringW(szCurrentDirectory);
	OutputDebugStringW(L"\n");
    return 0;
}

