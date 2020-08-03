#define INFRAREDPIN 3
#define REDPIN 6
#define YELLOWPIN 10
#define GREENPIN 9

void light(byte pin, int ms) {
    digitalWrite(pin, HIGH);
    delay(ms);
    digitalWrite(pin, LOW);
}

void light(byte pin1, byte pin2, int ms) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    delay(ms);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}

void blinked(byte pin, int ms) {
    for (byte i = 0; i < 4; i++) {
        light(pin, ms);
        delay(ms);
    }
}

void setup() {
    pinMode(INFRAREDPIN, OUTPUT);
    pinMode(REDPIN, OUTPUT);
    pinMode(YELLOWPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
}

void loop() {
    light(REDPIN, 4000);
    light(REDPIN, YELLOWPIN, 2000);
    noTone(INFRAREDPIN);
    light(GREENPIN, 2000);
    blinked(GREENPIN, 250);
    tone(INFRAREDPIN, 38000);
    light(YELLOWPIN, 3000);
}

/*
(1-4) Объявим пины светодиодов светофора.
(6) Функция включения одного светодиода на указанное время.
(12) Функция включения двух светодиодов на указанное время.
(20) Функция мигающего включения светодиода с указанным периодом мигания.
(34-41) Стандартный порядок сигналов светофора: красный, красный с жёлтым, инфракрасная команда «поехали», зелёный, зелёный (мигающий), инфракрасная команда «стоп», жёлтый.
*/
