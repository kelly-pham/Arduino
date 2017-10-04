const int pot=0;
int led[] = {3, 6, 9, 11};
int count = 0;
int value =0;
int timer1=50;
int timer2=500;
void setup() {
  Serial.begin(9600);
  int i;


  // create output for all led lights
  for (i = 0; i < 4; i += 1)
  {
    pinMode(led[i], OUTPUT);
  }
  pinMode(pot,OUTPUT);
}

void loop()
{
  value= analogRead(pot);
  value=constrain(value,0,1023);
  Serial.println(value);
  if (value >=500 && value <=600)
  {
    digitalWrite(led[0],HIGH);
  }
  else
  {
      count = analogRead(pot);
      count = map(count, 0,1023,0,4);
       count ++;
      if (count > 4)
      {
        count = 1;
  
      }
      else
      {
        // do nothing
      }
     
     
        // decrease counter until it reaches 1
        count--;
        if (count < 1)
        {
          count = count + 4;  // counter will be equal to the amount of LEd lights + 1
        Serial.println(count);
      }
      else
      {
        // do nothing
      }
    
  
 


    // Using switch case for counter
    switch (count)
    {
      case 1:
        digitalWrite(led[0], HIGH);    //turn on first LED
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], LOW);
        digitalWrite(led[3], LOW);
        delay(timer1);
        break;
      case 2:
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], HIGH);     //turn on second LED
        digitalWrite(led[2], LOW);
        digitalWrite(led[3], LOW);
        delay(timer2);
        break;
      case 3:
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], HIGH);     //turn on third LED
        digitalWrite(led[3], LOW);
        delay(timer2);
        break;
      case 4:
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], LOW);
        digitalWrite(led[3], HIGH);     //turn on fourth LED
        delay(timer2);
        break;
    }

  }
  
}
