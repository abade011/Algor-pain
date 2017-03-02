#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <cstddef>

class DynamicArray {
public:
  DynamicArray(size_t);
  size_t length();
  int select(size_t);
  void store(int, size_t);
  void push(int);
  int pop();
private:
  void extend();
};

#endif
