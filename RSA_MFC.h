
// RSA_MFC.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CRSA_MFCApp:
// О реализации данного класса см. RSA_MFC.cpp
//

class CRSA_MFCApp : public CWinApp
{
public:
	CRSA_MFCApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CRSA_MFCApp theApp;