%{
#include <iostream>
#include <FlexLexer.h>
#include "node.hpp"

using std::cerr;
using std::cout;
using std::endl;

extern Node *tree;
extern yyFlexLexer scanner;

#define yylex() scanner.yylex()

void yyerror (const char *);

%}

%union {
  Node* ttype;
}

%type <ttype> exp 
%token <ttype> NUM ID
%token EQUALTO LESSOREQ GREATEROREQ NOTEQUAL GREATER LESS NOT OR AND MOD
%token RPAREN LPAREN INT PRINT VOID IF READ ELSE CLASS RETURN THIS NEW WHILE 
%right EQUALS
%left PLUS MINUS OR
%left TIMES DIV AND


%%

input: exp  {
             tree=$1;
             }
;
exp: NUM  {
           $$=new nodeNum($1->getint()); delete $1;
          }
     | ID {
           $$=new nodeNum($1->getint()); delete$1;
          }
                     
     | exp PLUS exp { 
                     $$=new Node($1,$3);
                     $$->setval(" + ");
                    }
     | exp MINUS exp { 
                     $$=new Node($1,$3);
                     $$->setval(" - ");
                     }
     | exp TIMES exp {
                     $$=new Node($1,$3);
                     $$->setval(" * ");
                     }
     | exp DIV exp   { 
                     $$=new Node($1,$3);
                     $$->setval(" / ");
                     }
     | LPAREN exp RPAREN {
                     $$=new exp($2);   
                     }
;

%%







                      
