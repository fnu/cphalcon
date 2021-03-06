
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/object.h"

/**
 * Phalcon\Config
 *
 * Phalcon\Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 * 
 *
 */

/**
 * Phalcon\Config constructor
 *
 * @param array $arrayConfig
 * @return Phalcon\Config
 */
PHP_METHOD(Phalcon_Config, __construct){

	zval *array_config = NULL, *value = NULL, *key = NULL, *config_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &array_config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!array_config) {
		PHALCON_INIT_VAR(array_config);
		array_init(array_config);
	}
	
	if (!phalcon_valid_foreach(array_config TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(array_config);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_9656_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9656_0;
		}
		
		PHALCON_INIT_VAR(key);
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(value) == IS_ARRAY) { 
			PHALCON_INIT_VAR(config_value);
			object_init_ex(config_value, phalcon_config_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(config_value, "__construct", value, PH_CHECK);
			phalcon_update_property_zval_zval(this_ptr, key, config_value TSRMLS_CC);
		} else {
			phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9656_0;
	fee_9656_0:
	if(0){}
	
	
	PHALCON_MM_RESTORE();
}

