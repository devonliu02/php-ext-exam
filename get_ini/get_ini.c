/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_get_ini.h"

ZEND_DECLARE_MODULE_GLOBALS(get_ini)

/* True global resources - no need for thread safety here */
static int le_get_ini;

/* {{{ get_ini_functions[]
 *
 * Every user visible function must have an entry in get_ini_functions[].
 */
const zend_function_entry get_ini_functions[] = {
	PHP_FE(get_ini,	NULL)
	PHP_FE_END	/* Must be the last line in get_ini_functions[] */
};
/* }}} */

/* {{{ get_ini_module_entry
 */
zend_module_entry get_ini_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"get_ini",
	get_ini_functions,
	PHP_MINIT(get_ini),
	PHP_MSHUTDOWN(get_ini),
	PHP_RINIT(get_ini),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(get_ini),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(get_ini),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_GET_INI_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GET_INI
ZEND_GET_MODULE(get_ini)
#endif

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("get_ini.size", "29", PHP_INI_ALL, OnUpdateLong, size, zend_get_ini_globals, get_ini_globals)
    STD_PHP_INI_ENTRY("get_ini.name", "Jay", PHP_INI_ALL, OnUpdateString, name, zend_get_ini_globals, get_ini_globals)
PHP_INI_END()
/* }}} */

/* {{{ php_get_ini_init_globals
 */
static void php_get_ini_init_globals(zend_get_ini_globals *get_ini_globals)
{
	get_ini_globals->size = 0;
	get_ini_globals->name = NULL;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(get_ini)
{
	REGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(get_ini)
{
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(get_ini)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(get_ini)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(get_ini)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "get_ini support", "enabled");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
PHP_FUNCTION(get_ini)
{
	int len;
	char *strg;

	len = spprintf(&strg, 0, "Your name is %s, and your size is %ld", GET_INI_G(name), GET_INI_G(size));
	RETURN_STRINGL(strg, len, 0);
}
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
