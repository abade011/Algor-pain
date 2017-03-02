#include <cmath>
#include <chrono>

#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class Timing12Test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(Timing12Test);
  CPPUNIT_TEST(testLengthTiming);
  CPPUNIT_TEST(testRemoveTiming);
  CPPUNIT_TEST(testReverseTiming);
  CPPUNIT_TEST_SUITE_END();
private:
  static const int NCASES = 20;
  Node *nodes2[NCASES];
public:
  void setUp() {
    for (int i = 0; i < NCASES; i++) {
      nodes2[i] = Node::NIL;
    }
    for (int i = 0; i < NCASES; i++) {
      int n = pow(2, i);
      for (int j = 0; j < n; j++) {
	nodes2[i] = new Node(j, nodes2[i]);
      }
    }
  };
  void tearDown() {
    for (int i = 0; i < NCASES; i++) {
      int count = 0, limit = pow(2,i); // defend against unimplemented ->getNext()
      Node *n = nodes2[i];
      while(n != Node::NIL && count++ < limit) {
	Node *d = n;
	n = n->getNext();
	delete d;
      }
    }
  };
  void testLengthTiming();
  void testRemoveTiming();
  void testReverseTiming();
};

void Timing12Test::testLengthTiming() {
  /* FIXME: should really abstract this to reuse below but
     metaprogramming C++ is hard */
  int i;
  std::chrono::duration<double> diff, diff2;
  for (i = 0; i < NCASES-1; i++) {
    auto start = std::chrono::steady_clock::now();
    unsigned int result = nodes2[i]->length();
    auto end = std::chrono::steady_clock::now();
    diff = end - start;
    if (diff.count() > 0.25) {
      i++;
      break;
    }
  }
  auto start = std::chrono::steady_clock::now();
  unsigned int result = nodes2[i]->length();
  auto end = std::chrono::steady_clock::now();
  diff2 = end - start;
  double ratio = diff2.count() / diff.count();
  CPPUNIT_ASSERT_MESSAGE("length should scale linearly with list size", ratio > 1.2);    
  CPPUNIT_ASSERT_MESSAGE("length should scale linearly with list size", ratio < 2.5);    
}

void Timing12Test::testRemoveTiming() {
  int i;
  std::chrono::duration<double> diff, diff2;
  for (i = 0; i < NCASES-1; i++) {
    auto start = std::chrono::steady_clock::now();
    Node *result = nodes2[i]->remove(0);
    auto end = std::chrono::steady_clock::now();
    diff = end - start;
    if (diff.count() > 0.25) {
      i++;
      break;
    }
  }
  auto start = std::chrono::steady_clock::now();
  Node *result = nodes2[i]->remove(0);
  auto end = std::chrono::steady_clock::now();
  diff2 = end - start;
  double ratio = diff2.count() / diff.count();
  CPPUNIT_ASSERT_MESSAGE("remove should scale linearly with list size", ratio > 1.2);    
  CPPUNIT_ASSERT_MESSAGE("remove should scale linearly with list size", ratio < 2.5);    
}

void Timing12Test::testReverseTiming() {
  int i;
  std::chrono::duration<double> diff, diff2;
  for (i = 0; i < NCASES-1; i++) {
    auto start = std::chrono::steady_clock::now();
    Node *result = nodes2[i]->reverse();
    auto end = std::chrono::steady_clock::now();
    diff = end - start;
    if (diff.count() > 0.25) {
      i++;
      break;
    }
  }
  auto start = std::chrono::steady_clock::now();
  Node *result = nodes2[i]->reverse();
  auto end = std::chrono::steady_clock::now();
  diff2 = end - start;
  double ratio = diff2.count() / diff.count();
  CPPUNIT_ASSERT_MESSAGE("reverse should scale linearly with list size", ratio > 1.2);
  CPPUNIT_ASSERT_MESSAGE("reverse should scale linearly with list size", ratio < 2.5);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(Timing12Test, "Timing12");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Timing12");
