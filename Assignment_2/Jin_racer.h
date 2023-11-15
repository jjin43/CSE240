/*There are 2 new types of Racers, ExplosiveRacers and MemeRacers,
  Explosive Racers is extremly fast on asphalt, but very slow on everything else.
  MemeRacers has a completely random speed each time it runs and is unaffected by terrains.
 */

#pragma once
#ifndef RACER_H
#define RACER_H

#include <string>

class Racer
{
protected:
  std::string carName;
  double speed;
  double curProgress;
  int carNum;
  
public:
  Racer();
  Racer(int carNum);
  virtual ~Racer() = default;
  
  double getSpeed();
  double getCarNum();
  double getCurrentProgress();
  void resetProgress();
  virtual void makeProgress(double modifier)=0;
  std::string toString();
};

class StreetRacer : public Racer
{
public:
  StreetRacer(int carNum);
  void makeProgress(double modifier);

};

class SteadyRacer : public Racer
{
public:
  SteadyRacer(int carNum);
  void makeProgress(double modifier);
};

class ToughRacer : public Racer
{
public:
  ToughRacer(int carNum);
  void makeProgress(double modifier);
};

//Slow unless on a Slime or Asphalt RoadSegment
class ExplosiveRacer : public Racer
{
public:
  ExplosiveRacer(int carNum);
  void makeProgress(double modifier);
};

//Random int Speed 1-10
class MemeRacer : public Racer
{
public:
  MemeRacer(int carNum);
  void makeProgress(double modifier);
};

#endif
