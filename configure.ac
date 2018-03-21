AC_PREREQ([2.69])
AC_INIT([cp3], [0.1.0], [christian@parpart.family], [], [https://github.com/christianparpart/cp3])
dnl AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([configure.ac])
dnl AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([foreign subdir-objects serial-tests])
AM_MAINTAINER_MODE([enable])
AM_SILENT_RULES([yes])

AC_LANG_CPLUSPLUS
AC_PROG_RANLIB
AC_PROG_CC
#AC_PROG_CC_FOR_BUILD
AC_PROG_CXX
#AC_PROG_CXX_FOR_BUILD
#AC_PROC_LIBTOOL
AM_PROG_AR
AM_PROG_AS
#LT_INIT
PKG_PROG_PKG_CONFIG([0.25])

uname_system=`uname -s`
AC_MSG_NOTICE("Operating system: $uname_system")
AM_CONDITIONAL([PLATFORM_DARWIN], [test x$uname_system = xDarwin])
AM_CONDITIONAL([PLATFORM_LINUX], [test x$uname_system = xLinux])
AM_CONDITIONAL([PLATFORM_WSL], [uname -r | grep -q Microsoft])

AC_HEADER_STDC

AC_CHECK_HEADERS([sys/sendfile.h])
AC_CHECK_HEADERS([sys/resource.h])
AC_CHECK_HEADERS([sys/inotify.h])
AC_CHECK_HEADERS([sys/limits.h])
AC_CHECK_HEADERS([sys/mman.h])
AC_CHECK_HEADERS([sys/utsname.h])
AC_CHECK_HEADERS([security/pam_appl.h])
AC_CHECK_HEADERS([bzlib.h])
AC_CHECK_HEADERS([dlfcn.h])
AC_CHECK_HEADERS([execinfo.h])
AC_CHECK_HEADERS([netdb.h])
AC_CHECK_HEADERS([pwd.h])
AC_CHECK_HEADERS([pthread.h])
AC_CHECK_HEADERS([signal.h])
AC_CHECK_HEADERS([syslog.h])
AC_CHECK_HEADERS([unistd.h])
AC_CHECK_HEADERS([zlib.h])

AC_CHECK_DECLS([pthread_getname_np], [], [], [[#include <pthread.h>]])
AC_CHECK_DECLS([pthread_setname_np], [], [], [[#include <pthread.h>]])
AC_CHECK_DECLS([pthread_setaffinity_np], [], [], [[#include <pthread.h>]])

AC_CHECK_FUNCS([inotify_init1])
AC_CHECK_FUNCS([chroot])
AC_CHECK_FUNCS([pathconf])
AC_CHECK_FUNCS([sendfile])
AC_CHECK_FUNCS([posix_fadvise])
AC_CHECK_FUNCS([readahead])
AC_CHECK_FUNCS([pread])
AC_CHECK_FUNCS([nanosleep])
AC_CHECK_FUNCS([daemon])
AC_CHECK_FUNCS([sysconf])
AC_CHECK_FUNCS([pipe2])
AC_CHECK_FUNCS([dup2])
AC_CHECK_FUNCS([fork])
AC_CHECK_FUNCS([backtrace])
AC_CHECK_FUNCS([clock_gettime])
AC_CHECK_FUNCS([mkostemps])
AC_CHECK_FUNCS([backtrace])

####### OUTPUT ################################################################

AC_CONFIG_HEADERS(sysconfig.h)
AC_CONFIG_FILES(Makefile)
AC_OUTPUT
