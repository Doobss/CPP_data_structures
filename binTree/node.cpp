#include <iostream>

template <typename V>
struct Node {
  V data;
  struct Node<V> *left;
  struct Node<V> *right;
};
