// IKCSYSTEMDlg.h : header file
//
#include "SerialPort.h"
#if !defined(AFX_IKCSYSTEMDLG_H__320E4896_1245_4AEB_8C22_0BE50E868841__INCLUDED_)
#define AFX_IKCSYSTEMDLG_H__320E4896_1245_4AEB_8C22_0BE50E868841__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIKCSYSTEMDlg dialog

class CIKCSYSTEMDlg : public CDialog
{
// Construction
public:
	CSerialPort m_SerialPort; 
	BOOL m_bSerialPortOpened; 
    HICON m_hIconRed;    //ºìµÆÍ¼±ê¾ä±ú
	HICON m_hIconOff;    //ÎÞ±¨¾¯Í¼±ê¾ä±ú

	CIKCSYSTEMDlg(CWnd* pParent = NULL);	// standard constructor
  


// Dialog Data
	//{{AFX_DATA(CIKCSYSTEMDlg)
	enum { IDD = IDD_IKCSYSTEM_DIALOG };
	CStatic	m_ctrlIconOpenoff;
	CComboBox	m_ctrlComboComPort;
	CString	m_TEMP;
	CString	m_SHIDU;
	CString	m_YANWU;
	UINT	m_Hour;
	UINT	m_Minute;
	UINT	m_Second;
	UINT	m_Month;
	UINT	m_Year;
	UINT	m_Day;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIKCSYSTEMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIKCSYSTEMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    afx_msg LONG OnComm(WPARAM ch,LPARAM port);
	afx_msg void OnButtonOpen();
	afx_msg void OnButtonClose();
	afx_msg void OnButtonClosefs();
	afx_msg void OnButtonClosewindow();
	afx_msg void OnButtonOpenfs();
	afx_msg void OnButtonOpenwindow();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IKCSYSTEMDLG_H__320E4896_1245_4AEB_8C22_0BE50E868841__INCLUDED_)
