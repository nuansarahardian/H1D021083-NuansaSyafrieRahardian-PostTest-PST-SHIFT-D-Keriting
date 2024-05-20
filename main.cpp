#include <Arduino.h>
#include <Servo.h>

int trigPin = D1;
int echoPin = D2;
int servoPin = D4;

long duration;
long distance;
Servo myservo;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myservo.attach(servoPin);
    myservo.write(0); // Set posisi awal servo ke 0 derajat
}

void loop()
{
    // Kirim sinyal trigger ke sensor jarak
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Baca waktu pantulan sinyal
    duration = pulseIn(echoPin, HIGH);

    // Hitung jarak (dalam cm)
    distance = (duration * 0.034) / 2;

    // Kontrol servo berdasarkan jarak
    if (distance > 0 && distance <= 50)
    {
        myservo.write(90); // Putar servo ke 180 derajat
    }
    else
    {
        myservo.write(0); // Kembalikan servo ke posisi 0 derajat
    }

    delay(1000); // Tunggu 1 detik sebelum pengukuran berikutnya
}
