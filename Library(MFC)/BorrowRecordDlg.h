#pragma once
#include "afxcmn.h"
#include <vector>
#include "BorrowRecord.h"
#include "DBUtil.h"
#include "Book.h"
#include "User.h"
#include "StringConvert.h"
using namespace std;
// BorrowRecordDlg 对话框

class BorrowRecordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BorrowRecordDlg)

public:
	BorrowRecordDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BorrowRecordDlg();
	HWND m_parentHwnd;
	DBUtil m_dbUtil;
	StringConvert m_stringConvert;
// 对话框数据
	enum { IDD = IDD_BORROWRECORDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_cListCtrl;
};
