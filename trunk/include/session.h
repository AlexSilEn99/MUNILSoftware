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

#ifndef SESSION_H
#define SESSION_H

#include <deque>
#include <wx/defs.h>
#include <wx/string.h>
#include "committee.h"
#include "country.h"
#include "rollcallvote.h"

class Session {
public:
	Session() {};
	Session(const Committee&, wxString t=wxT(""));

	RollCallVote **RCVote();

	bool isStateManuallySaved();
	const wxString topic() const;

	void checkGSLContent();
	void printGSL();
	void readState( wxString file = wxEmptyString );
	void saveState( wxString file = wxEmptyString );
	void clearGSL();
	void setGSL(std::deque<Country*>, bool save = true);
	void setTopic(wxString);
	bool topicChosen();
	wxString topic();

	Committee *committee();
	std::deque<Country*> *GSL();

private:
	bool m_stateManuallySaved;
	bool m_topicChosen;

	wxString m_topic; 
	Committee m_committee;
	std::deque<Country*> m_GSL;
	
	RollCallVote *m_rcVote;
};

#endif
