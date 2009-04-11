/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
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

#if ( !defined (PREP_H) && defined(__cplusplus) )
#define PREP_H

/*  ---------------------------------------------------------------------------------------------------------
    platform::id
        Value of type platform::identifier describing the target platform

    platform::windows, platform::macosx, platform::linux
    platform::freebsd, platform::netbsd, platform::openbsd
    platform::darwin,  platform::solaris, platform::unix
        Boolean value that evaluates to true if the target platform is the same as the variable's name, false otherwise.
        Using the platform booleans is equivalent to using platform::id, but results in nicer code.

    platform::unicode
        Boolean value that evaluates to true if this application was built in Unicode mode. Of course this does not
        tell anything about the host system's actual capabilities.

    platform::gtk
    platform::carbon
    platform::cocoa
        Boolean values showing the presence of very specific toolkits. Use only for workarounds to specific problems with these.

    platform::bits
        Size of pointer in bits as a measure of CPU architecture (32 or 64 bits).
*/

namespace platform
{
    enum identifier
    {
        platform_unknown,
        platform_windows,
        platform_linux,
        platform_freebsd,
        platform_netbsd,
        platform_openbsd,
        platform_darwin,
        platform_solaris,
        platform_macosx
    };

    // unfortunately we still need to use the preprocessor here...
    #if ( wxUSE_UNICODE )
    const bool unicode = true;
    #else
    const bool unicode = false;
    #endif

    #if   defined ( __WIN32__ )
    const identifier id = platform_windows;
    #elif defined ( __WXMAC__ )  || defined ( __WXCOCOA__ )
    const identifier id = platform_macosx;
    #elif defined ( __linux__ )  || defined ( LINUX )
    const identifier id = platform_linux;
    #elif defined ( FREEBSD )    || defined ( __FREEBSD__ )
    const identifier id = platform_freebsd;
    #elif defined ( NETBSD )     || defined ( __NETBSD__ )
    const identifier id = platform_netbsd;
    #elif defined ( OPENBSD )    || defined ( __OPENBSD__ )
    const identifier id = platform_openbsd;
    #elif defined ( DARWIN )     || defined ( __APPLE__ )
    const identifier id = platform_darwin;
    #elif defined(sun) || defined(__sun)
    const identifier id = platform_solaris;
    #else
    const identifier id = platform_unknown;
    #endif

    #if   defined ( __WXGTK__ )
    const bool gtk = true;
    #else
    const bool gtk = false;
    #endif

    #if   defined ( __WXMAC__ )
    const bool carbon = true;
    #else
    const bool carbon = false;
    #endif

    #if   defined ( __WXCOCOA__ )
    const bool cocoa = true;
    #else
    const bool cocoa = false;
    #endif

	#if defined ( linux )
		#undef linux
	#endif

	#if defined ( unix )
		#undef unix
	#endif

    const bool windows = (id == platform_windows);
    const bool macosx  = (id == platform_macosx);
    const bool linux   = (id == platform_linux);
    const bool freebsd = (id == platform_freebsd);
    const bool netbsd  = (id == platform_netbsd);
    const bool openbsd = (id == platform_openbsd);
    const bool darwin  = (id == platform_darwin);
    const bool solaris = (id == platform_solaris);
    const bool unix    = (linux | freebsd | netbsd | openbsd | darwin | solaris);

    const int bits = 8*sizeof(void*);
};

#endif /* PREP_H */
