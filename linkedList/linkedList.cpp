#include <iostream>
#include "node.cpp"

template <typename T>
class LinkedList
{

  struct Node<T> *head;
  int size;

public:
  LinkedList()
  {
    size = 0;
    head = NULL;
  };

  int push(T value)
  {
    Node<T> *nextHead = new Node<T>;
    nextHead->next = head;
    nextHead->value = value;
    head = nextHead;
    size++;
    return size;
  };

  T pop()
  {
    T value = head->value;
    Node<T> *nextHead = head->next;
    delete head;
    head = nextHead;
    size--;
    return value;
  };
  int length()
  {
    return size;
  };
  void printLength()
  {
    std::cout << "Length " << size << std::endl;
  };
  void printHead()
  {
    Node<T> listHead = *head;
    std::cout << "listHead.value " << listHead.value << std::endl;
    std::cout << "listHead.next " << listHead.next << std::endl;
  };
  void print()
  {
    std::cout << std::endl;
    Node<T> listHead = *head;
    std::cout << "list value " << listHead.value << std::endl;
    do
    {
      listHead = *listHead.next;
      std::cout << "list value " << listHead.value << std::endl;
    } while (listHead.next != NULL);
    std::cout << "list length " << size << std::endl;
    std::cout << std::endl;
  };
};

int main()
{
  LinkedList<int> llInt;
  LinkedList<std::string> llStr;
  std::cout << std::endl
            << "_____START____ " << std::endl;

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
