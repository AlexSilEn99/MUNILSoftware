/*
 * Copyright (c) 2008-2010 Geert-Jan Besjes 
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

#ifndef __editcommitteedialog__
#define __editcommitteedialog__

#include "gui.h"
#include "newcommitteedialog.h"

/** Implementing GUI_EditCommitteeDialog */
class EditCommitteeDialog : public NewCommitteeDialog
{
public:
	/** Constructor */
	EditCommitteeDialog( wxWindow* parent, std::map<wxString, Country>* countries, wxString filename );

	void ValidateNewCommitteeInput( wxCommandEvent& event );
private:
	wxString m_filename;
};

#endif // __editcommitteedialog__
