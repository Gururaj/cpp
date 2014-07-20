#ifndef __BIGRAM_H
#define __BIGRAM_H

#include <vector>
#include <algorithm>
#include "utils.h"
#include <utility>
#include <boost/archive/text_oarchive.hpp>

using namespace std;

class Bigram
{
public:
  Bigram();
  ~Bigram();
  
  void set(string str);
  
  void dump();

  pair<string, int> match(vector<string> qr);
  
private:
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version) {
    ar & _count;
    ar & _bigrams;
    ar & _value;
  };
  
  string _value;
  vector<string> _bigrams;
  int _count;
};

#endif
