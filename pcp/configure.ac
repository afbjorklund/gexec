dnl
dnl Copyright goes here.
dnl
AC_INIT(pcp.c)

dnl
dnl Sets PACKAGE and VERSION defines
dnl
AM_INIT_AUTOMAKE(gexec-pcp,0.3.6)

dnl
dnl Creates config.h file with #defines instead of passing to compiler.
dnl
AM_CONFIG_HEADER(config.h)

dnl
dnl Change default installation prefix
dnl
AC_PREFIX_DEFAULT(/usr/local)

dnl
dnl Checks for programs.
dnl
AC_PROG_AWK
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_LIBTOOL

dnl
dnl Optional modules
dnl 

dnl
dnl Configurable parameters
dnl

dnl
dnl Checks for libraries.
dnl
AC_CHECK_LIB([e -lpthread], barrier_create,[],[AC_MSG_ERROR(libauth not found)])
AC_CHECK_LIB([auth -le -lssl -lcrypto], auth_init_credentials,[],[AC_MSG_ERROR(libauth not found)])
AC_CHECK_LIB(pthread, pthread_create,[],[AC_MSG_ERROR(pthread_create failed)])
AC_CHECK_LIB(ssl, RSA_free,[],[AC_MSG_ERROR(libssl: RSA_free not found)])

dnl
dnl Checks for header files.
dnl
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS(fcntl.h unistd.h)

dnl
dnl Checks for typedefs, structures, and compiler characteristics.
dnl
AC_C_CONST
AC_TYPE_UID_T
AC_HEADER_TIME

dnl
dnl Checks for library functions.
dnl
AC_TYPE_SIGNAL
AC_CHECK_FUNCS(select)

dnl
dnl Generate Makefiles (and other files) with substitutions.
dnl
AC_OUTPUT(Makefile     \
          config/gexec-pcpd  \
          gexec-pcp.spec)

