#pragma once


// AddBookDlg 对话框

class AddBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddBookDlg)

public:
	AddBookDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddBookDlg();
	HWND m_parentHwnd;
// 对话框数据
	enum { IDD = IDD_ADDBOOKDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCancel();
};
