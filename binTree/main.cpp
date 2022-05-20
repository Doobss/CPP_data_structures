#include "binTree.cpp"

void runInsertions(BinTree<int> bt)
{
  int insertions, value;
  std::cout << "Please Enter the number of insertions" << '\n';
  std::cin >> insertions;
  while (insertions--)
  {
    value = rand() % 1000;
    bt.insert(value);
    // std::cout << "Inserts left " << insertions << '\n';
  }
  bool found;
  int searchValue;
  searchValue = 33;
  found = bt.includes(searchValue);
  std::cout << "Searching for " << searchValue << " res " << found << '\n';
  searchValue = 56;
  found = bt.includes(searchValue);
  std::cout << "Searching for " << searchValue << " res " << found << '\n';
  searchValue = 45;
  found = bt.includes(searchValue);
  std::cout << "Searching for " << searchValue << " res " << found << '\n';
  bt.stats();
}

int main()
{
  BinTree<int> bt;
  runInsertions(bt);
};
