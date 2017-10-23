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
   for(int i =0; i < nodes.size(); i++)
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
  line =1; col=1;
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
  int line;

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
   cout << "<EXP> -> NUM " << endl;
  }
  private:
   int num;
 };

class idNode : public Node
 {
 public:
  idNode(string s) : Node(){
 idv = s; 
}
 virtual void print(ostream * out=0){
  cout << "<ID> " <<endl;
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
  assignNode (Node* n1, string s2, Node* n2) : Node(){
   node1 = n1;
   node2 = n2;
   svalue = s2;
  
} 
virtual void print(ostream * out=0){
   cout << "<ID> " << svalue << " <EXP>"<<endl;
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

  

#endif
