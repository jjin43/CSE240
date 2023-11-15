#include "WordEntry.h"
#include <string>

using namespace std;

WordEntry::WordEntry(){}

WordEntry::WordEntry(string input){
  word = input;
  for(string::size_type i=0; i<word.length();i++){
    word[i] = tolower(word[i]);
  }
}

void WordEntry::addFreq(){
  freq++;
}

bool WordEntry::operator==(const WordEntry& rhs) const{
  return (word == rhs.word);
}

bool WordEntry::operator!=(const WordEntry& rhs) const{
  return (word != rhs.word);
}

bool WordEntry::operator>(const WordEntry& rhs) const{
  return (word > rhs.word);
}

bool WordEntry::operator<(const WordEntry& rhs) const{
  return (word < rhs.word);
}
