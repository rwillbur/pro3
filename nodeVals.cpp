#include "nodeVals.h"
#include <string>
#include "node.hpp"
#include "program3.tab.h"


using std::string;



nodeVals:: nodeVals(int row, int column, int length, string tokenName, string input){
 line = row;
 col = column;
 len = length;
 itoken = tokenName;
 iinput = input;
 return;
 }
