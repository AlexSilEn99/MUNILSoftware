/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
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
