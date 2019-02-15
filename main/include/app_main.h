#include "app_camera.h"
#include "app_httpserver.h"
#include "app_wifi.h"

#define VERSION "0.9.0"

#define GPIO_BUTTON     34
#define I2C_SCL_PIN_NUM 22          /*!< gpio number for I2C master clock */
#define I2C_SDA_PIN_NUM 21          /*!< gpio number for I2C master data  */


typedef enum
{
    WAIT_FOR_WAKEUP,
    WAIT_FOR_CONNECT,
    START_DETECT,
    START_RECOGNITION,
    START_ENROLL,
    START_DELETE,

} en_fsm_state;

extern en_fsm_state g_state;
extern int g_is_enrolling;
extern int g_is_deleting;
