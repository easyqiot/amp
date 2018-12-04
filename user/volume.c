
#include <c_types.h>
#include <user_interface.h>
//#include <osapi.h>
#include <ets_sys.h>

#include "debug.h"

//#define VOLUME_MAX	1380
#define VOLUME_MAX  1576	
#define VOLUME_MIN	0
#define VOLUME_SAVE_DELAY	1000
#define VOLUME_PRIVATE_PARAM_SECTOR	0x7c


LOCAL ETSTimer save_timer;


struct volume_status {
	uint16_t current;
};


struct volume_status status;


void save_timer_func(void *arg) {
	bool ok = system_param_save_with_protect(VOLUME_PRIVATE_PARAM_SECTOR, 
			&status, sizeof(status));
	if (!ok) {
		ERROR("Cannot save volume\r\n");
	}
}

void volume_save() {
	os_timer_disarm(&save_timer);
	os_timer_arm(&save_timer, VOLUME_SAVE_DELAY, 0);
}


void volume_restore() {
	bool ok = system_param_load(VOLUME_PRIVATE_PARAM_SECTOR, 0,
			&status, sizeof(status));
	if (!ok) {
		status.current = 0;
		volume_save();
	}
}


void volume_shutdown() {
	motor_stop();
}


uint16_t volume_get() {
	return status.current;
}


uint16_t volume_set_current(uint16_t v) {
	status.current = v;
	volume_save();
}

void volume_set(uint16_t v) { 
	if (v < VOLUME_MIN || v > VOLUME_MAX) {
		return;
	}
	os_timer_disarm(&save_timer);
	int pos = (v - status.current) * 8;
	status.current = v;
	motor_rotate(pos);
}


void volume_increase(uint16_t v) { 
	volume_set(status.current + v);
}


void volume_init() {
	motor_set_stop_callback(volume_save);
	volume_restore();
	motor_init();

	os_timer_disarm(&save_timer);
	os_timer_setfn(&save_timer, (os_timer_func_t *) save_timer_func, 0);
}

