imagesdir = $(pkgdatadir)/images

images_DATA = logo.png\
		clear.png\
		splash.png\
		wxMUNlogo.png\
		wxMUNlogo_medium.png\
		wxMUNlogo_small.png

EXTRA_DIST = $(images_DATA) wxMUNsplash.svg wxMUNlogo.svg wxMUNlogo_horizontal.svg

if MACAPPBUNDLE
mac-copy-resources: $(images_DATA)
        mkdir -p $(top_builddir)/wxMUN.app/Contents/Resources/share/wxmun/images
	cp wxMUNicon.icns $(top_builddir)/wxMUN.app/Contents/Resources/wxMUN.icns

        for i in $(images_DATA); \
                do cp -f $(srcdir)/$$i $(top_builddir)/wxMUN.app/Contents/Resources/share/wxmun/images; \
        done
endif
