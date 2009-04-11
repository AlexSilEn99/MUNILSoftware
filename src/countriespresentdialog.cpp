#include <wx/wx.h>
#include <wx/app.h>
#include <wx/string.h>
#include <wx/choice.h>

#include <map>
#include "main.h"
#include "country.h"
#include "countriespresentdialog.h"

CountriesPresentDialog::CountriesPresentDialog( wxWindow* parent, std::map<wxString, Country> *countries )
:
GUI_CountriesPresentDialog( parent ), m_numPresent(0)
{
	std::map<wxString, Country>::iterator it = countries->begin();
	for(int i=0; it != countries->end(); it++, i++){
		m_countriesPresentCheckList->Append(it->second.name());
		if(it->second.isPresent()){
			m_countriesPresentCheckList->Check(i);
			m_numPresent++;
		}
	}

	CheckNumPresent();
}

void CountriesPresentDialog::CheckNumPresent()
{
	m_numPresentText->SetLabel(wxString::Format(wxT("%i"), m_numPresent));

	if(m_numPresent == 0){
		m_selectNoneButton->Enable(false);
		m_selectAllButton->Enable();
	} else if( m_numPresent == m_countriesPresentCheckList->GetCount() ) {
		m_selectAllButton->Enable(false);
		m_selectNoneButton->Enable();
	} else {
		m_selectNoneButton->Enable();
		m_selectAllButton->Enable();
	}
}

void CountriesPresentDialog::OnSelectAll(wxCommandEvent& event)
{
	m_numPresent = m_countriesPresentCheckList->GetCount();
	for(int i = 0; i < m_countriesPresentCheckList->GetCount(); i++)
		 m_countriesPresentCheckList->Check(i);
	CheckNumPresent();
}
void CountriesPresentDialog::OnSelectNone(wxCommandEvent& event)
{
	m_numPresent = 0;
	for(int i = 0; i < m_countriesPresentCheckList->GetCount(); i++)
		 m_countriesPresentCheckList->Check(i, false);
	CheckNumPresent();
}

void CountriesPresentDialog::OnInvert(wxCommandEvent& event)
{
	m_numPresent =  m_countriesPresentCheckList->GetCount() - m_numPresent;
	for(int i = 0; i < m_countriesPresentCheckList->GetCount(); i++)
		 m_countriesPresentCheckList->Check(i, !m_countriesPresentCheckList->IsChecked(i) );
	CheckNumPresent();	
}

void CountriesPresentDialog::OnCountriesPresentToggle( wxCommandEvent& event )
{
	int i = event.GetInt();

	if(m_countriesPresentCheckList->IsChecked(i))
		m_numPresent++;
	else
		m_numPresent--;

	CheckNumPresent();
}
