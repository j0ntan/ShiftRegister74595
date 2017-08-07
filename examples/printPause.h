void printPauseMessage() {
    Serial.print("Check the shift register output pins.\n");
    Serial.print("Enter something to continue.\n\n");

    while(!Serial.available());

    while(Serial.available())
        Serial.read();
}
