int kierunek1 = 5;
int kierunek2 = 6;
int btnprawo = 9;
int btnlewo = 10;
int predkosc = 7;
int start = 11;


bool obecny = LOW;
bool poprzedni = LOW;
bool ponownyOdczyt = LOW;
bool wlaczony = LOW; 

int ilestartow = 0; 

void setup()
{
  pinMode(kierunek1, OUTPUT);
  pinMode(kierunek2, OUTPUT);
  pinMode(btnprawo, INPUT);
  pinMode(btnlewo, INPUT);
  pinMode(predkosc, OUTPUT);
  pinMode(start, INPUT); 
  
  digitalWrite(kierunek1, LOW);
  digitalWrite(kierunek2, LOW);
  
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(predkosc, HIGH);
  obecny = digitalRead(start);
  if(obecny != poprzedni)
  {
    delay(15);
    ponownyOdczyt = digitalRead(start);
    if(ponownyOdczyt == obecny && obecny == HIGH)
    {
      wlaczony = !wlaczony; 
      if(wlaczony == HIGH)
      {
        ilestartow++;
        Serial.print("Liczba startow programu: ");
        Serial.print(ilestartow);
        Serial.print("\n");
      }
    }
    poprzedni= obecny;
  }
  if(wlaczony == HIGH)
  {
    if(digitalRead(btnlewo) == HIGH)
    {
      digitalWrite(kierunek1, HIGH);
      digitalWrite(kierunek2, LOW);
    }
    else if(digitalRead(btnprawo) == HIGH)
    {
      digitalWrite(kierunek1,LOW);
      digitalWrite(kierunek2,HIGH);
    }
    else
    {
      digitalWrite(kierunek1,LOW);
      digitalWrite(kierunek2,LOW);
    }
  }
}