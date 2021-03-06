#include "Servo.h"

Servo servo;

void setup() {
    servo.attach(9);
}

void loop() {
    int value = analogRead(A5);
    int angle = map(value, 0, 1023, 0, 180);
    servo.write(angle);
    delay(15);
}

/*
(1) Подключаем библиотеку Servo.h.
(3) Создаём объект для работы с сервоприводом.
(6) С помощью метода attach() передаём номер пина, к которому подключён сервопривод и запускаем его.
(10-11) Считываем положение потенциометра и преобразуем диапазон 0–1023 в диапазон 0–180.
(12) Даём команду сервоприводу установить вал на угол angle.
*/
