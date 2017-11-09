#include<ArduinoSTL.h>
using namespace std;

const int RLED = 8;
const int BLED = 9;
const int GLED = 10;

//#defind COMMON_ANODE
class Color
{
  public:
  int red;
  int blue;
  int green;

  Color()
  {
    }
// initiate construction
  Color(int red, int blue, int green)
  {
    red = 0;
   blue = 0;
    green = 0;
    }

    
// deconstruction 
  ~Color()
   {
    // do nothing
    }
    
  void display()
  {
    #ifdef COMMON_ANODE
    red = 255 - red;
    blue = 255 - blue;
    green = 255 - green;
    #endif 

    analogWrite(RLED,red);
    analogWrite(BLED,blue);
    analogWrite(GLED,green);
    
    }

  };


void setup() 
{
  pinMode(RLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);

  Color Stop(255,0,0);
  Stop.display();
  delay(1000);

  Color Yellow(255,50,0);
  Yellow.display();
  delay(1000);
  
  Color Go(0,255,0);
  Go.display();
  delay(1000);
}

void loop() 
{
  // do nothing 

}
