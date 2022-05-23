#include "linkedList.cpp"

int main() {
  LinkedList<int> llInt;
  LinkedList<std::string> llStr;
  std::cout << std::endl << "_____START____ " << std::endl;

  llInt.push(1);
  llInt.push(2);
  llInt.push(3);
  llInt.push(4);
  llInt.print();
  int val1 = llInt.pop();
  std::cout << "val1 " << val1 << std::endl;
  int val2 = llInt.pop();
  std::cout << "val2 " << val2 << std::endl;
  llInt.print();

  llStr.push("hello");
  llStr.push("again");
  llStr.push("does");
  llStr.push("this");
  llStr.push("work?");
  llStr.print();
  std::string str1 = llStr.pop();
  std::cout << "val1 " << str1 << std::endl;
  std::string str2 = llStr.pop();
  std::cout << "val2 " << str2 << std::endl;
  llStr.print();
}
