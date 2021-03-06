
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Queue\Beanstalk\Job
 *
 * Represents a job in a beanstalk queue
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk_Job) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Beanstalk, Job, phalcon, queue_beanstalk_job, phalcon_queue_beanstalk_job_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_queue_beanstalk_job_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_queue_beanstalk_job_ce, SL("_body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_queue_beanstalk_job_ce, SL("_queue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_id");

}

/**
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_body");

}

/**
 * Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __construct) {

	zval id;
	zval *queue, queue_sub, *id_param = NULL, *body, body_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&id);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &queue, &id_param, &body);

	zephir_get_strval(&id, id_param);


	zephir_update_property_zval(this_ptr, SL("_queue"), queue);
	zephir_update_property_zval(this_ptr, SL("_id"), &id);
	zephir_update_property_zval(this_ptr, SL("_body"), body);
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes a job from the server entirely
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, delete) {

	zval queue, _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&queue);
	zephir_read_property(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "delete ", &_0);
	ZEPHIR_CALL_METHOD(NULL, &queue, "write", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &queue, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, &_2, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk/job.zep", 55 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_3, "DELETED"));

}

/**
 * The release command puts a reserved job back into the ready queue (and marks
 * its state as "ready") to be run by any client. It is normally used when the job
 * fails because of a transitory error.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, release) {

	zval *priority_param = NULL, *delay_param = NULL, queue, _0, _1, _2, _3, _4, _5;
	zend_long priority, delay, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &priority_param, &delay_param);

	if (!priority_param) {
		priority = 100;
	} else {
		priority = zephir_get_intval(priority_param);
	}
	if (!delay_param) {
		delay = 0;
	} else {
		delay = zephir_get_intval(delay_param);
	}


	ZEPHIR_OBS_VAR(&queue);
	zephir_read_property(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, priority);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, delay);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSVSV(&_3, "release ", &_0, " ", &_1, " ", &_2);
	ZEPHIR_CALL_METHOD(NULL, &queue, "write", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &queue, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_5, &_4, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk/job.zep", 69 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_5, "RELEASED"));

}

/**
 * The bury command puts a job into the "buried" state. Buried jobs are put into
 * a FIFO linked list and will not be touched by the server again until a client
 * kicks them with the "kick" command.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, bury) {

	zval *priority_param = NULL, queue, _0, _1, _2, _3, _4;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &priority_param);

	if (!priority_param) {
		priority = 100;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_OBS_VAR(&queue);
	zephir_read_property(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, priority);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSV(&_2, "bury ", &_0, " ", &_1);
	ZEPHIR_CALL_METHOD(NULL, &queue, "write", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &queue, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk/job.zep", 83 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_4, "BURIED"));

}

/**
 * The `touch` command allows a worker to request more time to work on a job.
 * This is useful for jobs that potentially take a long time, but you still
 * want the benefits of a TTR pulling a job away from an unresponsive worker.
 * A worker may periodically tell the server that it's still alive and processing
 * a job (e.g. it may do this on `DEADLINE_SOON`). The command postpones the auto
 * release of a reserved job until TTR seconds from when the command is issued.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, touch) {

	zval queue, _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&queue);
	zephir_read_property(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "touch ", &_0);
	ZEPHIR_CALL_METHOD(NULL, &queue, "write", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &queue, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, &_2, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk/job.zep", 100 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_3, "TOUCHED"));

}

/**
 * Move the job to the ready queue if it is delayed or buried.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, kick) {

	zval queue, _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&queue);
	zephir_read_property(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "kick-job ", &_0);
	ZEPHIR_CALL_METHOD(NULL, &queue, "write", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &queue, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, &_2, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk/job.zep", 112 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_3, "KICKED"));

}

/**
 * Gives statistical information about the specified job if it exists.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, stats) {

	zval queue, response, _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&queue);
	zephir_read_property(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "stats-job ", &_0);
	ZEPHIR_CALL_METHOD(NULL, &queue, "write", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &queue, "readyaml", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk/job.zep", 126 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(&_2, "NOT_FOUND")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_3, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk/job.zep", 130 TSRMLS_CC);
	RETURN_CTOR(&_3);

}

/**
 * Checks if the job has been modified after unserializing the object
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __wakeup) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_id"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_beanstalk_exception_ce, "Unexpected inconsistency in Phalcon\\Queue\\Beanstalk\\Job::__wakeup() - possible break-in attempt!", "phalcon/queue/beanstalk/job.zep", 141);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

