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
#include "php_get_bigger.h"

/* If you declare any globals in php_get_bigger.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(get_bigger)
*/

/* True global resources - no need for thread safety here */
static int le_get_bigger;

/* {{{ get_bigger_functions[]
 *
 * Every user visible function must have an entry in get_bigger_functions[].
 */
const zend_function_entry get_bigger_functions[] = {
	PHP_FE(get_bigger_int,	NULL)
	PHP_FE(get_bigger_double,	NULL)
	PHP_FE_END	/* Must be the last line in get_bigger_functions[] */
};
/* }}} */

/* {{{ get_bigger_module_entry
 */
zend_module_entry get_bigger_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"get_bigger",
	get_bigger_functions,
	PHP_MINIT(get_bigger),
	PHP_MSHUTDOWN(get_bigger),
	PHP_RINIT(get_bigger),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(get_bigger),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(get_bigger),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_GET_BIGGER_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GET_BIGGER
ZEND_GET_MODULE(get_bigger)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("get_bigger.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_get_bigger_globals, get_bigger_globals)
    STD_PHP_INI_ENTRY("get_bigger.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_get_bigger_globals, get_bigger_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_get_bigger_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_get_bigger_init_globals(zend_get_bigger_globals *get_bigger_globals)
{
	get_bigger_globals->global_value = 0;
	get_bigger_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(get_bigger)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(get_bigger)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(get_bigger)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(get_bigger)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(get_bigger)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "get_bigger support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
PHP_FUNCTION(get_bigger_int)
{
	long a, b;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &a, &b) == FAILURE) {
		return;
	}

	if (a >= b) {
		RETVAL_LONG(a);	
	} else {
		RETVAL_LONG(b);	
	}
	return;
}

PHP_FUNCTION(get_bigger_double)
{
	double a, b;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &a, &b) == FAILURE) {
		return;
	}

	if (a >= b) {
		RETVAL_DOUBLE(a);
	} else {
		RETVAL_DOUBLE(b);
	}
	return;
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
