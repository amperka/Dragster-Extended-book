#include "Servo.h"

#define BUTTONPIN 9
#define SERVOPIN 6

#define OPENED 160
#define CLOSED 100

Servo barrier;
int state = OPENED;

void setup() {
    barrier.attach(SERVOPIN);
    barrier.write(state);
}

void loop() {
    if (digitalRead(BUTTONPIN) == 0) {
        delay(100);
        if (digitalRead(BUTTONPIN) == 0) {
            for (int i = state;
                (state == OPENED) ? i >= CLOSED : i <= OPENED;
                (state == OPENED) ? i-- : i++) {
                barrier.write(i);
                delay(15);
            }
            state = (state == OPENED) ? CLOSED : OPENED;
        }
    }
}

/*
(3-7) Даём имена пинам кнопки и сервопривода и углам наклона шлагбаума.
(10) Указываем начальное положение шлагбаума.
(18) Проверяем, нажата ли кнопка. Ждём 100 миллисекунд, пока пройдёт «дребезг контактов».
(21-25) Плавно меняем положение шлагбаума на обратное. В цикле for мы использовали тернарные (тройные) условные операторы ()?():(). Тернарные операции устроены просто: (условие) ? выражение 1 : выражение 2. Если условие истинно, выполняется выражение 1, если ложно — выражение 2.
(27) После того как движение закончилось, устанавливаем состояние как текущее.
*/
