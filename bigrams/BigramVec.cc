#include "BigramVec.h"
using namespace std;

BigramVec::BigramVec() {
  bigrams = vector<Bigram>();
}

void BigramVec::add(Bigram bigram) {
  bigrams.push_back(bigram);
}

void BigramVec::add(string line) {
  Bigram bigram = Bigram();
  bigram.set(line);
  add(bigram);
}

int BigramVec::size() {
  return bigrams.size();
}

vector<string> BigramVec::query(vector<string> qr) {

  vector<string> ret = vector<string>();

  int toMatch = qr.size()/2 - 2;

  for(vector<Bigram>::iterator it = bigrams.begin(); it != bigrams.end(); it++) {
    pair<string, int> mt = it->match(qr);
    // cout<<mt.first << " " <<mt.second<<"\n";
    if (mt.second > toMatch) {
      ret.push_back(mt.first);
    }
  }
  return ret;
}

void BigramVec::match(string str) {

  vector<string> qr = vector<string>();
  int count = 0;
  for (int i =1; i < str.length(); i++)  {		
    pair<string, string> ret = obtain(str, i);
    qr.push_back(ret.first);
    qr.push_back(ret.second);
    count++;
  }
  
  matched = query(qr);
}

void BigramVec::print() {
  
  cout<<"Matched values "<<endl;
  for (vector<string>::iterator it = matched.begin(); it != matched.end(); it++) {
    cout << *it <<"\n";
  }
}
