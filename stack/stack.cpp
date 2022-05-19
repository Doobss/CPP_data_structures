

#include <iostream>






struct Node {
  int value;
  struct Node * next;
};


class LinkedList {

  struct Node head;
  struct Node tail;
  int size;

  public:

  LinkedList() {
    struct Node firstNode = { .next = NULL };
    head = firstNode;
    tail = firstNode;
    size = 0;
  };

  int push(int value) {

    if ( size == 0 ) {
      head.value = value;
    }

    struct Node nextTail = { .value = value, .next = NULL };
    tail.next = & nextTail;
    tail = nextTail;
    size++;
    return size;
  }

  int length() {
    return size;
  }

  void printHead(bool newLine = true) {
    if ( newLine ) {
      std::cout << "Head value " << head.value << std::endl;
    }
    else {
      std::cout << "Head value " << head.value << " ";
    }
  }

  void printTail(bool newLine = true) {
    if ( newLine ) {
      std::cout << "Tail value " << tail.value << std::endl;
    }
    else {
      std::cout << "Tail value " << tail.value << " ";
    }
  }

    void printLength(bool newLine = true) {
    if ( newLine ) {
      std::cout << "Length " << size << std::endl;
    }
    else {
      std::cout << "Length " << size << " ";
    }
  }

  void print() {
    std::cout << std::endl;
    printHead();
    printTail();
    printLength();
    std::cout << std::endl;
  }

};


int main() {
  LinkedList ll;
  ll.print();
  ll.push(1);
  ll.print();
  ll.push(2);
  ll.print();
}