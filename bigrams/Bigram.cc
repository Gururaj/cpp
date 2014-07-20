
#include "Bigram.h"
#include <utility>
#include <algorithm>

using namespace std;

Bigram::Bigram() {
  _bigrams = vector<string>();
}

Bigram::~Bigram() { }

void Bigram::set(string str) {
  _count = 0;
  for (int i =1; i < str.length(); i++)  {		
    pair<string, string> ret = obtain(str, i);
    _bigrams.push_back(ret.first);
    _bigrams.push_back(ret.second);
    _count++;
  }

  sort(_bigrams.begin(), _bigrams.end());
  _value = str;
}

void Bigram::dump() {
  cout<<"Count:"<<_count<<"\n";
  for(vector<string>::iterator it = _bigrams.begin(); it != _bigrams.end(); ++it) {
    cout << *it <<" ";
  }
  cout<<"\n";
}


pair<string, int> Bigram::match(vector<string> qr) {
  // find min
  
  int matched = 0;

  for(
      vector<string>::iterator it = qr.begin(), bit = _bigrams.begin(); 
      it != qr.end() && bit != _bigrams.end(); 
      ) {
    
    int cmp = it->compare(*bit);
    // both are same
    if (cmp == 0) {
      matched++;
      it++;
      bit++;
    }
    else if (cmp < 0) {
      it++;
    } 
    else {
      bit++;
    }
    
  }
  return make_pair(_value, matched);
}

