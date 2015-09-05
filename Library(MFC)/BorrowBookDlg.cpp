// BorrowBookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "BorrowBookDlg.h"
#include "afxdialogex.h"


// BorrowBookDlg 对话框

IMPLEMENT_DYNAMIC(BorrowBookDlg, CDialogEx)

BorrowBookDlg::BorrowBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(BorrowBookDlg::IDD, pParent)
{

}

BorrowBookDlg::~BorrowBookDlg()
{
}

void BorrowBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_cCombType);
	DDX_Control(pDX, IDC_EDIT1, m_cName);
	DDX_Control(pDX, IDC_LIST1, m_cListCtrlResult);
	DDX_Control(pDX, IDC_EDIT2, m_cEditID);
}


BEGIN_MESSAGE_MAP(BorrowBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &BorrowBookDlg::OnQuery)
	ON_BN_CLICKED(IDC_BUTTON2, &BorrowBookDlg::OnBorrow)
END_MESSAGE_MAP()


// BorrowBookDlg 消息处理程序


void BorrowBookDlg::OnQuery()
{
	m_cListCtrlResult.DeleteAllItems();
	m_books.empty();
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	string strBookName;
	int nIndex = m_cCombType.GetCurSel();
	//wchar_t szName[64] = { 0 };
	CString strName;
	m_cName.GetWindowText(strName);
	//wsprintf(szName, _T("%s"), strName);
	wstring wstrName = strName.GetString();
	strBookName = m_stringConvert.ws2s(wstrName);
	//根据书名或者作者进行查询
	if (nIndex == 0 || nIndex == -1)
	{
		m_dbUtil.SelectBookByName(strBookName, m_books);
	}
	else if (nIndex == 1)
	{
		m_dbUtil.SelectBookByAuthor(strBookName, m_books);
	}
	vector<Book>::iterator vecIter;
	int i = 0, j = 0;
	int number = m_cListCtrlResult.GetItemCount();
	wstring wstrTemp;
	for (vecIter = m_books.begin(); vecIter != books.end(); vecIter++)
	{
		wchar_t chId[4] = { 0 };
		wsprintf(chId, _T("%d"), vecIter->GetBookID());
		m_cListCtrlResult.InsertItem(i, chId);
		m_cListCtrlResult.SetItemText(i, j++, chId);
		wstrTemp = m_stringConvert.s2ws(vecIter->GetBookName());
		m_cListCtrlResult.SetItemText(i, j++, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(vecIter->GetAuthor());
		m_cListCtrlResult.SetItemText(i, j++, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(vecIter->GetISBN());
		m_cListCtrlResult.SetItemText(i, j++, wstrTemp.c_str());
		wstrTemp = m_stringConvert.s2ws(vecIter->GetPub());
		m_cListCtrlResult.SetItemText(i, j++, wstrTemp.c_str());
		wchar_t wstrTotal[4] = { 0 };
		wsprintf(wstrTotal, _T("%d"), vecIter->GetTotalNum());
		m_cListCtrlResult.SetItemText(i, j++, wstrTotal);
		wchar_t wstrLeft[4] = { 0 };
		wsprintf(wstrLeft, _T("%d"), vecIter->GetLeftNum());
		m_cListCtrlResult.SetItemText(i, j++, wstrLeft);
		i ++;
		j = 0;
	}
}


void BorrowBookDlg::OnBorrow()
{
	CString cstrID;
	m_cEditID.GetWindowText(cstrID);
	wstring wstrID = cstrID;
	string strID = m_stringConvert.ws2s(wstrID);
	Book book;
	vector<Book>::iterator iterVec;
	for (iterVec = m_books.begin(); iterVec != m_books.end(); iterVec++)
	{
		if (iterVec->GetBookID() == atoi(strID.c_str()))
		{
			if (iterVec->GetLeftNum() == 0)
			{
				MessageBox(L"您选择的书籍没有余量，无法借阅");
				break;
			}
			else
			{
				m_dbUtil.
			}
		}
	}
}


BOOL BorrowBookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_cCombType.SetWindowTextW(_T("书名"));
	m_cCombType.AddString(_T("书名"));
	m_cCombType.AddString(_T("作者"));

	m_cListCtrlResult.InsertColumn(0, _T("图书ID"), LVCFMT_LEFT, 90);
	m_cListCtrlResult.InsertColumn(1, _T("书名"), LVCFMT_LEFT, 90);
	m_cListCtrlResult.InsertColumn(2, _T("作者"), LVCFMT_LEFT, 70);
	m_cListCtrlResult.InsertColumn(3, _T("ISBN"), LVCFMT_LEFT, 70);
	m_cListCtrlResult.InsertColumn(4, _T("出版社"), LVCFMT_LEFT, 70);
	m_cListCtrlResult.InsertColumn(5, _T("库存"), LVCFMT_LEFT, 48);
	m_cListCtrlResult.InsertColumn(6, _T("余量"), LVCFMT_LEFT, 49);

	return TRUE;  

}


void BorrowBookDlg::OnCancel()
{
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	CDialogEx::OnCancel();
}
