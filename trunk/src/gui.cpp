///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

// Using the construction of a static object to ensure that the help provider is set
class wxFBContextSensitiveHelpSetter
{
public:
wxFBContextSensitiveHelpSetter()
{
wxHelpProvider::Set( new wxSimpleHelpProvider );
}
};

static wxFBContextSensitiveHelpSetter s_wxFBSetTheHelpProvider;
///////////////////////////////////////////////////////////////////////////

GUI_MainFrame::GUI_MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetExtraStyle( wxFRAME_EX_METAL );
	
	wxBoxSizer* containerSizer;
	containerSizer = new wxBoxSizer( wxVERTICAL );
	
	m_mainPanel = new wxPanel( this, MAIN_PANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_mainPanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	
	wxBoxSizer* panelContainerSizer;
	panelContainerSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* headerSizer;
	headerSizer = new wxFlexGridSizer( 1, 2, 0, 0 );
	headerSizer->AddGrowableCol( 0 );
	headerSizer->SetFlexibleDirection( wxBOTH );
	headerSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* headerTextSizer;
	headerTextSizer = new wxFlexGridSizer( 2, 2, 0, 0 );
	headerTextSizer->AddGrowableCol( 1 );
	headerTextSizer->SetFlexibleDirection( wxBOTH );
	headerTextSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_currentCommitteeLabel = new wxStaticText( m_mainPanel, wxID_ANY, _("Committee:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_currentCommitteeLabel->Wrap( -1 );
	m_currentCommitteeLabel->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	headerTextSizer->Add( m_currentCommitteeLabel, 0, wxALL, 5 );
	
	m_currentCommitteeText = new wxStaticText( m_mainPanel, CURRENT_COMMITTEE, _("awaiting user input"), wxDefaultPosition, wxDefaultSize, 0 );
	m_currentCommitteeText->Wrap( -1 );
	m_currentCommitteeText->SetFont( wxFont( 12, 74, 93, 90, false, wxT("Sans") ) );
	
	headerTextSizer->Add( m_currentCommitteeText, 0, wxALL|wxEXPAND, 5 );
	
	m_currentTopicLabel = new wxStaticText( m_mainPanel, wxID_ANY, _("Current topic:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_currentTopicLabel->Wrap( -1 );
	m_currentTopicLabel->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	headerTextSizer->Add( m_currentTopicLabel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_currentTopicText = new wxStaticText( m_mainPanel, CURRENT_TOPIC, _("awaiting user input"), wxDefaultPosition, wxDefaultSize, 0 );
	m_currentTopicText->Wrap( -1 );
	m_currentTopicText->SetFont( wxFont( 12, 74, 93, 90, false, wxT("Sans") ) );
	
	headerTextSizer->Add( m_currentTopicText, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText67 = new wxStaticText( m_mainPanel, wxID_ANY, _("Present:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText67->Wrap( -1 );
	m_staticText67->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	headerTextSizer->Add( m_staticText67, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxVERTICAL );
	
	m_presentText = new wxStaticText( m_mainPanel, MEMBERS_PRESENT, _("0 / 0  (1/2 = 0; 2/3 = 0)"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_presentText->Wrap( -1 );
	m_presentText->SetFont( wxFont( 12, 74, 90, 90, false, wxT("Sans") ) );
	
	bSizer67->Add( m_presentText, 0, wxALL|wxEXPAND, 5 );
	
	m_noMembersPresentStaticText = new wxStaticText( m_mainPanel, NO_MEMBERS_PRESENT_TEXT, _("There are currently no members present!"), wxDefaultPosition, wxDefaultSize, 0 );
	m_noMembersPresentStaticText->Wrap( -1 );
	m_noMembersPresentStaticText->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	m_noMembersPresentStaticText->SetForegroundColour( wxColour( 187, 14, 14 ) );
	m_noMembersPresentStaticText->Hide();
	
	bSizer67->Add( m_noMembersPresentStaticText, 0, wxALL, 5 );
	
	headerTextSizer->Add( bSizer67, 1, wxEXPAND, 5 );
	
	headerSizer->Add( headerTextSizer, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_logoBitmap = new wxStaticBitmap( m_mainPanel, LOGO_BITMAP, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	headerSizer->Add( m_logoBitmap, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	panelContainerSizer->Add( headerSizer, 0, wxEXPAND|wxTOP, 5 );
	
	m_staticline1 = new wxStaticLine( m_mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	panelContainerSizer->Add( m_staticline1, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	m_mainauinotebook = new wxAuiNotebook( m_mainPanel, MUN_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_TAB_FIXED_WIDTH|wxAUI_NB_TAB_MOVE|wxAUI_NB_WINDOWLIST_BUTTON );
	m_GSLpanel = new wxPanel( m_mainauinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* GSLcontainerSizer;
	GSLcontainerSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_GSLsplitter = new wxSplitterWindow( m_GSLpanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DSASH|wxSP_BORDER|wxSP_LIVE_UPDATE );
	m_GSLsplitter->SetSashGravity( 1 );
	m_GSLsplitter->SetMinimumPaneSize( 400 );
	m_GSLsplitter->Connect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_GSLsplitterOnIdle ), NULL, this );
	m_GSLleftpanel = new wxPanel( m_GSLsplitter, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* GSLTimerSizer;
	GSLTimerSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12121;
	fgSizer12121 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12121->SetFlexibleDirection( wxBOTH );
	fgSizer12121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	GSLTimerSizer->Add( fgSizer12121, 1, wxEXPAND, 5 );
	
	wxBoxSizer* GSLCountrySizer;
	GSLCountrySizer = new wxBoxSizer( wxVERTICAL );
	
	m_GSLCountryPanel = new wxPanel( m_GSLleftpanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer41111;
	bSizer41111 = new wxBoxSizer( wxVERTICAL );
	
	m_GSLCountryFlag = new wxStaticBitmap( m_GSLCountryPanel, GSL_SPEAKER_FLAG, wxNullBitmap, wxDefaultPosition, wxSize( 150,100 ), 0 );
	m_GSLCountryFlag->SetMinSize( wxSize( 150,100 ) );
	m_GSLCountryFlag->SetMaxSize( wxSize( 150,100 ) );
	
	bSizer41111->Add( m_GSLCountryFlag, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GSLSpeaker = new wxStaticText( m_GSLCountryPanel, GSL_SPEAKER, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE|wxFULL_REPAINT_ON_RESIZE );
	m_GSLSpeaker->Wrap( -1 );
	m_GSLSpeaker->SetFont( wxFont( 17, 74, 90, 92, false, wxT("Sans") ) );
	m_GSLSpeaker->SetMinSize( wxSize( -1,30 ) );
	
	bSizer41111->Add( m_GSLSpeaker, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GSLCountryPanel->SetSizer( bSizer41111 );
	m_GSLCountryPanel->Layout();
	bSizer41111->Fit( m_GSLCountryPanel );
	GSLCountrySizer->Add( m_GSLCountryPanel, 1, wxEXPAND | wxALL, 5 );
	
	GSLTimerSizer->Add( GSLCountrySizer, 0, wxEXPAND, 5 );
	
	m_GSLSpeechGauge = new wxGauge( m_GSLleftpanel, GSL_GAUGE, 30, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	GSLTimerSizer->Add( m_GSLSpeechGauge, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* GSLtimeleftSizer;
	GSLtimeleftSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_GSL_timeleft = new wxStaticText( m_GSLleftpanel, GSL_TIME_LEFT, _("00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GSL_timeleft->Wrap( -1 );
	m_GSL_timeleft->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	GSLtimeleftSizer->Add( m_GSL_timeleft, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GSLtimesep = new wxStaticText( m_GSLleftpanel, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLtimesep->Wrap( -1 );
	m_GSLtimesep->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	GSLtimeleftSizer->Add( m_GSLtimesep, 0, wxALL, 5 );
	
	m_GSLtotaltime = new wxStaticText( m_GSLleftpanel, GSL_TOTAL_TIME, _("00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLtotaltime->Wrap( -1 );
	m_GSLtotaltime->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	GSLtimeleftSizer->Add( m_GSLtotaltime, 0, wxALL, 5 );
	
	GSLTimerSizer->Add( GSLtimeleftSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer1221;
	fgSizer1221 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1221->SetFlexibleDirection( wxBOTH );
	fgSizer1221->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	GSLTimerSizer->Add( fgSizer1221, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GSLYieldButton = new wxButton( m_GSLleftpanel, GSL_YIELD, _("&Yield to delegate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLYieldButton->Enable( false );
	
	bSizer72->Add( m_GSLYieldButton, 0, wxALL, 5 );
	
	m_GSLNext = new wxButton( m_GSLleftpanel, GSL_NEXT, _("&Next speaker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLNext->Enable( false );
	m_GSLNext->SetToolTip( _("Start the next speaker. You can also double-click the list.") );
	
	bSizer72->Add( m_GSLNext, 0, wxALL, 5 );
	
	bSizer87->Add( bSizer72, 1, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GSLResumeButton = new wxButton( m_GSLleftpanel, RESUME_GSL, _("&Resume"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLResumeButton->Enable( false );
	
	bSizer71->Add( m_GSLResumeButton, 0, wxALL, 5 );
	
	m_GSLPauseButton = new wxButton( m_GSLleftpanel, PAUSE_GSL, _("&Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLPauseButton->Enable( false );
	
	bSizer71->Add( m_GSLPauseButton, 0, wxALL, 5 );
	
	m_GSLStopButton = new wxButton( m_GSLleftpanel, wxID_STOP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLStopButton->SetToolTip( _("Stop the current speaker") );
	
	bSizer71->Add( m_GSLStopButton, 0, wxALL, 5 );
	
	bSizer87->Add( bSizer71, 1, wxEXPAND, 5 );
	
	GSLTimerSizer->Add( bSizer87, 0, wxALIGN_RIGHT, 5 );
	
	m_GSLleftpanel->SetSizer( GSLTimerSizer );
	m_GSLleftpanel->Layout();
	GSLTimerSizer->Fit( m_GSLleftpanel );
	m_GSLrightpanel = new wxPanel( m_GSLsplitter, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* GSLlistSizer;
	GSLlistSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* GSLtimesetsizer;
	GSLtimesetsizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_GSLtimeText = new wxStaticText( m_GSLrightpanel, wxID_ANY, _("Set speaker time:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLtimeText->Wrap( -1 );
	GSLtimesetsizer->Add( m_GSLtimeText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GSLminutesSpinCtrl = new wxSpinCtrl( m_GSLrightpanel, GSL_SPEAKER_TIME_MINUTES, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	m_GSLminutesSpinCtrl->SetMaxSize( wxSize( 80,-1 ) );
	
	bSizer73->Add( m_GSLminutesSpinCtrl, 0, wxALL, 5 );
	
	m_GSLsecondsSpinCtrl = new wxSpinCtrl( m_GSLrightpanel, GSL_SPEAKER_TIME_SECONDS, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, -1, 60, 0 );
	m_GSLsecondsSpinCtrl->SetMaxSize( wxSize( 80,-1 ) );
	
	bSizer73->Add( m_GSLsecondsSpinCtrl, 0, wxALL, 5 );
	
	GSLtimesetsizer->Add( bSizer73, 0, 0, 5 );
	
	GSLlistSizer->Add( GSLtimesetsizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline152 = new wxStaticLine( m_GSLrightpanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	GSLlistSizer->Add( m_staticline152, 0, wxALL|wxEXPAND, 5 );
	
	wxArrayString m_GSLChoiceChoices;
	m_GSLChoice = new wxChoice( m_GSLrightpanel, GSL_CHOICES, wxDefaultPosition, wxSize( 370,-1 ), m_GSLChoiceChoices, 0 );
	m_GSLChoice->SetSelection( 0 );
	m_GSLChoice->SetToolTip( _("Add country") );
	m_GSLChoice->SetMaxSize( wxSize( 370,-1 ) );
	
	GSLlistSizer->Add( m_GSLChoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GSLList = new wxListBox( m_GSLrightpanel, GSL_LIST, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_GSLList->SetToolTip( _("Current list of countries on the General Speakers List") );
	
	GSLlistSizer->Add( m_GSLList, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* GSLButtonSizer;
	GSLButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_GSLUpButton = new wxButton( m_GSLrightpanel, wxID_UP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLUpButton->SetToolTip( _("Move the selected country higher on the list") );
	
	GSLButtonSizer->Add( m_GSLUpButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GSLDownButton = new wxButton( m_GSLrightpanel, wxID_DOWN, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLDownButton->SetToolTip( _("Move the selected country lower on the list") );
	
	GSLButtonSizer->Add( m_GSLDownButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GSLDeleteButton = new wxButton( m_GSLrightpanel, wxID_DELETE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_GSLDeleteButton->SetToolTip( _("Remove the selected country from the list") );
	
	GSLButtonSizer->Add( m_GSLDeleteButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GSLClearButton = new wxButton( m_GSLrightpanel, wxID_CLEAR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	GSLButtonSizer->Add( m_GSLClearButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	GSLlistSizer->Add( GSLButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GSLrightpanel->SetSizer( GSLlistSizer );
	m_GSLrightpanel->Layout();
	GSLlistSizer->Fit( m_GSLrightpanel );
	m_GSLsplitter->SplitVertically( m_GSLleftpanel, m_GSLrightpanel, 800 );
	GSLcontainerSizer->Add( m_GSLsplitter, 1, wxEXPAND, 5 );
	
	m_GSLpanel->SetSizer( GSLcontainerSizer );
	m_GSLpanel->Layout();
	GSLcontainerSizer->Fit( m_GSLpanel );
	m_mainauinotebook->AddPage( m_GSLpanel, _("General Speakers List"), true, wxNullBitmap );
	m_singleSpeakerPanel = new wxPanel( m_mainauinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_singleSpeakerPanel->Hide();
	m_singleSpeakerPanel->SetToolTip( _("The single speaker tab can be used in conjuction with the GSL, to deal with a yield to questions or handle comments.") );
	
	wxBoxSizer* singleSpeakerCaucusContainerSizer;
	singleSpeakerCaucusContainerSizer = new wxBoxSizer( wxVERTICAL );
	
	m_singleSpeakerCaucusSplitter = new wxSplitterWindow( m_singleSpeakerPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DSASH|wxSP_BORDER|wxSP_LIVE_UPDATE );
	m_singleSpeakerCaucusSplitter->SetSashGravity( 1 );
	m_singleSpeakerCaucusSplitter->SetMinimumPaneSize( 400 );
	m_singleSpeakerCaucusSplitter->Connect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_singleSpeakerCaucusSplitterOnIdle ), NULL, this );
	m_singleSpeakerCaucusLeftPanel = new wxPanel( m_singleSpeakerCaucusSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* singleSpeakerTimerSizer;
	singleSpeakerTimerSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer191;
	fgSizer191 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer191->SetFlexibleDirection( wxBOTH );
	fgSizer191->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	singleSpeakerTimerSizer->Add( fgSizer191, 1, 0, 5 );
	
	wxBoxSizer* singleSpeakerCountryTimerSizer;
	singleSpeakerCountryTimerSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* singleSpeakerSpeakerSizer;
	singleSpeakerSpeakerSizer = new wxBoxSizer( wxVERTICAL );
	
	m_panel611 = new wxPanel( m_singleSpeakerCaucusLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4112;
	bSizer4112 = new wxBoxSizer( wxVERTICAL );
	
	m_singleSpeakerCountryFlag = new wxStaticBitmap( m_panel611, SINGLE_SPEAKER_FLAG, wxNullBitmap, wxDefaultPosition, wxSize( 150,100 ), 0 );
	m_singleSpeakerCountryFlag->SetMinSize( wxSize( 150,100 ) );
	m_singleSpeakerCountryFlag->SetMaxSize( wxSize( 150,100 ) );
	
	bSizer4112->Add( m_singleSpeakerCountryFlag, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_singleSpeakerName = new wxStaticText( m_panel611, SINGLE_SPEAKER_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE|wxFULL_REPAINT_ON_RESIZE );
	m_singleSpeakerName->Wrap( -1 );
	m_singleSpeakerName->SetFont( wxFont( 17, 74, 90, 92, false, wxT("Sans") ) );
	m_singleSpeakerName->SetMinSize( wxSize( -1,30 ) );
	
	bSizer4112->Add( m_singleSpeakerName, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panel611->SetSizer( bSizer4112 );
	m_panel611->Layout();
	bSizer4112->Fit( m_panel611 );
	singleSpeakerSpeakerSizer->Add( m_panel611, 1, wxEXPAND | wxALL, 5 );
	
	singleSpeakerCountryTimerSizer->Add( singleSpeakerSpeakerSizer, 1, wxEXPAND, 5 );
	
	m_singleSpeakerTimeGauge = new wxGauge( m_singleSpeakerCaucusLeftPanel, SINGLE_SPEAKER_GAUGE, 30, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL|wxFULL_REPAINT_ON_RESIZE );
	singleSpeakerCountryTimerSizer->Add( m_singleSpeakerTimeGauge, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* singleSpeakerTimeleftSizer;
	singleSpeakerTimeleftSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_singleSpeakerTimeleft = new wxStaticText( m_singleSpeakerCaucusLeftPanel, SINGLE_SPEAKER_TIME_LEFT, _("00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_singleSpeakerTimeleft->Wrap( -1 );
	m_singleSpeakerTimeleft->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	singleSpeakerTimeleftSizer->Add( m_singleSpeakerTimeleft, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_timesep111 = new wxStaticText( m_singleSpeakerCaucusLeftPanel, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_timesep111->Wrap( -1 );
	m_timesep111->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	singleSpeakerTimeleftSizer->Add( m_timesep111, 0, wxALL, 5 );
	
	m_totaltime111 = new wxStaticText( m_singleSpeakerCaucusLeftPanel, SINGLE_SPEAKER_TOTAL_TIME, _("00:30"), wxDefaultPosition, wxDefaultSize, 0 );
	m_totaltime111->Wrap( -1 );
	m_totaltime111->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	singleSpeakerTimeleftSizer->Add( m_totaltime111, 0, wxALL, 5 );
	
	singleSpeakerCountryTimerSizer->Add( singleSpeakerTimeleftSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	singleSpeakerTimerSizer->Add( singleSpeakerCountryTimerSizer, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	singleSpeakerTimerSizer->Add( 0, 20, 0, 0, 5 );
	
	wxBoxSizer* bSizer911;
	bSizer911 = new wxBoxSizer( wxVERTICAL );
	
	singleSpeakerTimerSizer->Add( bSizer911, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer861;
	bSizer861 = new wxBoxSizer( wxHORIZONTAL );
	
	m_stopSingleSpeakerButton = new wxButton( m_singleSpeakerCaucusLeftPanel, wxID_STOP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer861->Add( m_stopSingleSpeakerButton, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	singleSpeakerTimerSizer->Add( bSizer861, 0, wxALIGN_RIGHT, 5 );
	
	m_singleSpeakerCaucusLeftPanel->SetSizer( singleSpeakerTimerSizer );
	m_singleSpeakerCaucusLeftPanel->Layout();
	singleSpeakerTimerSizer->Fit( m_singleSpeakerCaucusLeftPanel );
	m_singleSpeakerRightPanel = new wxPanel( m_singleSpeakerCaucusSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* modCaucusRightSizer1;
	modCaucusRightSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1011 = new wxStaticText( m_singleSpeakerRightPanel, wxID_ANY, _("Single speaker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1011->Wrap( -1 );
	m_staticText1011->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	
	modCaucusRightSizer1->Add( m_staticText1011, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline1411 = new wxStaticLine( m_singleSpeakerRightPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	modCaucusRightSizer1->Add( m_staticline1411, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* newModfgSizer1;
	newModfgSizer1 = new wxFlexGridSizer( 8, 2, 0, 0 );
	newModfgSizer1->AddGrowableCol( 1 );
	newModfgSizer1->AddGrowableRow( 0 );
	newModfgSizer1->SetFlexibleDirection( wxBOTH );
	newModfgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_STlabel11 = new wxStaticText( m_singleSpeakerRightPanel, wxID_ANY, _("Set speaker time:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_STlabel11->Wrap( -1 );
	newModfgSizer1->Add( m_STlabel11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* speakerTimeSizer11;
	speakerTimeSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_singleSpeakerMinutes = new wxSpinCtrl( m_singleSpeakerRightPanel, SINGLE_SPEAKER_MINUTES, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	m_singleSpeakerMinutes->SetToolTip( _("Minutes") );
	m_singleSpeakerMinutes->SetMaxSize( wxSize( 80,-1 ) );
	
	speakerTimeSizer11->Add( m_singleSpeakerMinutes, 0, wxALL, 5 );
	
	m_singleSpeakerSeconds = new wxSpinCtrl( m_singleSpeakerRightPanel, SINGLE_SPEAKER_SECONDS, wxT("30"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, -1, 60, 30 );
	m_singleSpeakerSeconds->SetToolTip( _("Seconds") );
	m_singleSpeakerSeconds->SetMaxSize( wxSize( 80,-1 ) );
	
	speakerTimeSizer11->Add( m_singleSpeakerSeconds, 0, wxALL, 5 );
	
	newModfgSizer1->Add( speakerTimeSizer11, 1, wxEXPAND, 5 );
	
	modCaucusRightSizer1->Add( newModfgSizer1, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer531;
	bSizer531 = new wxBoxSizer( wxVERTICAL );
	
	m_singleSpeakerCountryListBox = new wxListBox( m_singleSpeakerRightPanel, SINGLE_SPEAKER_CHOICES, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	m_singleSpeakerCountryListBox->Enable( false );
	
	bSizer531->Add( m_singleSpeakerCountryListBox, 1, wxALL|wxEXPAND, 5 );
	
	modCaucusRightSizer1->Add( bSizer531, 1, wxEXPAND, 5 );
	
	m_singleSpeakerRightPanel->SetSizer( modCaucusRightSizer1 );
	m_singleSpeakerRightPanel->Layout();
	modCaucusRightSizer1->Fit( m_singleSpeakerRightPanel );
	m_singleSpeakerCaucusSplitter->SplitVertically( m_singleSpeakerCaucusLeftPanel, m_singleSpeakerRightPanel, 576 );
	singleSpeakerCaucusContainerSizer->Add( m_singleSpeakerCaucusSplitter, 1, wxEXPAND, 5 );
	
	m_singleSpeakerPanel->SetSizer( singleSpeakerCaucusContainerSizer );
	m_singleSpeakerPanel->Layout();
	singleSpeakerCaucusContainerSizer->Fit( m_singleSpeakerPanel );
	m_mainauinotebook->AddPage( m_singleSpeakerPanel, _("Single speaker"), false, wxNullBitmap );
	m_modCaucusPanel = new wxPanel( m_mainauinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* modCaucusContainerSizer;
	modCaucusContainerSizer = new wxBoxSizer( wxVERTICAL );
	
	m_modCaucusSplitter = new wxSplitterWindow( m_modCaucusPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DSASH|wxSP_BORDER|wxSP_LIVE_UPDATE );
	m_modCaucusSplitter->SetSashGravity( 1 );
	m_modCaucusSplitter->SetMinimumPaneSize( 400 );
	m_modCaucusSplitter->Connect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_modCaucusSplitterOnIdle ), NULL, this );
	m_modCaucusLeftPanel = new wxPanel( m_modCaucusSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* modCaucusTimerSizer;
	modCaucusTimerSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	modCaucusTimerSizer->Add( fgSizer19, 1, 0, 5 );
	
	wxBoxSizer* countryTimerSizer;
	countryTimerSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* modCaucusSpeakerSizer;
	modCaucusSpeakerSizer = new wxBoxSizer( wxVERTICAL );
	
	m_panel61 = new wxPanel( m_modCaucusLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer411;
	bSizer411 = new wxBoxSizer( wxVERTICAL );
	
	m_modCaucusCountryFlag = new wxStaticBitmap( m_panel61, MOD_CAUCUS_SPEAKER_FLAG, wxNullBitmap, wxDefaultPosition, wxSize( 150,100 ), 0 );
	m_modCaucusCountryFlag->SetMinSize( wxSize( 150,100 ) );
	m_modCaucusCountryFlag->SetMaxSize( wxSize( 150,100 ) );
	
	bSizer411->Add( m_modCaucusCountryFlag, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_modCaucusSpeaker = new wxStaticText( m_panel61, MOD_CAUCUS_SPEAKER, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE|wxFULL_REPAINT_ON_RESIZE );
	m_modCaucusSpeaker->Wrap( -1 );
	m_modCaucusSpeaker->SetFont( wxFont( 17, 74, 90, 92, false, wxT("Sans") ) );
	m_modCaucusSpeaker->SetMinSize( wxSize( -1,30 ) );
	
	bSizer411->Add( m_modCaucusSpeaker, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panel61->SetSizer( bSizer411 );
	m_panel61->Layout();
	bSizer411->Fit( m_panel61 );
	modCaucusSpeakerSizer->Add( m_panel61, 1, wxEXPAND | wxALL, 5 );
	
	countryTimerSizer->Add( modCaucusSpeakerSizer, 1, wxEXPAND, 5 );
	
	m_modCaucusSpeakerTimeGauge = new wxGauge( m_modCaucusLeftPanel, MOD_CAUCUS_SPEAKER_GAUGE, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL|wxFULL_REPAINT_ON_RESIZE );
	countryTimerSizer->Add( m_modCaucusSpeakerTimeGauge, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* modCaucusTimeleftSizer1;
	modCaucusTimeleftSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_modCaucustimeleft1 = new wxStaticText( m_modCaucusLeftPanel, MOD_CAUCUS_SPEAKER_TIME_LEFT, _("00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_modCaucustimeleft1->Wrap( -1 );
	m_modCaucustimeleft1->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	modCaucusTimeleftSizer1->Add( m_modCaucustimeleft1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_timesep11 = new wxStaticText( m_modCaucusLeftPanel, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_timesep11->Wrap( -1 );
	m_timesep11->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	modCaucusTimeleftSizer1->Add( m_timesep11, 0, wxALL, 5 );
	
	m_totaltime11 = new wxStaticText( m_modCaucusLeftPanel, MOD_CAUCUS_TOTAL_SPEAKER_TIME, _("00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_totaltime11->Wrap( -1 );
	m_totaltime11->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	modCaucusTimeleftSizer1->Add( m_totaltime11, 0, wxALL, 5 );
	
	countryTimerSizer->Add( modCaucusTimeleftSizer1, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	modCaucusTimerSizer->Add( countryTimerSizer, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	modCaucusTimerSizer->Add( 0, 20, 0, 0, 5 );
	
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );
	
	modCaucusTimerSizer->Add( bSizer91, 1, wxEXPAND, 5 );
	
	wxBoxSizer* caucusTimerSizer;
	caucusTimerSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* modCaucusTopicSizer;
	modCaucusTopicSizer = new wxBoxSizer( wxVERTICAL );
	
	m_panel62 = new wxPanel( m_modCaucusLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer412;
	bSizer412 = new wxBoxSizer( wxVERTICAL );
	
	m_modCaucusTopic = new wxStaticText( m_panel62, MOD_CAUCUS_TOPIC, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE );
	m_modCaucusTopic->Wrap( -1 );
	m_modCaucusTopic->SetFont( wxFont( 16, 74, 93, 90, false, wxT("Sans") ) );
	m_modCaucusTopic->SetMinSize( wxSize( -1,30 ) );
	
	bSizer412->Add( m_modCaucusTopic, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panel62->SetSizer( bSizer412 );
	m_panel62->Layout();
	bSizer412->Fit( m_panel62 );
	modCaucusTopicSizer->Add( m_panel62, 1, wxEXPAND | wxALL, 5 );
	
	caucusTimerSizer->Add( modCaucusTopicSizer, 1, wxEXPAND, 5 );
	
	m_modCaucusTimeGauge = new wxGauge( m_modCaucusLeftPanel, MOD_CAUCUS_GAUGE, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	caucusTimerSizer->Add( m_modCaucusTimeGauge, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* modCaucusTimeleftSizer;
	modCaucusTimeleftSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_modCaucustimeleft = new wxStaticText( m_modCaucusLeftPanel, MOD_CAUCUS_TIME_LEFT, _("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_modCaucustimeleft->Wrap( -1 );
	m_modCaucustimeleft->SetFont( wxFont( 22, 74, 90, 92, false, wxT("Sans") ) );
	
	modCaucusTimeleftSizer->Add( m_modCaucustimeleft, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_timesep1 = new wxStaticText( m_modCaucusLeftPanel, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_timesep1->Wrap( -1 );
	m_timesep1->SetFont( wxFont( 22, 74, 90, 92, false, wxT("Sans") ) );
	
	modCaucusTimeleftSizer->Add( m_timesep1, 0, wxALL, 5 );
	
	m_totaltime1 = new wxStaticText( m_modCaucusLeftPanel, MOD_CAUCUS_TOTAL_TIME, _("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_totaltime1->Wrap( -1 );
	m_totaltime1->SetFont( wxFont( 22, 74, 90, 92, false, wxT("Sans") ) );
	
	modCaucusTimeleftSizer->Add( m_totaltime1, 0, wxALL, 5 );
	
	caucusTimerSizer->Add( modCaucusTimeleftSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	modCaucusTimerSizer->Add( caucusTimerSizer, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxHORIZONTAL );
	
	m_resumeModCaucus = new wxButton( m_modCaucusLeftPanel, RESUME_MOD_CAUCUS, _("&Resume"), wxDefaultPosition, wxDefaultSize, 0 );
	m_resumeModCaucus->Enable( false );
	
	bSizer86->Add( m_resumeModCaucus, 0, wxALL, 5 );
	
	m_pauseModCaucus = new wxButton( m_modCaucusLeftPanel, PAUSE_MOD_CAUCUS, _("&Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer86->Add( m_pauseModCaucus, 0, wxALL, 5 );
	
	m_stopModCaucusButton1 = new wxButton( m_modCaucusLeftPanel, wxID_STOP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer86->Add( m_stopModCaucusButton1, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	modCaucusTimerSizer->Add( bSizer86, 0, wxALIGN_RIGHT, 5 );
	
	m_modCaucusLeftPanel->SetSizer( modCaucusTimerSizer );
	m_modCaucusLeftPanel->Layout();
	modCaucusTimerSizer->Fit( m_modCaucusLeftPanel );
	m_modCaucusRightPanel = new wxPanel( m_modCaucusSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* modCaucusRightSizer;
	modCaucusRightSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticText101 = new wxStaticText( m_modCaucusRightPanel, wxID_ANY, _("Start a new moderated caucus"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	m_staticText101->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	
	modCaucusRightSizer->Add( m_staticText101, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline141 = new wxStaticLine( m_modCaucusRightPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	modCaucusRightSizer->Add( m_staticline141, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* newModfgSizer;
	newModfgSizer = new wxFlexGridSizer( 8, 2, 0, 0 );
	newModfgSizer->AddGrowableCol( 1 );
	newModfgSizer->AddGrowableRow( 0 );
	newModfgSizer->SetFlexibleDirection( wxBOTH );
	newModfgSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText41 = new wxStaticText( m_modCaucusRightPanel, wxID_ANY, _("Topic"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	newModfgSizer->Add( m_staticText41, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_mod_caucus_topic = new wxTextCtrl( m_modCaucusRightPanel, NEW_MOD_CAUCUS_TOPIC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	newModfgSizer->Add( m_mod_caucus_topic, 1, wxALL|wxEXPAND, 5 );
	
	m_durationText1 = new wxStaticText( m_modCaucusRightPanel, wxID_ANY, _("Duration"), wxDefaultPosition, wxDefaultSize, 0 );
	m_durationText1->Wrap( -1 );
	newModfgSizer->Add( m_durationText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* durationSizer1;
	durationSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_mod_caucus_durationHours = new wxSpinCtrl( m_modCaucusRightPanel, NEW_MOD_CAUCUS_HOURS, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 99, 0 );
	m_mod_caucus_durationHours->SetToolTip( _("Hours") );
	m_mod_caucus_durationHours->SetMaxSize( wxSize( 80,-1 ) );
	
	durationSizer1->Add( m_mod_caucus_durationHours, 0, wxALL, 5 );
	
	m_mod_caucus_durationMinutes = new wxSpinCtrl( m_modCaucusRightPanel, NEW_MOD_CAUCUS_MINUTES, wxT("5"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, -1, 60, 5 );
	m_mod_caucus_durationMinutes->SetToolTip( _("Minutes") );
	m_mod_caucus_durationMinutes->SetMaxSize( wxSize( 80,-1 ) );
	
	durationSizer1->Add( m_mod_caucus_durationMinutes, 0, wxALL, 5 );
	
	m_mod_caucus_durationSeconds = new wxSpinCtrl( m_modCaucusRightPanel, NEW_MOD_CAUCUS_SECONDS, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, -1, 60, 0 );
	m_mod_caucus_durationSeconds->SetToolTip( _("Seconds") );
	m_mod_caucus_durationSeconds->SetMaxSize( wxSize( 80,-1 ) );
	
	durationSizer1->Add( m_mod_caucus_durationSeconds, 0, wxALL, 5 );
	
	newModfgSizer->Add( durationSizer1, 1, 0, 5 );
	
	m_STlabel1 = new wxStaticText( m_modCaucusRightPanel, wxID_ANY, _("Time per speaker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_STlabel1->Wrap( -1 );
	newModfgSizer->Add( m_STlabel1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* speakerTimeSizer1;
	speakerTimeSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_mod_caucus_STminutes = new wxSpinCtrl( m_modCaucusRightPanel, NEW_MOD_CAUCUS_ST_MINUTES, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	m_mod_caucus_STminutes->SetToolTip( _("Minutes") );
	m_mod_caucus_STminutes->SetMaxSize( wxSize( 80,-1 ) );
	
	speakerTimeSizer1->Add( m_mod_caucus_STminutes, 0, wxALL, 5 );
	
	m_mod_caucus_STseconds = new wxSpinCtrl( m_modCaucusRightPanel, NEW_MOD_CAUCUS_ST_SECONDS, wxT("30"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, -1, 60, 30 );
	m_mod_caucus_STseconds->SetToolTip( _("Seconds") );
	m_mod_caucus_STseconds->SetMaxSize( wxSize( 80,-1 ) );
	
	speakerTimeSizer1->Add( m_mod_caucus_STseconds, 0, wxALL, 5 );
	
	newModfgSizer->Add( speakerTimeSizer1, 1, wxEXPAND, 5 );
	
	m_stopModCaucusButton11 = new wxButton( m_modCaucusRightPanel, wxID_STOP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	newModfgSizer->Add( m_stopModCaucusButton11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );
	
	m_modCaucus_sdbSizer = new wxStdDialogButtonSizer();
	m_modCaucus_sdbSizerOK = new wxButton( m_modCaucusRightPanel, wxID_OK );
	m_modCaucus_sdbSizer->AddButton( m_modCaucus_sdbSizerOK );
	m_modCaucus_sdbSizerCancel = new wxButton( m_modCaucusRightPanel, wxID_CANCEL );
	m_modCaucus_sdbSizer->AddButton( m_modCaucus_sdbSizerCancel );
	m_modCaucus_sdbSizer->Realize();
	bSizer65->Add( m_modCaucus_sdbSizer, 0, wxEXPAND|wxALL, 5 );
	
	newModfgSizer->Add( bSizer65, 1, wxALIGN_RIGHT, 5 );
	
	modCaucusRightSizer->Add( newModfgSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline151 = new wxStaticLine( m_modCaucusRightPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	modCaucusRightSizer->Add( m_staticline151, 0, wxEXPAND | wxALL, 5 );
	
	m_modCaucusCountryListBox = new wxListBox( m_modCaucusRightPanel, MOD_CAUCUS_CHOICES, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	m_modCaucusCountryListBox->Enable( false );
	
	modCaucusRightSizer->Add( m_modCaucusCountryListBox, 1, wxALL|wxEXPAND, 5 );
	
	m_modCaucusRightPanel->SetSizer( modCaucusRightSizer );
	m_modCaucusRightPanel->Layout();
	modCaucusRightSizer->Fit( m_modCaucusRightPanel );
	m_modCaucusSplitter->SplitVertically( m_modCaucusLeftPanel, m_modCaucusRightPanel, 576 );
	modCaucusContainerSizer->Add( m_modCaucusSplitter, 1, wxEXPAND, 5 );
	
	m_modCaucusPanel->SetSizer( modCaucusContainerSizer );
	m_modCaucusPanel->Layout();
	modCaucusContainerSizer->Fit( m_modCaucusPanel );
	m_mainauinotebook->AddPage( m_modCaucusPanel, _("Moderated Caucus"), false, wxNullBitmap );
	m_unModCaucusPanel = new wxPanel( m_mainauinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* unmodCaucusContainerSizer;
	unmodCaucusContainerSizer = new wxBoxSizer( wxVERTICAL );
	
	m_unModCaucusSplitter = new wxSplitterWindow( m_unModCaucusPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DSASH|wxSP_BORDER|wxSP_LIVE_UPDATE );
	m_unModCaucusSplitter->SetSashGravity( 1 );
	m_unModCaucusSplitter->SetMinimumPaneSize( 400 );
	m_unModCaucusSplitter->Connect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_unModCaucusSplitterOnIdle ), NULL, this );
	m_unModCaucusLeftPanel = new wxPanel( m_unModCaucusSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* unModCaucusTimerSizer;
	unModCaucusTimerSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer121;
	fgSizer121 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer121->SetFlexibleDirection( wxBOTH );
	fgSizer121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	unModCaucusTimerSizer->Add( fgSizer121, 1, wxEXPAND, 5 );
	
	wxBoxSizer* unModCaucusTopicSizer;
	unModCaucusTopicSizer = new wxBoxSizer( wxVERTICAL );
	
	m_panel6 = new wxPanel( m_unModCaucusLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );
	
	m_unModCaucusTopic = new wxStaticText( m_panel6, UNMOD_CAUCUS_TOPIC, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE|wxFULL_REPAINT_ON_RESIZE );
	m_unModCaucusTopic->Wrap( -1 );
	m_unModCaucusTopic->SetFont( wxFont( 15, 74, 93, 90, false, wxT("Sans") ) );
	m_unModCaucusTopic->SetMinSize( wxSize( -1,30 ) );
	
	bSizer41->Add( m_unModCaucusTopic, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panel6->SetSizer( bSizer41 );
	m_panel6->Layout();
	bSizer41->Fit( m_panel6 );
	unModCaucusTopicSizer->Add( m_panel6, 1, wxEXPAND | wxALL, 5 );
	
	unModCaucusTimerSizer->Add( unModCaucusTopicSizer, 0, wxEXPAND, 5 );
	
	m_UnModCaucusTimeGauge = new wxGauge( m_unModCaucusLeftPanel, UNMOD_CAUCUS_GAUGE, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	unModCaucusTimerSizer->Add( m_UnModCaucusTimeGauge, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* timeleftSizer;
	timeleftSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_unmod_caucus_timeleft = new wxStaticText( m_unModCaucusLeftPanel, UNMOD_CAUCUS_TIME_LEFT, _("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_unmod_caucus_timeleft->Wrap( -1 );
	m_unmod_caucus_timeleft->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	timeleftSizer->Add( m_unmod_caucus_timeleft, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_timesep = new wxStaticText( m_unModCaucusLeftPanel, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_timesep->Wrap( -1 );
	m_timesep->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	timeleftSizer->Add( m_timesep, 0, wxALL, 5 );
	
	m_unmod_caucus_totaltime = new wxStaticText( m_unModCaucusLeftPanel, UNMOD_CAUCUS_TOTAL_TIME, _("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_unmod_caucus_totaltime->Wrap( -1 );
	m_unmod_caucus_totaltime->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	timeleftSizer->Add( m_unmod_caucus_totaltime, 0, wxALL, 5 );
	
	unModCaucusTimerSizer->Add( timeleftSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	unModCaucusTimerSizer->Add( fgSizer12, 1, wxEXPAND, 5 );
	
	m_stopUnModCaucusButton = new wxButton( m_unModCaucusLeftPanel, wxID_STOP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	unModCaucusTimerSizer->Add( m_stopUnModCaucusButton, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_unModCaucusLeftPanel->SetSizer( unModCaucusTimerSizer );
	m_unModCaucusLeftPanel->Layout();
	unModCaucusTimerSizer->Fit( m_unModCaucusLeftPanel );
	m_unModCaucusRightPanel = new wxPanel( m_unModCaucusSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* newUnModSizer;
	newUnModSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticText10 = new wxStaticText( m_unModCaucusRightPanel, wxID_ANY, _("Start a new unmoderated caucus"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	m_staticText10->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	
	newUnModSizer->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline14 = new wxStaticLine( m_unModCaucusRightPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	newUnModSizer->Add( m_staticline14, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* newUnModfgSizer;
	newUnModfgSizer = new wxFlexGridSizer( 8, 2, 0, 0 );
	newUnModfgSizer->AddGrowableCol( 1 );
	newUnModfgSizer->AddGrowableRow( 0 );
	newUnModfgSizer->SetFlexibleDirection( wxBOTH );
	newUnModfgSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( m_unModCaucusRightPanel, wxID_ANY, _("Topic"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	newUnModfgSizer->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_caucus_topic = new wxTextCtrl( m_unModCaucusRightPanel, NEW_UNMOD_CAUCUS_TOPIC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	newUnModfgSizer->Add( m_caucus_topic, 1, wxALL|wxEXPAND, 5 );
	
	m_durationText = new wxStaticText( m_unModCaucusRightPanel, wxID_ANY, _("Duration"), wxDefaultPosition, wxDefaultSize, 0 );
	m_durationText->Wrap( -1 );
	newUnModfgSizer->Add( m_durationText, 0, wxALL, 5 );
	
	wxBoxSizer* durationSizer;
	durationSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_durationHours = new wxSpinCtrl( m_unModCaucusRightPanel, NEW_UNMOD_CAUCUS_HOURS, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 100, 0 );
	m_durationHours->SetToolTip( _("Hours") );
	m_durationHours->SetMaxSize( wxSize( 80,-1 ) );
	
	durationSizer->Add( m_durationHours, 0, wxALL, 5 );
	
	m_durationMinutes = new wxSpinCtrl( m_unModCaucusRightPanel, NEW_UNMOD_CAUCUS_MINUTES, wxT("5"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, -1, 60, 5 );
	m_durationMinutes->SetToolTip( _("Minutes") );
	m_durationMinutes->SetMaxSize( wxSize( 80,-1 ) );
	
	durationSizer->Add( m_durationMinutes, 0, wxALL, 5 );
	
	m_durationSeconds = new wxSpinCtrl( m_unModCaucusRightPanel, NEW_UNMOD_CAUCUS_SECONDS, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, -1, 60, 0 );
	m_durationSeconds->SetToolTip( _("Seconds") );
	m_durationSeconds->SetMaxSize( wxSize( 80,-1 ) );
	
	durationSizer->Add( m_durationSeconds, 0, wxALL, 5 );
	
	newUnModfgSizer->Add( durationSizer, 1, wxEXPAND, 5 );
	
	m_stopUnModCaucusButton1 = new wxButton( m_unModCaucusRightPanel, wxID_STOP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	newUnModfgSizer->Add( m_stopUnModCaucusButton1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
	
	m_unmodCaucus_sdbSizer = new wxStdDialogButtonSizer();
	m_unmodCaucus_sdbSizerOK = new wxButton( m_unModCaucusRightPanel, wxID_OK );
	m_unmodCaucus_sdbSizer->AddButton( m_unmodCaucus_sdbSizerOK );
	m_unmodCaucus_sdbSizerCancel = new wxButton( m_unModCaucusRightPanel, wxID_CANCEL );
	m_unmodCaucus_sdbSizer->AddButton( m_unmodCaucus_sdbSizerCancel );
	m_unmodCaucus_sdbSizer->Realize();
	bSizer66->Add( m_unmodCaucus_sdbSizer, 1, wxALL|wxALIGN_RIGHT, 5 );
	
	newUnModfgSizer->Add( bSizer66, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	newUnModSizer->Add( newUnModfgSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline15 = new wxStaticLine( m_unModCaucusRightPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	newUnModSizer->Add( m_staticline15, 0, wxEXPAND | wxALL, 5 );
	
	m_unModCaucusRightPanel->SetSizer( newUnModSizer );
	m_unModCaucusRightPanel->Layout();
	newUnModSizer->Fit( m_unModCaucusRightPanel );
	m_unModCaucusSplitter->SplitVertically( m_unModCaucusLeftPanel, m_unModCaucusRightPanel, 576 );
	unmodCaucusContainerSizer->Add( m_unModCaucusSplitter, 1, wxEXPAND, 5 );
	
	m_unModCaucusPanel->SetSizer( unmodCaucusContainerSizer );
	m_unModCaucusPanel->Layout();
	unmodCaucusContainerSizer->Fit( m_unModCaucusPanel );
	m_mainauinotebook->AddPage( m_unModCaucusPanel, _("Unmoderated Caucus"), false, wxNullBitmap );
	m_procVotingPanel = new wxPanel( m_mainauinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* procVotingContainerSizer;
	procVotingContainerSizer = new wxBoxSizer( wxVERTICAL );
	
	m_procVotingSplitter = new wxSplitterWindow( m_procVotingPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DSASH|wxSP_BORDER|wxSP_LIVE_UPDATE );
	m_procVotingSplitter->SetSashGravity( 1 );
	m_procVotingSplitter->SetMinimumPaneSize( 400 );
	m_procVotingSplitter->Connect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_procVotingSplitterOnIdle ), NULL, this );
	m_procVotingLeftPanel = new wxPanel( m_procVotingSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* votingTimerSizer;
	votingTimerSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxVERTICAL );
	
	m_panel15 = new wxPanel( m_procVotingLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxVERTICAL );
	
	m_votingReason = new wxStaticText( m_panel15, VOTING_ON, _("Pick a reason to debate"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE );
	m_votingReason->Wrap( -1 );
	m_votingReason->SetFont( wxFont( 16, 74, 93, 90, false, wxT("Sans") ) );
	m_votingReason->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	
	bSizer93->Add( m_votingReason, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panel15->SetSizer( bSizer93 );
	m_panel15->Layout();
	bSizer93->Fit( m_panel15 );
	bSizer92->Add( m_panel15, 1, wxEXPAND | wxALL, 5 );
	
	votingTimerSizer->Add( bSizer92, 0, wxEXPAND, 5 );
	
	
	votingTimerSizer->Add( 0, 50, 0, 0, 5 );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	m_votingInFavourLabel = new wxStaticText( m_procVotingLeftPanel, VOTING_IN_FAVOUR, _("IN FAVOUR"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE|wxFULL_REPAINT_ON_RESIZE );
	m_votingInFavourLabel->Wrap( -1 );
	m_votingInFavourLabel->SetFont( wxFont( 16, 74, 90, 90, false, wxT("Sans") ) );
	m_votingInFavourLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	m_votingInFavourLabel->Enable( false );
	
	bSizer84->Add( m_votingInFavourLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText78 = new wxStaticText( m_procVotingLeftPanel, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText78->Wrap( -1 );
	m_staticText78->SetFont( wxFont( 16, 74, 90, 90, false, wxT("Sans") ) );
	m_staticText78->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	m_staticText78->Enable( false );
	
	bSizer84->Add( m_staticText78, 0, wxALL, 5 );
	
	m_votingAgainstLabel = new wxStaticText( m_procVotingLeftPanel, VOTING_AGAINST, _("AGAINST"), wxDefaultPosition, wxDefaultSize, 0 );
	m_votingAgainstLabel->Wrap( -1 );
	m_votingAgainstLabel->SetFont( wxFont( 16, 74, 90, 90, false, wxT("Sans") ) );
	m_votingAgainstLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	m_votingAgainstLabel->Enable( false );
	
	bSizer84->Add( m_votingAgainstLabel, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	votingTimerSizer->Add( bSizer84, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* votingCountrySizer;
	votingCountrySizer = new wxBoxSizer( wxVERTICAL );
	
	m_votingCountryPanel = new wxPanel( m_procVotingLeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4111;
	bSizer4111 = new wxBoxSizer( wxVERTICAL );
	
	m_VotingCountryFlag = new wxStaticBitmap( m_votingCountryPanel, VOTING_SPEAKER_FLAG, wxNullBitmap, wxDefaultPosition, wxSize( 150,100 ), 0 );
	m_VotingCountryFlag->SetMinSize( wxSize( 150,100 ) );
	m_VotingCountryFlag->SetMaxSize( wxSize( 150,100 ) );
	
	bSizer4111->Add( m_VotingCountryFlag, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_votingSpeaker = new wxStaticText( m_votingCountryPanel, VOTING_SPEAKER, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE|wxFULL_REPAINT_ON_RESIZE );
	m_votingSpeaker->Wrap( -1 );
	m_votingSpeaker->SetFont( wxFont( 17, 74, 90, 92, false, wxT("Sans") ) );
	m_votingSpeaker->SetMinSize( wxSize( -1,30 ) );
	
	bSizer4111->Add( m_votingSpeaker, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_votingCountryPanel->SetSizer( bSizer4111 );
	m_votingCountryPanel->Layout();
	bSizer4111->Fit( m_votingCountryPanel );
	votingCountrySizer->Add( m_votingCountryPanel, 1, wxEXPAND | wxALL, 5 );
	
	votingTimerSizer->Add( votingCountrySizer, 0, wxEXPAND, 5 );
	
	m_votingSpeechGauge = new wxGauge( m_procVotingLeftPanel, VOTING_GAUGE, 30, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	votingTimerSizer->Add( m_votingSpeechGauge, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* votingtimeleftSizer;
	votingtimeleftSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_voting_timeleft = new wxStaticText( m_procVotingLeftPanel, VOTING_TIME_LEFT, _("00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_voting_timeleft->Wrap( -1 );
	m_voting_timeleft->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	votingtimeleftSizer->Add( m_voting_timeleft, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_votingtimesep = new wxStaticText( m_procVotingLeftPanel, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_votingtimesep->Wrap( -1 );
	m_votingtimesep->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	votingtimeleftSizer->Add( m_votingtimesep, 0, wxALL, 5 );
	
	m_votingtotaltime = new wxStaticText( m_procVotingLeftPanel, VOTING_TOTAL_TIME, _("00:30"), wxDefaultPosition, wxDefaultSize, 0 );
	m_votingtotaltime->Wrap( -1 );
	m_votingtotaltime->SetFont( wxFont( 28, 74, 90, 92, false, wxT("Sans") ) );
	
	votingtimeleftSizer->Add( m_votingtotaltime, 0, wxALL, 5 );
	
	votingTimerSizer->Add( votingtimeleftSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer122;
	fgSizer122 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer122->SetFlexibleDirection( wxBOTH );
	fgSizer122->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	votingTimerSizer->Add( fgSizer122, 1, wxEXPAND, 5 );
	
	
	votingTimerSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxVERTICAL );
	
	m_votingStopButton = new wxButton( m_procVotingLeftPanel, wxID_STOP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( m_votingStopButton, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	votingTimerSizer->Add( bSizer68, 0, wxEXPAND, 5 );
	
	m_procVotingLeftPanel->SetSizer( votingTimerSizer );
	m_procVotingLeftPanel->Layout();
	votingTimerSizer->Fit( m_procVotingLeftPanel );
	m_procVotingRightPanel = new wxPanel( m_procVotingSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* votingRightBoxSizer;
	votingRightBoxSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer26;
	fgSizer26 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer26->AddGrowableCol( 1 );
	fgSizer26->AddGrowableRow( 0 );
	fgSizer26->AddGrowableRow( 1 );
	fgSizer26->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer26->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_votingOnLabel = new wxStaticText( m_procVotingRightPanel, wxID_ANY, _("Voting on:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_votingOnLabel->Wrap( -1 );
	fgSizer26->Add( m_votingOnLabel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_votingOnChoiceChoices[] = { _("Agenda"), _("Closure of Debate"), _("Postponement of Debate"), _("Resumption of Debate"), _("Amendment"), _("Division of the Question"), _("Reconsideration"), _("Other") };
	int m_votingOnChoiceNChoices = sizeof( m_votingOnChoiceChoices ) / sizeof( wxString );
	m_votingOnChoice = new wxChoice( m_procVotingRightPanel, VOTING_ON_CHOICES, wxDefaultPosition, wxDefaultSize, m_votingOnChoiceNChoices, m_votingOnChoiceChoices, 0 );
	m_votingOnChoice->SetSelection( 0 );
	m_votingOnChoice->SetToolTip( _("Pick a reason for this debate. This only sets the header and does not create seperate for/against lists!") );
	
	fgSizer26->Add( m_votingOnChoice, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_votingTimeText = new wxStaticText( m_procVotingRightPanel, wxID_ANY, _("Set speaker time:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_votingTimeText->Wrap( -1 );
	fgSizer26->Add( m_votingTimeText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxHORIZONTAL );
	
	m_votingMinutesSpinCtrl = new wxSpinCtrl( m_procVotingRightPanel, VOTING_TIME_MINUTES, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	m_votingMinutesSpinCtrl->SetMinSize( wxSize( 80,-1 ) );
	m_votingMinutesSpinCtrl->SetMaxSize( wxSize( 80,-1 ) );
	
	bSizer48->Add( m_votingMinutesSpinCtrl, 0, wxALL, 5 );
	
	m_votingSecondsSpinCtrl = new wxSpinCtrl( m_procVotingRightPanel, VOTING_TIME_SECONDS, wxT("30"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, -1, 60, 30 );
	m_votingSecondsSpinCtrl->SetMinSize( wxSize( 80,-1 ) );
	m_votingSecondsSpinCtrl->SetMaxSize( wxSize( 80,-1 ) );
	
	bSizer48->Add( m_votingSecondsSpinCtrl, 0, wxALL, 5 );
	
	fgSizer26->Add( bSizer48, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	votingRightBoxSizer->Add( fgSizer26, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBoxSizer* speakingInFavorSizer;
	speakingInFavorSizer = new wxStaticBoxSizer( new wxStaticBox( m_procVotingRightPanel, wxID_ANY, _("In favour") ), wxVERTICAL );
	
	wxArrayString m_inFavourChoiceChoices;
	m_inFavourChoice = new wxChoice( m_procVotingRightPanel, SPEAKING_IN_FAVOUR_CHOICES, wxDefaultPosition, wxSize( 370,-1 ), m_inFavourChoiceChoices, 0 );
	m_inFavourChoice->SetSelection( 0 );
	m_inFavourChoice->SetToolTip( _("Add country") );
	m_inFavourChoice->SetMaxSize( wxSize( 370,-1 ) );
	
	speakingInFavorSizer->Add( m_inFavourChoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_speakingInFavourList = new wxListBox( m_procVotingRightPanel, SPEAKING_IN_FAVOUR, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_speakingInFavourList->SetToolTip( _("Current list of countries speaking in favour") );
	
	speakingInFavorSizer->Add( m_speakingInFavourList, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* inFavourButtonSizer;
	inFavourButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_inFavourUpButton = new wxButton( m_procVotingRightPanel, wxID_UP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_inFavourUpButton->SetToolTip( _("Move the selected country higher on the list") );
	
	inFavourButtonSizer->Add( m_inFavourUpButton, 0, wxALL, 5 );
	
	m_inFavourDownButton = new wxButton( m_procVotingRightPanel, wxID_DOWN, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_inFavourDownButton->SetToolTip( _("Move the selected country lower on the list") );
	
	inFavourButtonSizer->Add( m_inFavourDownButton, 0, wxALL, 5 );
	
	m_inFavourDeleteButton = new wxButton( m_procVotingRightPanel, wxID_DELETE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_inFavourDeleteButton->SetToolTip( _("Remove the selected country from the list") );
	
	inFavourButtonSizer->Add( m_inFavourDeleteButton, 0, wxALL, 5 );
	
	m_inFavourClearButton = new wxButton( m_procVotingRightPanel, wxID_CLEAR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	inFavourButtonSizer->Add( m_inFavourClearButton, 0, wxALL, 5 );
	
	speakingInFavorSizer->Add( inFavourButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	votingRightBoxSizer->Add( speakingInFavorSizer, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* speakingAgainstSizer;
	speakingAgainstSizer = new wxStaticBoxSizer( new wxStaticBox( m_procVotingRightPanel, wxID_ANY, _("Against") ), wxVERTICAL );
	
	wxArrayString m_againstChoiceChoices;
	m_againstChoice = new wxChoice( m_procVotingRightPanel, SPEAKING_AGAINST_CHOICES, wxDefaultPosition, wxSize( 370,-1 ), m_againstChoiceChoices, 0 );
	m_againstChoice->SetSelection( 0 );
	m_againstChoice->SetToolTip( _("Add country") );
	m_againstChoice->SetMaxSize( wxSize( 370,-1 ) );
	
	speakingAgainstSizer->Add( m_againstChoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_speakingAgainstList = new wxListBox( m_procVotingRightPanel, SPEAKING_AGAINST, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_speakingAgainstList->SetToolTip( _("Current list of countries speaking against") );
	
	speakingAgainstSizer->Add( m_speakingAgainstList, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* againstButtonSizer;
	againstButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_againstUpButton = new wxButton( m_procVotingRightPanel, wxID_UP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_againstUpButton->SetToolTip( _("Move the selected country higher on the list") );
	
	againstButtonSizer->Add( m_againstUpButton, 0, wxALL, 5 );
	
	m_againstDownButton = new wxButton( m_procVotingRightPanel, wxID_DOWN, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_againstDownButton->SetToolTip( _("Move the selected country lower on the list") );
	
	againstButtonSizer->Add( m_againstDownButton, 0, wxALL, 5 );
	
	m_againstDeleteButton = new wxButton( m_procVotingRightPanel, wxID_DELETE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_againstDeleteButton->SetToolTip( _("Remove the selected country from the list") );
	
	againstButtonSizer->Add( m_againstDeleteButton, 0, wxALL, 5 );
	
	m_againstClearButton = new wxButton( m_procVotingRightPanel, wxID_CLEAR, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	againstButtonSizer->Add( m_againstClearButton, 0, wxALL, 5 );
	
	speakingAgainstSizer->Add( againstButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	votingRightBoxSizer->Add( speakingAgainstSizer, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_procVotingRightPanel->SetSizer( votingRightBoxSizer );
	m_procVotingRightPanel->Layout();
	votingRightBoxSizer->Fit( m_procVotingRightPanel );
	m_procVotingSplitter->SplitVertically( m_procVotingLeftPanel, m_procVotingRightPanel, 800 );
	procVotingContainerSizer->Add( m_procVotingSplitter, 1, wxEXPAND, 5 );
	
	m_procVotingPanel->SetSizer( procVotingContainerSizer );
	m_procVotingPanel->Layout();
	procVotingContainerSizer->Fit( m_procVotingPanel );
	m_mainauinotebook->AddPage( m_procVotingPanel, _("Procedural voting"), false, wxNullBitmap );
	m_rollCallVotePanel = new wxPanel( m_mainauinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* rollCallVoteSizer;
	rollCallVoteSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* rollCallFirstRoundSizer;
	rollCallFirstRoundSizer = new wxBoxSizer( wxVERTICAL );
	
	m_rollCallFirstRoundText = new wxStaticText( m_rollCallVotePanel, wxID_ANY, _("First round"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallFirstRoundText->Wrap( -1 );
	m_rollCallFirstRoundText->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	
	rollCallFirstRoundSizer->Add( m_rollCallFirstRoundText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline16 = new wxStaticLine( m_rollCallVotePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	rollCallFirstRoundSizer->Add( m_staticline16, 0, wxEXPAND | wxALL, 5 );
	
	m_rollCallFirstRoundChoices = new wxListBox( m_rollCallVotePanel, ROLL_CALL_FIRST_ROUND_CHOICES, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	rollCallFirstRoundSizer->Add( m_rollCallFirstRoundChoices, 1, wxALL|wxEXPAND, 5 );
	
	m_staticline19 = new wxStaticLine( m_rollCallVotePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	rollCallFirstRoundSizer->Add( m_staticline19, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* rollCallFirstRoundButtonSizer;
	rollCallFirstRoundButtonSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* rollCallFirstRoundYesNoSizer;
	rollCallFirstRoundYesNoSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_rollCallFirstRoundYesButton = new wxButton( m_rollCallVotePanel, wxID_YES, _("Yes"), wxDefaultPosition, wxDefaultSize, 0 );
	rollCallFirstRoundYesNoSizer->Add( m_rollCallFirstRoundYesButton, 0, wxALL, 5 );
	
	m_rollCallFirstRoundNoButton = new wxButton( m_rollCallVotePanel, wxID_NO, _("No"), wxDefaultPosition, wxDefaultSize, 0 );
	rollCallFirstRoundYesNoSizer->Add( m_rollCallFirstRoundNoButton, 0, wxALL, 5 );
	
	rollCallFirstRoundButtonSizer->Add( rollCallFirstRoundYesNoSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* rollCallFirstRoundYesNoRightsSizer;
	rollCallFirstRoundYesNoRightsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_rollCallFirstRoundYesWithRightsButton = new wxButton( m_rollCallVotePanel, wxID_ANY, _("Yes w/rights"), wxDefaultPosition, wxDefaultSize, 0 );
	rollCallFirstRoundYesNoRightsSizer->Add( m_rollCallFirstRoundYesWithRightsButton, 0, wxALL, 5 );
	
	m_rollCallFirstRoundNoWithRightsButton = new wxButton( m_rollCallVotePanel, wxID_ANY, _("No w/rights"), wxDefaultPosition, wxDefaultSize, 0 );
	rollCallFirstRoundYesNoRightsSizer->Add( m_rollCallFirstRoundNoWithRightsButton, 0, wxALL, 5 );
	
	rollCallFirstRoundButtonSizer->Add( rollCallFirstRoundYesNoRightsSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* rollCallFirstRoundAbstainPassSizer;
	rollCallFirstRoundAbstainPassSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_rollCallFirstRoundAbstainButton = new wxButton( m_rollCallVotePanel, wxID_ANY, _("Abstain"), wxDefaultPosition, wxDefaultSize, 0 );
	rollCallFirstRoundAbstainPassSizer->Add( m_rollCallFirstRoundAbstainButton, 0, wxALL, 5 );
	
	m_rollCallFirstRoundPassButton = new wxButton( m_rollCallVotePanel, wxID_ANY, _("Pass"), wxDefaultPosition, wxDefaultSize, 0 );
	rollCallFirstRoundAbstainPassSizer->Add( m_rollCallFirstRoundPassButton, 0, wxALL, 5 );
	
	rollCallFirstRoundButtonSizer->Add( rollCallFirstRoundAbstainPassSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	rollCallFirstRoundSizer->Add( rollCallFirstRoundButtonSizer, 0, wxEXPAND, 5 );
	
	rollCallVoteSizer->Add( rollCallFirstRoundSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* rollCallSecondRoundSizer;
	rollCallSecondRoundSizer = new wxBoxSizer( wxVERTICAL );
	
	m_rollCallSecondRoundText = new wxStaticText( m_rollCallVotePanel, wxID_ANY, _("Second Round"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallSecondRoundText->Wrap( -1 );
	m_rollCallSecondRoundText->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	m_rollCallSecondRoundText->Enable( false );
	
	rollCallSecondRoundSizer->Add( m_rollCallSecondRoundText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline17 = new wxStaticLine( m_rollCallVotePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	rollCallSecondRoundSizer->Add( m_staticline17, 0, wxEXPAND | wxALL, 5 );
	
	m_rollCallSecondRoundChoices = new wxListBox( m_rollCallVotePanel, ROLL_CALL_SECOND_ROUND_CHOICES, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_rollCallSecondRoundChoices->Enable( false );
	
	rollCallSecondRoundSizer->Add( m_rollCallSecondRoundChoices, 1, wxALL|wxEXPAND, 5 );
	
	m_staticline20 = new wxStaticLine( m_rollCallVotePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	rollCallSecondRoundSizer->Add( m_staticline20, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* rollCallSecondRoundButtonSizer;
	rollCallSecondRoundButtonSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* rollCallSecondRoundYesNoSizer;
	rollCallSecondRoundYesNoSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_rollCallSecondRoundYesButton = new wxButton( m_rollCallVotePanel, wxID_YES, _("Yes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallSecondRoundYesButton->Enable( false );
	
	rollCallSecondRoundYesNoSizer->Add( m_rollCallSecondRoundYesButton, 0, wxALL, 5 );
	
	m_rollCallSecondRoundNoButton = new wxButton( m_rollCallVotePanel, wxID_NO, _("No"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallSecondRoundNoButton->Enable( false );
	
	rollCallSecondRoundYesNoSizer->Add( m_rollCallSecondRoundNoButton, 0, wxALL, 5 );
	
	rollCallSecondRoundButtonSizer->Add( rollCallSecondRoundYesNoSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* rollCallSecondRoundYesNoRightsSizer;
	rollCallSecondRoundYesNoRightsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_rollCallSecondRoundYesWithRightsButton = new wxButton( m_rollCallVotePanel, wxID_ANY, _("Yes w/rights"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallSecondRoundYesWithRightsButton->Enable( false );
	
	rollCallSecondRoundYesNoRightsSizer->Add( m_rollCallSecondRoundYesWithRightsButton, 0, wxALL, 5 );
	
	m_rollCallSecondRoundNoWithRightsButton = new wxButton( m_rollCallVotePanel, wxID_ANY, _("No w/rights"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallSecondRoundNoWithRightsButton->Enable( false );
	
	rollCallSecondRoundYesNoRightsSizer->Add( m_rollCallSecondRoundNoWithRightsButton, 0, wxALL, 5 );
	
	rollCallSecondRoundButtonSizer->Add( rollCallSecondRoundYesNoRightsSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* rollCallSecondRoundAbstainPassSizer;
	rollCallSecondRoundAbstainPassSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_rollCallSecondRoundAbstainButton = new wxButton( m_rollCallVotePanel, wxID_ANY, _("Abstain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallSecondRoundAbstainButton->Enable( false );
	
	rollCallSecondRoundAbstainPassSizer->Add( m_rollCallSecondRoundAbstainButton, 0, wxALL, 5 );
	
	m_rollCallSecondRoundPassButton = new wxButton( m_rollCallVotePanel, wxID_ANY, _("Pass"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallSecondRoundPassButton->Enable( false );
	
	rollCallSecondRoundAbstainPassSizer->Add( m_rollCallSecondRoundPassButton, 0, wxALL, 5 );
	
	rollCallSecondRoundButtonSizer->Add( rollCallSecondRoundAbstainPassSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	rollCallSecondRoundSizer->Add( rollCallSecondRoundButtonSizer, 0, wxEXPAND, 5 );
	
	rollCallVoteSizer->Add( rollCallSecondRoundSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* rollCallOutcomeSizer;
	rollCallOutcomeSizer = new wxBoxSizer( wxVERTICAL );
	
	m_scrolledWindow1 = new wxScrolledWindow( m_rollCallVotePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer( wxVERTICAL );
	
	m_rollCallOutcomeText = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Outcome"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallOutcomeText->Wrap( -1 );
	m_rollCallOutcomeText->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	
	bSizer103->Add( m_rollCallOutcomeText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline18 = new wxStaticLine( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer103->Add( m_staticline18, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* rollCallOutcomeDetailsDataSizer;
	rollCallOutcomeDetailsDataSizer = new wxFlexGridSizer( 2, 2, 0, 0 );
	rollCallOutcomeDetailsDataSizer->AddGrowableCol( 1 );
	rollCallOutcomeDetailsDataSizer->SetFlexibleDirection( wxBOTH );
	rollCallOutcomeDetailsDataSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_inFavourCountText = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("In favour:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_inFavourCountText->Wrap( -1 );
	rollCallOutcomeDetailsDataSizer->Add( m_inFavourCountText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_inFavourCount = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_inFavourCount->Wrap( -1 );
	m_inFavourCount->Enable( false );
	
	rollCallOutcomeDetailsDataSizer->Add( m_inFavourCount, 0, wxALL|wxEXPAND, 5 );
	
	m_againstCountText = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Against:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_againstCountText->Wrap( -1 );
	rollCallOutcomeDetailsDataSizer->Add( m_againstCountText, 0, wxALL, 5 );
	
	m_againstCount = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_againstCount->Wrap( -1 );
	m_againstCount->Enable( false );
	
	rollCallOutcomeDetailsDataSizer->Add( m_againstCount, 0, wxALL, 5 );
	
	m_abstentionsCountText = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Abstentions:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_abstentionsCountText->Wrap( -1 );
	rollCallOutcomeDetailsDataSizer->Add( m_abstentionsCountText, 0, wxALL, 5 );
	
	m_abstentionsCount = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_abstentionsCount->Wrap( -1 );
	m_abstentionsCount->Enable( false );
	
	rollCallOutcomeDetailsDataSizer->Add( m_abstentionsCount, 0, wxALL, 5 );
	
	m_vetoTextLabel = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Veto:"), wxDefaultPosition, wxDefaultSize, 0|wxFULL_REPAINT_ON_RESIZE );
	m_vetoTextLabel->Wrap( -1 );
	m_vetoTextLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	m_vetoTextLabel->Enable( false );
	
	rollCallOutcomeDetailsDataSizer->Add( m_vetoTextLabel, 0, wxALL, 5 );
	
	m_vetoText = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("no"), wxDefaultPosition, wxDefaultSize, 0|wxFULL_REPAINT_ON_RESIZE );
	m_vetoText->Wrap( -1 );
	m_vetoText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	m_vetoText->Enable( false );
	
	rollCallOutcomeDetailsDataSizer->Add( m_vetoText, 0, wxALL, 5 );
	
	m_outcomeLabelText = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("RESULT:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_outcomeLabelText->Wrap( -1 );
	m_outcomeLabelText->SetFont( wxFont( 10, 74, 93, 92, false, wxT("Sans") ) );
	
	rollCallOutcomeDetailsDataSizer->Add( m_outcomeLabelText, 0, wxALL, 5 );
	
	wxBoxSizer* rollCallPassedFailedSizer;
	rollCallPassedFailedSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_outcomeTextPassed = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("PASSED"), wxDefaultPosition, wxDefaultSize, 0 );
	m_outcomeTextPassed->Wrap( -1 );
	m_outcomeTextPassed->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	m_outcomeTextPassed->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	m_outcomeTextPassed->Enable( false );
	
	rollCallPassedFailedSizer->Add( m_outcomeTextPassed, 0, wxALL, 5 );
	
	m_outcomeTextSep = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_outcomeTextSep->Wrap( -1 );
	m_outcomeTextSep->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	m_outcomeTextSep->Enable( false );
	
	rollCallPassedFailedSizer->Add( m_outcomeTextSep, 0, wxTOP|wxBOTTOM, 5 );
	
	m_outcomeTextFailed = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("FAILED"), wxDefaultPosition, wxDefaultSize, 0 );
	m_outcomeTextFailed->Wrap( -1 );
	m_outcomeTextFailed->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	m_outcomeTextFailed->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	m_outcomeTextFailed->Enable( false );
	
	rollCallPassedFailedSizer->Add( m_outcomeTextFailed, 0, wxALL, 5 );
	
	rollCallOutcomeDetailsDataSizer->Add( rollCallPassedFailedSizer, 1, wxEXPAND, 5 );
	
	bSizer103->Add( rollCallOutcomeDetailsDataSizer, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	m_staticline26 = new wxStaticLine( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer103->Add( m_staticline26, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* rollCallOutcomeVoteTypeSizer;
	rollCallOutcomeVoteTypeSizer = new wxBoxSizer( wxVERTICAL );
	
	m_rollCallConsensusCheckbox = new wxCheckBox( m_scrolledWindow1, wxID_ANY, _("Consensus-based voting"), wxDefaultPosition, wxDefaultSize, 0 );
	
	m_rollCallConsensusCheckbox->SetToolTip( _("The committee decides by consensus") );
	
	rollCallOutcomeVoteTypeSizer->Add( m_rollCallConsensusCheckbox, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* rollCallOutcomeVoteTypeSCModeSizer;
	rollCallOutcomeVoteTypeSCModeSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_noVetoRadioBtn = new wxRadioButton( m_scrolledWindow1, wxID_ANY, _("No P5-veto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_noVetoRadioBtn->SetToolTip( _("Do not vote as in the Security Council") );
	
	rollCallOutcomeVoteTypeSCModeSizer->Add( m_noVetoRadioBtn, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_vetoRadioBtn = new wxRadioButton( m_scrolledWindow1, wxID_ANY, _("P5 veto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_vetoRadioBtn->SetToolTip( _("Vote as a Security Council") );
	
	rollCallOutcomeVoteTypeSCModeSizer->Add( m_vetoRadioBtn, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	rollCallOutcomeVoteTypeSizer->Add( rollCallOutcomeVoteTypeSCModeSizer, 0, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* rollCallMinimumInFavourSizer;
	rollCallMinimumInFavourSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_rollCallMinimumInFavourCheckbox = new wxCheckBox( m_scrolledWindow1, wxID_ANY, _("Minimum affirmative:"), wxDefaultPosition, wxDefaultSize, 0 );
	
	m_rollCallMinimumInFavourCheckbox->SetToolTip( _("The committee has a minimum number of affirmative votes needed, instead of simple majority") );
	
	rollCallMinimumInFavourSizer->Add( m_rollCallMinimumInFavourCheckbox, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_minimumInFavourSpin = new wxSpinCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 0, 9999, 9 );
	m_minimumInFavourSpin->Enable( false );
	m_minimumInFavourSpin->SetToolTip( _("The committee has a minimum number of affirmative votes needed, instead of simple majority") );
	
	rollCallMinimumInFavourSizer->Add( m_minimumInFavourSpin, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	rollCallOutcomeVoteTypeSizer->Add( rollCallMinimumInFavourSizer, 1, 0, 5 );
	
	bSizer103->Add( rollCallOutcomeVoteTypeSizer, 0, wxALIGN_RIGHT, 5 );
	
	m_staticline181 = new wxStaticLine( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer103->Add( m_staticline181, 0, wxEXPAND | wxALL, 5 );
	
	m_rollCallDisplayOutcome = new wxCheckBox( m_scrolledWindow1, wxID_ANY, _("Display outcome"), wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer103->Add( m_rollCallDisplayOutcome, 0, wxALL, 5 );
	
	m_staticline21 = new wxStaticLine( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer103->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer110;
	bSizer110 = new wxBoxSizer( wxVERTICAL );
	
	m_rollCallVotingWithRightsLabel = new wxStaticText( m_scrolledWindow1, wxID_ANY, _("Voting with rights:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rollCallVotingWithRightsLabel->Wrap( -1 );
	m_rollCallVotingWithRightsLabel->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	m_rollCallVotingWithRightsLabel->Enable( false );
	
	bSizer110->Add( m_rollCallVotingWithRightsLabel, 0, wxALL, 5 );
	
	m_rollCallVotingWithRights = new wxListBox( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	m_rollCallVotingWithRights->Enable( false );
	m_rollCallVotingWithRights->SetMinSize( wxSize( -1,100 ) );
	
	bSizer110->Add( m_rollCallVotingWithRights, 1, wxALL|wxEXPAND, 5 );
	
	bSizer103->Add( bSizer110, 1, wxEXPAND, 5 );
	
	m_rollCallClearButton = new wxButton( m_scrolledWindow1, wxID_CLEAR, _("&Clear roll call votes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer103->Add( m_rollCallClearButton, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_scrolledWindow1->SetSizer( bSizer103 );
	m_scrolledWindow1->Layout();
	bSizer103->Fit( m_scrolledWindow1 );
	rollCallOutcomeSizer->Add( m_scrolledWindow1, 1, wxEXPAND | wxALL, 5 );
	
	rollCallVoteSizer->Add( rollCallOutcomeSizer, 1, wxEXPAND, 5 );
	
	m_rollCallVotePanel->SetSizer( rollCallVoteSizer );
	m_rollCallVotePanel->Layout();
	rollCallVoteSizer->Fit( m_rollCallVotePanel );
	m_mainauinotebook->AddPage( m_rollCallVotePanel, _("Roll call vote"), false, wxNullBitmap );
	
	bSizer42->Add( m_mainauinotebook, 1, wxEXPAND | wxALL, 5 );
	
	panelContainerSizer->Add( bSizer42, 1, wxEXPAND, 5 );
	
	m_mainPanel->SetSizer( panelContainerSizer );
	m_mainPanel->Layout();
	panelContainerSizer->Fit( m_mainPanel );
	containerSizer->Add( m_mainPanel, 1, wxEXPAND, 5 );
	
	m_bannerSizer = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_bannerSizer->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	
	wxBoxSizer* bBannerMainSizer;
	bBannerMainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bannerText = new wxStaticText( m_bannerSizer, wxID_ANY, _("The wxMUN homepage is hosted by "), wxDefaultPosition, wxDefaultSize, 0 );
	m_bannerText->Wrap( -1 );
	bSizer105->Add( m_bannerText, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bannerHyperlink = new wxHyperlinkCtrl( m_bannerSizer, wxID_ANY, _("United Netherlands"), wxT("http://www.unitednetherlands.org"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer105->Add( m_bannerHyperlink, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bBannerMainSizer->Add( bSizer105, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bannerSizer->SetSizer( bBannerMainSizer );
	m_bannerSizer->Layout();
	bBannerMainSizer->Fit( m_bannerSizer );
	containerSizer->Add( m_bannerSizer, 0, wxEXPAND, 5 );
	
	this->SetSizer( containerSizer );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_statusBar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	
	m_menubar = new wxMenuBar( 0 );
	m_fileMenu = new wxMenu();
	wxMenuItem* m_openMenuItem;
	m_openMenuItem = new wxMenuItem( m_fileMenu, wxID_OPEN, wxString( _("&Open State File") ) + wxT('\t') + wxT("Ctrl+O"), _("Open an existing state state of debate"), wxITEM_NORMAL );
	m_fileMenu->Append( m_openMenuItem );
	
	m_fileMenu->AppendSeparator();
	
	wxMenuItem* m_saveAsMenuItem;
	m_saveAsMenuItem = new wxMenuItem( m_fileMenu, wxID_SAVEAS, wxString( _("&Save State As") ) + wxT('\t') + wxT("Ctrl+S"), _("Save the current state of debate under a new name"), wxITEM_NORMAL );
	m_fileMenu->Append( m_saveAsMenuItem );
	
	m_fileMenu->AppendSeparator();
	
	wxMenuItem* m_quitMenuItem;
	m_quitMenuItem = new wxMenuItem( m_fileMenu, wxID_EXIT, wxString( _("&Quit") ) + wxT('\t') + wxT("Ctrl+Q"), _("Exit the program"), wxITEM_NORMAL );
	m_fileMenu->Append( m_quitMenuItem );
	
	m_menubar->Append( m_fileMenu, _("&File") );
	
	m_viewMenu = new wxMenu();
	wxMenuItem* m_fullscreenMenu;
	m_fullscreenMenu = new wxMenuItem( m_viewMenu, wxID_ZOOM_FIT, wxString( _("&Fullscreen") ) + wxT('\t') + wxT("Ctrl+F"), wxEmptyString, wxITEM_NORMAL );
	m_viewMenu->Append( m_fullscreenMenu );
	
	m_menubar->Append( m_viewMenu, _("&View") );
	
	m_manageMenu = new wxMenu();
	m_topicSelectorMenu = new wxMenu();
	m_topicAMenuItem = new wxMenuItem( m_topicSelectorMenu, TOPIC_A_MENU, wxString( _("Topic A") ) , wxEmptyString, wxITEM_CHECK );
	m_topicSelectorMenu->Append( m_topicAMenuItem );
	m_topicAMenuItem->Enable( false );
	
	m_topicBMenuItem = new wxMenuItem( m_topicSelectorMenu, TOPIC_B_MENU, wxString( _("Topic B") ) , wxEmptyString, wxITEM_CHECK );
	m_topicSelectorMenu->Append( m_topicBMenuItem );
	m_topicBMenuItem->Enable( false );
	
	m_manageMenu->Append( -1, _("&Select topic"), m_topicSelectorMenu );
	
	m_countriesPresentMenuItem = new wxMenuItem( m_manageMenu, wxID_SORT_ASCENDING, wxString( _("&Countries present") ) + wxT('\t') + wxT("Ctrl+Shift+C"), wxEmptyString, wxITEM_NORMAL );
	m_manageMenu->Append( m_countriesPresentMenuItem );
	m_countriesPresentMenuItem->Enable( false );
	
	m_votingProcedureMenuItem = new wxMenuItem( m_manageMenu, wxID_FORWARD, wxString( _("Start &voting procedure") ) + wxT('\t') + wxT("Ctrl+Shift+V"), wxEmptyString, wxITEM_NORMAL );
	m_manageMenu->Append( m_votingProcedureMenuItem );
	m_votingProcedureMenuItem->Enable( false );
	
	m_menubar->Append( m_manageMenu, _("&Manage debate") );
	
	m_committeeMenu = new wxMenu();
	wxMenuItem* m_newCommitteeMenuItem;
	m_newCommitteeMenuItem = new wxMenuItem( m_committeeMenu, wxID_NEW, wxString( _("&New") ) + wxT('\t') + wxT("Ctrl+N"), _("Create a new committee"), wxITEM_NORMAL );
	m_committeeMenu->Append( m_newCommitteeMenuItem );
	
	wxMenuItem* m_loadCommitteeMenuItem;
	m_loadCommitteeMenuItem = new wxMenuItem( m_committeeMenu, wxID_OPEN, wxString( _("&Load") ) + wxT('\t') + wxT("Ctrl+L"), _("Load an existing committee to start a new session. Load a state file if you want to resume debate!"), wxITEM_NORMAL );
	m_committeeMenu->Append( m_loadCommitteeMenuItem );
	
	wxMenuItem* m_editCommitteeMenuItem;
	m_editCommitteeMenuItem = new wxMenuItem( m_committeeMenu, wxID_EDIT, wxString( _("&Edit") ) + wxT('\t') + wxT("Ctrl+E"), _("Edit a committee file"), wxITEM_NORMAL );
	m_committeeMenu->Append( m_editCommitteeMenuItem );
	
	m_menubar->Append( m_committeeMenu, _("&Committee") );
	
	m_helpMenu = new wxMenu();
	wxMenuItem* m_helpMenuItem;
	m_helpMenuItem = new wxMenuItem( m_helpMenu, wxID_HELP, wxString( _("&Help") ) + wxT('\t') + wxT("F1"), _("View the on-line help"), wxITEM_NORMAL );
	m_helpMenu->Append( m_helpMenuItem );
	
	wxMenuItem* m_aboutMenuItem;
	m_aboutMenuItem = new wxMenuItem( m_helpMenu, wxID_ABOUT, wxString( _("&About") ) + wxT('\t') + wxT("F2"), _("About the program"), wxITEM_NORMAL );
	m_helpMenu->Append( m_aboutMenuItem );
	
	m_menubar->Append( m_helpMenu, _("&Help") );
	
	this->SetMenuBar( m_menubar );
	
	
	// Connect Events
	m_GSLYieldButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLYield ), NULL, this );
	m_GSLNext->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLNext ), NULL, this );
	m_GSLResumeButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLResume ), NULL, this );
	m_GSLPauseButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLPause ), NULL, this );
	m_GSLStopButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLStop ), NULL, this );
	m_GSLminutesSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnGSLMinutesChange ), NULL, this );
	m_GSLsecondsSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnGSLSecondsChange ), NULL, this );
	m_GSLChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnGSLChoice ), NULL, this );
	m_GSLList->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLListSelect ), NULL, this );
	m_GSLUpButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLUpClick ), NULL, this );
	m_GSLDownButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLDownClick ), NULL, this );
	m_GSLDeleteButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLDeleteClick ), NULL, this );
	m_GSLClearButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLClearClick ), NULL, this );
	m_stopSingleSpeakerButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnSingleSpeakerStop ), NULL, this );
	m_singleSpeakerMinutes->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnSingleSpeakerMinutesChange ), NULL, this );
	m_singleSpeakerSeconds->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnSingleSpeakerSecondsChange ), NULL, this );
	m_singleSpeakerCountryListBox->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnSingleSpeakerCountrySelect ), NULL, this );
	m_resumeModCaucus->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusResume ), NULL, this );
	m_pauseModCaucus->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusPause ), NULL, this );
	m_stopModCaucusButton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusStop ), NULL, this );
	m_mod_caucus_durationMinutes->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnModCaucusMinChange ), NULL, this );
	m_mod_caucus_durationSeconds->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnModCaucusSecChange ), NULL, this );
	m_mod_caucus_STseconds->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnModCaucusSTSecChange ), NULL, this );
	m_stopModCaucusButton11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusStop ), NULL, this );
	m_modCaucus_sdbSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusCancel ), NULL, this );
	m_modCaucus_sdbSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusStart ), NULL, this );
	m_modCaucusCountryListBox->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusCountrySelect ), NULL, this );
	m_stopUnModCaucusButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnUnModCaucusStop ), NULL, this );
	m_durationMinutes->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnUnModCaucusMinChange ), NULL, this );
	m_durationSeconds->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnUnModCaucusSecChange ), NULL, this );
	m_stopUnModCaucusButton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnUnModCaucusStop ), NULL, this );
	m_unmodCaucus_sdbSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnUnModCaucusCancel ), NULL, this );
	m_unmodCaucus_sdbSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnUnModCaucusStart ), NULL, this );
	m_votingStopButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnVotingStopSpeaker ), NULL, this );
	m_votingOnChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnVotingOnChoice ), NULL, this );
	m_votingMinutesSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnVotingMinutesChange ), NULL, this );
	m_votingSecondsSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnVotingSecondsChange ), NULL, this );
	m_inFavourChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnSpeakingInFavourChoice ), NULL, this );
	m_speakingInFavourList->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnSpeakingInFavourListSelect ), NULL, this );
	m_inFavourUpButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnInFavourUpClick ), NULL, this );
	m_inFavourDownButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnInFavourDownClick ), NULL, this );
	m_inFavourDeleteButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnInFavourDeleteClick ), NULL, this );
	m_inFavourClearButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnInFavourClearClick ), NULL, this );
	m_againstChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnSpeakingAgainstChoice ), NULL, this );
	m_speakingAgainstList->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnSpeakingAgainstListSelect ), NULL, this );
	m_againstUpButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnAgainstUpClick ), NULL, this );
	m_againstDownButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnAgainstDownClick ), NULL, this );
	m_againstDeleteButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnAgainstDeleteClick ), NULL, this );
	m_againstClearButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnAgainstClearClick ), NULL, this );
	m_rollCallFirstRoundYesButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundYes ), NULL, this );
	m_rollCallFirstRoundNoButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundNo ), NULL, this );
	m_rollCallFirstRoundYesWithRightsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundYesWithRights ), NULL, this );
	m_rollCallFirstRoundNoWithRightsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundNoWithRights ), NULL, this );
	m_rollCallFirstRoundAbstainButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundAbstain ), NULL, this );
	m_rollCallFirstRoundPassButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundPass ), NULL, this );
	m_rollCallSecondRoundYesButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallSecondRoundYes ), NULL, this );
	m_rollCallSecondRoundNoButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallSecondRoundNo ), NULL, this );
	m_rollCallConsensusCheckbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallConsensusCheck ), NULL, this );
	m_noVetoRadioBtn->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnRollCallSCModeToggle ), NULL, this );
	m_vetoRadioBtn->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnRollCallSCModeToggle ), NULL, this );
	m_rollCallMinimumInFavourCheckbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallMimimunInFavourCheck ), NULL, this );
	m_minimumInFavourSpin->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnRollCallMinimumInFavourChange ), NULL, this );
	m_rollCallDisplayOutcome->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallDisplayOutcomeCheck ), NULL, this );
	m_rollCallVotingWithRights->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallVotingWithRightsSpeakerSelect ), NULL, this );
	m_rollCallClearButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallClearVotes ), NULL, this );
	this->Connect( m_openMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnStateFileOpen ) );
	this->Connect( m_saveAsMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnStateFileSaveAs ) );
	this->Connect( m_quitMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnQuit ) );
	this->Connect( m_fullscreenMenu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::ToggleFullScreen ) );
	this->Connect( m_topicAMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnTopicAMenuSelect ) );
	this->Connect( m_topicBMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnTopicBMenuSelect ) );
	this->Connect( m_countriesPresentMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnCountriesPresentMenuSelect ) );
	this->Connect( m_votingProcedureMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnStartVotingProcedureMenuSelect ) );
	this->Connect( m_newCommitteeMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnNewCommittee ) );
	this->Connect( m_loadCommitteeMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnLoadCommittee ) );
	this->Connect( m_editCommitteeMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnEditCommittee ) );
	this->Connect( m_helpMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnHelp ) );
	this->Connect( m_aboutMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnAbout ) );
}

GUI_MainFrame::~GUI_MainFrame()
{
	// Disconnect Events
	m_GSLYieldButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLYield ), NULL, this );
	m_GSLNext->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLNext ), NULL, this );
	m_GSLResumeButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLResume ), NULL, this );
	m_GSLPauseButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLPause ), NULL, this );
	m_GSLStopButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLStop ), NULL, this );
	m_GSLminutesSpinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnGSLMinutesChange ), NULL, this );
	m_GSLsecondsSpinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnGSLSecondsChange ), NULL, this );
	m_GSLChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnGSLChoice ), NULL, this );
	m_GSLList->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLListSelect ), NULL, this );
	m_GSLUpButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLUpClick ), NULL, this );
	m_GSLDownButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLDownClick ), NULL, this );
	m_GSLDeleteButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLDeleteClick ), NULL, this );
	m_GSLClearButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnGSLClearClick ), NULL, this );
	m_stopSingleSpeakerButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnSingleSpeakerStop ), NULL, this );
	m_singleSpeakerMinutes->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnSingleSpeakerMinutesChange ), NULL, this );
	m_singleSpeakerSeconds->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnSingleSpeakerSecondsChange ), NULL, this );
	m_singleSpeakerCountryListBox->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnSingleSpeakerCountrySelect ), NULL, this );
	m_resumeModCaucus->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusResume ), NULL, this );
	m_pauseModCaucus->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusPause ), NULL, this );
	m_stopModCaucusButton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusStop ), NULL, this );
	m_mod_caucus_durationMinutes->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnModCaucusMinChange ), NULL, this );
	m_mod_caucus_durationSeconds->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnModCaucusSecChange ), NULL, this );
	m_mod_caucus_STseconds->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnModCaucusSTSecChange ), NULL, this );
	m_stopModCaucusButton11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusStop ), NULL, this );
	m_modCaucus_sdbSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusCancel ), NULL, this );
	m_modCaucus_sdbSizerOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusStart ), NULL, this );
	m_modCaucusCountryListBox->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnModCaucusCountrySelect ), NULL, this );
	m_stopUnModCaucusButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnUnModCaucusStop ), NULL, this );
	m_durationMinutes->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnUnModCaucusMinChange ), NULL, this );
	m_durationSeconds->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnUnModCaucusSecChange ), NULL, this );
	m_stopUnModCaucusButton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnUnModCaucusStop ), NULL, this );
	m_unmodCaucus_sdbSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnUnModCaucusCancel ), NULL, this );
	m_unmodCaucus_sdbSizerOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnUnModCaucusStart ), NULL, this );
	m_votingStopButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnVotingStopSpeaker ), NULL, this );
	m_votingOnChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnVotingOnChoice ), NULL, this );
	m_votingMinutesSpinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnVotingMinutesChange ), NULL, this );
	m_votingSecondsSpinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnVotingSecondsChange ), NULL, this );
	m_inFavourChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnSpeakingInFavourChoice ), NULL, this );
	m_speakingInFavourList->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnSpeakingInFavourListSelect ), NULL, this );
	m_inFavourUpButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnInFavourUpClick ), NULL, this );
	m_inFavourDownButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnInFavourDownClick ), NULL, this );
	m_inFavourDeleteButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnInFavourDeleteClick ), NULL, this );
	m_inFavourClearButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnInFavourClearClick ), NULL, this );
	m_againstChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnSpeakingAgainstChoice ), NULL, this );
	m_speakingAgainstList->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnSpeakingAgainstListSelect ), NULL, this );
	m_againstUpButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnAgainstUpClick ), NULL, this );
	m_againstDownButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnAgainstDownClick ), NULL, this );
	m_againstDeleteButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnAgainstDeleteClick ), NULL, this );
	m_againstClearButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnAgainstClearClick ), NULL, this );
	m_rollCallFirstRoundYesButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundYes ), NULL, this );
	m_rollCallFirstRoundNoButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundNo ), NULL, this );
	m_rollCallFirstRoundYesWithRightsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundYesWithRights ), NULL, this );
	m_rollCallFirstRoundNoWithRightsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundNoWithRights ), NULL, this );
	m_rollCallFirstRoundAbstainButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundAbstain ), NULL, this );
	m_rollCallFirstRoundPassButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallFirstRoundPass ), NULL, this );
	m_rollCallSecondRoundYesButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallSecondRoundYes ), NULL, this );
	m_rollCallSecondRoundNoButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallSecondRoundNo ), NULL, this );
	m_rollCallConsensusCheckbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallConsensusCheck ), NULL, this );
	m_noVetoRadioBtn->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnRollCallSCModeToggle ), NULL, this );
	m_vetoRadioBtn->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnRollCallSCModeToggle ), NULL, this );
	m_rollCallMinimumInFavourCheckbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallMimimunInFavourCheck ), NULL, this );
	m_minimumInFavourSpin->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUI_MainFrame::OnRollCallMinimumInFavourChange ), NULL, this );
	m_rollCallDisplayOutcome->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallDisplayOutcomeCheck ), NULL, this );
	m_rollCallVotingWithRights->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallVotingWithRightsSpeakerSelect ), NULL, this );
	m_rollCallClearButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_MainFrame::OnRollCallClearVotes ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnStateFileOpen ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnStateFileSaveAs ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnQuit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::ToggleFullScreen ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnTopicAMenuSelect ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnTopicBMenuSelect ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnCountriesPresentMenuSelect ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnStartVotingProcedureMenuSelect ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnNewCommittee ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnLoadCommittee ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnEditCommittee ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnHelp ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUI_MainFrame::OnAbout ) );
}

GUI_NewCommitteeDialog::GUI_NewCommitteeDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* newCommitteeSizer;
	newCommitteeSizer = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* ncInstructionSizer;
	ncInstructionSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Instructions") ), wxVERTICAL );
	
	ncInstructions = new wxStaticText( this, wxID_ANY, _("1. Check the countries you would like to be a part of this committee or council.\n2. Optionally check any observers present. wxMUN always checks observers aren't already members.\n3. You can edit individual committee/council details by clicking on their names in the list.\n4. Click 'OK'."), wxDefaultPosition, wxSize( 350,80 ), wxST_NO_AUTORESIZE );
	ncInstructions->Wrap( -1 );
	ncInstructionSizer->Add( ncInstructions, 0, wxALL|wxEXPAND, 5 );
	
	newCommitteeSizer->Add( ncInstructionSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* ncMainSizer;
	ncMainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* ncCountriesSizer;
	ncCountriesSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* membersSizer;
	membersSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* membersButtonSizer;
	membersButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_membersButtonText = new wxStaticText( this, wxID_ANY, _("Members:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_membersButtonText->Wrap( -1 );
	membersButtonSizer->Add( m_membersButtonText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_selectAllMembers = new wxButton( this, wxID_ANY, _("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	membersButtonSizer->Add( m_selectAllMembers, 0, wxALL, 5 );
	
	m_selectNoneMembers = new wxButton( this, wxID_ANY, _("Select None"), wxDefaultPosition, wxDefaultSize, 0 );
	m_selectNoneMembers->Enable( false );
	
	membersButtonSizer->Add( m_selectNoneMembers, 0, wxALL, 5 );
	
	m_invertMembers = new wxButton( this, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
	membersButtonSizer->Add( m_invertMembers, 0, wxALL, 5 );
	
	membersSizer->Add( membersButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxArrayString m_membersCheckListChoices;
	m_membersCheckList = new wxCheckListBox( this, ID_MEMBERS_CHECK_LIST, wxDefaultPosition, wxSize( 350,200 ), m_membersCheckListChoices, wxLB_MULTIPLE|wxLB_NEEDED_SB );
	m_membersCheckList->SetToolTip( _("Members of the committee/council") );
	
	membersSizer->Add( m_membersCheckList, 0, wxALL|wxEXPAND, 5 );
	
	ncCountriesSizer->Add( membersSizer, 1, wxEXPAND, 5 );
	
	m_staticline15 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	ncCountriesSizer->Add( m_staticline15, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* observersSizer;
	observersSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* observersButtonSizer;
	observersButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_observersButtonText = new wxStaticText( this, wxID_ANY, _("Observers:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_observersButtonText->Wrap( -1 );
	observersButtonSizer->Add( m_observersButtonText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_selectAllObservers = new wxButton( this, wxID_ANY, _("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	observersButtonSizer->Add( m_selectAllObservers, 0, wxALL, 5 );
	
	m_selectNoneObservers = new wxButton( this, wxID_ANY, _("Select None"), wxDefaultPosition, wxDefaultSize, 0 );
	m_selectNoneObservers->Enable( false );
	
	observersButtonSizer->Add( m_selectNoneObservers, 0, wxALL, 5 );
	
	m_invertObservers = new wxButton( this, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
	observersButtonSizer->Add( m_invertObservers, 0, wxALL, 5 );
	
	observersSizer->Add( observersButtonSizer, 1, wxEXPAND, 5 );
	
	wxArrayString m_observersCheckListChoices;
	m_observersCheckList = new wxCheckListBox( this, ID_OBSERVERS_CHECK_LIST, wxDefaultPosition, wxSize( 350,200 ), m_observersCheckListChoices, wxLB_MULTIPLE|wxLB_NEEDED_SB );
	m_observersCheckList->SetToolTip( _("Observers for this committee/council") );
	
	observersSizer->Add( m_observersCheckList, 0, wxALL|wxEXPAND, 5 );
	
	ncCountriesSizer->Add( observersSizer, 1, wxEXPAND, 5 );
	
	ncMainSizer->Add( ncCountriesSizer, 1, wxEXPAND|wxTOP, 5 );
	
	wxStaticBoxSizer* paramSizer;
	paramSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Settings:") ), wxVERTICAL );
	
	m_committeeNameStaticText = new wxStaticText( this, wxID_ANY, _("Committee/council name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_committeeNameStaticText->Wrap( -1 );
	paramSizer->Add( m_committeeNameStaticText, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_committeeNameTextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	paramSizer->Add( m_committeeNameTextCtrl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticTopicA = new wxStaticText( this, wxID_ANY, _("Topic A:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTopicA->Wrap( -1 );
	paramSizer->Add( m_staticTopicA, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_topicATextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	paramSizer->Add( m_topicATextCtrl, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticTopicB = new wxStaticText( this, wxID_ANY, _("Topic B:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTopicB->Wrap( -1 );
	paramSizer->Add( m_staticTopicB, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_topicBTextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	paramSizer->Add( m_topicBTextCtrl, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	wxBoxSizer* m_GSLtimeSizer;
	m_GSLtimeSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticDefaultGSLtime = new wxStaticText( this, wxID_ANY, _("Default GSL speaker time (sec):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDefaultGSLtime->Wrap( -1 );
	m_GSLtimeSizer->Add( m_staticDefaultGSLtime, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GSLspin = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 90 );
	m_GSLtimeSizer->Add( m_GSLspin, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM|wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	paramSizer->Add( m_GSLtimeSizer, 0, wxEXPAND, 5 );
	
	ncMainSizer->Add( paramSizer, 0, wxEXPAND, 5 );
	
	newCommitteeSizer->Add( ncMainSizer, 1, wxEXPAND, 5 );
	
	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();
	newCommitteeSizer->Add( m_sdbSizer3, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( newCommitteeSizer );
	this->Layout();
	newCommitteeSizer->Fit( this );
	
	// Connect Events
	m_selectAllMembers->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnSelectAllMembers ), NULL, this );
	m_selectNoneMembers->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnSelectNoneMembers ), NULL, this );
	m_invertMembers->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnInvertMembers ), NULL, this );
	m_membersCheckList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnMembersSelected ), NULL, this );
	m_membersCheckList->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnMembersToggle ), NULL, this );
	m_selectAllObservers->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnSelectAllObservers ), NULL, this );
	m_selectNoneObservers->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnSelectNoneObservers ), NULL, this );
	m_invertObservers->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnInvertObservers ), NULL, this );
	m_observersCheckList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnObserversSelected ), NULL, this );
	m_observersCheckList->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnObserversToggle ), NULL, this );
	m_sdbSizer3Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::CancelCommitteeInput ), NULL, this );
	m_sdbSizer3OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::ValidateNewCommitteeInput ), NULL, this );
}

GUI_NewCommitteeDialog::~GUI_NewCommitteeDialog()
{
	// Disconnect Events
	m_selectAllMembers->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnSelectAllMembers ), NULL, this );
	m_selectNoneMembers->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnSelectNoneMembers ), NULL, this );
	m_invertMembers->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnInvertMembers ), NULL, this );
	m_membersCheckList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnMembersSelected ), NULL, this );
	m_membersCheckList->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnMembersToggle ), NULL, this );
	m_selectAllObservers->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnSelectAllObservers ), NULL, this );
	m_selectNoneObservers->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnSelectNoneObservers ), NULL, this );
	m_invertObservers->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnInvertObservers ), NULL, this );
	m_observersCheckList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnObserversSelected ), NULL, this );
	m_observersCheckList->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_NewCommitteeDialog::OnObserversToggle ), NULL, this );
	m_sdbSizer3Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::CancelCommitteeInput ), NULL, this );
	m_sdbSizer3OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_NewCommitteeDialog::ValidateNewCommitteeInput ), NULL, this );
}

GUI_CountriesPresentDialog::GUI_CountriesPresentDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* membersPresentButtonSizer;
	membersPresentButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_selectAllButton = new wxButton( this, wxID_ANY, _("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	membersPresentButtonSizer->Add( m_selectAllButton, 0, wxALL, 5 );
	
	m_selectNoneButton = new wxButton( this, wxID_ANY, _("Select None"), wxDefaultPosition, wxDefaultSize, 0 );
	m_selectNoneButton->Enable( false );
	
	membersPresentButtonSizer->Add( m_selectNoneButton, 0, wxALL, 5 );
	
	m_invertButton = new wxButton( this, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
	membersPresentButtonSizer->Add( m_invertButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer64->Add( membersPresentButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* numPresentSizer;
	numPresentSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_numPresentLabelText = new wxStaticText( this, wxID_ANY, _("Currently present:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_numPresentLabelText->Wrap( -1 );
	m_numPresentLabelText->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	
	numPresentSizer->Add( m_numPresentLabelText, 0, wxALL, 5 );
	
	m_numPresentText = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_numPresentText->Wrap( -1 );
	m_numPresentText->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	
	numPresentSizer->Add( m_numPresentText, 0, wxALL, 5 );
	
	bSizer64->Add( numPresentSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxArrayString m_countriesPresentCheckListChoices;
	m_countriesPresentCheckList = new wxCheckListBox( this, COUNTRIES_PRESENT, wxDefaultPosition, wxSize( 350,350 ), m_countriesPresentCheckListChoices, wxLB_MULTIPLE|wxLB_NEEDED_SB|wxLB_SORT );
	bSizer64->Add( m_countriesPresentCheckList, 1, wxEXPAND|wxALL, 5 );
	
	m_sdbSizer8 = new wxStdDialogButtonSizer();
	m_sdbSizer8OK = new wxButton( this, wxID_OK );
	m_sdbSizer8->AddButton( m_sdbSizer8OK );
	m_sdbSizer8Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer8->AddButton( m_sdbSizer8Cancel );
	m_sdbSizer8->Realize();
	bSizer64->Add( m_sdbSizer8, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 5 );
	
	this->SetSizer( bSizer64 );
	this->Layout();
	bSizer64->Fit( this );
	
	// Connect Events
	m_selectAllButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_CountriesPresentDialog::OnSelectAll ), NULL, this );
	m_selectNoneButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_CountriesPresentDialog::OnSelectNone ), NULL, this );
	m_invertButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_CountriesPresentDialog::OnInvert ), NULL, this );
	m_countriesPresentCheckList->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_CountriesPresentDialog::OnCountriesPresentToggle ), NULL, this );
}

GUI_CountriesPresentDialog::~GUI_CountriesPresentDialog()
{
	// Disconnect Events
	m_selectAllButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_CountriesPresentDialog::OnSelectAll ), NULL, this );
	m_selectNoneButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_CountriesPresentDialog::OnSelectNone ), NULL, this );
	m_invertButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_CountriesPresentDialog::OnInvert ), NULL, this );
	m_countriesPresentCheckList->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_CountriesPresentDialog::OnCountriesPresentToggle ), NULL, this );
}

GUI_EditCommitteeDialog::GUI_EditCommitteeDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* editCommitteeSizer;
	editCommitteeSizer = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* editInstructionSizer;
	editInstructionSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Instructions") ), wxVERTICAL );
	
	editInstructions = new wxStaticText( this, wxID_ANY, _("1. Check the countries you would like to be a part of this committee or council.\n2. Optionally check any observers present. wxMUN always checks observers aren't already members.\n3. You can edit individual committee/council details by clicking on their names in the list.\n4. Click 'OK'."), wxDefaultPosition, wxSize( 350,70 ), wxST_NO_AUTORESIZE );
	editInstructions->Wrap( -1 );
	editInstructionSizer->Add( editInstructions, 0, wxALL|wxEXPAND, 5 );
	
	editCommitteeSizer->Add( editInstructionSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* m_membersObserversSizer;
	m_membersObserversSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Members and observers:") ), wxVERTICAL );
	
	wxArrayString m_membersCheckListChoices;
	m_membersCheckList = new wxCheckListBox( this, ID_EDIT_MEMBERS_CHECK_LIST, wxDefaultPosition, wxSize( 350,200 ), m_membersCheckListChoices, wxLB_MULTIPLE|wxLB_NEEDED_SB );
	m_membersCheckList->SetToolTip( _("Members of the committee/council") );
	
	m_membersObserversSizer->Add( m_membersCheckList, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline5 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_membersObserversSizer->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );
	
	wxArrayString m_observersCheckListChoices;
	m_observersCheckList = new wxCheckListBox( this, ID_EDIT_OBSERVERS_CHECK_LIST, wxDefaultPosition, wxSize( 350,200 ), m_observersCheckListChoices, wxLB_MULTIPLE|wxLB_NEEDED_SB );
	m_observersCheckList->SetToolTip( _("Members of the committee/council") );
	
	m_membersObserversSizer->Add( m_observersCheckList, 0, wxALL, 5 );
	
	bSizer8->Add( m_membersObserversSizer, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* paramSizer;
	paramSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Settings:") ), wxVERTICAL );
	
	m_committeeNameStaticText = new wxStaticText( this, wxID_ANY, _("Committee/council name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_committeeNameStaticText->Wrap( -1 );
	paramSizer->Add( m_committeeNameStaticText, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_committeeNameTextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	paramSizer->Add( m_committeeNameTextCtrl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticTopicA = new wxStaticText( this, wxID_ANY, _("Topic A:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTopicA->Wrap( -1 );
	paramSizer->Add( m_staticTopicA, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_topicATextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	paramSizer->Add( m_topicATextCtrl, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticTopicB = new wxStaticText( this, wxID_ANY, _("Topic B:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTopicB->Wrap( -1 );
	paramSizer->Add( m_staticTopicB, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_topicBTextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	paramSizer->Add( m_topicBTextCtrl, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	wxBoxSizer* m_GSLtimeSizer;
	m_GSLtimeSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticDefaultGSLtime = new wxStaticText( this, wxID_ANY, _("Default GSL speaker time (sec):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDefaultGSLtime->Wrap( -1 );
	m_GSLtimeSizer->Add( m_staticDefaultGSLtime, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GSLspin = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 90 );
	m_GSLtimeSizer->Add( m_GSLspin, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM|wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	paramSizer->Add( m_GSLtimeSizer, 0, wxEXPAND, 5 );
	
	bSizer8->Add( paramSizer, 0, wxEXPAND, 5 );
	
	editCommitteeSizer->Add( bSizer8, 1, wxEXPAND, 5 );
	
	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();
	editCommitteeSizer->Add( m_sdbSizer3, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( editCommitteeSizer );
	this->Layout();
	editCommitteeSizer->Fit( this );
	
	// Connect Events
	m_membersCheckList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_EditCommitteeDialog::OnMembersSelected ), NULL, this );
	m_membersCheckList->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_EditCommitteeDialog::OnMembersToggle ), NULL, this );
	m_observersCheckList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_EditCommitteeDialog::OnObserversSelected ), NULL, this );
	m_observersCheckList->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_EditCommitteeDialog::OnObserversToggle ), NULL, this );
	m_sdbSizer3Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_EditCommitteeDialog::CancelCommitteeInput ), NULL, this );
	m_sdbSizer3OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_EditCommitteeDialog::ValidateNewCommitteeInput ), NULL, this );
}

GUI_EditCommitteeDialog::~GUI_EditCommitteeDialog()
{
	// Disconnect Events
	m_membersCheckList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_EditCommitteeDialog::OnMembersSelected ), NULL, this );
	m_membersCheckList->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_EditCommitteeDialog::OnMembersToggle ), NULL, this );
	m_observersCheckList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_EditCommitteeDialog::OnObserversSelected ), NULL, this );
	m_observersCheckList->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( GUI_EditCommitteeDialog::OnObserversToggle ), NULL, this );
	m_sdbSizer3Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_EditCommitteeDialog::CancelCommitteeInput ), NULL, this );
	m_sdbSizer3OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_EditCommitteeDialog::ValidateNewCommitteeInput ), NULL, this );
}

GUI_ConfirmTopicSwapDialog::GUI_ConfirmTopicSwapDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_confirmTopicSwapText = new wxStaticText( this, wxID_ANY, _("You currenty already have a topic selected. Changing the topic is possible and allowed, but please bear in mind the side effects:\n\n1. The state of the debate on the current topic will be reset to a clean General Speakers List.\n2. Roll call votes are never stored and will be reset upon entering a new topic.\n3. Any old (current) settings in the current topic can not be retrieved! The state file is forever lost, if you want to keep the current GSL, save it under a different file name (File > Save State As)."), wxDefaultPosition, wxSize( 350,205 ), 0 );
	m_confirmTopicSwapText->Wrap( -1 );
	bSizer10->Add( m_confirmTopicSwapText, 1, wxEXPAND|wxRIGHT, 5 );
	
	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
	m_sdbSizer3->Realize();
	bSizer10->Add( m_sdbSizer3, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	bSizer9->Add( bSizer10, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer9 );
	this->Layout();
	bSizer9->Fit( this );
}

GUI_ConfirmTopicSwapDialog::~GUI_ConfirmTopicSwapDialog()
{
}

GUI_wxMUNAboutDialog::GUI_wxMUNAboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxVERTICAL );
	
	m_aboutLogo = new wxStaticBitmap( this, ABOUT_LOGO, wxNullBitmap, wxDefaultPosition, wxSize( 350,166 ), 0 );
	bSizer60->Add( m_aboutLogo, 0, wxALL, 5 );
	
	m_staticline18 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer60->Add( m_staticline18, 0, wxEXPAND | wxALL, 5 );
	
	m_aboutNotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel12 = new wxPanel( m_aboutNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl12 = new wxTextCtrl( m_panel12, ABOUT_DESCRIPTION, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxNO_BORDER|wxVSCROLL );
	bSizer61->Add( m_textCtrl12, 1, wxEXPAND, 0 );
	
	m_panel12->SetSizer( bSizer61 );
	m_panel12->Layout();
	bSizer61->Fit( m_panel12 );
	m_aboutNotebook->AddPage( m_panel12, _("Description"), false );
	m_panel13 = new wxPanel( m_aboutNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 5, 2, 0, 0 );
	fgSizer19->AddGrowableCol( 1 );
	fgSizer19->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText59 = new wxStaticText( m_panel13, wxID_ANY, _("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText59->Wrap( -1 );
	fgSizer19->Add( m_staticText59, 0, wxALL, 5 );
	
	m_staticText60 = new wxStaticText( m_panel13, ABOUT_NAME, _("nnn"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText60->Wrap( -1 );
	fgSizer19->Add( m_staticText60, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText61 = new wxStaticText( m_panel13, wxID_ANY, _("Version:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer19->Add( m_staticText61, 0, wxALL, 5 );
	
	m_staticText62 = new wxStaticText( m_panel13, ABOUT_VERSION, _("vvv"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	fgSizer19->Add( m_staticText62, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText63 = new wxStaticText( m_panel13, wxID_ANY, _("Author:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText63->Wrap( -1 );
	fgSizer19->Add( m_staticText63, 0, wxALL, 5 );
	
	m_staticText64 = new wxStaticText( m_panel13, ABOUT_AUTHOR, _("aaa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64->Wrap( -1 );
	fgSizer19->Add( m_staticText64, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText65 = new wxStaticText( m_panel13, wxID_ANY, _("E-mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText65->Wrap( -1 );
	fgSizer19->Add( m_staticText65, 0, wxALL, 5 );
	
	m_staticText66 = new wxStaticText( m_panel13, ABOUT_EMAIL, _("eee"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText66->Wrap( -1 );
	fgSizer19->Add( m_staticText66, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText88 = new wxStaticText( m_panel13, wxID_ANY, _("Homepage:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText88->Wrap( -1 );
	fgSizer19->Add( m_staticText88, 0, wxALL, 5 );
	
	m_hyperlink1 = new wxHyperlinkCtrl( m_panel13, wxID_ANY, _("http://wxmun.unitednetherlands.org"), wxT("http://wxmun.unitednetherlands.org"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	fgSizer19->Add( m_hyperlink1, 0, wxALL, 5 );
	
	bSizer62->Add( fgSizer19, 1, wxEXPAND, 5 );
	
	m_panel13->SetSizer( bSizer62 );
	m_panel13->Layout();
	bSizer62->Fit( m_panel13 );
	m_aboutNotebook->AddPage( m_panel13, _("Version"), false );
	m_panel14 = new wxPanel( m_aboutNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl121 = new wxTextCtrl( m_panel14, ABOUT_LICENSE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxNO_BORDER|wxVSCROLL );
	m_textCtrl121->SetFont( wxFont( 10, 76, 90, 90, false, wxT("Courier New") ) );
	m_textCtrl121->SetToolTip( _("wxMUN is licensed under the GPLv3.") );
	
	bSizer63->Add( m_textCtrl121, 1, wxEXPAND, 5 );
	
	m_panel14->SetSizer( bSizer63 );
	m_panel14->Layout();
	bSizer63->Fit( m_panel14 );
	m_aboutNotebook->AddPage( m_panel14, _("License"), true );
	
	bSizer60->Add( m_aboutNotebook, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	m_staticline19 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer60->Add( m_staticline19, 0, wxEXPAND | wxALL, 5 );
	
	m_aboutUNLlogobitmap = new wxStaticBitmap( this, UNL_LOGO_BITMAP, wxNullBitmap, wxDefaultPosition, wxSize( 165,47 ), 0 );
	bSizer60->Add( m_aboutUNLlogobitmap, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline20 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer60->Add( m_staticline20, 0, wxEXPAND | wxALL, 5 );
	
	m_closeAbout = new wxButton( this, wxID_CANCEL, _("&Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer60->Add( m_closeAbout, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer60 );
	this->Layout();
	bSizer60->Fit( this );
}

GUI_wxMUNAboutDialog::~GUI_wxMUNAboutDialog()
{
}

GUI_YieldDialog::GUI_YieldDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* yieldToDelegateSizer;
	yieldToDelegateSizer = new wxBoxSizer( wxVERTICAL );
	
	m_yieldToLabel = new wxStaticText( this, wxID_ANY, _("Yield to:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_yieldToLabel->Wrap( -1 );
	m_yieldToLabel->SetFont( wxFont( 10, 74, 90, 92, false, wxT("Sans") ) );
	
	yieldToDelegateSizer->Add( m_yieldToLabel, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_yieldToDelegateChoices = new wxListBox( this, YIELD_TO_DELEGATE_CHOICES, wxDefaultPosition, wxSize( 300,350 ), 0, NULL, wxLB_SINGLE|wxLB_SORT ); 
	yieldToDelegateSizer->Add( m_yieldToDelegateChoices, 1, wxALL|wxEXPAND, 5 );
	
	m_yieldOKButton = new wxButton( this, wxID_OK, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_yieldOKButton->Enable( false );
	
	yieldToDelegateSizer->Add( m_yieldOKButton, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	this->SetSizer( yieldToDelegateSizer );
	this->Layout();
	yieldToDelegateSizer->Fit( this );
	
	// Connect Events
	m_yieldToDelegateChoices->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_YieldDialog::OnHighlightDelegate ), NULL, this );
	m_yieldToDelegateChoices->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_YieldDialog::OnSelectDelegate ), NULL, this );
}

GUI_YieldDialog::~GUI_YieldDialog()
{
	// Disconnect Events
	m_yieldToDelegateChoices->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( GUI_YieldDialog::OnHighlightDelegate ), NULL, this );
	m_yieldToDelegateChoices->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUI_YieldDialog::OnSelectDelegate ), NULL, this );
}
