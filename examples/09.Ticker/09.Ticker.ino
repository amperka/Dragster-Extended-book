#include "TroykaOLED.h"
TroykaOLED display;

char text[] = "Amperka racing";
int length = strlen(text);
int symbolWidth = 12;
int width = symbolWidth * length;

void setup() {
    display.begin();
    display.setFont(alfabet12x16);
    display.autoUpdate(false);
}

void loop() {
    for (int x = 127; x > -width; x--) {
        display.clearDisplay();
        display.print(text, x, OLED_CENTER);
        display.update();
    }
}

/*
(4) Строка, которую будем выводить.
(5-7) Нам нужно выяснить длину строки в пикселях. Для этого определяем количество символов в строке функцией strlen и умножаем на количество пикселей в одном символе.
(12) Выключаем автообновление, будем управлять обновлением экрана вручную. Это позволит получить более плавную анимацию.
(16) Смещаем точку отрисовки влево на один пиксель.
(19) Рисуем текст на новом месте.
*/
