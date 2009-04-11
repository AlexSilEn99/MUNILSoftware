/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#ifndef COUNTRY_H
#define COUNTRY_H

#include <wx/defs.h>
#include <wx/string.h>

class Country {
public:
	Country(){};
 
	Country(const Country&);

	~Country() {};

	Country(wxString, wxString, bool, bool present=false);

	wxString name();
	wxString code();
	wxString flag();
	bool isObserver();
	bool isPresent();

	void makePresent();
	void makeNotPresent();
	void makeObserver();
	void makeMember();

private:
	wxString m_name;
	wxString m_code;
	bool m_observer;
	bool m_present; 
};

#endif
