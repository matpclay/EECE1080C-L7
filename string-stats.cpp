// Author: Matthew Clayton
// Source File: string-stats.cpp
// Description: Various string statistics

#include <cmath>
#include <cctype>
#include <string>

using namespace std;

// returns number of lines
unsigned numLines(const string& st){
  int lines = 0;
  for (int i = 1; i < st.length(); i++)
    if (st[i] == '\n')
      lines++; // if new line character, increment
  if (st[st.length() - 1] != '\n')
    lines++; // if last character is not new line, add one
  return lines;
}

// returns number of uppercase characters
unsigned upperCaseChars(const string& st){
  int uppers = 0;
  // for each character
  for (int j = 0; j < st.length(); j++)
    if(isupper(st[j])) // test if uppercase
      uppers++; // if uppercase, increment counter
  return uppers;
}

// returns number of lowercase characters
unsigned lowerCaseChars(const string& st){
  int lowers = 0;
  for (int k = 0; k < st.length(); k++)
    if(islower(st[k]))
      lowers++;
  return lowers;
}

// returns number of punctuation marks
unsigned numPunct(const string& st){
  int puncts = 0;
  for (int m = 0; m < st.length(); m++)
    if(ispunct(st[m]))
      puncts++;
  return puncts;
}

// returns number of decimal digits
unsigned numDigits(const string& st){
  int digits = 0;
  for (int n = 0; n < st.length(); n++)
    if(isdigit(st[n]))
      digits++;
  return digits;
}

unsigned numWords(const string& st){
  int words = 0;
  for (int p = 1; p < st.length(); p++)
    if (isalpha(st[p]) && !(isalpha(st[p-1])))
      words++; // if non-alpha appears before, must be a new word
  if (isalpha(st[0]))
    words++; // if first character is alpha, must be a word at start
  if (isalpha(st[st.length()]) && isalpha(st[st.length()-1]))
    // if last character is part of a word and previous
    // character is part of same word, end must be a word
    words++;

  return words;
}

vector<int> characterCounts(const string& st){
  vector<int> ret(26);
  st.tolower(); // make everything lowercase to ease letter counting
  for (int c = 0; c < st.length(); c++)
    if (int(st[c]) >= 97 && int(st[c]) <= 122)
      v[int(st[c]) - 97] += 1;
  return ret;
}
