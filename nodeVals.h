#ifndef NODEVALS_H
#define NODEVALS_H

#include <iostream>
#include <string>

using std::string;



class nodeVals{

  public:
    nodeVals(int row=0, int column=0, int length=0, string tokenName=0, string input=0);
        int line;
        int col;
        int len;
        string itoken;
        string iinput;
       };


#endif 
