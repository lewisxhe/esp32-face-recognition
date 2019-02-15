/* ESPRESSIF MIT License
 *
 * Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "app_main.h"
#include "esp_partition.h"
#include "ssd1306.h"

en_fsm_state g_state = WAIT_FOR_WAKEUP;
int g_is_enrolling = 0;
int g_is_deleting = 0;

void app_main()
{
    ssd1306_setFixedFont(ssd1306xled_font6x8);

    /*
    *   default use I2C_NUM_1
    *   SDA --> 21
    *   SCL --> 22
    */
    ssd1306_128x64_i2c_init();
    ssd1306_flipHorizontal(1);
    ssd1306_flipVertical(1);

    ssd1306_clearScreen();
    ssd1306_printFixedN(64/2-8, 28, "esp-who", STYLE_ITALIC, FONT_SIZE_2X);
    vTaskDelay(30 / portTICK_PERIOD_MS);
    ESP_LOGI("esp-eye", "Version "VERSION);
    app_wifi_init();
    app_camera_init();
    app_httpserver_init();
    ESP_LOGI("esp-eye", "Version "VERSION" success");
}
