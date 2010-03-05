///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __gui__
#define __gui__

#include <wx/cshelp.h>
#include <wx/intl.h>

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/gauge.h>
#include <wx/button.h>
#include <wx/spinctrl.h>
#include <wx/choice.h>
#include <wx/listbox.h>
#include <wx/splitter.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>
#include <wx/scrolwin.h>
#include <wx/aui/auibook.h>
#include <wx/hyperlink.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/notebook.h>

///////////////////////////////////////////////////////////////////////////

#define MAIN_PANEL 1000
#define CURRENT_COMMITTEE 1001
#define CURRENT_TOPIC 1002
#define MEMBERS_PRESENT 1003
#define NO_MEMBERS_PRESENT_TEXT 1004
#define LOGO_BITMAP 1005
#define MUN_NOTEBOOK 1006
#define GSL_SPEAKER_FLAG 1007
#define GSL_SPEAKER 1008
#define GSL_GAUGE 1009
#define GSL_TIME_LEFT 1010
#define GSL_TOTAL_TIME 1011
#define GSL_YIELD 1012
#define GSL_NEXT 1013
#define RESUME_GSL 1014
#define PAUSE_GSL 1015
#define GSL_SPEAKER_TIME_MINUTES 1016
#define GSL_SPEAKER_TIME_SECONDS 1017
#define GSL_CHOICES 1018
#define GSL_LIST 1019
#define SINGLE_SPEAKER_FLAG 1020
#define SINGLE_SPEAKER_NAME 1021
#define SINGLE_SPEAKER_GAUGE 1022
#define SINGLE_SPEAKER_TIME_LEFT 1023
#define SINGLE_SPEAKER_TOTAL_TIME 1024
#define SINGLE_SPEAKER_MINUTES 1025
#define SINGLE_SPEAKER_SECONDS 1026
#define SINGLE_SPEAKER_CHOICES 1027
#define MOD_CAUCUS_SPEAKER_FLAG 1028
#define MOD_CAUCUS_SPEAKER 1029
#define MOD_CAUCUS_SPEAKER_GAUGE 1030
#define MOD_CAUCUS_SPEAKER_TIME_LEFT 1031
#define MOD_CAUCUS_TOTAL_SPEAKER_TIME 1032
#define MOD_CAUCUS_TOPIC 1033
#define MOD_CAUCUS_GAUGE 1034
#define MOD_CAUCUS_TIME_LEFT 1035
#define MOD_CAUCUS_TOTAL_TIME 1036
#define RESUME_MOD_CAUCUS 1037
#define PAUSE_MOD_CAUCUS 1038
#define NEW_MOD_CAUCUS_TOPIC 1039
#define NEW_MOD_CAUCUS_HOURS 1040
#define NEW_MOD_CAUCUS_MINUTES 1041
#define NEW_MOD_CAUCUS_SECONDS 1042
#define NEW_MOD_CAUCUS_ST_MINUTES 1043
#define NEW_MOD_CAUCUS_ST_SECONDS 1044
#define MOD_CAUCUS_CHOICES 1045
#define UNMOD_CAUCUS_TOPIC 1046
#define UNMOD_CAUCUS_GAUGE 1047
#define UNMOD_CAUCUS_TIME_LEFT 1048
#define UNMOD_CAUCUS_TOTAL_TIME 1049
#define NEW_UNMOD_CAUCUS_TOPIC 1050
#define NEW_UNMOD_CAUCUS_HOURS 1051
#define NEW_UNMOD_CAUCUS_MINUTES 1052
#define NEW_UNMOD_CAUCUS_SECONDS 1053
#define VOTING_ON 1054
#define VOTING_IN_FAVOUR 1055
#define VOTING_AGAINST 1056
#define VOTING_SPEAKER_FLAG 1057
#define VOTING_SPEAKER 1058
#define VOTING_GAUGE 1059
#define VOTING_TIME_LEFT 1060
#define VOTING_TOTAL_TIME 1061
#define VOTING_ON_CHOICES 1062
#define VOTING_TIME_MINUTES 1063
#define VOTING_TIME_SECONDS 1064
#define SPEAKING_IN_FAVOUR_CHOICES 1065
#define SPEAKING_IN_FAVOUR 1066
#define SPEAKING_AGAINST_CHOICES 1067
#define SPEAKING_AGAINST 1068
#define ROLL_CALL_FIRST_ROUND_CHOICES 1069
#define ROLL_CALL_SECOND_ROUND_CHOICES 1070
#define TOPIC_A_MENU 1071
#define TOPIC_B_MENU 1072
#define COUNTRIES_PRESENT_MENU 1073
#define VOTING_PROCEDURE_MENU 1074
#define ID_MEMBERS_CHECK_LIST 1075
#define ID_OBSERVERS_CHECK_LIST 1076
#define COUNTRIES_PRESENT 1077
#define ID_EDIT_MEMBERS_CHECK_LIST 1078
#define ID_EDIT_OBSERVERS_CHECK_LIST 1079
#define ABOUT_LOGO 1080
#define ABOUT_DESCRIPTION 1081
#define ABOUT_NAME 1082
#define ABOUT_VERSION 1083
#define ABOUT_AUTHOR 1084
#define ABOUT_EMAIL 1085
#define ABOUT_LICENSE 1086
#define UNL_LOGO_BITMAP 1087
#define YIELD_TO_DELEGATE_CHOICES 1088

///////////////////////////////////////////////////////////////////////////////
/// Class GUI_MainFrame
///////////////////////////////////////////////////////////////////////////////
class GUI_MainFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_mainPanel;
		wxStaticText* m_currentCommitteeLabel;
		wxStaticText* m_currentCommitteeText;
		wxStaticText* m_currentTopicLabel;
		wxStaticText* m_currentTopicText;
		wxStaticText* m_staticText67;
		wxStaticText* m_presentText;
		wxStaticText* m_noMembersPresentStaticText;
		wxStaticBitmap* m_logoBitmap;
		wxStaticLine* m_staticline1;
		wxAuiNotebook* m_mainauinotebook;
		wxPanel* m_GSLpanel;
		wxSplitterWindow* m_GSLsplitter;
		wxPanel* m_GSLleftpanel;
		wxPanel* m_GSLCountryPanel;
		wxStaticBitmap* m_GSLCountryFlag;
		wxStaticText* m_GSLSpeaker;
		wxGauge* m_GSLSpeechGauge;
		wxStaticText* m_GSL_timeleft;
		wxStaticText* m_GSLtimesep;
		wxStaticText* m_GSLtotaltime;
		wxButton* m_GSLYieldButton;
		wxButton* m_GSLNext;
		wxButton* m_GSLResumeButton;
		wxButton* m_GSLPauseButton;
		wxButton* m_GSLStopButton;
		wxPanel* m_GSLrightpanel;
		wxStaticText* m_GSLtimeText;
		wxSpinCtrl* m_GSLminutesSpinCtrl;
		wxSpinCtrl* m_GSLsecondsSpinCtrl;
		wxStaticLine* m_staticline152;
		wxChoice* m_GSLChoice;
		wxListBox* m_GSLList;
		wxButton* m_GSLUpButton;
		wxButton* m_GSLDownButton;
		wxButton* m_GSLDeleteButton;
		wxButton* m_GSLClearButton;
		wxPanel* m_singleSpeakerPanel;
		wxSplitterWindow* m_singleSpeakerCaucusSplitter;
		wxPanel* m_singleSpeakerCaucusLeftPanel;
		wxPanel* m_panel611;
		wxStaticBitmap* m_singleSpeakerCountryFlag;
		wxStaticText* m_singleSpeakerName;
		wxGauge* m_singleSpeakerTimeGauge;
		wxStaticText* m_singleSpeakerTimeleft;
		wxStaticText* m_timesep111;
		wxStaticText* m_totaltime111;
		
		wxButton* m_stopSingleSpeakerButton;
		wxPanel* m_singleSpeakerRightPanel;
		wxStaticText* m_staticText1011;
		wxStaticLine* m_staticline1411;
		wxStaticText* m_STlabel11;
		wxSpinCtrl* m_singleSpeakerMinutes;
		wxSpinCtrl* m_singleSpeakerSeconds;
		wxListBox* m_singleSpeakerCountryListBox;
		wxPanel* m_modCaucusPanel;
		wxSplitterWindow* m_modCaucusSplitter;
		wxPanel* m_modCaucusLeftPanel;
		wxPanel* m_panel61;
		wxStaticBitmap* m_modCaucusCountryFlag;
		wxStaticText* m_modCaucusSpeaker;
		wxGauge* m_modCaucusSpeakerTimeGauge;
		wxStaticText* m_modCaucustimeleft1;
		wxStaticText* m_timesep11;
		wxStaticText* m_totaltime11;
		
		wxPanel* m_panel62;
		wxStaticText* m_modCaucusTopic;
		wxGauge* m_modCaucusTimeGauge;
		wxStaticText* m_modCaucustimeleft;
		wxStaticText* m_timesep1;
		wxStaticText* m_totaltime1;
		wxButton* m_resumeModCaucus;
		wxButton* m_pauseModCaucus;
		wxButton* m_stopModCaucusButton1;
		wxPanel* m_modCaucusRightPanel;
		wxStaticText* m_staticText101;
		wxStaticLine* m_staticline141;
		wxStaticText* m_staticText41;
		wxTextCtrl* m_mod_caucus_topic;
		wxStaticText* m_durationText1;
		wxSpinCtrl* m_mod_caucus_durationHours;
		wxSpinCtrl* m_mod_caucus_durationMinutes;
		wxSpinCtrl* m_mod_caucus_durationSeconds;
		wxStaticText* m_STlabel1;
		wxSpinCtrl* m_mod_caucus_STminutes;
		wxSpinCtrl* m_mod_caucus_STseconds;
		wxButton* m_stopModCaucusButton11;
		wxStdDialogButtonSizer* m_modCaucus_sdbSizer;
		wxButton* m_modCaucus_sdbSizerOK;
		wxButton* m_modCaucus_sdbSizerCancel;
		wxStaticLine* m_staticline151;
		wxListBox* m_modCaucusCountryListBox;
		wxPanel* m_unModCaucusPanel;
		wxSplitterWindow* m_unModCaucusSplitter;
		wxPanel* m_unModCaucusLeftPanel;
		wxPanel* m_panel6;
		wxStaticText* m_unModCaucusTopic;
		wxGauge* m_UnModCaucusTimeGauge;
		wxStaticText* m_unmod_caucus_timeleft;
		wxStaticText* m_timesep;
		wxStaticText* m_unmod_caucus_totaltime;
		wxButton* m_stopUnModCaucusButton;
		wxPanel* m_unModCaucusRightPanel;
		wxStaticText* m_staticText10;
		wxStaticLine* m_staticline14;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_caucus_topic;
		wxStaticText* m_durationText;
		wxSpinCtrl* m_durationHours;
		wxSpinCtrl* m_durationMinutes;
		wxSpinCtrl* m_durationSeconds;
		wxButton* m_stopUnModCaucusButton1;
		wxStdDialogButtonSizer* m_unmodCaucus_sdbSizer;
		wxButton* m_unmodCaucus_sdbSizerOK;
		wxButton* m_unmodCaucus_sdbSizerCancel;
		wxStaticLine* m_staticline15;
		wxPanel* m_procVotingPanel;
		wxSplitterWindow* m_procVotingSplitter;
		wxPanel* m_procVotingLeftPanel;
		wxPanel* m_panel15;
		wxStaticText* m_votingReason;
		
		wxStaticText* m_votingInFavourLabel;
		wxStaticText* m_staticText78;
		wxStaticText* m_votingAgainstLabel;
		wxPanel* m_votingCountryPanel;
		wxStaticBitmap* m_VotingCountryFlag;
		wxStaticText* m_votingSpeaker;
		wxGauge* m_votingSpeechGauge;
		wxStaticText* m_voting_timeleft;
		wxStaticText* m_votingtimesep;
		wxStaticText* m_votingtotaltime;
		
		wxButton* m_votingStopButton;
		wxPanel* m_procVotingRightPanel;
		wxStaticText* m_votingOnLabel;
		wxChoice* m_votingOnChoice;
		wxStaticText* m_votingTimeText;
		wxSpinCtrl* m_votingMinutesSpinCtrl;
		wxSpinCtrl* m_votingSecondsSpinCtrl;
		wxChoice* m_inFavourChoice;
		wxListBox* m_speakingInFavourList;
		wxButton* m_inFavourUpButton;
		wxButton* m_inFavourDownButton;
		wxButton* m_inFavourDeleteButton;
		wxButton* m_inFavourClearButton;
		wxChoice* m_againstChoice;
		wxListBox* m_speakingAgainstList;
		wxButton* m_againstUpButton;
		wxButton* m_againstDownButton;
		wxButton* m_againstDeleteButton;
		wxButton* m_againstClearButton;
		wxPanel* m_rollCallVotePanel;
		wxStaticText* m_rollCallFirstRoundText;
		wxStaticLine* m_staticline16;
		wxListBox* m_rollCallFirstRoundChoices;
		wxStaticLine* m_staticline19;
		wxButton* m_rollCallFirstRoundYesButton;
		wxButton* m_rollCallFirstRoundNoButton;
		wxButton* m_rollCallFirstRoundYesWithRightsButton;
		wxButton* m_rollCallFirstRoundNoWithRightsButton;
		wxButton* m_rollCallFirstRoundAbstainButton;
		wxButton* m_rollCallFirstRoundPassButton;
		wxStaticText* m_rollCallSecondRoundText;
		wxStaticLine* m_staticline17;
		wxListBox* m_rollCallSecondRoundChoices;
		wxStaticLine* m_staticline20;
		wxButton* m_rollCallSecondRoundYesButton;
		wxButton* m_rollCallSecondRoundNoButton;
		wxButton* m_rollCallSecondRoundYesWithRightsButton;
		wxButton* m_rollCallSecondRoundNoWithRightsButton;
		wxButton* m_rollCallSecondRoundAbstainButton;
		wxButton* m_rollCallSecondRoundPassButton;
		wxScrolledWindow* m_scrolledWindow1;
		wxStaticText* m_rollCallOutcomeText;
		wxStaticLine* m_staticline18;
		wxStaticText* m_inFavourCountText;
		wxStaticText* m_inFavourCount;
		wxStaticText* m_againstCountText;
		wxStaticText* m_againstCount;
		wxStaticText* m_abstentionsCountText;
		wxStaticText* m_abstentionsCount;
		wxStaticText* m_vetoTextLabel;
		wxStaticText* m_vetoText;
		wxStaticText* m_outcomeLabelText;
		wxStaticText* m_outcomeTextPassed;
		wxStaticText* m_outcomeTextSep;
		wxStaticText* m_outcomeTextFailed;
		wxStaticLine* m_staticline26;
		wxCheckBox* m_rollCallConsensusCheckbox;
		wxRadioButton* m_noVetoRadioBtn;
		wxRadioButton* m_vetoRadioBtn;
		wxCheckBox* m_rollCallMinimumInFavourCheckbox;
		wxSpinCtrl* m_minimumInFavourSpin;
		wxStaticLine* m_staticline181;
		wxCheckBox* m_rollCallDisplayOutcome;
		wxStaticLine* m_staticline21;
		wxStaticText* m_rollCallVotingWithRightsLabel;
		wxListBox* m_rollCallVotingWithRights;
		wxButton* m_rollCallClearButton;
		wxPanel* m_bannerSizer;
		wxStaticText* m_bannerText;
		wxHyperlinkCtrl* m_bannerHyperlink;
		wxStatusBar* m_statusBar;
		wxMenuBar* m_menubar;
		wxMenu* m_fileMenu;
		wxMenu* m_viewMenu;
		wxMenu* m_committeeMenu;
		wxMenu* m_helpMenu;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnGSLYield( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLNext( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLResume( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLPause( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLStop( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLMinutesChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnGSLSecondsChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnGSLChoice( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLListSelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLUpClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLDownClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLDeleteClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGSLClearClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSingleSpeakerStop( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSingleSpeakerMinutesChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnSingleSpeakerSecondsChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnSingleSpeakerCountrySelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnModCaucusResume( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnModCaucusPause( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnModCaucusStop( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnModCaucusMinChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnModCaucusSecChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnModCaucusSTSecChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnModCaucusCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnModCaucusStart( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnModCaucusCountrySelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnUnModCaucusStop( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnUnModCaucusMinChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnUnModCaucusSecChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnUnModCaucusCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnUnModCaucusStart( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnVotingStopSpeaker( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnVotingOnChoice( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnVotingMinutesChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnVotingSecondsChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnSpeakingInFavourChoice( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSpeakingInFavourListSelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnInFavourUpClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnInFavourDownClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnInFavourDeleteClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnInFavourClearClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSpeakingAgainstChoice( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSpeakingAgainstListSelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAgainstUpClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAgainstDownClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAgainstDeleteClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAgainstClearClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallFirstRoundYes( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallFirstRoundNo( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallFirstRoundYesWithRights( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallFirstRoundNoWithRights( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallFirstRoundAbstain( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallFirstRoundPass( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallSecondRoundYes( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallSecondRoundNo( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallConsensusCheck( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallSCModeToggle( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallMimimunInFavourCheck( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallMinimumInFavourChange( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnRollCallDisplayOutcomeCheck( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallVotingWithRightsSpeakerSelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRollCallClearVotes( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnStateFileOpen( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnStateFileSaveAs( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ){ event.Skip(); }
		virtual void ToggleFullScreen( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTopicAMenuSelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTopicBMenuSelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCountriesPresentMenuSelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnStartVotingProcedureMenuSelect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnNewCommittee( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnLoadCommittee( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnEditCommittee( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxMenu* m_manageMenu;
		wxMenu* m_topicSelectorMenu;
		wxMenuItem* m_topicAMenuItem;
		wxMenuItem* m_topicBMenuItem;
		wxMenuItem* m_countriesPresentMenuItem;
		GUI_MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,780 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~GUI_MainFrame();
		void m_GSLsplitterOnIdle( wxIdleEvent& )
		{
		m_GSLsplitter->SetSashPosition( 800 );
		m_GSLsplitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_GSLsplitterOnIdle ), NULL, this );
		}
		
		void m_singleSpeakerCaucusSplitterOnIdle( wxIdleEvent& )
		{
		m_singleSpeakerCaucusSplitter->SetSashPosition( 576 );
		m_singleSpeakerCaucusSplitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_singleSpeakerCaucusSplitterOnIdle ), NULL, this );
		}
		
		void m_modCaucusSplitterOnIdle( wxIdleEvent& )
		{
		m_modCaucusSplitter->SetSashPosition( 576 );
		m_modCaucusSplitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_modCaucusSplitterOnIdle ), NULL, this );
		}
		
		void m_unModCaucusSplitterOnIdle( wxIdleEvent& )
		{
		m_unModCaucusSplitter->SetSashPosition( 576 );
		m_unModCaucusSplitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_unModCaucusSplitterOnIdle ), NULL, this );
		}
		
		void m_procVotingSplitterOnIdle( wxIdleEvent& )
		{
		m_procVotingSplitter->SetSashPosition( 800 );
		m_procVotingSplitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( GUI_MainFrame::m_procVotingSplitterOnIdle ), NULL, this );
		}
		
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUI_NewCommitteeDialog
///////////////////////////////////////////////////////////////////////////////
class GUI_NewCommitteeDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* ncInstructions;
		wxStaticText* m_membersButtonText;
		wxButton* m_selectAllMembers;
		wxButton* m_selectNoneMembers;
		wxButton* m_invertMembers;
		wxCheckListBox* m_membersCheckList;
		wxStaticLine* m_staticline15;
		wxStaticText* m_observersButtonText;
		wxButton* m_selectAllObservers;
		wxButton* m_selectNoneObservers;
		wxButton* m_invertObservers;
		wxCheckListBox* m_observersCheckList;
		wxStaticText* m_committeeNameStaticText;
		wxTextCtrl* m_committeeNameTextCtrl;
		wxStaticText* m_staticTopicA;
		wxTextCtrl* m_topicATextCtrl;
		wxStaticText* m_staticTopicB;
		wxTextCtrl* m_topicBTextCtrl;
		wxStaticText* m_staticDefaultGSLtime;
		wxSpinCtrl* m_GSLspin;
		wxStdDialogButtonSizer* m_sdbSizer3;
		wxButton* m_sdbSizer3OK;
		wxButton* m_sdbSizer3Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectAllMembers( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectNoneMembers( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnInvertMembers( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnMembersSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnMembersToggle( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectAllObservers( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectNoneObservers( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnInvertObservers( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnObserversSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnObserversToggle( wxCommandEvent& event ){ event.Skip(); }
		virtual void CancelCommitteeInput( wxCommandEvent& event ){ event.Skip(); }
		virtual void ValidateNewCommitteeInput( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUI_NewCommitteeDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("New committee"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE );
		~GUI_NewCommitteeDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUI_CountriesPresentDialog
///////////////////////////////////////////////////////////////////////////////
class GUI_CountriesPresentDialog : public wxDialog 
{
	private:
	
	protected:
		wxButton* m_selectAllButton;
		wxButton* m_selectNoneButton;
		wxButton* m_invertButton;
		wxStaticText* m_numPresentLabelText;
		wxStaticText* m_numPresentText;
		wxCheckListBox* m_countriesPresentCheckList;
		wxStdDialogButtonSizer* m_sdbSizer8;
		wxButton* m_sdbSizer8OK;
		wxButton* m_sdbSizer8Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectAll( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectNone( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnInvert( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCountriesPresentToggle( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUI_CountriesPresentDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Countries present"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~GUI_CountriesPresentDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUI_EditCommitteeDialog
///////////////////////////////////////////////////////////////////////////////
class GUI_EditCommitteeDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* editInstructions;
		wxCheckListBox* m_membersCheckList;
		wxStaticLine* m_staticline5;
		wxCheckListBox* m_observersCheckList;
		wxStaticText* m_committeeNameStaticText;
		wxTextCtrl* m_committeeNameTextCtrl;
		wxStaticText* m_staticTopicA;
		wxTextCtrl* m_topicATextCtrl;
		wxStaticText* m_staticTopicB;
		wxTextCtrl* m_topicBTextCtrl;
		wxStaticText* m_staticDefaultGSLtime;
		wxSpinCtrl* m_GSLspin;
		wxStdDialogButtonSizer* m_sdbSizer3;
		wxButton* m_sdbSizer3OK;
		wxButton* m_sdbSizer3Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnMembersSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnMembersToggle( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnObserversSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnObserversToggle( wxCommandEvent& event ){ event.Skip(); }
		virtual void CancelCommitteeInput( wxCommandEvent& event ){ event.Skip(); }
		virtual void ValidateNewCommitteeInput( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUI_EditCommitteeDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit committee"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP );
		~GUI_EditCommitteeDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUI_ConfirmTopicSwapDialog
///////////////////////////////////////////////////////////////////////////////
class GUI_ConfirmTopicSwapDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_confirmTopicSwapText;
		wxStdDialogButtonSizer* m_sdbSizer3;
		wxButton* m_sdbSizer3OK;
		wxButton* m_sdbSizer3Cancel;
	
	public:
		GUI_ConfirmTopicSwapDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Confirm topic change"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~GUI_ConfirmTopicSwapDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUI_wxMUNAboutDialog
///////////////////////////////////////////////////////////////////////////////
class GUI_wxMUNAboutDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticBitmap* m_aboutLogo;
		wxStaticLine* m_staticline18;
		wxNotebook* m_aboutNotebook;
		wxPanel* m_panel12;
		wxTextCtrl* m_textCtrl12;
		wxPanel* m_panel13;
		wxStaticText* m_staticText59;
		wxStaticText* m_staticText60;
		wxStaticText* m_staticText61;
		wxStaticText* m_staticText62;
		wxStaticText* m_staticText63;
		wxStaticText* m_staticText64;
		wxStaticText* m_staticText65;
		wxStaticText* m_staticText66;
		wxStaticText* m_staticText88;
		wxHyperlinkCtrl* m_hyperlink1;
		wxPanel* m_panel14;
		wxTextCtrl* m_textCtrl121;
		wxStaticLine* m_staticline19;
		wxStaticLine* m_staticline20;
		wxButton* m_closeAbout;
	
	public:
		wxStaticBitmap* m_aboutUNLlogobitmap;
		GUI_wxMUNAboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("About wxMUN"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~GUI_wxMUNAboutDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUI_YieldDialog
///////////////////////////////////////////////////////////////////////////////
class GUI_YieldDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_yieldToLabel;
		wxListBox* m_yieldToDelegateChoices;
		wxButton* m_yieldOKButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnHighlightDelegate( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectDelegate( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUI_YieldDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Yield to other delegate"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~GUI_YieldDialog();
	
};

#endif //__gui__
