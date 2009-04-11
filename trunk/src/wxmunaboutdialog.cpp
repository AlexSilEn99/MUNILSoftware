/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#include "wxmunaboutdialog.h"
#include "defs.h"
#include "configmanager.h"

wxMUNAboutDialog::wxMUNAboutDialog( wxWindow* parent )
:
GUI_wxMUNAboutDialog( parent )
{
	wxStaticBitmap *bmpControl = (wxStaticBitmap*) wxWindow::FindWindowById(ABOUT_LOGO);

	wxImage im;
	if(im.LoadFile(ConfigManager::FindDataFile(_T("images/wxMUNlogo_medium.png")))){
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
	email->SetLabel(_T("g.besjes@student.science.ru.nl"));
	
	wxTextCtrl *license = (wxTextCtrl*) wxWindow::FindWindowById(ABOUT_LICENSE);
	license->SetValue(LICENSE_MIT);

}
