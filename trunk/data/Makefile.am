SUBDIRS = flags

datadir = $(pkgdatadir)/data

data_DATA = correct_committee.xml\
		correct_sc.xml\
		countries.xml\
		kabouter.xml\
		RIMUN.xml\
		sc.xml

if MACAPPBUNDLE
mac-copy-resources: $(data_DATA)
#        cp MacInfo.plist $(top_builddir)/FileZilla.app/Contents/Info.plist
#        cp $(srcdir)/FileZilla.icns $(top_builddir)/FileZilla.app/Contents/Resources/FileZilla.icns
#
#        for i in $(dist_resources_DATA); \
#                do cp -f "$(srcdir)/$$i" "$(top_builddir)/FileZilla.app/Contents/SharedSupport/resources"; \
#        done
#        mkdir -p "$(top_builddir)/FileZilla.app/Contents/SharedSupport/resources/48x48"
#        for i in $(dist_resources48_DATA); \
#                do cp -f "$(srcdir)/$$i" "$(top_builddir)/FileZilla.app/Contents/SharedSupport/resources/48x48"; \
#        done
#
#       # make in selected subdirs (i.e., flags for us)
#        $(MAKE) -C 16x16 mac-copy-resources
#        $(MAKE) -C 32x32 mac-copy-resources
#        $(MAKE) -C cyril mac-copy-resources
#        $(MAKE) -C blukis mac-copy-resources
#        $(MAKE) -C lone mac-copy-resources
#        $(MAKE) -C opencrystal mac-copy-resources
endif
