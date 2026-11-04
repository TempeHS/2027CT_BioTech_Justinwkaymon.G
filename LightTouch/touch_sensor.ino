
void touch_sensor() {
  s32 ret = mpr121.begin();
  mpr121.set_sensitivity(0x80);
  Serial.print("MPR121 initialisation result: ");
  Serial.println(ret);
}

void receive_data() {
    u16 result = 0;
    u16 filtered_data_buf[CHANNEL_NUM] = {0};
    u8 baseline_buf[CHANNEL_NUM] = {0};

    result = mpr121.check_status_register();
    mpr121.get_filtered_reg_data(&result, filtered_data_buf);

    for (int i = 0; i < CHANNEL_NUM; i++) {
        channelSignal[i] = (result & (1 << i)) ? HIGH : LOW;

        if (channelSignal[i] == HIGH) {
            Serial.print("Channel ");
            Serial.print(i);
            Serial.println(" touched");
            }
            }
          delay(60);
        }


