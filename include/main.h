/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
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

