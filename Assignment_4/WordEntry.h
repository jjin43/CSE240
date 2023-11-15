#pragma once
#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>

//stores the word and the frequency
struct WordEntry{
  std::string word;
  int freq = 0;
  
  WordEntry();
  WordEntry(std::string input);
  void addFreq();

  //Comparision Override
  bool operator==(const WordEntry& rhs) const;
  bool operator!=(const WordEntry& rhs) const;
  bool operator>(const WordEntry& rhs) const;
  bool operator<(const WordEntry& rhs) const;
};

#endif
