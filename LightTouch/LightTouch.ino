#include "Seeed_MPR121_driver.h"

Mpr121 mpr121;
bool sense_status = false;
u16 touch_status_flag[CHANNEL_NUM] = {0};

void setup(){
  Serial.begin(115200);
  touch_sensor();

}

void loop(){
  receive_data();

}
