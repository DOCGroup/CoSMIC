#pragma once

#include "Resource.h"

// ECLDialog dialog

class ECLDialog : public CDialog
{
	DECLARE_DYNAMIC(ECLDialog)
	std::string const & ecl_;

public:
	ECLDialog(std::string const & ecl,CWnd* pParent = NULL);   // standard constructor
	virtual ~ECLDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:

	BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};
