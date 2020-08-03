#include "Dragster.h"
#include "Octoliner.h"
#include "PID_dragster.h"
#include "TroykaLedMatrix.h"

Dragster robot(MMAX_16_OHM);

Octoliner octoliner;
int lineData[8];
TroykaLedMatrix matrix;
byte diagram[8];
byte sensitivity;
float speed = 0.2;
double output;
PID regulator(&output, 0.5, 0, 0.02);

void setup() {
    robot.begin();
    octoliner.begin();
    octoliner.setSensitivity(208);
    matrix.begin();
    Serial.begin(115200);
}

void loop() {
    for (int i = 0; i < 8; i++) {
        lineData[i] = 1023 - octoliner.analogRead(i);
        diagram[i] = matrix.map(lineData[i], 0, 1023);
    }

    matrix.drawBitmap(diagram);
    regulator.compute(octoliner.mapLine(lineData));
    robot.driveF(speed - output, speed + output);
}

/*
(15) Воспользуемся значениями коэффициентов и скорости из предыдущих экспериментов.
(28) Инвертируем значения датчиков, чтобы формула поиска линии осталась верной.
*/
