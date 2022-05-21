
#include <iostream>

#include "node.cpp"

template <typename T>
class LinkedArray {
  Node<T> *head;
  Node<T> *tail;
  int size;
  int storeSize;
  int minSize;
  Node<T> *store;

  void manageMemory() {
    int emptySpaces, newStoreSize;
    emptySpaces = storeSize - size;
    newStoreSize = storeSize;

    if (storeSize == size + 1) {
      newStoreSize = storeSize + storeSize;
    }
    if (emptySpaces > size && size > minSize) {
      newStoreSize = storeSize / 2;
    }

    if (newStoreSize != storeSize) {
      Node<T> *nextStore = new Node<T>[newStoreSize];
      for (int i = 0; i < size; i++) {
        nextStore[i] = store[i];
      }
      store = nextStore;
      std::cout << "NEW StoreSize " << newStoreSize << "   OLD StoreSize " << storeSize << '\n';
      storeSize = newStoreSize;
    }
  };

 public:
  LinkedArray() {
    size = 0;
    minSize = 4;
    storeSize = 8;
    store = new Node<T>[storeSize];
    // std::cout << "store " << store << '\n';
    head = NULL;
    tail = NULL;
  };

  int push(T value) {
    Node<T> *nextTail = new Node<T>;
    nextTail->prev = tail;
    nextTail->next = NULL;
    nextTail->value = value;
    if (tail != NULL) {
      tail->next = nextTail;
    }

    tail = nextTail;
    store[size] = *tail;
    size++;

    if (head == NULL) {
      head = tail;
    }

    manageMemory();
    return size;
  };

  T pop() {
    if (tail != NULL) {
      T value = tail->value;
      Node<T> *nextTail = tail->prev;
      nextTail->next = NULL;
      delete tail;
      Node<T> arrTail = store[size];
      arrTail.next = NULL;
      arrTail.prev = NULL;
      T empty;
      arrTail.value = empty;
      // Node<T> *nextArrTail = new Node<T>;
      // store[size] = *nextArrTail;
      tail = nextTail;
      size--;
      manageMemory();
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
    nextHead->value = value;
    if (head != NULL) {
      head->prev = nextHead;
    }
    head = nextHead;
    size++;
    if (tail == NULL) {
      tail = head;
    }
    manageMemory();
    return size;
  };

  T unShift() {
    if (head != NULL) {
      T value = head->value;
      Node<T> *nextHead = head->next;
      nextHead->prev = NULL;
      delete head;
      head = nextHead;
      size--;
      manageMemory();
      return value;
    } else {
      T empty;
      return empty;
    }
  };

  int length() {
    return size;
  };

  T index(int valueIndex) {
    if (size - 1 > valueIndex) {
      Node<T> LinkedArrayNode = store[valueIndex];
      return LinkedArrayNode.value;
    } else {
      T empty;
      return empty;
    }
  };

  void printStats() {
    std::cout << '\n' << "Printing STATS " << '\n';
    std::cout << "MAX store size " << storeSize << '\n';
    std::cout << "MIN store size " << minSize << '\n';
    std::cout << "Current size " << size << '\n';
    std::cout << '\n';
  };

  void each(void (*funcPtr)(T value, int index)) {
    Node<T> stored;
    for (int i = 0; size > i; i++) {
      stored = store[i];
      (*funcPtr)(stored.value, i);
    }
  };

  LinkedArray<T> map(T (*funcPtr)(T value, int index)) {
    LinkedArray<T> newLinkedArray;
    T newValue;
    Node<T> stored;
    for (int i = 0; size > i; i++) {
      stored = store[i];
      newValue = (*funcPtr)(stored.value, i);
      newLinkedArray.push(newValue);
    }
    return newLinkedArray;
  };
};
