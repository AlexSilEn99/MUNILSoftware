ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = foreign 1.7 dist-bzip2

if !LOCALES_ONLY
MAYBE_DIRS = include src data doc
endif

if LOCALES
MAYBE_LOCALES = po
endif

SUBDIRS = $(MAYBE_DIRS) $(MAYBE_LOCALES)

EXTRA_SUBDIRS = m4
DIST_SUBDIRS = $(SUBDIRS) $(EXTRA_SUBDIRS)
EXTRA_DIST = autogen.sh GPL.html

if !LOCALES_ONLY
if MACAPPBUNDLE
clean-local:
	rm -rf wxMUN.app
endif
endif

# Copy all the spec files. Of course, only one is actually used.
dist-hook:
	for specfile in *.spec; do \
		if test -f $$specfile; then \
			cp -p $$specfile $(distdir); \
		fi \
	done

sparse-check:
	$(MAKE) -C src $@
