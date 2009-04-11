/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#ifndef ROLLCALLVOTE_H
#define ROLLCALLVOTE_H

#include <set>
#include "wx/string.h"

class RollCallVote {
public:
	RollCallVote(bool consensus=false, bool hasVeto=false, bool hasMinInFavour=false);

	void Print();

	bool Passed();
	bool Failed();

	bool IsConsensusBased();
	void SetConsensusBasedFlag(bool);
	
	bool IsSCMode();
	void SetSCModeFlag(bool);

	bool HasMinInFavour();
	void SetMinInFavourFlag(bool);
	void SetMinInFavour(int);
	int GetMinInFavour();

	bool IsVetoed();

	void addAgainst(wxString);
	void addInFavour(wxString);
	void addAbstaining(wxString);
	
	void removeAgainst(wxString);
	void removeInFavour(wxString);
	void removeAbstaining(wxString);

	int numAgainst();
	int numInFavour();
	int numAbstentions();

private:

	bool m_consensusBased;
	bool m_hasMinInFavour;
	bool m_P5veto;
	
	int m_minInFavour;
	
	std::set<wxString> m_against;
	std::set<wxString> m_inFavour;
	std::set<wxString> m_abstaining;
};

#endif
