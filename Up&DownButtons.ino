/* EDUCATIONAL PURPOSE
  THE PROGRAM WILL CONTROL 2 PUSH BUTTONS IN WHICH 4 LED LIGHTS WILL COME ON IN COUNTER CLOCKWISE DIRECTION FOR THE 1ST BUTTON
  AND CLOCKWISE DIRECTION FOR THE 2ND BUTTONS.

  NOTE: THE AMOUNT OF LED LIGHTS CAN BE CHANGED AS WELL AS PIN NUMBER.
*/



// declare all variables
const int led[] = {2, 3, 4, 5};

int button1 = 8;
int lastButton1 = 0;
int currentButton1 = 0;
int count = 0;


int button2 = 12;
int lastButton2 = 0;
int currentButton2 = 0;

void setup()
{
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
  // Read state of Button 1
  currentButton1 = digitalRead(button1);
  // check state of Button 1
  if (lastButton1 != currentButton1)
  {
    if (currentButton1 == HIGH)
    {
      // increase the counter until it reaches the amount of LED lights
      count ++;
      if (count > 4)
      {
        count = 1;
        Serial.println(count);

      }
      else
      {
        // do nothing
      }
      delay(50);  // debounce
    }
    lastButton1 = currentButton1;         // set current State for Button 1


    // Read state of Button 2
    currentButton2 = digitalRead(button2);

    if (lastButton2 != currentButton2)
    {
      // check state of Button 2
      if (currentButton2 == HIGH)
      {
        // decrease counter until it reaches 1
        count--;
        if (count < 1)
          count = count + 4;  // counter will be equal to the amount of LEd lights + 1
        Serial.println(count);
      }
      else
      {
        // do nothing
      }
    }
    delay(50); // debounce button

    lastButton2 = currentButton2; // set current State for Button 2


    // Using switch case for counter
    switch (count)
    {
      case 1:
        digitalWrite(led[0], HIGH);    //turn on first LED
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], LOW);
        digitalWrite(led[3], LOW);
        break;
      case 2:
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], HIGH);     //turn on second LED
        digitalWrite(led[2], LOW);
        digitalWrite(led[3], LOW);
        break;
      case 3:
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], HIGH);     //turn on third LED
        digitalWrite(led[3], LOW);
        break;
      case 4:
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], LOW);
        digitalWrite(led[3], HIGH);     //turn on fourth LED
        break;
    }


  }
}
