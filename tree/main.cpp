#include "tree.cpp"

int main() {
  Tree<int, int> root(0);
  // root.addChild(1);
  Tree<int, int> rootChild1 = root.addChild(1);
  Tree<int, int> rootChild2 = root.addChild(2);
  Tree<int, int> rootChild3 = root.addChild(3);
  Tree<int, int> rootChild4 = root.addChild(23);
  Tree<int, int> rootChild5 = root.addChild(6);
  Tree<int, int> rootChild6 = root.addChild(34);
  DoublyLinked<Tree<int, int>> *gathered = root.gather();
  std::cout << '\n' << "Gathered size " << gathered->length() << '\n';

  Tree<int, int> root1(3);

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