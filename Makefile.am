AUTOMAKE_OPTIONS = foreign 1.7 dist-bzip2

SUBDIRS = src include data images m4
DIST_SUBDIRS = MSVC src include data images
EXTRA_DIST = autogen.sh mkinstalldirs

# Copy all the spec files. Of course, only one is actually used.
dist-hook:
	for specfile in *.spec; do \
		if test -f $$specfile; then \
			cp -p $$specfile $(distdir); \
		fi \
	done

sparse-check:
	$(MAKE) -C src $@
