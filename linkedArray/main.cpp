#include <iostream>
#include "array.cpp"

void eachTest(int value, int index)
{
  std::cout << "EACH "
            << " value " << value << " index " << index << '\n';
};

int mapTest(int value, int index)
{
  return value + 100;
};

Array<int> generateArray()
{
  Array<int> newArray;
  int arrayLength, newValue, i;
  std::cout << "Please enter an array length" << '\n';
  std::cin >> arrayLength;
  for (i = 0; arrayLength > i; i++)
  {
    newValue = rand() % 100; // v1 in the range 0 to 99
    newArray.push(newValue);
  }
  return newArray;
};

Array<int> halfArray(Array<int> toHalf)
{
  int arrayLength, halfIndex, i;
  arrayLength = toHalf.length();
  halfIndex = (arrayLength / 2);
  for (i = 0; halfIndex > i; i++)
  {
    toHalf.pop();
  }
  return toHalf;
};

int main()
{
  std::cout << "_____START____ " << '\n';
  Array<int> arrInt = generateArray();
  std::cout << "Generated array length " << arrInt.length() << '\n';

  std::cout << "Printing generated" << '\n';
  arrInt.each(eachTest);
  arrInt.printStats();
  Array<int> mapped = arrInt.map(mapTest);
  std::cout << "Printing mapped" << '\n';
  mapped.each(eachTest);
  mapped.printStats();
  mapped = halfArray(mapped);
  mapped.printStats();

  // Array<std::string> arrStr;
  // arrStr.push("hello");
  // arrStr.push("again");
  // arrStr.push("does");
  // arrStr.push("this");
  // arrStr.push("work?");
  // arrStr.print();
  // std::string str1 = arrStr.pop();
  // std::cout << "val1 " << str1 << '\n';
  // std::string str2 = arrStr.pop();
  // std::cout << "val2 " << str2 << '\n';
  // arrStr.print();
}