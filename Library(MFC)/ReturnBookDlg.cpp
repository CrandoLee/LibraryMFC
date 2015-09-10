// ReturnBookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "ReturnBookDlg.h"
#include "afxdialogex.h"


// ReturnBookDlg 对话框

IMPLEMENT_DYNAMIC(ReturnBookDlg, CDialogEx)

ReturnBookDlg::ReturnBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ReturnBookDlg::IDD, pParent)
{

}

ReturnBookDlg::~ReturnBookDlg()
{
}

void ReturnBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_cListCtrl);
	DDX_Control(pDX, IDC_EDIT1, m_cEditID);
}


BEGIN_MESSAGE_MAP(ReturnBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ReturnBookDlg::OnReturnBook)
END_MESSAGE_MAP()


// ReturnBookDlg 消息处理程序


void ReturnBookDlg::OnReturnBook()
{
	CString cstrBookId;
	m_cEditID.GetWindowText(cstrBookId);
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	wstring wstrID = cstrBookId;
	string strID = m_stringConvert.ws2s(wstrID);
	int nRecordId = atoi(strID.c_str());
	vector<BorrowRecord>::iterator vecIter;
	for (vecIter = m_vecBorrowRecords.begin(); vecIter != m_vecBorrowRecords.end(); vecIter++)
	{
		if (nRecordId == vecIter->m_nBorrowId)
		{
			break;
		}
	}
	if (vecIter == m_vecBorrowRecords.end())
	{
		MessageBox(L"您所输入的ID不在记录中，请重新输入");
		return;
	}
	
	if (m_dbUtil.FinishBorrowRecord(vecIter->m_nBorrowId, vecIter->m_nBookId))
	{
		MessageBox(L"归还成功");

		m_cListCtrl.DeleteAllItems();
		m_vecBorrowRecords.empty();
		m_dbUtil.SelectBorrowRecordByUserId(m_vecBorrowRecords, m_user.m_nID, 1);

		User user;
		Book book;
		vector<BorrowRecord>::iterator vecIter;
		int i = 0;
		for (vecIter = m_vecBorrowRecords.begin(); vecIter != m_vecBorrowRecords.end(); vecIter++)
		{
			user = m_dbUtil.SelectUserById(vecIter->m_nUserId);
			m_dbUtil.SelectBookById(vecIter->m_nBookId, book);
			wchar_t chBorrowId[4] = { 0 };
			wsprintf(chBorrowId, _T("%d"), vecIter->m_nBorrowId);
			m_cListCtrl.InsertItem(i, chBorrowId);
			m_cListCtrl.SetItemText(i, 0, chBorrowId);
			m_cListCtrl.SetItemText(i, 1, m_stringConvert.s2ws(book.GetBookName()).c_str());
			m_cListCtrl.SetItemText(i, 2, m_stringConvert.s2ws(vecIter->m_tBorrowDate).c_str());
			m_cListCtrl.SetItemText(i, 3, m_stringConvert.s2ws(vecIter->m_tShouldReturnDate).c_str());

			wchar_t szContinue[8] = { 0 };
			wsprintf(szContinue, _T("%d"), vecIter->m_nContinue);
			m_cListCtrl.SetItemText(i, 4, szContinue);
			i++;
		}
	}


	
}


BOOL ReturnBookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_cListCtrl.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 60);
	m_cListCtrl.InsertColumn(1, _T("书名"), LVCFMT_LEFT, 100);
	m_cListCtrl.InsertColumn(2, _T("借阅日期"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(3, _T("应还日期"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(4, _T("续借次数"), LVCFMT_LEFT, 79);

	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectBorrowRecordByUserId(m_vecBorrowRecords, m_user.m_nID, 1);

	User user;
	Book book;
	vector<BorrowRecord>::iterator vecIter;
	int i = 0;
	for (vecIter = m_vecBorrowRecords.begin(); vecIter != m_vecBorrowRecords.end(); vecIter++)
	{
		user = m_dbUtil.SelectUserById(vecIter->m_nUserId);
		m_dbUtil.SelectBookById(vecIter->m_nBookId, book);
		wchar_t chBorrowId[4] = { 0 };
		wsprintf(chBorrowId, _T("%d"), vecIter->m_nBorrowId);
		m_cListCtrl.InsertItem(i, chBorrowId);
		m_cListCtrl.SetItemText(i, 0, chBorrowId);
		m_cListCtrl.SetItemText(i, 1, m_stringConvert.s2ws(book.GetBookName()).c_str());
		m_cListCtrl.SetItemText(i, 2, m_stringConvert.s2ws(vecIter->m_tBorrowDate).c_str());
		m_cListCtrl.SetItemText(i, 3, m_stringConvert.s2ws(vecIter->m_tShouldReturnDate).c_str());

		wchar_t szContinue[8] = { 0 };
		wsprintf(szContinue, _T("%d"), vecIter->m_nContinue);
		m_cListCtrl.SetItemText(i, 4, szContinue);
		i++;
	}

	return TRUE;  

}


void ReturnBookDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	CDialogEx::OnCancel();
}
