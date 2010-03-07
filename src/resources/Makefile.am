SUBDIRS = 16x16 32x32 flags

resourcesdir = $(pkgdatadir)/resources

dist_resources_DATA = countries.xml

resources48dir = $(pkgdatadir)/resources/48x48
dist_resources48_DATA = 48x48/wxmun.png

if USE_RESOURCEFILE
nodist_noinst_DATA = wxmun.o

wxmun.o: $(srcdir)/wxmun.rc version.rc
	@if [ -f $@~ ]; then rm $@~; fi
	@WINDRES@ --include-dir=. --include-dir=$(srcdir) $(WINDRESFLAGS) $(srcdir)/wxmun.rc -D GNU_WINDRES -D HAS_VERSIONRC $@~ || rm $@~
	@if [ -f $@ ]; then rm $@; fi
	mv $@~ $@
endif

dist_noinst_DATA = wxmun.rc wxMUN.ico \
                wxMUN.icns MacInfo.plist.in \
                version.rc.in 

if MACAPPBUNDLE
mac-copy-resources: $(dist_resources_DATA)
	cp MacInfo.plist $(top_builddir)/wxMUN.app/Contents/Info.plist
	cp $(srcdir)/FileZilla.icns $(top_builddir)/wxMUN.app/Contents/Resources/wxMUN.icns

	for i in $(dist_resources_DATA); \
		do cp -f "$(srcdir)/$$i" "$(top_builddir)/wxMUN.app/Contents/SharedSupport/resources"; \
	done
	
	mkdir -p "$(top_builddir)/FileZilla.app/Contents/SharedSupport/resources/48x48"
	for i in $(dist_resources48_DATA); \
		do cp -f "$(srcdir)/$$i" "$(top_builddir)/wxMUN.app/Contents/SharedSupport/resources/48x48"; \
	done

	$(MAKE) -C 16x16 mac-copy-resources
	$(MAKE) -C 32x32 mac-copy-resources
	$(MAKE) -C flags mac-copy-resources
endif

pixmapsdir = $(datadir)/pixmaps
pixmaps_DATA = 48x48/wxmun.png

hicolorapps16dir = $(datadir)/icons/hicolor/16x16/apps
hicolorapps16_DATA = 16x16/wxmun.png
hicolorapps32dir = $(datadir)/icons/hicolor/32x32/apps
hicolorapps32_DATA = 32x32/wxmun.png
hicolorapps48dir = $(datadir)/icons/hicolor/48x48/apps
hicolorapps48_DATA = 48x48/wxmun.png
