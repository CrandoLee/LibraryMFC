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
	ON_BN_CLICKED(IDC_BUTTON2, &AdminDlg::OnQueryBook)
	ON_BN_CLICKED(IDC_BUTTON3, &AdminDlg::OnDeleteBook)
	ON_BN_CLICKED(IDC_BUTTON4, &AdminDlg::OnShowBookList)
	ON_BN_CLICKED(IDC_BUTTON6, &AdminDlg::OnAddUser)
	ON_BN_CLICKED(IDC_BUTTON7, &AdminDlg::OnShowUserList)
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

void AdminDlg::OnQueryBook()
{
	QueryBookDlg * queryBookDlg = new QueryBookDlg();
	queryBookDlg->m_parentHwnd = this->GetSafeHwnd();
	queryBookDlg->Create(IDD_QUERYDLG);
	queryBookDlg->ShowWindow(true);
	this->ShowWindow(false);
	m_bIsShow = false;
}


void AdminDlg::OnDeleteBook()
{
	DeleteBookDlg * deleteBookDlg = new DeleteBookDlg();
	deleteBookDlg->m_parentHwnd = this->GetSafeHwnd();
	deleteBookDlg->Create(IDD_DELBOOKDLG);
	deleteBookDlg->ShowWindow(true);
	this->ShowWindow(false);
	m_bIsShow = false;
}


void AdminDlg::OnShowBookList()
{
	// TODO:  在此添加控件通知处理程序代码
	BookListDlg *bookListDlg = new BookListDlg();
	bookListDlg->m_parentHwnd = this->GetSafeHwnd();
	bookListDlg->Create(IDD_BOOKLISTDLG);
	bookListDlg->ShowWindow(true);
	this->ShowWindow(false);
	m_bIsShow = false;
}


void AdminDlg::OnAddUser()
{
	AddUserDlg * addUserDlg = new AddUserDlg();
	addUserDlg->m_parentHwnd = this->GetSafeHwnd();
	addUserDlg->Create(IDD_ADDUSERDLG);
	addUserDlg->ShowWindow(true);
	this->ShowWindow(false);
	m_bIsShow = false;
}


void AdminDlg::OnShowUserList()
{
	UserListDlg *userListDlg = new UserListDlg();
	userListDlg->m_parentHwnd = this->GetSafeHwnd();
	userListDlg->Create(IDD_USERLISTDLG);
	userListDlg->ShowWindow(true);
	this->ShowWindow(false);
	m_bIsShow = false;
}
