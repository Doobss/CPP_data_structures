
#include <iostream>

#include "node.cpp"

template <typename T>
class Array {
  int size;
  int storeSize;
  int minSize;
  T *store;

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
      T *nextStore = new T[newStoreSize];
      for (int i = 0; i < size; i++) {
        nextStore[i] = store[i];
      }
      store = nextStore;
      std::cout << "NEW StoreSize " << newStoreSize << "   OLD StoreSize " << storeSize << '\n';
      storeSize = newStoreSize;
    }
  };

 public:
  Array() {
    size = 0;
    minSize = 4;
    storeSize = 8;
    store = new T[storeSize];
    // std::cout << "store " << store << '\n';
  };
  ;
  int push(T value) {
    store[size] = value;
    size++;
    manageMemory();
    return size;
  };
  T pop() {
    T value, empty;
    value = store[size];
    store[size] = empty;
    size--;
    manageMemory();
    return value;
  };
  int shift(T value) {
    std::cout << "SHIFT NOT IMP YET";
    size++;
    return size;
  };
  T unShift() {
    T value, empty;
    value = store[0];
    std::cout << "UNSHIFT NOT IMP YET";
    size--;
    manageMemory();
    return value;
  };
  int length() {
    return size;
  };
  T index(int valueIndex) {
    if (size - 1 > valueIndex) {
      return store[valueIndex];
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
    T value;
    for (int i = 0; size > i; i++) {
      value = store[i];
      (*funcPtr)(value, i);
    }
  };

  Array<T> map(T (*funcPtr)(T value, int index)) {
    Array<T> newArray;
    T value, newValue;
    for (int i = 0; size > i; i++) {
      value = store[i];
      newValue = (*funcPtr)(value, i);
      newArray.push(newValue);
    }
    return newArray;
  };
};

// void printStore()
// {
//   Ystored;
//   int i = 0;
//   do
//   {
//     stored = store[i];
//     // std::cout << "Store address " << store + i << " Store value " << stored.value << " index " << i << '\n';
//     std::cout << "Store value " << stored.value << " index " << i << '\n';
//     i++;
//   } while (size > i);
//   std::cout << "Length " << size << '\n';
//   std::cout << '\n';
// };

// void printTotalStore()
// {
//   Ystored;
//   int i = 0;
//   do
//   {
//     stored = store[i];
//     // std::cout << "Store address " << store + i << " Store value " << stored.value << " index " << i << '\n';
//     std::cout << "Store value " << stored.value << " index " << i << '\n';
//     i++;
//   } while (storeSize > i);
//   std::cout << "storeSize " << storeSize << '\n';
//   std::cout << '\n';
// };