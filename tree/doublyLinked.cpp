
#include <iostream>

#include "node.cpp"

template <typename F>
bool filter(F a, F b) {
  return a == b;
};

template <typename T>
class DoublyLinked {
  Node<T> *head;
  Node<T> *tail;
  int size;

  bool includes(T value, Node<T> *node, bool (*filterFunc)(T a, T b)) {
    if ((*filterFunc)(value, node->value)) {
      return true;
    } else {
      if (node->next) {
        return includes(value, node->next, filterFunc);
      }
      return false;
    }
  }

  bool includes(T *value, Node<T> *node, bool (*filterFunc)(T *a, T *b)) {
    if ((*filterFunc)(value, node->value)) {
      return true;
    } else {
      if (node->next) {
        return includes(value, node->next, filterFunc);
      }
      return false;
    }
  }

 public:
  DoublyLinked() {
    size = 0;
    head = NULL;
    tail = NULL;
  };
  ;
  int push(T *newValue) {
    std::cout << '\n' << "PUSHING new value" << '\n';
    std::cout << "newValue data " << newValue->data << '\n';
    std::cout << "newValue id " << newValue->id << '\n';
    std::cout << "newValue parent Id " << newValue->parent->id << '\n';
    // std::cout << "tail " << tail << '\n';
    // std::cout << "head " << head << '\n';

    Node<T> *nextTail = new Node<T>;
    nextTail->prev = tail;
    nextTail->next = NULL;
    nextTail->value = newValue;
    if (tail != NULL) {
      tail->next = nextTail;
    }
    tail = nextTail;
    size++;
    if (head == NULL) {
      head = tail;
    }
    return size;
  };

  T pop() {
    if (tail != NULL) {
      T *value = tail->value;
      Node<T> *nextTail = tail->prev;
      nextTail->next = NULL;
      delete tail;
      tail = nextTail;
      size--;
      return value;
    } else {
      T empty;
      return empty;
    }
  };

  int shift(T value) {
    Node<T> *nextHead = new Node<T>;
    nextHead->prev = NULL;
    nextHead->next = head;
    nextHead->value = *value;
    if (head != NULL) {
      head->prev = nextHead;
    }
    head = nextHead;
    size++;
    if (tail == NULL) {
      tail = head;
    }
    return size;
  };

  T unShift() {
    if (head != NULL) {
      T *value = head->value;
      Node<T> *nextHead = head->next;
      nextHead->prev = NULL;
      delete head;
      head = nextHead;
      size--;
      return value;
    } else {
      T empty;
      return empty;
    }
  };
  int length() {
    return size;
  };

  bool includes(T value, bool (*newFilterFunc)(T a, T b) = filter<T>) {
    return includes(value, head, newFilterFunc);
  }
  bool includes(T *value, bool (*newFilterFunc)(T *a, T *b) = filter<T>) {
    return includes(value, head, newFilterFunc);
  }

  void each(void (*newFilterFunc)(T *a)) {
    includes(head, newFilterFunc);
  }
  void each(void (*newFilterFunc)(T a)) {
    includes(head, newFilterFunc);
  }

  DoublyLinked<T> *gather(T *(*gatherFunc)(T *a)) {
    DoublyLinked<T> *gathered = new DoublyLinked<T>;
    Node<T> *listNode = head;
    while (listNode) {
      T *gatheredValue = gatherFunc(listNode->value);
      if (gatheredValue) {
        gathered->push(gatheredValue);
      }
      listNode = listNode->next;
    }
    return gathered;
  }

  void print() {
    std::cout << std::endl;
    Node<T> *listHead = head;
    std::cout << "list value " << listHead->value << std::endl;
    do {
      listHead = listHead->next;
      std::cout << "list value " << listHead->value << std::endl;
    } while (listHead->next != NULL);
    std::cout << "Length " << size << std::endl;
    std::cout << std::endl;
  };
};
