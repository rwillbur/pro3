#include<iostream>
#include<fstream>
#include<string>
#include"node.hpp"
#include"y.tab.h"
#include<FlexLexer.h>

using std::ifstream;
using std::ostream;
using std::string;
using std::cerr;
using std::cout;
using std::endl;

yyFlexLexer scanner;
Node *tree;

int main(int argc, char **argv)
{
 string infile, outfile;
 int position;
 ifstream input;
 ostream output(NULL);
 tree = 0;
 
 int i;
 if(argc>1)
  for(i=1; i<argc; i++)
   {
    infile = argv[1];
    position = infile.find('.');
    if (position ==0){
     cerr << "INVALID " << infile << endl;
    }
    if (position >0) {
     outfile = infile.substr(0,infile.size()-position) + "output";
    }
    else {
     outfile = infile + ".output"; 
    }
    if(input.is_open()){
     input.close();
    }
    //if(output.is_open()){
    // output.close();
    //} 
    input.open(infile);
    if(!input) {
     cerr<< "CANT OPEN" << infile <<endl;
     continue;
    }  
    /*output.open(outfile);
    if(!output){
     cerr<< "CANT OPEN OUTFILE " << outfile <<endl;
     input.close();
     cerr << "Skipping : " <<infile << endl;
     continue;
    }*/
    scanner.switch_streams(&input);
    yyparse();
    tree->print(&output);
    output << endl;
   }
   else {
   yyparse();
   cout << "Print tree " <<endl;
   tree->print(&cout);
   cout << endl;
   }
   return 0;
}



