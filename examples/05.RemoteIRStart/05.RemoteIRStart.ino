#include "Dragster.h"
#include "Octoliner.h"
#include "PID_dragster.h"

Dragster robot(MMAX_16_OHM);

Octoliner octoliner;
int lineData[8];
float speed = 0.35;
float kp = 0.5;
float kd = 0.02;
double output;
PID regulator(&output, kp, 0, kd);

void setup() {
    robot.begin();
    octoliner.begin();
    octoliner.setSensitivity(208);
    while (digitalRead(11) == 1) {
        delay(10);
    }
}

void loop() {
    for (int i = 0; i < 8; i++) {
        lineData[i] = octoliner.analogRead(i);
    }
    double difference = octoliner.mapLine(lineData);
    regulator.compute(difference);
    robot.driveF(speed - output, speed + output);
}

/*
(19) Цикл while повторяется раз за разом, пока условие внутри скобок истинно. Выражение в скобках означает «пока нет ИК-сигнала». Как только приёмник получит сигнал от пульта, цикл while прекратится и Драгстер устремится вперёд.
*/
