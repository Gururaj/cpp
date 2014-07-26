CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -Wc++11-extensions
LDFLAGS=-g -Wc++11-extensions
LDLIBS=-lboost_regex -lglog -lboost_serialization
BINARY=spellcheck
SRCS=main.cc utils.cc Bigram.cc BigramVec.cc serialize.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: $(BINARY)

spellcheck: $(OBJS)
	g++ $(LDFLAGS) -o spellcheck $(OBJS) $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)
	$(RM) $(BINARY)

dist-clean: clean
	$(RM) *~ .depend
	$(RM) ./log/*

check-syntax:
	$(CXX) -o nul -S ${CHK_SOURCES}

include .depend
