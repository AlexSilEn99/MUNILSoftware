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
#include <map>
#include <wx/defs.h>
#include <wx/string.h>
#include "defs.h"
#include "main.h"
#include "country.h"
#include "committee.h"

#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
//#include <unistd.h>
#include <errno.h>

Committee::Committee(const char *filename) : m_numTopics(0), m_votingTime(30), m_numPresent(0), m_numMembersPresent(0) {
	if(initFromXML(filename)){
		std::cout << "initFromXML ok" << std::endl;
	}
}

void Committee::setVotingTime(int t ){
	m_votingTime = t;
}

void Committee::setGSLtime(int t ){
	m_GSLtime = t;
}

int Committee::numTopics(){
	return m_numTopics;
}

int Committee::numMembers(){
	return m_members.size();
}

int Committee::numObservers(){
	return m_observers.size();
}

int Committee::numCountries(){
	return m_countries.size();
}

std::map<wxString, Country> *Committee::countries(){
	return &m_countries;
}

std::map<wxString, Country*> *Committee::members(){
	return &m_members;
}

std::map<wxString, Country*> *Committee::observers(){
	return &m_observers;
}

int Committee::numPresent(){
	return m_numPresent;
}

int Committee::numMembersPresent(){
	return m_numMembersPresent;
}

void Committee::setPresent(int n){
	m_numPresent = n;
}

void Committee::setMembersPresent(int n){
	m_numMembersPresent = n;
}

void Committee::printMembers(){
	for( std::map<wxString, Country*>::iterator it = m_members.begin(); it != m_members.end(); it++){
		std::cout << it->second->code().fn_str() << " " << it->second->name().fn_str() << std::endl;
	}
}

void Committee::printObservers(){
	for( std::map<wxString, Country*>::iterator it = m_observers.begin(); it != m_observers.end(); it++){
		std::cout << it->second->code().fn_str() << " " << it->second->name().fn_str() << std::endl;
	}
}

void Committee::printCountries(){
	printMembers();
	printObservers();
}

void Committee::setCountries(std::map<wxString, Country> countries){
	std::map<wxString, Country>::iterator it = countries.begin();

	std::map<wxString, Country> countries_old = m_countries;

	m_countries.clear(); m_members.clear(); m_observers.clear();
	for(; it != countries.end(); it++){
		if(countries_old.find(it->second.name()) != countries_old.end() && countries_old[it->second.name()].isPresent())
			it->second.makePresent();
		addCountry(it->second);
	}
}

bool Committee::addCountry(Country c){
	std::map<wxString, Country>::iterator it = m_countries.find(c.name());

	if( it != m_countries.end() ) //already exists!
		return false;

	m_countries[c.name()] = c;
	if( c.isObserver() )
		m_observers[c.name()] = &(m_countries[c.name()]);
	else
		m_members[c.name()] = &(m_countries[c.name()]);

	return true;
}

void Committee::removeCountry(Country c){
	// we don't care about non-existing members being deleted
	m_countries.erase(c.name());
	m_observers.erase(c.name());
	m_members.erase(c.name());
}

wxString Committee::name(){
	return m_name;
}

wxString Committee::topicA(){
	return m_topicA;
}

wxString Committee::topicB(){
	return m_topicB;
}

void Committee::setTopicA(wxString t){
	m_topicA = t;
}

void Committee::setTopicB(wxString t){
	m_topicB = t;
}

int Committee::GSLtime(){
	return m_GSLtime;
}

int Committee::votingTime(){
	return m_votingTime;
}

bool Committee::initFromXML(const char *filename){
	xercesc::XercesDOMParser *m_CommiteeFileParser = new XercesDOMParser;
	char* _name;
	char* _code;
	char* _observer;
	char* _present;
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
	XMLCh* TAG_topics;
	XMLCh* TAG_topic;

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

	// Test to see if the file is ok.
/*	struct stat fileStatus;
	int iretStat = stat(filename, &fileStatus);

	if( iretStat == ENOENT ){
		throw ( "Path file_name does not exist, or path is an empty string." );
		return false;
	} else if( iretStat == ENOTDIR ){
		throw ( "A component of the path is not a directory." );
		return false;
	} else if( iretStat == ELOOP ){
		throw ( "Too many symbolic links encountered while traversing the path.");
		return false;
	} else if( iretStat == EACCES ){
		throw ( "Permission denied.");
		return false;
	} else if( iretStat == ENAMETOOLONG ){
		throw ( "File can not be read\n");
		return false;
	}
*/
	// Configure DOM parser.
	m_CommiteeFileParser->setValidationScheme( XercesDOMParser::Val_Never );
	m_CommiteeFileParser->setDoNamespaces( false );
	m_CommiteeFileParser->setDoSchema( false );
	m_CommiteeFileParser->setLoadExternalDTD( false );

	try {
		m_CommiteeFileParser->parse( filename );

		// no need to free this pointer - owned by the parent parser object
		XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* xmlDoc = m_CommiteeFileParser->getDocument();

		// Get the top-level element: Name is "countries". No attributes for "countries"
		DOMElement* elementRoot = xmlDoc->getDocumentElement();
		//if( !elementRoot ) throw(std::runtime_error( "empty XML document" ));
		if( !elementRoot) return false;

		// Parse XML file for tags of interest: "committee"
		// Look one level nested within "committee". (child of root)
		DOMNodeList*      children = elementRoot->getChildNodes();
		const  XMLSize_t nodeCount = children->getLength();

		//std::cout << XMLString::transcode(currentElement->getTagName()) << std::endl;
		const XMLCh* xmlch_name = elementRoot->getAttribute(ATTR_name);
		_name = XMLString::transcode(xmlch_name);
		std::cout << _name << std::endl;
		if(_name == "")
			throw "Committee does not have a name!";

		m_name = wxString::FromAscii(_name);

		const XMLCh* xmlch_time = elementRoot->getAttribute(ATTR_GSLtime);
		setGSLtime(atoi(XMLString::transcode(xmlch_time)));
	
		// For all nodes, children of "countries" in the XML tree.
		for( XMLSize_t xx = 0; xx < nodeCount; ++xx ){
			DOMNode* currentNode = children->item(xx);

			if( currentNode->getNodeType() &&  // true is not NULL
				currentNode->getNodeType() == DOMNode::ELEMENT_NODE ) { // is element 
         
				// Found node which is an Element. Re-cast node as element
				DOMElement* currentElement = dynamic_cast< xercesc::DOMElement* >( currentNode );

				std::cout << XMLString::transcode(currentElement->getTagName()) << std::endl;

				// list of countries
				if( XMLString::equals(currentElement->getTagName(), TAG_countries)) {
					DOMNodeList*      countries    = currentElement->getChildNodes();
					const  XMLSize_t  countryCount = countries->getLength();

					if(countryCount == 0)
						throw "Committee does not have any countries!";

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

							const XMLCh* xmlch_code = currentEl->getAttribute(ATTR_code);
							_code = XMLString::transcode(xmlch_code);	

							const XMLCh* xmlch_observer = currentEl->getAttribute(ATTR_observer);
							_observer = XMLString::transcode(xmlch_observer);
							
							const XMLCh* xmlch_present = currentEl->getAttribute(ATTR_present);
							_present = XMLString::transcode(xmlch_present);
						}
						
						wxString wxname = wxString::FromAscii(_name);
						wxString wxcode = wxString::FromAscii(_code);
						Country c(wxGetApp().findCountry(wxcode));
						
						if(strncmp(_observer,"true", 4) == 0){
							c.makeObserver();
							std::cout << "observer true" << std::endl;
						} else {
							std::cout << "_observer = " << _observer << std::endl;
							c.makeMember();	
						}
						
						if(strncmp(_present,"true", 4) == 0){
							m_numPresent++;
							if(!c.isObserver())
								m_numMembersPresent++;
								
							c.makePresent();
						} else {
							c.makeNotPresent();
						}
									

						addCountry(c);
						//std::cout << "name: " << m_name << " code: " << m_code << " observer: " << m_observer << std::endl;
					}
				}
				// list of topics
				else if( XMLString::equals(currentElement->getTagName(), TAG_topics)) {
					DOMNodeList*      topics    = currentElement->getChildNodes();
					const XMLSize_t  topicCount = topics->getLength();	
					if(topicCount == 0)
						throw "Committee does not have any topics!";

					//traverse all topics
					for(XMLSize_t k = 0; k < topicCount; ++k) {
						DOMNode* currentNode = topics->item(k);					
							if( !(currentNode->getNodeType() &&  // true is not NULL
								currentNode->getNodeType() == DOMNode::ELEMENT_NODE) )  // is element 
         							continue;

						// Found node which is an Element. Re-cast node as element
						DOMElement* currentEl = dynamic_cast< xercesc::DOMElement* >( currentNode );

						if( XMLString::equals(currentEl->getTagName(), TAG_topic)) {
							if(++m_numTopics > 2)
								break; // only support two topics as of now	

							// Already tested node as type element and of name "topic".
							// Read attributes of element "topic".
							const XMLCh* xmlch_topic = currentEl->getAttribute(ATTR_name);
							_topicXML = XMLString::transcode(xmlch_topic);

							//max 2 topics, the first will be A and the second B
							if(m_numTopics==1) m_topicA = wxString::FromAscii(_topicXML);
							else	 m_topicB = wxString::FromAscii(_topicXML);
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
		return false;
	} catch ( const char *e ){
		// put up about box
		std::cerr << e << std::endl;
		return false;
	}

	return true;
}

