#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class BasicNodeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BasicNodeTest);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testGetItem);
  CPPUNIT_TEST(testSetItem);
  CPPUNIT_TEST(testSetNext);
  CPPUNIT_TEST_SUITE_END();
  
public:
  void setUp() { };
  void tearDown() { };

  void testConstructor();
  void testGetItem();
  void testSetItem();
  void testSetNext();
};

void BasicNodeTest::testConstructor() {
  Node *n = new Node(0, Node::NIL);
  CPPUNIT_ASSERT_MESSAGE("The Node constructor must never return NULL", n != NULL);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The Node constrctor must treat its first argument as the item (or getItem() isn't working yet)", 0, n->getItem());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The Node constructor must treat its second argument as the next node (or getNext() isn't working yet)", Node::NIL, n->getNext());
  Node *nn = new Node(104, n);
  CPPUNIT_ASSERT_MESSAGE("The Node constructor must never return NULL", nn != NULL);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The Node constrctor must treat its first argument as the item (or getItem() isn't working yet); something might be defaulting to 0", 104, nn->getItem());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The Node constructor must treat its second argument as the next node (or getNext() isn't working yet); something might be defaulting to Node::NIL", n, nn->getNext());
  delete n;
  delete nn;
}

#include <cstdlib>

void BasicNodeTest::testGetItem() {
  for (int k = 0; k < 100; k++) {
    int i = rand();
    Node *n = new Node(i, Node::NIL);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("getItem() returned something unexpected after a constructor", i, n->getItem());
    delete n;
  }
}

void BasicNodeTest::testSetItem() {
  Node *n = new Node(0, Node::NIL);
  for (int k = 0; k < 100; k++) {
    int i = rand();
    n->setItem(i);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("getItem() returned something unexpected after setItem()", i, n->getItem());
  }
  delete n;
}

void BasicNodeTest::testSetNext() {
  Node *n = new Node(1, Node::NIL);
  Node *nn = new Node(2, Node::NIL);
  n->setNext(nn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("getNext() returned something unexpected after setNext()", nn, n->getNext());
  nn->setNext(nn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("getNext() returned something unexpected after setNext()", nn, nn->getNext());
  delete nn;
  delete n;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BasicNodeTest, "Basic");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Basic");
