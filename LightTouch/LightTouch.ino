#include "Seeed_MPR121_driver.h"

Mpr121 mpr121;
bool sense_status = False
u16 touch_status_flag[CHANNEL_NUM] = {0};
void setup() {
    s32 ret = 0;
    Serial.begin(115200);
    mpr121.set_sensitivity(0x60);       //change the sensitivity of the touch sensor//
    delay(100);
}
void loop() {
    u16 result = 0;
    u16 filtered_data_buf[CHANNEL_NUM] = {0};
    u8 baseline_buf[CHANNEL_NUM] = {0};

    result = mpr121.check_status_register();

    mpr121.get_filtered_reg_data(&result, filtered_data_buf);

    for (int i = 0; i < CHANNEL_NUM; i++) {
        if (result & (1 << i)) {                      /*key i is pressed!!*/
            if (0 == touch_status_flag[i]) {
                touch_status_flag[i] = 1;
                sense_status = true
            }
        } else {
            if (1 == touch_status_flag[i]) {
                touch_status_flag[i] = 0;
                sense_status = false
            }
        }
    }
    delay(50);
  serialprint(sense_status);
}
