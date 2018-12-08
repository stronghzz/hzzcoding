// IKCSYSTEM.h : main header file for the IKCSYSTEM application
//

#if !defined(AFX_IKCSYSTEM_H__35A2CF5C_C1A2_49C8_900C_ECF0DBB96F51__INCLUDED_)
#define AFX_IKCSYSTEM_H__35A2CF5C_C1A2_49C8_900C_ECF0DBB96F51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIKCSYSTEMApp:
// See IKCSYSTEM.cpp for the implementation of this class
//

class CIKCSYSTEMApp : public CWinApp
{
public:
	CIKCSYSTEMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIKCSYSTEMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIKCSYSTEMApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IKCSYSTEM_H__35A2CF5C_C1A2_49C8_900C_ECF0DBB96F51__INCLUDED_)
