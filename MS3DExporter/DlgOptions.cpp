#include "stdafx.h"
#include "resource.h"
#include "DlgOptions.h"
#include "About.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



//======================================================================
// constructor
//======================================================================
cDlgOptions::cDlgOptions(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_OPTIONS, pParent)
{
	//{{AFX_DATA_INIT(cDlgOptions)
	//}}AFX_DATA_INIT
}

//======================================================================
// DoDataExchange
//======================================================================
void cDlgOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cDlgOptions)
	//}}AFX_DATA_MAP
}



//======================================================================
// Message Map
//======================================================================
BEGIN_MESSAGE_MAP(cDlgOptions, CDialog)
	//{{AFX_MSG_MAP(cDlgOptions)
    ON_BN_CLICKED(IDC_BTBROWSE,     OnBrowse)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



//======================================================================
// OnInitDialog
//======================================================================
BOOL cDlgOptions::OnInitDialog() 
{
	CDialog::OnInitDialog();
    CDialog::CenterWindow();

    m_nFlags = eMeshes | eMaterials;
    m_sPathName.Empty();

    CheckDlgButton (IDC_BTMESHES, TRUE);
    CheckDlgButton (IDC_BTMATERIALS, TRUE);
	
	return TRUE;
}

//======================================================================
// OnClose
//======================================================================
void cDlgOptions::OnClose() 
{
	OnCancel ();
}

//======================================================================
// OnCancel
//======================================================================
void cDlgOptions::OnCancel() 
{
	CDialog::OnCancel();
}

//======================================================================
// OnOK
//======================================================================
void cDlgOptions::OnOK() 
{
    GetDlgItemText (IDC_FILENAME, m_sPathName);

    m_nFlags = 0;
    if (IsDlgButtonChecked (IDC_BTMESHES))
        m_nFlags |= eMeshes;
    if (IsDlgButtonChecked (IDC_BTMATERIALS))
        m_nFlags |= eMaterials;

	CDialog::OnOK();
}

//======================================================================
// OnBrowse
//======================================================================
void cDlgOptions::OnBrowse() 
{
    //
    // choose filename
    //
    CFileDialog fileDlg (FALSE, "mdl", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST,
                         "Allegianc MDL Files (*.mdl)|*.mdl|All Files (*.*)|*.*||");
    if (!fileDlg.DoModal ())
        m_sPathName.Empty ();
    else
        m_sPathName = fileDlg.GetPathName ();

    SetDlgItemText (IDC_FILENAME, m_sPathName);
}

//======================================================================
// GetPathName
//======================================================================
CString cDlgOptions::GetPathName() 
{
    return m_sPathName;
}

//======================================================================
// GetPathName
//======================================================================
int cDlgOptions::GetOptionFlags() 
{
    return m_nFlags;
}
