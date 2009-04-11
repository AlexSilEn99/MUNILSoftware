/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * This file is part of wxMUN.
 *
 * wxMUN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * wxMUN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with wxMUN.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
#	include <wx/wx.h>
#	include <wx/file.h>
#endif

#include <wx/file.h>
#include <iostream>
#include <fstream>
#include "main.h"
#include "defs.h"
#include "country.h"
#include "gui.h"
#include "newcommitteedialog.h"

NewCommitteeDialog::NewCommitteeDialog( wxWindow* parent,  std::map<wxString, Country> *countries)
: 
GUI_NewCommitteeDialog( parent )
{
	std::map<wxString, Country>::iterator it;
	int i=0; int j=0;
	for(it = countries->begin(); it != countries->end(); it++, i++, j++){
		const wxString& name = it->second.name(); 

		m_observersCheckList->AppendString(name);
		m_membersCheckList->AppendString(name);
		m_countriesByID[i] = &(it->second);

	}

	m_numMembers = 0;
	m_numObservers = 0;
}

void NewCommitteeDialog::RemoveMember(int id)
{
	if(m_membersCheckList->IsChecked(id))
		m_numMembers--;

	m_membersCheckList->Check(id,false);
}

void NewCommitteeDialog::RemoveObserver(int id)
{
	if(m_observersCheckList->IsChecked(id))
		m_numObservers--;
	m_observersCheckList->Check(id,false);
}

void NewCommitteeDialog::CheckNumbers(){
	m_selectAllObservers->Enable(true);
	m_selectNoneMembers->Enable(true);

	m_selectNoneObservers->Enable(true);
	m_selectAllMembers->Enable(true);

	if(m_numObservers == m_observersCheckList->GetCount()){
		m_selectAllObservers->Enable(false);
		m_selectNoneMembers->Enable(false);
	} else if (m_numMembers == m_membersCheckList->GetCount()) {
		m_selectNoneObservers->Enable(false);
		m_selectAllMembers->Enable(false);
	} else {
		if (m_numMembers == 0)
			m_selectNoneMembers->Enable(false);
		if (m_numObservers == 0)
			m_selectNoneObservers->Enable(false);
	}
}

void NewCommitteeDialog::OnMembersToggle( wxCommandEvent& event )
{
	int id = event.GetSelection() ;

	//observers & members are mutually exclusive
	if(m_membersCheckList->IsChecked(id)){
		RemoveObserver(id);

		m_numMembers++;
		std::map<wxString, Country >::iterator it = m_selectedCountries.find(m_countriesByID[id]->code());
		if(it != m_selectedCountries.end())
			m_selectedCountries.erase(it);

		m_selectedCountries[m_countriesByID[id]->code()] = Country(m_countriesByID[id]->name(), m_countriesByID[id]->code(), false);
	} else {
		m_numMembers--;
		m_selectedCountries.erase(m_countriesByID[id]->code());
	}
	CheckNumbers();
}

void NewCommitteeDialog::OnSelectAllMembers( wxCommandEvent& event )
{
	int n = m_membersCheckList->GetCount();

	m_selectedCountries.clear();

	m_numMembers = n;
	m_numObservers = 0;

	for(int i = 0; i < n; i++){
		m_membersCheckList->Check(i);
		m_observersCheckList->Check(i, false);
		m_selectedCountries[m_countriesByID[i]->code()] = Country(m_countriesByID[i]->name(), m_countriesByID[i]->code(), false);
	}
	CheckNumbers();
}

void NewCommitteeDialog::OnSelectNoneMembers( wxCommandEvent& event )
{
	int n = m_membersCheckList->GetCount();

	for(int i = 0; i < n; i++){
		if(!m_membersCheckList->IsChecked(i))
			continue;

		m_selectedCountries.erase(m_countriesByID[i]->code());
		m_numMembers--;
		m_membersCheckList->Check(i, false);		
	}
	CheckNumbers();
}

void NewCommitteeDialog::OnInvertMembers( wxCommandEvent& event )
{
	int n = m_membersCheckList->GetCount();

	for(int i = 0; i < n; i++){
		if(!m_membersCheckList->IsChecked(i)){
			m_numMembers++;
			RemoveObserver(i); 
			m_membersCheckList->Check(i);
			m_selectedCountries[m_countriesByID[i]->code()] = Country(m_countriesByID[i]->name(), m_countriesByID[i]->code(), false);
		} else {
			m_selectedCountries.erase(m_countriesByID[i]->code());
			m_numMembers--;
			m_membersCheckList->Check(i, false);
		}
	}
	CheckNumbers();
}

void NewCommitteeDialog::OnObserversToggle( wxCommandEvent& event )
{
	int id = event.GetSelection() ;

	//observers & members are mutually exclusive
	if(m_observersCheckList->IsChecked(id)){
		RemoveMember(id);
		
		m_numObservers++;
		m_selectedCountries[m_countriesByID[id]->code()] = Country(m_countriesByID[id]->name(), m_countriesByID[id]->code(), true);
	} else {
		m_numObservers--;
		m_selectedCountries.erase(m_countriesByID[id]->code());
	}
	CheckNumbers();
}

void NewCommitteeDialog::OnSelectAllObservers( wxCommandEvent& event )
{
	int n = m_membersCheckList->GetCount();

	m_selectedCountries.clear();

	m_numMembers = 0;
	m_numObservers = n;

	for(int i = 0; i < n; i++){
		m_observersCheckList->Check(i);
		m_membersCheckList->Check(i, false);
		m_selectedCountries[m_countriesByID[i]->code()] = Country(m_countriesByID[i]->name(), m_countriesByID[i]->code(), true);
	}
	CheckNumbers();
}

void NewCommitteeDialog::OnSelectNoneObservers( wxCommandEvent& event )
{
	int n = m_observersCheckList->GetCount();

	for(int i = 0; i < n; i++){
		if(!m_observersCheckList->IsChecked(i))
			continue;

		m_selectedCountries.erase(m_countriesByID[i]->code());
		m_numObservers--;
		m_observersCheckList->Check(i, false);		
	}
	CheckNumbers();
}

void NewCommitteeDialog::OnInvertObservers( wxCommandEvent& event )
{
	int n = m_observersCheckList->GetCount();

	for(int i = 0; i < n; i++){
		if(!m_observersCheckList->IsChecked(i)){
			m_numObservers++;
			RemoveMember(i); 
			m_observersCheckList->Check(i);
			m_selectedCountries[m_countriesByID[i]->code()] = Country(m_countriesByID[i]->name(), m_countriesByID[i]->code(), true);
		} else {
			m_selectedCountries.erase(m_countriesByID[i]->code());
			m_numObservers--;
			m_observersCheckList->Check(i, false);
		}
	}
	CheckNumbers();
}

bool NewCommitteeDialog::DoValidate(){
	bool retval = true;
	if( m_numMembers == 0 || m_topicATextCtrl->IsEmpty() || m_committeeNameTextCtrl->IsEmpty() || m_GSLspin->GetValue() == 0 ) {
		retval = false;
		wxString message;
		if(m_numMembers == 0)
			message << wxT("Your committee has 0 members.\n");
	
		if(m_committeeNameTextCtrl->IsEmpty()){
			message << wxT("Your committee does not have a name.\n");
		}

		if(m_topicATextCtrl->IsEmpty()){
			message << wxT("Your committee does not have a Topic A.\n");
		}
	
		if(m_GSLspin->GetValue() == 0){
			message << wxT("The time for speeches is 0 seconds.\n");
		}
		wxMessageBox(message,
				wxT("Cannot create committee"), 
				wxICON_WARNING | wxOK, this);
	}
	return retval;
}

void NewCommitteeDialog::WriteFile(wxString filename){
	wxFile XMLoutput;
	XMLoutput.Create(filename, true);
		
	wxString s = _("<?xml version='1.0' encoding='UTF-8'?>");
	
	XMLoutput.Write(s+wxT("\n"));
	XMLoutput.Write(wxT("\n<committee "));
	XMLoutput.Write(wxT("name=\"")+m_committeeNameTextCtrl->GetValue()+wxT("\" "));
	//write GSL time
	s = wxString(wxT("")); s << m_GSLspin->GetValue();
	XMLoutput.Write(wxT("GSLtime=\"")+s+wxT("\" >\n"));

	// write countries
	XMLoutput.Write(wxT("\t<countries>\n"));

	//loop
	std::map<wxString, Country >::iterator it = m_selectedCountries.begin();
	for(it; it != m_selectedCountries.end(); it++){
		XMLoutput.Write(wxT("\t\t<country "));
		XMLoutput.Write(wxT("name=\"")+it->second.name()+wxT("\" "));
		XMLoutput.Write(wxT("code=\"")+it->second.code()+wxT("\" "));

		if(it->second.isObserver())
			XMLoutput.Write(wxT("observer=\"true\" "));

		XMLoutput.Write(wxT("/>\n"));
	}

	XMLoutput.Write(wxT("\t</countries>\n"));

	XMLoutput.Write(wxT("\t<topics>\n"));
	XMLoutput.Write(wxT("\t\t<topic name=\"")+m_topicATextCtrl->GetValue()+wxT("\" />\n"));

	if(!m_topicBTextCtrl->IsEmpty()){ //possible topic B
		XMLoutput.Write(wxT("\t\t<topic name=\"")+m_topicBTextCtrl->GetValue()+wxT("\" />\n"));
	}
	XMLoutput.Write(wxT("\t</topics>\n"));			
	XMLoutput.Write(wxT("</committee>\n"));
	parentFrame->SetCurrentDocPath(filename);
}

void NewCommitteeDialog::ValidateNewCommitteeInput ( wxCommandEvent& ){
	wxString filename;

	if( !DoValidate() )
		return;
		
	wxFileDialog *SaveDialog = new wxFileDialog(
		this, _("Save Committee As"), wxEmptyString, wxEmptyString,
		_("XML files (*.xml)|*.xml|"),
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
 
	if (SaveDialog->ShowModal() != wxID_OK)
		return;
		
	WriteFile(SaveDialog->GetPath());

	if(IsModal())
		EndModal(wxID_OK);
	else
		Close(wxID_OK); 
}
