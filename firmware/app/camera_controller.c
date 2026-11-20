#include "camera_controller.h"

camera_state_t camera_controller_init(void)
{
    return CAMERA_OFF;
}

camera_state_t camera_controller_update(
    bool enable_requested,
    bool fault_active)
{
    if (fault_active) {
        return CAMERA_OFF;
    }

    if (enable_requested) {
        return CAMERA_ON_COMMANDED;
    }

    return CAMERA_OFF;
}
