/*
Author: Justin Jin
Date: 6/30/2020
Description: This program goes through a text file, and using a bst, collects the number of each word in the file. Then returns a summary of the analysis.
Usage: <exe> <input file>
       After the program outputs the "Word Summary", user have the option to
       1.[Find Specific Word Frequency], 2.[Output to file], 3.[Quit]
 */

#include "Jin_bst.h"
#include "WordEntry.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//Parsing Helper
bool isNumber(string str);

//Recursive count total word frequency
int totalWordCount(Node<WordEntry>* treeRoot);
//Recursive print to File
void writeToFile(Node<WordEntry>* treeRoot, ofstream& outFile);

//Recursive methods for finding the most and least used words
void mostFreqRecur(Node<WordEntry>* treeRoot, string arr[]);
void leastFreqRecur(Node<WordEntry>* treeRoot, string arr[]);
//FreqRecur() Helper methods
void Reorder(string arr[], string newInsert, int pos);
void FreqReorder(int arr[], int newInsert, int pos);


int main(int argc, char** argv){
  
  if(argc != 2){
    cout << "Error -- Usage: <exe> <Input File>\n" << endl;
    return 1;
  }
  
  ifstream inFile(argv[1]);

  BST<WordEntry>* bst;
  bst = new BST<WordEntry>();

  if(inFile.is_open()){
    string line;
    char* parPtr;

    //Read file line by line (while has next line)
    while(getline(inFile,line)){
      
      //split line string by delimeters
      parPtr = strtok(line.data()," ,.;_-/#$*()!%[]:\"\'\t\r");
      while(parPtr != NULL){
	
	//only parse into token if is a word
	if(!isNumber(parPtr)){
	  WordEntry word(parPtr);
	  Node<WordEntry>* temp = bst->Insert(word);
	  if(temp != NULL)
	    temp->data.addFreq();
	
	}
	parPtr = strtok(NULL," ,.;_-/#$*()!%[]:\"\'\t\r");
      }
      
    }
    
  }
  else{
    cout <<"Error -- Targeted Input File Does Not Exist\n";
    return 1;
  }
  
  cout << "**** Word Summary ****" << endl;
  cout << "Total Words: " << to_string(totalWordCount(bst->root)) << endl;
  cout << "Total Unique Words: " << to_string(bst->Count()) << endl;
  
  string topFive[5];
  mostFreqRecur(bst->root,topFive);
  string botFive[5];
  leastFreqRecur(bst->root,botFive);
  
  cout << "The 5 most frequently used words: " << endl;
  for(int i=0; i<5; i++){
    cout << topFive[i] << "\t- " << to_string(bst->Find(topFive[i])->data.freq) << endl;
  }
  cout << "The 5 least frequently used words: " << endl;
  for(int i=0; i<5; i++){
    cout << botFive[i] << "\t- " << to_string(bst->Find(botFive[i])->data.freq) << endl;
  }
  
  int choice = 0;
  
  while(choice != 3 && choice != 2){
    cout << endl;
    cout << "1. Find Frequency of a Specific Word" << endl;
    cout << "2. Output Alphabetical Word Analysis to a File" << endl;
    cout << "3. Quit" << endl;
    
    cin >> choice;
    if(cin.fail())
      choice = 0;
    
    switch(choice){

      //Find Word
    case 1:{
      string wordFind;
      cout <<"Please Enter a Word to Find: ";
      cin >> wordFind;
      for(string::size_type i=0; i<wordFind.length();i++){
	wordFind[i] = tolower(wordFind[i]);
      }
      Node<WordEntry>* nodeFind = bst->Find(wordFind);
      if(nodeFind != NULL){
	cout << nodeFind->data.word << "\t\t- " << to_string(nodeFind->data.freq) << endl;
      }
      else{
	cout << "This Word Does Not Exist in the File" << endl;
      }
      break;
    }
      
      //Output to File
    case 2:{
      cout << "The Word Analysis will output as [ WordAnalysis.txt ]" << endl;
      ofstream outFile("WordAnalysis.txt");
      writeToFile(bst->root, outFile);
      outFile.close();
      break;
    }
      
      //Quit
    case 3:
      cout << "**** Exiting Program ****" << endl;
      break;
      
    default:
      cout << "Invalid Option, Try Again :[1-3]" << endl;
    }
  }
  delete bst;
  return 0;
}

bool isNumber(string str){
  for(string::size_type i=0; i<str.length(); i++){
    if(isdigit(str[i])==true)
      return true;
  }
  return false;

}

//All methods below uses inorder transversal in recursion

int totalWordCount(Node<WordEntry>* treeRoot){
  if(treeRoot == NULL)
    return 0;
  
  return treeRoot->data.freq + totalWordCount(treeRoot->left) + totalWordCount(treeRoot->right); 
}

void writeToFile(Node<WordEntry>* treeRoot, ofstream& outFile){
  if(treeRoot == NULL)
    return;

  writeToFile(treeRoot->left, outFile);
  outFile << treeRoot->data.word << "\t- " << to_string(treeRoot->data.freq) << endl;
  writeToFile(treeRoot->right, outFile);
}

void mostFreqRecur(Node<WordEntry>* treeRoot, string arr[]){
  static int larFreq[5] = {0,0,0,0,0};

  if(treeRoot == NULL)
    return;
  
  mostFreqRecur(treeRoot->left, arr);
  if(treeRoot->data.freq > larFreq[0]){
    Reorder(arr, treeRoot->data.word, 0);
    FreqReorder(larFreq, treeRoot->data.freq, 0);
  } 
  else if(treeRoot->data.freq > larFreq[1]){
    Reorder(arr, treeRoot->data.word, 1);
    FreqReorder(larFreq, treeRoot->data.freq, 1);
  }
  else if(treeRoot->data.freq > larFreq[2]){
    Reorder(arr, treeRoot->data.word, 2);
    FreqReorder(larFreq, treeRoot->data.freq, 2);
  }
  else if(treeRoot->data.freq > larFreq[3]){
    Reorder(arr, treeRoot->data.word, 3);
    FreqReorder(larFreq, treeRoot->data.freq, 3);
  }
  else if(treeRoot->data.freq > larFreq[4]){
    Reorder(arr, treeRoot->data.word, 4);
    FreqReorder(larFreq, treeRoot->data.freq, 4);
  }
  mostFreqRecur(treeRoot->right, arr);

}

void leastFreqRecur(Node<WordEntry>* treeRoot, string arr[]){
  static int smolFreq[5] = {100000,100000,100000,100000,100000};

  if(treeRoot == NULL)
    return;
  
  leastFreqRecur(treeRoot->left, arr);
  if(treeRoot->data.freq < smolFreq[0]){
    Reorder(arr, treeRoot->data.word, 0);
    FreqReorder(smolFreq, treeRoot->data.freq, 0);
  } 
  else if(treeRoot->data.freq < smolFreq[1]){
    Reorder(arr, treeRoot->data.word, 1);
    FreqReorder(smolFreq, treeRoot->data.freq, 1);
  }
  else if(treeRoot->data.freq < smolFreq[2]){
    Reorder(arr, treeRoot->data.word, 2);
    FreqReorder(smolFreq, treeRoot->data.freq, 2);
  }
  else if(treeRoot->data.freq < smolFreq[3]){
    Reorder(arr, treeRoot->data.word, 3);
    FreqReorder(smolFreq, treeRoot->data.freq, 3);
  }
  else if(treeRoot->data.freq < smolFreq[4]){
    Reorder(arr, treeRoot->data.word, 4);
    FreqReorder(smolFreq, treeRoot->data.freq, 4);
  }
  leastFreqRecur(treeRoot->right, arr);

}


void FreqReorder(int arr[], int newInsert, int pos){
  for(int i = 4; i>pos; i--){
    arr[i] = arr[i-1];
  }
  arr[pos] = newInsert;
}

void Reorder(string arr[], string newInsert, int pos){
  for(int i = 4; i>pos; i--){
    arr[i] = arr[i-1];
  }
  arr[pos] = newInsert;
}
