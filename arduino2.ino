#include <LiquidCrystal.h>
// Reciever
char mystr[20]; //Initialized variable to store recieved data
char resp[20];
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
}
 
void loop()
{
  if(Serial.available() > 0){
    Serial.readBytes(mystr,11);
    lcd.setCursor(0, 0);
    if(mystr[0] == 'R'){
      lcd.print(mystr);
      delay(1000);
    }
  }
 
 delay(300);
 
 lcd.clear();
}