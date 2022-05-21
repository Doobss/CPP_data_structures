#include "binIdTree.cpp"

bool searchForValues(BinIdTree<int, int> bt)
{
  try
  {
    bool found, search;
    int searchValue;
    search = true;
    while (search)
    {
      std::cout << "Please enter a value to searchfor " << '\n';
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> searchValue;
      found = bt.includes(searchValue);
      std::cout << "Search result for " << searchValue << " = " << found << '\n';
      std::cout << "Search again? 0 = no, 1 = yes " << '\n';
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> search;
    }

    std::cout << "Finised search " << '\n';
    bt.stats();
    return true;
  }
  catch (std::runtime_error &e)
  {
    std::cerr << "Error in searchForValues" << e.what() << '\n';
    return false;
  }
};

bool runInsertions(BinIdTree<int, int> bt)
{
  try
  {
    int insertions, range, value;
    bool inserted;
    std::cout << "Please Enter the number of insertions" << '\n';
    std::cin >> insertions;
    std::cout << "Please Enter the range of random integers to choose from." << '\n';
    std::cin >> range;
    while (insertions--)
    {
      inserted = false;
      while (!inserted)
      {
        value = rand() % range;
        inserted = bt.insert(value);
      }
      // std::cout << "Inserts left " << insertions << '\n';
    }

    searchForValues(bt);
    return true;
  }

  catch (std::runtime_error &e)
  {
    std::cerr << "Error in runInsertions" << e.what() << '\n';
    return false;
  }
}

int main()
{
  try
  {
    bool finishedFunc;
    BinIdTree<int, int> bt;
    finishedFunc = runInsertions(bt);
    // finishedFunc = searchForValues(bt);
  }
  catch (std::runtime_error &e)
  {
    std::cout << "Error in main" << e.what() << '\n';
  }
};
