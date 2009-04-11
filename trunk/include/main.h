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

#ifndef MAIN_H
#define MAIN_H

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#if defined(XERCES_NEW_IOSTREAMS)
 #include <iostream>
#else
 #include <iostream.h>
#endif

XERCES_CPP_NAMESPACE_USE

#include <wx/wx.h>
#include <wx/splash.h>
#include <wx/defs.h>
#include <wx/string.h>
#include <wx/filename.h>

// #include <libxml++/libxml++.h>
#include <map>
#include "wxmunframe.h"
#include "country.h"
#include "session.h"

extern wxMUNFrame *parentFrame;

class MyApp : public wxApp {
public:
	MyApp() : m_committeeLoaded(false) {}
        bool OnInit();
        int OnExit();
        int OnRun();

	void LoadCommitteeFromFile(wxString filename, bool overwriteState = true);
	void readState(wxString filename= wxT(""));

	bool isCommitteeLoaded();
	void committeeLoaded();

	void setSession(Session);
	Session *session();

	Country *findCountryPtr(wxString);
	Country findCountry(wxString);
	wxString findCountryCode(wxString);
	wxString findCountryFlagByName(wxString);
	
	std::map<wxString, Country> *availableCountries();
	std::map<wxString, Country*> *committeeCountries();

private:
	bool m_committeeLoaded;
	Session m_session;

        std::map<wxString, Country> m_allAvailableCountries;
        std::map<wxString, Country*> m_committeeCountries;

//	const char *extractTextFromXMLTag(const xmlpp::Node*);
//	void ParseCountry(const xmlpp::Node*);
        bool ReadCountries(const char *);

};

DECLARE_APP( MyApp );

#endif /* MAIN_H */

