//Robert Willburn
//Compilers
//23 Oct 17
#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include "nodeVals.h"

using std::string;
using std::endl;
using std::ostream;
using std::cout;
using std::vector;
using std::queue;

class Node
{
 public:
 Node(nodeVals* n = 0)
 {
  nvals = n;
  reset();
  dval=0.0;
  ival=0;
 }
 virtual ~Node()
  {
   for(unsigned int i =0; i < nodes.size(); i++)
   {
    delete nodes[i];
   }
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
  lines =1; col=1;
  sval.clear();
 }
 void setNode (Node *p, int index)
 {
  nodes[index] = p;
  return;
 }
 Node* getNode(int index)
 {
    return nodes[index];
 }
 void addNode(Node *p)
 {
  if(p != 0)
  {
   nodes.push_back(p);
  }
  return;
 }
 virtual void print(ostream *out = 0)
 {
  *out <<sval;
  for(unsigned int i = 0; i < nodes.size(); i++)
  {
   nodes[i]->print(out);
  }
  return;
 }

 protected:
  int col; 
  int lines;

  int ival;
  double dval;
  string sval;
  nodeVals* nvals;

  vector<Node*> nodes;
 };


class nodeNum : public Node
{
 public:
  nodeNum (string s) : Node(){
   num = atoi(s.c_str());
  }
  virtual void print(ostream * out =0){
   cout << "<EXP> -> NUM " << num <<endl;
  }
  private:
   int num;
 };

class sNode : public Node
{
 public:
  sNode (Node* s) : Node(){
   n = s;  }
  virtual void print(ostream * out =0){
   cout << "<SIMPLETYPE> -> ";
   n->print();
  }
  private:
   Node* n;
 };

 class varNode : public Node
{
 public:
  varNode (Node* n1, Node* n2, string sem) : Node(){
   
   tnod = n1;
   idnod = n2;
   semi = sem;
  }
  virtual void print(ostream * out =0){
   cout<<"<SIMPLETYPE> -> <ID> "<<semi <<endl;
   tnod->print();
   cout << " " ;
   idnod->print();
   cout<<semi<<endl<<endl;
  
  }
  private:
   Node* tnod;
   Node* idnod;
   string eqs;
   string semi;
 };

class simpNode : public Node
{
 public:
  simpNode (Node* n, bool b, Node* n2 = 0, Node* n3 = 0) : Node(){
   nod = n;
   bracks = b;
  }
  virtual void print(ostream * out =0){
    
   if(bracks){
    cout<<brackets;
   }
   nod->print();
   }
   private:
   Node* nod;
   bool bracks = false;
   string brackets = " []";
};

 class idNode : public Node
{
 public:
  idNode (string s, bool b) : Node(){
   idv = s;
   bracks = b;
  }
  virtual void print(ostream * out =0)
  {
   cout << "<ID> " << idv;
   if(bracks)
    {
     cout<<brackets;
    }
  }
  private:
   string idv;
   string brackets = " []";
   bool bracks = false;
 };

 class intNode : public Node
{
 public:
  intNode (string s) : Node(){
   idv = s;
  }
  virtual void print(ostream * out =0)
  {
   cout << "<TYPE> " << idv;
  }
  private:
   string idv;
 };
 

 


class muldivNode : public Node
 {
  public:
  muldivNode (Node* n1, string s, Node* n2) : Node(){
   node1 = n1;
   node2 = n2;
   svalue = s;
  } 
virtual void print(ostream * out=0){
   cout << "<EXP> " << svalue << " <EXP>"<<endl;
   cout << "Left Child ";
   node1->print();
   cout << "Right Child ";
   node2->print();
  
  }
  private:
   Node* node1 =0;
   Node* node2 =0;
   string svalue;

 };
class addsubNode : public Node
 {
  public:
  addsubNode (Node* n1, string s, Node* n2) : Node(){
   node1 = n1;
   node2 = n2;
   svalue = s;
  } 
virtual void print(ostream * out=0){
   cout << "<EXP> " << svalue << " <EXP>"<<endl;
   cout << "Left Child ";
   node1->print();
   cout << "Right Child ";
   node2->print();
 
  }
  private:
   Node* node1 =0;
   Node* node2 =0;
   string svalue;

 };
class assignNode : public Node
 {
  public:
  assignNode (Node* n1, string s, Node* n2, string s2) : Node(){
   node1 = n1;
   node2 = n2;
   svalue = s;
   svalue2 = s2;
  
} 
virtual void print(ostream * out=0){
   cout << "<ID> " << svalue << " <EXP>" << svalue2 <<endl;
   node1->print();
   cout << endl;
   node2->print();
  }
  private:
   Node* node1 =0;
   Node* node2 =0;
   string svalue;
   string svalue2;

};

class errorN : public Node
{
 public:
  errorN(string err) : Node () {
  errorS = err;
  }
 virtual void printNode(ostream * out =0)
 {
  cout << errorS << "Error " << endl;
 }
 private:
  string errorS;
};  

#endif
