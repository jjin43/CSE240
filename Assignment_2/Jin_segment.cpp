/*Slime is a new RoadSegment that has a totally random speed modifier from 0.0 to 1.0,
Slime always have a 5% chance to spawn, which is taken off from the road segment that is most likely to spawn next.
Slime doesn't generate itself as neighbors, but have a equal chance to generate all other RoadSegments.
*/

#include "Jin_segment.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;
double fRand(double min, double max);

RoadSegment::RoadSegment(){
  length = rand()%(50-10 + 1) + 10;
}

void RoadSegment::toString(){
  cout<<  name + " - " + to_string(length) + " units" << endl;;
}

int RoadSegment::getLength(){
  return length;
}

int RoadSegment::getModifier(){
  return modifier;
}

string RoadSegment::getName(){
  return name;
}

AsphaltSegment::AsphaltSegment() : RoadSegment(){
  name = "Asphalt";
  modifier = 1.0;
}

RoadSegment* AsphaltSegment::generateNeighbor(){
  int temp = fRand(0.0,1.0);
  if(temp<=0.60){
    AsphaltSegment* next = new AsphaltSegment();
    return next;
  }
  else if(temp >0.60 && temp <= 0.80){
    CrumbledSegment* next = new CrumbledSegment();
    return next;
  }
  else if(temp >0.80 && temp <= 0.90){
    GravelSegment* next = new GravelSegment();
    return next;
  }
  else if(temp > 0.90 && temp <= 0.95){
    DirtSegment* next = new DirtSegment();
    return next;
  }
  else{
    SlimeSegment* next = new SlimeSegment();
    return next;
  } 
}

CrumbledSegment::CrumbledSegment() : RoadSegment(){
  name = "Crumbled";
  modifier = fRand(0.6,0.8);
}

RoadSegment* CrumbledSegment::generateNeighbor(){
  int temp = fRand(0.0,1.0);
  if(temp<=0.20){
    AsphaltSegment* next = new AsphaltSegment();
    return next;
  }
  else if(temp >0.20 && temp <= 0.60){
    CrumbledSegment* next = new CrumbledSegment();
    return next;
  }
  else if(temp >0.60 && temp <= 0.85){
    GravelSegment* next = new GravelSegment();
    return next;
  }
  else if(temp > 0.85 && temp <= 0.90){
    DirtSegment* next = new DirtSegment();
    return next;
  }
  else{
    SlimeSegment* next = new SlimeSegment();
    return next;
  }
}

GravelSegment::GravelSegment() : RoadSegment(){
  name = "Gravel";
  modifier = fRand(0.3,0.6);
}

RoadSegment* GravelSegment::generateNeighbor(){
  int temp = fRand(0.0,1.0);
  if(temp<=0.05){
    AsphaltSegment* next = new AsphaltSegment();
    return next;
  }
  else if(temp >0.05 && temp <= 0.15){
    CrumbledSegment* next = new CrumbledSegment();
    return next;
  }
  else if(temp >0.15 && temp <= 0.65){
    GravelSegment* next = new GravelSegment();
    return next;
  }
  else if(temp > 0.65 && temp <= 0.95){
    DirtSegment* next = new DirtSegment();
    return next;
  }
  else{
    SlimeSegment* next = new SlimeSegment();
    return next;
  }
}

DirtSegment::DirtSegment() : RoadSegment(){
  name = "Dirt";
  modifier = fRand(0.0,0.3);
}

RoadSegment* DirtSegment::generateNeighbor(){
  int temp = fRand(0.0,1.0);
  if(temp <= 0.05){
    CrumbledSegment* next = new CrumbledSegment();
    return next;
  }
  else if(temp >0.05 && temp <= 0.40){
    GravelSegment* next = new GravelSegment();
    return next;
  }
  else if(temp > 0.40 && temp <= 0.95){
    DirtSegment* next = new DirtSegment();
    return next;
  }
  else{
    SlimeSegment* next = new SlimeSegment();
    return next;
  }
}

SlimeSegment::SlimeSegment() : RoadSegment(){
  name = "Slime";
  modifier = fRand(0.0,1.0);
}

RoadSegment* SlimeSegment::generateNeighbor(){
  int temp = fRand(0.0,1.0);
  if(temp<=0.25){
    AsphaltSegment* next = new AsphaltSegment();
    return next;
  }
  else if(temp >0.25 && temp <= 0.50){
    CrumbledSegment* next = new CrumbledSegment();
    return next;
  }
  else if(temp >0.50 && temp <= 0.75){
    GravelSegment* next = new GravelSegment();
    return next;
  }
  else{
    DirtSegment* next = new DirtSegment();
    return next;
  }
  
}

double fRand(double min, double max){
  double lower = min;
  double upper = max;
  srand((unsigned int)time(NULL));
  return ((double)rand() * (upper - lower)) / (double)RAND_MAX + lower;
}
