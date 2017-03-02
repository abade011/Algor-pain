#include <cmath>
#include <chrono>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "BinarySearch.hpp"

class BinarySearchTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BinarySearchTest);
  CPPUNIT_TEST(testZeroLengthSearch);
  CPPUNIT_TEST(testSmallSearch);
  CPPUNIT_TEST(testSearchScaling);
  CPPUNIT_TEST_SUITE_END();
private:
  static const int NCASES = 20;
  int *arrays2[NCASES];
public:
  void setUp() {
    for (int i = 0; i < NCASES; i++) {
      int n = pow(2, i);
      arrays2[i] = new int[n];
      for (int j = 0; j < n; j++)
        arrays2[i][j] = j;
    }
  };
  void tearDown() {
    for (int i = 0; i < NCASES; i++) {
      delete[] arrays2[i];
    }
  };

  void testZeroLengthSearch();
  void testSmallSearch();
  void testSearchScaling();
};

void BinarySearchTest::testZeroLengthSearch() {
  int x[0];
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty array", !BinarySearch::search(x, 0, 0, 0));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty array", !BinarySearch::search(x, 1, 0, 0));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty array", !BinarySearch::search(x, 2, 0, 0));
  int y[4] = {0,2,3,4};
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty search", !BinarySearch::search(y, 0, 0, 0));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty search", !BinarySearch::search(y, 1, 1, 1));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty search", !BinarySearch::search(y, 2, 2, 2));
  CPPUNIT_ASSERT_MESSAGE("nothing is in an empty search", !BinarySearch::search(y, 4, 3, 3));
}

void BinarySearchTest::testSmallSearch() {
  int x[4] = {0,2,4,6};
  CPPUNIT_ASSERT_MESSAGE("-2 is not in {0,2,4,6}", !BinarySearch::search(x, -2, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("-1 is not in {0,2,4,6}", !BinarySearch::search(x, -1, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("0 is in {0,2,4,6}", BinarySearch::search(x, 0, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("1 is not in {0,2,4,6}", !BinarySearch::search(x, 1, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("2 is in {0,2,4,6}", BinarySearch::search(x, 2, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("3 is not in {0,2,4,6}", !BinarySearch::search(x, 3, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("4 is in {0,2,4,6}", BinarySearch::search(x, 4, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("5 is not in {0,2,4,6}", !BinarySearch::search(x, 5, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("6 is in {0,2,4,6}", BinarySearch::search(x, 6, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("7 is not in {0,2,4,6}", !BinarySearch::search(x, 7, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("8 is not in {0,2,4,6}", !BinarySearch::search(x, 8, 0, 4));
  CPPUNIT_ASSERT_MESSAGE("4 is not in the first half of {0,2,4,6}", !BinarySearch::search(x, 4, 0, 2));
  CPPUNIT_ASSERT_MESSAGE("2 is not in the second half of {0,2,4,6}", !BinarySearch::search(x, 2, 2, 4));
}

void BinarySearchTest::testSearchScaling() {
  int i;
  const int count = 10000;
  std::chrono::duration<double> diff, diff2;
  for (i = 0; i < NCASES-1; i++) {
    int n = pow(2, i);
    auto start = std::chrono::steady_clock::now();
    for (int j = 0; j < count; j++) {
      bool result = BinarySearch::search(arrays2[i], 0, 0, n);
      result = BinarySearch::search(arrays2[i], n-1, 0, n);
    }
    auto end = std::chrono::steady_clock::now();
    diff = end - start;
    if (diff.count() > 0.25) {
      i++;
      break;
    }
  }
  int n = pow(2, i);
  auto start = std::chrono::steady_clock::now();
  for (int j = 0; j < count; j++) {
    bool result = BinarySearch::search(arrays2[i], 0, 0, n);
    result = BinarySearch::search(arrays2[i], n-1, 0, n);
  }
  auto end = std::chrono::steady_clock::now();
  diff2 = end - start;
  double ratio = diff2.count() / diff.count();
  CPPUNIT_ASSERT_MESSAGE("binary search should scale logarithmically", ratio > 0.95);
  CPPUNIT_ASSERT_MESSAGE("binary search should scale logarithmically", ratio < 1.2);
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BinarySearchTest, "BinarySearch");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("BinarySearch");


/* FIXME: more boilerplate */
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
