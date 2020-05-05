#include "sound.h"


Sound::Sound(int pin) {
  _pinNum = pin;
  pinMode(_pinNum, OUTPUT);
  digitalWrite(_pinNum, HIGH);

}

void Sound::melodySound(void) {
  int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };

  int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };
  digitalWrite(3, LOW);
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(_pinNum, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(_pinNum);
    digitalWrite(_pinNum, HIGH);
  }
}
void Sound::beep(long ms) {
  digitalWrite(_pinNum, LOW);
  delay(ms);
  digitalWrite(_pinNum, HIGH);
}

void Sound::phone(void) {
  digitalWrite(_pinNum, LOW);
  for ( int ii = 0; ii < 10; ii++ ) {

    tone(_pinNum, 1000);

    delay(50);

    tone(_pinNum, 500);

    delay(50);

  }

  noTone(_pinNum);
  digitalWrite(_pinNum, HIGH);
}

void Sound::bee(void) {
  const int buzzer = _pinNum;
  digitalWrite(buzzer,HIGH);
  const int toneTable[7][5] = {

    { 66, 131, 262, 523, 1046},  // C Do

    { 74, 147, 294, 587, 1175},  // D Re

    { 83, 165, 330, 659, 1318},  // E Mi

    { 88, 175, 349, 698, 1397},  // F Fa

    { 98, 196, 392, 784, 1568},  // G So

    {110, 220, 440, 880, 1760},  // A La

    {124, 247, 494, 988, 1976}   // B Si

  };

  char toneName[] = "CDEFGAB";

  char beeTone[] = "GEEFDDCDEFGGGGEEFDDCEGGEDDDDDEFEEEEEFGGEEFDDCEGGC";

  char starTone[] = "CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";

  int beeBeat[] = {

    1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2,

    1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4,

    1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2,

    1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4

  };

  int starBeat[] = {

    1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2,

    1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2,

    1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2

  };
  int ii, length, toneNo;
  int duration;
  length = sizeof(beeTone) - 1;

  for ( ii = 0; ii < length; ii++ ) {

    //toneNo = getTone(beeTone[ii]);
    int tonNo = 0;
    for ( int iii=0; iii<7; iii++ ) {

        if ( toneName[iii]==beeTone[ii] ) {

            toneNo = iii;

            break;

        }

    }

    duration = beeBeat[ii] * 333;

    tone(buzzer, toneTable[toneNo][3]);

    delay(duration);

    noTone(buzzer);
    
  } 
  digitalWrite(buzzer,HIGH);
}
