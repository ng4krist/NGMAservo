void position_manually()
{
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
}

