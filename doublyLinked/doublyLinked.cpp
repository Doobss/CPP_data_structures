
#include <iostream>
#include "node.cpp"

template <typename T>
class DoublyLinked
{

  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  DoublyLinked()
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
  DoublyLinked<int> dlInt;
  DoublyLinked<std::string> dlStr;
  std::cout << std::endl
            << "_____START____ " << std::endl;

  dlInt.push(1);
  dlInt.push(2);
  dlInt.push(3);
  dlInt.push(4);
  dlInt.shift(0);
  dlInt.shift(-1);
  dlInt.shift(-2);

  dlInt.print();
  int val1 = dlInt.pop();
  std::cout << "val1 " << val1 << std::endl;
  int val2 = dlInt.unShift();
  std::cout << "val2 " << val2 << std::endl;
  dlInt.print();

  dlStr.push("hello");
  dlStr.push("again");
  dlStr.push("does");
  dlStr.push("this");
  dlStr.push("work?");
  dlStr.print();
  dlStr.shift("Ahhhhhh");
  dlStr.shift("shifted");
  std::string str1 = dlStr.pop();
  std::cout << "val1 " << str1 << std::endl;
  std::string str2 = dlStr.pop();
  std::cout << "val2 " << str2 << std::endl;
  dlStr.print();
}
