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
