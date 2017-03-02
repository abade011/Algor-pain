#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
  Node(int, Node *);
  static Node * const NIL;

  //Week 11
  int item;
  Node *next;

  //Week 12
  int sum();
  int max();
  Node* append(Node* appending);
  Node* merge(Node* merging);

  Node *getNext();
  int getItem();
  void setItem(int);
  void setNext(Node *);

  int nthItem(unsigned int);
  Node *nthNext(unsigned int);
  
  unsigned int length();
  Node *remove(int i);
  Node *reverse();
};

#endif
