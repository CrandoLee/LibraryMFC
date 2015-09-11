#pragma once
#include "afxcmn.h"
#include "DBUtil.h"
#include "User.h"
#include "StringConvert.h"

// UserListDlg 对话框

class UserListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UserListDlg)

public:
	UserListDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UserListDlg();

// 对话框数据
	enum { IDD = IDD_USERLISTDLG };
	HWND m_parentHwnd;
	StringConvert m_stringConvert;
	DBUtil m_dbUtil;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	CListCtrl m_cListUser;
	virtual void OnOK();
};
