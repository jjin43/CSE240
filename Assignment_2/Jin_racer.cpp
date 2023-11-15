/*There are 2 new types of Racers, ExplosiveRacers and MemeRacers,
  Explosive Racers is extremly fast on asphalt, but very slow on everything else.
  MemeRacers has a completely random speed each time it runs and is unaffected by terrains.
 */

#include "Jin_racer.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
double funcRand(double min, double max);

Racer::Racer(){}

Racer::Racer(int num){
  carNum = num;
}

double Racer::getSpeed(){
  return speed;
}

double Racer::getCarNum(){
  return carNum;
}

double Racer::getCurrentProgress(){
  return curProgress;
}

void Racer::resetProgress(){
  curProgress = 0.0;
}

string Racer::toString(){
  return "Racer #" + to_string(carNum) + " " + carName + " - ";
}

StreetRacer::StreetRacer(int carNum) : Racer(carNum){
  carName = "Street Racer";
  speed = funcRand(5.5,7.0); 
}

void StreetRacer::makeProgress(double modifier){
  curProgress += (speed * modifier) + 0.5;
}

SteadyRacer::SteadyRacer(int carNum) : Racer(carNum){
  carName = "Steady Racer";
  speed = funcRand(3.0,4.0);
}

void SteadyRacer::makeProgress(double modifier){
  curProgress += speed;
}

ToughRacer::ToughRacer(int carNum) : Racer(carNum){
  carName = "Tough Racer";
  speed = funcRand(2.0,3.0);
}

void ToughRacer::makeProgress(double modifier){
   double bonusSpeed = 5 * (1.0 - modifier);
   curProgress += (speed + bonusSpeed);
}

ExplosiveRacer::ExplosiveRacer(int carNum) : Racer(carNum){
  carName = "Explosive Racer";
  speed = funcRand(0.8,1.5);
}

void ExplosiveRacer::makeProgress(double modifier){
  if(modifier == 1){
      curProgress += 7;
    }
    else
      curProgress += speed*modifier + 0.5;
}

MemeRacer::MemeRacer(int carNum) : Racer(carNum){
  carName = "Meme Racer";
  speed = 1;
}

void MemeRacer::makeProgress(double modifier){
  speed = 1 + (rand()%8);
  curProgress += speed;
}

double funcRand(double min, double max){
  double lower = min;
  double upper = max;
  return ((double)rand() * (upper - lower)) / (double)RAND_MAX + lower;
}
