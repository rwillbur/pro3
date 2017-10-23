%{
#include <iostream>
#include <FlexLexer.h>
#include "node.hpp"
#include "nodeVals.h"

using std::cerr;
using std::cout;
using std::endl;

extern Node *tree;
extern yyFlexLexer scanner;

#define yylex() scanner.yylex()

void yyerror (const char *);

%}

%union {
  Node* nptr;
  nodeVals* vals;
}

%type <nptr> exp statement idst
%token <vals> NUM ID
%token <nptr> EQUALS
%token <nptr> EQUALTO LESSOREQ GREATEROREQ NOTEQUAL GREATER LESS NOT OR AND MOD
%token <nptr> RPAREN LPAREN INT PRINT VOID IF READ ELSE CLASS RETURN THIS NEW WHILE 
//%right EQUALS
%left <nptr> PLUS MINUS //OR
%left <nptr> TIMES DIV //AND


%%
input: statement{
             tree=$1;
             }
;

statement: idst EQUALS exp {
          string eq = "=";
          $$=new assignNode($1,eq,$3);
          }
;

idst: ID{
             $$=new idNode($1->iinput);
      }


exp: NUM  {
           $$=new nodeNum($1->iinput); delete $1; 
          }
     |exp PLUS exp{
           string s = "+";
           $$=new addsubNode($1,s,$3); 
          }
     |exp MINUS exp{
           string s ="-";
           $$=new addsubNode($1,s,$3);
          }
     |exp TIMES exp{
           string s = "*";
           $$=new muldivNode($1,s,$3); 
          }
     |exp DIV exp{
           string s ="/";
           $$=new muldivNode($1,s,$3);
          }
           
     
                     
;




%%







                      
