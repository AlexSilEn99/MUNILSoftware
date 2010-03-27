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

#include <xercesc/util/XercesVersion.hpp>

#include "wxmunaboutdialog.h"

#include "defs.h"
#include "configmanager.h"
#include "version.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format) {
        wxString wxbuild(wxVERSION_STRING);

        if (format == long_f ) {
#if defined(__WXMSW__)
                wxbuild << _T("-windows");
#elif defined(__WXMAC__)
                wxbuild << _T("-mac");
#elif defined(__UNIX__)
                wxbuild << _T("-linux");
#endif

#if wxUSE_UNICODE
                wxbuild << _T("-unicode");
#else
                wxbuild << _T("-ANSI");
#endif // wxUSE_UNICODE
        }

        return wxbuild;
}

wxMUNAboutDialog::wxMUNAboutDialog( wxWindow* parent )
:
GUI_wxMUNAboutDialog( parent )
{
	wxStaticBitmap *bmpControl = (wxStaticBitmap*) wxWindow::FindWindowById(ABOUT_LOGO);

	wxImage im;
	if(im.LoadFile(ConfigManager::FindResourceFile(wxT("wxMUNlogo_medium.png")))){
		im.ConvertAlphaToMask();
		wxBitmap bmp(im);
		bmpControl->SetBitmap(bmp);  
	}	
	
	//wxNotebook *nb = (wxNotebook*) wxWindow::FindWindowById(MUN_NOTEBOOK);
	m_aboutNotebook->SetSelection(0);
	
	wxTextCtrl *description = (wxTextCtrl*) wxWindow::FindWindowById(ABOUT_DESCRIPTION);
	description->SetValue(_T("wxMUN manages Model United Nations (MUN) debates. You can manage committees through XML files and save the current state (which is also auto-saved after every speaker) of debate anywhere you wish.\n\nwxMUN is fully written in C++, using the Xerces-C++ XML parser and the wxWidgets toolkit."));
	
	wxStaticText *name = (wxStaticText*) wxWindow::FindWindowById(ABOUT_NAME);
	name->SetLabel(_T(PACKAGE_NAME));
	
	wxStaticText *version = (wxStaticText*) wxWindow::FindWindowById(ABOUT_VERSION);
	version->SetLabel(_T(VERSION));
	
	wxStaticText *author = (wxStaticText*) wxWindow::FindWindowById(ABOUT_AUTHOR);
	author->SetLabel(_T("Geert-Jan Besjes"));
	
	wxStaticText *email = (wxStaticText*) wxWindow::FindWindowById(ABOUT_EMAIL);
	email->SetLabel(_T("gbesjes@gmx.com"));
	
	wxTextCtrl *license = (wxTextCtrl*) wxWindow::FindWindowById(ABOUT_LICENSE);
	license->SetValue(LICENSE_GPL);

	wxStaticText *build_creation = (wxStaticText*) wxWindow::FindWindowById(BUILD_TIME);
	build_creation->SetLabel(version_build_creation);

	wxStaticText *build_xerces = (wxStaticText*) wxWindow::FindWindowById(BUILD_XERCES);
	wxString xercesVersion = wxT(XERCES_VERSIONSTR); xercesVersion.Replace(wxT("_"),wxT("."));
	build_xerces->SetLabel(xercesVersion);

	wxStaticText *build_wxwidgets = (wxStaticText*) wxWindow::FindWindowById(BUILD_WXWIDGETS);
	build_wxwidgets->SetLabel(wxbuildinfo(long_f));	

	wxStaticText *build_compiler = (wxStaticText*) wxWindow::FindWindowById(BUILD_COMPILER);
	build_compiler->SetLabel(wxT(USED_COMPILER));

	wxStaticText *build_cflags = (wxStaticText*) wxWindow::FindWindowById(BUILD_CFLAGS);
	build_cflags->SetLabel(wxT(USED_CXXFLAGS));

//	XERCES_VERSIONSTR
}
