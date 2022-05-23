#include "tree.cpp"

int main() {
  typedef Tree<int, int> Tree_type;
  Tree_type root(0);
  // root.addChild(1);
  Tree_type rootChild1 = root.addChild(1);
  Tree_type rootChild2 = root.addChild(2);
  Tree_type rootChild3 = root.addChild(3);
  Tree_type rootChild4 = root.addChild(23);
  Tree_type rootChild5 = root.addChild(6);
  Tree_type rootChild6 = root.addChild(34);
  DoublyLinked<Tree_type> *gathered = root.gather();
  std::cout << '\n' << "Gathered size " << gathered->length() << '\n';

  Tree_type root1(3);

  std::cout << '\n' << "Includes tests " << '\n';
  bool found;
  int value = 2;
  found = root.includes(&rootChild1);
  std::cout << "Includes value " << rootChild1.data << " res = " << found << '\n';
  found = root.includes(&root1);
  std::cout << "Includes value " << root1.data << " res = " << found << '\n';
  // value = 3;
  // found = root.includes(*rootChild1);
  // std::cout << "Includes value " << value << " res = " << found << '\n';
  // value = 5;
  // found = root.includes(*rootChild1);
  // std::cout << "Includes value " << value << " res = " << found << '\n';
  // // value = -1;
  // // found = root.includes(value);
  // // std::cout << "Includes value " << value << " res = " << found << '\n';
  // value = -2;
  // found = root.includes(*rootChild2);
  // std::cout << "Includes value " << value << " res = " << found << '\n';

  root.print();
  rootChild2.print();
};