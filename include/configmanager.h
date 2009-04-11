/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

/* ------------------------------------------------------------------------------------------------------------------*/
/** Search dirs values. Used as a bitmask in ConfigManager::LocateDataFile() and friends.*/
enum SearchDirs
{
	sdHome			= 0x0001, ///< User's home directory
	sdBase			= 0x0002, ///< Code::Blocks' installation base
	sdTemp			= 0x0004, ///< System-wide temp folder
	sdPath			= 0x0008, ///< All dirs in the PATH environment variable
	sdConfig		  = 0x0010, ///< Config folder
	sdCurrent		 = 0x0020, ///< Current working folder

	sdDataUser		= 0x0400, ///< Data folder in user's dir
	sdAllUser		 = 0x0f00, ///< Convenience value meaning "all sd*User values"

	sdDataGlobal	  = 0x4000, ///< Data folder in base dir
	sdAllGlobal	   = 0xf000, ///< Convenience value meaning "all sd*Global values"

	sdAllKnown		= 0xffff, ///< All known dirs (i.e. all of the above)
};

class ConfigManager {
public:
	static wxString GetFolder(SearchDirs dir);
	static wxString FindDataFile(const wxString&);
private:
	static void InitPaths();
	static wxString config_folder;
	static wxString home_folder;
	static wxString data_path_user;
	static wxString data_path_global;
	static wxString app_path;
	static wxString temp_folder;
	static bool relo;
};

#endif /* CONFIGMANAGER_H */
