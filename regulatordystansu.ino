float odleglosc= 0;
float uchyb = 0;
float u = 0;
float k = 0.7;
float aktualna = 0;
float zakladanaOdl = 15;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);// Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);// Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{

  Serial.begin(9600);
}

void loop()
{
  odleglosc = 0.01723 * readUltrasonicDistance(7, 7); //w cm
  uchyb=odleglosc-zakladanaOdl-aktualna;
  u=uchyb*k;
  aktualna = aktualna + u;
  
  Serial.print("Odleglosc od przedmiotu: ");
  Serial.println(odleglosc);
  Serial.print("Aktualna pozycja dzwigni: ");
  Serial.println(aktualna);
  delay(1000);
}