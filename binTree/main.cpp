#include "binTree.cpp"

bool searchForValues(BinTree<int> bt) {
  bool found, search;
  int searchValue;
  search = true;
  while (search) {
    std::cout << "Please enter a value to searchfor Enter -1 to quit " << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> searchValue;
    if (searchValue == -1) {
      search = false;
    } else {
      found = bt.includes(searchValue);
      std::cout << "Search result for " << searchValue << " = " << found << '\n';
    }
    // std::cout << "Search again? 0 = no, 1 = yes " << '\n';
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // std::cin >> search;
  }
  std::cout << "Finised search " << '\n';
  return true;
};

bool gatherValues(BinTree<int> bt) {
  LinkedList<int>* gathered = bt.gather();
  gathered->print();
  std::cout << " Linkedlist length " << gathered->length() << '\n';
  return true;
}

bool runInsertions(BinTree<int> bt) {
  int insertions, range, value;
  bool inserted;
  std::cout << "Please Enter the number of insertions" << '\n';
  std::cin >> insertions;
  std::cout << "Please Enter the range of random integers to choose from." << '\n';
  std::cin >> range;
  while (insertions--) {
    inserted = false;
    while (!inserted) {
      value = rand() % range;
      inserted = bt.insert(value + 1);
    }
  }

  gatherValues(bt);
  searchForValues(bt);
  bt.stats();
  return true;
};

int main() {
  bool finishedFunc;
  BinTree<int> bt;
  finishedFunc = runInsertions(bt);
};
