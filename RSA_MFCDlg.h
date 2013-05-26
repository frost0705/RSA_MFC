
// RSA_MFCDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CRSA_MFCDlg
class CRSA_MFCDlg : public CDialogEx
{
// Создание
public:
	CRSA_MFCDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_RSA_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString openFilePath;
	CString encryptedFilePath;
	CString decryptedFilePath;
	CString encryptionKeyPath;
	CString decryptionFilePath;
	afx_msg void OnBnClickedFile();
	afx_msg void OnBnClickedFile2();
	afx_msg void OnBnClickedFile3();
	afx_msg void OnBnClickedFile4();
	afx_msg void OnBnClickedFile5();
	CString openFile;
	CString decryptedFile;
	CString openText;
	CString decryptedText;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
