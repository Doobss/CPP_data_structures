#include <iostream>

#include "node.cpp"

template <typename T>
class LinkedList {
  typedef Node<T> *NP;
  typedef std::function<void(NP)> each_callback;
  typedef std::function<bool(NP)> filter_callback;
  int size;

 public:
  struct Node<T> *head;
  LinkedList() {
    size = 0;
    head = NULL;
  };

  int push(T value) {
    Node<T> *nextHead = new Node<T>;
    nextHead->next = head;
    nextHead->value = value;
    head = nextHead;
    size++;
    return size;
  };

  T pop() {
    T value = head->value;
    Node<T> *nextHead = head->next;
    delete head;
    head = nextHead;
    size--;
    return value;
  };

  void each(each_callback for_each) {
    Node<T> *list_node = head;
    while (list_node != NULL) {
      for_each(list_node);
      list_node = list_node->next;
    }
  }

  LinkedList<T> *filter(filter_callback filter_func) {
    LinkedList<T> *filtered_list = new LinkedList<T>;
    Node<T> *list_node = head;
    bool add_to_new_list = false;
    while (list_node != NULL) {
      add_to_new_list = filter_func(list_node);
      if (add_to_new_list) {
        T added_data = list_node->value;
        std::cout << " pushing " << added_data->key << '\n';
        filtered_list->push(added_data);
      }
      list_node = list_node->next;
    }
    return filtered_list;
  }

  int length() {
    return size;
  };

  void printLength() {
    std::cout << "Length " << size << std::endl;
  };

  void printHead() {
    Node<T> listHead = *head;
    std::cout << "listHead.value " << listHead.value << std::endl;
    std::cout << "listHead.next " << listHead.next << std::endl;
  };

  void print() {
    std::cout << std::endl;
    Node<T> listHead = *head;
    std::cout << "list value " << listHead.value << std::endl;
    do {
      listHead = *listHead.next;
      std::cout << "list value " << listHead.value << std::endl;
    } while (listHead.next != NULL);
    std::cout << "list length " << size << std::endl;
    std::cout << std::endl;
  };
};
