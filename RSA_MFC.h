
// RSA_MFC.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CRSA_MFCApp:
// � ���������� ������� ������ ��. RSA_MFC.cpp
//

class CRSA_MFCApp : public CWinApp
{
public:
	CRSA_MFCApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CRSA_MFCApp theApp;