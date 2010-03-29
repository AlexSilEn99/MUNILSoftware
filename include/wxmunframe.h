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

#ifndef __mainframe__
#define __mainframe__

/**
@file
Subclass of GUI_MainFrame, which is generated by wxFormBuilder.
*/

#include "../src/gui.h"
#include "country.h"
#include <wx/mstream.h>
#include <deque>

#define CAUCUS_SPEAKER_TIMER 9000
#define VOTING_SPEAKER_TIMER 9001
#define GSL_SPEAKER_TIMER 9002
#define SINGLE_SPEAKER_TIMER 9003
#define UNMOD_CAUCUS_TIMER  9004
#define MOD_CAUCUS_TIMER  9005

#define wxGetBitmapFromMemory(name) _wxGetBitmapFromMemory(name ## _png, sizeof(name ## _png))
inline wxBitmap _wxGetBitmapFromMemory(const unsigned char *data, int length) {
        wxMemoryInputStream is(data, length);
        return wxBitmap(wxImage(is, wxBITMAP_TYPE_ANY, -1), -1);
}

/** Implementing GUI_MainFrame */
class wxMUNFrame : public GUI_MainFrame {

protected:
        wxStaticBitmap* m_logoBitmap;

        // Handlers for GUI_MainFrame events.
        void ToggleFullScreen( wxCommandEvent& event );
        void StopAllSpeakers();

        // GSL stuff
        void OnGSLStop( wxCommandEvent& event );
        void StopGSL();
        void OnGSLPause( wxCommandEvent& event );
        void PauseGSL();
        void OnGSLResume( wxCommandEvent& event );
        void ResumeGSL();
        void OnGSLNext( wxCommandEvent& event );
        void OnGSLYield( wxCommandEvent& event );
        void EnableGSLPauseButton();
        void EnableGSLResumeButton();
        void EnableGSLNextButton();
        void EnableGSLStopButton();
        void DisableGSLPauseButton();
        void DisableGSLResumeButton();
        void DisableGSLNextButton();
        void DisableGSLStopButton();
        void EnableGSLYieldButton();
        void DisableGSLYieldButton();

        //Single speaker
        void OnSingleSpeakerMinutesChange ( wxSpinEvent& event);
        void OnSingleSpeakerSecondsChange ( wxSpinEvent& event);
        void OnSingleSpeakerTimeChange();
        void OnSingleSpeakerCountrySelect( wxCommandEvent& event );
        void StartSingleSpeaker(wxString);
        void OnSingleSpeakerStop( wxCommandEvent& event );
        void ResetSingleSpeakerLabels();
        void StopSingleSpeaker();
        void OnSingleSpeakerPause( wxCommandEvent& event );
        void OnSingleSpeakerResume( wxCommandEvent& event );
        void PauseSingleSpeaker();
        void ResumeSingleSpeaker();
        
        // caucus stuff
        void OnModCaucusStart( wxCommandEvent& event );
        void OnUnModCaucusStart( wxCommandEvent& event );
        void OnModCaucusCountrySelect( wxCommandEvent& event );
        void OnModCaucusCancel( wxCommandEvent& event );
        void OnUnModCaucusCancel( wxCommandEvent& event );
        void OnModCaucusStop( wxCommandEvent& event );
        void OnUnModCaucusStop( wxCommandEvent& event );
        void OnModCaucusResume( wxCommandEvent& event );
        void OnModCaucusPause( wxCommandEvent& event );
        void PauseModCaucus();
        void ResumeModCaucus();
        void EnableModCaucusPauseButton();
        void DisableModCaucusPauseButton(bool enableResumeButton=true);
        
        void OnStateFileOpen( wxCommandEvent& event );
        void OnStateFileSaveAs( wxCommandEvent& event );
        void OnQuit( wxCommandEvent& event );

        void OnNewCommittee( wxCommandEvent& event );
        void OnLoadCommittee( wxCommandEvent& event );
        void OnEditCommittee( wxCommandEvent& event );

        void OnHelp( wxCommandEvent& event );
        void OnAbout( wxCommandEvent& event );

        void OnTopicAMenuSelect ( wxCommandEvent& event);
        void OnTopicBMenuSelect ( wxCommandEvent& event);
        
        void OnCountriesPresentMenuSelect ( wxCommandEvent& event);

        // Roll call
        void OnStartVotingProcedureMenuSelect( wxCommandEvent& event);
        void OnRollCallDisplayOutcomeCheck(wxCommandEvent& event);
        void OnRollCallConsensusCheck(wxCommandEvent& event);
        void OnRollCallMimimunInFavourCheck(wxCommandEvent& event);
        void OnRollCallMinimumInFavourChange( wxSpinEvent& event);
        void OnRollCallSCModeToggle(wxCommandEvent& event);

        wxString RollCallGetName(wxListBox*);
        wxString RollCallGetFirstRoundName(bool isPass=false);
        wxString RollCallGetSecondRoundName();

        void OnRollCallFirstRoundYes(wxCommandEvent& event);
        void OnRollCallFirstRoundNo(wxCommandEvent& event);
        void OnRollCallFirstRoundYesWithRights(wxCommandEvent& event);
        void OnRollCallFirstRoundNoWithRights(wxCommandEvent& event);
        void OnRollCallFirstRoundAbstain(wxCommandEvent& event);
        void OnRollCallFirstRoundPass(wxCommandEvent& event);

        void OnRollCallSecondRoundYes(wxCommandEvent& event);
        void OnRollCallSecondRoundNo(wxCommandEvent& event);

        void OnRollCallClearVotes(wxCommandEvent& event);
        void OnRollCallVotingWithRightsSpeakerSelect(wxCommandEvent& event);

        void EnableAndResetRollCallCtrls();
        void DisableRollCallCtrls();

        void StartRollCallSecondRound(bool lastIsPass = false);
        void ToggleRollCallVetoLabels();
        void DisplayRollCallOutcome();
        
        // GSL time change events
        void OnGSLMinutesChange ( wxSpinEvent& event);
        void OnGSLSecondsChange ( wxSpinEvent& event);
        void OnGSLTimeChange();
        
        void updateGSLdata(wxListBox *, bool saveState=true);
        void OnGSLListSelect( wxCommandEvent& event );
        void StartNextGSLSpeaker(wxListBox*);
        void OnGSLUpClick( wxCommandEvent& event );
        void OnGSLDownClick( wxCommandEvent& event );
        void OnGSLDeleteClick( wxCommandEvent& event );
        void OnGSLClearClick( wxCommandEvent& event );
        void OnGSLChoice( wxCommandEvent& event );
        
        // voting time change events
        void OnVotingMinutesChange ( wxSpinEvent& event);
        void OnVotingSecondsChange ( wxSpinEvent& event);
        void OnVotingTimeChange();

        // mod caucus time change event
        void OnModCaucusMinChange ( wxSpinEvent& event);
        void OnModCaucusSecChange ( wxSpinEvent& event);
        void OnModCaucusSTSecChange ( wxSpinEvent& event);
        void OnModCaucusTimeChange();

        // unmod caucus time change event
        void OnUnModCaucusMinChange ( wxSpinEvent& event);
        void OnUnModCaucusSecChange ( wxSpinEvent& event);
        void OnUnModCaucusTimeChange();

        // voting list events
        void OnVotingOnChoice( wxCommandEvent& event );
        void OnSpeakingInFavourListSelect( wxCommandEvent& event );
        void OnInFavourUpClick( wxCommandEvent& event );
        void OnInFavourDownClick( wxCommandEvent& event );
        void OnInFavourDeleteClick( wxCommandEvent& event );
        void OnInFavourClearClick( wxCommandEvent& event );
        void OnSpeakingInFavourChoice( wxCommandEvent& event );
        void OnSpeakingAgainstListSelect( wxCommandEvent& event );
        void OnAgainstUpClick( wxCommandEvent& event );
        void OnAgainstDownClick( wxCommandEvent& event );
        void OnAgainstDeleteClick( wxCommandEvent& event );
        void OnAgainstClearClick( wxCommandEvent& event );
        void OnSpeakingAgainstChoice( wxCommandEvent& event);
        void OnVotingStopSpeaker( wxCommandEvent& event);
        void StopVotingSpeaker();
        
        // timer events
        void OnCaucusSpeakerTimerEvent ( wxTimerEvent& event);
        void OnVotingSpeakerTimerEvent ( wxTimerEvent& event);
        void OnGSLSpeakerTimerEvent ( wxTimerEvent& event);
        void OnSingleSpeakerTimerEvent ( wxTimerEvent& event);
        void OnUnModCaucusTimerEvent ( wxTimerEvent& event);
        void OnModCaucusTimerEvent ( wxTimerEvent& event);

        // rest are utilities to enable/disable labels and texts
        void DisableModCaucusChoices();

        void ResetModCaucusSpeakerLabels(bool clearTotal=false);
        void ResetModCaucusLabels(bool clearCtrls=true, bool clearSpeakerTotal=true);
        void ResetUnModCaucusLabels();
        void StopModCaucus(bool clearSpeakerCtrls=true);
        void StopUnModCaucus();
        void ClearModCaucusInput();
        void ClearUnModCaucusInput();
        void DisableModCaucusCtrls(bool DisableResumeButton=true);
        void EnableModCaucusCtrls(bool enablePauseButton=true);
        void DisableUnModCaucusCtrls();
        void EnableUnModCaucusCtrls();
        void DisableCaucusCtrls();
        void EnableCaucusCtrls();

        void DisableVotingCtrls();
        void EnableVotingCtrls();
        void DisableVotingTimeCtrls();
        void EnableVotingTimeCtrls();
        
        void DisableGSLCtrls(bool disableChoice = true);
        void EnableGSLCtrls();
        void DisableGSLTimerCtrls();
        void EnableGSLTimerCtrls();

        void DisableSingleSpeakerCtrls();
        void EnableSingleSpeakerCtrls();
        void EnableSingleSpeakerPauseButton();
        void DisableSingleSpeakerPauseButton();
        void EnableSingleSpeakerResumeButton();
        void DisableSingleSpeakerResumeButton();
        void DisableSingleSpeakerTimerCtrls();
        void EnableSingleSpeakerTimerCtrls();
        
        bool ConfirmTopicSwap();
        void NoInitDialog();
        void SetWindowTitle(wxString);

        // The Path to the file we have open
        wxString CurrentDocPath;
        
public:
        /** Constructor */
        wxMUNFrame( wxWindow* parent );

        void updateGSLListBox(std::deque<Country*> *);
        void LoadSetLabels();
        void SetCurrentDocPath(wxString);
        wxString GetCurrentDocPath();
        
private:
        DECLARE_EVENT_TABLE()
        
        // Speaker timers (seperate because of seperate gauges)
        wxTimer _caucusSpeakerTimer;
        wxTimer _votingSpeakerTimer;
        wxTimer _GSLSpeakerTimer;
        wxTimer _singleSpeakerTimer;
        wxTimer _unmodCaucusTimer; //need seperate counter id & var
        wxTimer _modCaucusTimer;

        bool _GSLtimerPaused;
        bool _timerPaused;
        bool _caucusRunning;
        bool _speakerRunning;
        bool _GSLspeakerRunning;

        // GSL needs own vars because of possibility of yield to questions
        int _GSLspeakerSeconds;
        int _GSLspeakerLength; 

        int _speakerSeconds;
        int _speakerLength;

        // mod & unmod cannot be at the same time, so we use the same variables
        int _caucusSeconds;
        int _caucusLength;

};

#endif // __mainframe__
