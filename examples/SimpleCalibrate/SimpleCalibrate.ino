int black;
int white;
int rawVal;
int calibrated;

void setup(){
    Serial.begin(9600);
    pinMode(3,INPUT_PULLUP);

    while(digitalRead(3));
    white = analogRead(A0);
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);

    while(digitalRead(3));
    black = analogRead(A0);
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);

}

void loop(){
    rawVal = analogRead(A0);
    calibrated = map(rawVal,white,black,0,1000);
    Serial.println(calibrated);
}