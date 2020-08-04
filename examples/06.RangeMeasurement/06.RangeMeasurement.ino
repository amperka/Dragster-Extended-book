#define TRIGPIN 8
#define ECHOPIN 9

void setup() {
    pinMode(TRIGPIN, OUTPUT);
    pinMode(ECHOPIN, INPUT);
    Serial.begin(115200);
}

void loop() {
    digitalWrite(TRIGPIN, HIGH);
    delayMicroseconds(5);
    digitalWrite(TRIGPIN, LOW);

    unsigned long duration = pulseIn(ECHOPIN, HIGH);
    float distance = 0.345 * duration / 2;

    Serial.print(distance);
    Serial.println("mm");

    delay(100);
}

/*
(1-2)  Пины триггера и эха называем понятными именами вместо чисел.
(11-13) Подаём короткий импульс для запуска сигнала. delayMicroseconds сделает задержку в 5 микросекунд между двумя командами digitalWrite.
(15-16) Как только импульс вернётся на приёмник дальномера, он подаст значение LOW на пин ECHOPIN. Функцией pulseIn замеряем время между отправкой сигнала HIGH передатчиком и получением отражённого сигнала приёмником и вычисляем расстояние до препятствия в миллиметрах.
(18-19) Выводим расстояние до объекта в монитор порта.
*/
