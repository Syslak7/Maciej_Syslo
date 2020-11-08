float a;
float b;
char dzialanie;
void setup()
{
  Serial.begin(9600);
}

void czekaj()
{
  while(!Serial.available())
  {
  }
}
void loop()
{
  Serial.print("Podaj pierwsza liczbe dzialania: ");
  czekaj();
  a = Serial.parseFloat();
  Serial.print(a);
  Serial.print("\nPodaj druga liczbe dzialania: ");
  czekaj();
  b = Serial.parseFloat();
  Serial.print(b);
  Serial.print("\nPodaj rodzaj dzialania (+,-,*,/) ");
  czekaj();
  dzialanie = Serial.read();
  Serial.print(dzialanie);
  switch(dzialanie)
  {
    case('+'):
    Serial.print("\nWynik to: ");
    Serial.print(a+b);
    Serial.print("\n");
    break;
    
    case('-'):
    Serial.print("\nWynik to: ");
    Serial.print(a-b);
    Serial.print("\n");
    break;
   
    case('*'):
    Serial.print("\nWynik to: ");
    Serial.print(a*b);
    Serial.print("\n");
    break;
    
    case('/'):
    if(b!=0)
    {
      Serial.print("\nWynik to: ");
      Serial.print(a/b);
      Serial.print("\n");
    }
    else Serial.print("\nNie mozna dzielic przez zero!\n");
    break;
    default:Serial.print("\nWybrano bledne dzialanie!\n");
    break;
  }
}