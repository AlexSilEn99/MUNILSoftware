## Process this file with automake to produce Makefile.in

noinst_HEADERS = clear_png.h \
			committee.h \
			configmanager.h \
			confirmtopicswapdialog.h \
			countriespresentdialog.h \
			country.h \
			defs.h \
			editcommitteedialog.h \
			app.h \
			newcommitteedialog.h \
			noname.h \
			prep.h \
			rollcallvote.h\
			session.h \
			unl_logo.h \
			votingpanel.h \
			wxmunframe.h\
			wxmunaboutdialog.h \
			yielddialog.h

BUILT_SOURCES = version.h

version.h: version.h.SH
	$(SHELL) version.h.SH

clean:
	rm version.h

EXTRA_DIST = $(noinst_HEADERS) version.h.SH

dist-hook:
	rm -rf version.h

