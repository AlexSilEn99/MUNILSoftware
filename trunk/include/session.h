/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
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
