#pragma once
#ifndef RACE_H
#define RACE_H

#include <string>
#include "Jin_racer.h"
#include "Jin_segment.h"

class Race{
 protected:
  int length;
  int choice = 0;
 public:
  Race();
  void runRace();
  int getChoice();
};

#endif
