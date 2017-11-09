#include<ArduinoSTL.h>
using namespace std;

int speakerPin = 9;
const int capacity = 128;
char notes[3][capacity + 1];
int size = 0;
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

int button1 = 8;
int currentButton1 = 0;
int lastButton1 = 0;
int count1 = 0;

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

void checkButton(int button1)
{
  currentButton1 = digitalRead(button1);
  delay(50);

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
void playMusic(int i)
{
  int count = 0;
  int dash = 0;

  while (notes[i][count])
  {
    if (notes[i][count] != '-')
    {
      if (notes[i][count] == ' ')
      {
        delay(100);
      }
      else
      {
        dash += 1;
        playNote(notes[i][count], 150);
      }
    }
    else
    {
      playNote(notes[i][count - dash], 250);
    }
    count += 1;

  }
}
