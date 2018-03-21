# This file is part of the "x0" project, http://github.com/christianparpart/x0>
#   (c) 2009-2017 Christian Parpart <christian@parpart.family>
#
# Licensed under the MIT License (the "License"); you may not use this
# file except in compliance with the License. You may obtain a copy of
# the License at: http://opensource.org/licenses/MIT

EXTRA_DIST = autogen.sh
bin_PROGRAMS =
lib_LIBRARIES =
noinst_LIBRARIES =
check_PROGRAMS =
TESTS =

####### cp3 ###################################################################

bin_PROGRAMS += cp3

cp3_CXXFLAGS = \
	-std=c++17 \
	$(AM_CXXFLAGS) \
	-I$(top_srcdir)

cp3_LDADD = \
	$(AM_LDFLAGS)

# cp3_LDFLAGS += -static -static-libgcc -static-libstdc++

cp3_SOURCES = \
	main.cc

####### man ###################################################################

man_MANS = cp3.8

man: cp3.8

cp3.8: cp3.8.pod
	pod2man --name=cp3 --section 8 --release --utf8 --stderr --utf8 \
		--center "cp3 - C++ interpreter" \
		$< >$@

# vim:ts=8
# EOF
