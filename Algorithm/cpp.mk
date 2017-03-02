LDLIBS += -lcppunit -lstdc++
CXXFLAGS += -std=c++11

ifeq ($(OS),Windows_NT)
  MYOS := Windows
else
  MYOS := $(shell uname -s)
endif

ifeq ($(MYOS),Darwin)
CPPUNITDIR = /Users/adamb/CppUnit
CPPFLAGS += -I$(CPPUNITDIR)/include
LDFLAGS += -L$(CPPUNITDIR)/lib
endif
