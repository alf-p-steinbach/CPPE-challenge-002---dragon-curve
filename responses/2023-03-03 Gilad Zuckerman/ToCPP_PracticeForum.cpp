// From all of my MFC C++ SINGLE DOCUMENT Drawing program , Only the relevant variablrs, structs and classes is here , BUT ALL #include(s) : GILAD ZUCKERMAN answered positively to Alf P. Steinbach request , I hope i did not drop something....
// the source is of C++ 14 COMPILED BY Microsotf visual C++ community 2022

// FILE : stdafx.h
#pragma once // PT GILAD ZUCKERMAN SDN BHD
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _WINSOCK_DEPCRECATED
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "targetver.h"
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#define _AFX_ALL_WARNINGS
#include <afxwin.h>
#include <afxext.h>
#include <afxdisp.h>
#ifndef STRICT
#define STRICT
#endif
#ifndef WINVER
#define WINVER 0x0601
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif
#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0601
#endif
#ifndef _WIN32_IE
#define _WIN32_IE 0x0600
#endif
#define _ATL_NO_AUTOMATIC_NAMESPACE
#ifndef _SECURE_ATL
#define _SECURE_ATL 1 // Use Secure C Runtime In ATL
#endif
#include <atlsocket.h>
#include <icmpapi.h>
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <afxcontrolbars.h>
#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif
// end of file

// FILE : stdafx.cpp
#include "stdafx.h" // stdafx.cpp : source file that includes just the standard includes DateTime2.pch will be the pre-compiled header stdafx.obj will contain the pre-compiled type information PT GILAD ZUCKERMAN SDN BHD
// end of file

// dragon curve classes anf dunctions
// global data vaiables and function first, to provide scope access.
#pragma once // PT GILAD ZUCKERMAN SDN BHD
#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif
#include <windows.h>
#include <stddef.h>
#include <stdexcept>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dos.h>
#include <io.h>
#include <direct.h>
#include <conio.h>
#include <process.h>
#include <fcntl.h>
#include <time.h>
#include <vector>
#include <bitset>
#include <array>
#include <string>
#include <intrin.h>
#include <afxwin.h>
#include <afxcolordialog.h>
#include <random>
#include <atltime.h>
#include <math.h>
#include <memory.h>
#include <sys/timeb.h>
#include <afxinet.h>
#include <tchar.h>
#include <ctype.h>
#include <shellapi.h>
#include <afxtempl.h>
#include <afxsock.h>
#include <iphlpapi.h>
#include <winsock2.h>
#include <locale>
#include <sstream>
#include <gdiplusimagecodec.h>
#include <cmath>
#include <cstdio>
#include <psapi.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <OleCtl.h>
#include <mmsystem.h>
#include <filesystem> // C++17 standard header file
#include <experimental/filesystem> // Header file for pre-standard implementation
using namespace std::experimental::filesystem::v1;
using namespace std::experimental::filesystem;
#include <algorithm>
#ifndef __ATL_SOCKET__
#pragma message("To avoid this message please put atlsocket.h in your pre compiled header (normally stdafx.h)")
#include <atlsocket.h>
#endif
#ifndef _ICMP_INCLUDED_
#pragma message("To avoid this message please put icmpapi.h in your pre compiled header (normally stdafx.h)")
#include <icmpapi.h>
#endif
#ifndef CPING_EXT_CLASS
#define CPING_EXT_CLASS
#endif
#ifndef CPING_EXT_API
#define CPING_EXT_API
#endif
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Iphlpapi.lib")
#pragma comment(lib, "gdiplus")
#pragma comment(lib, "Winmm.lib")
#include <iostream>
using std::runtime_error;
using std::exception;
using C_str = const char *;
using Size = ptrdiff_t;
using namespace std;
#include "resource.h"
#include "DateTime2Doc.h"
#ifndef __WAVFILE_H__
#define __WAVFILE_H__
static COLORREF gColors[6] = { 0xff0000, 0x00ff33, 0x0033ff, 0xffff00, 0x00ffff, 128 };
inline void ErrorNull()
{
if (!MessageBoxA(NULL, "NULL", "ERROR", 0U))
	exit(1);
exit(1);
}
inline void RunSecureZeroMemoryAndExitOnError()
{
WNDCLASSEX wcex = { NULL };
PVOID pVOID = SecureZeroMemory(&wcex, sizeof(WNDCLASSEX));
if (!pVOID)
	ErrorNull();
}
inline CString TurnCharAsteriskToCString(char szSource[])
{
if (!szSource || !szSource[0] || (szSource[0] == '\0') || (szSource == "\0") || (szSource == NULL))
	ErrorNull();
CString strTarget(szSource);
if (!strTarget || !strTarget.GetBuffer())
	ErrorNull();
return strTarget;
}
inline void FileNotFoundErrorMessageWithNOExit(char FileName[])
{ // also L"NOT FOUND or INACCESSIBLE"
if (!MessageBox(NULL, _T("NOT FOUND or INACCESSIBLE"), TurnCharAsteriskToCString(FileName), 0U))
	ErrorNull();
}
inline void FileNotFoundErrorMessageWithAnExit(char FileName[])
{
FileNotFoundErrorMessageWithNOExit(FileName);
ErrorNull();
}
inline char *CurrentDIr(char CurrentDirectory[])
{
if (!GetCurrentDirectoryA(4200, CurrentDirectory))
	FileNotFoundErrorMessageWithAnExit(CurrentDirectory);
return CurrentDirectory;
}
inline char *ReturnFileFullPath(char FileName[], char szFull[4200])
{
if (_fullpath(CurrentDIr(szFull), FileName, 4200) == NULL)
	FileNotFoundErrorMessageWithAnExit(FileName);
return szFull;
}
typedef class MyBitmap // MyBitmap
{
private:
	HBITMAP bmp;
	HDC hdc = NULL;
	HPEN pen = NULL;
	HBRUSH brush = NULL;
	void *pBits = NULL;
	int width = 0, height = 0, wid = 0;
	DWORD clr = 0;
public:
	MyBitmap() : pen(NULL), brush(NULL), clr(0), wid(1) {}
	~MyBitmap() { RunSecureZeroMemoryAndExitOnError(); }
	bool Create(int w, int h)
	{
	BITMAPINFO bi;
	ZeroMemory(&bi, sizeof(bi));
	bi.bmiHeader.biSize = sizeof(bi.bmiHeader);
	bi.bmiHeader.biBitCount = (sizeof(DWORD) * 8);
	bi.bmiHeader.biCompression = BI_RGB;
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biWidth = w;
	bi.bmiHeader.biHeight = -h;
	HDC dc = GetDC(GetConsoleWindow());
	if (!dc)
		ErrorNull();
	bmp = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, &pBits, NULL, 0);
	if (!bmp)
		ErrorNull();
	hdc = CreateCompatibleDC(dc);
	if (!hdc)
		ErrorNull();
	if (SelectObject(hdc, bmp) == NULL)
		ErrorNull();
	if (!ReleaseDC(GetConsoleWindow(), dc))
		ErrorNull();
	width = w;
	height = h;
	return true;
	}
	inline void Clear(BYTE clr = 0) { memset(pBits, clr, (width * height * sizeof(DWORD))); }
	void SetBrushColor(DWORD bClr)
	{
	if (brush)
		if (!DeleteObject(brush))
			ErrorNull();
	brush = CreateSolidBrush(bClr);
	if (brush == NULL)
		ErrorNull();
	if (SelectObject(hdc, brush) == NULL)
		ErrorNull();
	}
	void SetPenColor(DWORD c)
	{
	clr = c;
	createPen();
	}
	void SetPenWidth(int w)
	{
	wid = w;
	createPen();
	}
	char *SaveBitmap(std::string path)
	{ // keep 2 arrays
	char char_array[4200] = "\0", szFull[4200] = "\0";
	BITMAPFILEHEADER fileheader;
	BITMAPINFO infoheader;
	BITMAP bitmap;
	DWORD wb = 0;
	if (!GetObject(bmp, sizeof(bitmap), &bitmap))
		ErrorNull();
	DWORD *dwpBits = new DWORD[bitmap.bmWidth * bitmap.bmHeight];
	if (!dwpBits)
		ErrorNull();
	ZeroMemory(dwpBits, (bitmap.bmWidth * bitmap.bmHeight * sizeof(DWORD)));
	ZeroMemory(&infoheader, sizeof(BITMAPINFO));
	ZeroMemory(&fileheader, sizeof(BITMAPFILEHEADER));
	infoheader.bmiHeader.biBitCount = (sizeof(DWORD) * 8);
	infoheader.bmiHeader.biCompression = BI_RGB;
	infoheader.bmiHeader.biPlanes = 1;
	infoheader.bmiHeader.biSize = sizeof(infoheader.bmiHeader);
	infoheader.bmiHeader.biHeight = bitmap.bmHeight;
	infoheader.bmiHeader.biWidth = bitmap.bmWidth;
	infoheader.bmiHeader.biSizeImage = (bitmap.bmWidth * bitmap.bmHeight * sizeof(DWORD));
	fileheader.bfType = 0x4D42;
	fileheader.bfOffBits = (sizeof(infoheader.bmiHeader) + sizeof(BITMAPFILEHEADER));
	fileheader.bfSize = (fileheader.bfOffBits + infoheader.bmiHeader.biSizeImage);
	if (GetDIBits(hdc, bmp, 0, height, (LPVOID)dwpBits, &infoheader, DIB_RGB_COLORS) == ERROR_INVALID_PARAMETER)
		ErrorNull();
	HANDLE file = CreateFileA(path.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == INVALID_HANDLE_VALUE)
		ErrorNull();
	if (WriteFile(file, &fileheader, sizeof(BITMAPFILEHEADER), &wb, NULL) == FALSE)
		ErrorNull();
	if (WriteFile(file, &infoheader.bmiHeader, sizeof(infoheader.bmiHeader), &wb, NULL) == FALSE)
		ErrorNull();
	if (WriteFile(file, dwpBits, (bitmap.bmWidth * bitmap.bmHeight * 4), &wb, NULL) == FALSE)
		ErrorNull();
	if (!CloseHandle(file))
		ErrorNull();
	delete[]dwpBits;
	return ReturnFileFullPath(ConvertStdStringToCharString(path.c_str(), char_array), szFull); // keep 2 arrays
	}
	inline HDC getDC() const { return hdc; }
	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }
	void createPen()
	{
	if (pen)
		if (!DeleteObject(pen))
			ErrorNull();
	pen = CreatePen(PS_SOLID, wid, clr);
	if (pen == NULL)
		ErrorNull();
	if (!SelectObject(hdc, pen))
		ErrorNull();
	}
} MyBitmap;
typedef class DragonCurve // DragonCurve
{
private:
	int dir = 8;
	MyBitmap bmp;
	string generator;
public:
	DragonCurve(COLORREF Color = 0) 
	{
	bmp.Create(800, 800);
	bmp.Clear(Color);
	}
	~DragonCurve() { RunSecureZeroMemoryAndExitOnError(); }
	inline void Save(string p) { bmp.SaveBitmap(p); }
	void Generate(int it)
	{
	generator.push_back(1);
	string temp;
	for (int y = 0; y < (it - 1); y++)
		{
		temp = generator;
		temp.push_back(1);
		for (string::reverse_iterator x = generator.rbegin(); x != generator.rend(); x++)
			temp.push_back(!(*x));
		generator = temp;
		}
	}
	void Draw(int iterations) 
	{ 
	Generate(iterations); 
	Draw();
	}
	void Draw()
	{
	HDC dc = bmp.getDC();
	if (dc == NULL)
		ErrorNull();
	int mov[] = { 0, 0, 1, -1, 1, -1, 1, 0 }, i = 0;
	for (int t = 0; t < 4; t++)
		{
		int a = 400, b = a; 
		a += mov[i++];
		b += mov[i++];
		if (!MoveToEx(dc, a, b, NULL))
			ErrorNull();
		bmp.SetPenColor(gColors[t]);
		for (string::iterator x = generator.begin(); x < generator.end(); x++)
			{
			switch (dir)
					{
					case 1:
						if (*x) 
							{ 
							a += 1; 
							dir = 2; 
							}
						else 
							{
							a -= 1;
							dir = 8;
							}
						break;
					case 2:
						if (*x)
							{ 
							b += 1;
							dir = 4;
							}
						else 
							{
							b -= 1;
							dir = 1;
							}
						break;
					case 4:
						if (*x)
							{
							a -= 1;
							dir = 8;
							}
						else
							{
							a += 1;
							dir = 2;
							}
						break;
					case 8:
						if (*x) 
							{
							b -= 1;
							dir = 1;
							}
						else 
							{
							b += 1;
							dir = 4;
							}
						break;
					}
			if (!LineTo(dc, a, b))
				ErrorNull();
			}
		}
	}
} DragonCurve;
inline void Save3DragonCurveFiles() // This function is made of only a small part of a function in the View class,  that keeps 395 files, most are fractals, named as serial numbers, this part is modified for sharing in the forum 
{
char szFull[4200] = "\0";
DragonCurve BDC; // 
BDC.Draw(17);
if (sprintf_s(szFull, 4200, "%s\\1.BMP", CurrentDIr(szFull)) == -1)
	ErrorNull();
BDC.Save(szFull);
DragonCurve GDC(8882055);
GDC.Draw(17);
if (sprintf_s(szFull, 4200, "%s\\2.BMP", CurrentDIr(szFull)) == -1)
	ErrorNull();
GDC.Save(szFull);
DragonCurve WDC(16777215);
WDC.Draw(17);
if (sprintf_s(szFull, 4200, "%s\\3.BMP", CurrentDIr(szFull)) == -1)
	ErrorNull();
WDC.Save(szFull);
}