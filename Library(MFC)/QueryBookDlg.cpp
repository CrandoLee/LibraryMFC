// QueryBookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "QueryBookDlg.h"
#include "afxdialogex.h"


// QueryBookDlg 对话框

IMPLEMENT_DYNAMIC(QueryBookDlg, CDialogEx)

QueryBookDlg::QueryBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(QueryBookDlg::IDD, pParent)
{

}

QueryBookDlg::~QueryBookDlg()
{
}

void QueryBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_cComBox);
	DDX_Control(pDX, IDC_EDIT1, m_cEditName);
	DDX_Control(pDX, IDC_LIST1, m_cListCtrl);
}


BEGIN_MESSAGE_MAP(QueryBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &QueryBookDlg::OnQuery)

END_MESSAGE_MAP()


// QueryBookDlg 消息处理程序


void QueryBookDlg::OnQuery()
{
	m_cListCtrl.DeleteAllItems();
	vector<Book> books;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	string strBookName;
	int nIndex = m_cComBox.GetCurSel();
	//wchar_t szName[64] = { 0 };
	CString strName;
	m_cEditName.GetWindowText(strName);
	//wsprintf(szName, _T("%s"), strName);
	wstring wstrName = strName.GetString();
	strBookName = m_stringConvert.ws2s(wstrName);
	//根据书名或者作者进行查询
	if (nIndex == 0 || nIndex == -1)
	{
		m_dbUtil.SelectBookByName(strBookName, books);
	}
	else if (nIndex == 1)
	{
		m_dbUtil.SelectBookByAuthor(strBookName, books);
	}
	vector<Book>::iterator vecIter;
	int i = 0, j = 0;
	int number = m_cListCtrl.GetItemCount();
	wstring wstrTemp;
	for (vecIter = books.begin(); vecIter != books.end(); vecIter++)
	{
		wchar_t chId[4] = { 0 };
		wsprintf(chId, _T("%d"), i + 1);
		m_cListCtrl.InsertItem(i, chId);
		m_cListCtrl.SetItemText(i, j++, chId);
		wstrTemp = m_stringConvert.s2ws(vecIter->GetBookName());
		m_cListCtrl.SetItemText(i, j++, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(vecIter->GetAuthor());
		m_cListCtrl.SetItemText(i, j++, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(vecIter->GetISBN());
		m_cListCtrl.SetItemText(i, j++, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(vecIter->GetPub());
		m_cListCtrl.SetItemText(i, j++, wstrTemp.c_str());
		wchar_t wstrTotal[4] = { 0 };
		wsprintf(wstrTotal, _T("%d"), vecIter->GetTotalNum());
		m_cListCtrl.SetItemText(i, j++, wstrTotal);
		wchar_t wstrLeft[4] = { 0 };
		wsprintf(wstrLeft, _T("%d"), vecIter->GetLeftNum());
		m_cListCtrl.SetItemText(i, j++, wstrLeft);
		i ++;
		j = 0;
	}

}


BOOL QueryBookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_cComBox.SetWindowText(_T("书名"));
	m_cComBox.AddString(_T("书名"));
	m_cComBox.AddString(_T("作者"));

 	m_cListCtrl.InsertColumn(0, _T("编号"),LVCFMT_LEFT,80);
	m_cListCtrl.InsertColumn(1, _T("书名"), LVCFMT_LEFT, 100);
	m_cListCtrl.InsertColumn(2, _T("作者"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(3, _T("ISBN"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(4, _T("出版社"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(5, _T("库存"), LVCFMT_LEFT, 78);
	m_cListCtrl.InsertColumn(6, _T("余量"), LVCFMT_LEFT,79);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void QueryBookDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	CDialogEx::OnCancel();
}
