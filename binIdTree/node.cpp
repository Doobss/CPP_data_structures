#include <iostream>

template <typename I, typename D>
class Node {
  I buildId(D data) {
    I newId = data;
    return newId;
  }

 public:
  I id;
  D data;
  struct Node<I, D> *left;
  struct Node<I, D> *right;
  Node(D initData, Node<I, D> *initLeft = NULL, Node<I, D> *initRight = NULL) {
    id = buildId(initData);
    data = initData;
    left = initLeft;
    right = initRight;
  }
};
