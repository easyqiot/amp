
#include <c_types.h>

//#define VOLUME_MAX	1380
#define VOLUME_MAX  1576	
#define VOLUME_MIN	0


LOCAL uint16_t volume_current;


void volume_save(uint16_t v) {
}


void volume_shutdown() {
	motor_stop();
	volume_save(volume_current);
}


uint16_t volume_get() {
	return volume_current;
}


uint16_t volume_set_current(uint16_t v) {
	volume_current = v;
}

void volume_set(uint16_t v) { 
	if (v < VOLUME_MIN || v > VOLUME_MAX) {
		return;
	}
	motor_rotate((v - volume_current) * 8);
	volume_current = v;
	volume_save(v);
}


void volume_increase(uint16_t v) { 
	volume_set(volume_current + v);
}


void volume_init() {
	motor_init();
}


