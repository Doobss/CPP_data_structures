
#include <iostream>
#include "node.cpp"

template <typename T>
class Array
{

  Node<T> *head;
  Node<T> *tail;
  int size;
  Node<T> *store[8];

public:
  Array()
  {
    size = 0;
    head = NULL;
    tail = NULL;
  };
  ;
  int push(T value)
  {

    Node<T> *nextTail = new Node<T>;
    nextTail->prev = tail;
    nextTail->next = NULL;
    nextTail->value = value;
    if (tail != NULL)
    {
      tail->next = nextTail;
    }
    store[size] = tail;
    tail = nextTail;
    size++;
    if (head == NULL)
    {
      head = tail;
    }
    return size;
  };
  T pop()
  {
    if (tail != NULL)
    {
      T value = tail->value;
      Node<T> *nextTail = tail->prev;
      nextTail->next = NULL;
      delete tail;
      tail = nextTail;
      size--;
      return value;
    }
    else
    {
      T empty;
      return empty;
    }
  };
  int shift(T value)
  {
    Node<T> *nextHead = new Node<T>;
    nextHead->prev = NULL;
    nextHead->next = head;
    nextHead->value = value;
    if (head != NULL)
    {
      head->prev = nextHead;
    }
    head = nextHead;
    size++;
    if (tail == NULL)
    {
      tail = head;
    }
    return size;
  };
  T unShift()
  {
    if (head != NULL)
    {
      T value = head->value;
      Node<T> *nextHead = head->next;
      nextHead->prev = NULL;
      delete head;
      head = nextHead;
      size--;
      return value;
    }
    else
    {
      T empty;
      return empty;
    }
  };
  int length()
  {
    return size;
  };
  T index(int valueIndex)
  {
    if (size - 1 > valueIndex)
    {
      Node<T> *nodeRef = store[valueIndex];
      Node<T> arrayNode = *nodeRef;
      return arrayNode.value;
    }
    else
    {
      T empty;
      return empty;
    }
  };
  void print()
  {
    std::cout << std::endl;
    Node<T> *listHead = head;
    std::cout << "list value " << listHead->value << std::endl;
    do
    {
      listHead = listHead->next;
      std::cout << "list value " << listHead->value << std::endl;
    } while (listHead->next != NULL);
    std::cout << "Length " << size << std::endl;
    std::cout << std::endl;
  };
};

int main()
{
  Array<int> arrInt;
  std::cout << std::endl
            << "_____START____ " << std::endl;

  arrInt.push(1);
  arrInt.push(2);
  arrInt.push(3);
  arrInt.push(4);
  // arrInt.shift(0);
  // arrInt.shift(-1);
  // arrInt.shift(-2);
  int index1 = arrInt.index(1);
  std::cout << "index1 " << index1 << std::endl;

  int index2 = arrInt.index(2);
  std::cout << "index2 " << index2 << std::endl;

  int index234 = arrInt.index(234);
  std::cout << "index234 " << index234 << std::endl;
  arrInt.print();

  // int val1 = arr.pop();
  // std::cout << "val1 " << val1 << std::endl;
  // int val2 = arr.unShift();
  // std::cout << "val2 " << val2 << std::endl;
  // arr.print();

  Array<std::string> arrStr;
  arrStr.push("hello");
  arrStr.push("again");
  arrStr.push("does");
  arrStr.push("this");
  arrStr.push("work?");
  arrStr.print();
  std::string str1 = arrStr.pop();
  std::cout << "val1 " << str1 << std::endl;
  std::string str2 = arrStr.pop();
  std::cout << "val2 " << str2 << std::endl;
  arrStr.print();
}
