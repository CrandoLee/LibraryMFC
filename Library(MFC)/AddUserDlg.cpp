// AddUserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "AddUserDlg.h"
#include "afxdialogex.h"


// AddUserDlg 对话框

IMPLEMENT_DYNAMIC(AddUserDlg, CDialogEx)

AddUserDlg::AddUserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddUserDlg::IDD, pParent)
{

}

AddUserDlg::~AddUserDlg()
{
}

void AddUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_cEditName);
	DDX_Control(pDX, IDC_EDIT2, m_cEditPassword);
	DDX_Control(pDX, IDC_COMBO1, m_cCombType);
}


BEGIN_MESSAGE_MAP(AddUserDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &AddUserDlg::OnBtnCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &AddUserDlg::OnSaveUser)
END_MESSAGE_MAP()


// AddUserDlg 消息处理程序


void AddUserDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	CDialogEx::OnCancel();
}


void AddUserDlg::OnBtnCancel()
{
	OnCancel();
}


BOOL AddUserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_cCombType.SetWindowText(L"学生");
	m_cCombType.AddString(L"学生");
	m_cCombType.AddString(L"管理员");
	return TRUE;
}


void AddUserDlg::OnSaveUser()
{
	int nIndex = m_cCombType.GetCurSel();
	if (nIndex == 1 || nIndex == -1)
	{
		nIndex = 0;
	}
	else
	{
		nIndex = 1;
	}
	User user;
	CString cstrName;
	m_cEditName.GetWindowText(cstrName);
	CString cstrPassword;
	m_cEditPassword.GetWindowText(cstrPassword);

	wstring wstrName = cstrName;
	wstring wstrPassword = cstrPassword;
	string strName = m_stringConvert.ws2s(wstrName);
	string strPassword = m_stringConvert.ws2s(wstrPassword);

	if (strName == "")
	{
		MessageBox(L"用户名不能为空");
		return;
	}

	if (strPassword == "")
	{
		MessageBox(L"密码不能为空");
		return;
	}

	user.m_strName = strName;
	user.m_strPassword = strPassword;
	user.m_nRole = nIndex;

	m_dbUtil.OpenDB();
	m_dbUtil.AddUser(user);
	MessageBox(L"用户添加成功");
}
