#pragma once
#include "QueryBookDlg.h"
#include "BorrowBookDlg.h"
#include "User.h"
#include "BorrowRecordDlg.h"
#include "ReturnBookDlg.h"
#include "ReBorrowBookDlg.h"
// StuDlg 对话框

class StuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StuDlg)

public:
	StuDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StuDlg();
	bool m_bIsShow;
	User m_user;
// 对话框数据
	enum { IDD = IDD_STUDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg LRESULT  OnChangeState(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	afx_msg void OnLogout();
	afx_msg void OnQueryBook();
	afx_msg void OnBorrowBook();
	afx_msg void OnQueryMyBorrowRecord();
	afx_msg void OnReturnBook();
	afx_msg void OnReborrowBook();
};
