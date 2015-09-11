#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "DBUtil.h"
#include "StringConvert.h"
#include <vector>

using namespace std;
// QueryBookDlg 对话框

class QueryBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QueryBookDlg)

public:
	QueryBookDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~QueryBookDlg();

// 对话框数据
	enum { IDD = IDD_QUERYDLG };
public :
	HWND m_parentHwnd;
	DBUtil m_dbUtil;
	StringConvert m_stringConvert;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnQuery();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CComboBox m_cComBox;
	virtual BOOL OnInitDialog();
	CEdit m_cEditName;
	CListCtrl m_cListCtrl;
	virtual void OnCancel();
	virtual void OnOK();
};
