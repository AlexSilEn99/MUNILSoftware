INCLUDES = -I.. -I../include

SUBDIRS = resources

EXTRA_DIST = gui.h

bin_PROGRAMS = wxmun
wxmun_SOURCES = committee.cpp \
		configmanager.cpp \
		confirmtopicswapdialog.cpp \
		countriespresentdialog.cpp \
		country.cpp \
		editcommitteedialog.cpp \
		gui.cpp \
		main.cpp \
		newcommitteedialog.cpp \
		noname.cpp \
		rollcallvote.cpp\
		session.cpp \
		wxmunframe.cpp\
		wxmunaboutdialog.cpp\
		yielddialog.cpp

# wxmun_LDADD = @LIBS@
wxmun_CFLAGS = $(WX_CFLAGS_ONLY)
wxmun_CXXFLAGS = $(WX_CXXFLAGS_ONLY) 
wxmun_CPPFLAGS = $(WX_CPPFLAGS) $(XERCES_CPPFLAGS)
wxmun_LDFLAGS = $(XERCES_LDFLAGS)
wxmun_LDADD = $(WX_LIBS) $(XERCES_LIBS)

if MACAPPBUNDLE
noinst_DATA = $(top_builddir)/wxMUN.app/Contents/MacOS/wxmun$(EXEEXT)
endif

$(top_builddir)/wxMUN.app/Contents/MacOS/wxmun$(EXEEXT): wxmun
	mkdir -p $(top_builddir)/wxMUN.app/Contents/MacOS
	mkdir -p $(top_builddir)/wxMUN.app/Contents/SharedSupport/resources
	mkdir -p $(top_builddir)/wxMUN.app/Contents/Resources
	$(MAKE) -C resources mac-copy-resources
	strip wxmun
	cp -f wxmun $(top_builddir)/wxMUN.app/Contents/MacOS/wxmun
