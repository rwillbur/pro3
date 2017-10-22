file: prog3
CXX=g++
CXXFLAGS=-ggdb -std=c++11 -Wall
YACC=bison
YFLAGS=--report=state -W -d
LEX=flex
LEXXX=flex++
LFLAGS=--warn

.PHONY: clean

prog3: y.tab.c y.tab.h program3_lex.cpp program3.cpp node.hpp
	 $(CXX)  $(CXXFLAGS)  program3.cpp y.tab.c program3_lex.cpp -o prog3

y.tab.c : program3.y node.hpp
	 $(YACC) $(YFLAGS) program3.y

y.tab.h : program3.y node.hpp
	 $(YACC) $(YFLAGS) program3.y

program3_lex.cpp: program3.lpp node.hpp
	 $(LEXXX) $(LFLAGS) program3.lpp

tidy:
	/bin/rm -f a.out core.* y.tab.* program3.output \
	  program3_lex.cpp

clean: tidy
	/bin/rm -f prog3
