void light_setup() {
    pinMode(LED_PIN, OUTPUT);

}

void light_output(){
    digitalWrite(LED_PIN, sense_status);

}
