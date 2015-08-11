// AddBookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "AddBookDlg.h"
#include "afxdialogex.h"


// AddBookDlg 对话框

IMPLEMENT_DYNAMIC(AddBookDlg, CDialogEx)

AddBookDlg::AddBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddBookDlg::IDD, pParent)
{

}

AddBookDlg::~AddBookDlg()
{
}

void AddBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &AddBookDlg::OnCancel)
END_MESSAGE_MAP()


// AddBookDlg 消息处理程序


void AddBookDlg::OnCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	OnCancel();
	//SendMessage()
}
