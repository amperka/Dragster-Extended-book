#include "TroykaProximity.h"

TroykaProximity sensor;

void setup() {
    sensor.begin();
    Serial.begin(115200);
}

void loop() {
    int range = sensor.readRange();

    if (range >= 150) {
            Serial.println("Out of range");
    } 
    else {
            Serial.println(range);
    }
    delay(200);
}

/*
(3) Объявляем переменную для работы с датчиком.
(11) Считываем расстояние в миллиметрах функцией readRange.
(13) Результат больше 150 означает, что объектов вблизи датчика нет.
*/
