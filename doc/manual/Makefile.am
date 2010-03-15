docudir = $(docdir)/manual
docu_DATA = manual.pdf

EXTRA_DIST = manual.pdf

if MACAPPBUNDLE
mac-copy-resources: $(docu_DATA)
	cp manual.pdf $(top_builddir)/wxMUN.app/Contents/SharedSupport
endif
