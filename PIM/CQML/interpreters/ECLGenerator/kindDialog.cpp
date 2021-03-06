// KindDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ECLGenerator.h"
#include "KindDialog.h"

#include <sstream>

// KindDialog dialog

IMPLEMENT_DYNAMIC(KindDialog, CDialog)

KindDialog::KindDialog(CWnd* pParent /*=NULL*/)
	:  CDialog(KindDialog::IDD, pParent)
{
}

KindDialog::~KindDialog()
{
}

BOOL KindDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	CEdit * input;

	input = reinterpret_cast<CEdit *>(GetDlgItem(EDIT1));
	input->SetFocus ();

	input = reinterpret_cast<CEdit *>(GetDlgItem(EDIT2));
	input->SetWindowTextA ("Host");

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

std::list <std::string> KindDialog::get_component_kinds () const
{
	return component_kinds_;
}

std::list <std::string> KindDialog::get_node_kinds () const
{
	return node_kinds_;
}

std::string KindDialog::get_planname () const
{
	return this->placement_plan_name_;
}

void KindDialog::OnOK ()
{
	char buffer [1024];
	
	// TODO: Add extra initialization here
	CEdit *input;

	input = reinterpret_cast<CEdit *>(GetDlgItem(EDIT1));
	input->GetWindowTextA (buffer, 1024);
	std::istringstream comp_str_stream(buffer);
	std::copy (std::istream_iterator <std::string> (comp_str_stream),
		std::istream_iterator <std::string> (),
		std::back_inserter (this->component_kinds_));

	input = reinterpret_cast<CEdit *>(GetDlgItem(EDIT2));
	input->GetWindowTextA (buffer, 1024);
	std::istringstream node_str_stream(buffer);
	std::copy (std::istream_iterator <std::string> (node_str_stream),
		std::istream_iterator <std::string> (),
		std::back_inserter (this->node_kinds_));

	input = reinterpret_cast<CEdit *>(GetDlgItem(EDIT3));
	input->GetWindowTextA (buffer, 1024);
	this->placement_plan_name_ = buffer;

	CDialog::OnOK ();
}

BEGIN_MESSAGE_MAP(KindDialog, CDialog)
	ON_COMMAND (IDOK, OnOK)
END_MESSAGE_MAP()


// KindDialog message handlers
