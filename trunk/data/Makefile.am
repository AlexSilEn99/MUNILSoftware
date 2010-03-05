SUBDIRS = flags

wxmundatadir = $(pkgdatadir)/data

dist_wxmundata_DATA = correct_committee.xml\
		correct_sc.xml\
		countries.xml\
		kabouter.xml\
		RIMUN.xml\
		sc.xml

if MACAPPBUNDLE
mac-copy-resources: $(data_DATA)
	cp ../MacInfo.plist $(top_builddir)/wxMUN.app/Contents/Info.plist
	mkdir -p $(top_builddir)/wxMUN.app/Contents/Resources/share/wxmun/data

	for i in $(dist_wxmundata_DATA); \
		do cp -f "$(srcdir)/$$i" "$(top_builddir)/wxMUN.app/Contents/Resources/share/wxmun/data"; \
	done

	$(MAKE) -C flags mac-copy-resources
endif
