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
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_tokyo_dystopia.h"
#include "dystopia.h"
#include "tcqdb.h"
#include "laputa.h"
#include "tcwdb.h"

ZEND_DECLARE_MODULE_GLOBALS(tokyo_dystopia)

/* {{{ tokyo_dystopia_functions[] */
static function_entry tokyo_dystopia_functions[] = {
	PHP_FE(tokyo_dystopia_core_ctor, NULL)
	PHP_FE(tokyo_dystopia_core_open, NULL)
	PHP_FE(tokyo_dystopia_core_close, NULL)
	PHP_FE(tokyo_dystopia_core_tune, NULL)
	PHP_FE(tokyo_dystopia_core_setcache, NULL)
	PHP_FE(tokyo_dystopia_core_setfwmmax, NULL)
	PHP_FE(tokyo_dystopia_core_get, NULL)
	PHP_FE(tokyo_dystopia_core_put, NULL)
	PHP_FE(tokyo_dystopia_core_out, NULL)
	PHP_FE(tokyo_dystopia_core_search, NULL)
	PHP_FE(tokyo_dystopia_core_iterinit, NULL)
	PHP_FE(tokyo_dystopia_core_iternext, NULL)
	PHP_FE(tokyo_dystopia_core_sync, NULL)
	PHP_FE(tokyo_dystopia_core_optimize, NULL)
	PHP_FE(tokyo_dystopia_core_vanish, NULL)
	PHP_FE(tokyo_dystopia_core_copy, NULL)
	PHP_FE(tokyo_dystopia_core_path, NULL)
	PHP_FE(tokyo_dystopia_core_rnum, NULL)
	PHP_FE(tokyo_dystopia_core_fsiz, NULL)
	PHP_FE(tokyo_dystopia_core_ecode, NULL)
	PHP_FE(tokyo_dystopia_core_errmsg, NULL)

	PHP_FE(tokyo_dystopia_qgram_ctor, NULL)
	PHP_FE(tokyo_dystopia_qgram_open, NULL)
	PHP_FE(tokyo_dystopia_qgram_close, NULL)
	PHP_FE(tokyo_dystopia_qgram_tune, NULL)
	PHP_FE(tokyo_dystopia_qgram_setcache, NULL)
	PHP_FE(tokyo_dystopia_qgram_setfwmmax, NULL)
	PHP_FE(tokyo_dystopia_qgram_put, NULL)
	PHP_FE(tokyo_dystopia_qgram_out, NULL)
	PHP_FE(tokyo_dystopia_qgram_search, NULL)
	PHP_FE(tokyo_dystopia_qgram_sync, NULL)
	PHP_FE(tokyo_dystopia_qgram_optimize, NULL)
	PHP_FE(tokyo_dystopia_qgram_vanish, NULL)
	PHP_FE(tokyo_dystopia_qgram_copy, NULL)
	PHP_FE(tokyo_dystopia_qgram_path, NULL)
	PHP_FE(tokyo_dystopia_qgram_tnum, NULL)
	PHP_FE(tokyo_dystopia_qgram_fsiz, NULL)
	PHP_FE(tokyo_dystopia_qgram_ecode, NULL)
	PHP_FE(tokyo_dystopia_qgram_errmsg, NULL)

	PHP_FE(tokyo_dystopia_simple_ctor, NULL)
	PHP_FE(tokyo_dystopia_simple_open, NULL)
	PHP_FE(tokyo_dystopia_simple_close, NULL)
	PHP_FE(tokyo_dystopia_simple_tune, NULL)
	PHP_FE(tokyo_dystopia_simple_setcache, NULL)
	PHP_FE(tokyo_dystopia_simple_setfwmmax, NULL)
	PHP_FE(tokyo_dystopia_simple_get, NULL)
	PHP_FE(tokyo_dystopia_simple_put, NULL)
	PHP_FE(tokyo_dystopia_simple_out, NULL)
	PHP_FE(tokyo_dystopia_simple_search, NULL)
	PHP_FE(tokyo_dystopia_simple_sync, NULL)
	PHP_FE(tokyo_dystopia_simple_optimize, NULL)
	PHP_FE(tokyo_dystopia_simple_vanish, NULL)
	PHP_FE(tokyo_dystopia_simple_copy, NULL)
	PHP_FE(tokyo_dystopia_simple_path, NULL)
	PHP_FE(tokyo_dystopia_simple_rnum, NULL)
	PHP_FE(tokyo_dystopia_simple_fsiz, NULL)
	PHP_FE(tokyo_dystopia_simple_ecode, NULL)
	PHP_FE(tokyo_dystopia_simple_errmsg, NULL)

	PHP_FE(tokyo_dystopia_word_ctor, NULL)
	PHP_FE(tokyo_dystopia_word_open, NULL)
	PHP_FE(tokyo_dystopia_word_close, NULL)
	PHP_FE(tokyo_dystopia_word_tune, NULL)
	PHP_FE(tokyo_dystopia_word_setcache, NULL)
	PHP_FE(tokyo_dystopia_word_setfwmmax, NULL)
	PHP_FE(tokyo_dystopia_word_put, NULL)
	PHP_FE(tokyo_dystopia_word_out, NULL)
	PHP_FE(tokyo_dystopia_word_search, NULL)
	PHP_FE(tokyo_dystopia_word_sync, NULL)
	PHP_FE(tokyo_dystopia_word_optimize, NULL)
	PHP_FE(tokyo_dystopia_word_vanish, NULL)
	PHP_FE(tokyo_dystopia_word_copy, NULL)
	PHP_FE(tokyo_dystopia_word_path, NULL)
	PHP_FE(tokyo_dystopia_word_tnum, NULL)
	PHP_FE(tokyo_dystopia_word_fsiz, NULL)
	PHP_FE(tokyo_dystopia_word_ecode, NULL)
	PHP_FE(tokyo_dystopia_word_errmsg, NULL)
    {NULL, NULL, NULL}
};
/* }}} */

/* {{{ tokyo_dystopia_core_functions[] */
static zend_function_entry tokyo_dystopia_core_functions[] = {
	PHP_FALIAS(tokyodystopiacore,		tokyo_dystopia_core_ctor,			NULL)
	PHP_FALIAS(open,					tokyo_dystopia_core_open,			NULL)
	PHP_FALIAS(close,					tokyo_dystopia_core_close,			NULL)
	PHP_FALIAS(tune,					tokyo_dystopia_core_tune,			NULL)
	PHP_FALIAS(setcache,				tokyo_dystopia_core_setcache,		NULL)
	PHP_FALIAS(setfwmmax,				tokyo_dystopia_core_setfwmmax,		NULL)
	PHP_FALIAS(get,						tokyo_dystopia_core_get,			NULL)
	PHP_FALIAS(put,						tokyo_dystopia_core_put,			NULL)
	PHP_FALIAS(out,						tokyo_dystopia_core_out,			NULL)
	PHP_FALIAS(search,					tokyo_dystopia_core_search,			NULL)
	PHP_FALIAS(iterinit,				tokyo_dystopia_core_iterinit,		NULL)
	PHP_FALIAS(iternext,				tokyo_dystopia_core_iternext,		NULL)
	PHP_FALIAS(sync,					tokyo_dystopia_core_sync,			NULL)
	PHP_FALIAS(optimize,				tokyo_dystopia_core_optimize,		NULL)
	PHP_FALIAS(vanish,					tokyo_dystopia_core_vanish,			NULL)
	PHP_FALIAS(copy,					tokyo_dystopia_core_copy,			NULL)
	PHP_FALIAS(path,					tokyo_dystopia_core_path,			NULL)
	PHP_FALIAS(rnum,					tokyo_dystopia_core_rnum,			NULL)
	PHP_FALIAS(fsiz,					tokyo_dystopia_core_fsiz,			NULL)
	PHP_FALIAS(ecode,					tokyo_dystopia_core_ecode,			NULL)
	PHP_FALIAS(errmsg,					tokyo_dystopia_core_errmsg,			NULL)
	{NULL, NULL, NULL}
};
/* }}} */

/* {{{ tokyo_dystopia_qgram_functions[] */
static zend_function_entry tokyo_dystopia_qgram_functions[] = {
	PHP_FALIAS(tokyodystopiaqgram,		tokyo_dystopia_qgram_ctor,			NULL)
	PHP_FALIAS(open,					tokyo_dystopia_qgram_open,			NULL)
	PHP_FALIAS(close,					tokyo_dystopia_qgram_close,			NULL)
	PHP_FALIAS(tune,					tokyo_dystopia_qgram_tune,			NULL)
	PHP_FALIAS(setcache,				tokyo_dystopia_qgram_setcache,		NULL)
	PHP_FALIAS(setfwmmax,				tokyo_dystopia_qgram_setfwmmax,		NULL)
	PHP_FALIAS(put,						tokyo_dystopia_qgram_put,			NULL)
	PHP_FALIAS(out,						tokyo_dystopia_qgram_out,			NULL)
	PHP_FALIAS(search,					tokyo_dystopia_qgram_search,			NULL)
	PHP_FALIAS(sync,					tokyo_dystopia_qgram_sync,			NULL)
	PHP_FALIAS(optimize,				tokyo_dystopia_qgram_optimize,		NULL)
	PHP_FALIAS(vanish,					tokyo_dystopia_qgram_vanish,			NULL)
	PHP_FALIAS(copy,					tokyo_dystopia_qgram_copy,			NULL)
	PHP_FALIAS(path,					tokyo_dystopia_qgram_path,			NULL)
	PHP_FALIAS(rnum,					tokyo_dystopia_qgram_tnum,			NULL)
	PHP_FALIAS(fsiz,					tokyo_dystopia_qgram_fsiz,			NULL)
	PHP_FALIAS(ecode,					tokyo_dystopia_qgram_ecode,			NULL)
	PHP_FALIAS(errmsg,					tokyo_dystopia_qgram_errmsg,			NULL)
	{NULL, NULL, NULL}
};
/* }}} */

/* {{{ tokyo_dystopia_simple_functions[] */
static zend_function_entry tokyo_dystopia_simple_functions[] = {
	PHP_FALIAS(tokyodystopiasimple,		tokyo_dystopia_simple_ctor,			NULL)
	PHP_FALIAS(open,					tokyo_dystopia_simple_open,			NULL)
	PHP_FALIAS(close,					tokyo_dystopia_simple_close,			NULL)
	PHP_FALIAS(tune,					tokyo_dystopia_simple_tune,			NULL)
	PHP_FALIAS(setcache,				tokyo_dystopia_simple_setcache,		NULL)
	PHP_FALIAS(setfwmmax,				tokyo_dystopia_simple_setfwmmax,		NULL)
	PHP_FALIAS(get,						tokyo_dystopia_simple_get,			NULL)
	PHP_FALIAS(put,						tokyo_dystopia_simple_put,			NULL)
	PHP_FALIAS(out,						tokyo_dystopia_simple_out,			NULL)
	PHP_FALIAS(search,					tokyo_dystopia_simple_search,			NULL)
	PHP_FALIAS(iterinit,				tokyo_dystopia_simple_iterinit,		NULL)
	PHP_FALIAS(iternext,				tokyo_dystopia_simple_iternext,		NULL)
	PHP_FALIAS(sync,					tokyo_dystopia_simple_sync,			NULL)
	PHP_FALIAS(optimize,				tokyo_dystopia_simple_optimize,		NULL)
	PHP_FALIAS(vanish,					tokyo_dystopia_simple_vanish,			NULL)
	PHP_FALIAS(copy,					tokyo_dystopia_simple_copy,			NULL)
	PHP_FALIAS(path,					tokyo_dystopia_simple_path,			NULL)
	PHP_FALIAS(rnum,					tokyo_dystopia_simple_rnum,			NULL)
	PHP_FALIAS(fsiz,					tokyo_dystopia_simple_fsiz,			NULL)
	PHP_FALIAS(ecode,					tokyo_dystopia_simple_ecode,			NULL)
	PHP_FALIAS(errmsg,					tokyo_dystopia_simple_errmsg,			NULL)
	{NULL, NULL, NULL}
};
/* }}} */

/* {{{ tokyo_dystopia_word_functions[] */
static zend_function_entry tokyo_dystopia_word_functions[] = {
	PHP_FALIAS(tokyodystopiaword,		tokyo_dystopia_word_ctor,			NULL)
	PHP_FALIAS(open,					tokyo_dystopia_word_open,			NULL)
	PHP_FALIAS(close,					tokyo_dystopia_word_close,			NULL)
	PHP_FALIAS(tune,					tokyo_dystopia_word_tune,			NULL)
	PHP_FALIAS(setcache,				tokyo_dystopia_word_setcache,		NULL)
	PHP_FALIAS(setfwmmax,				tokyo_dystopia_word_setfwmmax,		NULL)
	PHP_FALIAS(put,						tokyo_dystopia_word_put,			NULL)
	PHP_FALIAS(out,						tokyo_dystopia_word_out,			NULL)
	PHP_FALIAS(search,					tokyo_dystopia_word_search,			NULL)
	PHP_FALIAS(sync,					tokyo_dystopia_word_sync,			NULL)
	PHP_FALIAS(optimize,				tokyo_dystopia_word_optimize,		NULL)
	PHP_FALIAS(vanish,					tokyo_dystopia_word_vanish,			NULL)
	PHP_FALIAS(copy,					tokyo_dystopia_word_copy,			NULL)
	PHP_FALIAS(path,					tokyo_dystopia_word_path,			NULL)
	PHP_FALIAS(rnum,					tokyo_dystopia_word_tnum,			NULL)
	PHP_FALIAS(fsiz,					tokyo_dystopia_word_fsiz,			NULL)
	PHP_FALIAS(ecode,					tokyo_dystopia_word_ecode,			NULL)
	PHP_FALIAS(errmsg,					tokyo_dystopia_word_errmsg,			NULL)
	{NULL, NULL, NULL}
};
/* }}} */

/* {{{ tokyo_dystopia_module_entry */
zend_module_entry tokyo_dystopia_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_TOKYO_DYSTOPIA_EXTNAME,
    tokyo_dystopia_functions,
	PHP_MINIT(tokyo_dystopia),
	PHP_MSHUTDOWN(tokyo_dystopia),
	PHP_RINIT(tokyo_dystopia),					/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(tokyo_dystopia),				/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(tokyo_dystopia),
#if ZEND_MODULE_API_NO >= 20010901
    PHP_TOKYO_DYSTOPIA_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TOKYO_DYSTOPIA
ZEND_GET_MODULE(tokyo_dystopia)
#endif

/* {{{ static function prototype */
static void _tokyo_dystopia_core_resource_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC);
static int _tokyo_dystopia_core_ctor(zval *obj);
static void* _tokyo_dystopia_get_db_core(zval *obj);

static void _tokyo_dystopia_qgram_resource_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC);
static int _tokyo_dystopia_qgram_ctor(zval *obj);
static void* _tokyo_dystopia_get_db_qgram(zval *obj);

static void _tokyo_dystopia_simple_resource_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC);
static int _tokyo_dystopia_simple_ctor(zval *obj);
static void* _tokyo_dystopia_get_db_simple(zval *obj);

static void _tokyo_dystopia_word_resource_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC);
static int _tokyo_dystopia_word_ctor(zval *obj);
static void* _tokyo_dystopia_get_db_word(zval *obj);
/* }}} */

/* {{{ static variables */
static int le_tokyo_dystopia_core;
static int le_tokyo_dystopia_qgram;
static int le_tokyo_dystopia_simple;
static int le_tokyo_dystopia_word;
static zend_class_entry *tokyo_dystopia_core_entry_ptr = NULL;
static zend_class_entry *tokyo_dystopia_qgram_entry_ptr = NULL;
static zend_class_entry *tokyo_dystopia_simple_entry_ptr = NULL;
static zend_class_entry *tokyo_dystopia_word_entry_ptr = NULL;
/* }}} */

/* {{{ module interface */
/* {{{ php_tokyo_dystopia_init_globals */
static void php_tokyo_dystopia_init_globals(zend_tokyo_dystopia_globals *tokyo_dystopia_globals) {   
}
/* }}} */

/* {{{ php_tokyo_dystopia_shutdown_globals */
static void php_tokyo_dystopia_shutdown_globals(zend_tokyo_dystopia_globals *tokyo_dystopia_globals TSRMLS_DC) {
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(tokyo_dystopia) {
	ZEND_INIT_MODULE_GLOBALS(tokyo_dystopia, php_tokyo_dystopia_init_globals, php_tokyo_dystopia_shutdown_globals);

	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/

	le_tokyo_dystopia_core = zend_register_list_destructors_ex(_tokyo_dystopia_core_resource_dtor, NULL, "tokyo dystopia core object", module_number);
	le_tokyo_dystopia_qgram = zend_register_list_destructors_ex(_tokyo_dystopia_qgram_resource_dtor, NULL, "tokyo dystopia qgram object", module_number);
	le_tokyo_dystopia_simple = zend_register_list_destructors_ex(_tokyo_dystopia_simple_resource_dtor, NULL, "tokyo dystopia simple object", module_number);
	le_tokyo_dystopia_word = zend_register_list_destructors_ex(_tokyo_dystopia_word_resource_dtor, NULL, "tokyo dystopia word object", module_number);

	zend_class_entry tokyo_dystopia_core_entry;
	INIT_CLASS_ENTRY(tokyo_dystopia_core_entry, "tokyodystopiacore", tokyo_dystopia_core_functions);
	tokyo_dystopia_core_entry_ptr = zend_register_internal_class(&tokyo_dystopia_core_entry TSRMLS_CC);

	zend_class_entry tokyo_dystopia_qgram_entry;
	INIT_CLASS_ENTRY(tokyo_dystopia_qgram_entry, "tokyodystopiaqgram", tokyo_dystopia_qgram_functions);
	tokyo_dystopia_qgram_entry_ptr = zend_register_internal_class(&tokyo_dystopia_qgram_entry TSRMLS_CC);

	zend_class_entry tokyo_dystopia_simple_entry;
	INIT_CLASS_ENTRY(tokyo_dystopia_simple_entry, "tokyodystopiasimple", tokyo_dystopia_simple_functions);
	tokyo_dystopia_simple_entry_ptr = zend_register_internal_class(&tokyo_dystopia_simple_entry TSRMLS_CC);

	zend_class_entry tokyo_dystopia_word_entry;
	INIT_CLASS_ENTRY(tokyo_dystopia_word_entry, "tokyodystopiaword", tokyo_dystopia_word_functions);
	tokyo_dystopia_word_entry_ptr = zend_register_internal_class(&tokyo_dystopia_word_entry TSRMLS_CC);

	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_IDBOREADER",	IDBOREADER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_IDBOWRITER",	IDBOWRITER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_IDBOCREAT",	IDBOCREAT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_IDBOTRUNC",	IDBOTRUNC, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_IDBONOLCK",	IDBONOLCK, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_IDBOLCKNB",	IDBOLCKNB, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_IDBTLARGE",		IDBTLARGE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_IDBTDEFLATE",	IDBTDEFLATE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_IDBTTCBS",		IDBTTCBS, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBOREADER",	QDBOREADER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBOWRITER",	QDBOWRITER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBOCREAT",	QDBOCREAT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBOTRUNC",	QDBOTRUNC, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBONOLCK",	QDBONOLCK, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBOLCKNB",	QDBOLCKNB, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBTLARGE",		QDBTLARGE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBTDEFLATE",	QDBTDEFLATE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBTTCBS",		QDBTTCBS, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBSSUBSTR",		QDBSSUBSTR, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBSPREFIX",		QDBSPREFIX, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBSSUFFIX",		QDBSSUFFIX, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_QDBSFULL",		QDBSFULL, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_JDBOREADER",	JDBOREADER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_JDBOWRITER",	JDBOWRITER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_JDBOCREAT",	JDBOCREAT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_JDBOTRUNC",	JDBOTRUNC, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_JDBONOLCK",	JDBONOLCK, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_JDBOLCKNB",	JDBOLCKNB, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_JDBTLARGE",		JDBTLARGE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_JDBTDEFLATE",	JDBTDEFLATE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_JDBTTCBS",		JDBTTCBS, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_WDBOREADER",	WDBOREADER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_WDBOWRITER",	WDBOWRITER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_WDBOCREAT",	WDBOCREAT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_WDBOTRUNC",	WDBOTRUNC, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_WDBONOLCK",	WDBONOLCK, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_WDBOLCKNB",	WDBOLCKNB, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_WDBTLARGE",		WDBTLARGE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_WDBTDEFLATE",	WDBTDEFLATE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TOKYO_DYSTOPIA_WDBTTCBS",		WDBTTCBS, CONST_CS | CONST_PERSISTENT);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(tokyo_dystopia) {
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/

#ifndef ZTS
	php_tokyo_dystopia_shutdown_globals(&tokyo_dystopia_globals TSRMLS_CC);
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(tokyo_dystopia) {
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RSHUTDOWN_FUNCTION */
PHP_RSHUTDOWN_FUNCTION(tokyo_dystopia) {
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(tokyo_dystopia) {
	php_info_print_table_start();
	php_info_print_table_row(2, "Tokyo Dystopia", "enabled");
	php_info_print_table_row(2, "Revision", "$Revision: 142 $");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */
/* }}} */

/* {{{ static functions */
/* {{{ _tokyo_dystopia_core_resource_dtor */
static void _tokyo_dystopia_core_resource_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC) {
	tcidbdel((TCIDB*)rsrc->ptr TSRMLS_CC);
}
/* }}} */

/* {{{ _tokyo_dystopia_core_ctor */
static int _tokyo_dystopia_core_ctor(zval *obj) {
	if (!obj) {
		return -1;
	}

	TCIDB *db = tcidbnew();
	int list_id = zend_list_insert(db, le_tokyo_dystopia_core);
	add_property_resource(obj, "db", list_id);

	return 0;
}
/* }}} */

/* {{{ _tokyo_dystopia_get_db_core */
static void* _tokyo_dystopia_get_db_core(zval *obj) {
	zval **db_tmp;
	int resource_type;
	tokyo_dystopia_objprop_get_p(obj, "db", db_tmp, 0);
	if (db_tmp == NULL) {
		return NULL;
	}
	void *db = (void*)zend_list_find(Z_LVAL_PP(db_tmp), &resource_type);
	if (db == NULL || resource_type != le_tokyo_dystopia_core) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "db identifier not found");
		return NULL;
	}

	return db;
}
/* }}} */

/* {{{ _tokyo_dystopia_qgram_resource_dtor */
static void _tokyo_dystopia_qgram_resource_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC) {
	tcqdbdel((TCQDB*)rsrc->ptr TSRMLS_CC);
}
/* }}} */

/* {{{ _tokyo_dystopia_qgram_ctor */
static int _tokyo_dystopia_qgram_ctor(zval *obj) {
	if (!obj) {
		return -1;
	}

	TCQDB *db = tcqdbnew();
	int list_id = zend_list_insert(db, le_tokyo_dystopia_qgram);
	add_property_resource(obj, "db", list_id);

	return 0;
}
/* }}} */

/* {{{ _tokyo_dystopia_get_db_qgram */
static void* _tokyo_dystopia_get_db_qgram(zval *obj) {
	zval **db_tmp;
	int resource_type;
	tokyo_dystopia_objprop_get_p(obj, "db", db_tmp, 0);
	if (db_tmp == NULL) {
		return NULL;
	}
	void *db = (void*)zend_list_find(Z_LVAL_PP(db_tmp), &resource_type);
	if (db == NULL || resource_type != le_tokyo_dystopia_qgram) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "db identifier not found");
		return NULL;
	}

	return db;
}
/* }}} */

/* {{{ _tokyo_dystopia_simple_resource_dtor */
static void _tokyo_dystopia_simple_resource_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC) {
	tcjdbdel((TCJDB*)rsrc->ptr TSRMLS_CC);
}
/* }}} */

/* {{{ _tokyo_dystopia_simple_ctor */
static int _tokyo_dystopia_simple_ctor(zval *obj) {
	if (!obj) {
		return -1;
	}

	TCJDB *db = tcjdbnew();
	int list_id = zend_list_insert(db, le_tokyo_dystopia_simple);
	add_property_resource(obj, "db", list_id);

	return 0;
}
/* }}} */

/* {{{ _tokyo_dystopia_get_db_simple */
static void* _tokyo_dystopia_get_db_simple(zval *obj) {
	zval **db_tmp;
	int resource_type;
	tokyo_dystopia_objprop_get_p(obj, "db", db_tmp, 0);
	if (db_tmp == NULL) {
		return NULL;
	}
	void *db = (void*)zend_list_find(Z_LVAL_PP(db_tmp), &resource_type);
	if (db == NULL || resource_type != le_tokyo_dystopia_simple) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "db identifier not found");
		return NULL;
	}

	return db;
}
/* }}} */

/* {{{ _tokyo_dystopia_word_resource_dtor */
static void _tokyo_dystopia_word_resource_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC) {
	tcwdbdel((TCWDB*)rsrc->ptr TSRMLS_CC);
}
/* }}} */

/* {{{ _tokyo_dystopia_word_ctor */
static int _tokyo_dystopia_word_ctor(zval *obj) {
	if (!obj) {
		return -1;
	}

	TCWDB *db = tcwdbnew();
	int list_id = zend_list_insert(db, le_tokyo_dystopia_word);
	add_property_resource(obj, "db", list_id);

	return 0;
}
/* }}} */

/* {{{ _tokyo_dystopia_get_db_word */
static void* _tokyo_dystopia_get_db_word(zval *obj) {
	zval **db_tmp;
	int resource_type;
	tokyo_dystopia_objprop_get_p(obj, "db", db_tmp, 0);
	if (db_tmp == NULL) {
		return NULL;
	}
	void *db = (void*)zend_list_find(Z_LVAL_PP(db_tmp), &resource_type);
	if (db == NULL || resource_type != le_tokyo_dystopia_word) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "db identifier not found");
		return NULL;
	}

	return db;
}
/* }}} */
/* }}} */

/* {{{ proto tokyo_dystopia_core_ctor() */
PHP_FUNCTION(tokyo_dystopia_core_ctor) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (!obj) {
		RETURN_FALSE;
	}

	_tokyo_dystopia_core_ctor(obj);
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_open */
PHP_FUNCTION(tokyo_dystopia_core_open) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *path;
	int path_len;
	int flag;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &path, &path_len, &flag) == FAILURE) {
		return;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbopen(db, path, flag)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_close */
PHP_FUNCTION(tokyo_dystopia_core_close) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbclose(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_tune */
PHP_FUNCTION(tokyo_dystopia_core_tune) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long ernum;
	long etnum;
	long iusiz;
	long flag;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &ernum, &etnum, &iusiz, &flag) == FAILURE) {
		return;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbtune(db, ernum, etnum, iusiz, flag)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_setcache */
PHP_FUNCTION(tokyo_dystopia_core_setcache) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long icsiz;
	long lcnum;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &icsiz, &lcnum) == FAILURE) {
		return;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbsetcache(db, icsiz, lcnum)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_setfwmmax */
PHP_FUNCTION(tokyo_dystopia_core_setfwmmax) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long fwmmax;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &fwmmax) == FAILURE) {
		return;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbsetfwmmax(db, fwmmax)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_iterinit */
PHP_FUNCTION(tokyo_dystopia_core_iterinit) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbiterinit(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_iternext */
PHP_FUNCTION(tokyo_dystopia_core_iternext) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcidbiternext(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_sync */
PHP_FUNCTION(tokyo_dystopia_core_sync) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbsync(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_optimize */
PHP_FUNCTION(tokyo_dystopia_core_optimize) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidboptimize(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_vanish */
PHP_FUNCTION(tokyo_dystopia_core_vanish) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbvanish(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_copy */
PHP_FUNCTION(tokyo_dystopia_core_copy) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *path;
	int path_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
		return;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbcopy(db, path)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_path */
PHP_FUNCTION(tokyo_dystopia_core_path) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	char *path = tcidbpath(db);
	if (!path) {
		RETURN_FALSE;
	}

	RETURN_STRING(path, 1);
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_rnum */
PHP_FUNCTION(tokyo_dystopia_core_rnum) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcidbrnum(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_fsiz */
PHP_FUNCTION(tokyo_dystopia_core_fsiz) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcidbfsiz(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_get */
PHP_FUNCTION(tokyo_dystopia_core_get) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &id) == FAILURE) {
		return;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	char *data = tcidbget(db, id);
	if (!data) {
		RETURN_FALSE;
	}

	RETVAL_STRING(data, 1);
	free(data);
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_put */
PHP_FUNCTION(tokyo_dystopia_core_put) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	char *data;
	int data_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ls", &id, &data, &data_len) == FAILURE) {
		return;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (id <= 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "id parameter should be positive");
		RETURN_FALSE;
	}

	if (tcidbput(db, id, data)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_out */
PHP_FUNCTION(tokyo_dystopia_core_out) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &id) == FAILURE) {
		return;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcidbout(db, id)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_search */
PHP_FUNCTION(tokyo_dystopia_core_search) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *q;
	int q_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &q, &q_len) == FAILURE) {
		return;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	int n;
	uint64_t *r = tcidbsearch2(db, q, &n);
	if (!r) {
		RETURN_FALSE;
	}
	
	int i;
	array_init(return_value);
	zval *tmp;
	for (i = 0; i < n; i++) {
		add_index_long(return_value, i, r[i]);
	}
	free(r);
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_ecode */
PHP_FUNCTION(tokyo_dystopia_core_ecode) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcidbecode(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_core_errmsg */
PHP_FUNCTION(tokyo_dystopia_core_errmsg) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_core_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCIDB *db = (TCIDB*)_tokyo_dystopia_get_db_core(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	// FIXME: const char* -> char*
	RETURN_STRING(tcidberrmsg(tcidbecode(db)), 1);
}
/* }}} */


/* {{{ proto tokyo_dystopia_qgram_ctor() */
PHP_FUNCTION(tokyo_dystopia_qgram_ctor) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (!obj) {
		RETURN_FALSE;
	}

	_tokyo_dystopia_qgram_ctor(obj);
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_open */
PHP_FUNCTION(tokyo_dystopia_qgram_open) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *path;
	int path_len;
	long flag;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &path, &path_len, &flag) == FAILURE) {
		return;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdbopen(db, path, flag)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_close */
PHP_FUNCTION(tokyo_dystopia_qgram_close) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdbclose(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_tune */
PHP_FUNCTION(tokyo_dystopia_qgram_tune) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long etnum;
	long flag;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &etnum, &flag) == FAILURE) {
		return;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdbtune(db, etnum, flag)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_setcache */
PHP_FUNCTION(tokyo_dystopia_qgram_setcache) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long icsiz;
	long lcnum;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &icsiz, &lcnum) == FAILURE) {
		return;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdbsetcache(db, icsiz, lcnum)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_setfwmmax */
PHP_FUNCTION(tokyo_dystopia_qgram_setfwmmax) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long fwmmax;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &fwmmax) == FAILURE) {
		return;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdbsetfwmmax(db, fwmmax)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_sync */
PHP_FUNCTION(tokyo_dystopia_qgram_sync) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdbsync(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_optimize */
PHP_FUNCTION(tokyo_dystopia_qgram_optimize) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdboptimize(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_vanish */
PHP_FUNCTION(tokyo_dystopia_qgram_vanish) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdbvanish(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_copy */
PHP_FUNCTION(tokyo_dystopia_qgram_copy) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *path;
	int path_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
		return;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdbcopy(db, path)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_path */
PHP_FUNCTION(tokyo_dystopia_qgram_path) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	char *path = tcqdbpath(db);
	if (!path) {
		RETURN_FALSE;
	}

	RETURN_STRING(path, 1);
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_tnum */
PHP_FUNCTION(tokyo_dystopia_qgram_tnum) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcqdbtnum(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_fsiz */
PHP_FUNCTION(tokyo_dystopia_qgram_fsiz) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcqdbfsiz(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_put */
PHP_FUNCTION(tokyo_dystopia_qgram_put) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	char *data;
	int data_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ls", &id, &data, &data_len) == FAILURE) {
		return;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (id <= 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "id parameter should be positive");
		RETURN_FALSE;
	}

	if (tcqdbput(db, id, data)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_out */
PHP_FUNCTION(tokyo_dystopia_qgram_out) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	char *data;
	int data_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ls", &id, &data, &data_len) == FAILURE) {
		return;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcqdbout(db, id, data)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_search */
PHP_FUNCTION(tokyo_dystopia_qgram_search) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *q;
	int q_len;
	long mode;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &q, &q_len, &mode) == FAILURE) {
		return;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	int n;
	uint64_t *r = tcqdbsearch(db, q, mode, &n);
	if (!r) {
		RETURN_FALSE;
	}
	
	int i;
	array_init(return_value);
	zval *tmp;
	for (i = 0; i < n; i++) {
		add_index_long(return_value, i, r[i]);
	}
	free(r);
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_ecode */
PHP_FUNCTION(tokyo_dystopia_qgram_ecode) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcqdbecode(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_qgram_errmsg */
PHP_FUNCTION(tokyo_dystopia_qgram_errmsg) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_qgram_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCQDB *db = (TCQDB*)_tokyo_dystopia_get_db_qgram(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	// FIXME: const char* -> char*
	RETURN_STRING(tcqdberrmsg(tcqdbecode(db)), 1);
}
/* }}} */


/* {{{ proto tokyo_dystopia_simple_ctor() */
PHP_FUNCTION(tokyo_dystopia_simple_ctor) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (!obj) {
		RETURN_FALSE;
	}

	_tokyo_dystopia_simple_ctor(obj);
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_open */
PHP_FUNCTION(tokyo_dystopia_simple_open) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *path;
	int path_len;
	long flag;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &path, &path_len, &flag) == FAILURE) {
		return;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbopen(db, path, flag)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_close */
PHP_FUNCTION(tokyo_dystopia_simple_close) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbclose(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_tune */
PHP_FUNCTION(tokyo_dystopia_simple_tune) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long ernum;
	long etnum;
	long iusiz;
	long flag;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &ernum, &etnum, &iusiz, &flag) == FAILURE) {
		return;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbtune(db, ernum, etnum, iusiz, flag)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_setcache */
PHP_FUNCTION(tokyo_dystopia_simple_setcache) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	int icsiz;
	int lcnum;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &icsiz, &lcnum) == FAILURE) {
		return;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbsetcache(db, icsiz, lcnum)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_setfwmmax */
PHP_FUNCTION(tokyo_dystopia_simple_setfwmmax) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	int fwmmax;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &fwmmax) == FAILURE) {
		return;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbsetfwmmax(db, fwmmax)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_iterinit */
PHP_FUNCTION(tokyo_dystopia_simple_iterinit) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbiterinit(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_iternext */
PHP_FUNCTION(tokyo_dystopia_simple_iternext) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcjdbiternext(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_sync */
PHP_FUNCTION(tokyo_dystopia_simple_sync) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbsync(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_optimize */
PHP_FUNCTION(tokyo_dystopia_simple_optimize) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdboptimize(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_vanish */
PHP_FUNCTION(tokyo_dystopia_simple_vanish) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbvanish(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_copy */
PHP_FUNCTION(tokyo_dystopia_simple_copy) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *path;
	int path_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
		return;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbcopy(db, path)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_path */
PHP_FUNCTION(tokyo_dystopia_simple_path) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	char *path = tcjdbpath(db);
	if (!path) {
		RETURN_FALSE;
	}

	RETURN_STRING(path, 1);
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_rnum */
PHP_FUNCTION(tokyo_dystopia_simple_rnum) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcjdbrnum(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_fsiz */
PHP_FUNCTION(tokyo_dystopia_simple_fsiz) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcjdbfsiz(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_get */
PHP_FUNCTION(tokyo_dystopia_simple_get) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &id) == FAILURE) {
		return;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	TCLIST *list = tcjdbget(db, id);
	if (!list) {
		RETURN_FALSE;
	}

	array_init(return_value);
	char *data;
	int data_len;
	int n = 0;
	while ((data = tclistshift(list, &data_len)) != NULL) {
		add_index_stringl(return_value, n, data, data_len, 1);
		free(data);
		n++;
	}
	tclistdel(list);
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_put */
PHP_FUNCTION(tokyo_dystopia_simple_put) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	zval *array;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "la", &id, &array) == FAILURE) {
		return;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (id <= 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "id parameter should be positive");
		RETURN_FALSE;
	}

	TCLIST *list = tclistnew();
	zval **tmp;
	zend_hash_internal_pointer_reset(Z_ARRVAL_P(array));
	while (zend_hash_get_current_data(Z_ARRVAL_P(array), (void**)&tmp) == SUCCESS) {
		convert_to_string_ex(tmp);
		tclistpush(list, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
		zend_hash_move_forward(Z_ARRVAL_P(array));
	}

	if (tcjdbput(db, id, list)) {
		tclistdel(list);
		RETURN_FALSE;
	}

	tclistdel(list);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_out */
PHP_FUNCTION(tokyo_dystopia_simple_out) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &id) == FAILURE) {
		return;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcjdbout(db, id)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_search */
PHP_FUNCTION(tokyo_dystopia_simple_search) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *q;
	int q_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &q, &q_len) == FAILURE) {
		return;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	int n;
	uint64_t *r = tcjdbsearch2(db, q, &n);
	if (!r) {
		RETURN_FALSE;
	}
	
	int i;
	array_init(return_value);
	zval *tmp;
	for (i = 0; i < n; i++) {
		add_index_long(return_value, i, r[i]);
	}
	free(r);
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_ecode */
PHP_FUNCTION(tokyo_dystopia_simple_ecode) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcjdbecode(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_simple_errmsg */
PHP_FUNCTION(tokyo_dystopia_simple_errmsg) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_simple_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCJDB *db = (TCJDB*)_tokyo_dystopia_get_db_simple(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	// FIXME: const char* -> char*
	RETURN_STRING(tcjdberrmsg(tcjdbecode(db)), 1);
}
/* }}} */


/* {{{ proto tokyo_dystopia_word_ctor() */
PHP_FUNCTION(tokyo_dystopia_word_ctor) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (!obj) {
		RETURN_FALSE;
	}

	_tokyo_dystopia_word_ctor(obj);
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_open */
PHP_FUNCTION(tokyo_dystopia_word_open) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *path;
	int path_len;
	int flag;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &path, &path_len, &flag) == FAILURE) {
		return;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcwdbopen(db, path, flag)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_close */
PHP_FUNCTION(tokyo_dystopia_word_close) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcwdbclose(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_tune */
PHP_FUNCTION(tokyo_dystopia_word_tune) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	int etnum;
	int flag;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &etnum, &flag) == FAILURE) {
		return;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcwdbtune(db, etnum, flag)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_setcache */
PHP_FUNCTION(tokyo_dystopia_word_setcache) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	int icsiz;
	int lcnum;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &icsiz, &lcnum) == FAILURE) {
		return;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcwdbsetcache(db, icsiz, lcnum)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_setfwmmax */
PHP_FUNCTION(tokyo_dystopia_word_setfwmmax) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	int fwmmax;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &fwmmax) == FAILURE) {
		return;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcwdbsetfwmmax(db, fwmmax)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_sync */
PHP_FUNCTION(tokyo_dystopia_word_sync) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcwdbsync(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_optimize */
PHP_FUNCTION(tokyo_dystopia_word_optimize) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcwdboptimize(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_vanish */
PHP_FUNCTION(tokyo_dystopia_word_vanish) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcwdbvanish(db)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_copy */
PHP_FUNCTION(tokyo_dystopia_word_copy) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *path;
	int path_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &path_len) == FAILURE) {
		return;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (!tcwdbcopy(db, path)) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_path */
PHP_FUNCTION(tokyo_dystopia_word_path) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	char *path = tcwdbpath(db);
	if (!path) {
		RETURN_FALSE;
	}

	RETURN_STRING(path, 1);
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_tnum */
PHP_FUNCTION(tokyo_dystopia_word_tnum) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcwdbtnum(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_fsiz */
PHP_FUNCTION(tokyo_dystopia_word_fsiz) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcwdbfsiz(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_put */
PHP_FUNCTION(tokyo_dystopia_word_put) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	zval *array;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "la", &id, &array) == FAILURE) {
		return;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	if (id <= 0) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "id parameter should be positive");
		RETURN_FALSE;
	}

	TCLIST *list = tclistnew();
	zval **tmp;
	zend_hash_internal_pointer_reset(Z_ARRVAL_P(array));
	while (zend_hash_get_current_data(Z_ARRVAL_P(array), (void**)&tmp) == SUCCESS) {
		convert_to_string_ex(tmp);
		tclistpush(list, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
		zend_hash_move_forward(Z_ARRVAL_P(array));
	}

	if (tcwdbput(db, id, list)) {
		tclistdel(list);
		RETURN_FALSE;
	}

	tclistdel(list);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_out */
PHP_FUNCTION(tokyo_dystopia_word_out) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	long id;
	zval *array;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "la", &id) == FAILURE) {
		return;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	TCLIST *list = tclistnew();
	zval **tmp;
	zend_hash_internal_pointer_reset(Z_ARRVAL_P(array));
	while (zend_hash_get_current_data(Z_ARRVAL_P(array), (void**)&tmp) == SUCCESS) {
		convert_to_string_ex(tmp);
		tclistpush(list, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
		zend_hash_move_forward(Z_ARRVAL_P(array));
	}

	if (tcwdbout(db, id, list)) {
		tclistdel(list);
		RETURN_FALSE;
	}

	tclistdel(list);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_search */
PHP_FUNCTION(tokyo_dystopia_word_search) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	char *q;
	int q_len;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &q, &q_len) == FAILURE) {
		return;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	int n;
	uint64_t *r = tcwdbsearch(db, q, &n);
	if (!r) {
		RETURN_FALSE;
	}
	
	int i;
	array_init(return_value);
	zval *tmp;
	for (i = 0; i < n; i++) {
		add_index_long(return_value, i, r[i]);
	}
	free(r);
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_ecode */
PHP_FUNCTION(tokyo_dystopia_word_ecode) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	RETURN_LONG(tcwdbecode(db));
}
/* }}} */

/* {{{ proto tokyo_dystopia_word_errmsg */
PHP_FUNCTION(tokyo_dystopia_word_errmsg) {
	zval *obj = TOKYO_DYSTOPIA_GET_THIS(tokyo_dystopia_word_entry_ptr);
	if (obj == NULL) {
		RETURN_FALSE;
	}

	TCWDB *db = (TCWDB*)_tokyo_dystopia_get_db_word(obj);
	if (db == NULL) {
		RETURN_FALSE;
	}

	// FIXME: const char* -> char*
	RETURN_STRING(tcwdberrmsg(tcwdbecode(db)), 1);
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
