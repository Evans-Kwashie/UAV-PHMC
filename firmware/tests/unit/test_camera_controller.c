#include "camera_controller.h"
#include "test_assert.h"

int main (void)
{

    ASSERT_EQ_INT(CAMERA_OFF, camera_controller_init());
    ASSERT_EQ_INT(CAMERA_ON_COMMANDED, camera_controller_update(true, false));
    ASSERT_EQ_INT(CAMERA_OFF, camera_controller_update(false, false));
    ASSERT_EQ_INT(CAMERA_OFF, camera_controller_update(true, true));
    ASSERT_EQ_INT(CAMERA_OFF, camera_controller_update(false, true));

    return 0;
}
