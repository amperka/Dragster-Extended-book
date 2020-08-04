#include "TroykaLedMatrix.h"

int left, right;

TroykaLedMatrix matrix;
byte diagram[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

void setup() {
    matrix.begin();
    Serial.begin(115200);
}

void loop() {
    right = analogRead(A0);
    left = analogRead(A3);
    diagram[0] = matrix.map(right, 0, 1023);
    diagram[7] = matrix.map(left, 0, 1023);

    Serial.print(right);
    Serial.print("\t");
    Serial.println(left);

    matrix.drawBitmap(diagram);
    delay(200);
}

/*
(10) Запускаем Serial, чтобы видеть, в каких пределах изменяются значения left и right.
(16-17) Переводим значения датчиков в высоту столбиков матрицы. Используем только левый и правый столбцы для визуализации. Устанавливаем верхнюю границу значений на 1023.
(19-21) Печатаем значения в монитор порта для наглядности.
*/
