#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "Jin_racer.h"
#include "Jin_segment.h"
#include "Jin_race.h"

using namespace std;
void outputTrack(RoadSegment* roads[],int length);
void outputDivider(int numLoop);

Race::Race(){
  
  //Begining Menu
  cout << "Welcome to the Racer Derby!" << endl;
  
  cout << "Would you like to: " << endl;
  cout << "1 - Determine the length of the race" << endl;
  cout << "2 - Run a random race" << endl;
  cout << "-1 - Exit" << endl;
  
  srand((unsigned)time(NULL));
  
  cin >> choice;
  switch(choice){
  case 1:{
    bool correctLen = false;
    while(!correctLen){
      cout << "Set Race Length to (Integer 0-50):";
      cin >> length;
      if(length >= 10 && length <=50){
	correctLen = true;
      }
      else{
	cout << "Invalid Race Length : Please Try Again" << endl;;
      }
    }
    length ++;
    break;
  }
  case 2:
    length = rand()%(50-10 +1) + 10;
    length ++;
    break;
  case -1:
    break;
  default:
    cout << "Please enter a valid option : Try Again" << endl;
  }
  
}

void Race::runRace(){
  //generate Racers
  Racer** racer = new Racer*[8];
  for(int i=0; i<8; i++){
    int rnd = rand()%(5-1 +1)+ 1;
    switch(rnd){
    case 1:
      racer[i] = new StreetRacer(i+1);
      break;
	
    case 2:
      racer[i] = new SteadyRacer(i+1);
      break;
      
    case 3:
      racer[i] = new ToughRacer(i+1);
      break;

    case 4:
      racer[i] = new ExplosiveRacer(i+1);
      break;
	
    case 5:
      racer[i] =  new MemeRacer(i+1);
      break;
      
    }
  }

  //generate RoadSegments
  RoadSegment** roads = new RoadSegment*[length];
  //generate first road randomly
  int rnd1 = rand()%(4) + 1;
  switch(rnd1){
  case 1:
    roads[0] = new AsphaltSegment();
    break;
  case 2:
    roads[0] = new CrumbledSegment();
    break;
  case 3:
    roads[0] = new GravelSegment();
    break;
  case 4:
    roads[0] = new DirtSegment();
    break;
  }

  for(int i=1;i<length;i++){
    roads[i] = roads[i-1]->generateNeighbor();
  }
  
  cout << "*** Race Starting ***" << endl;
  //Race Main Loop
  length --;
  int numLoop = 0;
  int winner = 0;
  bool hasWinner = false;
  int lane[8] = {0,0,0,0,0,0,0,0};
  while(!hasWinner){
    numLoop++;
    //count the progress of road segments for each racer seperately using int[]
    for(int i=0; i<8; i++){
      //make progress
      //Default behavior if unexpected results happened
      int mod = roads[lane[i]]->getModifier();
      if(mod > 1 || mod <= 0){
	mod = 1.0;
      }
	
      racer[i]->makeProgress(mod);
      //check Win condition
      //2nd Default behavior
      int rLen = roads[lane[i]]->getLength();
      if(rLen < 0 || rLen > 51){
	rLen = 35;
      }
      if(racer[i]->getCurrentProgress()>= rLen){
	lane[i] += 1;
	
	if(lane[i] > length){
	  lane[i] = length;
	  winner = i+1;
	  hasWinner = true;
	  break;
	}
	else{
	  racer[i]->resetProgress();
	}

      }	
    }
    outputDivider(numLoop);
    //output Racer Progress
    outputTrack(roads,length);
    for(int i=0; i<8; i++){
      cout << racer[i]->toString();
      printf("%.2f units\tinto Segment#%d -\t",racer[i]->getCurrentProgress(),lane[i]);
      roads[lane[i]]->toString();
    }
    
  }
  cout << "*** Winner is [Racer #" << to_string(winner) << "] ***"  << endl;

  //clean up
  for(int i=0; i<8; i++){
    delete racer[i];
  }
  
  for(int i=0; i<length+1; i++){
    delete roads[i];
  }
  delete[] roads;
  delete[] racer;
  
}

int Race::getChoice(){
  return choice;
}
  
void outputTrack(RoadSegment* roads[], int length){
  for(int i=0; i<length; i++){
    printf("- %c ",(roads[i]->getName()).front());
  }
  printf(" -\n");
}


void outputDivider(int numLoop){
  cout << "########################################" << endl;
  cout << "Update " + to_string(numLoop) + "!" << endl;
  cout << "---------------" << endl;
}
