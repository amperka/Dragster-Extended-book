#include "Dragster.h"
#include "PID_dragster.h"

#define TRIGPIN 8
#define ECHOPIN 9

Dragster robot(MMAX_16_OHM);
double output;
PID regulator(&output, 0.5, 0.1, 0.02);

void setup() {
    pinMode(TRIGPIN, OUTPUT);
    pinMode(ECHOPIN, INPUT);
    robot.begin();
    regulator.setOutputLimits(-0.2, 0.2);
}

void loop() {
    digitalWrite(TRIGPIN, HIGH);
    delayMicroseconds(5);
    digitalWrite(TRIGPIN, LOW);

    long duration = pulseIn(ECHOPIN, HIGH, 1800);

    if (duration == 0) {
        robot.driveF(0, 0);
    } else {
        double distance = 0.34 * duration / 2.0;
        double difference = (100 - distance) / 100.0;
        regulator.compute(difference);
        robot.driveF(output, output);
    }
}

/*
(9) Настраиваем коэффициенты ПИД-регулятора.
(15) Ограничиваем пределы регулирования, чтобы Драгстер не делал резких «шумовых» движений, которые могут возникнуть из-за погрешности измерения дальности.
(23) Функция pulseIn() принимает и третий параметр: timeout. Это время, через которое функция перестаёт ждать эхо и досрочно возвращает значение 0. Ждём эха 1800 микросекунд. Если ответа нет, значит на расстоянии 60 см перед Драгстером ничего нет. Отключаем двигатели.
(29) Вычисляем ошибку регулирования и применяем её в расчётах скорости колёс.
*/
