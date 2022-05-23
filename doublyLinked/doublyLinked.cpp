
#include <iostream>

#include "node.cpp"

template <typename F>
bool filter(F a, F b) {
  return a == b;
};

template <typename T>
class DoublyLinked {
  typedef Node<T> *Node_ref_type;
  typedef bool (*filter_func_type)(T a, T b);
  Node_ref_type head;
  Node_ref_type tail;
  int size;

  bool includes(T value, Node_ref_type node, filter_func_type filter_func) {
    if (filter_func(value, node->value)) {
      return true;
    } else {
      if (node->next) {
        return includes(value, node->next, filter_func);
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
  int push(T value) {
    Node_ref_type next_tail = new Node<T>;
    next_tail->prev = tail;
    next_tail->next = NULL;
    next_tail->value = value;
    if (tail != NULL) {
      tail->next = next_tail;
    }
    tail = next_tail;
    size++;
    if (head == NULL) {
      head = tail;
    }
    return size;
  };
  T pop() {
    if (tail != NULL) {
      T value = tail->value;
      Node_ref_type next_tail = tail->prev;
      next_tail->next = NULL;
      delete tail;
      tail = next_tail;
      size--;
      return value;
    } else {
      T empty;
      return empty;
    }
  };
  int shift(T value) {
    Node_ref_type next_head = new Node<T>;
    next_head->prev = NULL;
    next_head->next = head;
    next_head->value = value;
    if (head != NULL) {
      head->prev = next_head;
    }
    head = next_head;
    size++;
    if (tail == NULL) {
      tail = head;
    }
    return size;
  };
  T unShift() {
    if (head != NULL) {
      T value = head->value;
      Node_ref_type next_head = head->next;
      next_head->prev = NULL;
      delete head;
      head = next_head;
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

  bool includes(T value, filter_func_type new_filter_func = filter<T>) {
    return includes(value, head, new_filter_func);
  }
  void print() {
    std::cout << std::endl;
    Node_ref_type list_head = head;
    std::cout << "list value " << list_head->value << std::endl;
    do {
      list_head = list_head->next;
      std::cout << "list value " << list_head->value << std::endl;
    } while (list_head->next != NULL);
    std::cout << "Length " << size << std::endl;
    std::cout << std::endl;
  };
};
