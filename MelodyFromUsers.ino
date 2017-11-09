/*
 * THIS PROGRAM WILL LET USERS ENTER 3 MELODIES THEY WANT TO PLAY, THEN CONTROL IT WITH THE PUSH BUTTON. 
 * AFTER 3 MELODIES BEING PLAY, IT WILL BE REPEATED 
 * 
 * NOTE: 
 * OPTIONAL - INSTEAD OF LETTING USERS ONLY ENTER MAXIMUM 3 MELODIES, WE CAN LET THE USER ENTER HOW MANY MELODIES THEY WANT TO PLAY 
 * 
 */
 
#include<ArduinoSTL.h>
using namespace std;

// declare global variables
const int speakerPin = 9;
const int capacity = 128;
char notes[3][capacity + 1];
int size = 0;

int button1 = 8;



// Function is using to read the input and check if it larger than desired size, if yes print out "Too large !!"
void read(char str[], int capacity, int &size)
{
  size = 0;
  while (size <= capacity)
  {
    str[size] = cin.get();
    if (str[size] == '\n')
    {
      str[size] = 0;
      size -= 1;
      return;
    }
    size += 1;
  }
  cout << "Too large!!" << endl;
  str[size] = 0;
  size = 0;
}


void setup()
{
  pinMode(speakerPin, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  Serial.begin(9600);


  // Getting input from users ( 3 melodies they want to play)
  cout << "Enter 1st song: " << endl;
  read(notes[0], capacity, size );
  cout << "You entered: " << notes[0] << endl ;

  cout << "Enter 2nd song: " << endl;
  read(notes[1], capacity, size );
  cout << "You entered: " << notes[1] << endl;

  cout << "Enter 3rd song: " << endl;
  read(notes[2], capacity, size );
  cout << "You entered: " << notes[2] << endl;

}
void loop()
{
  // calling checkButton function
  checkButton(button1);
}


void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

// Function will check when user press a push button which will scroll through 3 songs entered earlier
void checkButton(int button1)
{
  int currentButton1 = 0;
  int lastButton1 = 0;
  int count1 = 0;

  
  currentButton1 = digitalRead(button1);   // read the push button 
  delay(50);

  // debounce 
  if (lastButton1 != currentButton1)
  {
    if (currentButton1 == 1)
    {
      count1 += 1;
      Serial.println(count1);
      if (count1 > 3)
      {
        count1 = 0;
      }
      delay(50);
    }
  }
  lastButton1 = currentButton1;

  // Control which song to play depends on how many times user presses the push button 
  switch (count1)
  {
    case 1:
      playMusic(0);
      break;
    case 2:
      playMusic(1);
      break;
    case 3:
      playMusic(2);
      break;
  }
}

// Playing the melodies that containts dash, space( as rest) with a desired duration.
void playMusic(int i)
{
  int count = 0;
  int dash = 0;

  while (notes[i][count])    // when check all character within the string
  {
    if (notes[i][count] != '-')     // if the character is not a dash
    {
      if (notes[i][count] == ' ')    // if the character is a space, have it delay for 100ms ( acting as a rest)
      {
        delay(100);
      }
      else                          // if the character is not a space, increase dash by 1 and play melody in 150ms
      {
        dash += 1;
        playNote(notes[i][count], 150);
      }
    }
    else                        // if the character is a dash, then play a melody
    {
      playNote(notes[i][count - dash], 250);
    }
    count += 1;           // increase count by 1

  }
}
