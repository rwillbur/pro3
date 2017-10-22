#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>
#include<string>

using std::string;
using std::endl;
using std::ostream;

class Node
{
 public:
 Node(Node *lf=0,Node *rt=0)
 {
  reset();
  dval=0.0;
  ival=0;
  left=lf;
  right=rt;
 }
 virtual ~Node()
  {
   if(left) delete left;
   if(right) delete right;
  }
 int getint() const
 { 
  return ival;
 }
 double getdbl() const
 {
  return dval;
 }
 string getstring() const
 {
  return sval;
 }
 void setval(const char *v)
 {
  sval = v;
 }
 void setval(const string s)
 {
  sval=s;
 }
 void setval(int i)
 {
  ival = i;
 }
 void setval(double d)
 {
  dval = d;
 }
 void reset() 
 {
  yyline=yycol=nextline=nextcol=1;
 }
 void setleft (Node *p)
 {
  left = p;
  return;
 }
 void setright (Node *p)
 {
  right=p;
  return;
 }
 Node* getleft()
 {
  return left;
 }
 Node* getright()
 {
  return right;
 }
 virtual void print(ostream *out = 0)
 {
  if(left) left->print(out);
  *out << sval;
  if(right) right->print(out);
  return;
 }
 protected:
  int yyline;
  int yycol;
  int ival;
  double dval;
  string sval;
  int nextcol;
  int nextline;
  Node *left,*right;
};

class nodeNum : public Node
{
 public:
  nodeNum(int i)
   {
    ival = i;
   };
  virtual void print (ostream *out =0)
   {
    *out << "( ";
    if(left) left->print(out);
    if(right) right->print(out);
    *out << " )";
    return;
   }
};
  


#endif
