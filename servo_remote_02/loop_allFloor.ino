void loop_allFloor()
{
  if (playback == 1 && record != 0) //record != 1
  {
    Serial.print("p ");
    Serial.print(iterate);
    if (distance < 0)
    {
      if (iterate >= distance && playback_direction == 1)
      {
        myservo.attach(6);
        myservo.write(6);
        delay(50);
        myservo.write(0);
        iterate--;
        myservo.detach();
      }
      else
      {
        playback_direction = 0;
      }
      if (iterate <= 0 && playback_direction == 0)
      {
        myservo.attach(6);
        myservo.write(180);
        delay(50);
        myservo.write(0);
        iterate++;
        myservo.detach();
      }
      else
      {
        playback_direction = 1;
      }
    }


    else
    {
      if (iterate <= distance && playback_direction == 1)
      {
        myservo.attach(6);
        myservo.write(180);
        delay(50);
        myservo.write(0);
        iterate++;
        myservo.detach();
      }
      else
      {
        playback_direction = 0;
      }
      if (iterate >= 0 && playback_direction == 0)
      {
        myservo.attach(6);
        myservo.write(6);
        delay(50);
        myservo.write(0);
        iterate--;
        myservo.detach();
      }
      else
      {
        playback_direction = 1;
      }
    }
    Serial.println();
  }
}
