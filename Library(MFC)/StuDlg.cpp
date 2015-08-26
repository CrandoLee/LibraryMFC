// StuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "StuDlg.h"
#include "afxdialogex.h"


// StuDlg 对话框

IMPLEMENT_DYNAMIC(StuDlg, CDialogEx)

StuDlg::StuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(StuDlg::IDD, pParent)
{

}

StuDlg::~StuDlg()
{
}

void StuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StuDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &StuDlg::OnLogout)
END_MESSAGE_MAP()


// StuDlg 消息处理程序


void StuDlg::OnCancel()
{
	
	exit(0);
}

//退出登录
void StuDlg::OnLogout()
{
	OnCancel();
}
