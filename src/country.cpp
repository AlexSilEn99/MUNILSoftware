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
	wxString path = wxT("resources/flags/"); //TODO move this to configmanager element
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
