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
		return 0;
	}
	else
		while (list != Node::NIL) {
			list = list->getNext();
			counter++;
		}
	return counter;
}

Node *Node::remove(int i) {
	Node* delList = this;

	if (delList == Node::NIL) {
		return Node::NIL;
	}
	else if (delList->getItem() == i) {
		return delList->getNext()->remove(i);
	}
	else {
		return new Node(delList->getItem(), delList->getNext()->remove(i));
	}
}

Node *Node::reverse() {

	if (this == Node::NIL) {
		return Node::NIL;
	}
	else if (this->getNext() == Node::NIL) {
		return new Node(this->getItem(), this->getNext());
	}
	else {
	Node* tempNode = this;
	Node* newList = Node::NIL;

	while (tempNode != Node::NIL) {
		newList = new Node(tempNode->getItem(), newList);
		tempNode = tempNode->getNext();

	}
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
