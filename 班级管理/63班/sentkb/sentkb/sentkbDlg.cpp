
// sentkbDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "sentkb.h"
#include "sentkbDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsentkbDlg �Ի���



CsentkbDlg::CsentkbDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CsentkbDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsentkbDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CsentkbDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CsentkbDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CsentkbDlg ��Ϣ�������

BOOL CsentkbDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CsentkbDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CsentkbDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CsentkbDlg::OnBnClickedButton1()
{
	//HWND hWnd = ::FindWindow(L"Qt5QWindowIcon", L"Ӣ�۴�˵����֮�켣 - MuMuģ����");
	HWND hWnd = ::FindWindow(L"Notepad", nullptr);
	if (hWnd)
	{
		HWND hEdit = ::FindWindowEx(hWnd, nullptr, L"Qt5QWindowIcon", nullptr);
		//keybd_event(,);
#if 0
		::PostMessage(hWnd, WM_KEYDOWN, 'B', 0);
		Sleep(100);
		::PostMessage(hWnd, WM_KEYUP, 'B', 0);
		Sleep(200);
		::PostMessage(hWnd, WM_KEYDOWN, 'A', 0);
		Sleep(100);
		::PostMessage(hWnd, WM_KEYUP, 'A', 0);
		Sleep(200);
		::PostMessage(hEdit, WM_KEYDOWN, 'B', 0);
		Sleep(100);
		::PostMessage(hEdit, WM_KEYUP, 'B', 0);
		Sleep(200);
		::PostMessage(hEdit, WM_KEYDOWN, 'A', 0);
		Sleep(100);
		::PostMessage(hEdit, WM_KEYUP, 'A', 0);
		Sleep(200);
#else
		int res = ::SendMessage(hWnd, WM_KEYDOWN, 'B', 0);
		Sleep(100);
		res = ::SendMessage(hWnd, WM_KEYUP, 'B', 0);
		Sleep(200);
		res = ::SendMessage(hWnd, WM_KEYDOWN, 'A', 0);
		Sleep(100);
		res = ::SendMessage(hWnd, WM_KEYUP, 'A', 0);
		Sleep(200);
		res = ::SendMessage(hEdit, WM_KEYDOWN, 'B', 0);
		Sleep(100);
		res = ::SendMessage(hEdit, WM_KEYUP, 'B', 0);
		Sleep(200);
		res = ::SendMessage(hEdit, WM_KEYDOWN, 'A', 0);
		Sleep(100);
		res = ::SendMessage(hEdit, WM_KEYUP, 'A', 0);
		Sleep(200);
#endif
		/*HWND hEdits = ::FindWindowEx(hWnd, nullptr, L"Qt5QWindowIcon", nullptr);
		HWND hEdit = ::FindWindowEx(hEdits, nullptr, L"canvasWin", nullptr);*/
	}
	else
	{
		AfxMessageBox(L"��򿪼��±��ļ���");
		return;
	}
}
