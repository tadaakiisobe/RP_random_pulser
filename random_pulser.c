#include <stdio.h>
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <wiringPi.h>
#define pin 21

int main (void)
{
  //  double howlongtowait = 1; // 12.5kHz
  //  double howlongtowait = 10; // 200 Hz
  //  double howlongtowait = 100; // 20Hz
  double howlongtowait = 1000; // 1.9Hz

  //  boost::random::random_device RndDev; // seed
  std::size_t seed = 0;
  boost::random::mt19937 RndGen(seed);
  boost::random::uniform_01<double> Uniform01;

  wiringPiSetupGpio () ;
  pinMode (pin, OUTPUT) ;
  int i;
  double a;
  //  for (i=0;i<100;i++)
  for (;;)
    {
      a = Uniform01(RndGen);
      digitalWrite (pin, HIGH) ; //delay (howlongtowait * a) ;
      digitalWrite (pin,  LOW) ; delay (howlongtowait * a) ;
      //      printf("%d %f\n",i,a);
    }
  return 0 ;
}
