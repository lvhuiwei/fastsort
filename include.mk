CC = mpicc

AM_CPPFLAGS = $(DEPS_CFLAGS)
AM_CPPFLAGS += -I../src

#== Debugging flags ==
# AM_CPPFLAGS += -DNDEBUG
#AM_CPPFLAGS += -DDEBUG
#AM_CPPFLAGS += -g -rdynamic -lSegFault -Werror
AM_CPPFLAGS += -O3

#== Configuration flags ==
#AM_CPPFLAGS += -DCONFIG_FOO

#== Profiling flags ==
#AM_CPPFLAGS += -DPROFILING_ALLTOALL
