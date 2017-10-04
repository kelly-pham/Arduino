
/*
 * RUNNING LEDs IN CLOck-WISE OR COUNTERC CLOCK-WISE DIRECTION, CONTROLLED BY POTENTIONMETER (POT)  
 */
// declare global variables 

const int pot=0;
int led []= {3,5,6,10};
int i;
int value;
int timer;
int rate;

int count1;

void setup()
{
  Serial.begin(9600);
  for (i=0;i < 4; i +=1)
    {
      pinMode(led[i],OUTPUT);
      }
  pinMode(pot,OUTPUT);
  rate=500;           
  }

void loop()
{
  value=analogRead(pot); 
  Serial.println(value);
  if (value == 0)                         // Turn on 1st LEd when pot value = 0
    {
      digitalWrite(led[0],HIGH);
      digitalWrite(led[1],LOW);
      digitalWrite(led[2],LOW);
      digitalWrite(led[3],LOW);
                  
      }
   else if (value >= 570 )            // When value greater or equal than 570, LEDs will be iluminated in clock-wise direction    
   {
    if (value >=1000)
    {
      timer = 100;                    // set a different rate when value exceeds 1000
      }
      else
      timer = 1000;                   // default rate
    count1 ++;
    if (count1 >4)
      {
        count1 = 1;
        Serial.println(count1);
        
      }
    else
      {
        // do nothing
        }
        delay (timer);
       
   }
   else if (value <570)             // When value smaller than 570, LEds will be illuminated in counter clock-wise direction
   {
    if (value < 200)
      {
        timer = 100;              // set different rate when value too small
        }
    else
    timer = 1000;                 // default rate
    count1--;
      if (count1 < 1)
      {
        count1= count1 +4;     // counter will be equal to the amount of LEd lights + 1
      Serial.println(count1);
      
      }
     else 
      {
       // do nothing
        }
        delay(timer);
    } 
       
  


   switch (count1)
  {
    case 1:
      digitalWrite(led[0],HIGH);     //turn on first LED
      digitalWrite(led[1],LOW);       
      digitalWrite(led[2],LOW);
      digitalWrite(led[3],LOW);
      break;
   case 2:
      digitalWrite(led[0],LOW);
      digitalWrite(led[1],HIGH);      //turn on second LED
      digitalWrite(led[2],LOW);
      digitalWrite(led[3],LOW);
      break;
   case 3:
      digitalWrite(led[0],LOW);
      digitalWrite(led[1],LOW);
      digitalWrite(led[2],HIGH);      //turn on third LED
      digitalWrite(led[3],LOW);
      break;
   case 4:
      digitalWrite(led[0],LOW);
      digitalWrite(led[1],LOW);
      digitalWrite(led[2],LOW);
      digitalWrite(led[3],HIGH);      //turn on fourth LED
      break; 
    }

 
}

