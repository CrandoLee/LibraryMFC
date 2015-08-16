// AddBookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Library(MFC).h"
#include "AddBookDlg.h"
#include "afxdialogex.h"


// AddBookDlg 对话框

IMPLEMENT_DYNAMIC(AddBookDlg, CDialogEx)

AddBookDlg::AddBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddBookDlg::IDD, pParent)
{

}

AddBookDlg::~AddBookDlg()
{
}

void AddBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_cEditBookName);
	DDX_Control(pDX, IDC_EDIT2, m_cEditAuthor);
	DDX_Control(pDX, IDC_EDIT3, m_cEditISBN);
	DDX_Control(pDX, IDC_EDIT4, m_cEditPublish);
	DDX_Control(pDX, IDC_EDIT5, m_cEditNumber);
}


BEGIN_MESSAGE_MAP(AddBookDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &AddBookDlg::OnCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &AddBookDlg::OnAddBook)
END_MESSAGE_MAP()


// AddBookDlg 消息处理程序


void AddBookDlg::OnCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	CDialogEx::OnCancel();
	
}

//增加书籍
void AddBookDlg::OnAddBook()
{
	// TODO:  在此添加控件通知处理程序代码
	wchar_t szName[32] = { 0 };
	m_cEditBookName.GetWindowText(szName, 32);
	wchar_t szAuthor[32] = { 0 };
	m_cEditAuthor.GetWindowText(szAuthor, 32);
	wchar_t szISBN[32] = { 0 };
	m_cEditISBN.GetWindowText(szISBN, 32);
	wchar_t szPublish[32] = { 0 };
	m_cEditPublish.GetWindowText(szPublish, 32);
	wchar_t szNumber[4] = { 0 };
	m_cEditNumber.GetWindowText(szNumber, 4);

	wstring wstrName = szName;
	wstring wstrAuthor = szAuthor;
	wstring wstrISBN = szISBN;
	wstring wstrPublish = szPublish;
	wstring wstrNumber = szNumber;

	string strName;
	string strAuthor;
	string strISBN;
	string strPubish;
	string strNum;
	strNum = m_stringConvert.ws2s(wstrNumber);

	char szTime[64] = { 0 };
	time_t lt;
	lt = time(NULL);
	TimeUtil timeUtil;
	timeUtil.TimeToString(lt, szTime);


	Book book;
	book.SetBookName(m_stringConvert.ws2s(wstrName));
	book.SetAuthor(m_stringConvert.ws2s(wstrAuthor));
	book.SetISBN(m_stringConvert.ws2s(wstrISBN));
	book.SetPub(m_stringConvert.ws2s(wstrPublish));
	book.SetInDate(szTime);
	book.SetTotalNum(atoi(strNum.c_str()));
	book.SetLeftNum(atoi(strNum.c_str()));

	DBUtil dbUtil;
	dbUtil.OpenDB();
	dbUtil.AddBook(book);

	MessageBox(_T("添加成功"), _T("消息"), MB_ICONINFORMATION | MB_OK);
	::SendMessage(m_parentHwnd, WM_CHANEG_STATE, NULL, NULL);
	OnOK();
	DestroyWindow();
}
