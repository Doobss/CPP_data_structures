#include <iostream>



struct Node {
  int value;
  struct Node * next;
};



class LinkedList {

  struct Node * head;
  int size;

  public:
  LinkedList();
  int push(int value);
  int pop();
  int length();
  void printLength();
  void printHead();
  void print();

};




LinkedList::LinkedList() {
  size = 0;
  head = NULL;
};



int LinkedList::push(int value) {
  struct Node * nextHead = new Node;
  nextHead -> next = head;
  nextHead -> value = value;
  head = nextHead;
  size++;
  return size;
}


int LinkedList::pop() {
  int value = head -> value;
  struct Node * nextHead = head -> next;
  delete head;
  head = nextHead;
  size--;
  return value;
}

int LinkedList::length() {
  return size;
}

void LinkedList::printLength() {
  std::cout << "Length " << size << std::endl;
}

void LinkedList::printHead() {
  struct Node listHead = * head;
  std::cout << "listHead.value " << listHead.value << std::endl;
  std::cout << "listHead.next " << listHead.next << std::endl;
}

void LinkedList::print() {
  std::cout << std::endl;
  struct Node listHead = * head;
  std::cout << "list value " << listHead.value << std::endl;
  do {
    listHead = * listHead.next;
    std::cout << "list value " << listHead.value << std::endl;
  } while ( listHead.next != NULL );
  std::cout << "list length " << size << std::endl;
  std::cout << std::endl;
}


int main() {
  LinkedList ll;
  std::cout << std::endl << "_____START____ " << std::endl;

  ll.push(1);
  ll.push(2);
  ll.push(3);
  ll.push(4);
  ll.push(44);
  ll.push(4545);
  ll.push(234);
  ll.push(31);

  ll.print();
  int val1 = ll.pop();
  std::cout << "val1 " << val1 << std::endl;
  int val2 = ll.pop();
  std::cout << "val2 " << val2 << std::endl;
  ll.print();
}



// class LinkedList {

//   struct Node * head;
//   int size;

//   public:

//   LinkedList() {
//     size = 0;
//     head = NULL;
//   };



//   int push(int value) {
//     struct Node * nextHead = new Node;
//     nextHead -> next = head;
//     nextHead -> value = value;
//     head = nextHead;
//     size++;
//     return size;
//   }


//   int pop() {
//     int value = head -> value;
//     struct Node * nextHead = head -> next;
//     delete head;
//     head = nextHead;
//     size--;
//     return value;
//   }

//   int length() {
//     return size;
//   }

//   void printLength() {
//     std::cout << "Length " << size << std::endl;
//   }

//   void printHead() {
//     struct Node listHead = * head;
//     std::cout << "listHead.value " << listHead.value << std::endl;
//     std::cout << "listHead.next " << listHead.next << std::endl;
//   }

//   void print() {
//     std::cout << std::endl;
//     struct Node listHead = * head;
//     std::cout << "list value " << listHead.value << std::endl;
//     do {
//       listHead = * listHead.next;
//       std::cout << "list value " << listHead.value << std::endl;
//     } while ( listHead.next != NULL );
//     std::cout << "list length " << size << std::endl;
//     std::cout << std::endl;
//   }

// };
