#include "TroykaOLED.h"
TroykaOLED display;

void setup() {
    display.begin();
}

void loop() {
    display.setFont(digits24x40);
    for (int i = 5; i > 0; i--) {
        display.clearDisplay();
        display.print(i, OLED_CENTER, OLED_CENTER);
        delay(1000);
    }

    display.clearDisplay();
    display.setFont(alfabet12x16);
    display.print("Hi, racer!", OLED_CENTER, OLED_CENTER);
    delay(2000);
}

/*
(1) Подключаем библиотеки TroykaOLED.h для работы с OLED-дисплеем.
(5) Запускаем дисплей.
(9-14) Рисуем обратный отсчет. OLED_CENTER — константа библиотеки с координатами центра экрана по осям x и y.
(9) Задаем шрифт для цифр.
(10) Реализуем обратный отсчёт от 5 до 1 с помощью цикла.
(11) Чистим экран.
(12) Рисуем очередную цифру в центре экрана.
(16-19) Рисуем текст "Hi, racer".
(17) Задаем шрифт для букв.
*/
