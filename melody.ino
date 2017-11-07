#include<ArduinoSTL.h>
using namespace std;

int speakerPin = 9;
const int capacity = 128;
char notes[capacity + 1];
int size = 0;

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
  Serial.begin(9600);
  cout << "Enter a melody you like: " << endl;
  read(notes, capacity, size );
  cout << "You entered: " << notes;

  int count = 0;
  int dash = 0;
  while (notes[count])
  {
    if (notes[count] != '-')
    {
      if (notes[count] == ' ')
      {
        delay(100);
      }
      else
      {
        dash += 1;
        playNote(notes[count], 150);
      }
    }
    else
    {
      playNote(notes[count - dash], 150);
    }
    count += 1;
  }

}


void loop()
{
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
