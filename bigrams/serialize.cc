#include "serialize.h"
#include <boost/archive/text_iarchive.hpp>


bool fexists(const char *name) {
  std::ifstream ifname(name);
  return ifname;
}


void parseFile(const char* fileName, BigramVec &bigramVec) {
  loginfo("reading from file");
  std::ifstream myfile(fileName);
  std::string line;
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
	bigramVec.add(line);
    }
    myfile.close();
  }
}

BigramVec read(const char *archiveName, const char *file) {
  BigramVec big;
  if (fexists(archiveName))  {
    loginfo("Reading from archive..");
    std::ifstream ifs(archiveName);
    boost::archive::text_iarchive ia(ifs);
    ia >> big;
  }
  else {
    big = BigramVec();
    parseFile(file, big);
  }
  loginfo("Done..");
  return big;
}

void save(const char *archiveName, BigramVec &bigramVec) {
  loginfo("Saving...");
  ofstream ofs(archiveName);
  {
    boost::archive::text_oarchive oa(ofs);
    oa << bigramVec;
  }
  loginfo("Done..");
}

