/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#ifndef COMMITTEE_H
#define COMMITTEE_H

#include <iostream>
#include <map>
#include <wx/defs.h>
#include <wx/string.h>
#include <wx/arrstr.h>
#include "country.h"

class Committee {
public:
	Committee() {};
	Committee(const char *);

	wxString name();
	wxString topicA();
	wxString topicB();
	int GSLtime();
	int votingTime();

	std::map<wxString, Country>* countries();
	std::map<wxString, Country*>* members();
	std::map<wxString, Country*>* observers();
	
	void setTopicA(wxString);
	void setTopicB(wxString);

	void setGSLtime(int);
	void setVotingTime(int);

	void setCountries(std::map<wxString, Country>);
	bool addCountry(Country);
	void removeCountry(Country);

	void setPresent(int);
	void setMembersPresent(int);

	int numPresent();
	int numMembersPresent();
	
	int numTopics();
	int numMembers();
	int numObservers();
	int numCountries();

	void printMembers();
	void printObservers();
	void printCountries();
private:	
	bool initFromXML(const char *);

	wxString m_name;
	std::map<wxString, Country> m_countries; //use country name as the index of the map to keep this baby sorted by names

	// contains pointers to elements in m_countries
	std::map<wxString, Country*> m_members;
	std::map<wxString, Country*> m_observers;

	wxString m_topicA, m_topicB;
	int m_numTopics;
	int m_GSLtime;
	int m_votingTime;
	int m_numPresent;
	int m_numMembersPresent;
};

#endif
