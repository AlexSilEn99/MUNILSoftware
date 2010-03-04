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
