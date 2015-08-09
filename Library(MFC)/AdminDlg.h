#pragma once


// AdminDlg 对话框

class AdminDlg : public CDialog
{
	DECLARE_DYNAMIC(AdminDlg)

public:
	AdminDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AdminDlg();

// 对话框数据
	enum { IDD = IDD_ADMINDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCancel();
};
