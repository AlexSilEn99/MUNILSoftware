docudir = $(docdir)
docu_DATA = manual/manual.pdf

EXTRA_DIST = manual/manual.pdf

if MACAPPBUNDLE
mac-copy-resources: $(docu_DATA)
	cp manual/manual.pdf $(top_builddir)/wxMUN.app/Contents/SharedSupport
endif
