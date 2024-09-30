#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#define sensor1 A0
#define sensor2 A1
#define led_puser A2
#define Led_Warning A4
#define B_puser A5

int ledState = LOW;            //הבהוב בלי דיילי
unsigned long previousMillis = 0;       
const long interval = 1000;

int buttonState = 0;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int moisture = 0;
int time=7;
byte degree[8] =
{
0b00011,
0b00011,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000
};
void setup()
  {
  lcd.begin(16,2);
  lcd.createChar(1, degree);

  lcd.setCursor(4,0);
  lcd.print("Welcome!");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("The temperature");
  lcd.setCursor(0,1);
  lcd.print("   in tami 8 ");
  delay(2000);
  lcd.clear();
  
  Serial.begin(9600);
  pinMode(Led_Warning, OUTPUT);
  pinMode(B_puser, INPUT);
  pinMode(led_puser, OUTPUT);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
 
}
void loop()
{ 
                                              //בחירת מצבים
    buttonState = digitalRead(4);
    buttonState1 = digitalRead(5);
    buttonState2 = digitalRead(6);
    buttonState3 = digitalRead(7);
    // delay(100);
       if(buttonState3 == HIGH)
       {
         lcd.clear();
           lcd.print(" Please select");
             lcd.setCursor(3,1);
             lcd.print("a cup size");
         while(buttonState1 == LOW && buttonState == LOW && buttonState2 == LOW)
         {
           /*lcd.clear();
           lcd.print(" Please select");
             lcd.setCursor(3,1);
             lcd.print("a cup size");*/
          
            buttonState = digitalRead(4);
            buttonState1 = digitalRead(5);
            buttonState2 = digitalRead(6);
           // delay(300);
           if(buttonState==HIGH)
           {
             lcd.clear();
             time=3;
             lcd.print("You chose a size");
             lcd.setCursor(3,1);
             lcd.print("  4s cup");
             delay(2000);
             lcd.clear();
           }
           if(buttonState1==HIGH)
           {
             lcd.clear();
             time=7;
             lcd.print("You chose a size");
             lcd.setCursor(3,1);
             lcd.print("  8s cup");
             delay(2000);
             lcd.clear();
           }

           if(buttonState2==HIGH)
           {
             lcd.clear();
             time=14;
             lcd.print("You chose a size");
             lcd.setCursor(3,1);
             lcd.print("  15s cup");
             delay(2000);
             lcd.clear();
           }
         }
         buttonState = 0;
         buttonState1 = 0;
         buttonState2 = 0;
       } 
  /*---------Temperature-------*/
  float reading1=analogRead(sensor1);//חמים
  float temperatureWarm=reading1*(5.0/1023.0)*100-49.78;

 buttonState = digitalRead(4);
    buttonState1 = digitalRead(5);
    buttonState2 = digitalRead(6);
    buttonState3 = digitalRead(7);
  
   float reading2=analogRead(sensor2);// קרים
  float temperatureCold=reading2*(5.0/1023.0)*100-49.78;

  /*------Display Result------*/
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("warm");
  lcd.setCursor(10,0);
  lcd.print("cold");
  lcd.setCursor(0,1);
  lcd.print(temperatureWarm);
  lcd.write(1);
  lcd.print("C");
  lcd.setCursor(9,1);
  lcd.print(temperatureCold);
  lcd.write(1);
  lcd.print("C");
   //Serial.println(sensor1);
    
   /* if(temperatureWarm <= 50 )//בקרת חמים
    {
     digitalWrite(2, HIGH);
    }
       else
      {
         digitalWrite(2, LOW);
      }*/

    /* if( temperatureCold >= 10 )               //בקרת קירור
    {
     digitalWrite(3, HIGH);
    }
       else
      {
         digitalWrite(3, LOW);
      }*/
  
    buttonState = digitalRead(4);
    buttonState1 = digitalRead(5);
    buttonState2 = digitalRead(6);
    buttonState3 = digitalRead(7);
  
    buttonState = digitalRead(4);             //כפתור רתיחה ובקרה חמים
     if (buttonState == HIGH || temperatureWarm <= 50)
     {
       while(temperatureWarm < 90)
       {
         delay(300);
          /*if( temperatureCold >= 10 )               //בקרת קירור
           {
           digitalWrite(3, HIGH);
           }
          else
           {
           digitalWrite(3, LOW);
           }*/
              unsigned long currentMillis = millis();
            if (currentMillis - previousMillis >= interval)//הבהוב בלי דיילי
            {
                 previousMillis = currentMillis;
                if (ledState == LOW) {
                  ledState = HIGH;
                } else {
                  ledState = LOW;
                }
                digitalWrite(2, ledState);
              }
                  // קריאה והדפסה מחדש
              reading1=analogRead(sensor1);
           temperatureWarm=reading1*(5.0/1023.0)*100-49.78;


            reading2=analogRead(sensor2);
           temperatureCold=reading2*(5.0/1023.0)*100-49.78;

          /*------Display Result------*/
          lcd.clear();
          lcd.setCursor(2,0);
          lcd.print("warm");
          lcd.setCursor(10,0);
          lcd.print("cold");
          lcd.setCursor(0,1);
          lcd.print(temperatureWarm);
          lcd.write(1);
          lcd.print("C");
          lcd.setCursor(9,1);
          lcd.print(temperatureCold);
          lcd.write(1);
          lcd.print("C");
          buttonState2 = digitalRead(6);
          buttonState3 = digitalRead(7);
      
         if( buttonState2 == HIGH  )//מזיגה מים קרים תוך כדי רתיחה
         {
        
         buttonState=0;
         buttonState1=0;
         buttonState2=0;
         buttonState3=0;
         buttonState4=0;
         digitalWrite(3, HIGH);

        for(int i=0; i<time+1;i++)
       {
          unsigned long currentMillis = millis();
          if (currentMillis - previousMillis >= interval)//הבהוב בלי דיילי
            {
                 previousMillis = currentMillis;
                if (ledState == LOW) {
                  ledState = HIGH;
                } else {
                  ledState = LOW;
                }
                digitalWrite(2, ledState);
              }
          
             lcd.clear();
             lcd.print("The time to fill");
             lcd.setCursor(0,1);
             lcd.print("your cup is ->");
             lcd.print(time-i+1);
             delay(1000);
         if(buttonState1 == HIGH || buttonState == HIGH || buttonState2 == HIGH || buttonState3 == HIGH || buttonState4 == HIGH)
           break;
         buttonState = digitalRead(4);
         buttonState1 = digitalRead(5);
         buttonState2 = digitalRead(6);
         buttonState3 = digitalRead(7);
         buttonState4 = digitalRead(B_puser);
       } 
           lcd.clear();
           lcd.print("      Enjoy   ");
           buttonState = 0;
           buttonState1 = 0;
           buttonState2 = 0;
           buttonState3=0;
           buttonState4=0;
           digitalWrite(3, LOW);
           delay(500);
         }
         
         if(  buttonState3 == HIGH )//לחיצה תוך כדי רתיחה
         {
             lcd.clear();
             lcd.print(" Please select");
             lcd.setCursor(3,1);
             lcd.print("a cup size");
           while(buttonState1 == LOW && buttonState == LOW && buttonState2 == LOW)
         {
             unsigned long currentMillis = millis();
            if (currentMillis - previousMillis >= interval)//הבהוב בלי דיילי
            {
                 previousMillis = currentMillis;
                if (ledState == LOW) {
                  ledState = HIGH;
                } else {
                  ledState = LOW;
                }
                digitalWrite(2, ledState);
              }
             
            buttonState = digitalRead(4);
            buttonState1 = digitalRead(5);
            buttonState2 = digitalRead(6);
           if(buttonState==HIGH)
           {
             lcd.clear();
             time=3;
             lcd.print("You chose a size");
             lcd.setCursor(3,1);
             lcd.print("  4s cup");
             delay(2000);
             lcd.clear();
           }
           if(buttonState1==HIGH)
           {
             lcd.clear();
             time=7;
             lcd.print("You chose a size");
             lcd.setCursor(3,1);
             lcd.print("  8s cup");
             delay(2000);
             lcd.clear();
           }

           if(buttonState2==HIGH)
           {
             lcd.clear();
             time=14;
             lcd.print("You chose a size");
             lcd.setCursor(3,1);
             lcd.print("  15s cup");
             delay(2000);
             lcd.clear();
           }
         }
          buttonState = 0;
         buttonState1 = 0;
         buttonState2 = 0;
        }
       }
       digitalWrite(2, LOW);
     }
    buttonState = digitalRead(4);
    buttonState1 = digitalRead(5);
    buttonState2 = digitalRead(6);
    buttonState3 = digitalRead(7);
  
    buttonState1 = digitalRead(5);           //כפתור מזיגה חמים
     if (buttonState1 == HIGH && temperatureWarm >= 90 )
     {
       buttonState=0;
       buttonState1=0;
       buttonState2=0;
       buttonState3=0;
       buttonState4=0;
        digitalWrite(2, HIGH);
       for(int i=0; i<time+1;i++)
       {
         
             lcd.clear();
             lcd.print("The time to fill");
             lcd.setCursor(0,1);
             lcd.print("your cup is ->");
             lcd.print(time-i+1);
         
              delay(1000);
         
           if(buttonState1 == HIGH || buttonState == HIGH || buttonState2 == HIGH || buttonState3 == HIGH || buttonState4 == HIGH)
           {
             break;
           }
             buttonState = digitalRead(4);
             buttonState1 = digitalRead(5);
             buttonState2 = digitalRead(6);
             buttonState3 = digitalRead(7);
             buttonState4 = digitalRead(B_puser);
        }
           lcd.clear();
           lcd.print("      Enjoy   ");
           buttonState =  0;
           buttonState1 = 0;
           buttonState2 = 0;
           buttonState3 = 0;
           buttonState4 = 0;
           digitalWrite(2, LOW);
           delay(500);
     }
    buttonState = digitalRead(4);
    buttonState1 = digitalRead(5);
    buttonState2 = digitalRead(6);
    buttonState3 = digitalRead(7);
  
     buttonState2 = digitalRead(6);          //כפתור מזיגה קרים
     if (buttonState2 == HIGH )
     {
       buttonState=0;
       buttonState1=0;
       buttonState2=0;
        buttonState3=0;
        buttonState4=0;
       digitalWrite(3, HIGH);
      for(int i=0; i<time+1;i++)
       {
             lcd.clear();
             lcd.print("The time to fill");
             lcd.setCursor(0,1);
             lcd.print("your cup is ->");
             lcd.print(time-i+1);
             delay(1000);
         
        if(buttonState1 == HIGH || buttonState == HIGH || buttonState2 == HIGH || buttonState3 == HIGH || buttonState4 == HIGH)
           break;
         buttonState = digitalRead(4);
         buttonState1 = digitalRead(5);
         buttonState2 = digitalRead(6);
         buttonState3 = digitalRead(7);
         buttonState4 = digitalRead(B_puser);
       } 
           lcd.clear();
           lcd.print("      Enjoy   ");
           buttonState = 0;
           buttonState1 = 0;
           buttonState2 = 0;
           buttonState3=0;
           buttonState4=0;
           digitalWrite(3, LOW);
          
     }
          buttonState = digitalRead(4);
          buttonState1 = digitalRead(5);
          buttonState2 = digitalRead(6);
  		  buttonState3 = digitalRead(7);
  
                                        //לד אזהרה מים נשפכים
    
    delay(10); // Wait for 10 millisecond(s)
    moisture = analogRead(A3);
    Serial.println(moisture);
    if (moisture > 800)
    {
            digitalWrite(Led_Warning, HIGH);
    }
    else {
            digitalWrite(Led_Warning, LOW);
         }

        buttonState = digitalRead(4);
    buttonState1 = digitalRead(5);
    buttonState2 = digitalRead(6);
    buttonState3 = digitalRead(7);
                                              // מים פושרים
     buttonState4 = digitalRead(B_puser);
    // delay(100);
     if (buttonState4 == HIGH )
     {
       digitalWrite(led_puser, HIGH);
       digitalWrite(2, HIGH);
       delay(1000);
       digitalWrite(2, LOW);
       digitalWrite(3, HIGH);
       delay(3000);
       digitalWrite(3, LOW);
       digitalWrite(led_puser, LOW);
     }
    else
    {
      digitalWrite(led_puser, LOW);
       delay(100);
    }

    buttonState = digitalRead(4);
    buttonState1 = digitalRead(5);
    buttonState2 = digitalRead(6);
    buttonState3 = digitalRead(7);
  
  delay(1000);
}