#include "TroykaOLED.h"
#include "TroykaColorSensor.h"

typedef enum {
    RED = 0, GREEN = 1, BLUE = 2,OTHER = 3 
} ColorComponent;

TroykaColorSensor colorSensor;
int colors[4] = { 0, 0, 0, 0 };
int totalCount = 0;
TroykaOLED display;

int colorIs(RGB c) {
    if ((c.red > c.green) && (c.red > c.blue)) return RED;
    else if ((c.green > c.red) && (c.green > c.blue)) return GREEN;
    else if ((c.blue > c.green) && (c.blue > c.red)) return BLUE;
    else return OTHER;
}

void setup() {
    colorSensor.begin();
    display.begin();
    display.clearDisplay();
}

void loop() {
    analogWrite(13, analogRead(A5) / 4);
    if (digitalRead(10) == 0) {
        totalCount++;
        ColorComponent answer = colorIs(colorSensor.colorRead());
        colors[answer] += 1;
        display.setFont(alfabet12x16);
        display.clearDisplay();
        display.print(totalCount, OLED_CENTER, OLED_CENTER);
        delay(500);
    }
    if (totalCount == 10) {
        display.clearDisplay();
        display.setFont(alfabet6x8);
        display.print("Red: ", 0, 0); display.print(colors[RED], 40, 0);
        display.print("Green: ", 0, 10); display.print(colors[GREEN], 40, 10);
        display.print("Blue: ", 0, 20); display.print(colors[BLUE], 40, 20);
        display.print("Other: ", 0, 30); display.print(colors[OTHER], 40, 30);
        totalCount = 0;
        colors[0] = colors[1] = colors[2] = colors[3] = 0;
        delay(5000);
    }
}

/*
(1 and 11) Добавляем в код строчки для работы OLED-дисплея.
(32 and 34) Вместо вывода в Serial указываем display, выбираем шрифт, а также добавляем очистку экрана, устанавливаем курсор в центр экрана и печатаем цифру.
(40-43) То же самое проделываем для печати результата.
*/
