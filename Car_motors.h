// class to controll motors
#include <Arduino.h>

#ifndef CAR_MOTORS_MODULE
#define CAR_MOTORS_MODULE

typedef enum
{
  left    = 2,
  center  = 1,
  right   = 0,
}direction;

const int spining_speed = 240;     //degree per second
const int driving_speed = 80;      //cm per second

class car_motors 
{
  int motor_pins[4];
public:
  car_motors(int pin1, int pin2, int pin3, int pin4);
  void move_forward();
  void stop();
  void move_rightly();
  void move_leftly();
  void move_back();
  void spin (int degree, direction spining_direction);
  void drive(int distance);
};

  car_motors::car_motors(int pin1, int pin2, int pin3, int pin4)
  {
    motor_pins[0] = pin1;
    motor_pins[1] = pin2;
    motor_pins[2] = pin3;
    motor_pins[3] = pin4;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
  }

  void car_motors::move_forward()
  {
    digitalWrite( motor_pins[0], LOW);        
    digitalWrite( motor_pins[1], HIGH);
    digitalWrite( motor_pins[2], LOW);
    digitalWrite( motor_pins[3], HIGH);
  }

  void car_motors::stop()
  {
    digitalWrite( motor_pins[0],LOW );
    digitalWrite( motor_pins[1],LOW );
    digitalWrite( motor_pins[2],LOW );
    digitalWrite( motor_pins[3],LOW );
  }

  void car_motors::move_rightly()
  {
    digitalWrite( motor_pins[0], LOW);
    digitalWrite( motor_pins[1], HIGH);
    digitalWrite( motor_pins[2], HIGH);
    digitalWrite( motor_pins[3], LOW);
  }

  void car_motors::move_leftly()
  {   
    digitalWrite( motor_pins[0], HIGH);     
    digitalWrite( motor_pins[1], LOW);
    digitalWrite( motor_pins[2], LOW);
    digitalWrite( motor_pins[3], HIGH);
  }

  void car_motors::move_back()
  {   
    digitalWrite( motor_pins[0], HIGH);     
    digitalWrite( motor_pins[1], LOW);
    digitalWrite( motor_pins[2], HIGH);
    digitalWrite( motor_pins[3], LOW);
  }

  void car_motors::spin (int degree, direction spining_direction)
  {
    int delay_time;
    delay_time = (degree*1.0)/(spining_speed*1.0)*1000.0;
    if(spining_direction == right)
    {
      move_rightly();
    }else if(spining_direction == left)
    {
      move_leftly();
    }
    delay(delay_time);
    stop();
  }

  void car_motors::drive(int distance)
  {
    int delay_time;
    delay_time = ((distance*1.0)/(driving_speed*1.0))*(1000*1.0);
    move_forward();
    delay(delay_time);
    stop();
  }

#endif