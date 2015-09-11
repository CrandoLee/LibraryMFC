// BorrowRecordDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "BorrowRecordDlg.h"
#include "afxdialogex.h"


// BorrowRecordDlg 对话框

IMPLEMENT_DYNAMIC(BorrowRecordDlg, CDialogEx)

BorrowRecordDlg::BorrowRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(BorrowRecordDlg::IDD, pParent)
{

}

BorrowRecordDlg::~BorrowRecordDlg()
{
}

void BorrowRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_cListCtrl);
}


BEGIN_MESSAGE_MAP(BorrowRecordDlg, CDialogEx)
END_MESSAGE_MAP()


// BorrowRecordDlg 消息处理程序


void BorrowRecordDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	::SendMessage(m_parentHwnd,WM_CHANEG_STATE,NULL,NULL);
	CDialogEx::OnCancel();
}


BOOL BorrowRecordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_nStuID = 0;
	
	m_cListCtrl.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 60);
	m_cListCtrl.InsertColumn(1, _T("书名"), LVCFMT_LEFT, 100);
	m_cListCtrl.InsertColumn(2, _T("借阅人"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(3, _T("借阅日期"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(4, _T("应还日期"), LVCFMT_LEFT, 80);
	m_cListCtrl.InsertColumn(5, _T("还书日期"), LVCFMT_LEFT, 78);
	m_cListCtrl.InsertColumn(6, _T("续借次数"), LVCFMT_LEFT, 79);

	vector<BorrowRecord> borrowRecords;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	if (m_nStuID != 0)
	{
		m_dbUtil.SelectBorrowRecordByUserId(borrowRecords,m_nStuID, 2);
	}
	else
	{
		m_dbUtil.SelectAllBorrowRecord(borrowRecords);
	}
	
	User user;
	Book book;
	vector<BorrowRecord>::iterator vecIter;
	int i = 0;
	cout << "ID       书名        借阅人    借阅日期       应还日期     还书日期   续借次数" << endl;
	for (vecIter = borrowRecords.begin(); vecIter != borrowRecords.end(); vecIter++)
	{
		user = m_dbUtil.SelectUserById(vecIter->m_nUserId);
		m_dbUtil.SelectBookById(vecIter->m_nBookId, book);
		wchar_t chBorrowId[4] = { 0 };
		wsprintf(chBorrowId, _T("%d"), vecIter->m_nBorrowId);
		m_cListCtrl.InsertItem(i, chBorrowId);
		m_cListCtrl.SetItemText(i, 0, chBorrowId);
		m_cListCtrl.SetItemText(i, 1, m_stringConvert.s2ws(book.GetBookName()).c_str());
		m_cListCtrl.SetItemText(i, 2, m_stringConvert.s2ws(user.m_strName).c_str());
		m_cListCtrl.SetItemText(i, 3, m_stringConvert.s2ws(vecIter->m_tBorrowDate).c_str());
		m_cListCtrl.SetItemText(i, 4, m_stringConvert.s2ws(vecIter->m_tShouldReturnDate).c_str());
		if (vecIter->m_tReturnDate.length() == 0)
		{
			m_cListCtrl.SetItemText(i, 5, L"");
		}
		else
		{
			m_cListCtrl.SetItemText(i, 5, m_stringConvert.s2ws(vecIter->m_tReturnDate).c_str());
		}
		
		wchar_t szContinue[8] = { 0 };
		wsprintf(szContinue, _T("%d"), vecIter->m_nContinue);
		m_cListCtrl.SetItemText(i, 6, szContinue);
		i ++;

	}
	
	return TRUE;  

}


void BorrowRecordDlg::OnOK()
{

}
