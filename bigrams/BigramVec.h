#ifndef __BIGRAMVEC_H
#define __BIGRAMVEC_H

#include "utils.h"
#include "Bigram.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <utility>

using namespace std;

class BigramVec
{
  
public:
  
  BigramVec();
  virtual ~BigramVec() {}
  void add(Bigram bigram);
  void add(string line);
  int size();
  
  void match(string str);

  void print();

private:
  vector<string> query(vector<string> qr);
  
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version) {
    ar & bigrams;
  };
  
  vector<Bigram> bigrams;
  
  vector<string> matched;
};

#endif
