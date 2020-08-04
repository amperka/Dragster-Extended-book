#include "QuadDisplay2.h"
#include "TroykaProximity.h"

#define DISTANCE 130

TroykaProximity proximity;
QuadDisplay quad(6);

long startTime = 0;
bool startRace = false;

void setup() {
  quad.begin();
  proximity.begin();
  quad.displayFloat(0, 2);
  while (proximity.readRange() >= DISTANCE);
}

void loop() {
  if (proximity.readRange() < DISTANCE) {
    delay(50);
    if (proximity.readRange() < DISTANCE) {
      startTime = millis();
      if (startRace == true) {
        delay(2000);
      } else {
        startRace = true;
      }
    }
  }
  float lapTime = millis() - startTime;
  quad.displayFloat(lapTime / 1000.0, 2);
}

/*
(1) Подключаем библиотеку QuadDisplay2.
(4) Задаём порог срабатывания датчика.
(9-10) Объявляем переменную startTime для работы со временем и startRace — флаг, с помощью которого мы отследим начало гонки.
(15-16) Перед началом гонки выводим на дисплей 0 и ждем первого проезда.
(20) Получаем показания датчика. Если перед датчиком ничего нет, readRange() возвращает максимальное значение — 255.
(21) Устраняем «дребезг» датчика.
(23-28) Засекаем системное время, затем проверяем началась ли уже гонка или нет. Если это не первый круг — 2 секунды показываем результат круга.
(31-32) Выводим текущее время круга — разность между текущим временем и стартовым. Миллисекунды превращаем в секунды.
*/
