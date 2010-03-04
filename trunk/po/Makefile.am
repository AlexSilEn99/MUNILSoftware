CLEANFILES = *.po.new *.mo wxmun.pot wxmun.pot.new wxmun.pot~

dist_noinst_DATA = wxmun.pot @WXMUN_LINGUAS_PO@ 

install-data-local: install-wxmun-catalogs

install-wxmun-catalogs: allmo
	for i in @WXMUN_LINGUAS@ ; do \
	  $(mkinstalldirs) $(DESTDIR)$(localedir)/$$i/LC_MESSAGES ; \
	  $(INSTALL_DATA) $$i.mo $(DESTDIR)$(localedir)/$$i/LC_MESSAGES/wxmun.mo ; \
	done

uninstall-local:
	for i in @WXMUN_LINGUAS@ ; do \
	  rm $(DESTDIR)$(localedir)/$$i/LC_MESSAGES/wxmun.mo ; \
	done


# Unused code
#WXWIN_LINGUAS  =    de

#install-wxstd-catalogs:
#	for i in $(WXWIN_LINGUAS) ; do \
#	  $(mkinstalldirs) $(DESTDIR)$(localedir)/$$i ; \
#	  $(INSTALL_DATA) wxwin/$$i.mo $(DESTDIR)$(localedir)/$$i/wxmun-wxstd.mo ; \
#	done



# ----------------------------------------------------------------------------
# Logic for catalogs updating follows
# Try to not modify catalog files if nothing has changed
# But touch them to make sure the timestamps are correct
# so that the uptodate checks are only made if neccessary.
# ----------------------------------------------------------------------------

# the programs we use (TODO: use configure to detect them)
MSGFMT=@msgfmt@ -c --verbose
MSGMERGE=@msgmerge@
XGETTEXT=@xgettext@

# common xgettext args: C++ syntax, use the specified macro names as markers
XGETTEXT_ARGS=-C -k_ -kwxGetTranslation -kwxTRANSLATE -kwxPLURAL:1,2 -s -j

# implicit rules
%.mo: %.po.new
	$(MSGFMT) -o $@ $< || exit 1

# a PO file must be updated from wxstd.po to include new translations
%.po.new: $(srcdir)/%.po wxmun.pot
	file=$@; \
	cat $(srcdir)/$${file%.po.new}.po > $@
	if [ ! -f $@ ]; then \
	  exit 1; \
	fi
	$(MSGMERGE) $@ wxmun.pot -o $@~ || exit 1
	@mv $@~ $@

# touch file so that timestamp is newer than that of wxmun.pot
	@touch $@;

wxmun.pot: $(srcdir)/src/*.cpp $(srcdir)/include/*.h  
	@rm -f $@.new
	@touch $@.new

	FILES="`find $(srcdir)/../src -name '*.h' -o -name '*.cpp'`"; \
	$(XGETTEXT) $(XGETTEXT_ARGS) -o $@.new $$FILES || exit 1

# change charset declaration in template file to UTF-8
	cat $@.new | sed -e "s/^\"Content-Type: .*$$/\"Content-Type: text\\/plain; charset=UTF-8\\\\n\"/" > $@.new~
	@mv $@.new~ $@.new  

	if [ -f $@ ]; then \
	  touch $@; \
	  $(MSGMERGE) -U $@ $@.new || exit 1; \
	else \
	  mv $@.new $@; \
	fi;

	@if [ -f $@.pot~ ]; then rm $@~; fi
	@if [ -f $@.new ]; then rm $@.new; fi

allpo: @WXMUN_LINGUAS_PO_NEW@

# this target which will not be called automatically will update the .po files
updatepo: @WXMUN_LINGUAS_PO_NEW@
	for t in @WXMUN_LINGUAS@; do \
          cp $$t.po.new $(srcdir)/$$t.po || exit 1; \
        done

allmo: @WXMUN_LINGUAS_MO@

# on the Mac copy the .mo files into the application bundle
if MACAPPBUNDLE

noinst_DATA = $(top_builddir)/wxMUN.app/Contents/SharedSupport/locales

$(top_builddir)/wxMUN.app/Contents/SharedSupport/locales: allmo
	mkdir -p $(top_builddir)/wxMUN.app/Contents/SharedSupport/locales
	for i in @WXMUN_LINGUAS@ ; do \
	  mkdir -p $(top_builddir)/wxMUN.app/Contents/Resources/$$i.lproj; \
	  mkdir -p $(top_builddir)/wxMUN.app/Contents/SharedSupport/locales/$$i; \
	  cp -f $$i.mo $(top_builddir)/wxMUN.app/Contents/SharedSupport/locales/$$i/wxmun.mo; \
	done
	mkdir -p $(top_builddir)/wxMUN.app/Contents/Resources/en.lproj

endif

all: allmo

.PHONY: allpo allmo force-update FORCE
