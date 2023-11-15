/*
  Author: Justin Jin
  Date: 6/23/2022
  Description: This program will create a race track mini game, where 8 different racers with different speed and progress on the road  are randomly generated, 
  which runs on  and a user indicated or randomly generated length of random road segments. The program will then announce the winner to be whoever finished the race first.
  Extra Credits: This program have 3 more types of things to the race, 2 racers [ExplosiveRacer,MemeRacer], and 1 RoadSegment [SlimeSegment].
 */

#include <iostream>
#include "Jin_race.h"
#include "Jin_racer.h"
#include "Jin_segment.h"

int main(int argc, char** argv)
{
  Race r;
  if(r.getChoice() != -1)
    r.runRace();
  return 0;
}
