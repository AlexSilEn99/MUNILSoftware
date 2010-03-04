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
