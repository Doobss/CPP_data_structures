
#include <iostream>



struct Node {
  int value;
  struct Node * next;
  struct Node * prev;
};



class Array {

  struct Node * head;
  struct Node * tail;
  int size;
  struct Node * store[8];


  public:
  Array();
  int push(int value);
  int pop();
  int shift(int value);
  int unShift();
  int length();
  int index(int valueIndex);
  void print();
};




Array::Array() {
  size = 0;
  head = NULL;
  tail = NULL;
};



int Array::push(int value) {

  struct Node * nextTail = new Node;
  nextTail -> prev = tail;
  nextTail -> next = NULL;
  nextTail -> value = value;
  if ( tail != NULL ) {
    tail -> next = nextTail;
  }
  store[size] = tail;
  tail = nextTail;
  size++;
  if ( head == NULL ) {
    head = tail;
  }
  return size;
}


int Array::pop() {
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


int Array::shift(int value) {
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



int Array::unShift() {
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


int Array::index( int valueIndex ) {
  if ( size - 1 > valueIndex ) {
    struct Node * nodeRef = store[valueIndex];
    struct Node arrayNode = * nodeRef;
    return arrayNode.value;
  }
  else {
    return -1;
  }
}



int Array::length() {
  return size;
}


void Array::print() {
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
  Array arr;
  std::cout << std::endl << "_____START____ " << std::endl;

  arr.push(1);
  arr.push(2);
  arr.push(3);
  arr.push(4);
  // arr.shift(0);
  // arr.shift(-1);
  // arr.shift(-2);
  int index1 = arr.index(1);
  std::cout << "index1 " << index1 << std::endl;

  int index2 = arr.index(2);
  std::cout << "index2 " << index2 << std::endl;


  int index234 = arr.index(234);
  std::cout << "index234 " << index234 << std::endl;
  arr.print();
  // int val1 = arr.pop();
  // std::cout << "val1 " << val1 << std::endl;
  // int val2 = arr.unShift();
  // std::cout << "val2 " << val2 << std::endl;
  // arr.print();
}
