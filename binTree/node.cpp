#include <iostream>

template <typename V>
class BinNode {
 public:
  typedef BinNode<V> *BNP;
  V data;
  int id;
  BNP left;
  BNP right;
  BinNode(V newData, BNP newLeft = NULL, BNP newRight = NULL) {
    data = newData;
    id = newData;
    left = newLeft;
    right = newRight;
  };
  BNP clone() {
    return new BinNode<V>(*this);
  }
};
