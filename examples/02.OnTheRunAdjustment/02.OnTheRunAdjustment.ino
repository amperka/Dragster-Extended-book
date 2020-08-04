#include "Dragster.h"
#include "Octoliner.h"
#include "PID_dragster.h"

Dragster robot(MMAX_16_OHM);

Octoliner octoliner;
int lineData[8];

double output;
PID regulator(&output, 0.0, 0.0, 0.0);

void setup() {
    robot.begin();
    octoliner.begin();
    octoliner.setSensitivity(208);
}

void loop() {
    float kp = analogRead(A4) / 1023.0 * 1.0;
    float kd = analogRead(A5) / 1023.0 * 0.2;
    float speed = analogRead(A11) / 1023.0 * 1.0;

    regulator.SetTunings(kp, 0, kd);

    for (int i = 0; i < 8; i++) {
        lineData[i] = octoliner.analogRead(i);
    }
    float difference = octoliner.mapLine(lineData);

    regulator.compute(difference);

    robot.driveF(speed - output, speed + output);
}

/*
(11) Устанавливаем все коэффициенты ПИД-регулятора «в ноль».
(14) Не забудь скорректировать направление вращения колёс, как в предыдущей главе, если это необходимо.
(16) Здесь и в дальнейшем указывай в команде octoliner.setSensitivity() значение полученное при калибровке (эксперимент 16 из первой части набора «Драгстер»).
(20-22) Пропорциональный коэффициент kp настраиваем потенциометром на пине A4 в диапазоне 0.0–1.0. Дифференциальный kd — на пине A5 в диапазоне 0.0–0.2. Скорость speed определяем от 0 до 1.
(24) Обновляем коэффициенты ПИД-регулятора.
*/
