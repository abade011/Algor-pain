#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class ExtendedNodeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(ExtendedNodeTest);
  CPPUNIT_TEST(testNthItem);
  CPPUNIT_TEST(testNthNext);  
  CPPUNIT_TEST_SUITE_END();

  Node *n;
  Node *ncirc;
public:
  void setUp() {
    n = new Node(17, new Node(34, new Node(3, Node::NIL)));
    ncirc = new Node(2, new Node(3, Node::NIL));
    ncirc->getNext()->setNext(ncirc);
  };
  void tearDown() {
    Node *tmp;
    while (n != Node::NIL && n != NULL) {
      tmp = n->getNext();
      delete n;
      n = tmp;
    }
    delete ncirc->getNext();
    delete ncirc;
  };

  void testNthItem();
  void testNthNext();
};

#include <cstdlib>

void ExtendedNodeTest::testNthItem() {
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right first (index 0) item from nthItem()", 17, n->nthItem(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right second (index 1) item from nthItem()", 34, n->nthItem(1));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right third (index 2) item from nthItem()", 3, n->nthItem(2));
  for (int k = 0; k < 100; k++) {
    int i = rand() % 1000;
    CPPUNIT_ASSERT_EQUAL(ncirc->nthItem(i % 2), ncirc->nthItem(i));
  }
}

void ExtendedNodeTest::testNthNext() {
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right first (index 0) next from nthNext()", n->getNext(), n->nthNext(0));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right second (index 1) next from nthNext()", n->getNext()->getNext(), n->nthNext(1));
  CPPUNIT_ASSERT_EQUAL_MESSAGE("Not getting the right third (index 2) next from nthNext()", Node::NIL, n->nthNext(2));
  for (int k = 0; k < 100; k++) {
    int i = rand() % 1000;
    CPPUNIT_ASSERT_EQUAL(ncirc->nthNext(i % 2), ncirc->nthNext(i));
  }
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(ExtendedNodeTest, "Extended");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Extended");
