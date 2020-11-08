int a;
int b;
int etap=0;
String rodzaj;
void setup()
{
  Serial.begin(8000);
  Serial.println("Kalkulator");
}
bool check(int x)
{
  if(abs(x)>=100)
  {
    Serial.println("Tylko liczby dwucyfrowe :(");
    etap=0;
    return true;
  }
  return false;
}
void loop()
{
  if(!etap)
  {
    etap++;
    Serial.println("Podaj pierwszą liczbę działania");
  }
  if (Serial.available())
  {
    delay(100);
    while (Serial.available()>0)
   {
      if(etap==1)
      {
        etap++;
        String s=Serial.readStringUntil('\n');
        a=s.toInt();
        if(check(a)) break;
        Serial.println("Wybierz rodzaj działania:\n1.Dodawanie\n2.Odejmowanie\n3.Mnożenie\n4.Dzielenie");
      }
      else if(etap==2)
      {
        etap++;
        String s1=Serial.readStringUntil('\n');
        rodzaj=s1.toInt();
        if(check(rodzaj))break;
        Serial.println("Podaj drugą liczbę działania");
      }
      else if(etap==3)
      {
        etap=0;
        String s2=Serial.readStringUntil('\n');
        b=s2.toInt();
        if(check(b))break;
        if(!(rodzaj>=1 && rodzaj<=4))
        {
          Serial.println("Nie wybrano prawidłowego działania :(");
          etap=0;
          break;
        }
        Serial.println("Wynik to:");
        if(rodzaj==1) Serial.print(a+b);
        else if(rodzaj==2) Serial.print(a-b);
        else if(rodzaj==3) Serial.print(a*b);
        else if(rodzaj==4) Serial.print(a/b);
       }
    }
  }