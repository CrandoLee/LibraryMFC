
// LibraryDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "User.h"
#include "Manager.h"
#include "DBUtil.h"
#include "StringConvert.h"
#include "AdminDlg.h"
// CLibraryDlg 对话框
class CLibraryDlg : public CDialogEx
{
// 构造
public:
	CLibraryDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LIBRARYMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBtnCancel();
	afx_msg void OnBtnSubmit();
	CEdit m_cEditName;
	CEdit m_cEditPass;
};
