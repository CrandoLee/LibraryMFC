#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include <vector>
#include "Book.h"
#include "DBUtil.h"
#include "StringConvert.h"
using namespace std;
// BorrowBookDlg 对话框

class BorrowBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BorrowBookDlg)

public:
	BorrowBookDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BorrowBookDlg();

	HWND m_parentHwnd;
	DBUtil m_dbUtil;
	StringConvert m_stringConvert;
	vector<Book> m_books;
// 对话框数据
	enum { IDD = IDD_BORROWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cCombType;
	CEdit m_cName;
	afx_msg void OnQuery();
	CListCtrl m_cListCtrlResult;
	CEdit m_cEditID;
	afx_msg void OnBorrow();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
};
