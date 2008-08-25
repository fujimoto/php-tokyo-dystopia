PHP_ARG_ENABLE(tokyo_dystopia, whether to enable tokyo dystopia support,
[  --enable-tokyo-dystopia    enable tokyo dystopia support])

if test -z "$PHP_TOKYO_DYSTOPIA_DIR"; then
PHP_ARG_WITH(tokyo-dystopia-dir, for the location of tokyo dystopia,
[  --with-tokyo-dystopia-dir[=DIR]   Set the path to tokyo dystopia install prefix.], no, no)
fi

if test "$PHP_TOKYO_DYSTOPIA" = "yes"; then
  if test "$PHP_TOKYO_DYSTOPIA_DIR" != "no" && test "$PHP_TOKYO_DYSTOPIA_DIR" != "yes"; then
    if test -f "$PHP_TOKYO_DYSTOPIA_DIR/include/dystopia.h"; then
      PHP_TOKYO_DYSTOPIA_DIR="$PHP_TOKYO_DYSTOPIA_DIR"
      PHP_TOKYO_DYSTOPIA_INCDIR="$PHP_TOKYO_DYSTOPIA_DIR/include"
    else
      AC_MSG_ERROR([Can't find tokyo dystopia headers under "$PHP_TOKYO_DYSTOPIA_DIR"])
    fi
  else
    for i in /usr/local /usr; do
      if test -f "$i/include/dystopia.h"; then
        PHP_TOKYO_DYSTOPIA_DIR="$i"
        PHP_TOKYO_DYSTOPIA_INCDIR="$i/include"
      fi
    done
  fi

  dnl # cairo
  AC_MSG_CHECKING([for the location of tokyo dystopia])
  if test "$PHP_TOKYO_DYSTOPIA_DIR" = "no"; then
    AC_MSG_ERROR([tokyo dystopia extension requires tokyo dystopia installation. Use --with-tokyo-dystopia-dir=<DIR> to specify prefix where tokyo dystopia include and library are located])
  else
    AC_MSG_RESULT([$PHP_TOKYO_DYSTOPIA_DIR])
    PHP_ADD_INCLUDE($PHP_TOKYO_DYSTOPIA_INCDIR)
  fi

  AC_DEFINE(HAVE_TOKYO_DYSTOPIA, 1, [Whether you have tokyo dystopia or not])
  PHP_ADD_LIBRARY_WITH_PATH(tokyodystopia, $PHP_TOKYO_DYSTOPIA_DIR/lib, TOKYO_DYSTOPIA_SHARED_LIBADD)
  PHP_NEW_EXTENSION(tokyo_dystopia, tokyo_dystopia.c, $ext_shared)
  PHP_SUBST(TOKYO_DYSTOPIA_SHARED_LIBADD)
fi
