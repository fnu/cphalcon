
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 * 
 */

PHP_METHOD(Phalcon_Mvc_Dispatcher, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_dispatcher_ce, this_ptr, SL("_params"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\Manager $eventManager
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setEventsManager){

	zval *event_manager = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventManager"), event_manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the default namespace
 *
 * @param string $namespace
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultNamespace){

	zval *namespace = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &namespace) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultNamespace"), namespace TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the default controller name
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the default action name
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultAction){

	zval *action_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the controller name to be dispatched
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_controllerName"), controller_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets last dispatched controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(controller_name);
	phalcon_read_property(&controller_name, this_ptr, SL("_controllerName"), PH_NOISY_CC);
	
	RETURN_CCTOR(controller_name);
}

/**
 * Sets the action name to be dispatched
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setActionName){

	zval *action_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets last dispatched action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActionName){

	zval *action_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(action_name);
	phalcon_read_property(&action_name, this_ptr, SL("_actionName"), PH_NOISY_CC);
	
	RETURN_CCTOR(action_name);
}

/**
 * Sets action params to be dispatched
 *
 * @param array $params
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setParams){

	zval *params = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets action params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getParams){

	zval *params = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	
	RETURN_CCTOR(params);
}

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed $param
 * @param  mixed $value
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setParam){

	zval *param = NULL, *value = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &param, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_params"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, param, &value, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_params"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets a param by its name or numeric index
 *
 * @param  mixed $param
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getParam){

	zval *param = NULL, *params = NULL, *param_value = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(params, param);
	if (eval_int) {
		PHALCON_INIT_VAR(param_value);
		phalcon_array_fetch(&param_value, params, param, PH_NOISY_CC);
		
		RETURN_CCTOR(param_value);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Dispatches a controller action taking into account the routing parameters
 *
 * @return Phalcon\Mvc\Controller
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, dispatch){

	zval *dependency_injector = NULL, *events_manager = NULL;
	zval *status = NULL, *value = NULL, *controller = NULL, *number_dispatches = NULL;
	zval *default_namespace = NULL, *finished = NULL, *controller_name = NULL;
	zval *camelized_class = NULL, *controller_class = NULL;
	zval *action_name = NULL, *params = NULL, *action_method = NULL, *call_object = NULL;
	zval *exception_message = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL, *c6 = NULL;
	zval *c7 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_dispatcher_exception_ce, "A dependency injection container is required to access related dispatching services");
		return;
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventManager"), PH_NOISY_CC);
	if (zend_is_true(events_manager)) {
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "dispatch:beforeDispatchLoop", 1);
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", c0, this_ptr, PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(value);
	ZVAL_NULL(value);
	
	PHALCON_INIT_VAR(controller);
	ZVAL_NULL(controller);
	
	PHALCON_INIT_VAR(number_dispatches);
	ZVAL_LONG(number_dispatches, 0);
	
	PHALCON_INIT_VAR(default_namespace);
	phalcon_read_property(&default_namespace, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	ws_1d57_0:
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_finished"), PH_NOISY_CC);
		PHALCON_CPY_WRT(finished, t0);
		if (zend_is_true(finished)) {
			goto we_1d57_0;
		}
		phalcon_update_property_bool(this_ptr, SL("_finished"), 1 TSRMLS_CC);
		
		PHALCON_INIT_VAR(controller_name);
		phalcon_read_property(&controller_name, this_ptr, SL("_controllerName"), PH_NOISY_CC);
		if (!zend_is_true(controller_name)) {
			PHALCON_INIT_VAR(controller_name);
			phalcon_read_property(&controller_name, this_ptr, SL("_defaultController"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_controllerName"), controller_name TSRMLS_CC);
		}
		
		if (zend_is_true(events_manager)) {
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "dispatch:beforeDispatch", 1);
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", c1, this_ptr, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
			
			PHALCON_INIT_VAR(controller_name);
			phalcon_read_property(&controller_name, this_ptr, SL("_controllerName"), PH_NOISY_CC);
		}
		
		PHALCON_INIT_VAR(camelized_class);
		PHALCON_CALL_STATIC_PARAMS_1(camelized_class, "phalcon\\text", "camelize", controller_name);
		
		PHALCON_INIT_VAR(controller_class);
		PHALCON_CONCAT_VVS(controller_class, default_namespace, camelized_class, "Controller");
		
		PHALCON_INIT_VAR(controller);
		PHALCON_CALL_METHOD_PARAMS_1(controller, dependency_injector, "getshared", controller_class, PH_NO_CHECK);
		if (phalcon_method_exists_ex(controller, SL("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(controller, "initialize", PH_NO_CHECK);
		}
		
		PHALCON_INIT_VAR(action_name);
		phalcon_read_property(&action_name, this_ptr, SL("_actionName"), PH_NOISY_CC);
		if (!zend_is_true(action_name)) {
			PHALCON_INIT_VAR(action_name);
			phalcon_read_property(&action_name, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(params);
		phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(action_method);
		PHALCON_CONCAT_VS(action_method, action_name, "Action");
		if (phalcon_method_exists(controller, action_method TSRMLS_CC) == SUCCESS) {
			if (zend_is_true(events_manager)) {
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, "dispatch:beforeExecuteRoute", 1);
				PHALCON_INIT_VAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", c2, this_ptr, PH_NO_CHECK);
				if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
					PHALCON_INIT_VAR(value);
					ZVAL_BOOL(value, 0);
					goto we_1d57_0;
				}
			}
			
			PHALCON_INIT_VAR(call_object);
			array_init(call_object);
			phalcon_array_append(&call_object, controller, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&call_object, action_method, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_FUNC_PARAMS_2(value, "call_user_func_array", call_object, params);
			if (zend_is_true(events_manager)) {
				PHALCON_INIT_VAR(c3);
				ZVAL_STRING(c3, "dispatch:afterExecuteRoute", 1);
				PHALCON_INIT_VAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", c3, this_ptr, PH_NO_CHECK);
				if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
					PHALCON_INIT_VAR(value);
					ZVAL_BOOL(value, 0);
					goto we_1d57_0;
				}
			}
		} else {
			if (zend_is_true(events_manager)) {
				PHALCON_INIT_VAR(c4);
				ZVAL_STRING(c4, "dispatch:beforeNotFoundAction", 1);
				PHALCON_INIT_VAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", c4, this_ptr, PH_NO_CHECK);
				if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
					PHALCON_INIT_VAR(value);
					ZVAL_BOOL(value, 0);
					goto we_1d57_0;
				}
			}
			if (phalcon_method_exists_ex(controller, SL("notfoundaction") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_VAR(call_object);
				array_init(call_object);
				phalcon_array_append(&call_object, controller, PH_SEPARATE TSRMLS_CC);
				add_next_index_stringl(call_object, SL("notFoundAction"), 1);
				
				PHALCON_INIT_VAR(value);
				PHALCON_CALL_FUNC_PARAMS_2(value, "call_user_func_array", call_object, params);
			} else {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Action '", action_name, "' was not found on controller '", controller_name, "'");
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_throwdispatchexception", exception_message, PH_NO_CHECK);
			}
		}
		
		PHALCON_SEPARATE(number_dispatches);
		increment_function(number_dispatches);
		
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 256);
		
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, t1, number_dispatches TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(c5);
			ZVAL_STRING(c5, "Dispatcher has detected a cyclic routing causing stability problems", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_throwdispatchexception", c5, PH_NO_CHECK);
		}
		
		if (zend_is_true(events_manager)) {
			PHALCON_INIT_VAR(c6);
			ZVAL_STRING(c6, "dispatch:afterDispatch", 1);
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", c6, this_ptr, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
		goto ws_1d57_0;
	we_1d57_0:
	if (zend_is_true(events_manager)) {
		PHALCON_INIT_VAR(c7);
		ZVAL_STRING(c7, "dispatch:afterDispatchLoop", 1);
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", c7, this_ptr, PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	phalcon_update_property_zval(this_ptr, SL("_returnedValue"), value TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_lastController"), controller TSRMLS_CC);
	
	RETURN_CCTOR(controller);
}

/**
 * Throws an internal exception
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException){

	zval *message = NULL, *dependency_injector = NULL, *response = NULL;
	zval *exception = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_dispatcher_exception_ce, "A dependency injection container is required to access the 'response' service");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "response", 1);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD_PARAMS_1(response, dependency_injector, "get", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 404);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "Not Found", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(response, "setstatuscode", c1, c2, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_mvc_dispatcher_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", message, PH_CHECK);
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
}

/**
 * @param array $forward
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, forward){

	zval *forward = NULL, *controller_name = NULL, *action_name = NULL;
	zval *params = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &forward) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(forward) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_dispatcher_exception_ce, "$forward parameter must be an Array");
		return;
	}
	eval_int = phalcon_array_isset_string(forward, SL("controller")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(controller_name);
		phalcon_array_fetch_string(&controller_name, forward, SL("controller"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_controllerName"), controller_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(forward, SL("action")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(action_name);
		phalcon_array_fetch_string(&action_name, forward, SL("action"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(forward, SL("params")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(params);
		phalcon_array_fetch_string(&params, forward, SL("params"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if the dispatch loop is finished or have more pendent controller to disptach
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, isFinished){

	zval *finished = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(finished);
	phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
	
	RETURN_CCTOR(finished);
}

/**
 * Returns the lastest dispatched controller
 *
 * @return Phalcon\Mvc\Controller
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController){

	zval *last_controller = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(last_controller);
	phalcon_read_property(&last_controller, this_ptr, SL("_lastController"), PH_NOISY_CC);
	
	RETURN_CCTOR(last_controller);
}

/**
 * Returns value returned by the lastest dispatched action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getReturnedValue){

	zval *returned_value = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(returned_value);
	phalcon_read_property(&returned_value, this_ptr, SL("_returnedValue"), PH_NOISY_CC);
	
	RETURN_CCTOR(returned_value);
}

