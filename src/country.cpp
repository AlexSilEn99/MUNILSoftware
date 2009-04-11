/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#include <iostream>
#include <wx/defs.h>
#include <wx/string.h>
#include "country.h"

Country::Country(const Country &c){
	m_name = c.m_name;
	m_code = c.m_code;
	m_observer = c.m_observer;
	m_present = c.m_present;
}

Country::Country(wxString name, wxString code, bool o=false, bool p) : m_name(name), m_code(code), m_observer(o), m_present(p) {
}

wxString Country::name(){
	return m_name;
}

wxString Country::code(){
	return m_code;
}

wxString Country::flag(){
	wxString path = wxT("data/flags/");
	wxString s(m_code);
	return path+s.append(wxString(wxT(".png")));
}

void Country::makeObserver() {
	m_observer = true;
	std::cout << "made " << m_name.mb_str() << " obs. " << std::endl;
}

void Country::makeMember() {
	m_observer = false;
}

bool Country::isObserver(){
	return m_observer;
}

void Country::makePresent() {
	m_present = true;
}

void Country::makeNotPresent() {
	m_present = false;
}

bool Country::isPresent(){
	return m_present;
}
