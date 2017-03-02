#include "Node.hpp"

class CycleInfo {
public:
  unsigned int start;
  unsigned int length;
};

bool isCyclic(Node *);
CycleInfo *cycleInfo(Node *);
