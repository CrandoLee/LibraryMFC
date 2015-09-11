#pragma once
#include "afxcmn.h"
#include "DBUtil.h"
#include "StringConvert.h"
// BookListDlg 对话框

class BookListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BookListDlg)

public:
	BookListDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BookListDlg();
	HWND m_parentHwnd;
	DBUtil m_dbUtil;
	StringConvert m_stringConvert;
// 对话框数据
	enum { IDD = IDD_BOOKLISTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_cListCtrl;
	virtual void OnOK();
};
