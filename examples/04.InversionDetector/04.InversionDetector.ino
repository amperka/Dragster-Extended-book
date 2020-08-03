#include "Dragster.h"
#include "Octoliner.h"
#include "PID_dragster.h"
#include "TroykaLedMatrix.h"

Dragster robot(MMAX_16_OHM);

Octoliner octoliner;
int lineData[8];

TroykaLedMatrix matrix;
byte diagram[8];
float speed = 0.2;
double output;
PID regulator(&output, 0.5, 0, 0.02);

void setup() {
    robot.begin();
    octoliner.begin();
    octoliner.setSensitivity(208);
    matrix.begin();
}

void loop() {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        lineData[i] = octoliner.analogRead(i);
        sum += lineData[i];
        diagram[i] = matrix.map(lineData[i], 0, 1023);
    }
    matrix.drawBitmap(diagram);
    if (sum > 511 * 8) {
        for (int i = 0; i < 8; i++) {
            lineData[i] = 1023 - lineData[i];
        }
    }
    float error = octoliner.mapLine(lineData);

    regulator.compute(error);
    robot.driveF(speed - output, speed + output);
}

/*
(25) Накапливаем в переменной sum сумму отражённого света, собранного всеми датчиками
(27) Предполагаем, что Драгстер едет по белому полю с чёрной линией.
(33-35) Если sum получилась больше половины от максимума, перезаписываем каждое значение массива lineData для белой линии на чёрном поле.
*/
