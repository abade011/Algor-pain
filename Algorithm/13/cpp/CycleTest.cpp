#include <cmath>
#include <chrono>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "Node.hpp"
#include "CycleInfo.hpp"

class CycleTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(CycleTest);
  CPPUNIT_TEST(testNoncyclicDetection);
  CPPUNIT_TEST(testSmallCyclicDetection);
  CPPUNIT_TEST(testRandomCyclicDetection);
  CPPUNIT_TEST(testNoncyclicInfo);
  CPPUNIT_TEST(testSmallCyclicInfo);
  CPPUNIT_TEST(testRandomCyclicInfo);
  CPPUNIT_TEST_SUITE_END();
public:
  void testNoncyclicDetection();
  void testSmallCyclicDetection();
  void testRandomCyclicDetection();
  void testNoncyclicInfo();
  void testSmallCyclicInfo();
  void testRandomCyclicInfo();
};

void CycleTest::testNoncyclicDetection() {
  CPPUNIT_ASSERT_MESSAGE("Node::NIL is not cyclic by definition", !isCyclic(Node::NIL));
  Node *n = new Node(1, Node::NIL);
  CPPUNIT_ASSERT_MESSAGE("A one-element list is not cyclic", !isCyclic(n));
  Node *nn = new Node(2, n);
  CPPUNIT_ASSERT_MESSAGE("A two-element list is not cyclic", !isCyclic(nn));
  delete n;
  delete nn;
}

void CycleTest::testNoncyclicInfo() {
  CPPUNIT_ASSERT_MESSAGE("Node::NIL's CycleInfo should be NULL by definition", NULL == cycleInfo(Node::NIL));
  Node *n = new Node(1, Node::NIL);
  CPPUNIT_ASSERT_MESSAGE("A one-element list's CycleInfo should be NULL", NULL == cycleInfo(n));
  Node *nn = new Node(2, n);
  CPPUNIT_ASSERT_MESSAGE("A two-element list's CycleInfo should be NULL", NULL == cycleInfo(nn));
  delete n;
  delete nn;
}

void CycleTest::testSmallCyclicDetection() {
  Node *n = new Node(1, Node::NIL);
  n->setNext(n);
  CPPUNIT_ASSERT_MESSAGE("A one-element cyclic list should be detected as cyclic", isCyclic(n));
  Node *nn = new Node(2, n);
  CPPUNIT_ASSERT_MESSAGE("A two-element list with a cycle at the end should be detected as cyclic", isCyclic(nn));
  n->setNext(nn);
  CPPUNIT_ASSERT_MESSAGE("A two-element list cycling back to the start should be detected as cyclic", isCyclic(nn));
  CPPUNIT_ASSERT_MESSAGE("A two-element list cycling back to the start should be detected as cyclic wherever you start", isCyclic(n));
  delete n;
  delete nn;
}

void CycleTest::testSmallCyclicInfo() {
  Node *n = new Node(1, Node::NIL);
  n->setNext(n);
  CycleInfo *cn = cycleInfo(n);
  CPPUNIT_ASSERT_MESSAGE("A one-element cyclic list should be detected as cyclic", NULL != cn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("A one-element cyclic list's cycle starts at 0", 0U, cn->start);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("A one-element cyclic list's cycle's length is 1", 1U, cn->length);
  Node *nn = new Node(2, n);
  delete cn;
  CycleInfo *cnn = cycleInfo(nn);
  CPPUNIT_ASSERT_MESSAGE("A two-element list with a cycle at the end should be detected as cyclic", NULL != cnn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("A two-element list with a cycle at the end's cycle starts at 1", 1U, cnn->start);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("A two-element list with a cycle at the end's cycle's length is 1", 1U, cnn->length);
  delete cnn;
  n->setNext(nn);
  cn = cycleInfo(n);
  cnn = cycleInfo(nn);
  CPPUNIT_ASSERT_MESSAGE("A two-element list cycling back to the start should be detected as cyclic", NULL != cnn);
  CPPUNIT_ASSERT_MESSAGE("A two-element list cycling back to the start should be detected as cyclic wherever you start", NULL != cn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("A two-element cyclic list's cycle starts at 0", 0U, cnn->start);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("A two-element cyclic list's cycle has length 2", 2U, cnn->length);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("A two-element cyclic list's cycle starts at 0 wherever you start", 0U, cn->start);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("A two-element cyclic list's cycle has length 2 wherever you start", 2U, cn->length);
  delete cn;
  delete cnn;
  delete n;
  delete nn;
}

void CycleTest::testRandomCyclicDetection() {
  Node *n = new Node(0, Node::NIL);
  Node *tail = n;
  for (int i = 1; i < 100; i++) {
    n = new Node(i, n);
  }
  int start = rand() % 100;
  Node *head = n;
  for (int i = 0; i < start; i++) {
    head = head->getNext();
  }
  tail->setNext(head);
  CPPUNIT_ASSERT_MESSAGE("A randomly-made cyclic list should be detected as cyclic", isCyclic(n));
  for (int i = 0; i < 100; i++) {
    Node *next = n->getNext();
    delete n;
    n = next;
  }
}

void CycleTest::testRandomCyclicInfo() {
  Node *n = new Node(0, Node::NIL);
  Node *tail = n;
  for (int i = 1; i < 100; i++) {
    n = new Node(i, n);
  }
  int start = rand() % 100;
  Node *head = n;
  for (int i = 0; i < start; i++) {
    head = head->getNext();
  }
  tail->setNext(head);
  CycleInfo *cn = cycleInfo(n);
  CPPUNIT_ASSERT_MESSAGE("A randomly-made cyclic list should be detected as cyclic", NULL != cn);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The start of a cycle in a randomly-made cyclic list should be detected correctly", (unsigned int) start, cn->start);
  CPPUNIT_ASSERT_EQUAL_MESSAGE("The length of a cycle in a randomly-made cyclic list should be detected correctly", (unsigned int) 100-start, cn->length);
  for (int i = 0; i < 100; i++) {
    Node *next = n->getNext();
    delete n;
    n = next;
  }
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CycleTest, "Cycle");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Cycle");

int main(int argc, char *argv[]) {
  if (argc > 2) {
    std::cerr << "Usage: " << argv[0] << " [suitename]" << std::endl;
    return 1;
  }

  CppUnit::Test *test;
  CppUnit::TextUi::TestRunner runner;
  if (argc == 2)
    test = CppUnit::TestFactoryRegistry::getRegistry(argv[1]).makeTest();
  else
    test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  runner.addTest(test);
  runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), std::cerr));

  bool wasSuccessful = runner.run();
  return wasSuccessful ? 0 : 1;
}
