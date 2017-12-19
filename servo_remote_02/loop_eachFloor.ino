void loop_eachFloor()
{
  if (playback == 1 && record != 1)  //record != 1
  {
    Serial.print("p ");
    Serial.print(iterate);
    if (distance < 0)
    {
      pauseFloor = abs(distance / 5);
      if (iterate >= distance && playback_direction == 1)
      {
        myservo.attach(6);
        myservo.write(6);
        delay(50);
        myservo.write(0);
        iterate--;
        if (iterate % pauseFloor == 0)
          delay(5000);
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
        if (iterate % pauseFloor == 0)
          delay(5000);
        myservo.detach();
      }
      else
      {
        playback_direction = 1;
      }
    }


    else
    {
      pauseFloor = abs(distance / 5);
      if (iterate <= distance && playback_direction == 1)
      {
        myservo.attach(6);
        myservo.write(180);
        delay(50);
        myservo.write(0);
        iterate++;
        if (iterate % pauseFloor == 0)
          delay(5000);
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
        if (iterate % pauseFloor == 0)
          delay(5000);
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
