//Robert Willburn
//Compilers
//23 Oct 17

%{
#include <iostream>
#include <FlexLexer.h>
#include "node.hpp"
#include "nodeVals.h"

using std::cerr;
using std::cout;
using std::endl;

//extern Node *tree;
extern vector<Node*> trees;
extern yyFlexLexer scanner;

#define yylex() scanner.yylex()

void yyerror (const char *);

%}

%union {
  Node* nptr;
  nodeVals* vals;
}

%type <nptr> exp statement simpleType idst input VarDeclaration Type ints
%token <vals> NUM ID INT
%token <nptr> EQUALS SEMI
%token <nptr> EQUALTO LESSOREQ GREATEROREQ NOTEQUAL GREATER LESS NOT OR AND MOD 
%token <nptr> RPAREN LPAREN PRINT VOID IF READ ELSE CLASS RETURN THIS NEW WHILE RBRACKET LBRACKET
//%right EQUALS
%left <nptr> PLUS MINUS //OR
%left <nptr> TIMES DIV //AND


%%
/* This will not read a file. At one pint it did, now it does not. If you manually plug in input it will give the same result as the same input from a file */
start: %empty{} 
    | start input {trees.push_back($2);}
;

input: statement{  }
    | VarDeclaration {}
;
//this takes a simple type ID and a semicolon
VarDeclaration : simpleType idst SEMI{
           string sem = ";";
           $$=new varNode($1,$2,sem);
           }
        

;
//This takes a type and possibly left and right brackets. If there are brackets, it prints them out before the type, otherwise it just prints out the type. 
simpleType: Type {
          bool b = false;
          $$=new simpNode($1,b);
          }
          | Type LBRACKET RBRACKET{
          bool b = true;
          $$= new simpNode($1,b,$2,$3);
          }

;
//This differentiates between the type int and any id. More data types can be added later.
Type: ints{$$=new sNode($1); }
   | idst {$$=new sNode($1); }
;         
          
//A statement takes an identifier, an = sign, an exp and a semicolon. 
statement: idst EQUALS exp SEMI{
          string eq = "=";
          string sem = ";";
          $$=new assignNode($1,eq,$3,sem);
          }
          | idst EQUALS exp error{
           cerr << "Missing ';' after statement: line" <<endl;
           $$ = new errorN("<Statement>");
          }
           
;

idst: ID{ 
          bool b = false;
          $$=new idNode($1->iinput, b); 
          delete $1; }
      |ID LBRACKET RBRACKET {
         bool b = true;
         $$=new idNode($1->iinput, b); delete $1; 
        }

;
//the type int
ints: INT { $$=new intNode($1->itoken);}
;

//expression
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







                      
