
#include "utils.h"
#include "Bigram.h"
#include "BigramVec.h"
#include <fstream>
#include <utility>
#include <string>

using namespace std;

  // boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );
void match(istream& in, string& str, boost::regex &pat) {
  getline(in, str);
  boost::smatch matches;
  if (boost::regex_match(str, matches, pat))  {
    cout << matches[2] << endl;
  }
}

void initlog(char *name, const char *dir)  {
  google::SetLogDestination(google::INFO, dir);
  google::InitGoogleLogging(name);
}

void loginfo(string msg, bool use)  {
  if (use == true) {
    LOG(INFO) << msg;  
  }
  else  {
    cout<< msg << "\n";
  }
}


void loginfo(string msg) {
  loginfo(msg, false);
}

pair<string, string> obtain(string str, int i) {
  string br = str.substr(i-1, 2);
  pair<string, string> returnPair;
  string rv = br;
  reverse(rv.begin(), rv.end());
  returnPair = make_pair(string(br), string(rv));
  return returnPair;
}


