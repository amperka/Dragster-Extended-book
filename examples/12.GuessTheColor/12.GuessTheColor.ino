#include "TroykaColorSensor.h"

TroykaColorSensor colorSensor;

void printColor(RGB c) {
    if ((c.red > c.green) && (c.red > c.blue))
        Serial.println("RED");
    if ((c.green > c.red) && (c.green > c.blue))
        Serial.println("GREEN");
    if ((c.blue > c.green) && (c.blue > c.red))
        Serial.println("BLUE");
}

void setup() {
    colorSensor.begin();
    Serial.begin(115200);
}

void loop() {
    analogWrite(13, analogRead(A5) / 4);
    RGB color = colorSensor.colorRead();
    printColor(color);
    delay(100);
}

/*
(5) Функция printColor определяет компонент цвета с наибольшей интенсивностью и выводит результат в монитор порта.
(21-23) Каждые 100 миллисекунд считываем цвета предметов и вызываем функцию printColor.
*/
