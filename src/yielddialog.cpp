#include "yielddialog.h"

YieldDialog::YieldDialog( wxWindow* parent )
:
GUI_YieldDialog( parent )
{

}

void YieldDialog::OnHighlightDelegate( wxCommandEvent& event )
{
	m_yieldOKButton->Enable(true);
}

void YieldDialog::OnSelectDelegate( wxCommandEvent& event )
{
	if(IsModal())
		EndModal(wxID_OK);
	else
		Close(wxID_OK);
}
