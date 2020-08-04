#include "TroykaColorSensor.h"

typedef enum {
    RED = 0, GREEN = 1, BLUE = 2, OTHER = 3
} ColorComponent;

TroykaColorSensor colorSensor;
int colors[4] = { 0, 0, 0, 0 };
int totalCount = 0;

int colorIs(RGB c) {
    if ((c.red > c.green) && (c.red > c.blue)) return RED;
    else if ((c.green > c.red) && (c.green > c.blue)) return GREEN;
    else if ((c.blue > c.green) && (c.blue > c.red)) return BLUE;
    else return OTHER;
}

void setup() {
    colorSensor.begin();
    Serial.begin(115200);
}

void loop() {
    analogWrite(13, analogRead(A5) / 4);
    if (digitalRead(10) == 0) {
        totalCount++;
        ColorComponent answer = colorIs(colorSensor.colorRead());
        colors[answer] += 1;
        Serial.println(totalCount);
        delay(500);
    }
    if (totalCount == 10) {
        Serial.print("Red: ");
        Serial.println(colors[RED]);
        Serial.print("Green: ");
        Serial.println(colors[GREEN]);
        Serial.print("Blue: ");
        Serial.println(colors[BLUE]);
        Serial.print("Other: ");
        Serial.println(colors[OTHER]);
        totalCount = 0;
        colors[0] = colors[1] = colors[2] = colors[3] = 0;
    }
}

/*
(3) Enum — это специальный «перечислимый» тип данных. Он отслеживает правильное использование констант, объявленных внутри него, тем самым упрощая отладку. Typedef — способ создания собственных типов данных, обычно используется для сокращения записи.
(4) Каждому цвету присваиваем число, чтобы было удобнее работать с массивом colors. OTHER — это цвет, не имеющий единственного преобладающего компонента.
(8-9) В переменной totalCount храним общее число попыток, а в массиве colors — число предметов каждого цвета.
(25) По нажатии кнопки USER BTN (10) увеличиваем счётчик попыток на 1 и считываем цвет предмета перед датчиком.
(27) Определяем компонент цвета с наибольшей интенсивностью. Функция colorIs вернёт номер цвета, и он запишется в переменную answer. Увеличиваем счётчик этого компонента на 1.
(32) Как только число попыток достигнет 10, выводим в монитор порта количество всех предметов каждого цвета.
*/
