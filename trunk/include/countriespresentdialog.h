#ifndef __countriespresentdialog__
#define __countriespresentdialog__

/**
@file
Subclass of GUI_CountriesPresentDialog, which is generated by wxFormBuilder.
*/

#include "gui.h"

/** Implementing GUI_CountriesPresentDialog */
class CountriesPresentDialog : public GUI_CountriesPresentDialog
{
public:
	/** Constructor */
	CountriesPresentDialog( wxWindow* parent, std::map<wxString, Country> *countries );

	void OnCountriesPresentToggle( wxCommandEvent& event);
	void OnSelectAll(wxCommandEvent& event);
	void OnSelectNone(wxCommandEvent& event);
	void OnInvert(wxCommandEvent& event);
private:
	void CheckNumPresent();
	int m_numPresent;
};

#endif // __countriespresentdialog__
