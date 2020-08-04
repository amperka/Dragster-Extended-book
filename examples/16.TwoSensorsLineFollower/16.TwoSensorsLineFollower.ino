#include "Dragster.h"
#include "PID_dragster.h"
#include "TroykaLedMatrix.h"

int left, right;

Dragster robot(MMAX_16_OHM);

TroykaLedMatrix matrix;
byte diagram[8];
float kp = 0.3;
float kd = 0.3;
float speed = 0.25;
double output;
PID regulator(&output, kp, 0.02, kd);

void setup() {
    robot.begin();
    matrix.begin();
}

void loop() {
    right = analogRead(A0);
    diagram[0] = matrix.map(right, 0, 1023);
    left = analogRead(A3);
    diagram[7] = matrix.map(left, 0, 1023);
    matrix.drawBitmap(diagram);
    float difference = (right - left) / 1023.0;
    regulator.compute(difference);
    robot.driveF(speed - output, speed + output);
}

/*
(28) Определяем ошибку регулирования через разность двух значений датчиков.
*/
