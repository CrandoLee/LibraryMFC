// DeleteBookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "DeleteBookDlg.h"
#include "afxdialogex.h"


// DeleteBookDlg 对话框

IMPLEMENT_DYNAMIC(DeleteBookDlg, CDialogEx)

DeleteBookDlg::DeleteBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DeleteBookDlg::IDD, pParent)
{

}

DeleteBookDlg::~DeleteBookDlg()
{
}

void DeleteBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_cEditId);
	DDX_Control(pDX, IDC_LIST1, m_cListCtrl);
}


BEGIN_MESSAGE_MAP(DeleteBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DeleteBookDlg::OnQuery)
	ON_BN_CLICKED(IDC_BUTTON2, &DeleteBookDlg::OnDelete)
END_MESSAGE_MAP()


// DeleteBookDlg 消息处理程序


void DeleteBookDlg::OnQuery()
{
	// TODO:  在此添加控件通知处理程序代码
	m_cListCtrl.DeleteAllItems();
	CString sId;
	m_cEditId.GetWindowText(sId);
	wstring wsId = sId.GetString();
	string strId = m_stringConvert.ws2s(wsId);
	int nId = atoi(strId.c_str());
	Book book;
	book.SetBookID(-1);
	m_DbUtil.OpenDB();
	m_DbUtil.SelectBookById(nId, book);
	wstring wstrTemp;
	if (book.GetBookID() != -1)
	{
		//wsTemp = m_stringConvert.s2ws(book.GetBookID());
		wchar_t szID[4] = { 0 };
		wsprintf(szID, _T("%d"), book.GetBookID());
		m_cListCtrl.InsertItem(0, _T("1"));
		m_cListCtrl.SetItemText(0, 0, szID);
		wstrTemp = m_stringConvert.s2ws(book.GetBookName());
		m_cListCtrl.SetItemText(0, 1,wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(book.GetAuthor());
		m_cListCtrl.SetItemText(0, 2, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(book.GetISBN());
		m_cListCtrl.SetItemText(0, 3, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(book.GetPub());
		m_cListCtrl.SetItemText(0, 4, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(book.GetInDate());
		m_cListCtrl.SetItemText(0, 5, wstrTemp.c_str());
		wchar_t szTotal[4] = { 0 };
		wsprintf(szTotal, _T("%d"), book.GetTotalNum());
		m_cListCtrl.SetItemText(0, 6, szTotal);
	}
}


void DeleteBookDlg::OnDelete()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_cListCtrl.GetItemCount() > 0)
	{
		TCHAR szBuf[1024];
		LVITEM lvi;
		lvi.iItem = 0;
		lvi.iSubItem = 0;
		lvi.mask = LVIF_TEXT;
		lvi.pszText = szBuf;
		lvi.cchTextMax = 1024;
		m_cListCtrl.GetItem(&lvi);
		CString sId = szBuf;
		wstring wsId = sId.GetString();
		string strId = m_stringConvert.ws2s(wsId);
		if (m_DbUtil.DeleteBookById(atoi(strId.c_str())))
		{
			MessageBox(_T("删除成功"),_T("消息"), MB_USERICON | MB_OK);
			m_cListCtrl.DeleteAllItems();
		}
		else
		{
			MessageBox(_T("删除失败"), _T("消息"), MB_USERICON | MB_OK);
		}
	}
	else
	{
		//MessageBox(_T("没有这个相应ID的图书信息"), _T("警告"), MB_OK);
		MessageBox(_T("没有这个相应ID的图书信息"), _T("错误"), MB_ICONWARNING | MB_OK);
	}
}


BOOL DeleteBookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_cListCtrl.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 60);
	m_cListCtrl.InsertColumn(1, _T("书名"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(2, _T("作者"), LVCFMT_LEFT, 60);
	m_cListCtrl.InsertColumn(3, _T("ISBN"), LVCFMT_LEFT, 60);
	m_cListCtrl.InsertColumn(4, _T("出版社"), LVCFMT_LEFT, 60);
	m_cListCtrl.InsertColumn(5, _T("入库日期"), LVCFMT_LEFT, 60);
	m_cListCtrl.InsertColumn(6, _T("库存"), LVCFMT_LEFT, 60);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void DeleteBookDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	CDialogEx::OnCancel();
}


void DeleteBookDlg::OnOK()
{

}
