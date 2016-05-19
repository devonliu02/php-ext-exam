dnl $Id$
dnl config.m4 for extension get_ini

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(get_ini, for get_ini support,
dnl Make sure that the comment is aligned:
[  --with-get_ini             Include get_ini support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(get_ini, whether to enable get_ini support,
dnl Make sure that the comment is aligned:
dnl [  --enable-get_ini           Enable get_ini support])

if test "$PHP_GET_INI" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-get_ini -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/get_ini.h"  # you most likely want to change this
  dnl if test -r $PHP_GET_INI/$SEARCH_FOR; then # path given as parameter
  dnl   GET_INI_DIR=$PHP_GET_INI
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for get_ini files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       GET_INI_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$GET_INI_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the get_ini distribution])
  dnl fi

  dnl # --with-get_ini -> add include path
  dnl PHP_ADD_INCLUDE($GET_INI_DIR/include)

  dnl # --with-get_ini -> check for lib and symbol presence
  dnl LIBNAME=get_ini # you may want to change this
  dnl LIBSYMBOL=get_ini # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $GET_INI_DIR/lib, GET_INI_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_GET_INILIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong get_ini lib version or lib not found])
  dnl ],[
  dnl   -L$GET_INI_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(GET_INI_SHARED_LIBADD)

  PHP_NEW_EXTENSION(get_ini, get_ini.c, $ext_shared)
fi
