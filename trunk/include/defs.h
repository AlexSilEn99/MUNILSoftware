/*
 * Copyright (c) 2008-2009 Geert-Jan Besjes 
 *
 * See COPYING for the status of this software. 
 */

#ifndef DEFS_H
#define DEFS_H

#ifndef VERSION
 #define VERSION "0.27"
#endif

#ifndef PACKAGE_NAME
 #define PACKAGE_NAME "wxMUN"
#endif

#define DARK_RED (wxColour(187, 14, 14))
#define DARK_GREEN (wxColour(00, 79 , 00))

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
