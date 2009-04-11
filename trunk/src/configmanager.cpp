/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>

#include "configmanager.h"
#include "prep.h"

#define cbC2U wxString::FromAscii

wxString ConfigManager::config_folder;
wxString ConfigManager::home_folder;
wxString ConfigManager::data_path_user;
wxString ConfigManager::data_path_global;
wxString ConfigManager::app_path;
wxString ConfigManager::temp_folder;
bool ConfigManager::relo = 0;

namespace
{
	wxString DetermineExecutablePath()
	{
		#if (__WXMSW__)
			wxChar name[MAX_PATH];
			GetModuleFileName(0L, name, MAX_PATH);
			wxFileName fname(name);
			return fname.GetPath(wxPATH_GET_VOLUME);
		#else
		#if (__linux__)
			char c[PATH_MAX+1];
			char *p = realpath("/proc/self/exe", &c[0]);
			if(p == 0)
				return _T(".");
			wxFileName fname(cbC2U(p));
			return fname.GetPath(wxPATH_GET_VOLUME);
		#elif defined(sun) || defined(__sun)
			wxFileName fname(cbC2U(getexecname()));
			return fname.GetPath(wxPATH_GET_VOLUME);
		#elif defined(__APPLE__) && defined(__MACH__)
			char path[MAXPATHLEN+1];
			uint32_t path_len = MAXPATHLEN;
			// SPI first appeared in Mac OS X 10.2
			_NSGetExecutablePath(path, &path_len);
			wxFileName fname(wxString(path, wxConvUTF8));
			return fname.GetPath(wxPATH_GET_VOLUME);
		#else
			return _T(".");
		#endif
		#endif
	};
	wxString DetermineResourcesPath()
	{
		#if defined(__WXMAC__)
			CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(CFBundleGetMainBundle());
			CFURLRef absoluteURL = CFURLCopyAbsoluteURL(resourcesURL); // relative -> absolute
			CFRelease(resourcesURL);
			CFStringRef cfStrPath = CFURLCopyFileSystemPath(absoluteURL,kCFURLPOSIXPathStyle);
			CFRelease(absoluteURL);
			wxString str = wxMacCFStringHolder(cfStrPath).AsString(wxLocale::GetSystemEncoding());
			if (!str.Contains(wxString(_T("/Resources"))))
			   return ::DetermineExecutablePath() + _T("/.."); // not a bundle, use relative path
			return str;
		#else
			return _T(".");
		#endif
	};
}

wxString ConfigManager::FindDataFile(const wxString& filename){
	wxPathList searchPaths;

	wxString u(wxStandardPathsBase::Get().GetUserDataDir() + wxFILE_SEP_PATH + filename);
	wxString e(ConfigManager::GetFolder(sdDataGlobal) + wxFILE_SEP_PATH +filename);

	//std::cout << u.mb_str() << std::endl;
	//std::cout << e.mb_str() << std::endl;

	if(::wxFileExists(u))
		return u;
	
	if(::wxFileExists(e)){
		ConfigManager::relo = true;
		return e;
	}

	return wxEmptyString;
}

wxString ConfigManager::GetFolder(SearchDirs dir){
	static bool once = 1;

	if(once) {
		InitPaths();
		once = false;
	}

	switch (dir) {
		case sdHome:
			return ConfigManager::home_folder;

		case sdBase:
			return ConfigManager::app_path;

		case sdTemp:
			return ConfigManager::temp_folder;

		case sdConfig:
			return ConfigManager::config_folder;

		case sdCurrent:
			return ::wxGetCwd();

		case sdDataGlobal:
			return ConfigManager::data_path_global;

		case sdDataUser:
			return ConfigManager::data_path_user;

		default:
			return wxEmptyString;
	}
}

void ConfigManager::InitPaths() {
	ConfigManager::config_folder = wxStandardPathsBase::Get().GetUserDataDir();
	ConfigManager::home_folder = wxStandardPathsBase::Get().GetUserConfigDir();
	ConfigManager::app_path = ::DetermineExecutablePath();
	wxString res_path = ::DetermineResourcesPath();

	// if non-empty, the app has overriden it (e.g. "--prefix" was passed in the command line)
	if (data_path_global.IsEmpty()) {
		if(platform::windows)
			ConfigManager::data_path_global = app_path + wxFILE_SEP_PATH + _T("share") + wxFILE_SEP_PATH +_T("wxmun");
		else if(platform::macosx)
			ConfigManager::data_path_global = res_path + wxFILE_SEP_PATH + _T("share") + wxFILE_SEP_PATH +_T("wxmun");
		else
			ConfigManager::data_path_global = wxStandardPathsBase::Get().GetDataDir();
	}

	ConfigManager::data_path_user = ConfigManager::relo ? data_path_global : config_folder + _T("/share/wxmun");

   // CreateDirRecursively(ConfigManager::config_folder);
   // CreateDirRecursively(ConfigManager::data_path_user   + _T("/plugins/"));
   // CreateDir(ConfigManager::data_path_user   + _T("/scripts/"));

	ConfigManager::temp_folder = wxStandardPathsBase::Get().GetTempDir();
};
