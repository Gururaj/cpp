
#include <iostream>
#include <fstream>
#include "utils.h"
#include "serialize.h"
#include "BigramVec.h"


using namespace std;

int main(int argc, char *argv[]) 
{
  initlog(argv[0], "./log/");
  
  BigramVec bigramVec = read("archive", "/usr/share/dict/words");
  // other actions
  
  string str;
  cout <<"Enter: ";
  getline(cin, str);
  cout << str << "\n";
  
  bigramVec.match(str);

  bigramVec.print();

  // archive back  
  save("archive", bigramVec);

  return 0;
}


