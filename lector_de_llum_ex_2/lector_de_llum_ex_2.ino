/**********************************************************************************
**                                                                               **
**                              Lector de Llum                                   **
**                                                                               **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************

//********** Variables ************************************************************
const int ldr0 = A0;         // donar nom al pin A0 de l’Arduino
const int ldr1 = A1;         // donar nom al pin A1 de l’Arduino
const int ldr2 = A2;         // donar nom al pin A2 de l’Arduino
const int led0 = 9;          // donar nom al pin 9 de l’Arduino
const int led1 = 10;          // donar nom al pin 10 de l’Arduino
const int led2 = 11;          // donar nom al pin 11 de l’Arduino

int valLdr0, valLdr1, valLdr2;     // per guardar valors del ldrs
//********** Setup ****************************************************************
void setup()
{
  Serial.begin(9600);
  pinMode(led0, OUTPUT);     // definir el pin 9 com una sortida
   pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

//********** Loop *****************************************************************
void loop()
{
  valLdr0 = analogRead(ldr0);   // llegir valor ldr0
  valLdr1 = analogRead(ldr1);   // llegir valor ldr1
  valLdr2 = analogRead(ldr2);   // llegir valor ldr2
 
  if (valLdr0 < 90)
  {
    valLdr0 = 255;
  }
  else if (valLdr0 > 580)
  {
    valLdr0 = 0;
  }
  else
  {
    
    valLdr0 = map(valLdr0, 90, 580, 255, 0);   // mapejar valor de 0-1023 a 0-255
     
  }
  analogWrite(led0, valLdr0);    // actualitzar l'estat del led
 
  Serial.println(valLdr2);
  if (valLdr1 < 210)
  {
    valLdr1 = 0;
     }
  else if (valLdr1 > 580)
  {
    valLdr1 = 0;
  }
  
  else
  {
    valLdr1 = map(valLdr1, 210, 580, 255, 0);   // mapejar valor de 0-1023 a 0-255
     
  }
  analogWrite(led1, valLdr1);    // actualitzar l'estat del led
   
  if (valLdr2 < 400)
  {
    //Serial.println(valLdr2);
    valLdr2 = 0;
  }
    else if (valLdr2 > 780)
  {
    valLdr2 = 0;
  }
  else
  {
    valLdr2 = map(valLdr2, 400, 780, 255, 0);   // mapejar valor de 0-1023 a 0-255
     
  }
  analogWrite(led2, valLdr2);    // actualitzar l'estat del led
 
}

//********** Funcions *************************************************************

