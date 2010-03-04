INCLUDES = -I.. -I../include

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

wxmun_LDADD = @LIBS@
wxmun_CXXFLAGS = @CXXFLAGS@ 

if MACAPPBUNDLE
noinst_DATA = $(top_builddir)/wxMUN.app/Contents/MacOS/wxmun$(EXEEXT)
endif

$(top_builddir)/wxMUN.app/Contents/MacOS/wxmun$(EXEEXT): wxmun
        mkdir -p $(top_builddir)/wxMUN.app/Contents/MacOS
        mkdir -p $(top_builddir)/wxMUN.app/Contents/SharedSupport/resources
        mkdir -p $(top_builddir)/wxMUN.app/Contents/Resources
        $(MAKE) -C ../data/resources mac-copy-resources
        $(MAKE) -C ../images/resources mac-copy-resources
        cp -f wxmun $(top_builddir)/wxMUN.app/Contents/MacOS/wxmun
