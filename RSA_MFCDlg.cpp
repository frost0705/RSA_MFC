
// RSA_MFCDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "RSA_MFC.h"
#include "RSA_MFCDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CRSA_MFCDlg



CRSA_MFCDlg::CRSA_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRSA_MFCDlg::IDD, pParent)
	, openFilePath(_T("C:\\Users\\Frost0705\\Desktop\\RSA_Files\\open_file.txt"))
	, encryptedFilePath(_T("C:\\Users\\Frost0705\\Desktop\\RSA_Files\\encrypted_file.txt"))
	, decryptedFilePath(_T("C:\\Users\\Frost0705\\Desktop\\RSA_Files\\decrypted_file.txt"))
	, encryptionKeyPath(_T("C:\\Users\\Frost0705\\Desktop\\RSA_Files\\encryption_key.txt"))
	, decryptionFilePath(_T("C:\\Users\\Frost0705\\Desktop\\RSA_Files\\decryption_key.txt"))
	, openText(_T("Содержание открытого файла"))
	, decryptedText(_T("Содержание расшифрованного файла"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSA_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, PATH_EDIT_openFile, openFilePath);
	DDX_Text(pDX, PATH_EDIT2_encryptedFile, encryptedFilePath);
	DDX_Text(pDX, PATH_EDIT4_decryptedFile, decryptedFilePath);
	DDX_Text(pDX, PATH_EDIT3_encryptionKey, encryptionKeyPath);
	DDX_Text(pDX, PATH_EDIT5_decryptionKey, decryptionFilePath);

	DDX_Text(pDX, IDC_EDIT4, openText);
	DDX_Text(pDX, IDC_EDIT5, decryptedText);
}

BEGIN_MESSAGE_MAP(CRSA_MFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(OPEN_FILE, &CRSA_MFCDlg::OnBnClickedFile)
	ON_BN_CLICKED(OPEN_FILE2, &CRSA_MFCDlg::OnBnClickedFile2)
	ON_BN_CLICKED(OPEN_FILE3, &CRSA_MFCDlg::OnBnClickedFile3)
	ON_BN_CLICKED(OPEN_FILE4, &CRSA_MFCDlg::OnBnClickedFile4)
	ON_BN_CLICKED(OPEN_FILE5, &CRSA_MFCDlg::OnBnClickedFile5)
	ON_BN_CLICKED(IDC_BUTTON2, &CRSA_MFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRSA_MFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CRSA_MFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CRSA_MFCDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// обработчики сообщений CRSA_MFCDlg

BOOL CRSA_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CRSA_MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CRSA_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CRSA_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//#include "RSA_frost0705.h"


void CRSA_MFCDlg::OnBnClickedFile()
{
	CFileDialog dlg(TRUE);
	
	if (dlg.DoModal() == IDOK)
	{
		openFilePath = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}

void CRSA_MFCDlg::OnBnClickedFile2()
{
	CFileDialog dlg(TRUE);
	
	if (dlg.DoModal() == IDOK)
	{
		encryptedFilePath = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}

void CRSA_MFCDlg::OnBnClickedFile3()
{
	CFileDialog dlg(TRUE);
	
	if (dlg.DoModal() == IDOK)
	{
		decryptedFilePath = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}

void CRSA_MFCDlg::OnBnClickedFile4()
{
	CFileDialog dlg(TRUE);
	
	if (dlg.DoModal() == IDOK)
	{
		encryptionKeyPath = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}

void CRSA_MFCDlg::OnBnClickedFile5()
{
	CFileDialog dlg(TRUE);
	
	if (dlg.DoModal() == IDOK)
	{
		decryptionFilePath = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}


void CRSA_MFCDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	FILE *openFile;
	
	fopen_s(&openFile,openFilePath,"w");
	int size;
	size = openText.GetLength();
	openText.OemToCharA();
	wchar_t *h = new wchar_t[size];
	for (int i = 0; i < size;i++)
	{
		h[i] = openText[i];
	}
	fwrite(&size,sizeof(int),1,openFile);
	fwrite(h,size*sizeof(wchar_t),1,openFile);
	delete [] h;
	fclose(openFile);
}


void CRSA_MFCDlg::OnBnClickedButton3()
{

	UpdateData(TRUE);

	FILE *openFile;
	fopen_s(&openFile,openFilePath,"r");
	int size;
	
	fread(&size,sizeof(int),1,openFile);
	wchar_t *h = new wchar_t[size];
	fread(h,size*sizeof(wchar_t),1,openFile);
	CString message(h,size);
	openText = message;
	fclose(openFile);
	delete [] h;
	UpdateData(FALSE);




}


void CRSA_MFCDlg::OnBnClickedButton4()
{
	UpdateData(TRUE);

	FILE *decryptedFile;
	fopen_s(&decryptedFile,decryptedFilePath,"r");
	int size;
	
	fread(&size,sizeof(int),1,decryptedFile);
	wchar_t *h = new wchar_t[size];
	fread(h,size*sizeof(wchar_t),1,decryptedFile);
	CString message(h,size);
	
	decryptedText = message;
	fclose(decryptedFile);
	delete [] h;
	UpdateData(FALSE);
}


void CRSA_MFCDlg::OnBnClickedButton5()
{
	// TODO: добавьте свой код обработчика уведомлений
}
