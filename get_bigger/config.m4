dnl $Id$
dnl config.m4 for extension get_bigger

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(get_bigger, for get_bigger support,
dnl Make sure that the comment is aligned:
[  --with-get_bigger             Include get_bigger support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(get_bigger, whether to enable get_bigger support,
dnl Make sure that the comment is aligned:
dnl [  --enable-get_bigger           Enable get_bigger support])

if test "$PHP_GET_BIGGER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-get_bigger -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/get_bigger.h"  # you most likely want to change this
  dnl if test -r $PHP_GET_BIGGER/$SEARCH_FOR; then # path given as parameter
  dnl   GET_BIGGER_DIR=$PHP_GET_BIGGER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for get_bigger files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       GET_BIGGER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$GET_BIGGER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the get_bigger distribution])
  dnl fi

  dnl # --with-get_bigger -> add include path
  dnl PHP_ADD_INCLUDE($GET_BIGGER_DIR/include)

  dnl # --with-get_bigger -> check for lib and symbol presence
  dnl LIBNAME=get_bigger # you may want to change this
  dnl LIBSYMBOL=get_bigger # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $GET_BIGGER_DIR/lib, GET_BIGGER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_GET_BIGGERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong get_bigger lib version or lib not found])
  dnl ],[
  dnl   -L$GET_BIGGER_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(GET_BIGGER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(get_bigger, get_bigger.c, $ext_shared)
fi
