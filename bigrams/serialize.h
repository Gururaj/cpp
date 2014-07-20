#ifndef __SERIALIZE_H
#define __SERIALIZE_H

#include <fstream>
#include <boost/archive/text_iarchive.hpp>
#include "BigramVec.h"

bool fexists(const char *name);

void parseFile(const char* fileName, BigramVec &bigramVec);

BigramVec read(const char *archiveName, const char *file);

void save(const char *archiveName, BigramVec &bigramVec);

#endif
