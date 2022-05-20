#include "binTree.cpp"

void runInsertions(BinTree<int> bt)
{
  int insertions, value;
  std::cout << "Please Enter the number of insertions" << '\n';
  std::cin >> insertions;
  while (insertions--)
  {
    value = rand() % 100;
    bt.insert(value);
  }
}

int main()
{
  BinTree<int> bt;
  runInsertions(bt);

};
