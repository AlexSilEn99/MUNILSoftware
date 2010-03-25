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
	sdConfig		= 0x0010, ///< Config folder
	sdCurrent		= 0x0020, ///< Current working folder
        sdResources             = 0x0040, ///< Resources path

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
	static wxString FindResourceFile(const wxString&);
private:
	static void InitPaths();
	static wxString config_folder;
	static wxString home_folder;
	static wxString data_path_user;
	static wxString data_path_global;
	static wxString app_path;
	static wxString resource_path;
	static wxString temp_folder;
	static bool relo;
};

#endif /* CONFIGMANAGER_H */
