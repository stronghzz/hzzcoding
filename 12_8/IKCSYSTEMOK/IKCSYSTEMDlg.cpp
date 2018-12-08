// IKCSYSTEMDlg.cpp : implementation file
//

#include <string.h>
#include "stdafx.h"
#include "IKCSYSTEM.h"
#include "IKCSYSTEMDlg.h"
CFont cfont; 
char rxdata[11];
char databuf[6];
int timer=0 ,i=0;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

    
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIKCSYSTEMDlg dialog

CIKCSYSTEMDlg::CIKCSYSTEMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIKCSYSTEMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIKCSYSTEMDlg)
	m_TEMP = _T("");
	m_SHIDU = _T("");
	m_YANWU = _T("");
	m_Hour = 0;
	m_Minute = 0;
	m_Second = 0;
	m_Month = 0;
	m_Year = 0;
	m_Day = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIKCSYSTEMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIKCSYSTEMDlg)
	DDX_Control(pDX, IDC_STATIC_OPENOFF, m_ctrlIconOpenoff);
	DDX_Control(pDX, IDC_COMBO_COMPORT, m_ctrlComboComPort);
	DDX_Text(pDX, IDC_EDIT_TEMP, m_TEMP);
	DDX_Text(pDX, IDC_EDIT_SHIDU, m_SHIDU);
	DDX_Text(pDX, IDC_EDIT_YANWU, m_YANWU);
	DDX_Text(pDX, IDC_HOUR, m_Hour);
	DDX_Text(pDX, IDC_MINUTE, m_Minute);
	DDX_Text(pDX, IDC_SENCOND, m_Second);
	DDX_Text(pDX, IDC_MONTH, m_Month);
	DDX_Text(pDX, IDC_YEAR, m_Year);
	DDX_Text(pDX, IDC_DAY, m_Day);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIKCSYSTEMDlg, CDialog)
	//{{AFX_MSG_MAP(CIKCSYSTEMDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_COMM_RXCHAR,OnComm)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_CLOSEFS, OnButtonClosefs)
	ON_BN_CLICKED(IDC_BUTTON_CLOSEWINDOW, OnButtonClosewindow)
	ON_BN_CLICKED(IDC_BUTTON_OPENFS, OnButtonOpenfs)
	ON_BN_CLICKED(IDC_BUTTON_OPENWINDOW, OnButtonOpenwindow)
    ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIKCSYSTEMDlg message handlers

BOOL CIKCSYSTEMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

     cfont.CreateFont(26,                                        //字体大小
                      0,0,0,FW_NORMAL,   
                      FALSE,FALSE,   
                      0,   
                      ANSI_CHARSET,                  // nCharSet
                      OUT_DEFAULT_PRECIS,     // nOutPrecision
                      CLIP_DEFAULT_PRECIS,     // nClipPrecision
                      DEFAULT_QUALITY,             // nQuality
                      DEFAULT_PITCH | FF_SWISS, "Arial");            // 字体
                      CWnd*  pWnd = GetDlgItem(IDC_STATIC1);    // 静态文本的编号
                      pWnd->SetFont(&cfont);


	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
    
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    m_hIconRed  = AfxGetApp()->LoadIcon(IDI_ICON_RED);//////////////////////////?加载图标
	m_hIconOff	= AfxGetApp()->LoadIcon(IDI_ICON_OFF);
	m_ctrlComboComPort.SetCurSel(0);
	CString strl;
   // CTime tm;
   // tm = CTime::GetCurrentTime();       /////////////////////////////////////////
   // strl=tm.Format("%Y年%m月%d日 %X");    //将当前时间格式化！
  //  this->GetDlgItem(IDC_Time)->SetWindowText(strl);
    SetTimer(WM_TIMER,100,NULL);
	CTime Time=CTime::GetCurrentTime();
    this->m_Year=Time.GetYear();
    this->m_Month=Time.GetMonth();
    this->m_Day=Time.GetDay();
	this->m_Hour=Time.GetHour();
	this->m_Minute=Time.GetMinute();
	this->m_Second=Time.GetSecond();
	UpdateData(false);
    m_ctrlIconOpenoff.SetIcon(m_hIconOff);

	return TRUE;  // return TRUE  unless you set the focus to a control


}

void CIKCSYSTEMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIKCSYSTEMDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIKCSYSTEMDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
LONG CIKCSYSTEMDlg::OnComm(WPARAM ch,LPARAM port)
{
    rxdata[i]=(char)ch;
	 i++;
	 timer++;
 	if(timer==12)
    {
      timer=0;  
      i=0;
       if((rxdata[0]=='E')&&(rxdata[1]=='B')&&(rxdata[2]=='3')&&(rxdata[10]=='C')&&(rxdata[11]=='F'))
        {
           for(i=3; i<10; i++)
		   {
            databuf[i-3]=rxdata[i];
		   }
		     m_YANWU=databuf;
             if(strncmp(m_YANWU, "NO SMOG", 7) == 0) {
				 m_ctrlIconOpenoff.SetIcon(m_hIconOff);}
             if(strncmp(m_YANWU, "SMOKing", 7) == 0){ 
				 m_ctrlIconOpenoff.SetIcon(m_hIconRed);}

            UpdateData(FALSE);
		 }
	 
///////////////////////////////////////////////////////////////////////////////////////////////
     if((rxdata[0]=='E')&&(rxdata[1]=='B')&&(rxdata[2]=='1')&&(rxdata[10]=='C')&&(rxdata[11]=='F'))
        {

           for(i=3; i<10; i++)
		   {
             databuf[i-3]=rxdata[i];
		   }
		     m_TEMP=databuf;
		   
           UpdateData(FALSE);
		 }
     
/////////////////////////////////////////////////////////////////////////////////////////////////
  
          if((rxdata[0]=='E')&&(rxdata[1]=='B')&&(rxdata[2]=='2')&&(rxdata[10]=='C')&&(rxdata[11]=='F'))
        {

           for(i=3; i<10; i++)
		   {
              databuf[i-3]=rxdata[i];
		   }
             m_SHIDU=databuf;

             UpdateData(FALSE);

		 }

	}
   
	return 0;
}

void CIKCSYSTEMDlg::OnButtonOpen() 
{
	// TODO: Add your control notification handler code here
	int nPort=m_ctrlComboComPort.GetCurSel()+1; 
	if(m_SerialPort.InitPort(this, nPort, 38400,'N',8,1,EV_RXFLAG | EV_RXCHAR,512))
	{
		m_SerialPort.StartMonitoring();
		m_bSerialPortOpened=TRUE;
	}
	else
	{
		AfxMessageBox("没有发现此串口或被占用!");
		m_bSerialPortOpened=FALSE;
	}
	GetDlgItem(IDC_BUTTON_OPEN)->EnableWindow(!m_bSerialPortOpened);
	GetDlgItem(IDC_BUTTON_CLOSE)->EnableWindow(m_bSerialPortOpened);

}

void CIKCSYSTEMDlg::OnButtonClose() 
{
	// TODO: Add your control notification handler code here
	
    m_SerialPort.ClosePort();//关闭串口
    m_bSerialPortOpened=FALSE;
	GetDlgItem(IDC_BUTTON_OPEN)->EnableWindow(!m_bSerialPortOpened);
	GetDlgItem(IDC_BUTTON_CLOSE)->EnableWindow(m_bSerialPortOpened);

}

//void CIKCSYSTEMDlg::OnButtonSend() 
//{
	// TODO: Add your control notification handler code here
//	if(!m_bSerialPortOpened) return; //检查串口是否打开
//	UpdateData(TRUE); //读入编辑框中的数据
//	m_SerialPort.WriteToPort((LPCTSTR)m_strEditSendMsg);//发送数据

//}

void CIKCSYSTEMDlg::OnButtonClosefs() 
{
	// TODO: Add your control notification handler code here
	if(!m_bSerialPortOpened) return; //检查串口是否打开
    char  ctlbutton1[]="off1";
    m_SerialPort.WriteToPort((LPCTSTR)ctlbutton1);//发送数据
}

void CIKCSYSTEMDlg::OnButtonClosewindow() 
{
	// TODO: Add your control notification handler code here
	if(!m_bSerialPortOpened) return; //检查串口是否打开
    char  ctlbutton2[]="off0";
    m_SerialPort.WriteToPort((LPCTSTR)ctlbutton2);//发送数据
}

void CIKCSYSTEMDlg::OnButtonOpenfs() 
{
	// TODO: Add your control notification handler code here
	if(!m_bSerialPortOpened) return; //检查串口是否打开
    char  ctlbutton3[]="on1";
    m_SerialPort.WriteToPort((LPCTSTR)ctlbutton3);//发送数据
}

void CIKCSYSTEMDlg::OnButtonOpenwindow() 
{
	// TODO: Add your control notification handler code here
	if(!m_bSerialPortOpened) return; //检查串口是否打开
    char  ctlbutton4[]="on0";
    m_SerialPort.WriteToPort((LPCTSTR)ctlbutton4);//发送数据
}

void CIKCSYSTEMDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime Time=CTime::GetCurrentTime();
    m_Year=Time.GetYear();
    m_Month=Time.GetMonth();
    m_Day=Time.GetDay();
	m_Hour=Time.GetHour();
	m_Minute=Time.GetMinute();
	m_Second=Time.GetSecond();
	UpdateData(false);	
	CDialog::OnTimer(nIDEvent);
}
