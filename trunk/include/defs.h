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

#ifndef DEFS_H
#define DEFS_H

#ifndef VERSION
 #define VERSION "0.38"
#endif

#ifndef PACKAGE_NAME
 #define PACKAGE_NAME "wxMUN"
#endif

#define DARK_RED (wxColour(187, 14, 14))
#define DARK_GREEN (wxColour(00, 79 , 00))

#define LICENSE_GPL wxT("Copyright (c) 2008-2009 Geert-Jan Besjes\n\nThis program is free software: you can redistribute it and/or modify "\
	"it under the terms of the GNU General Public License as published by "\
	"the Free Software Foundation, either version 3 of the License, or "\
	"(at your option) any later version.\n\n"\
	""\
	"This program is distributed in the hope that it will be useful, "\
	"but WITHOUT ANY WARRANTY; without even the implied warranty of "\
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the "\
	"GNU General Public License for more details.\n\n"\
	""\
	"You should have received a copy of the GNU General Public License "\
	"along with this program.  If not, see <http://www.gnu.org/licenses/>. ")

#define LICENSE_MIT wxT("Copyright (c) 2008-2009 Geert-Jan Besjes\n\nPermission is hereby granted, free of charge, to any person " \
"obtaining a copy of this software and associated documentation " \
"files (the \"Software\"), to deal in the Software without " \
"restriction, including without limitation the rights to use, " \
"copy, modify, merge, publish, distribute, sublicense, and/or sell " \
"copies of the Software, and to permit persons to whom the " \
"Software is furnished to do so, subject to the following " \
"conditions:" \
"\n\n" \
"The above copyright notice and this permission notice shall be " \
"included in all copies or substantial portions of the Software. " \
"\n\n" \
"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, " \
"EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES " \
"OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND " \
"NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT " \
"HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, " \
"WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING " \
"FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR " \
"OTHER DEALINGS IN THE SOFTWARE.")

#define COMMITTEE_XML_HEADER "<!DOCTYPE committee [\n \
  <!ELEMENT committee (name, countries, GSLtime?, topics) >\n \
  <!ELEMENT name (#PCDATA) >\n \
  <!ELEMENT countries (country+) >\n \
  <!ELEMENT country (countryname,code?,observer?) >\n \
  <!ELEMENT countryname (#PCDATA) >\n \
  <!ELEMENT code (#PCDATA) >\n \
  <!ELEMENT observer (#PCDATA) >\n \
  <!ELEMENT GSLtime (#PCDATA) >\n \
  <!ELEMENT topics (topic+) >\n \
  <!ELEMENT topic (topicname) >\n \
  <!ELEMENT topicname (#PCDATA) >\n \
]>"

#define DEFAULT_WINDOW_TITLE wxT("wxMUN")

#endif
