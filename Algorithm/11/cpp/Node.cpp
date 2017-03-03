#include <cstdlib>
#include <climits>

#include "Node.hpp"

using namespace std;

Node * const Node::NIL = new Node(0, NULL);

Node::Node(int i, Node *n) {
	item = i;
	next = n;
}

int Node::getItem() {
	return item;
}

Node *Node::getNext() {
	return next;
}

void Node::setItem(int i) {
	item = i;
}

void Node::setNext(Node *n) {
	next = n;
}

int Node::nthItem(unsigned int i) {
	Node* tempHead = this;
	int counter = 0;
	while (counter != i) {
		tempHead = tempHead->getNext();
		counter++;
	}
	return tempHead->getItem();
}

Node *Node::nthNext(unsigned int i) {
	Node* tempHead = this;
	int counter = 0;
	while (counter != i) {
		tempHead = tempHead->getNext();
		counter++;
	}
	return tempHead->getNext();
}

unsigned int Node::length() {
	Node* list = this;
	int counter = 0;

	if (list == Node::NIL) {
		return 0;//if list is NIL then return 0
	}
	else
        //else, while the list is not NIL then access the next node
		while (list != Node::NIL) {
			list = list->getNext();
            //increment counter by 1
			counter++;
		}
	return counter;//returns counter
}

Node *Node::remove(int i) {
    //delList calls this
	Node* delList = this;

	if (delList == Node::NIL) {
		return Node::NIL;//if node is Node::NIL then return NIL
	}
	else if (delList->getItem() == i) {
        //if delList (this) is i then move onto the next node
		return delList->getNext()->remove(i);
	}
	else {
        //else returns a new node with delList's value and removes the rest of the list and its next value
		return new Node(delList->getItem(), delList->getNext()->remove(i));
	}
}

Node *Node::reverse() {
    //tempNode calls this and newList is has the varible NIL
    Node* tempNode = this;
    Node* newList = Node::NIL;
    
	if (tempNode == Node::NIL) {
		return Node::NIL;//if node is Node::NIL then return NIL
	}
	else if (tempNode->getNext() == Node::NIL) {
        //if tempNode then return a copy of the tempNode = this
		return new Node(tempNode->getItem(), tempNode->getNext());
	}
	else {
    //else, while it is not the end of the list then tempNode is at the top
	while (tempNode != Node::NIL) {
		newList = new Node(tempNode->getItem(), newList);
		tempNode = tempNode->getNext();

	}
    //this will return the newList
	return newList;
}
}

int Node::sum() {
	if (this != NIL)
		return getItem() + getNext()->sum();
	else
		return 0;
}

/*
 * Local Variables:
 * compile-command: "make -k Node && ./Node Basic"
 * End:
 */
