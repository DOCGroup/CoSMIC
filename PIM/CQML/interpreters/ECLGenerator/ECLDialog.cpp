// ECLDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ECLGenerator.h"
#include "ECLDialog.h"


// ECLDialog dialog

IMPLEMENT_DYNAMIC(ECLDialog, CDialog)

ECLDialog::ECLDialog(std::string const & ecl,
					 CWnd* pParent /*=NULL*/)
	:  ecl_ (ecl),
       CDialog(ECLDialog::IDD, pParent)
{
}

ECLDialog::~ECLDialog()
{
}

BOOL ECLDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CEdit *Display;

	Display = reinterpret_cast<CEdit *>(GetDlgItem(IDC_EDIT1));
	Display->SetWindowText(ecl_.c_str());

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BEGIN_MESSAGE_MAP(ECLDialog, CDialog)
END_MESSAGE_MAP()


// ECLDialog message handlers
