#include "Node.hpp"
#include "ListVisualiser.hpp"

int main() {
  Node *a = new Node(1, new Node(11, new Node(23, Node::NIL)));
  ListVisualiser::visualise(a);
  return 0;
}
