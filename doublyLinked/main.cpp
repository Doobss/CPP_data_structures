#include "doublyLinked.cpp"

int main() {
  DoublyLinked<int> dlInt;
  DoublyLinked<std::string> dlStr;
  std::cout << std::endl << "_____START____ " << std::endl;

  dlInt.push(1);
  dlInt.push(2);
  dlInt.push(3);
  dlInt.push(4);
  dlInt.shift(0);
  dlInt.shift(-1);
  dlInt.shift(-2);

  dlInt.print();
  bool found;
  int value = -2;
  found = dlInt.includes(value);
  std::cout << "Includes value " << value << " res = " << found << '\n';

  int val1 = dlInt.pop();
  std::cout << "val1 " << val1 << std::endl;
  int val2 = dlInt.unShift();
  std::cout << "val2 " << val2 << std::endl;
  dlInt.print();

  value = 1;
  found = dlInt.includes(value);
  std::cout << "Includes value " << value << " res = " << found << '\n';
  value = 3;
  found = dlInt.includes(value);
  std::cout << "Includes value " << value << " res = " << found << '\n';
  value = 5;
  found = dlInt.includes(value);
  std::cout << "Includes value " << value << " res = " << found << '\n';
  value = -1;
  found = dlInt.includes(value);
  std::cout << "Includes value " << value << " res = " << found << '\n';
  value = -2;
  found = dlInt.includes(value);
  std::cout << "Includes value " << value << " res = " << found << '\n';

  // dlStr.push("hello");
  // dlStr.push("again");
  // dlStr.push("does");
  // dlStr.push("this");
  // dlStr.push("work?");
  // dlStr.print();
  // dlStr.shift("Ahhhhhh");
  // dlStr.shift("shifted");
  // std::string str1 = dlStr.pop();
  // std::cout << "val1 " << str1 << std::endl;
  // std::string str2 = dlStr.pop();
  // std::cout << "val2 " << str2 << std::endl;
  // dlStr.print();
}
