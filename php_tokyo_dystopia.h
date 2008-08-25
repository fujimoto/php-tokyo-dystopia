/*
  +----------------------------------------------------------------------+
  | PHP Version 4                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2003 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.02 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available at through the world-wide-web at                           |
  | http://www.php.net/license/2_02.txt.                                 |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+

  $Id$
*/
#ifndef PHP_TOKYO_DYSTOPIA_H
#define PHP_TOKYO_DYSTOPIA_H

#define PHP_TOKYO_DYSTOPIA_VERSION "0.1.0"
#define PHP_TOKYO_DYSTOPIA_EXTNAME "tokyo_dystopia"

#ifdef PHP_WIN32
#define PHP_TOKYO_DYSTOPIA_API __declspec(dllexport)
#else
#define PHP_TOKYO_DYSTOPIA_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#define	TOKYO_DYSTOPIA_GET_THIS(ce)			(getThis() ? (Z_OBJCE_P(getThis()) == ce ? getThis() : NULL) : NULL)

PHP_MINIT_FUNCTION(tokyo_dystopia);
PHP_MSHUTDOWN_FUNCTION(tokyo_dystopia);
PHP_RINIT_FUNCTION(tokyo_dystopia);
PHP_RSHUTDOWN_FUNCTION(tokyo_dystopia);
PHP_MINFO_FUNCTION(tokyo_dystopia);

/* {{{ function prototype */
PHP_FUNCTION(tokyo_dystopia_core_ctor);
PHP_FUNCTION(tokyo_dystopia_core_open);
PHP_FUNCTION(tokyo_dystopia_core_close);
PHP_FUNCTION(tokyo_dystopia_core_tune);
PHP_FUNCTION(tokyo_dystopia_core_setcache);
PHP_FUNCTION(tokyo_dystopia_core_setfwmmax);
PHP_FUNCTION(tokyo_dystopia_core_get);
PHP_FUNCTION(tokyo_dystopia_core_put);
PHP_FUNCTION(tokyo_dystopia_core_out);
PHP_FUNCTION(tokyo_dystopia_core_search);
PHP_FUNCTION(tokyo_dystopia_core_iterinit);
PHP_FUNCTION(tokyo_dystopia_core_iternext);
PHP_FUNCTION(tokyo_dystopia_core_sync);
PHP_FUNCTION(tokyo_dystopia_core_optimize);
PHP_FUNCTION(tokyo_dystopia_core_vanish);
PHP_FUNCTION(tokyo_dystopia_core_copy);
PHP_FUNCTION(tokyo_dystopia_core_path);
PHP_FUNCTION(tokyo_dystopia_core_rnum);
PHP_FUNCTION(tokyo_dystopia_core_fsiz);
PHP_FUNCTION(tokyo_dystopia_core_ecode);
PHP_FUNCTION(tokyo_dystopia_core_errmsg);

PHP_FUNCTION(tokyo_dystopia_qgram_ctor);
PHP_FUNCTION(tokyo_dystopia_qgram_open);
PHP_FUNCTION(tokyo_dystopia_qgram_close);
PHP_FUNCTION(tokyo_dystopia_qgram_tune);
PHP_FUNCTION(tokyo_dystopia_qgram_setcache);
PHP_FUNCTION(tokyo_dystopia_qgram_setfwmmax);
PHP_FUNCTION(tokyo_dystopia_qgram_put);
PHP_FUNCTION(tokyo_dystopia_qgram_out);
PHP_FUNCTION(tokyo_dystopia_qgram_search);
PHP_FUNCTION(tokyo_dystopia_qgram_sync);
PHP_FUNCTION(tokyo_dystopia_qgram_optimize);
PHP_FUNCTION(tokyo_dystopia_qgram_vanish);
PHP_FUNCTION(tokyo_dystopia_qgram_copy);
PHP_FUNCTION(tokyo_dystopia_qgram_path);
PHP_FUNCTION(tokyo_dystopia_qgram_rnum);
PHP_FUNCTION(tokyo_dystopia_qgram_fsiz);
PHP_FUNCTION(tokyo_dystopia_qgram_ecode);
PHP_FUNCTION(tokyo_dystopia_qgram_errmsg);

PHP_FUNCTION(tokyo_dystopia_simple_ctor);
PHP_FUNCTION(tokyo_dystopia_simple_open);
PHP_FUNCTION(tokyo_dystopia_simple_close);
PHP_FUNCTION(tokyo_dystopia_simple_tune);
PHP_FUNCTION(tokyo_dystopia_simple_setcache);
PHP_FUNCTION(tokyo_dystopia_simple_setfwmmax);
PHP_FUNCTION(tokyo_dystopia_simple_get);
PHP_FUNCTION(tokyo_dystopia_simple_put);
PHP_FUNCTION(tokyo_dystopia_simple_out);
PHP_FUNCTION(tokyo_dystopia_simple_search);
PHP_FUNCTION(tokyo_dystopia_simple_iterinit);
PHP_FUNCTION(tokyo_dystopia_simple_iternext);
PHP_FUNCTION(tokyo_dystopia_simple_sync);
PHP_FUNCTION(tokyo_dystopia_simple_optimize);
PHP_FUNCTION(tokyo_dystopia_simple_vanish);
PHP_FUNCTION(tokyo_dystopia_simple_copy);
PHP_FUNCTION(tokyo_dystopia_simple_path);
PHP_FUNCTION(tokyo_dystopia_simple_rnum);
PHP_FUNCTION(tokyo_dystopia_simple_fsiz);
PHP_FUNCTION(tokyo_dystopia_simple_ecode);
PHP_FUNCTION(tokyo_dystopia_simple_errmsg);

PHP_FUNCTION(tokyo_dystopia_word_ctor);
PHP_FUNCTION(tokyo_dystopia_word_open);
PHP_FUNCTION(tokyo_dystopia_word_close);
PHP_FUNCTION(tokyo_dystopia_word_tune);
PHP_FUNCTION(tokyo_dystopia_word_setcache);
PHP_FUNCTION(tokyo_dystopia_word_setfwmmax);
PHP_FUNCTION(tokyo_dystopia_word_put);
PHP_FUNCTION(tokyo_dystopia_word_out);
PHP_FUNCTION(tokyo_dystopia_word_search);
PHP_FUNCTION(tokyo_dystopia_word_sync);
PHP_FUNCTION(tokyo_dystopia_word_optimize);
PHP_FUNCTION(tokyo_dystopia_word_vanish);
PHP_FUNCTION(tokyo_dystopia_word_copy);
PHP_FUNCTION(tokyo_dystopia_word_path);
PHP_FUNCTION(tokyo_dystopia_word_rnum);
PHP_FUNCTION(tokyo_dystopia_word_fsiz);
PHP_FUNCTION(tokyo_dystopia_word_ecode);
PHP_FUNCTION(tokyo_dystopia_word_errmsg);
/* }}} */

extern zend_module_entry tokyo_dystopia_module_entry;
#define phpext_tokyo_dystopia_ptr &tokyo_dystopia_module_entry

/* {{{ module global */
ZEND_BEGIN_MODULE_GLOBALS(tokyo_dystopia)
ZEND_END_MODULE_GLOBALS(tokyo_dystopia)

#ifdef ZTS
#define TOKYO_DYSTOPIA_G(v) TSRMG(tokyo_dystopia_globals_id, zend_tokyo_dystopia_globals *, v)
#else
#define TOKYO_DYSTOPIA_G(v) (tokyo_dystopia_globals.v)
#endif

ZEND_EXTERN_MODULE_GLOBALS(tokyo_dystopia)
/* }}} */

/* {{{ macro */
#define	tokyo_dystopia_objprop_get(zv, key, element, on_error) { \
	if (zend_hash_find(Z_OBJPROP(zv), key, strlen(key)+1, (void**)&element) != SUCCESS) { \
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "property [%s] is not set", key); \
		element = NULL; \
		on_error; \
	} \
}
#define tokyo_dystopia_objprop_get_p(zv_p, key, element, on_error)	tokyo_dystopia_objprop_get(*zv_p, key, element, on_error)
#define tokyo_dystopia_objprop_get_pp(zv_pp, key, element, on_error)	tokyo_dystopia_objprop_get(**zv_pp, key, element, on_error)

#define	tokyo_dystopia_objprop_is_false(element) 	(Z_TYPE_PP(element) == IS_BOOL && Z_BVAL_PP(element) == 0)
/* }}} */

/* {{{ inline */
static inline int tokyo_dystopia_objprop_get_long_p(zval *zv_p, char *key) {
	zval **element;
	tokyo_dystopia_objprop_get_p(zv_p, key, element, return 0);
	convert_to_long_ex(element);
	return Z_LVAL_PP(element);
}

static inline int tokyo_dystopia_array_get_long_p(zval *zv_p, char *key) {
	zval **element;
	if (zend_hash_find(Z_ARRVAL_P(zv_p), key, strlen(key)+1, (void**)&element) == SUCCESS) {
		convert_to_long_ex(element);
		return Z_LVAL_PP(element);
	}
	return 0;
}
/* }}} */
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
