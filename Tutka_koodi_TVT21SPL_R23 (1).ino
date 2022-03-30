#include <LiquidCrystal.h>                                      // Kirjasto LCD-näytön ohjaamiseen.
#include <Servo.h>                                              // Kirjasto servomoottorille.

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;       // Digitaalipinnit LCD näytölle.
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo myServo;                                                  // Servomoottorin muuttuja.
const int trigPin = 10;                                         // Ultraäänianturin trigger-pinni.
const int echoPin = 11;                                         // Ultraäänianturin echo-pinni.
long duration;                                                  // Muuttuja ääniaallon kulkemiseen kestävälle ajalle.
long distance;                                                  // Muuttuja objektin etäisyydelle.
const int summeri = 9;                                          // Summeri pinnissä 9.
int aani=1;                                                     // Muuttuja äänimerkin antamiselle.

int joyX = A1;                                                  // X-akseli. Kun sen arvo on 0, aktivoituu vasemmalle komento. Kun arvo on 1023, aktivoituu oikealle komento.
int joyY = A0;                                                  // Y-akseli. Kun sen arvo on 0, aktivoituu alhaalle komento. Kun arvo on 1023, aktivoituu ylhäälle komento. 
int joyB = 8;                                                   // Napin painallus. Aktivoituu, kun "button" arvo on 0.
int xValue;                                                     // Min 0 max 1023.
int yValue;                                                     // Min 0 max 1023.
int button;                                                     // Normaalisti arvo 1, nappia painaessa 0.

int resetti=1;

void setup() 
{
  lcd.begin(16, 2);                                             // Funktio LCD-näytölle, jonka täytyy olla ennen muita LCD-näytön komentoja.
  pinMode(joyB, INPUT_PULLUP);
  pinMode(joyX,INPUT);
  pinMode(joyY,INPUT);
  pinMode(summeri, OUTPUT);                                     // Määritellään summerin pinni outputiksi.
  pinMode(trigPin, OUTPUT);                                     // Määritellään ultraäänianturin trigger-pinni outputiksi.
  pinMode(echoPin, INPUT);                                      // Määritellään ultraäänianturin echo-pinni inputiksi.
  Serial.begin(19200);
  myServo.attach(12);                                           // Servoon kytketty pinni.
  
  xValue = analogRead(joyX);                                    // Lukee tietoa analog-pinniltä.
  yValue = analogRead(joyY);                                    // --||--
  button = digitalRead(joyB);                                   // --||--

}

void loop() 
{
while(resetti!=0){                                              // Jos resetti on muu kuin 0, pysytään silmukan sisällä.
 
  lcd.clear();                                                  // Tyhjennetään näyttö.
  
  lcd.setCursor(0, 0);                                          // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
  lcd.print("TUTKA");                                           // Tulostetaan teksti näytölle.

  lcd.setCursor(0, 1);                                          // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
  lcd.print("TVT21SPL");                                        // Tulostetaan teksti näytölle.
  
  delay(2000);                                                  // 2 sekunnin viive.
  lcd.clear();                                                  // Tyhjennetään näyttö.
  lcd.setCursor(0, 0);                                          // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
  lcd.print("CREATED BY");                                      // Tulostetaan teksti näytölle.
  lcd.setCursor(0, 1);                                          // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
  lcd.print("FOLLOWING:");                                      // Tulostetaan teksti näytölle.

  delay(2000);                                                  // 2 sekunnin viive.
  lcd.clear();                                                  // Tyhjennetään näyttö.
  lcd.setCursor(0, 0);                                          // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
  lcd.print("ERIKA");                                           // Tulostetaan teksti näytölle.
  lcd.setCursor(0, 1);                                          // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
  lcd.print("KORHONEN");                                        // Tulostetaan teksti näytölle.

  delay(2000);                                                  // 2 sekunnin viive.
  lcd.clear();                                                  // Tyhjennetään näyttö.
  lcd.setCursor(0, 0);                                          // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
  lcd.print("JOHANNES");                                        // Tulostetaan teksti näytölle.
  lcd.setCursor(0, 1);                                          // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
  lcd.print("HUTTUNEN");                                        // Tulostetaan teksti näytölle.
  
  delay(2000);                                                  // 2 sekunnin viive.
  lcd.clear();                                                  // Tyhjennetään näyttö.
  lcd.setCursor(0, 0);                                          // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
  lcd.print("ONNI");                                            // Tulostetaan teksti näytölle.
  lcd.setCursor(0, 1);                                          // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
  lcd.print("HIETANEN");                                        // Tulostetaan teksti näytölle.

  delay(2000);                                                  // 2 sekunnin viive.
  lcd.clear();                                                  // Tyhjennetään näyttö.
  lcd.setCursor(0, 0);                                          // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
  lcd.print("WELCOME TO");                                      // Tulostetaan teksti näytölle.
  lcd.setCursor(0, 1);                                          // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
  lcd.print("MAIN MENU!");                                      // Tulostetaan teksti näytölle.

  delay(2000);                                                  // 2 sekunnin viive.
  valikko();                                                    // Aloitetaan valikko-funktio.
  delay(10);                                                    // 10 millisekunnin viive.
  }
}
/*
Valikko-funktiossa on tarkoitus valita esimerkiksi asetuksien ja ohjelman aloittamisen
väliltä.
*/

void valikko(){                                                 // Funktio valikolle.
  while(resetti!=0)                                             // Valikossa pysytään, kunnes resetti on 0.
  {
    lcd.clear();                                                // Tyhjennetään näyttö.
    lcd.setCursor(0,0);                                         // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
    lcd.print("MAIN MENU");                                     // Tulostetaan teksti näytölle.
    lcd.setCursor(0,1);                                         // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
    lcd.print("START RADAR");                                   // Tulostetaan teksti näytölle.
    
    if(analogRead(joyX) > 1000)                                 // If lause toteutuu jos joystickiä käännetään oikealle.
    {
       while(digitalRead(joyB) == HIGH)                         // Toistorakenne ,joka on tosi, kun joystickiä ei paineta.
       {
        delay(50);                                              // Viive 50ms.
        lcd.clear();                                            // Tyhjennetään näyttö.
        lcd.setCursor(0,0);                                     // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
        lcd.print("RADAR IN");                                  // Tulostetaan teksti näytölle.
        lcd.setCursor(0,1);                                     // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
        lcd.print("ACTION");                                    // Tulostetaan teksti näytölle.
        
        tutka();                                                // Kutsutaan tutka funktio.
       }    
    }
    
    if(analogRead(joyY)<100)                                    // If lause toteutuu jos joystickiä käännetään alas.
    {
      delay(100);                                               // Viive 100ms.
      while(analogRead(joyY)<1000)                              // Toistorakenne joka on tosi kunnes joystickiä käännetään ylös.
      {
        lcd.clear();                                            // Tyhjennetään näyttö.
        lcd.setCursor(0,0);                                     // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
        lcd.print("MAIN MENU");                                 // Tulostetaan teksti näytölle.
        lcd.setCursor(0,1);                                     // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
        lcd.print("MANUAL RADAR");                              // Tulostetaan teksti näytölle.
        
        if(analogRead(joyX)>1000)                               // If lause toteutuu jos joystickiä käännetään oikealle.
        {
          delay(50);                                            // Viive 50ms.
          lcd.clear();                                          // Tyhjennetään näyttö.
          lcd.setCursor(0,0);                                   // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
          lcd.print("MANUAL RADAR");                            // Tulostetaan teksti näytölle.
          lcd.setCursor(0,1);                                   // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
          lcd.print("IN ACTION");                               // Tulostetaan teksti näytölle.
          manuaaliTutka();                                      // Aloittaa manuaalitutkan funktion.
        }
        delay(100);
        if(analogRead(joyY)<100){                              // If lause toteutuu jos joystickiä käännetään alas.
          while(analogRead(joyY)<1000){                        // Toistorakenteessa pysytään kunnes joystickiä käännetään ylös.
            lcd.clear();                                       // Tyhjennetään näyttö.
            lcd.setCursor(0,0);                                // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
            lcd.print("MAIN MENU");                            // Tulostetaan teksti näytölle.
            lcd.setCursor(0,1);                                // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
            lcd.print("SETTINGS");                             // Tulostetaan teksti näytölle.
            delay(100);                                        // Viive 100ms.
            if(analogRead(joyX)>1000){                         // If lause toteutuu jos joystickiä käännetään oikealle.
              asetukset();                                     // Kutsutaan asetukset funktio.
              }
            }
          }
        
        delay(200);                                           // Viive 200ms.
      }
    }

    delay(200);                                               // Viive 200ms.
    }





}
 
void tutka()
{
  for(int i = 15; i <= 165 ; i++)                               // Servo liikkuu aste kerrallaan 15 asteesta 165 asteeseen.
  {  
    
   if(digitalRead(joyB) == LOW)                                 // Jos joystickiä painetaan, lopettaa ohjelman ja avaa valikon.
  {
    valikko();
  }
    
    myServo.write(i);                                           // Lähettää astemäärän servolle.
    delay(30);                                                  // Viive 30 millisekunttia.
    distance = calculateDistance();                             // Kutsuu calculate funktiota, joka laskee etäisyyden.
    delay(40);                                                  // Viive 40 millisekunttia.

    if(aani==1)                                                 // Muuttuja, jota voidaan muokata asetuksista.
    {
    aanimerkki();                                               // Kutsuu aani funktiota, joka tuottaa äänimerkin.
    }
    
    Serial.print(i);                                            // Lähettää tämän hetkisen astemäärän sarjaportille.
    Serial.print(","); 
    Serial.print(distance);                                     // Lähettää etäisyyden lukuarvon sarjaportille.
    Serial.print("."); 
    analogRead(joyX);                                           // Lukee joystickin vaakasuuntaisen arvon.
  }

  for(int i = 165; i > 15; i--)                                 // Muuten sama kuin edellinen, mutta servo liikkuu vastakkaiseen suuntaan.
  {  
    if(digitalRead(joyB) == LOW)
  {
    valikko();
  }
  
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    delay(40);

    
    if(aani==1)
    {
    aanimerkki();                                               
    }
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    analogRead(joyX);
  }
}

int calculateDistance()                                         // Funktio, joka laskee ultraäänianturin mittaaman etäisyyden.
{ 
  digitalWrite(trigPin, LOW);                                   // Trigger-pinni LOW tilassa 2 mikrosekunttia.
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);                                  // Trigger-pinni HIGH tilassa 10 mikrosekuntia.
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);                            // Lukee echo-pinniltä ääniaallon kulkemiseen kestävän ajan mikrosekunteina.
  delay(2);
  distance= duration*0.034/2;                                   // Laskee etäisyyden kuluneen ajan perusteella.
  return distance;                                              // Palauttaa distance int muuttujan funktiosta.
}

int aanimerkki()                                                // Funktio, joka antaa äänimerkin, kun objekti havaitaan.
{
  if(distance > 1 && distance <= 40)                            // Summeri päästää yhtäkestoista ääntää, kun objektin etäisyys on 1 cm ja 40 cm välillä.
  {
    tone(summeri, 200);                                         // Summeri tuottaa ääntä 200 Hz taajuudella.
  }

  else
  {
    noTone(summeri);                                            // Summeri ei tuota ääntä.
  }
}

void manuaaliTutka()                                            // Funktio tutkalle, jota voidaan ohjata manuaalisesti joystickin avulla.
{
  int i=90;                                                     // i muuttuja on kulma.
  
  while(digitalRead(joyB) == HIGH)                              // Kun joystickin nappia ei paineta.
  {
    if(analogRead(joyX) < 100 && i <= 165)                      // Kun joystickia väännetään vasemmalle, tutka liikkuu vasemmalle, kunnes astemäärä on 165 astetta.
    {
      i++;
    }
        
    if(analogRead(joyX) > 1000 && i > 15)                       // Kun joystickia väännetään oikealle, tutka liikkuu oikealle, kunnes astemäärä on 15 astetta.
    {
      i--;
    }
      
    myServo.write(i);                                           // Lähettää astemäärän servolle.
    delay(30);                                                  // Viive 30 millisekunttia.
    distance=calculateDistance();                               // Kutsuu funktiota, joka laskee objektin etäisyyden.
    delay(40);                                                  // Viive 40 millisekunttia.

    if(aani==1)
    {
     aanimerkki();                                              // Kutsuu funktiota, joka tuottaa äänimerkin, kun havaitaan objekti.
    }

    Serial.print(i);                                            // Lähettää astemäärän sarjaportille.
    Serial.print(",");
    Serial.print(distance);                                     // Lähettää objektin etäisyyden sarjaportille.
    Serial.print(".");
 }
}
  
/*
Asetukset funktiossa on tarkoitus pystyä muokkaaamaan asetuksia.
*/

void asetukset(){                                                       // Asetukset funktio missä voidaan vaihtaa kuuluuko ääni vai ei.
  while(analogRead(joyX)>100){                                          // Kunnes joystickiä käännetään vasemmalle toisto on päällä.
        lcd.clear();                                                    // Tyhjennetään näyttö.
        lcd.setCursor(0,0);                                             // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
        lcd.print("SETTINGS");                                          // Tulostetaan teksti näytölle.
        lcd.setCursor(0,1);                                             // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
        lcd.print("SOUNDS");                                            // Tulostetaan teksti näytölle.
        delay(200);                                                     // Viive 200ms.
        if(analogRead(joyX)>1000)
        {
          while(analogRead(joyX)>100)
          {
            lcd.clear();                                                // Tyhjennetään näyttö.
            lcd.setCursor(0,0);                                         // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
            lcd.print("SOUNDS");                                        // Tulostetaan teksti näytölle.
            lcd.setCursor(0,1);                                         // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
            lcd.print("ON");                                            // Tulostetaan teksti näytölle.
            delay(200);                                                 // Viive 200ms.
            if(analogRead(joyX)>1000)                                   // If lauseessa muutetaan aani=1 jolloin ääni kuuluu tutkasta, kun joystickiä käännetään oikealle.
            {
              lcd.clear();                                              // Tyhjennetään näyttö.
              lcd.setCursor(0,0);                                       // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
              lcd.print("SOUNDS");                                      // Tulostetaan teksti näytölle.
              lcd.setCursor(0,1);                                       // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
              lcd.print("ENABLED");                                     // Tulostetaan teksti näytölle.
              aani=1;
              delay(2000);                                              // Viive 2 sekunttia.
            }
            if(analogRead(joyY)<100)                                    // Jos joystickiä käännetään alas niin If lause toteutuu.
            {
              while(analogRead(joyY)<1000 && analogRead(joyX)>100)      // Ollaan nii kauan toistossa kunnes joystickiä käännetään ylös tai vasemmalle.
              {
                lcd.clear();                                            // Tyhjennetään näyttö.
                lcd.setCursor(0,0);                                     // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
                lcd.print("SOUNDS");                                    // Tulostetaan teksti näytölle.
                lcd.setCursor(0,1);                                     // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
                lcd.print("OFF");                                       // Tulostetaan teksti näytölle.
                delay(200);                                             // Viive 200ms.
                if(analogRead(joyX)>1000)                               // Jos joystickiä käännetään oikealle if lause on tosi.
                  {
                    lcd.clear();                                        // Tyhjennetään näyttö.
                    lcd.setCursor(0,0);                                 // Asetetaan näyttö ensimmäiselle merkille ensimmäiselle riville.
                    lcd.print("SOUNDS");                                // Tulostetaan teksti näytölle.
                    lcd.setCursor(0,1);                                 // Asetetaan näyttö ensimmäiselle merkille toisella rivillä.
                    lcd.print("DISABLED");                              // Tulostetaan teksti näytölle.
                    aani=0;
                    delay(2000);                                        // Viive 2 sekunttia.
                }
              }
              delay(200);                                               // Viive 200ms.
            }
          }
        }
  }
}
