#include "TroykaColorSensor.h"

TroykaColorSensor colorSensor;

void setup() {
    colorSensor.begin();
    Serial.begin(115200);
}

void loop() {
    analogWrite(13, analogRead(A5) / 4);

    RGB color = colorSensor.colorRead();

    Serial.print(color.red);
    Serial.print('\t');
    Serial.print(color.green);
    Serial.print('\t');
    Serial.println(color.blue);

    delay(100);
}

/*
(1) Подключаем библиотеку датчика цвета.
(3) Объявляем переменную colorSensor для работы с датчиком.
(11) Регулируем ШИМ управления подсветкой с помощью потенциометра в пине A5. Значение функции делим на 4, чтобы сократить диапазон 0–1023 до 0–255. Результат останется достаточно точным для работы.
(13) Считываем интенсивность цветов.
*/
