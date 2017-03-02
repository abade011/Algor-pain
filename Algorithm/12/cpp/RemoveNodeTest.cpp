#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class RemoveNodeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(RemoveNodeTest);
  CPPUNIT_TEST(testRemoveOfNIL);
  CPPUNIT_TEST(testRemove1);
  CPPUNIT_TEST(testRemove2);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testRemoveOfNIL();
  void testRemove1();
  void testRemove2();
};

void RemoveNodeTest::testRemoveOfNIL() {
  Node *n = Node::NIL->remove(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What can you remove from NIL?", Node::NIL, n);
  n = Node::NIL->remove(0);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What can you remove from NIL?", Node::NIL, n);
}

void RemoveNodeTest::testRemove1() {
  Node *n = new Node(1, Node::NIL);
  Node *r = n->remove(0);
  CPPUNIT_ASSERT_MESSAGE("remove must return a fresh list", r != n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change the length", 1U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change any item", 1, r->getItem());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change the next field", Node::NIL, r->getNext());
  /* we're going to ignore memory leaks from ->remove() for now */
  r = n->remove(1);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing the only item present gives a length zero list", 0U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the only length zero list is NIL", Node::NIL, r);
  delete n;
}

void RemoveNodeTest::testRemove2() {
  Node *n = new Node(1, Node::NIL);
  Node *nn = new Node(2, n);
  Node *r = nn->remove(0);
  CPPUNIT_ASSERT_MESSAGE("remove must return a fresh list", r != nn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change the length", 2U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change any item", 2, r->getItem());
  CPPUNIT_ASSERT_MESSAGE("remove must return a completely fresh list", r->getNext() != n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change any item", 1, r->getNext()->getItem());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("removing an object not present doesn't change the next fields", Node::NIL, r->getNext()->getNext());
  /* again, ignoring memory leaks from ->remove() */
  r = nn->remove(1);
  CPPUNIT_ASSERT_MESSAGE("remove must return a fresh list", r != nn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("remove of an object present will change the length", 1U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("remove of an object present can change which item is first", 2, r->getItem());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("remove of an object present will change the list structure", Node::NIL, r->getNext());
  
  delete n;
  delete nn;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(RemoveNodeTest, "Remove");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Remove");
