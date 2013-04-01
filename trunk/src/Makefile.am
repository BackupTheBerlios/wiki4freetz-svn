NULL = 

AM_CPPFLAGS = \
	$(GENIEWIKI_CFLAGS) \
	-include $(CONFIG_HEADER) \
	$(NULL)

bin_PROGRAMS = geniewiki 

BUILT_SOURCES = geniewiki.vala.stamp

geniewiki_VALASOURCES = \
	wiki.gs \
	wikifile.gs \
	wikihandler.gs \
	wikitext.gs \
	$(NULL)

geniewiki_SOURCES = \
	$(geniewiki_VALASOURCES:.gs=.c) \
	$(NULL)

#geniewiki_VALAFLAGS = --pkg gio-2.0

geniewiki.vala.stamp: $(geniewiki_VALASOURCES)
	$(VALAC) $(geniewiki_VALAFLAGS) -C $^
	touch $@

geniewiki_LDADD = \
	$(GENIEWIKI_LIBS) \
	$(NULL)

EXTRA_DIST = \
	$(geniewiki_VALASOURCES) \
	geniewiki.vala.stamp \
	$(NULL)

DISTCLEANFILES = \
	$(NULL)

