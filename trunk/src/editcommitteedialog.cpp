/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#include "committee.h"
#include "country.h"
#include "editcommitteedialog.h"

EditCommitteeDialog::EditCommitteeDialog( wxWindow* parent, std::map<wxString, Country>* countries, wxString filename)
: NewCommitteeDialog(parent, countries), m_filename(filename)
{
	Committee *c = new Committee(filename.mb_str());

	this->SetTitle(wxT("Edit committee"));
	m_committeeNameTextCtrl->SetValue(c->name());
	m_topicATextCtrl->SetValue(c->topicA());
	m_topicBTextCtrl->SetValue(c->topicB());
	m_GSLspin->SetValue(c->GSLtime());

	m_numMembers = c->members()->size();
	m_numObservers = c->observers()->size();

	std::map<wxString, Country>::iterator it; int i;
	for(it = c->countries()->begin(); it != c->countries()->end(); it++){
		
		if( (i = m_membersCheckList->FindString(it->second.name()) ) == wxNOT_FOUND)
			continue;

		if( it->second.isObserver() ){
			m_observersCheckList->Check(i);
			m_selectedCountries[it->second.code()] = Country(it->second.name(), it->second.code(), true);
		} else {
			m_membersCheckList->Check(i);
			m_selectedCountries[it->second.code()] = Country(it->second.name(), it->second.code(), false);
		}
	}

	CheckNumbers();
	delete c;

}

void EditCommitteeDialog::ValidateNewCommitteeInput( wxCommandEvent& event )
{
	if(!DoValidate())
		return;

	WriteFile(m_filename);

	if(IsModal())
		EndModal(wxID_OK);
	else
		Close(wxID_OK); 

	// TODO: Implement ValidateNewCommitteeInput
}
