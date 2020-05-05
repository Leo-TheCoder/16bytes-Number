
// CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalculatorDlg dialog

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, DecInput(_T(""))
	, BinInput(_T(""))
	, HexInput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, DecInput);
	DDX_Text(pDX, IDC_EDIT2, BinInput);
	DDX_Text(pDX, IDC_EDIT3, HexInput);
	DDX_Control(pDX, BtnNum1, b_Num1);
	DDX_Control(pDX, BtnNum2, b_Num2);
	DDX_Control(pDX, BtnNum3, b_Num3);
	DDX_Control(pDX, BtnNum4, b_Num4);
	DDX_Control(pDX, BtnNum5, b_Num5);
	DDX_Control(pDX, BtnNum6, b_Num6);
	DDX_Control(pDX, BtnNum7, b_Num7);
	DDX_Control(pDX, BtnNum8, b_Num8);
	DDX_Control(pDX, BtnNum9, b_Num9);
	DDX_Control(pDX, BtnNum0, b_Num0);
	DDX_Control(pDX, BtnNumA, b_NumA);
	DDX_Control(pDX, BtnNumB, b_NumB);
	DDX_Control(pDX, BtnNumC, b_NumC);
	DDX_Control(pDX, BtnNumD, b_NumD);
	DDX_Control(pDX, BtnNumE, b_NumE);
	DDX_Control(pDX, BtnNumF, b_NumF);

	DDX_Control(pDX, BtnEqual, b_Equal);
	DDX_Control(pDX, BtnBackspace, b_Del);
	DDX_Control(pDX, BtnClear, b_Clear);
	DDX_Control(pDX, BtnDot, b_Dot);
	DDX_Control(pDX, BtnChangeSign, b_ChangeSign);

	DDX_Control(pDX, BtnPlus, b_oprPlus);
	DDX_Control(pDX, BtnMinus, b_oprMinus);
	DDX_Control(pDX, BtnMultiply, b_oprMultiply);
	DDX_Control(pDX, BtnDivision, b_oprDivision);

	DDX_Control(pDX, BtnAnd, b_oprAnd);
	DDX_Control(pDX, BtnOr, b_oprOr);
	DDX_Control(pDX, BtnXor, b_oprXor);
	DDX_Control(pDX, BtnNot, b_oprNot);
	DDX_Control(pDX, BtnRightShift, b_oprRightShift);
	DDX_Control(pDX, BtnLeftShift, b_oprLeftShift);
	DDX_Control(pDX, BtnRolLeft, b_oprLeftRol);
	DDX_Control(pDX, BtnRolRight, b_oprRightRol);

	DDX_Control(pDX, BtnBin, b_Binary);
	DDX_Control(pDX, BtnHex, b_Hex);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(BtnNum1, &CCalculatorDlg::OnBnClickedBtnnum1)
	ON_BN_CLICKED(BtnNum2, &CCalculatorDlg::OnBnClickedBtnnum2)
	ON_BN_CLICKED(BtnNum3, &CCalculatorDlg::OnBnClickedBtnnum3)
	ON_BN_CLICKED(BtnNum4, &CCalculatorDlg::OnBnClickedBtnnum4)
	ON_BN_CLICKED(BtnNum5, &CCalculatorDlg::OnBnClickedBtnnum5)
	ON_BN_CLICKED(BtnNum6, &CCalculatorDlg::OnBnClickedBtnnum6)
	ON_BN_CLICKED(BtnNum7, &CCalculatorDlg::OnBnClickedBtnnum7)
	ON_BN_CLICKED(BtnNum8, &CCalculatorDlg::OnBnClickedBtnnum8)
	ON_BN_CLICKED(BtnNum9, &CCalculatorDlg::OnBnClickedBtnnum9)
	ON_BN_CLICKED(BtnChangeSign, &CCalculatorDlg::OnBnClickedBtnchangesign)
	ON_BN_CLICKED(BtnNum0, &CCalculatorDlg::OnBnClickedBtnnum0)
	ON_BN_CLICKED(BtnDot, &CCalculatorDlg::OnBnClickedBtndot)
	ON_BN_CLICKED(BtnPlus, &CCalculatorDlg::OnBnClickedBtnplus)
	ON_BN_CLICKED(BtnMinus, &CCalculatorDlg::OnBnClickedBtnminus)
	ON_BN_CLICKED(BtnMultiply, &CCalculatorDlg::OnBnClickedBtnmultiply)
	ON_BN_CLICKED(BtnDivision, &CCalculatorDlg::OnBnClickedBtndivision)
	ON_BN_CLICKED(BtnEqual, &CCalculatorDlg::OnBnClickedBtnequal)
	ON_BN_CLICKED(BtnNumA, &CCalculatorDlg::OnBnClickedBtnnuma)
	ON_BN_CLICKED(BtnNumB, &CCalculatorDlg::OnBnClickedBtnnumb)
	ON_BN_CLICKED(BtnNumC, &CCalculatorDlg::OnBnClickedBtnnumc)
	ON_BN_CLICKED(BtnNumD, &CCalculatorDlg::OnBnClickedBtnnumd)
	ON_BN_CLICKED(BtnNumE, &CCalculatorDlg::OnBnClickedBtnnume)
	ON_BN_CLICKED(BtnNumF, &CCalculatorDlg::OnBnClickedBtnnumf)
	ON_BN_CLICKED(BtnAnd, &CCalculatorDlg::OnBnClickedBtnand)
	ON_BN_CLICKED(BtnOr, &CCalculatorDlg::OnBnClickedBtnor)
	ON_BN_CLICKED(BtnXor, &CCalculatorDlg::OnBnClickedBtnxor)
	ON_BN_CLICKED(BtnNot, &CCalculatorDlg::OnBnClickedBtnnot)
	ON_BN_CLICKED(BtnRightSihft, &CCalculatorDlg::OnBnClickedBtnrightsihft)
	ON_BN_CLICKED(BtnLeftShift, &CCalculatorDlg::OnBnClickedBtnleftshift)
	ON_BN_CLICKED(BtnRolRight, &CCalculatorDlg::OnBnClickedBtnrolright)
	ON_BN_CLICKED(BtnRolLeft, &CCalculatorDlg::OnBnClickedBtnrolleft)
	ON_BN_CLICKED(BtnBackspace, &CCalculatorDlg::OnBnClickedBtnbackspace)
	ON_BN_CLICKED(BtnClear, &CCalculatorDlg::OnBnClickedBtnclear)
	ON_BN_CLICKED(BtnHex, &CCalculatorDlg::OnBnClickedBtnhex)
	ON_BN_CLICKED(BtnBin, &CCalculatorDlg::OnBnClickedBtnbin)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	ShowWindow(SW_NORMAL);

	// TODO: Add extra initialization here
	ActiveInput = &DecInput;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CCalculatorDlg::OnBnClickedBtnchangesign()
{
	// TODO: Add your control notification handler code here
}