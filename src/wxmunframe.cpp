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

#include <wx/image.h>
#include <wx/file.h>
#include <wx/filedlg.h>
#include <wx/aboutdlg.h>
#include <wx/progdlg.h>
#include <wx/string.h>
#include <wx/colour.h>
#include <wx/choice.h>
#include <map>

#include "country.h"
#include "app.h"
#include "wxmunframe.h"
#include "defs.h"
#include "confirmtopicswapdialog.h"
#include "newcommitteedialog.h"
#include "editcommitteedialog.h"
#include "configmanager.h"
#include "wxmunaboutdialog.h"
#include "countriespresentdialog.h"
#include "yielddialog.h"
#include "clear_png.h"
#include "unl_logo.h"
#include "rollcallvote.h"

#ifdef HAVE_CONFIG_H
 #include "../config.h"
#endif

//TODO: the various up/down/clear functions should be combined into e..g. a template!

// silly utility
// TODO: we should inherit from wxListBox and make this a new member
void swapListStrings(wxListBox *l, int i, int j) {
        wxString i_str = l->GetString(i);
        wxString j_str = l->GetString(j);

        l->SetString(i, j_str);
        l->SetString(j, i_str);
}

//another silly utility
void realTime(int &hrs, int &min, int &sec) {
        if(sec == 60 && min < 59) {
                min++; sec=0;
        } else if (sec == 60 && min == 59 && hrs < 100) {
                hrs++; min=0; sec=0;
        } else if (sec == 60) {
                sec = 59;
        } else if(sec == -1 && min > 0) {
                min--; sec=59;
        } else if (sec == -1 && min == 0 && hrs > 0) {
                hrs--; min--; sec = 0;
        } else if (sec == -1) {
                sec = 0;
        }
}

//another overloaded silly utility
void realTime(int &min, int &sec) {
        if(sec == 60 && min < 59) {
                min++; sec=0;
        } else if (sec == 60 && min == 59) {
                sec = 59;
        } else if(sec == -1 && min > 0) {
                min--; sec=59;
        } else if (sec == -1) {
                sec = 0;
        }
}

// utility to clear progress bar with label and time
void clearTimerLabels(int gauge_id, int time_id, int label_id, int flag_id=0, bool withHrs = false) {

        wxStaticText *timeLeft = (wxStaticText*) wxWindow::FindWindowById(time_id);
        if(withHrs) {
                timeLeft->SetLabel(wxString::Format(wxT("00:00:00")));
        } else {
                timeLeft->SetLabel(wxString::Format(wxT("00:00")));
        }

        timeLeft->SetForegroundColour(wxColour(wxT("BLACK")));

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(gauge_id);
        progressBar->SetValue(0);

        wxStaticText *text =  (wxStaticText*) wxWindow::FindWindowById(label_id);
        text->SetLabel(wxT(""));

        if(flag_id != 0) {
                //clear flag
        }
}

// put a fully transparent PNG back to remove the flag
void clearCountryFlag(int id) {
        wxStaticBitmap *f = (wxStaticBitmap*) wxWindow::FindWindowById(id);
        wxImage flag;

        f->SetBitmap(wxGetBitmapFromMemory(clear));                
}

// utility to set country flag
void setCountryFlag(int id, wxString name) {
        wxStaticBitmap *f = (wxStaticBitmap*) wxWindow::FindWindowById(id);
        wxImage flag;        

        clearCountryFlag(id);

#ifdef DEBUG
        std::cout << "setCountryFlag(): loading " << wxGetApp().findCountryFlagByName(name) << std::endl;
#endif
        
        if( !wxFile::Exists(wxGetApp().findCountryFlagByName(name)) ) {
#ifdef DEBUG
                std::cout << "setCountryFlag(): file does not exist" << std::endl;
#endif
                return;
        }

        if ( !flag.LoadFile(wxGetApp().findCountryFlagByName(name))) {
#ifdef DEBUG
                std::cout << "setCountryFlag(): image cannot load " << std::endl;
#endif
                return;
        }

        // scale the image, preserving the aspect ratio
        int w = flag.GetWidth();
        int h = flag.GetHeight();
        int newW, newH;
        if (w > h) {
                newW = 150;
                newH = 150 * h / w;
        } else {
                newH = 100;
                newW = 100 * w / h;
        }
        
        flag = flag.Scale(newW,newH);

        wxBitmap fb(flag);
        f->SetBitmap(fb);
}

wxMUNFrame::wxMUNFrame( wxWindow* parent )
:
GUI_MainFrame( parent ), 
_caucusSpeakerTimer(this,CAUCUS_SPEAKER_TIMER),
_votingSpeakerTimer(this,VOTING_SPEAKER_TIMER),
_GSLSpeakerTimer(this,GSL_SPEAKER_TIMER),
_singleSpeakerTimer(this,SINGLE_SPEAKER_TIMER),
_unmodCaucusTimer(this, UNMOD_CAUCUS_TIMER),
_modCaucusTimer(this, MOD_CAUCUS_TIMER)
{
        _speakerRunning = false; _GSLtimerPaused = false; _timerPaused = false; _caucusRunning = false;
        _caucusSeconds = 0; _speakerSeconds = 0;
        
        DisableCaucusCtrls();
        DisableVotingCtrls();
        DisableGSLCtrls();

        // disable caucus resume button        (enabled by disable caucus ctrls)
        wxButton *resumeButton = (wxButton*) wxWindow::FindWindowById(RESUME_MOD_CAUCUS);
        resumeButton->Enable(false);

        //set logo
        wxStaticBitmap *l = (wxStaticBitmap*) wxWindow::FindWindowById(LOGO_BITMAP);
        wxImage logo;

        if(!logo.LoadFile(ConfigManager::FindResourceFile(wxT("logo.png"))))
                return; //display might get corrupted, but that's better than a segfault!

        wxBitmap lb(logo);
        l->SetBitmap(lb);
}

void wxMUNFrame::SetCurrentDocPath(wxString filename) {
        CurrentDocPath = filename;
}

void wxMUNFrame::StopAllSpeakers() {
        StopGSL();
        StopModCaucus();
        StopUnModCaucus();
        StopVotingSpeaker();
        StopSingleSpeaker();
}

wxString wxMUNFrame::GetCurrentDocPath() {
        return CurrentDocPath;
}

void wxMUNFrame::NoInitDialog() {
        wxString message;

        if(!wxGetApp().isCommitteeLoaded())
                message << wxT("Error: you have not loaded any committee or council yet");
        else if(!wxGetApp().session()->topicChosen())
                message << wxT("Error: the committee/council has not yet chosen the topic to discuss!");

        wxMessageBox(message,
                wxT("Cannot execute action"),
                wxICON_ERROR | wxOK, this);
}

void wxMUNFrame::ToggleFullScreen( wxCommandEvent& event ) {
        if(IsFullScreen())
                ShowFullScreen(false);
        else
                ShowFullScreen(true); 
}

void wxMUNFrame::EnableCaucusCtrls() {
        EnableModCaucusCtrls(false);
        EnableUnModCaucusCtrls();

        DisableModCaucusChoices();
}

void wxMUNFrame::DisableModCaucusChoices() {
        wxListBox *modCaucusChoices = (wxListBox*) wxWindow::FindWindowById(MOD_CAUCUS_CHOICES);
        modCaucusChoices->Enable(false);
}

void wxMUNFrame::DisableCaucusCtrls() {
        DisableModCaucusCtrls();
        DisableUnModCaucusCtrls();
}

void wxMUNFrame::EnableModCaucusPauseButton() {
        wxButton *pauseButton = (wxButton*) wxWindow::FindWindowById(PAUSE_MOD_CAUCUS);
        wxButton *resumeButton = (wxButton*) wxWindow::FindWindowById(RESUME_MOD_CAUCUS);
                
        pauseButton->Enable(true); resumeButton->Enable(false);
}

void wxMUNFrame::DisableModCaucusPauseButton(bool enableResumeButton) { //true by default
        wxButton *pauseButton = (wxButton*) wxWindow::FindWindowById(PAUSE_MOD_CAUCUS);
        wxButton *resumeButton = (wxButton*) wxWindow::FindWindowById(RESUME_MOD_CAUCUS);
                
        pauseButton->Enable(false); resumeButton->Enable(enableResumeButton);
}

void wxMUNFrame::EnableModCaucusCtrls(bool enablePauseButton) {
        wxTextCtrl *topicCtrl = (wxTextCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_TOPIC);

        wxSpinCtrl *hours   = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_HOURS);
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_SECONDS);
        wxSpinCtrl *ST_minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_MINUTES);
        wxSpinCtrl *ST_seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_SECONDS);

        topicCtrl->Enable(true);
        hours->Enable(true); minutes->Enable(true); seconds->Enable(true);
        ST_minutes->Enable(true); ST_seconds->Enable(true);

        if(enablePauseButton)
                EnableModCaucusPauseButton();
}

void wxMUNFrame::DisableModCaucusCtrls(bool DisableResumeButton) {
        wxTextCtrl *topicCtrl = (wxTextCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_TOPIC);

        wxSpinCtrl *hours   = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_HOURS);
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_SECONDS);
        wxSpinCtrl *ST_minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_MINUTES);
        wxSpinCtrl *ST_seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_SECONDS);

        topicCtrl->Enable(false);
        hours->Enable(false); minutes->Enable(false); seconds->Enable(false);
        ST_minutes->Enable(false); ST_seconds->Enable(false);

        DisableModCaucusPauseButton(!DisableResumeButton);
}

void wxMUNFrame::EnableUnModCaucusCtrls() {
        wxTextCtrl *topicCtrl = (wxTextCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_TOPIC);

        wxSpinCtrl *hours   = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_HOURS);
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_SECONDS);

        topicCtrl->Enable(true);
        hours->Enable(true); minutes->Enable(true); seconds->Enable(true);
}

void wxMUNFrame::DisableUnModCaucusCtrls() {
        wxTextCtrl *topicCtrl = (wxTextCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_TOPIC);

        wxSpinCtrl *hours   = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_HOURS);
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_SECONDS);

        topicCtrl->Enable(false);
        hours->Enable(false); minutes->Enable(false); seconds->Enable(false);
}

void wxMUNFrame::ClearModCaucusInput() {
        wxTextCtrl *topicCtrl = (wxTextCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_TOPIC);
        topicCtrl->Clear();

        wxSpinCtrl *hours   = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_HOURS);
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_SECONDS);
        wxSpinCtrl *ST_minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_MINUTES);
        wxSpinCtrl *ST_seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_SECONDS);

        hours->SetValue(0);
        minutes->SetValue(5);
        seconds->SetValue(0);

        ST_minutes->SetValue(0);
        ST_seconds->SetValue(30);
}

void wxMUNFrame::ClearUnModCaucusInput() {
        wxTextCtrl *topicCtrl = (wxTextCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_TOPIC);
        topicCtrl->Clear();

        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_SECONDS);

        minutes->SetValue(5);
        seconds->SetValue(0);
}

void wxMUNFrame::DisableVotingTimeCtrls() {
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(VOTING_TIME_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(VOTING_TIME_SECONDS);
        minutes->Enable(false); seconds->Enable(false);
}

void wxMUNFrame::EnableVotingTimeCtrls() {
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(VOTING_TIME_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(VOTING_TIME_SECONDS);
        minutes->Enable(true); seconds->Enable(true);
}

void wxMUNFrame::EnableVotingCtrls() {
        wxChoice *inFavourChoices = (wxChoice*) (wxWindow::FindWindowById(SPEAKING_IN_FAVOUR_CHOICES));
        wxChoice *againstChoices = (wxChoice*) (wxWindow::FindWindowById(SPEAKING_AGAINST_CHOICES));

        wxChoice *votingOn = (wxChoice*) (wxWindow::FindWindowById(VOTING_ON_CHOICES));

        wxListBox *inFavourList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR);
        wxListBox *againstList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_AGAINST);

        inFavourChoices->Enable(true); inFavourList->Enable(true);
        againstChoices->Enable(true); againstList->Enable(true);
        votingOn->Enable(true);

        EnableVotingTimeCtrls();
}

void wxMUNFrame::DisableVotingCtrls() {
        wxChoice *inFavourChoices = (wxChoice*) (wxWindow::FindWindowById(SPEAKING_IN_FAVOUR_CHOICES));
        wxChoice *againstChoices = (wxChoice*) (wxWindow::FindWindowById(SPEAKING_AGAINST_CHOICES));

        wxChoice *votingOn = (wxChoice*) (wxWindow::FindWindowById(VOTING_ON_CHOICES));

        wxListBox *inFavourList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR);
        wxListBox *againstList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_AGAINST);

        inFavourChoices->Enable(false); inFavourList->Enable(false);
        againstChoices->Enable(false); againstList->Enable(false);
        votingOn->Enable(false);

        DisableVotingTimeCtrls();
}

void wxMUNFrame::EnableGSLTimerCtrls() {
        wxSpinCtrl *GSLminutes = (wxSpinCtrl*) wxWindow::FindWindowById(GSL_SPEAKER_TIME_MINUTES);
        wxSpinCtrl *GSLseconds = (wxSpinCtrl*) wxWindow::FindWindowById(GSL_SPEAKER_TIME_SECONDS);

        GSLminutes->Enable(true);
        GSLseconds->Enable(true);
}

void wxMUNFrame::EnableGSLCtrls() {
        wxChoice *GSLChoices = (wxChoice*) wxWindow::FindWindowById(GSL_CHOICES);
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);

        //don't do anything if no countries present
        if(GSLChoices->GetCount() == 0)
                return;
        
        GSLChoices->Enable(true);
        GSLList->Enable(true);
        EnableGSLTimerCtrls();

        EnableGSLNextButton();
        EnableGSLStopButton();
}

void wxMUNFrame::DisableGSLTimerCtrls() {
        wxSpinCtrl *GSLminutes = (wxSpinCtrl*) wxWindow::FindWindowById(GSL_SPEAKER_TIME_MINUTES);
        wxSpinCtrl *GSLseconds = (wxSpinCtrl*) wxWindow::FindWindowById(GSL_SPEAKER_TIME_SECONDS);

        GSLminutes->Enable(false);
        GSLseconds->Enable(false);
}

void wxMUNFrame::DisableGSLCtrls(bool disableChoice /* = true */) {
        wxChoice *GSLChoices = (wxChoice*) wxWindow::FindWindowById(GSL_CHOICES);
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);

        if(disableChoice)
                GSLChoices->Enable(false);
                
        GSLList->Enable(false);
        DisableGSLTimerCtrls();

        DisableGSLNextButton();
        DisableGSLStopButton();
}

void wxMUNFrame::OnGSLMinutesChange ( wxSpinEvent &event ) {
        OnGSLTimeChange();
}

void wxMUNFrame::OnGSLSecondsChange ( wxSpinEvent &event ) {
        OnGSLTimeChange();
}

void wxMUNFrame::OnGSLTimeChange () {
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(GSL_SPEAKER_TIME_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(GSL_SPEAKER_TIME_SECONDS);

        int min = minutes->GetValue();
        int sec = seconds->GetValue();

        unsigned int duration = 60*min + sec;

        if(duration == 0) {
                wxMessageBox(wxT("Warning: you just set the time to 0 seconds!"),
                                wxT("Cannot execute action"),
                                wxICON_WARNING | wxOK, this);
        }

        realTime(min,sec);
        minutes->SetValue(min);
        seconds->SetValue(sec);

        wxStaticText *time  = ((wxStaticText*) wxWindow::FindWindowById(GSL_TOTAL_TIME) );
        time->SetLabel(wxString::Format(wxT("%02d:%02d"), min, sec));

        wxGauge *GSLGauge = (wxGauge*) wxWindow::FindWindowById(GSL_GAUGE);
        GSLGauge->SetRange(duration);

        wxGetApp().session()->committee()->setGSLtime(duration);
        wxGetApp().session()->saveState();
}

// single speaker ctrls & timers
void wxMUNFrame::EnableSingleSpeakerCtrls() {
        wxListBox *choices = (wxListBox*) wxWindow::FindWindowById(SINGLE_SPEAKER_CHOICES);

        choices->Enable(true);
        EnableSingleSpeakerTimerCtrls();
}

void wxMUNFrame::DisableSingleSpeakerCtrls() { 
        wxListBox *choices = (wxListBox*) wxWindow::FindWindowById(SINGLE_SPEAKER_CHOICES);

        choices->Enable(false);
        DisableSingleSpeakerTimerCtrls();
}

void wxMUNFrame::EnableSingleSpeakerPauseButton() {
        m_pauseSingleSpeakerButton->Enable();
}

void wxMUNFrame::DisableSingleSpeakerPauseButton() {
        m_pauseSingleSpeakerButton->Enable(false);
}

void wxMUNFrame::EnableSingleSpeakerResumeButton() {
        m_resumeSingleSpeakerButton->Enable();
}

void wxMUNFrame::DisableSingleSpeakerResumeButton() {
        m_resumeSingleSpeakerButton->Enable(false);
}

void wxMUNFrame::EnableSingleSpeakerTimerCtrls() {
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(SINGLE_SPEAKER_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(SINGLE_SPEAKER_SECONDS);

        minutes->Enable(true);
        seconds->Enable(true);
}

void wxMUNFrame::DisableSingleSpeakerTimerCtrls() {
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(SINGLE_SPEAKER_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(SINGLE_SPEAKER_SECONDS);

        minutes->Enable(false);
        seconds->Enable(false);
}

void wxMUNFrame::OnSingleSpeakerMinutesChange ( wxSpinEvent &event ) {
        OnSingleSpeakerTimeChange();
}

void wxMUNFrame::OnSingleSpeakerSecondsChange ( wxSpinEvent &event ) {
        OnSingleSpeakerTimeChange();
}

void wxMUNFrame::OnSingleSpeakerTimeChange () {
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(SINGLE_SPEAKER_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(SINGLE_SPEAKER_SECONDS);

        int min = minutes->GetValue();
        int sec = seconds->GetValue();

        unsigned int duration = 60*min + sec;

        if(duration == 0) {
                wxMessageBox(wxT("Warning: you just set the time to 0 seconds!"),
                                wxT("Cannot execute action"),
                                wxICON_WARNING | wxOK, this);
        }

        realTime(min,sec);
        minutes->SetValue(min);
        seconds->SetValue(sec);

        wxStaticText *time  = ((wxStaticText*) wxWindow::FindWindowById(SINGLE_SPEAKER_TOTAL_TIME) );
        time->SetLabel(wxString::Format(wxT("%02d:%02d"), min, sec));

        wxGauge *speakerGauge = (wxGauge*) wxWindow::FindWindowById(SINGLE_SPEAKER_GAUGE);
        speakerGauge->SetRange(duration);
}

void wxMUNFrame::OnSingleSpeakerCountrySelect( wxCommandEvent& event ) {
        wxListBox *choices  = (wxListBox*) wxWindow::FindWindowById(SINGLE_SPEAKER_CHOICES);
        wxString name = choices->GetStringSelection();

        StartSingleSpeaker(name);
}

void wxMUNFrame::StartSingleSpeaker(wxString name) {
        
        //Stop any speaker *EXCEPT* GSL: they can be active (paused) when this is a yield.
        StopModCaucus();
        StopUnModCaucus();
        StopSingleSpeaker();
        StopVotingSpeaker();
        
        // send some signal that we have a speaker and start a counter somewhere...
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(SINGLE_SPEAKER_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(SINGLE_SPEAKER_SECONDS);

        int min = minutes->GetValue();
        int sec = seconds->GetValue();        
        unsigned int duration = 60*min + sec;

        wxStaticText *timeLeft = (wxStaticText*) wxWindow::FindWindowById(SINGLE_SPEAKER_TIME_LEFT);
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d"), min, sec));
        timeLeft->SetForegroundColour( wxColour( wxSYS_COLOUR_WINDOWTEXT) );

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(SINGLE_SPEAKER_GAUGE);
        progressBar->SetValue(0);

        DisableSingleSpeakerTimerCtrls();

        // set flag & country name!
        wxStaticText *country =  (wxStaticText*) wxWindow::FindWindowById(SINGLE_SPEAKER_NAME);
        country->SetLabel(name);
        country->SetSize(country->GetBestSize());
        country->CentreOnParent(wxHORIZONTAL);

        setCountryFlag(SINGLE_SPEAKER_FLAG, name);

        //DisableGSLCtrls();
        PauseGSL();
        DisableCaucusCtrls();
        DisableVotingCtrls();
        
        EnableSingleSpeakerPauseButton();

        // m_GSLpanel->Enable(false); 
        m_procVotingPanel->Enable(false);
        m_modCaucusPanel->Enable(false); m_unModCaucusPanel->Enable(false);

        _speakerLength  = duration;
        _speakerSeconds = duration;
        _speakerRunning = true;
        _singleSpeakerTimer.Start(1000);
}

void wxMUNFrame::OnSingleSpeakerStop( wxCommandEvent& event ) {
        if( !(_speakerRunning && _singleSpeakerTimer.IsRunning() )  ) {
                return;
        }
        
        StopSingleSpeaker();
}

void wxMUNFrame::OnSingleSpeakerResume( wxCommandEvent& event ) {
        if( !(_speakerRunning && (_singleSpeakerTimer.IsRunning() || _timerPaused) ) ) {
                return;
        }
        
        ResumeSingleSpeaker();
}

void wxMUNFrame::OnSingleSpeakerPause( wxCommandEvent& event ) {
        if( !(_speakerRunning && (_singleSpeakerTimer.IsRunning() || _timerPaused) ) ) {
                return;
        }
        
        PauseSingleSpeaker();
}

void wxMUNFrame::PauseSingleSpeaker() {
        _singleSpeakerTimer.Stop();
        _timerPaused = true;
        
        EnableSingleSpeakerResumeButton();
        DisableSingleSpeakerPauseButton();
        DisableSingleSpeakerTimerCtrls();
}

void wxMUNFrame::ResumeSingleSpeaker() {        
        _singleSpeakerTimer.Start();
        _timerPaused = false;
        
        DisableSingleSpeakerResumeButton();
        EnableSingleSpeakerPauseButton();
        DisableSingleSpeakerTimerCtrls();
}

void wxMUNFrame::ResetSingleSpeakerLabels() {
        clearTimerLabels(SINGLE_SPEAKER_GAUGE, SINGLE_SPEAKER_TIME_LEFT, SINGLE_SPEAKER_NAME);
        clearCountryFlag(SINGLE_SPEAKER_FLAG);
}

// mod caucus time change event
void wxMUNFrame::OnModCaucusMinChange ( wxSpinEvent& event) {
        OnModCaucusTimeChange();
}

void wxMUNFrame::OnModCaucusSecChange ( wxSpinEvent& event) {
        OnModCaucusTimeChange();
}

void wxMUNFrame::OnModCaucusSTSecChange ( wxSpinEvent& event) {
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_SECONDS);
        
        int min = minutes->GetValue();
        int sec = seconds->GetValue();
        
        realTime(min,sec);
        minutes->SetValue(min);
        seconds->SetValue(sec);

}

void wxMUNFrame::OnModCaucusTimeChange() {
        wxSpinCtrl *hours   = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_HOURS);
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_SECONDS);
        
        int hrs = hours->GetValue();
        int min = minutes->GetValue();
        int sec = seconds->GetValue();        
        
        realTime(hrs,min,sec);
        hours->SetValue(hrs);
        minutes->SetValue(min);
        seconds->SetValue(sec);
}

// unmod caucus time change event
void wxMUNFrame::OnUnModCaucusMinChange ( wxSpinEvent& event) {
        OnUnModCaucusTimeChange();
}

void wxMUNFrame::OnUnModCaucusSecChange ( wxSpinEvent& event) {
        OnUnModCaucusTimeChange();
}

void wxMUNFrame::OnUnModCaucusTimeChange() {
        wxSpinCtrl *hours   = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_HOURS);
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_SECONDS);
        
        int hrs = hours->GetValue();
        int min = minutes->GetValue();
        int sec = seconds->GetValue();        
        
        realTime(hrs,min,sec);
        hours->SetValue(hrs);
        minutes->SetValue(min);
        seconds->SetValue(sec);

}

void wxMUNFrame::updateGSLListBox(std::deque<Country*> *GSL) {
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        GSLList->Clear();

        for(std::deque<Country*>::iterator it = GSL->begin(); it != GSL->end(); it++) {
                GSLList->Append( (*it)->name());
        }
}

void wxMUNFrame::updateGSLdata(wxListBox *GSLList, bool saveState) {
        int i, n = GSLList->GetCount();
        wxString code;

        std::deque<Country*> GSL;
        for(i=0; i<n; i++) {
                code = wxGetApp().findCountryCode(GSLList->GetString(i));
                GSL.push_back(wxGetApp().findCountryPtr(code));
        }
        
        wxGetApp().session()->setGSL(GSL, saveState);
        //wxGetApp().session()->printGSL();
}


void wxMUNFrame::OnGSLListSelect( wxCommandEvent& event ) {
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        int i = GSLList->GetSelection();

        if(i == wxNOT_FOUND || i != 0 ) //to avoid accidental mis-clicks the speaker *must* be on top of the list
                return;

        StartNextGSLSpeaker(GSLList);
} 

void wxMUNFrame::StartNextGSLSpeaker(wxListBox *GSLList) {
        if(GSLList->GetCount() == 0)
                return;

        if(_caucusRunning) {                
                wxMessageDialog dialog(NULL, wxT("Warning: you have an active caucus! If you start this speaker, the caucus will be stopped automatically."),
                        wxT("Warning: caucus running"),
                        wxNO_DEFAULT|wxYES_NO|wxCANCEL|wxICON_WARNING);
                        
                if ( dialog.ShowModal() != wxID_YES )
                        return;
        }
        
        int i = 0;
        GSLList->SetSelection(i); //in case we're calling by the next button this is needed
        
        wxString name = GSLList->GetStringSelection();
        std::map<wxString, Country> *countries = wxGetApp().session()->committee()->countries();
        std::map<wxString, Country>::iterator it = countries->find(name);
        if(!it->second.isPresent()) {                
                wxMessageDialog dialog( NULL, 
                                wxT("The country first on the General Speakers List is not present.\n\nIf you proceed, the member will be removed and the second of the list will start."), 
                                wxT("General Speakers List"),
                                 wxNO_DEFAULT|wxYES_NO|wxCANCEL|wxICON_WARNING);
                                
                if ( dialog.ShowModal() == wxID_YES ) {
                        GSLList->Delete(0);
                        updateGSLdata(GSLList);
                        StartNextGSLSpeaker(GSLList);
                }
                
                if(GSLList->GetCount() == 0) {
                        DisableGSLNextButton();
                }
                
                return;
        }
        
        // send some signal that we have a speaker and start a counter somewhere...
        _GSLspeakerLength = wxGetApp().session()->committee()->GSLtime();
        
        const unsigned int minutes = _GSLspeakerLength % 3600 / 60;
        const unsigned int seconds = _GSLspeakerLength % 60;

        wxStaticText *timeLeft = (wxStaticText*) wxWindow::FindWindowById(GSL_TIME_LEFT);
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d"), minutes, seconds));
        timeLeft->SetForegroundColour( wxColour( wxSYS_COLOUR_WINDOWTEXT) );

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(GSL_GAUGE);
        progressBar->SetValue(0);
        
        EnableGSLNextButton();
        EnableGSLPauseButton();
        EnableGSLYieldButton();
        
        // set flag & country name!
        wxStaticText *country =  (wxStaticText*) wxWindow::FindWindowById(GSL_SPEAKER);
        country->SetLabel(name);
        country->SetSize(country->GetBestSize());
        country->CentreOnParent(wxHORIZONTAL);
        
        setCountryFlag(GSL_SPEAKER_FLAG, name);
        
        GSLList->Delete(i);
        updateGSLdata(GSLList);
        DisableGSLTimerCtrls();
        DisableCaucusCtrls();
        DisableVotingCtrls();
        
        m_procVotingPanel->Enable(false);
        m_modCaucusPanel->Enable(false); m_unModCaucusPanel->Enable(false);

        if(GSLList->GetCount() == 0)
                DisableGSLNextButton();

        ResumeGSL(); //kills any other speaker left
        _GSLspeakerSeconds = _GSLspeakerLength;
        _GSLspeakerRunning = true;
        _GSLSpeakerTimer.Start(1000);
}

void wxMUNFrame::OnGSLUpClick( wxCommandEvent& event ) {
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        int i = GSLList->GetSelection();

        if(i == wxNOT_FOUND || i == 0 ) //can't move first upwards
                return;
        
        swapListStrings(GSLList, i, i-1);
        GSLList->SetSelection(i-1);
        
        updateGSLdata(GSLList);
}

void wxMUNFrame::OnGSLDownClick( wxCommandEvent& event ) {
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        int i = GSLList->GetSelection();
        int last = GSLList->GetCount()-1;
        
        if(i == wxNOT_FOUND || i == last) //can't move last downwards
                return;
        
        swapListStrings(GSLList, i, i+1);
        GSLList->SetSelection(i+1);
        
        updateGSLdata(GSLList);
}


void wxMUNFrame::OnGSLDeleteClick( wxCommandEvent& event ) {
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);

        int i = GSLList->GetSelection();
        if(i == wxNOT_FOUND)
                return;

        GSLList->Delete(i);
        updateGSLdata(GSLList);
}


void wxMUNFrame::OnGSLClearClick( wxCommandEvent& event ) {
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);

        if(GSLList->GetCount() == 0)
                return;

        wxMessageDialog dialog( NULL, 
                wxT("You are about to clear the General Speakers List!\n\nAre you sure you want to do this?"), 
                wxT("General Speakers List"),
                 wxNO_DEFAULT|wxYES_NO|wxCANCEL|wxICON_WARNING);
                                
        if ( dialog.ShowModal() != wxID_YES )
                return;
        
        GSLList->Clear();
        updateGSLdata(GSLList);
}

void wxMUNFrame::OnGSLChoice( wxCommandEvent& event ) {
        wxChoice *choices = (wxChoice*) (wxWindow::FindWindowById(GSL_CHOICES));
        wxString s = choices->GetStringSelection();

        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        if(GSLList->FindString(s) == wxNOT_FOUND)
                GSLList->Append(s);
        
        updateGSLdata(GSLList);

        if(!_speakerRunning)
                EnableGSLNextButton();
} 

void wxMUNFrame::OnGSLStop( wxCommandEvent& event ) {
        if( !(_GSLspeakerRunning && (_GSLSpeakerTimer.IsRunning() || _GSLtimerPaused) ) ) {
                return;
        }

        StopGSL();
}

void wxMUNFrame::OnGSLNext( wxCommandEvent& event ) {
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        StartNextGSLSpeaker(GSLList);
}

void wxMUNFrame::OnGSLYield( wxCommandEvent& event ) {
        if( !(_GSLspeakerRunning && (_GSLSpeakerTimer.IsRunning() || _GSLtimerPaused) ) ) 
                return;
        
        PauseGSL();
        
        YieldDialog dlg(this);
        wxListBox *choices  = (wxListBox*) wxWindow::FindWindowById(YIELD_TO_DELEGATE_CHOICES);
        
        Committee *c = wxGetApp().session()->committee();
        std::map<wxString, Country>::iterator it = c->countries()->begin();
        for(int i=0; it != c->countries()->end(); it++, i++) {
                choices->Append(it->second.name());
        }

        if ( dlg.ShowModal() != wxID_OK ) {
                ResumeGSL();
                return;        
        }

        wxString name = choices->GetStringSelection();
#ifdef DEBUG
        std::cout << "wxMUNFrame::OnGSLYield(): yield to " << name.mb_str() << std::endl;
#endif

        Country *country = wxGetApp().findCountryPtr(wxGetApp().findCountryCode(name));
        if(!country) { //shouldn't happen!
                ResumeGSL(); 
                return;
        }
        
        wxStaticText *countryText =  (wxStaticText*) wxWindow::FindWindowById(GSL_SPEAKER);
        countryText->SetLabel(name);
        countryText->SetSize(countryText->GetBestSize());
        countryText->CentreOnParent(wxHORIZONTAL);
        
        setCountryFlag(GSL_SPEAKER_FLAG, name);

        DisableGSLYieldButton(); //no double yields
        ResumeGSL();
}

void wxMUNFrame::OnGSLPause( wxCommandEvent& event ) {
        if( !(_GSLspeakerRunning && (_GSLSpeakerTimer.IsRunning() || _GSLtimerPaused) ) ) {
                return;
        }
        
        PauseGSL();
}

void wxMUNFrame::OnGSLResume( wxCommandEvent& event ) {
        if( !(_GSLspeakerRunning && (_GSLSpeakerTimer.IsRunning() || _GSLtimerPaused) ) ) {
                return;
        }
        
        ResumeGSL();
}

void wxMUNFrame::EnableGSLPauseButton() {
        wxButton *p = (wxButton*) wxWindow::FindWindowById(PAUSE_GSL);
        p->Enable(true);
}

void wxMUNFrame::EnableGSLResumeButton() {             
        wxButton *r = (wxButton*) wxWindow::FindWindowById(RESUME_GSL);
        r->Enable(true);
}

void wxMUNFrame::DisableGSLPauseButton() {
        wxButton *p = (wxButton*) wxWindow::FindWindowById(PAUSE_GSL);
        p->Enable(false);
}

void wxMUNFrame::DisableGSLResumeButton() {
        wxButton *r = (wxButton*) wxWindow::FindWindowById(RESUME_GSL);
        r->Enable(false);
}

void wxMUNFrame::DisableGSLStopButton() {
        m_GSLStopButton->Enable(false);
}

void wxMUNFrame::EnableGSLStopButton() {
        m_GSLStopButton->Enable(true);
}

void wxMUNFrame::DisableGSLNextButton() {       
        wxButton *p = (wxButton*) wxWindow::FindWindowById(GSL_NEXT);
        p->Enable(false);
}

void wxMUNFrame::EnableGSLNextButton() {
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        if(GSLList->GetCount() == 0)
                return;
        
        wxButton *r = (wxButton*) wxWindow::FindWindowById(GSL_NEXT);
        r->Enable(true);

}

void wxMUNFrame::DisableGSLYieldButton() {
        wxButton *p = (wxButton*) wxWindow::FindWindowById(GSL_YIELD);
        p->Enable(false);
}

void wxMUNFrame::EnableGSLYieldButton() {
        wxButton *r = (wxButton*) wxWindow::FindWindowById(GSL_YIELD);
        r->Enable(true);
}

void wxMUNFrame::PauseGSL() {
        _GSLSpeakerTimer.Stop();
        _GSLtimerPaused = true;
        
        EnableGSLResumeButton();
        DisableGSLPauseButton();
        DisableGSLTimerCtrls();
}

void wxMUNFrame::ResumeGSL() {
        StopModCaucus();
        StopUnModCaucus();
        StopSingleSpeaker();
        StopVotingSpeaker();
        
        _GSLSpeakerTimer.Start();
        _GSLtimerPaused = false;
        
        DisableGSLResumeButton();
        EnableGSLPauseButton();
        DisableGSLTimerCtrls();
}

void wxMUNFrame::StopGSL() {
        EnableCaucusCtrls();
        EnableVotingCtrls();
        EnableGSLCtrls();
        
        m_GSLpanel->Enable(true); m_singleSpeakerPanel->Enable(true); m_procVotingPanel->Enable(true);
        m_modCaucusPanel->Enable(true); m_unModCaucusPanel->Enable(true);
        
        DisableGSLYieldButton();
        DisableGSLPauseButton();
        DisableGSLResumeButton();
        
        clearCountryFlag(GSL_SPEAKER_FLAG);
        clearTimerLabels(GSL_GAUGE, GSL_TIME_LEFT, GSL_SPEAKER);
        
        DisableGSLPauseButton();
        DisableGSLResumeButton();
                        
        _GSLSpeakerTimer.Stop();
        _GSLspeakerRunning = false;
}

void wxMUNFrame::OnModCaucusStart( wxCommandEvent& event ) {
        if(_caucusRunning)
                return;

        if(!wxGetApp().isCommitteeLoaded() || !wxGetApp().session()->topicChosen()) {
                NoInitDialog();
                return;
        }

        StopAllSpeakers();

        // find the topic
        wxTextCtrl *topicCtrl = (wxTextCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_TOPIC);
        wxString topic = topicCtrl->GetValue();

        // find the durations
        wxSpinCtrl *hours   = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_HOURS);
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_SECONDS);
        
        wxSpinCtrl *STminutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_MINUTES);
        wxSpinCtrl *STseconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_MOD_CAUCUS_ST_SECONDS);

        const unsigned int duration = 3600*hours->GetValue() + 60*minutes->GetValue() + seconds->GetValue();
        const unsigned int STduration = 60*STminutes->GetValue() + STseconds->GetValue();
        
        if(topic.IsEmpty()) {
                wxMessageBox(wxT("Error: a moderated caucus must have a topic!"),
                        wxT("Cannot start caucus"),
                        wxICON_WARNING | wxOK, this);
                return;
        }

        if(duration == 0 || STduration == 0) {
                wxMessageBox(wxT("Error: duration and speaker time must be greater than zero!"),
                        wxT("Cannot start caucus"),
                        wxICON_WARNING | wxOK, this);
                return;
        }

        // enable the list of possible speakers
        wxListBox *modCaucusChoices = (wxListBox*) wxWindow::FindWindowById(MOD_CAUCUS_CHOICES);
        modCaucusChoices->Enable(true);        

        //set the topic label
        wxStaticText *topicLabel = (wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_TOPIC);
        topicLabel->SetLabel(topic);
        topicLabel->SetSize(topicLabel->GetBestSize());
        topicLabel->Wrap(topicLabel->GetBestSize().GetWidth());
        topicLabel->CentreOnParent(wxHORIZONTAL);

        // set total time labels & gauge        
        wxStaticText *timeLeft  = ((wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_TIME_LEFT) );
        wxStaticText *totalTime = ((wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_TOTAL_TIME) );
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d:%02d"),  hours->GetValue(), minutes->GetValue(), seconds->GetValue()));
        totalTime->SetLabel(wxString::Format(wxT("%02d:%02d:%02d"), hours->GetValue(), minutes->GetValue(), seconds->GetValue()));

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(MOD_CAUCUS_GAUGE);
        progressBar->SetRange(duration);
        progressBar->SetValue(0);

        // set total speaker time and progress bar range (time left is of course done per speaker)
        wxStaticText *STtime = ((wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_TOTAL_SPEAKER_TIME) );
        STtime->SetLabel(wxString::Format(wxT("%02d:%02d"), STminutes->GetValue(), STseconds->GetValue()));
        
        wxGauge* STprogressBar = (wxGauge*) wxWindow::FindWindowById(MOD_CAUCUS_SPEAKER_GAUGE);
        STprogressBar->SetRange(STduration);
        STprogressBar->SetValue(0);
        
        DisableVotingCtrls(); //no need to vote during caucus
        DisableCaucusCtrls();
//         //DisableGSLCtrls(); //no GSL editing during mod caucus!
        
        m_singleSpeakerPanel->Enable(false); m_procVotingPanel->Enable(false);
        m_unModCaucusPanel->Enable(false);

        ClearModCaucusInput();
        EnableModCaucusPauseButton();

        _caucusLength = _caucusSeconds = duration;
        _speakerLength = _speakerSeconds = STduration;
        
        _caucusRunning = true;
        _modCaucusTimer.Start(1000);

        // TODO: Implement OnModCaucusClick
}

void wxMUNFrame::OnModCaucusPause( wxCommandEvent& event ) {        
        PauseModCaucus();
}

void wxMUNFrame::PauseModCaucus() {
        if(!_caucusRunning) //we never set the booleans but stop the timers when pausing
                return;
                
        if(_modCaucusTimer.IsRunning() )
                _modCaucusTimer.Stop();
        
        if(_speakerRunning && _caucusSpeakerTimer.IsRunning() )
                _caucusSpeakerTimer.Stop();
        
        _timerPaused = true;        
        DisableModCaucusPauseButton();
}

void wxMUNFrame::OnModCaucusResume( wxCommandEvent& event ) {        
        ResumeModCaucus();
}

void wxMUNFrame::ResumeModCaucus() {
        if(!_caucusRunning) //we never set the booleans but stop the timers when pausing
                return;
        
        if(_caucusRunning && _modCaucusTimer.IsRunning())
                return;
        
        if(!_modCaucusTimer.IsRunning() )
                _modCaucusTimer.Start();
        
        if(_speakerRunning && !_caucusSpeakerTimer.IsRunning() )
                _caucusSpeakerTimer.Start();
        
        _timerPaused = false;        
        EnableModCaucusPauseButton();
}

void wxMUNFrame::OnModCaucusCountrySelect( wxCommandEvent& event ) {
        const unsigned int minutes = _speakerLength % 3600 / 60;
        const unsigned int seconds = _speakerLength % 60;

        wxStaticText *STtimeLeft = (wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_SPEAKER_TIME_LEFT);
        STtimeLeft->SetLabel(wxString::Format(wxT("%02d:%02d"), minutes, seconds));
        STtimeLeft->SetForegroundColour( wxColour( wxSYS_COLOUR_WINDOWTEXT) );

        wxGauge* STprogressBar = (wxGauge*) wxWindow::FindWindowById(MOD_CAUCUS_SPEAKER_GAUGE);
        STprogressBar->SetValue(0);
        
        // set flag & country name!
        wxListBox *choices  = (wxListBox*) wxWindow::FindWindowById(MOD_CAUCUS_CHOICES);
        wxStaticText *country  = (wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_SPEAKER);
        
        wxString name = choices->GetStringSelection();
        country->SetLabel(name);
        country->SetSize(country->GetBestSize());
        country->CentreOnParent(wxHORIZONTAL);

        setCountryFlag(MOD_CAUCUS_SPEAKER_FLAG, name);

        //always resume debate
        ResumeModCaucus();
        
        // DO NOT disable mod caucus choices, maybe speaker ends speech within the allotted time!
        _speakerSeconds = _speakerLength;
        _speakerRunning = true;
        _caucusSpeakerTimer.Start(1000);
        
}

void wxMUNFrame::OnModCaucusCancel( wxCommandEvent& event ) {
        if(_caucusRunning)
                return;
                
        ClearModCaucusInput();
}

void wxMUNFrame::OnModCaucusStop( wxCommandEvent& event ) {
        if( !(_caucusRunning && (_modCaucusTimer.IsRunning() || _timerPaused) ) ) {
                return;
        }
        
        StopModCaucus(true);
}

//void wxMUNFrame::OnUnModCaucusClick( wxCommandEvent& event )
void wxMUNFrame::OnUnModCaucusStart( wxCommandEvent& event ) {
        if(!wxGetApp().isCommitteeLoaded() || !wxGetApp().session()->topicChosen()) {
                NoInitDialog();
                return;
        }

        if(_caucusRunning)
                return;

        StopAllSpeakers();
        
        // implement a fancy counter! 
        // (simply a 1 sec timer + gauge and some text which is constantly renewed)
        wxTextCtrl *topicCtrl = (wxTextCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_TOPIC);
        wxString topic = topicCtrl->GetValue();

        wxSpinCtrl *hours   = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_HOURS);
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(NEW_UNMOD_CAUCUS_SECONDS);

        const unsigned int duration = 3600*hours->GetValue() + 60*minutes->GetValue() + seconds->GetValue();

        if(duration == 0) {
                wxMessageBox(wxT("Error: duration must be greater than zero!"),
                        wxT("Cannot start caucus"),
                        wxICON_WARNING | wxOK, this);
                return;
        }

        wxStaticText *topicLabel = (wxStaticText*) wxWindow::FindWindowById(UNMOD_CAUCUS_TOPIC);
        topicLabel->SetLabel(topic);
        topicLabel->SetSize(topicLabel->GetBestSize());
        topicLabel->CentreOnParent(wxHORIZONTAL);
        
        wxStaticText *timeLeft  = ((wxStaticText*) wxWindow::FindWindowById(UNMOD_CAUCUS_TIME_LEFT) );
        wxStaticText *totalTime = ((wxStaticText*) wxWindow::FindWindowById(UNMOD_CAUCUS_TOTAL_TIME) );

        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d:%02d"),  hours->GetValue(), minutes->GetValue(), seconds->GetValue()));
        totalTime->SetLabel(wxString::Format(wxT("%02d:%02d:%02d"), hours->GetValue(), minutes->GetValue(), seconds->GetValue()));

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(UNMOD_CAUCUS_GAUGE);
        progressBar->SetRange(duration);
        progressBar->SetValue(0);

        // DO NOT lock GSL, chairs will want to edit it during breaks!
        DisableVotingCtrls(); //no need to vote during caucus
        DisableCaucusCtrls();
        ClearUnModCaucusInput();
        
        m_singleSpeakerPanel->Enable(false); m_procVotingPanel->Enable(false);
        m_modCaucusPanel->Enable(false); 

        _caucusLength = _caucusSeconds = duration;
        _caucusRunning = true;
        _unmodCaucusTimer.Start(1000);

}

void wxMUNFrame::OnUnModCaucusCancel( wxCommandEvent& event ) {
        if(_caucusRunning)
                return;

        ClearUnModCaucusInput();
}

void wxMUNFrame::OnUnModCaucusStop ( wxCommandEvent& event) {
        if( !(_caucusRunning && _unmodCaucusTimer.IsRunning() ) ) {
                return;
        }
                
        StopUnModCaucus();
}

void wxMUNFrame::OnStateFileOpen( wxCommandEvent& event ) {
        if(wxGetApp().isCommitteeLoaded() && !wxGetApp().session()->isStateManuallySaved()) {
                wxMessageDialog dialog( NULL, 
                        _("You currently already have loaded a committee. Proceed with loading a state file? Any current state will be lost!"), 
                        _("Load state file"),
                        wxNO_DEFAULT|wxYES_NO|wxICON_QUESTION); 

                //dialog if user wants to clear
                if(dialog.ShowModal() != wxID_YES)
                        return;
        } 

        wxFileDialog* OpenDialog = new wxFileDialog(
                this, _("Choose a file to open"), wxEmptyString, wxEmptyString, 
                _("XML files (*.xml)|*.xml"),
                wxFD_OPEN | wxFILE_MUST_EXIST, wxDefaultPosition);
 
        if (OpenDialog->ShowModal() == wxID_OK) { // if the user click "Open" instead of "Cancel"
                CurrentDocPath = OpenDialog->GetPath();
        
                //to be sure, instantiate a new Session                
                Session s;
                wxGetApp().setSession(s);
        
                wxGetApp().readState(CurrentDocPath);
        }
}

void wxMUNFrame::OnStateFileSaveAs( wxCommandEvent& event ) {
        wxFileDialog* SaveDialog = new wxFileDialog(
                this, _("Choose a location to save"), wxEmptyString, wxEmptyString, 
                _("XML files (*.xml)|*.xml"),
                wxFD_SAVE | wxOVERWRITE_PROMPT, wxDefaultPosition);
 
        if (SaveDialog->ShowModal() == wxID_OK) { // if the user click "Open" instead of "Cancel"        
                wxGetApp().session()->saveState(SaveDialog->GetPath());
        }
}

void wxMUNFrame::OnQuit( wxCommandEvent& event ) {
        // saving is done automatically, don't worry about it
        Close();
}

void wxMUNFrame::OnNewCommittee( wxCommandEvent& event ) {
        std::map<wxString, Country> *countries = wxGetApp().availableCountries();
        NewCommitteeDialog dlg(this, countries);

        if ( dlg.ShowModal() != wxID_OK )
                return;

        wxMessageDialog dialog( NULL, 
                        _("Committee created!\nLoad the newly created committee?"), 
                        _("New committee"),
                         wxYES_DEFAULT|wxYES_NO|wxICON_INFORMATION);
                                
        if ( dialog.ShowModal() == wxID_YES ) {
                wxGetApp().LoadCommitteeFromFile(CurrentDocPath, true); 
        }         
}

void wxMUNFrame::OnEditCommittee( wxCommandEvent& event ) {
        wxFileDialog* OpenDialog = new wxFileDialog(
                this, _("Choose a committee file to edit"), wxEmptyString, wxEmptyString, 
                _("XML files (*.xml)|*.xml"),
                wxFD_OPEN | wxFILE_MUST_EXIST, wxDefaultPosition);
 
        if (OpenDialog->ShowModal() != wxID_OK) { // if the user click "Open" instead of "Cancel"
                return;        
        }

        CurrentDocPath = OpenDialog->GetPath();

        std::map<wxString, Country> *countries = wxGetApp().availableCountries();
        EditCommitteeDialog dlg(this, countries, CurrentDocPath);

        if ( dlg.ShowModal() != wxID_OK )
                return;

        if(wxGetApp().isCommitteeLoaded()) {
                wxMessageDialog dialog( NULL, 
                                _("Committee saved!\n\nLoad the newly defined committee preserving the current state of debate (yes), not preserving the state (no) or do not load the new committee (cancel)?\n\nAny countries no longer present in the edited committee will be removed from the General Speakers list, even if you wish to preserve it."), 
                                _("Edit committee"),
                                 wxYES_DEFAULT|wxYES_NO|wxCANCEL|wxICON_QUESTION);

                switch ( dialog.ShowModal() ) { 
                        case wxID_YES: 
                                wxGetApp().LoadCommitteeFromFile(CurrentDocPath, false); 
                                break; 
                        case wxID_NO: 
                                wxGetApp().LoadCommitteeFromFile(CurrentDocPath, true); 
                                break; 
                        case wxID_CANCEL: 
                                return;
                                break; 
                        default:
                                break;
                }
        } else {        
                wxMessageDialog dialog( NULL, 
                                _("Committee saved!\nLoad the newly defined committee?"), 
                                _("Edit committee"),
                                wxYES_DEFAULT|wxYES_NO|wxICON_QUESTION);
                                
                if ( dialog.ShowModal() == wxID_YES ) {
                        wxGetApp().LoadCommitteeFromFile(CurrentDocPath); 
                }
        }        
}

void wxMUNFrame::OnLoadCommittee( wxCommandEvent& event ) {
        if(wxGetApp().isCommitteeLoaded()  && !wxGetApp().session()->isStateManuallySaved()) {
                wxMessageBox(_("Warning: you have already loaded a committee! Loading another one will overwrite your current settings!"),
                             _("Already loaded committee"),
                             wxICON_WARNING | wxOK, this);
        }

        wxFileDialog* OpenDialog = new wxFileDialog(
                this, _("Choose a file to open"), wxEmptyString, wxEmptyString, 
                _("XML files (*.xml)|*.xml"),
                wxFD_OPEN | wxFILE_MUST_EXIST, wxDefaultPosition);
 
        if (OpenDialog->ShowModal() == wxID_OK) { // if the user click "Open" instead of "Cancel"
                CurrentDocPath = OpenDialog->GetPath();
                wxGetApp().LoadCommitteeFromFile(CurrentDocPath, true);
        }
}

void wxMUNFrame::LoadSetLabels() {
        StopAllSpeakers();
        
        //m_rollCallVotePanel->Enable(false);
        DisableRollCallCtrls();
        
        m_mainauinotebook->SetSelection(m_mainauinotebook->GetPageIndex(m_GSLpanel));

        wxStaticText *committee_label = (wxStaticText*) wxWindow::FindWindowById(CURRENT_COMMITTEE);
        committee_label->SetLabel(wxGetApp().session()->committee()->name());
                
        if(wxGetApp().session()->committee()->numPresent() > 0) {
                EnableVotingCtrls();
                if(wxGetApp().session()->topicChosen()) {
                        EnableCaucusCtrls();
                        EnableGSLCtrls();        
                }
        }
                
        if(wxGetApp().session()->GSL()->size() > 0 && wxGetApp().session()->committee()->numPresent() > 0)
                EnableGSLNextButton();
                
        m_countriesPresentMenuItem->Enable(true);
                
        wxStaticText *presentLabel = (wxStaticText*) wxWindow::FindWindowById(MEMBERS_PRESENT);        
        presentLabel->SetLabel(wxString::Format(wxT("%i / %i  (1/2 = %d; 2/3 = %d)"), wxGetApp().session()->committee()->numPresent(), 
                                        wxGetApp().session()->committee()->countries()->size(), 
                                        (wxGetApp().session()->committee()->numPresent() == 0) ? 0 : 1 + wxGetApp().session()->committee()->numPresent()/2, 
                                        (int) ceil((float) wxGetApp().session()->committee()->numPresent()*(2.0/3.0))  ));
        
        //wxMenuItem *votingMenu = this->m_manageMenu->FindItem(VOTING_PROCEDURE_MENU); 
        
        if(wxGetApp().session()->committee()->numPresent() == 0) {
                presentLabel->SetForegroundColour(DARK_RED);
                wxFont presFont = presentLabel->GetFont();
                presFont.SetWeight(wxFONTWEIGHT_BOLD);
                presentLabel->SetFont(presFont);

                m_votingProcedureMenuItem->Enable(false);
        } else {
                presentLabel->SetForegroundColour(wxColour( wxSYS_COLOUR_WINDOWTEXT));
                wxFont presFont = presentLabel->GetFont();
                presFont.SetWeight(wxFONTWEIGHT_NORMAL);
                presentLabel->SetFont(presFont);

                if(wxGetApp().session()->topicChosen())
                        m_votingProcedureMenuItem->Enable(true);
        }
                        
        wxMenuItem *tA = this->m_topicSelectorMenu->FindItem(TOPIC_A_MENU); 
        wxMenuItem *tB = this->m_topicSelectorMenu->FindItem(TOPIC_B_MENU); 
        wxStaticText *topic_label = (wxStaticText*) wxWindow::FindWindowById(CURRENT_TOPIC);

        tA->SetText(wxGetApp().session()->committee()->topicA());
        tA->Enable(); tA->Check(false);
                
        if(wxGetApp().session()->committee()->numTopics() == 1) {
                tA->Check(true); tA->Enable(false);
                tB->SetText(_("No Topic B"));
                tB->Enable(false);
                        
                topic_label->SetLabel(wxGetApp().session()->committee()->topicA());
                wxGetApp().session()->setTopic(wxGetApp().session()->committee()->topicA());                
        } else if(wxGetApp().session()->topicChosen()) { // 2 topics, one chosen
                tB->SetText(wxGetApp().session()->committee()->topicB());
                wxGetApp().session()->setTopic(wxGetApp().session()->committee()->topicB());
                
                if(wxGetApp().session()->committee()->topicA() == wxGetApp().session()->topic()) {
                        topic_label->SetLabel(wxGetApp().session()->committee()->topicA());
                
                        tA->Check(true); tA->Enable(false);
                        tB->Enable(true);                                
                } else {
                        topic_label->SetLabel(wxGetApp().session()->committee()->topicB());
                
                        tB->Check(true); tB->Enable(false);
                        tA->Enable(true);                        
                }
        } else { // 2 topics, none chosen
                tB->SetText(wxGetApp().session()->committee()->topicB());
                tB->Enable();

                topic_label->SetLabel(_("awaiting user input")); //reset in case a previous session already set this
                topic_label->SetForegroundColour(DARK_RED);
                
                //lock the controls until topic chosen
                DisableGSLCtrls();
                DisableCaucusCtrls();
                DisableSingleSpeakerCtrls();
        }
                
#ifdef DEBUG
        std::cout << "wxMUNFrame::LoadSetLabels(): topic chosen? " << wxGetApp().session()->topicChosen() << std::endl;
        std::cout << "wxMUNFrame::LoadSetLabels(): topic A = " << wxGetApp().session()->committee()->topicA().mb_str() << std::endl;
        std::cout << "wxMUNFrame::LoadSetLabels(): topic B = " << wxGetApp().session()->committee()->topicB().mb_str() << std::endl;
#endif
                
        //set GSL time 
        wxSpinCtrl *GSLminutes = (wxSpinCtrl*) wxWindow::FindWindowById(GSL_SPEAKER_TIME_MINUTES);
        wxSpinCtrl *GSLseconds = (wxSpinCtrl*) wxWindow::FindWindowById(GSL_SPEAKER_TIME_SECONDS);
        
        const unsigned int minutes = wxGetApp().session()->committee()->GSLtime() % 3600 / 60;
        const unsigned int seconds = wxGetApp().session()->committee()->GSLtime() % 60;

        wxStaticText *time  = ((wxStaticText*) wxWindow::FindWindowById(GSL_TOTAL_TIME) );
        time->SetLabel(wxString::Format(wxT("%02d:%02d"), minutes, seconds));

        GSLminutes->SetValue(minutes);
        GSLseconds->SetValue(seconds);
                
        wxGauge *GSLGauge = (wxGauge*) wxWindow::FindWindowById(GSL_GAUGE);
        GSLGauge->SetRange(wxGetApp().session()->committee()->GSLtime());
                
        // bring the choice lists back
        wxChoice *GSLChoices = (wxChoice*) wxWindow::FindWindowById(GSL_CHOICES);
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        wxListBox *modCaucusChoices = (wxListBox*) wxWindow::FindWindowById(MOD_CAUCUS_CHOICES);
        wxChoice *againstChoices = (wxChoice*) wxWindow::FindWindowById(SPEAKING_AGAINST_CHOICES);
        wxChoice *inFavourChoices = (wxChoice*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR_CHOICES);
        wxListBox *rcFirstRoundChoices = (wxListBox*) wxWindow::FindWindowById(ROLL_CALL_FIRST_ROUND_CHOICES);
        wxListBox *singleSpeakerChoices = (wxListBox*) wxWindow::FindWindowById(SINGLE_SPEAKER_CHOICES);

        GSLChoices->Clear(); 
        modCaucusChoices->Clear();
        againstChoices->Clear();
        inFavourChoices->Clear();
        singleSpeakerChoices->Clear();
        rcFirstRoundChoices->Clear();
        
        if(!wxGetApp().session()->topicChosen()) {
                GSLList->Clear(); updateGSLdata(GSLList);
        }
        
        std::map<wxString, Country> *countries = wxGetApp().session()->committee()->countries();
        std::map<wxString, Country>::iterator it = countries->begin();
        for(; it != countries->end(); it++) {
#ifdef DEBUG
                std::cout << "wxMUNFrame::LoadSetLabels(): " <<it->second.name().mb_str() << ", present? " << it->second.isPresent() << ", observer? " << it->second.isObserver() << std::endl;
#endif
                if ( !it->second.isPresent() )
                        continue;
                        
                wxString name = it->second.name();
                
                GSLChoices->Append(name);
                modCaucusChoices->Append(name);
                againstChoices->Append(name);
                inFavourChoices->Append(name);
                singleSpeakerChoices->Append(name);
                
                if( !it->second.isObserver())
                        rcFirstRoundChoices->Append(name);
                
        }
              
        if(wxGetApp().session()->topicChosen() && wxGetApp().session()->committee()->numPresent() > 0) {
                EnableGSLCtrls();
                EnableCaucusCtrls();
                EnableSingleSpeakerCtrls();
        }
        
}

void wxMUNFrame::OnHelp( wxCommandEvent& event ) {
        // TODO: Implement OnHelp
}

void wxMUNFrame::OnAbout( wxCommandEvent& event ) {
        wxMUNAboutDialog* dlg = new wxMUNAboutDialog(this);
        dlg->m_aboutUNLlogobitmap->SetBitmap(wxGetBitmapFromMemory(unl_logo));

        dlg->ShowModal();
        dlg->Destroy();
}

bool wxMUNFrame::ConfirmTopicSwap() {

        ConfirmTopicSwapDialog dlg(this);

        if ( dlg.ShowModal() != wxID_OK )
                return false;        

        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        GSLList->Clear(); updateGSLdata(GSLList); 

        return true;
}

void wxMUNFrame::OnTopicAMenuSelect ( wxCommandEvent& event ) {
        wxMenuItem *tA = this->m_topicSelectorMenu->FindItem(TOPIC_A_MENU); 
        wxMenuItem *tB = this->m_topicSelectorMenu->FindItem(TOPIC_B_MENU); 

        if( wxGetApp().session()->committee()->numTopics() > 1 && wxGetApp().session()->topicChosen() ) {
                if (!ConfirmTopicSwap()) {
                        tA->Check(false);
                        return;
                }        
        }

        tA->Check(true); tA->Enable(false);
        tB->Check(false); tB->Enable(true); //to switch topics we gray out the one currently selected; "unselecting" a topic is impossible!

        wxStaticText *topic_label = (wxStaticText*) wxWindow::FindWindowById(CURRENT_TOPIC);
        topic_label->SetLabel(wxGetApp().session()->committee()->topicA());
        topic_label->SetForegroundColour(wxColour( wxSYS_COLOUR_WINDOWTEXT));

        wxGetApp().session()->setTopic(wxGetApp().session()->committee()->topicA());

//TODO: following should move to shared function with OnTopicBSelect!        

        //clear GSL
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        GSLList->Clear();

        // if roll call locked this, bring it back
        m_countriesPresentMenuItem->Enable(true);
        
        m_GSLpanel->Enable(true); m_singleSpeakerPanel->Enable(true); m_procVotingPanel->Enable(true);
        m_modCaucusPanel->Enable(true); m_unModCaucusPanel->Enable(true); 
        //m_rollCallVotePanel->Enable(false);        
        
        //SetRollCallFirstRoundLabels();
        DisableRollCallCtrls();
        
        //free the GSL controls
        if(wxGetApp().session()->committee()->numPresent() > 0) {
                EnableGSLCtrls();
                EnableCaucusCtrls();
                EnableSingleSpeakerCtrls();
                
                //wxMenuItem *votingMenu = this->m_manageMenu->FindItem(VOTING_PROCEDURE_MENU); 
                m_votingProcedureMenuItem->Enable(true);
        }
        m_mainauinotebook->SetSelection(m_mainauinotebook->GetPageIndex(m_GSLpanel));

}

void wxMUNFrame::OnTopicBMenuSelect ( wxCommandEvent& event ) {
        wxMenuItem *tA = this->m_topicSelectorMenu->FindItem(TOPIC_A_MENU); 
        wxMenuItem *tB = this->m_topicSelectorMenu->FindItem(TOPIC_B_MENU); 

        if( wxGetApp().session()->committee()->numTopics() > 1 && wxGetApp().session()->topicChosen() ) {
                if (!ConfirmTopicSwap()) {
                        tB->Check(false);
                        return;
                }        
        }

        tB->Check(true); tB->Enable(false);
        tA->Check(false); tA->Enable(true); //to switch topics

        wxStaticText *topic_label = (wxStaticText*) wxWindow::FindWindowById(CURRENT_TOPIC);
        topic_label->SetLabel(wxGetApp().session()->committee()->topicB());
        topic_label->SetForegroundColour(wxColour( wxSYS_COLOUR_WINDOWTEXT));
        
        wxGetApp().session()->setTopic(wxGetApp().session()->committee()->topicB());
        
//TODO: following should move to shared function with OnTopicASelect!        

        //clear GSL
        wxListBox *GSLList = (wxListBox*) wxWindow::FindWindowById(GSL_LIST);
        GSLList->Clear();        

        // if roll call locked this, bring it back
        m_countriesPresentMenuItem->Enable(true);        

        m_GSLpanel->Enable(true); m_singleSpeakerPanel->Enable(true); m_procVotingPanel->Enable(true);
        m_modCaucusPanel->Enable(true); m_unModCaucusPanel->Enable(true); 
        //m_rollCallVotePanel->Enable(false);
        
        //SetRollCallFirstRoundLabels();
        DisableRollCallCtrls();
        
        //free the GSL controls and caucus controls
        if(wxGetApp().session()->committee()->numPresent() > 0) {
                EnableGSLCtrls();
                EnableCaucusCtrls();
                EnableSingleSpeakerCtrls();
                
                //wxMenuItem *votingMenu = this->m_manageMenu->FindItem(VOTING_PROCEDURE_MENU); 
                m_votingProcedureMenuItem->Enable(true);
        }
        m_mainauinotebook->SetSelection(m_mainauinotebook->GetPageIndex(m_GSLpanel));

}

void wxMUNFrame::OnCountriesPresentMenuSelect( wxCommandEvent& event) {
        CountriesPresentDialog dlg(this, wxGetApp().session()->committee()->countries() );

        wxCheckListBox *membersPresent  = (wxCheckListBox*) wxWindow::FindWindowById(COUNTRIES_PRESENT);
        Committee *c = wxGetApp().session()->committee();
        std::map<wxString, Country>::iterator it;

        if ( dlg.ShowModal() != wxID_OK )
                return;        

        // set the country lists in voting & GSL panels
        wxChoice *GSLChoices = (wxChoice*) wxWindow::FindWindowById(GSL_CHOICES);
        wxListBox *modCaucusChoices = (wxListBox*) wxWindow::FindWindowById(MOD_CAUCUS_CHOICES);
        wxChoice *againstChoices = (wxChoice*) wxWindow::FindWindowById(SPEAKING_AGAINST_CHOICES);
        wxChoice *inFavourChoices = (wxChoice*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR_CHOICES);
        wxListBox *rcFirstRoundChoices = (wxListBox*) wxWindow::FindWindowById(ROLL_CALL_FIRST_ROUND_CHOICES);
        wxListBox *singleSpeakerChoices = (wxListBox*) wxWindow::FindWindowById(SINGLE_SPEAKER_CHOICES);

        // clear anything that might be there 
        GSLChoices->Clear();
        modCaucusChoices->Clear();
        againstChoices->Clear();
        inFavourChoices->Clear();
        rcFirstRoundChoices->Clear();
        singleSpeakerChoices->Clear();

        unsigned int nMembersPresent = 0, nPresent = 0;
        for(unsigned int i=0; i < membersPresent->GetCount(); i++) {
                const wxString name = membersPresent->GetString(i);
                if( (it = c->countries()->find(name)) == c->countries()->end() )
                        return;
                        
                if ( membersPresent->IsChecked(i) ) {
                        nPresent++;

                        it->second.makePresent();
                        GSLChoices->Append(name);
                        modCaucusChoices->Append(name);
                        againstChoices->Append(name);
                        inFavourChoices->Append(name);
                        singleSpeakerChoices->Append(name);
                        
                        if(!it->second.isObserver()) {
                                nMembersPresent++;
                                rcFirstRoundChoices->Append(name);
                        }
                } else {
                        it->second.makeNotPresent();
                }
        }
        
        if( !_caucusRunning && !_speakerRunning && nPresent > 0) {
                EnableVotingCtrls();
                if(wxGetApp().session()->topicChosen()) {
                        EnableGSLCtrls();
                        EnableCaucusCtrls();
                        EnableSingleSpeakerCtrls();
                        if(wxGetApp().session()->GSL()->size() > 0)
                                EnableGSLNextButton();
                }
        //} else if (!_caucusRunning && !_speakerRunning) {
        } else {
                DisableGSLNextButton();
                DisableGSLCtrls(true);
                DisableVotingCtrls();
                DisableCaucusCtrls();
                DisableSingleSpeakerCtrls();
                
                m_votingProcedureMenuItem->Enable(false);
        }
        c->setPresent(nPresent);
        c->setMembersPresent(nPresent);
        
        wxStaticText *presentLabel = (wxStaticText*) wxWindow::FindWindowById(MEMBERS_PRESENT);        
        presentLabel->SetLabel(wxString::Format(wxT("%i / %i  (1/2 = %i; 2/3 = %i)"), nPresent, 
                                                membersPresent->GetCount(), 
                                                (nPresent == 0) ? 0 : 1 + nPresent/2, 
                                                (int) ceil((float) nPresent*(2.0/3.0))  ));
        
        if(nPresent == 0) {  
                presentLabel->SetForegroundColour(DARK_RED);
                wxFont presFont = presentLabel->GetFont();
                presFont.SetWeight(wxFONTWEIGHT_BOLD);
                presentLabel->SetFont(presFont);

                wxMessageBox(_("Currently, there are no countries present. Most functionality will be unavailable."),
                             _("Countries present"),
                             wxICON_INFORMATION | wxOK, this);                
                
        } else {
                presentLabel->SetForegroundColour(wxColour(wxSYS_COLOUR_WINDOWTEXT));
                wxFont presFont = presentLabel->GetFont();
                presFont.SetWeight(wxFONTWEIGHT_NORMAL);
                presentLabel->SetFont(presFont);

                m_votingProcedureMenuItem->Enable();
        }
        
        wxGetApp().session()->saveState();        
}

void wxMUNFrame::ResetModCaucusSpeakerLabels(bool clearTotal) {

        clearTimerLabels(MOD_CAUCUS_SPEAKER_GAUGE, MOD_CAUCUS_SPEAKER_TIME_LEFT, MOD_CAUCUS_SPEAKER);
        
        if(clearTotal) {
                wxStaticText *STtime  = ((wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_TOTAL_SPEAKER_TIME) );
                STtime->SetLabel(wxString::Format(wxT("00:00") ));
        }
}

void wxMUNFrame::ResetModCaucusLabels(bool clearSpeakerCtrls, bool clearSpeakerTotal) {
        clearTimerLabels(MOD_CAUCUS_GAUGE, MOD_CAUCUS_TIME_LEFT, MOD_CAUCUS_TOPIC, 0, true);
        clearCountryFlag(MOD_CAUCUS_SPEAKER_FLAG);

        wxStaticText *totalTime = ((wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_TOTAL_TIME) );
        totalTime->SetLabel(wxString::Format(wxT("00:00:00") ));
        
        if(clearSpeakerCtrls) {
                ResetModCaucusSpeakerLabels(clearSpeakerTotal);
        }
}

void wxMUNFrame::ResetUnModCaucusLabels() {
        clearTimerLabels(UNMOD_CAUCUS_GAUGE, UNMOD_CAUCUS_TIME_LEFT, UNMOD_CAUCUS_TOPIC, 0, true);

        wxStaticText *totalTime = ((wxStaticText*) wxWindow::FindWindowById(UNMOD_CAUCUS_TOTAL_TIME) );
        totalTime->SetLabel(wxString::Format(wxT("00:00:00") ));
}

void wxMUNFrame::OnVotingMinutesChange ( wxSpinEvent &event ) {
        OnVotingTimeChange();
}

void wxMUNFrame::OnVotingSecondsChange ( wxSpinEvent &event ) {
        OnVotingTimeChange();
}

void wxMUNFrame::OnVotingTimeChange () {
        wxSpinCtrl *minutes = (wxSpinCtrl*) wxWindow::FindWindowById(VOTING_TIME_MINUTES);
        wxSpinCtrl *seconds = (wxSpinCtrl*) wxWindow::FindWindowById(VOTING_TIME_SECONDS);
        
        int min = minutes->GetValue();
        int sec = seconds->GetValue();
        
        unsigned int duration = 60*min + sec;
        
        if(duration == 0) {
                wxMessageBox(wxT("Warning: you just set the speakers time to 0 seconds!"),
                                wxT("Cannot execute action"),
                                wxICON_WARNING | wxOK, this);
        }

        realTime(min,sec);
        minutes->SetValue(min);
        seconds->SetValue(sec);
                
        wxStaticText *time  = ((wxStaticText*) wxWindow::FindWindowById(VOTING_TOTAL_TIME) );
        time->SetLabel(wxString::Format(wxT("%02d:%02d"), min, sec));
        
        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(VOTING_GAUGE);
        progressBar->SetRange(duration);
        
        wxGetApp().session()->committee()->setVotingTime(duration);
}

void wxMUNFrame::OnVotingOnChoice( wxCommandEvent& event ) {
        wxChoice *choices = (wxChoice*) wxWindow::FindWindowById(VOTING_ON_CHOICES);
        wxStaticText *choiceText = (wxStaticText*) wxWindow::FindWindowById(VOTING_ON);
        
        choiceText->SetLabel(choices->GetStringSelection());
        choiceText->SetSize(choiceText->GetBestSize());
        choiceText->CentreOnParent(wxHORIZONTAL);
}

//TODO: share most of this function with oninagainstselect
void wxMUNFrame::OnSpeakingInFavourListSelect( wxCommandEvent& event ) {
        // TODO: Implement OnSpeakingInFavourListSelect
        wxListBox *inFavourList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR);
        int i = inFavourList->GetSelection();

        if(i == wxNOT_FOUND || i != 0 ) //to avoid accidental mis-clicks the speaker *must* be on top of the list
                return;

        StopAllSpeakers();
        
        // send some signal that we have a speaker and start a counter somewhere...
        _speakerLength = wxGetApp().session()->committee()->votingTime();
        
        const unsigned int minutes = _speakerLength % 3600 / 60;
        const unsigned int seconds = _speakerLength % 60;

        wxStaticText *timeLeft = (wxStaticText*) wxWindow::FindWindowById(VOTING_TIME_LEFT);
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d"), minutes, seconds));

        wxStaticText *favourLabel = (wxStaticText*) wxWindow::FindWindowById(VOTING_IN_FAVOUR);
        wxStaticText *againstLabel = (wxStaticText*) wxWindow::FindWindowById(VOTING_AGAINST);
        
        favourLabel->Enable(true); againstLabel->Enable(false);
        favourLabel->SetForegroundColour( wxColour( 0,79,0) );
        againstLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(VOTING_GAUGE);
        progressBar->SetValue(0);
        
        // set flag & country name!
        wxStaticText *country =  (wxStaticText*) wxWindow::FindWindowById(VOTING_SPEAKER);
        wxString name=inFavourList->GetStringSelection();
        country->SetLabel(name);
        country->SetSize(country->GetBestSize());
        country->CentreOnParent(wxHORIZONTAL);
        setCountryFlag(VOTING_SPEAKER_FLAG, name);
        
        
        // DO NOT disable voting choices, maybe speaker end speech before _speakerLength seconds!
        inFavourList->Delete(i);
        DisableGSLCtrls();
        DisableCaucusCtrls();
        DisableVotingTimeCtrls();

        m_GSLpanel->Enable(false); m_singleSpeakerPanel->Enable(false);
        m_modCaucusPanel->Enable(false); m_unModCaucusPanel->Enable(false);

        _speakerSeconds = _speakerLength;
        _speakerRunning = true;
        _votingSpeakerTimer.Start(1000);

}

void wxMUNFrame::OnInFavourUpClick( wxCommandEvent& event ) {
        wxListBox *inFavourList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR);
        int i = inFavourList->GetSelection();

        if(i == wxNOT_FOUND || i == 0 ) //can't move first upwards
                return;
        
        swapListStrings(inFavourList, i, i-1);
        inFavourList->SetSelection(i-1);
}

void wxMUNFrame::OnInFavourDownClick( wxCommandEvent& event ) {
        wxListBox *inFavourList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR);
        int i = inFavourList->GetSelection();
        int last = inFavourList->GetCount()-1;
        
        if(i == wxNOT_FOUND || i == last) //can't move last downwards
                return;
        
        swapListStrings(inFavourList, i, i+1);
        inFavourList->SetSelection(i+1);
}

void wxMUNFrame::OnInFavourDeleteClick( wxCommandEvent& event ) {
        wxListBox *inFavourList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR);

        int i = inFavourList->GetSelection();
        if(i == wxNOT_FOUND)
                return;

        inFavourList->Delete(i);
}

void wxMUNFrame::OnInFavourClearClick( wxCommandEvent& event ) {
        wxListBox *inFavourList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR);
        inFavourList->Clear();
}

void wxMUNFrame::OnSpeakingInFavourChoice( wxCommandEvent& event ) {
        //adds member to in favour list

        wxChoice *choices = (wxChoice*) (wxWindow::FindWindowById(SPEAKING_IN_FAVOUR_CHOICES));
        wxString s = choices->GetStringSelection();

        // speaker must be present on neither of the lists
        wxListBox *inFavourList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR);
        wxListBox *againstList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_AGAINST);

        if(inFavourList->FindString(s) == wxNOT_FOUND && againstList->FindString(s) == wxNOT_FOUND)
                inFavourList->Append(s);

}

//TODO: share most of this function with oninfavourselect
void wxMUNFrame::OnSpeakingAgainstListSelect( wxCommandEvent& event ) {
        wxListBox *againstList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_AGAINST);
        int i = againstList->GetSelection();

        if(i == wxNOT_FOUND || i != 0 ) //to avoid accidental mis-clicks the speaker *must* be on top of the list
                return;

        StopAllSpeakers();
        
        // send some signal that we have a speaker and start a counter somewhere...
        _speakerLength = wxGetApp().session()->committee()->votingTime();
        
        const unsigned int minutes = _speakerLength % 3600 / 60;
        const unsigned int seconds = _speakerLength % 60;

        wxStaticText *timeLeft = (wxStaticText*) wxWindow::FindWindowById(VOTING_TIME_LEFT);
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d"), minutes, seconds));

        wxStaticText *favourLabel = (wxStaticText*) wxWindow::FindWindowById(VOTING_IN_FAVOUR);
        wxStaticText *againstLabel = (wxStaticText*) wxWindow::FindWindowById(VOTING_AGAINST);
        
        favourLabel->Enable(false); againstLabel->Enable(true);
        againstLabel->SetForegroundColour( wxColour( 187,14,14) );
        favourLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(VOTING_GAUGE);
        progressBar->SetValue(0);
        
        // set flag & country name!
        wxStaticText *country =  (wxStaticText*) wxWindow::FindWindowById(VOTING_SPEAKER);
        wxString name = againstList->GetStringSelection();
        country->SetLabel(name);
        country->SetSize(country->GetBestSize());
        country->CentreOnParent(wxHORIZONTAL);
        setCountryFlag(VOTING_SPEAKER_FLAG, name);
        
        // DO NOT disable voting choices, maybe speaker end speech before _speakerLength seconds!
        againstList->Delete(i);
        DisableGSLCtrls();
        DisableCaucusCtrls();
        DisableVotingTimeCtrls();
        
        m_GSLpanel->Enable(false); m_singleSpeakerPanel->Enable(false);
        m_modCaucusPanel->Enable(false); m_unModCaucusPanel->Enable(false);

        _speakerSeconds = _speakerLength;
        _speakerRunning = true;
        _votingSpeakerTimer.Start(1000);
}

void wxMUNFrame::OnAgainstUpClick( wxCommandEvent& event ) {
        wxListBox *againstList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_AGAINST);
        int i = againstList->GetSelection();

        if(i == wxNOT_FOUND || i == 0 ) //can't move first upwards
                return;
        
        swapListStrings(againstList, i, i-1);
        againstList->SetSelection(i-1);

}

void wxMUNFrame::OnAgainstDownClick( wxCommandEvent& event ) {
        wxListBox *againstList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_AGAINST);
        int i = againstList->GetSelection();
        int last = againstList->GetCount()-1;
        
        if(i == wxNOT_FOUND || i == last ) //can't move last downwards
                return;
        
        swapListStrings(againstList, i, i+1);
        againstList->SetSelection(i+1);
}

void wxMUNFrame::OnAgainstDeleteClick( wxCommandEvent& event ) {
        wxListBox *againstList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_AGAINST);

        int i = againstList->GetSelection();
        if(i == wxNOT_FOUND)
                return;

        againstList->Delete(i);
}

void wxMUNFrame::OnAgainstClearClick( wxCommandEvent& event ) {
        wxListBox *againstList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_AGAINST);
        againstList->Clear();
}

void wxMUNFrame::OnSpeakingAgainstChoice( wxCommandEvent& event ) {
        //adds member to against list
        wxChoice *choices = (wxChoice*) (wxWindow::FindWindowById(SPEAKING_AGAINST_CHOICES));
        wxString s = choices->GetStringSelection();

        wxListBox *inFavourList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_IN_FAVOUR);
        wxListBox *againstList = (wxListBox*) wxWindow::FindWindowById(SPEAKING_AGAINST);

        // speaker must be present on neither of the lists
        if(inFavourList->FindString(s) == wxNOT_FOUND && againstList->FindString(s) == wxNOT_FOUND)
                againstList->Append(s);

}

void wxMUNFrame::OnVotingStopSpeaker( wxCommandEvent& event) {
        if( !(_speakerRunning && (_votingSpeakerTimer.IsRunning() || _timerPaused) ) ) {
                return;
        }
        StopVotingSpeaker();
}

void wxMUNFrame::StopVotingSpeaker() {
        _votingSpeakerTimer.Stop();
        _speakerRunning = false;

        clearTimerLabels(VOTING_GAUGE, VOTING_TIME_LEFT, VOTING_SPEAKER, 0);

// don't disable texts here, allows user to keep track of what the last speaker did
//        wxStaticText *favourLabel = (wxStaticText*) wxWindow::FindWindowById(VOTING_IN_FAVOUR);
//        wxStaticText *againstLabel = (wxStaticText*) wxWindow::FindWindowById(VOTING_AGAINST);
//
//        favourLabel->Enable(false); againstLabel->Enable(false);
//        favourLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
//        againstLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

        wxStaticText *time  = ((wxStaticText*) wxWindow::FindWindowById(VOTING_TIME_LEFT) );
        time->SetLabel(wxString::Format(wxT("00:00") ));
        
        clearCountryFlag(VOTING_SPEAKER_FLAG);        
        
        EnableVotingCtrls();

        if(wxGetApp().session()->topicChosen()) {
                EnableCaucusCtrls();
                EnableGSLCtrls();
                EnableSingleSpeakerCtrls();
                
                m_GSLpanel->Enable(true); m_singleSpeakerPanel->Enable(true); m_procVotingPanel->Enable(true);
                m_modCaucusPanel->Enable(true); m_unModCaucusPanel->Enable(true);
        }
}

/*****************
 * ROLL CALL
 *****************/

void wxMUNFrame::OnStartVotingProcedureMenuSelect( wxCommandEvent& event) {
        wxMessageDialog dialog( NULL, 
                wxT("Do you really want to start voting procedure? Remember: you will no longer be able to edit the members present."), 
                wxT("Start voting procedure?"),
                wxNO_DEFAULT|wxYES_NO|wxICON_WARNING); 

        if(dialog.ShowModal() != wxID_YES)
                return;

        StopAllSpeakers();

        m_countriesPresentMenuItem->Enable(false);        

        //wxMenuItem *votingMenu = m_manageMenu->FindItem(VOTING_PROCEDURE_MENU); 
        m_votingProcedureMenuItem->Enable(false);
        
        //m_GSLpanel->Enable(false); m_singleSpeakerPanel->Enable(false);
        //m_modCaucusPanel->Enable(false); m_unModCaucusPanel->Enable(false);
        //Note: motions & proc voting still allowed in this stage!
        DisableGSLCtrls();
        DisableCaucusCtrls();

        //m_rollCallVotePanel->Enable(true);
        EnableAndResetRollCallCtrls();
        
        m_mainauinotebook->SetSelection(m_mainauinotebook->GetPageIndex(m_rollCallVotePanel));
        
        RollCallVote **rcVote = wxGetApp().session()->RCVote();
        *rcVote = new RollCallVote;

        m_minimumInFavourSpin->SetRange(0, wxGetApp().session()->committee()->numMembersPresent() );
}

void wxMUNFrame::OnRollCallDisplayOutcomeCheck(wxCommandEvent& event) {
        if(m_rollCallDisplayOutcome->GetValue()) {
                m_inFavourCount->Enable(true);
                m_againstCount->Enable(true);
                m_abstentionsCount->Enable(true);

                m_inFavourCount->SetForegroundColour( wxColour( wxSYS_COLOUR_WINDOWTEXT) );
                m_againstCount->SetForegroundColour( wxColour( wxSYS_COLOUR_WINDOWTEXT) );
                m_abstentionsCount->SetForegroundColour( wxColour( wxSYS_COLOUR_WINDOWTEXT) );

                if(m_vetoRadioBtn->GetValue() && !m_rollCallConsensusCheckbox->GetValue()) {
                        m_vetoText->Enable(true);
                        m_vetoText->SetForegroundColour( wxColour( wxSYS_COLOUR_WINDOWTEXT) );
                }

                DisplayRollCallOutcome();
        } else {
                m_inFavourCount->Enable(false);
                m_againstCount->Enable(false);
                m_abstentionsCount->Enable(false);
                m_vetoText->Enable(false);
                
                m_inFavourCount->SetForegroundColour( wxColour( wxSYS_COLOUR_GRAYTEXT) );
                m_againstCount->SetForegroundColour( wxColour( wxSYS_COLOUR_GRAYTEXT) );
                m_abstentionsCount->SetForegroundColour( wxColour( wxSYS_COLOUR_GRAYTEXT) );
                m_vetoText->SetForegroundColour( wxColour( wxSYS_COLOUR_GRAYTEXT) );

                m_inFavourCount->SetLabel( wxString::Format(wxT("%i"), 0 ) );
                m_againstCount->SetLabel( wxString::Format(wxT("%i"), 0 ) );
                m_abstentionsCount->SetLabel( wxString::Format(wxT("%i"), 0 ) );
        
                m_outcomeTextFailed->Enable(false);
                m_outcomeTextPassed->Enable(false);
                m_vetoText->SetLabel(wxT("no"));
                
        }
}

void wxMUNFrame::OnRollCallConsensusCheck(wxCommandEvent& event) {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();
                        
        (*rcVote)->SetConsensusBasedFlag(m_rollCallConsensusCheckbox->GetValue());
        m_noVetoRadioBtn->Enable(!m_rollCallConsensusCheckbox->GetValue());
        m_vetoRadioBtn->Enable(!m_rollCallConsensusCheckbox->GetValue());
        
        m_rollCallMinimumInFavourCheckbox->Enable(!m_rollCallConsensusCheckbox->GetValue());
        m_minimumInFavourSpin->Enable(!m_rollCallConsensusCheckbox->GetValue() && m_rollCallMinimumInFavourCheckbox->GetValue() );
        
        ToggleRollCallVetoLabels();
        
        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::OnRollCallMimimunInFavourCheck(wxCommandEvent& event) {
        m_minimumInFavourSpin->Enable( m_rollCallMinimumInFavourCheckbox->GetValue() );
        
        RollCallVote **rcVote = wxGetApp().session()->RCVote();
        (*rcVote)->SetMinInFavourFlag(m_rollCallMinimumInFavourCheckbox->GetValue());
        
        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
        
}

void wxMUNFrame::OnRollCallMinimumInFavourChange( wxSpinEvent& event) {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();
        (*rcVote)->SetMinInFavour(m_minimumInFavourSpin->GetValue());

        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::OnRollCallSCModeToggle(wxCommandEvent& event) {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();
        (*rcVote)->SetSCModeFlag(m_vetoRadioBtn->GetValue());

        ToggleRollCallVetoLabels();

        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::ToggleRollCallVetoLabels() {
        if(m_vetoRadioBtn->GetValue() && !m_rollCallConsensusCheckbox->GetValue())
                m_vetoTextLabel->Enable();
        else 
                m_vetoTextLabel->Enable(false);        
}

wxString wxMUNFrame::RollCallGetName(wxListBox *list) {
        int i = list->GetSelection();
        int last = list->GetCount()-1;

        wxString name = list->GetStringSelection();
        int j = (i+1 > last ) ? 0 : i+1; //cycle the list with periodic boundary conditions

        //first set selection, then delete previous!
        list->SetSelection(j);
        list->Delete(i);
                
        return name;
}

wxString wxMUNFrame::RollCallGetFirstRoundName(bool isPass) {
        wxString name = RollCallGetName(m_rollCallFirstRoundChoices);
        
        if(m_rollCallFirstRoundChoices->GetCount() == 0)
                StartRollCallSecondRound(isPass);
        
        return name;
}

wxString wxMUNFrame::RollCallGetSecondRoundName() {
        wxString name = RollCallGetName(m_rollCallSecondRoundChoices);

        if(m_rollCallSecondRoundChoices->GetCount() == 0) {
                m_rollCallSecondRoundText->Enable(false);        
                m_rollCallSecondRoundChoices->Enable(false);
                m_rollCallSecondRoundYesButton->Enable(false);
                m_rollCallSecondRoundNoButton->Enable(false);
                
                if ( m_rollCallVotingWithRights->GetCount() > 0) {
                        m_rollCallVotingWithRightsLabel->Enable(true);
                        m_rollCallVotingWithRights->Enable(true);
                }
        }
        
        return name;
}

void wxMUNFrame::OnRollCallFirstRoundYes(wxCommandEvent& event) {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();        
        (*rcVote)->addInFavour(RollCallGetFirstRoundName());
        
        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::OnRollCallFirstRoundNo(wxCommandEvent& event) {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();        
        (*rcVote)->addAgainst(RollCallGetFirstRoundName());
        
        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::OnRollCallFirstRoundYesWithRights(wxCommandEvent& event) {
        wxString name = RollCallGetFirstRoundName();

        RollCallVote **rcVote = wxGetApp().session()->RCVote();        
        (*rcVote)->addInFavour(name);
        
        m_rollCallVotingWithRights->Append(name + wxT(" (F)"));
        
        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::OnRollCallFirstRoundNoWithRights(wxCommandEvent& event) {
        wxString name = RollCallGetFirstRoundName();

        RollCallVote **rcVote = wxGetApp().session()->RCVote();        
        (*rcVote)->addAgainst(name);
        
        m_rollCallVotingWithRights->Append(name + wxT(" (A)"));
        
        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::OnRollCallFirstRoundAbstain(wxCommandEvent& event) {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();        
        (*rcVote)->addAbstaining(RollCallGetFirstRoundName());
        
        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::OnRollCallFirstRoundPass(wxCommandEvent& event) {
        m_rollCallSecondRoundChoices->Append(RollCallGetFirstRoundName(true));

        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}


void wxMUNFrame::OnRollCallSecondRoundYes(wxCommandEvent& event) {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();        
        (*rcVote)->addInFavour(RollCallGetSecondRoundName());
        
        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::OnRollCallSecondRoundNo(wxCommandEvent& event) {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();        
        (*rcVote)->addAgainst(RollCallGetSecondRoundName());
        
        if(m_rollCallDisplayOutcome->GetValue())
                DisplayRollCallOutcome();
}

void wxMUNFrame::StartRollCallSecondRound(bool lastIsPass) {
        m_rollCallFirstRoundChoices->Enable(false);
        m_rollCallFirstRoundYesButton->Enable(false);
        m_rollCallFirstRoundNoButton->Enable(false);
        m_rollCallFirstRoundYesWithRightsButton->Enable(false);
        m_rollCallFirstRoundNoWithRightsButton->Enable(false);
        m_rollCallFirstRoundAbstainButton->Enable(false);
        m_rollCallFirstRoundPassButton->Enable(false);
        m_rollCallFirstRoundText->Enable(false);

        if( m_rollCallSecondRoundChoices->GetCount() > 0 || lastIsPass ) { //if last is only pass, it will only be written later to the list and count == 0
                m_rollCallSecondRoundText->Enable(true);
                m_rollCallSecondRoundChoices->Enable(true);
                m_rollCallSecondRoundYesButton->Enable(true);
                m_rollCallSecondRoundNoButton->Enable(true);
        } else if ( m_rollCallVotingWithRights->GetCount() > 0) {
                m_rollCallVotingWithRightsLabel->Enable(true);
                m_rollCallVotingWithRights->Enable(true);
        }
}

void wxMUNFrame::DisplayRollCallOutcome() {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();        
        (*rcVote)->Print();

        if((*rcVote)->IsSCMode() && !(*rcVote)->IsConsensusBased())
                m_vetoText->Enable();
        else
                m_vetoText->Enable(false);

        if( (*rcVote)->numAgainst() == 0 && (*rcVote)->numInFavour() == 0 && (*rcVote)->numAbstentions() == 0 && m_rollCallSecondRoundChoices->GetCount() == 0 )
                return;
        
        m_inFavourCount->SetLabel( wxString::Format(wxT("%i"), (*rcVote)->numInFavour() ) );
        m_againstCount->SetLabel( wxString::Format(wxT("%i"), (*rcVote)->numAgainst() ) );
        m_abstentionsCount->SetLabel( wxString::Format(wxT("%i"), (*rcVote)->numAbstentions() ) );
        
        m_outcomeTextFailed->Enable(false);
        m_outcomeTextPassed->Enable(false);
        m_vetoText->SetLabel(wxT("no"));

        if( (*rcVote)->Passed() ) {
                m_outcomeTextPassed->Enable();
        } else {
                m_outcomeTextFailed->Enable();
                if( (*rcVote)->IsSCMode() && (*rcVote)->IsVetoed() ) {
                        m_vetoText->SetLabel(wxT("yes"));
                }
        }
}

void wxMUNFrame::OnRollCallVotingWithRightsSpeakerSelect(wxCommandEvent& event) {
        wxString name = m_rollCallVotingWithRights->GetStringSelection();
        int i =  m_rollCallVotingWithRights->GetSelection();

        m_mainauinotebook->SetSelection(m_mainauinotebook->GetPageIndex(m_singleSpeakerPanel));
        StartSingleSpeaker( name.Mid(0, name.Length()-4 ) ); // chop off the " (A)" or " (F)"

        m_rollCallVotingWithRights->Delete(i);
        if( m_rollCallVotingWithRights->GetCount() == 0) {
                m_rollCallVotingWithRightsLabel->Enable(false);
                m_rollCallVotingWithRights->Enable(false);        
        }
}

void wxMUNFrame::OnRollCallClearVotes(wxCommandEvent& event) {
        RollCallVote **rcVote = wxGetApp().session()->RCVote();

        if( (*rcVote)->numAgainst() == 0 && (*rcVote)->numInFavour() == 0 && (*rcVote)->numAbstentions() == 0 && m_rollCallSecondRoundChoices->GetCount() == 0 )
                return;
                
        wxMessageDialog dialog( NULL, 
                wxT("Do you really want to clear all votes cast?"), 
                wxT("Clear all votes"),
                wxNO_DEFAULT|wxYES_NO|wxICON_WARNING); 

        if(dialog.ShowModal() != wxID_YES)
                return;

        *rcVote = new RollCallVote(m_rollCallConsensusCheckbox->GetValue(), m_vetoRadioBtn->GetValue());

        m_rollCallDisplayOutcome->SetValue(false);
        //SetRollCallFirstRoundLabels();
        EnableAndResetRollCallCtrls();

        DisplayRollCallOutcome();
}

void wxMUNFrame::EnableAndResetRollCallCtrls() {
        m_rollCallDisplayOutcome->Enable(true);
        m_rollCallClearButton->Enable(true);

        m_inFavourCountText->Enable(true); m_againstCountText->Enable(true); m_abstentionsCountText->Enable(true); m_outcomeLabelText->Enable(true); 
        m_rollCallConsensusCheckbox->Enable(true); m_noVetoRadioBtn->Enable(true); m_vetoRadioBtn->Enable(true);
        m_rollCallMinimumInFavourCheckbox->Enable(true); m_minimumInFavourSpin->Enable(false);

        std::map<wxString, Country>* countries = wxGetApp().session()->committee()->countries();
        std::map<wxString, Country>::iterator it = countries->begin();

        m_rollCallFirstRoundChoices->Clear();
        m_rollCallSecondRoundChoices->Clear();
        for(; it != countries->end(); it++) {
                if( it->second.isObserver() || !it->second.isPresent())
                        continue;
                        
                m_rollCallFirstRoundChoices->Append(it->second.name());
        }

        m_rollCallFirstRoundText->Enable(true); m_rollCallSecondRoundText->Enable(false);
        m_rollCallFirstRoundChoices->Enable(true); m_rollCallSecondRoundChoices->Enable(false);
        m_rollCallFirstRoundYesButton->Enable(true); m_rollCallSecondRoundYesButton->Enable(false);
        m_rollCallFirstRoundNoButton->Enable(true); m_rollCallSecondRoundNoButton->Enable(false);
        m_rollCallFirstRoundYesWithRightsButton->Enable(true);
        m_rollCallFirstRoundNoWithRightsButton->Enable(true);
        m_rollCallFirstRoundAbstainButton->Enable(true);
        m_rollCallFirstRoundPassButton->Enable(true);

        m_inFavourCount->Enable(false);
        m_againstCount->Enable(false);
        m_abstentionsCount->Enable(false);
        m_outcomeTextFailed->Enable(false);
        m_outcomeTextPassed->Enable(false);

        m_inFavourCount->SetLabel( wxString::Format(wxT("%i"), 0 ) );
        m_againstCount->SetLabel( wxString::Format(wxT("%i"), 0 ) );
        m_abstentionsCount->SetLabel( wxString::Format(wxT("%i"), 0 ) );
        m_vetoText->SetLabel(wxT("no"));

        m_rollCallVotingWithRightsLabel->Enable(false);
        m_rollCallVotingWithRights->Enable(false);
        m_rollCallVotingWithRights->Clear();
}

void wxMUNFrame::DisableRollCallCtrls() {
        m_rollCallDisplayOutcome->Enable(false);
        m_rollCallClearButton->Enable(false);

        m_inFavourCountText->Enable(false); m_againstCountText->Enable(false); m_abstentionsCountText->Enable(false); m_outcomeLabelText->Enable(false); 
        m_rollCallConsensusCheckbox->Enable(false); m_noVetoRadioBtn->Enable(false); m_vetoRadioBtn->Enable(false);
        m_rollCallMinimumInFavourCheckbox->Enable(false); m_minimumInFavourSpin->Enable(false);
        
        m_rollCallFirstRoundText->Enable(false); m_rollCallSecondRoundText->Enable(false);
        m_rollCallFirstRoundChoices->Enable(false); m_rollCallSecondRoundChoices->Enable(false);
        m_rollCallFirstRoundYesButton->Enable(false); m_rollCallSecondRoundYesButton->Enable(false);
        m_rollCallFirstRoundNoButton->Enable(false); m_rollCallSecondRoundNoButton->Enable(false);
        m_rollCallFirstRoundYesWithRightsButton->Enable(false);
        m_rollCallFirstRoundNoWithRightsButton->Enable(false);
        m_rollCallFirstRoundAbstainButton->Enable(false);
        m_rollCallFirstRoundPassButton->Enable(false);
        
        m_inFavourCount->Enable(false);
        m_againstCount->Enable(false);
        m_abstentionsCount->Enable(false);
        m_outcomeTextFailed->Enable(false);
        m_outcomeTextPassed->Enable(false);
}

/*****************
 * TIMERS
 *****************/

void wxMUNFrame::OnGSLSpeakerTimerEvent ( wxTimerEvent& event) {
        --_GSLspeakerSeconds;
        
        const unsigned int minutes = _GSLspeakerSeconds % 3600 / 60;
        const unsigned int seconds = _GSLspeakerSeconds % 60;
        
        wxStaticText *timeLeft  = ((wxStaticText*) wxWindow::FindWindowById(GSL_TIME_LEFT) );
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d"), minutes, seconds));

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(GSL_GAUGE);
        progressBar->SetValue(_GSLspeakerLength - _GSLspeakerSeconds);

        if(_GSLspeakerSeconds <= 10)
                timeLeft->SetForegroundColour(wxColour(wxT("RED")));

        if(_GSLspeakerSeconds == 0)
                StopGSL();
}

void wxMUNFrame::OnSingleSpeakerTimerEvent ( wxTimerEvent& event) {
        --_speakerSeconds;

        const unsigned int minutes = _speakerSeconds % 3600 / 60;
        const unsigned int seconds = _speakerSeconds % 60;
        
        wxStaticText *timeLeft  = ((wxStaticText*) wxWindow::FindWindowById(SINGLE_SPEAKER_TIME_LEFT) );
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d"), minutes, seconds));

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(SINGLE_SPEAKER_GAUGE);
        progressBar->SetValue(_speakerLength - _speakerSeconds);

        if(_speakerSeconds <= 10)
                timeLeft->SetForegroundColour(wxColour(wxT("RED")));

        if(_speakerSeconds == 0)
                StopSingleSpeaker();
}

void wxMUNFrame::StopSingleSpeaker() {
        EnableCaucusCtrls();
        EnableVotingCtrls();
        EnableGSLCtrls();

        DisableSingleSpeakerPauseButton();
        DisableSingleSpeakerResumeButton();
        
        EnableSingleSpeakerCtrls();        
        ResetSingleSpeakerLabels();
        
        m_GSLpanel->Enable(true); m_singleSpeakerPanel->Enable(true); m_procVotingPanel->Enable(true);
        m_modCaucusPanel->Enable(true); m_unModCaucusPanel->Enable(true);

        _singleSpeakerTimer.Stop();
        _speakerRunning = false;
}

void wxMUNFrame::OnCaucusSpeakerTimerEvent(wxTimerEvent&) {
        --_speakerSeconds;
        
        const unsigned int minutes = _speakerSeconds % 3600 / 60;
        const unsigned int seconds = _speakerSeconds % 60;

        wxStaticText *timeLeft  = ((wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_SPEAKER_TIME_LEFT) );
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d"), minutes, seconds));

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(MOD_CAUCUS_SPEAKER_GAUGE);
        progressBar->SetValue(_speakerLength - _speakerSeconds);

        if(_speakerSeconds <= 10) {
                timeLeft->SetForegroundColour(wxColour(wxT("RED")));
        }

        if(_speakerSeconds == 0) {
                _caucusSpeakerTimer.Stop();
                _speakerRunning = false;
                ResetModCaucusSpeakerLabels(false);
                clearCountryFlag(MOD_CAUCUS_SPEAKER_FLAG);
                
                if(!_caucusRunning) {
                        //speaker was last in caucus
                        StopModCaucus(true); //clear everything!

                        wxMessageDialog dialog( NULL, 
                                wxT("The current moderated caucus has lapsed!"), 
                                wxT("Caucus ended"),
                                wxOK|wxICON_WARNING);
                                
                        if ( dialog.ShowModal() == wxID_OK )
                                return;
                }
        }
}

void wxMUNFrame::OnModCaucusTimerEvent(wxTimerEvent&) {
        // this function does not do much, as a speaker might still be speaking!
        
        --_caucusSeconds;

        const unsigned int hours = _caucusSeconds / 3600;
        const unsigned int minutes = _caucusSeconds % 3600 / 60;
        const unsigned int seconds = _caucusSeconds % 60;

        wxStaticText *timeLeft  = ((wxStaticText*) wxWindow::FindWindowById(MOD_CAUCUS_TIME_LEFT) );
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d:%02d"), hours, minutes, seconds));

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(MOD_CAUCUS_GAUGE);
        progressBar->SetValue(_caucusLength - _caucusSeconds);

        if(_caucusSeconds == 0)
                StopModCaucus(false); //don't clear anything!
 
}

void wxMUNFrame::StopModCaucus(bool clearCtrls) {
        EnableCaucusCtrls();
        EnableVotingCtrls();
        EnableGSLCtrls();
        EnableSingleSpeakerCtrls();

        m_GSLpanel->Enable(true); m_singleSpeakerPanel->Enable(true); m_procVotingPanel->Enable(true);
        m_modCaucusPanel->Enable(true); m_unModCaucusPanel->Enable(true);

        if(clearCtrls) { //user hit stop button or speakertimer found out caucustimer already stopped when he ended, so we clear
                ResetModCaucusLabels(true);
                _caucusSpeakerTimer.Stop(); //stop the speaker
                DisableModCaucusPauseButton(false);
        }

        _modCaucusTimer.Stop();
        _caucusRunning = false;
}

void wxMUNFrame::StopUnModCaucus() {
        EnableCaucusCtrls();
        EnableGSLCtrls();
        EnableVotingCtrls();
        EnableSingleSpeakerCtrls();
        ResetUnModCaucusLabels();

        m_GSLpanel->Enable(true); m_singleSpeakerPanel->Enable(true); m_procVotingPanel->Enable(true);
        m_modCaucusPanel->Enable(true); m_unModCaucusPanel->Enable(true);

        _unmodCaucusTimer.Stop();
        _caucusRunning = false;
}

void wxMUNFrame::OnUnModCaucusTimerEvent(wxTimerEvent&) {
        --_caucusSeconds;

        const unsigned int hours = _caucusSeconds / 3600;
        const unsigned int minutes = _caucusSeconds % 3600 / 60;
        const unsigned int seconds = _caucusSeconds % 60;

        wxStaticText *timeLeft  = ((wxStaticText*) wxWindow::FindWindowById(UNMOD_CAUCUS_TIME_LEFT) );
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d:%02d"), hours, minutes, seconds));

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(UNMOD_CAUCUS_GAUGE);
        progressBar->SetValue(_caucusLength - _caucusSeconds);
        
        if(_caucusSeconds <= 30) {
                timeLeft->SetForegroundColour(wxColour(wxT("RED")));
        } 
        
        if(_caucusSeconds == 0) {
                StopUnModCaucus();

                wxMessageDialog dialog( NULL, 
                        wxT("The current unmoderated caucus has lapsed!"), 
                        wxT("Caucus ended"),
                        wxOK|wxICON_WARNING);

                if ( dialog.ShowModal() == wxID_OK )
                        return;

        } 
}

void wxMUNFrame::OnVotingSpeakerTimerEvent ( wxTimerEvent& event) {
        --_speakerSeconds;

        const unsigned int minutes = _speakerSeconds % 3600 / 60;
        const unsigned int seconds = _speakerSeconds % 60;

        wxStaticText *timeLeft  = ((wxStaticText*) wxWindow::FindWindowById(VOTING_TIME_LEFT) );
        timeLeft->SetLabel(wxString::Format(wxT("%02d:%02d"), minutes, seconds));

        wxGauge* progressBar = (wxGauge*) wxWindow::FindWindowById(VOTING_GAUGE);
        progressBar->SetValue(_speakerLength - _speakerSeconds);

        if(_speakerSeconds <= 10)
                timeLeft->SetForegroundColour(wxColour(wxT("RED")));

        if(_speakerSeconds == 0)
                StopVotingSpeaker();
}

// set up the timers
BEGIN_EVENT_TABLE(wxMUNFrame, wxFrame)
   EVT_TIMER(CAUCUS_SPEAKER_TIMER,  wxMUNFrame::OnCaucusSpeakerTimerEvent)
   EVT_TIMER(VOTING_SPEAKER_TIMER,  wxMUNFrame::OnVotingSpeakerTimerEvent)
   EVT_TIMER(GSL_SPEAKER_TIMER,  wxMUNFrame::OnGSLSpeakerTimerEvent)
   EVT_TIMER(SINGLE_SPEAKER_TIMER,  wxMUNFrame::OnSingleSpeakerTimerEvent)
   EVT_TIMER(UNMOD_CAUCUS_TIMER,   wxMUNFrame::OnUnModCaucusTimerEvent)
   EVT_TIMER(MOD_CAUCUS_TIMER,   wxMUNFrame::OnModCaucusTimerEvent)
END_EVENT_TABLE()
