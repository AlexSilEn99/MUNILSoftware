/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#include <iostream>
#include <set>
#include "country.h"
#include "rollcallvote.h"

RollCallVote::RollCallVote(bool consensusBased, bool hasP5veto, bool hasMinInFavour) 
: m_consensusBased(consensusBased), m_P5veto(hasP5veto), m_hasMinInFavour(hasMinInFavour), m_minInFavour(9)
{

}

void RollCallVote::Print(){
	std::set<wxString>::iterator it;
	
	std::cout << "In favour: " << std::endl;
	for(it = m_inFavour.begin(); it != m_inFavour.end(); it++)
		std::cout << "\t" << it->mb_str() << std::endl;
		
	std::cout << "Against: " << std::endl;
	for(it = m_against.begin(); it != m_against.end(); it++)
		std::cout << "\t" << it->mb_str() << std::endl;

	std::cout << "Abstaining: " << std::endl;
	for(it = m_abstaining.begin(); it != m_abstaining.end(); it++)
		std::cout << "\t" << it->mb_str() << std::endl;
}

bool RollCallVote::Passed()
{
	if( ( m_consensusBased && numAgainst() > 0 ) || 		//consensus fails
 	    ( m_P5veto && IsVetoed() )  ||				// vetoed
	    ( m_hasMinInFavour && numInFavour() < GetMinInFavour() ) 	// doesn't meet minimum amount
	    ) {

		return false;
	} else if ( numAgainst() < numInFavour() ) {
		return true;
	} else {
		return false;
	}
	
	return false;
}

bool RollCallVote::Failed()
{
	return !Passed();
}

bool RollCallVote::IsConsensusBased(){
	return m_consensusBased;
}

void RollCallVote::SetConsensusBasedFlag(bool b){
	m_consensusBased = b;
}
	
bool RollCallVote::IsSCMode(){
	return m_P5veto;
}

bool RollCallVote::IsVetoed(){
	//Very ugly! But it works. Sort of. 
	// (that is - if the user doesn't rename one of these countries...)
	
	if( !m_P5veto || m_against.size() == 0)
		return false;
		
	std::set<wxString>::iterator it = m_against.begin();
	for(; it != m_against.end(); it++){
		if ( *it == wxT("China") ||
		     *it == wxT("France") ||
		     *it == wxT("Russian Federation") ||
		     *it == wxT("United Kingdom") ||
		     *it == wxT("United States of America") )
		  	return true;
	}	
	
	return false;
}

void RollCallVote::SetSCModeFlag(bool b){
	m_P5veto = b;
}

bool RollCallVote::HasMinInFavour()
{
	 return m_hasMinInFavour;
}

void RollCallVote::SetMinInFavourFlag(bool b)
{
	m_hasMinInFavour = b;
}

void RollCallVote::SetMinInFavour(int n)
{
	m_minInFavour = n;
}

int RollCallVote::GetMinInFavour()
{
	return m_minInFavour;
}

void RollCallVote::addAgainst(wxString s){
	m_against.insert(s);
}

void RollCallVote::addInFavour(wxString s){
	m_inFavour.insert(s);
}

void RollCallVote::addAbstaining(wxString s){
	m_abstaining.insert(s);
}

void RollCallVote::removeAgainst(wxString s){
	m_against.erase(s);
}

void RollCallVote::removeInFavour(wxString s){
	m_inFavour.erase(s);
}

void RollCallVote::removeAbstaining(wxString s){
	m_abstaining.erase(s);
}

int RollCallVote::numAgainst(){
	return m_against.size();
}

int RollCallVote::numInFavour(){
	return m_inFavour.size();
}

int RollCallVote::numAbstentions(){
	return m_abstaining.size();
}

