#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class ReverseNodeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(ReverseNodeTest);
  CPPUNIT_TEST(testReverseOfNIL);
  CPPUNIT_TEST(testReverse1);
  CPPUNIT_TEST(testReverse2);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testReverseOfNIL();
  void testReverse1();
  void testReverse2();
};

void ReverseNodeTest::testReverseOfNIL() {
  Node *n = Node::NIL->reverse();
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What should the reverse of NIL be?", Node::NIL, n);
}

void ReverseNodeTest::testReverse1() {
  Node *n = new Node(1, Node::NIL);
  Node *r = n->reverse();
  CPPUNIT_ASSERT_MESSAGE("reverse must return a fresh list", r != n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("reverse should not change the length of the list", 1U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the first item of a reversed one-element list is the same as the first element of the original", 1, r->getItem());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("reverse of a one-element list should be a one-element list", Node::NIL, r->getNext());
  /* we're going to ignore memory leaks from ->reverse() for now */
  delete n;
}

void ReverseNodeTest::testReverse2() {
  Node *n = new Node(1, Node::NIL);
  Node *nn = new Node(2, n);
  Node *r = nn->reverse();
  CPPUNIT_ASSERT_MESSAGE("reverse must return a fresh list", r != n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("reverse must not change the length of the list", 2U, r->length());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the second item becomes the first", 1, r->getItem());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("the first item becomes the second", 2, r->getNext()->getItem());
  CPPUNIT_ASSERT_EQUAL_MESSAGE("reverse of a two-element list should be a two-element list", Node::NIL, r->getNext()->getNext());
  /* again, ignoring memory leaks from ->reverse() */
  delete n;
  delete nn;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(ReverseNodeTest, "Reverse");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Reverse");
