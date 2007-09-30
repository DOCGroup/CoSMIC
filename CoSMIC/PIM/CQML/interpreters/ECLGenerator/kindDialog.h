#pragma once

#include "Resource.h"

#include <list>

// KindDialog dialog

class KindDialog : public CDialog
{
	DECLARE_DYNAMIC(KindDialog)
	std::list <std::string> component_kinds_;
    std::list <std::string> node_kinds_;

public:
	KindDialog(CWnd* pParent = NULL);   // standard constructor
	std::list <std::string> get_component_kinds ();
    std::list <std::string> get_node_kinds ();
	virtual ~KindDialog();

	void OnOK ();

// Dialog Data
	enum { IDD = IDD_DIALOG2, 
		   EDIT1 = IDC_EDIT1, 
		   EDIT2 = IDC_EDIT2 };

protected:

	BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};
