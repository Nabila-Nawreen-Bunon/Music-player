// C++ code
//
class musicPlayer{
  public:
  musicPlayer(int buzzerPin){
    this->buzzerPin=buzzerPin;
    pinMode(buzzerPin,OUTPUT);
  }
  void playNote(int frequency,int duration){
    tone(buzzerPin,frequency,duration);
    delay(duration*1.30);
  }
  void playMelody(int *notes, int *duration, int length){
    for(int i=0;i<length;i++){
      playNote(notes[i],duration[i]);
    }
  }
  void setVolume(int volumePin){
    int sensorValue=analogRead(volumePin);
    volume=map(sensorValue,0,1023,0,255);
    analogWrite(3,volume);
  }
  private:
  int buzzerPin;
  int volume;
};
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
int melody[]={ NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5};
int noteDurations[]={4,4,4,4,4,4,4,4};
musicPlayer myPlayer(8);

void setup()
{
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);
}

void loop()
{
  myPlayer.setVolume(A0);
  int melodyLength=sizeof(melody)/sizeof(melody[0]);
  myPlayer.playMelody(melody,noteDurations,melodyLength);
  delay(2000);
}
  
 
