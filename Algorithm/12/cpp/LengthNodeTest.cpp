#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class LengthNodeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(LengthNodeTest);
  CPPUNIT_TEST(testLengthOfNIL);
  CPPUNIT_TEST(testLength);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testLengthOfNIL();
  void testLength();
};

void LengthNodeTest::testLengthOfNIL() {
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What is the length of NIL?", 0U, Node::NIL->length());
}

void LengthNodeTest::testLength() {
  Node *n = new Node(1, Node::NIL);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What is the length of a list whose next is NIL?", 1U, n->length());
  Node *nn = new Node(2, n);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("What is the length of a list whose next is a list with length 1?", 2U, nn->length());
  delete n;
  delete nn;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(LengthNodeTest, "Length");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Length");
