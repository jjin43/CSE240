/*Slime is a new RoadSegment that has a totally random speed modifier from 0.0 to 1.0,
Slime always have a 5% chance to spawn, which is taken off from the road segment that is most likely to spawn next.
Slime doesn't generate itself as neighbors, but have a equal chance to generate all other RoadSegments.
*/

#pragma once
#ifndef ROADSEGMENT_H
#define ROADSEGMENT_H

#include <string>

class RoadSegment
{
protected:
  int length;
  double modifier;
  std::string name;

public:
  RoadSegment();
  virtual ~RoadSegment() = default;
  virtual RoadSegment* generateNeighbor()=0;
  void toString();
  std::string getName();
  int getLength();
  int getModifier();
  //double fRand(int max, int min);
  
};

class AsphaltSegment : public RoadSegment
{
 public:
  AsphaltSegment();
  RoadSegment* generateNeighbor();
  
};

class CrumbledSegment : public RoadSegment
{
public:
  CrumbledSegment();
  RoadSegment* generateNeighbor();
  
};

class GravelSegment : public RoadSegment
{
public:
  GravelSegment();
  RoadSegment* generateNeighbor();
  
};

class DirtSegment : public RoadSegment
{
public:
  DirtSegment();
  RoadSegment* generateNeighbor();
  
};

class SlimeSegment : public RoadSegment
{
public:
  SlimeSegment();
  RoadSegment* generateNeighbor();

};

#endif
