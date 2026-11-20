#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include <stdbool.h>

typedef enum {
    CAMERA_OFF = 0,
    CAMERA_ON_COMMANDED
}   camera_state_t;

camera_state_t camera_controller_init(void);

camera_state_t camera_controller_update(
    bool enable_requested,
    bool fault_active);

#endif
