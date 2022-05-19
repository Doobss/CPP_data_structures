
#include <iostream>



struct Node {
  int value;
  struct Node * next;
  struct Node * prev;
};



class DoublyLinked {

  struct Node * head;
  struct Node * tail;
  int size;

  public:
  DoublyLinked();
  int push(int value);
  int pop();
  int shift(int value);
  int unShift();
  int length();
  void print();
};




DoublyLinked::DoublyLinked() {
  size = 0;
  head = NULL;
  tail = NULL;
};



int DoublyLinked::push(int value) {

  struct Node * nextTail = new Node;
  nextTail -> prev = tail;
  nextTail -> next = NULL;
  nextTail -> value = value;
  if ( tail != NULL ) {
    tail -> next = nextTail;
  }
  tail = nextTail;
  size++;
  if ( head == NULL ) {
    head = tail;
  }
  return size;
}


int DoublyLinked::pop() {
  if ( tail != NULL ) {
    int value = tail -> value;
    struct Node * nextTail = tail -> prev;
    nextTail -> next = NULL;
    delete tail;
    tail = nextTail;
    size--;
    return value;
  }
  else {
    return -1;
  }
}


int DoublyLinked::shift(int value) {
  struct Node * nextHead = new Node;
  nextHead -> prev = NULL;
  nextHead -> next = head;
  nextHead -> value = value;
  if( head != NULL ) {
    head -> prev = nextHead;
  }
  head = nextHead;
  size++;
  if ( tail == NULL ) {
    tail = head;
  }
  return size;
}



int DoublyLinked::unShift() {
  if ( head != NULL ) {
    int value = head -> value;
    struct Node * nextHead = head -> next;
    nextHead -> prev = NULL;
    delete head;
    head = nextHead;
    size--;
    return value;
  }
  else {
    return -1;
  }
}

int DoublyLinked::length() {
  return size;
}


void DoublyLinked::print() {
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
  DoublyLinked dl;
  std::cout << std::endl << "_____START____ " << std::endl;

  dl.push(1);
  dl.push(2);
  dl.push(3);
  dl.push(4);
  dl.shift(0);
  dl.shift(-1);
  dl.shift(-2);

  dl.print();
  int val1 = dl.pop();
  std::cout << "val1 " << val1 << std::endl;
  int val2 = dl.unShift();
  std::cout << "val2 " << val2 << std::endl;
  dl.print();
}
