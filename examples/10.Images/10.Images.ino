#include "TroykaOLED.h"

TroykaOLED display;

const byte PROGMEM logo[] = {
    11, 16,
    0x88, 0x50, 0x20, 0x8e, 0x51, 0x51, 0x51, 0x8e, 0x20, 0x50, 0x88,
    0x0f, 0x10, 0x27, 0x48, 0x50, 0x50, 0x50, 0x48, 0x27, 0x10, 0x0f
};

int position = 60;
int direction = 1;

void setup() {
    display.begin();
    display.autoUpdate(false);
}

void loop() {
    display.clearDisplay();
    display.drawImage(logo, position, OLED_CENTER);
    display.update();

    position += direction;

    if ((position > 115) || (position < 3)) {
        direction *= -1;
    }
}

/*
(5-9) Задаём массив пикселей изображения.
(6) Размеры картинки в пикселях — ширина и высота.
(11-12) Положение по оси x в начальный момент — примерно в центре, и направление движения — слева-направо.
(21) Рисуем изображение в указанных координатах.
(24) Смещаем координату отрисовки на один пиксель.
(26-28) При приближении картинки к краям экрана меняем направление движения.
*/
