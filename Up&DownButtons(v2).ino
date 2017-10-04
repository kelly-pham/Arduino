
/* EDUCATIONAL PURPOSE
  THE PROGRAM WILL CONTROL 2 PUSH BUTTONS IN WHICH 4 LED LIGHTS WILL COME ON IN COUNTER CLOCKWISE DIRECTION FOR THE 1ST BUTTON
  AND CLOCKWISE DIRECTION FOR THE 2ND BUTTONS.

  NOTE: 1)THE AMOUNT OF LED LIGHTS CAN BE CHANGED AS WELL AS PIN NUMBER.
        2) MODULE % EXPRESSION SERVES SAME PURPOSE AS SWITCH STATEMENT.
        3) OPTIONAL: FADING LEDs EITHER FROM DARK TO BRIGHT OR VICE VERSA.
*/


//declare global variables

int button1 = 8;
int button2 = 12;

int currentButton1 = 0;
int lastButton1 = 0;

int currentButton2 = 0;
int lastButton2 = 0;

int led[] = {3, 5, 6, 9};
int count = 0;

void setup() {
  Serial.begin(9600);
  int i;


  // create output for all led lights
  for (i = 0; i < 4; i += 1)
  {
    pinMode(led[i], OUTPUT);
  }

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop()
{
  currentButton1 = digitalRead(button1);      // READ CURRENT STATE OF BUTTON 1
  currentButton2 = digitalRead(button2);      // READ CURRENT STATE OF BUTTON 2
  delay(50);

  if (currentButton1 != lastButton1)     // TOGGLE BUTTON 1
  {
    if (currentButton1 == 1)
    {

      // COUNT VALUE WILL GO FROM 0 TO 3
      if (count != -1)
      {
        digitalWrite(led[0] + count, LOW);
      }
      count = count + 1;
      count = count % 4;
      Serial.println(count);        // CHECK COUNT VALUE ON MONITOR
      digitalWrite(led[0] + count, HIGH);

      /* OPTIONAL: Fading LEDs FROM DARK TO BRIGHT
        for (int value = 0; value <= 255; value += 1)
         {
          analogWrite(led[0] + count, value);
          Serial.println( count);    // CHECK VALUE OF COUNT ON MONITOR
           Serial.println(value);
          }
      */
    }

  }
  lastButton1 = currentButton1;


  if (currentButton2 != lastButton2)     // TOGGLE BUTTON 2
  {
    if (currentButton2 == 1)
    {

      // COUNT VALUE WILL GO FROM 3 TO 0
      if (count != -1)
      {
        digitalWrite(led[0] + count, LOW);
      }
      count = count + 3;
      count = count % 4;
      Serial.println(count);      // CHECK COUNT VALUE OF MONITOR
      digitalWrite(led[0] + count, HIGH);

      /* OPTIONAL: FADING LEDs FROM BRIGHT TO DARK
        for (int value = 255; value >= 0; value -= 1)
         {
        analogWrite(led[0] + count, value);
        Serial.println( count);
        Serial.println(value);
          }
      */
    }

  }
  lastButton2 = currentButton2;

}
