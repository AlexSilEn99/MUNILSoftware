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

#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
//#include <unistd.h>
#include <errno.h>

#include <wx/file.h>
#include <wx/taskbar.h>
#include <wx/sstream.h>
#include <wx/url.h>
#include <wx/artprov.h>
#include "wx/aui/aui.h"

#ifdef HAVE_CONFIG_H
 #include "../config.h"
#endif

#include "app.h" //TODO: BAD stuff!
#include "configmanager.h"
#include "defs.h"

//using namespace xercesc_2_8;
XERCES_CPP_NAMESPACE_USE

wxMUNFrame *parentFrame;

wxULongLong ConvertToVersionNumber(const wxChar* version) {
        // This function is (c) the FileZilla project.

        // Crude conversion from version string into number for easy comparison
        // Supported version formats:
        // 1.2.4
        // 11.22.33.44
        // 1.2.3-rc3
        // 1.2.3.4-beta5
        // All numbers can be as large as 1024, with the exception of the release candidate.

        // Only either rc or beta can exist at the same time)
        //
        // The version string A.B.C.D-rcE-betaF expands to the following binary representation:
        // 0000aaaaaaaaaabbbbbbbbbbccccccccccddddddddddxeeeeeeeeeffffffffff
        //
        // x will be set to 1 if neither rc nor beta are set. 0 otherwise.
        //
        // Example:
        // 2.2.26-beta3 will be converted into
        // 0000000010 0000000010 0000011010 0000000000 0000000000 0000000011
        // which in turn corresponds to the simple 64-bit number 2254026754228227
        // And these can be compared easily

        wxASSERT(*version >= '0' && *version <= '9');

        wxULongLong v = 0;
        int segment = 0;

        int shifts = 0;

        for (; *version; version++) {
                if (*version == '.' || *version == '-' || *version == 'b') {
                        v += segment;
                        segment = 0;
                        v <<= 10;
                        shifts++;
                }
                
                if (*version == '-' && shifts < 4) {
                        v <<= (4 - shifts) * 10;
                        shifts = 4;
                } else if (*version >= '0' && *version <= '9') {
                        segment *= 10;
                        segment += *version - '0';
                }
        }
        v += segment;
        v <<= (5 - shifts) * 10;

        // Make sure final releases have a higher version number than rc or beta releases
        if ((v & 0x0FFFFF) == 0)
                v |= 0x080000;

        return v;
}

bool wxMUN::checkForUpdates(){
        wxString current = wxT(VERSION), latest;

        wxURL url(wxT(CHECK_FOR_UPDATE_URL));
        wxYield();
        wxInputStream *data = url.GetInputStream();
        if (!data)
                return false;

        wxStringOutputStream buf(&latest);
        data->Read(buf);

        latest.Trim();
        m_latest_version = latest;

        if( ConvertToVersionNumber(current) < ConvertToVersionNumber(latest) )
                return true;

        return false;
}

void wxMUN::setSession(Session s){
        m_session = s;
        m_session.saveState();
}

Session *wxMUN::session(){
        return &m_session;
}

bool wxMUN::isCommitteeLoaded(){
        return m_committeeLoaded;
}

void wxMUN::committeeLoaded(){
        m_committeeLoaded = true;
}

Country* wxMUN::findCountryPtr(wxString code){
        std::map<wxString, Country>::iterator it = m_allAvailableCountries.find(code);
        if(it == m_allAvailableCountries.end())
                return NULL;

        return &(m_allAvailableCountries[code]);
}

Country wxMUN::findCountry(wxString code){
        std::map<wxString, Country>::iterator it = m_allAvailableCountries.find(code);
        if(it == m_allAvailableCountries.end())
                throw -1;

        return m_allAvailableCountries[code];
}

wxString wxMUN::findCountryCode(wxString name){
        std::map<wxString, Country>::iterator it = m_allAvailableCountries.begin();
        for(; it != m_allAvailableCountries.end(); it++){
                if(it->second.name() == name)
                        return it->first;
        }

        return wxEmptyString;
}

wxString wxMUN::findCountryFlagByName(wxString name){
        std::map<wxString, Country>::iterator it = m_allAvailableCountries.begin();
        for(; it != m_allAvailableCountries.end(); it++){
                if(it->second.name() == name)
                        return it->second.flag();
        }

        return wxEmptyString;
}

std::map<wxString, Country>* wxMUN::availableCountries() {
        return &m_allAvailableCountries;
}

std::map<wxString, Country*>* wxMUN::committeeCountries() {
        return &m_committeeCountries;
}

void MakeLowerAscii(wxString& str){
        for (size_t i = 0; i < str.Len(); i++) {
                wxChar& c = str[i];
                if (c >= 'A' && c <= 'Z')
                        c += 32;
        }
}

//TODO: move to more sensible place
wxIconBundle wxMUN::GetIconBundle(const wxArtID& id, const wxArtClient& client /*=wxART_OTHER*/) {
        wxIconBundle iconBundle;

        if (id.Left(4) != _T("ART_"))
                return iconBundle;

        wxString name = id.Mid(4);
        MakeLowerAscii(name);

        const wxChar* dirs[3] = { _T("16x16/"), _T("32x32/"), _T("48x48/") };

        for (int i = 0; i < 3; i++) {
                wxString file =  ConfigManager::GetFolder(sdResources) + wxFILE_SEP_PATH + dirs[i] + name + _T(".png");

                if (!wxFileName::FileExists(file))
                        continue;

                iconBundle.AddIcon(wxIcon(file, wxBITMAP_TYPE_PNG));
        }

        return iconBundle;
}

bool wxMUN::ReadCountries(const char *filename){

        xercesc::XercesDOMParser *m_CountriesFileParser = new XercesDOMParser;
        char* m_name = NULL;
        char* m_code = NULL;
        char* m_observer = NULL;
        const char *_true = "true";

        // Internal class use only. Hold Xerces data in UTF-16 SMLCh type.
        XMLCh* TAG_countries;
        XMLCh* TAG_country;
        XMLCh* ATTR_name;
        XMLCh* ATTR_code;
        XMLCh* ATTR_observer;

        TAG_countries   = XMLString::transcode("countries");
        TAG_country     = XMLString::transcode("country");
        ATTR_name       = XMLString::transcode("name");
        ATTR_code       = XMLString::transcode("code");
        ATTR_observer   = XMLString::transcode("observer");

        // Configure DOM parser.
        m_CountriesFileParser->setValidationScheme( XercesDOMParser::Val_Never );
        m_CountriesFileParser->setDoNamespaces( false );
        m_CountriesFileParser->setDoSchema( false );
        m_CountriesFileParser->setLoadExternalDTD( false );

        try {
                m_CountriesFileParser->parse( filename );

                // no need to free this pointer - owned by the parent parser object
                XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* xmlDoc = m_CountriesFileParser->getDocument();

                // Get the top-level element: Name is "countries". No attributes for "countries"
                DOMElement* elementRoot = xmlDoc->getDocumentElement();
                //if( !elementRoot ) throw(std::runtime_error( "empty XML document" ));
                if( !elementRoot) return false;

                // Parse XML file for tags of interest: "countries"
                // Look one level nested within "countries". (child of root)
                DOMNodeList*	  children = elementRoot->getChildNodes();
                const  XMLSize_t nodeCount = children->getLength();

                // For all nodes, children of "countries" in the XML tree.
                for( XMLSize_t xx = 0; xx < nodeCount; ++xx ){
                        DOMNode* currentNode = children->item(xx);
                        if( currentNode->getNodeType() &&  // true is not NULL
                                currentNode->getNodeType() == DOMNode::ELEMENT_NODE ) { // is element 
                        
                                // Found node which is an Element. Re-cast node as element
                                DOMElement* currentElement = dynamic_cast< xercesc::DOMElement* >( currentNode );
                                if( XMLString::equals(currentElement->getTagName(), TAG_country)) {
                                        // Already tested node as type element and of name "country".
                                        // Read attributes of element "country".
                                        const XMLCh* xmlch_name = currentElement->getAttribute(ATTR_name);
                                        m_name = XMLString::transcode(xmlch_name);

                                        const XMLCh* xmlch_code = currentElement->getAttribute(ATTR_code);
                                        m_code = XMLString::transcode(xmlch_code);

                                        const XMLCh* xmlch_observer = currentElement->getAttribute(ATTR_observer);
                                        m_observer = XMLString::transcode(xmlch_observer);

                                        // break;  // Data found. No need to look at other elements in tree.
                                }
                                wxString wxname = wxString::FromAscii(m_name);
                                wxString wxcode = wxString::FromAscii(m_code);
                                m_allAvailableCountries[wxcode] = Country(wxname, wxcode, (m_observer==_true));

                                //std::cout << "name: " << m_name << " code: " << m_code << " observer: " << m_observer << std::endl;
                        }
                }
        } catch( xercesc::XMLException& e ) {
                char* message = xercesc::XMLString::transcode( e.getMessage() );
                std::ostringstream errBuf;
                
                errBuf << "Error parsing file: " << message << std::endl;
                XMLString::release( &message );
                return false;
        }

        return true;
}

void wxMUN::LoadCommitteeFromFile(wxString filename, bool overwriteState){
        if(filename == wxEmptyString)
                return;

        Committee c(filename.mb_str());
        if(overwriteState){
                // create session instance
                Session s(c);

                // write session back to wxMUN instance and save
                wxGetApp().committeeLoaded();
                wxGetApp().setSession(s);

        } else {
                //only overwrite the committee countries in session
                wxGetApp().session()->committee()->setCountries(* (c.countries()) );
                wxGetApp().session()->checkGSLContent();
                parentFrame->updateGSLListBox(wxGetApp().session()->GSL());
        }

        wxGetApp().session()->saveState();
        parentFrame->LoadSetLabels();

        // prepare message header for user
        wxString message = wxT("Loaded '");
        message << c.name(); message << wxT("'\n");
        message << c.numCountries() << wxT(" countries in committee (") << c.numMembers();
        message << wxT(" members, ") << c.numObservers() << wxT(" observers)\n\n");

        // append topics to the message
        if(c.numTopics() == 1){
                message << wxT("Topic:\n");
                message << c.topicA() << wxT("\n");
        } else {
                message << wxT("Topics:\n");
                message << c.topicA() << wxT("\n");
                message << c.topicB() << wxT("\n");
        }

        wxMessageBox(message,
                wxT("Loaded committee"),
                wxICON_INFORMATION | wxOK, NULL);
}

//TODO: should move into a library (like all the other state/country/committee stuff)
void wxMUN::readState(wxString filename /* = wxEmptyString */){
        wxString file = (filename != wxEmptyString) ? filename : ConfigManager::GetFolder(sdConfig) + wxFILE_SEP_PATH + _T("state.xml");

#ifdef DEBUG
        std::cout << "wxMUN::readState(): " << file.mb_str() << std::endl;
#endif
        
        if(wxFile::Exists(file)){
                m_session.readState(file);
                m_committeeLoaded = true;
                
                parentFrame->LoadSetLabels(); //clear any GSL
        }
}

bool wxMUN::OnInit(){
        ConfigManager* mgr = 0;

        try {
                xercesc::XMLPlatformUtils::Initialize();
        } catch( xercesc::XMLException& e ){
                char* message = xercesc::XMLString::transcode( e.getMessage() ) ;
                std::cerr << "XML toolkit initialization error: "
                        << message
                        << std::endl;
                xercesc::XMLString::release( &message ) ;
                return false;
        }

        try { 
                if(ConfigManager::FindResourceFile(_T("countries.xml")) == wxEmptyString){
                        throw "Could not find datafile";
                }
                ReadCountries(ConfigManager::FindResourceFile(_T("countries.xml")).mb_str());
        } catch (const char *error) {
                wxString message = wxT("wxMUN could not read country data file resources/");
                message << wxFILE_SEP_PATH << wxT("countries.xml.\n");
                message << wxT("(Expecting file to be at ");
                message << ConfigManager::GetFolder(sdResources) + wxFILE_SEP_PATH + _T("countries.xml");
                message << wxT("\nor, if you have made your own version, at:\n");		
                message << ConfigManager::GetFolder(sdDataUser) + wxFILE_SEP_PATH + _T("countries.xml");
                message << wxT(")\n");		

                wxMessageBox(message,
                        wxT("Error: cannot initialize"),
                        wxICON_ERROR | wxOK, NULL);

                return false;
        }

        //we don't know what crazy formats people might make flags in, init all possible handlers!
        ::wxInitAllImageHandlers(); 

#ifndef DEBUG
        wxImage bitmap;
        wxSplashScreen *splash=NULL;
        if (bitmap.LoadFile(ConfigManager::FindResourceFile(wxT("splash.png")), wxBITMAP_TYPE_PNG)){
                splash = new wxSplashScreen(bitmap,
                                wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
                                3500, NULL, -1, wxDefaultPosition, wxDefaultSize,
                                wxSIMPLE_BORDER|wxFRAME_NO_TASKBAR|wxSTAY_ON_TOP); 
        }

        if(splash){ 
                //explicitely delete the splash or the parent frame will start minimized
                wxMilliSleep(3500);
                delete splash; 
        }
#endif

        wxYield();

        parentFrame = new wxMUNFrame(NULL);
        parentFrame->SetTitle(wxString(DEFAULT_WINDOW_TITLE));
        parentFrame->Centre();
        parentFrame->Show(true);

        readState();

        //wxTaskBarIcon* tbIcon = new wxTaskBarIcon();
#ifdef __WXMSW__
        parentFrame->SetIcon(wxICON(appicon));
        //tbIcon->SetIcon(wxICON(MAIN_ICON))
#else
        parentFrame->SetIcons(GetIconBundle(_T("ART_WXMUN")));
        //tbIcon->SetIcon(wxMUN_xpm);
#endif // __WXMSW__

        wxAuiNotebook *nb = (wxAuiNotebook*) wxWindow::FindWindowById(MUN_NOTEBOOK);
        nb->SetSelection(0);

        if( checkForUpdates() ){
                wxString message = wxT("An updated version to wxMUN is available. You are currently running version ");
                message << wxT(VERSION);
                message << wxT(", the latest downloadable one is wxMUN ") << m_latest_version << wxT(".\n\nVisit http://wxmun.unitednetherlands.org to get the update.");

                wxMessageBox(message,
                        wxT("New version available!"),
                        wxICON_INFORMATION | wxOK, parentFrame);
        }

        return true;
        }

int wxMUN::OnExit(){
        xercesc::XMLPlatformUtils::Terminate();

        return 0;
}

IMPLEMENT_APP( wxMUN );
