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

#ifndef __newcommitteedialog__
#define __newcommitteedialog__

/**
@file
Subclass of GUI_NewCommitteeDialog, which is generated by wxFormBuilder.
*/

#include "gui.h"
#include "country.h"
#include <map>

/** Implementing GUI_NewCommitteeDialog */
class NewCommitteeDialog : public GUI_NewCommitteeDialog
{
public:
	/** Constructor */
	NewCommitteeDialog( wxWindow* parent, std::map<wxString, Country>* );

	void RemoveMember(int);
	void RemoveObserver(int);

	void OnMembersToggle( wxCommandEvent& );
	void OnObserversToggle( wxCommandEvent& );

	virtual void ValidateNewCommitteeInput ( wxCommandEvent& );

	void OnSelectAllMembers( wxCommandEvent& event );
	void OnSelectNoneMembers( wxCommandEvent& event );
	void OnInvertMembers( wxCommandEvent& event );

	void OnSelectAllObservers( wxCommandEvent& event );
	void OnSelectNoneObservers( wxCommandEvent& event );
	void OnInvertObservers( wxCommandEvent& event );

        void GetCountriesSelected( std::map< wxString, Country >* countries );

protected:
	void CheckNumbers();
	bool DoValidate();
	void WriteFile(wxString);

        std::map<wxString, Country > m_selectedCountries; //cannot be pointer because of observers
	std::map<int, Country* > m_countriesByID;

	int m_numMembers;
	int m_numObservers;
};

#endif // __newcommitteedialog__