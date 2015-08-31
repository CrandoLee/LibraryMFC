// UserListDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "UserListDlg.h"
#include "afxdialogex.h"


// UserListDlg 对话框

IMPLEMENT_DYNAMIC(UserListDlg, CDialogEx)

UserListDlg::UserListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(UserListDlg::IDD, pParent)
{

}

UserListDlg::~UserListDlg()
{
}

void UserListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_cListUser);
}


BEGIN_MESSAGE_MAP(UserListDlg, CDialogEx)
END_MESSAGE_MAP()


// UserListDlg 消息处理程序


BOOL UserListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//CRect crect;
	//m_cListUser.GetWindowRect(crect);
	m_cListUser.InsertColumn(0, _T("ID"), LVCFMT_LEFT,100);
	m_cListUser.InsertColumn(1, _T("用户名"), LVCFMT_LEFT, 100);
	m_cListUser.InsertColumn(2, _T("用户类型"), LVCFMT_LEFT, 100);

	m_dbUtil.OpenDB();
	vector<User> vecUsers;
	m_dbUtil.SelectAllUser(vecUsers);

	vector<User>::iterator vecIter;
	User userTemp;
	int i = 0, j = 0;
	for (vecIter = vecUsers.begin(); vecIter != vecUsers.end(); vecIter ++)
	{
		userTemp = *vecIter;
		m_cListUser.InsertItem(i,_T(""));
		wchar_t wszID[10] = { 0 };
		wsprintf(wszID, _T("%d"), userTemp.m_nID);

		wstring wstrName = m_stringConvert.s2ws(userTemp.m_strName);

		m_cListUser.SetItemText(i, 0, wszID);
		m_cListUser.SetItemText(i, 1, wstrName.c_str());
		if (userTemp.m_nRole == 0)
		{
			m_cListUser.SetItemText(i, 2, _T("管理员"));
		}
		else
		{
			m_cListUser.SetItemText(i, 2, _T("学生"));
		}
		i ++;
	}
	return TRUE;  
}


void UserListDlg::OnCancel()
{
	
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	CDialogEx::OnCancel();
}
