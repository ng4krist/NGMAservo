#include <Servo.h>
#include <IRremote.h>

Servo myservo;
int RECV_PIN = 12;
long distance, iterate, pauseFloor;
byte playback = 0, playback_direction = 0, record = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;

long IRprevious;
/*
  standby     20DF48B7
  mute        20DF58A7
  front       20DFE01F
  center      20DF10EF
  rear        20DF906F
  surround    20DF50AF
  vcd         20DFD02F
  dvd         20DFF807
  left        20DF807F
  center      20DF7887
  right       20DFC03F
  reset       20DFA05F

  BASS
  up          20DF40BF
  down        20DFC837
  left        20DF30CF
  right       20DF708F
*/

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    if (results.value)
    {
      if (results.value == 0xFFFFFFFF)
      {
        results.value = IRprevious;
      }
      myservo.attach(6);

      if (results.value == 0x20DFA05F)      //reset
      {
        myservo.write(0);
        playback = 0;
      }

      if (results.value == 0x20DF40BF && record != 1)     //UP
      {
        myservo.write(6);
        delay(50);
        myservo.write(0);
      }
      if (results.value == 0x20DFC837 && record != 1)     //DOWN
      {
        myservo.write(180);
        delay(50);
        myservo.write(0);
      }
      if (results.value == 0x20DF48B7 && record != 1)   //STANDBY
      {
        record = 1;
        playback_direction = 0;
        digitalWrite(13, HIGH);
        distance = 0;
      }
      if (results.value == 0x20DF40BF && record == 1)     //UP
      {
        myservo.write(6);
        delay(50);
        myservo.write(0);
        distance--;
        Serial.println(distance);
      }
      if (results.value == 0x20DFC837 && record == 1)     //DOWN
      {
        myservo.write(180);
        delay(50);
        myservo.write(0);
        distance++;
        Serial.println(distance);
      }
      if (results.value == 0x20DF58A7 && record == 1)     //MUTE
      {
        digitalWrite(13, LOW);
        iterate = distance;
        record = 0;
      }

      if (results.value == 0x20DF30CF && record != 1)     //LEFT
      {
        playback = 0;
      }
      if (results.value == 0x20DF708F && record != 1)     //RIGHT
      {
        playback = 1;
      }
      myservo.detach();
      Serial.println(results.value, HEX);
      IRprevious = results.value;
      irrecv.resume();
    }
  }
  loop_eachFloor();
}

