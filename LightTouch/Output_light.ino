void light_setup() {
    pinMode(LED_PIN, OUTPUT);

}

void light_output(){
    int anyTouched = LOW;

    for (int i = 0; i < CHANNEL_NUM; i++) {
        if (channelSignal[i] == HIGH) {
            anyTouched = HIGH;
        }
    }
    digitalWrite(LED_PIN, anyTouched);

}
