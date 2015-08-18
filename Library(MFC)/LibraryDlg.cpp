
// LibraryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "LibraryDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CLibraryDlg 对话框



CLibraryDlg::CLibraryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLibraryDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLibraryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_cEditName);
	DDX_Control(pDX, IDC_EDIT2, m_cEditPass);
}

BEGIN_MESSAGE_MAP(CLibraryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CLibraryDlg::OnBtnCancel)
	ON_BN_CLICKED(IDOK, &CLibraryDlg::OnBtnSubmit)
END_MESSAGE_MAP()


// CLibraryDlg 消息处理程序

BOOL CLibraryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLibraryDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLibraryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLibraryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLibraryDlg::OnBtnCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CLibraryDlg::OnBtnSubmit()
{
	// TODO:  在此添加控件通知处理程序代码
	//AfxMessageBox(_T("sdas"));
	char chName[32] = { 0 };
	CString cstrName;
	m_cEditName.GetWindowText(cstrName);
	CString cstrPass;
	m_cEditPass.GetWindowText(cstrPass);
	DBUtil dbUtil;
	if (!dbUtil.OpenDB())
	{
		MessageBox(_T("错误"), _T("连接数据库失败"), MB_ICONWARNING | MB_OK);
		return;
	}
	StringConvert stringCovert;

	string strName;
	wstring wstrName = cstrName.GetString();
	strName = stringCovert.ws2s(wstrName);

	string strPass;
	wstring wstrPass = cstrPass.GetString();
	strPass = stringCovert.ws2s(wstrPass);

 	User user = dbUtil.ReadUser(strName, strPass);

	if (user.m_nRole == 0)
	{
		//登录用户为管理员
		AdminDlg* adminDlg = new AdminDlg();
		adminDlg->Create(IDD_ADMINDLG);
		adminDlg->m_bIsShow = true;
		adminDlg->ShowWindow(true);
		this->ShowWindow(false);
	}
	else if (user.m_nRole == 1)
	{
		//登陆用户为普通学生
	}
	else
	{
		MessageBox(_T("用户名或密码错误"), _T("错误"), MB_ICONWARNING | MB_OK);
		return;
	}
}
