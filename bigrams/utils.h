#ifndef __UTILS_H__
#define __UTILS_H__

#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>
#include <boost/regex.hpp>
#include <glog/logging.h>

// boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );
void match(std::istream& is, std::string& str, boost::regex &pat);

void initlog(char *name, const char *dir);

void loginfo(std::string msg);

std::pair<std::string, std::string> obtain(std::string str, int i);

#endif
