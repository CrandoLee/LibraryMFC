// AdminDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "AdminDlg.h"
#include "afxdialogex.h"

// AdminDlg 对话框

IMPLEMENT_DYNAMIC(AdminDlg, CDialog)

AdminDlg::AdminDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AdminDlg::IDD, pParent)
{

}

AdminDlg::~AdminDlg()
{
}

void AdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdminDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON8, &AdminDlg::OnCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &AdminDlg::OnAddBook)
	ON_MESSAGE(WM_CHANEG_STATE, &AdminDlg::OnChangeState)
END_MESSAGE_MAP()


// AdminDlg 消息处理程序

//退出登录
void AdminDlg::OnCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	exit(0);
}


void AdminDlg::OnAddBook()
{
	// TODO:  在此添加控件通知处理程序代码
	AddBookDlg* addBoolDlg = new AddBookDlg();
	addBoolDlg->m_parentHwnd = this->GetSafeHwnd();
	addBoolDlg->Create(IDD_ADDBOOKDLG);
	addBoolDlg->ShowWindow(true);
	this->ShowWindow(false);
	m_bIsShow = false;
}

afx_msg LRESULT  AdminDlg::OnChangeState(WPARAM wParam, LPARAM lParam)
{
	if (m_bIsShow == false)
	{
		m_bIsShow = true;
		this->ShowWindow(true);
	}
	return true;
}