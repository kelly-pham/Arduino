/* EDUCATIONAL PURPOSE
   THIS PROGRAM WILL CONTROL LED LIGHTS BASE ON VALUE READING FROM POTENTIALMETER (AKA "MINI THERMOMETER" ) WHERE VALUE OVER 1000
   WILL LIGHT UP ALL 4 LEDs, OVER 700 WILL LIGHT UP 3 LEDs AND SO ON).
*/

// declare global variable
const int pot = 0;
int value;
int count;
int led[] = {6, 5, 4, 3};
int i;

void setup()
{
  // Set up Output for LED lights
  for (i = 0; i < 4; i += 1)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);
  }
  pinMode(pot, INPUT);
  Serial.begin(9600);

}


void loop()
{

  value = analogRead(pot);        // Read value from analog ranging from 0 - 1023
  Serial.println(value);          // Print out value on monitor
  delay(500);
  for (i = 4; i > 0; i -= 1)
  {
    if (value > 0 && value <= 400)
    {
      digitalWrite(led[0], HIGH);           // turn on 1st LED when value between 0 and 400
    }
    else
    {
      digitalWrite(led[0], LOW);            // if value = 0, no lights on
    }

    if ( value > 400)
    {
      digitalWrite(led[i], HIGH);           // turn on 2 LEDs when value over 400
      digitalWrite(led[0], HIGH);
    }
    else
    {
      digitalWrite(led[i], LOW);
    }

    if (value > 700)
    {
      digitalWrite(led[i], HIGH);         // turn on 3 LEDs when value over 700
      digitalWrite(led[0], HIGH);
    }
    else
    {
      digitalWrite(led[i + 1 ], LOW);
    }

    if ( value > 1000)
    {
      digitalWrite(led[i], HIGH);         // turn on 4 LEDs when value over 1000
      digitalWrite(led[0], HIGH);
    }
    else
    {
      digitalWrite(led[i + 2], LOW);
    }

  }

}

