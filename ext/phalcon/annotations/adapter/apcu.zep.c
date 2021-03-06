
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Annotations\Adapter\Apcu
 *
 * Stores the parsed annotations in APCu. This adapter is suitable for production
 *
 *<code>
 * use Phalcon\Annotations\Adapter\Apcu;
 *
 * $annotations = new Apcu();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Apcu) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Apcu, phalcon, annotations_adapter_apcu, phalcon_annotations_adapter_ce, phalcon_annotations_adapter_apcu_method_entry, 0);

	zend_declare_property_string(phalcon_annotations_adapter_apcu_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_annotations_adapter_apcu_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Adapter\Apcu constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apcu, __construct) {

	zval *options = NULL, options_sub, __$null, prefix, ttl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&ttl);

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&prefix, options, SL("prefix"), 1)) {
			zephir_update_property_zval(this_ptr, SL("_prefix"), &prefix);
		}
		if (zephir_array_isset_string_fetch(&ttl, options, SL("lifetime"), 1)) {
			zephir_update_property_zval(this_ptr, SL("_ttl"), &ttl);
		}
	}

}

/**
 * Reads parsed annotations from APCu
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apcu, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVV(&_2, "_PHAN", &_1, &key);
	zephir_fast_strtolower(&_0, &_2);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_fetch", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Writes parsed annotations to APCu
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apcu, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data, data_sub, _0, _1, _2, _3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVV(&_2, "_PHAN", &_1, &key);
	zephir_fast_strtolower(&_0, &_2);
	zephir_read_property(&_3, this_ptr, SL("_ttl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_store", NULL, 0, &_0, data, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

