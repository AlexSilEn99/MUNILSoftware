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

#include <deque>
#include <sstream>

#include <wx/defs.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/filefn.h>

#include "app.h"
#include "session.h"
#include "committee.h"
#include "country.h"
#include "configmanager.h"
#include "rollcallvote.h"

XERCES_CPP_NAMESPACE_USE

Session::Session(const Committee &c, wxString t) : m_topic(t), m_committee(c) {
	m_topicChosen=false;
	m_stateManuallySaved=false;
}

RollCallVote** Session::RCVote(){
	return &m_rcVote;
}

bool Session::isStateManuallySaved(){
	return m_stateManuallySaved;
}

void Session::checkGSLContent(){
	std::map<wxString, Country>* countries = m_committee.countries();
	for(std::deque<Country*>::iterator it = m_GSL.begin(); it != m_GSL.end();){
		//std::cout << "checking " << (*it)->name().mb_str() << std::endl;
		if( countries->find( (*it)->name() ) != countries->end() ) {
			it++;
		} else {
			//std::cout << "erasing " << (*it)->name().mb_str() << std::endl;
			it = m_GSL.erase(it);
		}
	}
}

const wxString Session::topic() const{
	return m_topic;
}

bool Session::topicChosen() {
	return m_topicChosen;
}

wxString Session::topic() {
	return m_topic;
}

void Session::setTopic(wxString t){
	m_topicChosen = true;
	m_topic = t;
	saveState();
}

Committee *Session::committee(){
	return &m_committee;
}

void Session::printGSL(){
	std::deque<Country*>::iterator it = m_GSL.begin();
	for(; it != m_GSL.end(); it++){
		std::cout << (*it)->code().fn_str() << " -- " << (*it)->name().fn_str() << std::endl;
	}
	std::cout << "-------" << std::endl;
}

void Session::setGSL(std::deque<Country*> GSL, bool save){
	m_GSL = GSL;
	if(save)
		saveState();
}	

std::deque<Country*> *Session::GSL(){
	return &m_GSL;
}

void Session::clearGSL(){
	std::deque<Country*> _GSL;
	setGSL(_GSL, true);
}

void Session::readState(wxString file){ //file default NULL

	wxString filename;
	if(file != wxEmptyString) {
		filename = file;
	} else {
		if(!wxDirExists(ConfigManager::GetFolder(sdConfig)) )
#ifdef __WXMSW__
			wxMkDir(ConfigManager::GetFolder(sdConfig).mb_str());
#else
			wxMkDir(ConfigManager::GetFolder(sdConfig).mb_str(), 0700);
#endif
		filename = ConfigManager::GetFolder(sdConfig) + wxFILE_SEP_PATH + _T("state.xml");
	}
	
	std::cout << "file = " << std::endl;
	
	wxFile stateFile;
	stateFile.Open(filename); 
	
	xercesc::XercesDOMParser *m_stateFileParser = new XercesDOMParser;
	char* _name;
	char* _code;
	char* _observer;
	char* _present;
	char* _chosen;
	char* _topicXML; //m_topicA and m_topicB are members of the class, subfix XML to prevent confusion

	// Internal class use only. Hold Xerces data in UTF-16 SMLCh type.
	XMLCh* TAG_committee;
	XMLCh* ATTR_GSLtime;
	XMLCh* TAG_countries;
	XMLCh* TAG_country;
	XMLCh* ATTR_name;
	XMLCh* ATTR_code;
	XMLCh* ATTR_observer;
	XMLCh* ATTR_present;
	XMLCh* TAG_GSL;
	XMLCh* TAG_topics;
	XMLCh* TAG_topic;
	XMLCh* ATTR_chosen;

	TAG_committee	= XMLString::transcode("committee");
	ATTR_GSLtime	= XMLString::transcode("GSLtime");
	TAG_countries	= XMLString::transcode("countries");
	TAG_country	= XMLString::transcode("country");
	ATTR_name	= XMLString::transcode("name");
	ATTR_code	= XMLString::transcode("code");
	ATTR_observer	= XMLString::transcode("observer");
	ATTR_present	= XMLString::transcode("present");
	TAG_topics	= XMLString::transcode("topics");
	TAG_topic	= XMLString::transcode("topic");
	ATTR_chosen	= XMLString::transcode("chosen");
	TAG_GSL		= XMLString::transcode("GSL");
	
	wxMenuItem *tA = (wxMenuItem*) wxWindow::FindWindowById(TOPIC_A_MENU); 
	wxMenuItem *tB = (wxMenuItem*) wxWindow::FindWindowById(TOPIC_B_MENU); 
	
	m_stateFileParser->setValidationScheme( XercesDOMParser::Val_Never );
	m_stateFileParser->setDoNamespaces( false );
	m_stateFileParser->setDoSchema( false );
	m_stateFileParser->setLoadExternalDTD( false );
	
	// init committee through its own function
	Committee c(filename.mb_str());
	m_committee = c;
	
	std::cout << "comm init done: " << m_committee.name().mb_str() << std::endl;
	
	//read the GSL and which topic is set
	try {
		m_stateFileParser->parse( filename.mb_str() );

		// no need to free this pointer - owned by the parent parser object
		XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* xmlDoc = m_stateFileParser->getDocument();

		// Get the top-level element: Name is "countries". No attributes for "countries"
		DOMElement* elementRoot = xmlDoc->getDocumentElement();
		//if( !elementRoot ) throw(std::runtime_error( "empty XML document" ));
		if( !elementRoot) 
			return;

		// Parse XML file for tags of interest: "committee"
		// Look one level nested within "committee". (child of root)
		DOMNodeList*      children = elementRoot->getChildNodes();
		const  XMLSize_t nodeCount = children->getLength();
	
		// For all nodes, children of "countries" in the XML tree.
		for( XMLSize_t xx = 0; xx < nodeCount; ++xx ){
			DOMNode* currentNode = children->item(xx);

			if( currentNode->getNodeType() &&  // true is not NULL
				currentNode->getNodeType() == DOMNode::ELEMENT_NODE ) { // is element 
         
				// Found node which is an Element. Re-cast node as element
				DOMElement* currentElement = dynamic_cast< xercesc::DOMElement* >( currentNode );

				std::cout << XMLString::transcode(currentElement->getTagName()) << std::endl;

				// list of countries for GSL
				if( XMLString::equals(currentElement->getTagName(), TAG_GSL)) {
					DOMNodeList*      countries    = currentElement->getChildNodes();
					const  XMLSize_t  countryCount = countries->getLength();

					//traverse all countries
					for(XMLSize_t k = 0; k < countryCount; ++k) {
						DOMNode* currentNode = countries->item(k);					
							if( !(currentNode->getNodeType() &&  // true is not NULL
								currentNode->getNodeType() == DOMNode::ELEMENT_NODE) )  // is element 
         							continue;

						// Found node which is an Element. Re-cast node as element
						DOMElement* currentEl = dynamic_cast< xercesc::DOMElement* >( currentNode );

						if( XMLString::equals(currentEl->getTagName(), TAG_country)) {
							// Already tested node as type element and of name "country".
							// Read attributes of element "country".
							const XMLCh* xmlch_name = currentEl->getAttribute(ATTR_name);
							_name = XMLString::transcode(xmlch_name);
						}
						
						wxString wxname = wxString::FromAscii(_name);
						wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);

						std::cout << "loaded " << _name << std::endl;

						if(GSLList->FindString(wxname) == wxNOT_FOUND){
							GSLList->Append(wxname);	
							wxString code = wxGetApp().findCountryCode(wxname);
							m_GSL.push_back(wxGetApp().findCountryPtr(code));
						}
					

					}
				} 
				// list of topics
				
				if( XMLString::equals(currentElement->getTagName(), TAG_topics)) {
					DOMNodeList*      topics    = currentElement->getChildNodes();
					const XMLSize_t  topicCount = topics->getLength();	
					if(topicCount == 0)
						throw "Committee does not have any topics!";

					std::cout << "traversing topics" << std::endl;

					//traverse all topics
					for(XMLSize_t k = 0; k < topicCount; ++k) {
						DOMNode* currentNode = topics->item(k);					
							if( !(currentNode->getNodeType() &&  // true is not NULL
								currentNode->getNodeType() == DOMNode::ELEMENT_NODE) )  // is element 
         							continue;

						if(k == 2)
								break; // only support two topics as of now	

						// Found node which is an Element. Re-cast node as element
						DOMElement* currentEl = dynamic_cast< xercesc::DOMElement* >( currentNode );

						if( XMLString::equals(currentEl->getTagName(), TAG_topic)) {
							// Already tested node as type element and of name "topic".
							// Read attributes of element "topic".
							const XMLCh* xmlch_topic = currentEl->getAttribute(ATTR_name);
							_topicXML = XMLString::transcode(xmlch_topic);

							const XMLCh* xmlch_chosen = currentEl->getAttribute(ATTR_chosen);
							_chosen = XMLString::transcode(xmlch_chosen);
							
							std::cout << "hello i'm topicXML" << std::endl;
							std::cout << _topicXML << " " << strlen(_chosen) << " " << _chosen << std::endl;
							
							if(k == 0){
								m_committee.setTopicA(wxString::FromAscii(_topicXML));
							} else {
								m_committee.setTopicB(wxString::FromAscii(_topicXML));
							}
							
							if(strncmp(_chosen, "true", 4) == 0){
								m_topicChosen = true;
								m_topic = wxString::FromAscii(_topicXML);
							}
						}
						// std::cout << "topic: " << m_topicXML << std::endl;
					}
				}

			}
		}
	} catch( xercesc::XMLException& e ) {
		// make this graphical!
		char* message = xercesc::XMLString::transcode( e.getMessage() );
		std::ostringstream errBuf;
		
		errBuf << "Error parsing file: " << message << std::endl;
		XMLString::release( &message );
		return;
	} catch ( const char *e ){
		// put up about box
		std::cerr << e << std::endl;
		return;
	}
}

void Session::saveState(wxString file){ //file default NULL
	
	std::cout << "Save state called" << std::endl;
	
	wxString filename;
	if(file != wxEmptyString) {
		m_stateManuallySaved=true;
		filename = file;
	} else {
		m_stateManuallySaved=false; //modified, so modifications are not saved manually (yet)
		if(!wxDirExists(ConfigManager::GetFolder(sdConfig)) )
#ifdef __WXMSW__
			wxMkDir(ConfigManager::GetFolder(sdConfig).mb_str());
#else				
		wxMkDir(ConfigManager::GetFolder(sdConfig).mb_str(), 0700);
#endif
		filename = ConfigManager::GetFolder(sdConfig) + wxFILE_SEP_PATH + _T("state.xml");
	}
	wxFile XMLoutput;
	XMLoutput.Create(filename, true); //overwrite any existing state
		
	wxString s = _T("<?xml version='1.0' encoding='UTF-8'?>");
	
	XMLoutput.Write(s+wxT("\n"));
	XMLoutput.Write(wxT("\n<committee "));
	XMLoutput.Write(wxT("name=\"")+m_committee.name()+wxT("\" "));
	
	//write GSL time
	s = wxString(wxT("")); s << m_committee.GSLtime();
	XMLoutput.Write(wxT("GSLtime=\"")+s+wxT("\" >\n"));

	// write countries
	XMLoutput.Write(wxT("\t<countries>\n"));

	//loop
	std::map<wxString, Country >::iterator it = m_committee.countries()->begin();
	for(it; it != m_committee.countries()->end(); it++){
		XMLoutput.Write(wxT("\t\t<country "));
		XMLoutput.Write(wxT("name=\"")+it->second.name()+wxT("\" "));
		XMLoutput.Write(wxT("code=\"")+it->second.code()+wxT("\" "));

		if(it->second.isObserver())
			XMLoutput.Write(wxT("observer=\"true\" "));
		
		if(it->second.isPresent())
			XMLoutput.Write(wxT("present=\"true\" "));
		else
			XMLoutput.Write(wxT("present=\"false\" "));

		XMLoutput.Write(wxT("/>\n"));
	}

	XMLoutput.Write(wxT("\t</countries>\n"));

	XMLoutput.Write(wxT("\t<GSL>\n"));
	std::deque<Country*>::iterator iter = m_GSL.begin();
	for(; iter != m_GSL.end(); iter++){
		//std::cout << (*iter)->code().fn_str() << " -- " << (*iter)->name().fn_str() << std::endl;
		XMLoutput.Write(wxT("\t\t<country name=\"")+(*iter)->name()+wxT("\" />\n"));
	}	
	XMLoutput.Write(wxT("\t</GSL>\n"));

	XMLoutput.Write(wxT("\t<topics>\n"));
	XMLoutput.Write(wxT("\t\t<topic name=\"")+m_committee.topicA());
	if(m_topic == m_committee.topicA())
		XMLoutput.Write(wxT("\" chosen=\"true"));
	XMLoutput.Write(wxT("\" />\n"));

	if(!m_committee.topicB().IsEmpty() && m_committee.topicA() != m_committee.topicB()){ //possible topic B
		XMLoutput.Write(wxT("\t\t<topic name=\"")+m_committee.topicB());
		if(m_topic == m_committee.topicB())
			XMLoutput.Write(wxT("\" chosen=\"true"));
		XMLoutput.Write(wxT("\" />\n"));
	}
	XMLoutput.Write(wxT("\t</topics>\n"));			
	XMLoutput.Write(wxT("</committee>\n"));
}
