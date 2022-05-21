#include "node.cpp"

template <typename C>
C compare(C a, C b) {
  return a - b;
};

template <typename I, typename T>
class BinIdTree {
  Node<I, T> *head;
  I sum;
  long nodes;
  I(*comparison)
  (I a, I b);

  bool insert(Node<I, T> *base, Node<I, T> *added) {
    try {
      Node<I, T> *left = base->left;
      Node<I, T> *right = base->right;
      I compareValue = (*comparison)(base->id, added->id);
      Node<I, T> *next = compareValue > 0 ? right : left;
      if (compareValue != added->id) {
        if (next != NULL) {
          return insert(next, added);
        } else {
          if (compareValue > 0) {
            base->right = added;
          } else {
            base->left = added;
          }
          nodes++;
          sum += added->id;
          return true;
        }
      }
      return false;
    } catch (std::logic_error &e) {
      std::cerr << "LOGIC Error in BinIdTree<T>::insert(Node<I, T> *base, Node<I, T> *added)" << e.what() << '\n';
      return false;
    } catch (std::runtime_error &e) {
      std::cerr << "RUNTIME Error in BinIdTree<T>::insert(Node<I, T> *base, Node<I, T> *added)" << e.what() << '\n';
      return false;
    } catch (std::exception &e) {
      std::cerr << "Error in BinIdTree<T>::insert(Node<I, T> *base, Node<I, T> *added)" << e.what() << '\n';
      return false;
    }
  };

  bool includes(Node<I, T> *searchNode, T id) {
    try {
      std::cout << "Node id " << searchNode->id << " search Value " << id << '\n';
      if (id == searchNode->id) {
        return true;
      } else {
        int compareValue = (*comparison)(searchNode->id, id);
        if (compareValue > 0) {
          if (searchNode->right) {
            return includes(searchNode->right, id);
          } else {
            return false;
          }
        } else {
          if (searchNode->left) {
            return includes(searchNode->left, id);
          } else {
            return false;
          }
        }
      }
    } catch (std::logic_error &e) {
      std::cerr << "LOGIC Error in BinIdTree<T>::includes(Node<I, T> *searchNode, T data)" << e.what() << '\n';
      return false;
    } catch (std::runtime_error &e) {
      std::cerr << "RUNTIME Error in BinIdTree<T>::includes(Node<I, T> *searchNode, T data)" << e.what() << '\n';
      return false;
    } catch (std::exception &e) {
      std::cerr << "Error in BinIdTree<T>::includes(Node<I, T> *searchNode, T data)" << e.what() << '\n';
      return false;
    }
  };

 public:
  BinIdTree(int (*compareFunc)(I a, I b) = compare<I>) {
    head = NULL;
    sum = 0;
    nodes = 0;
    comparison = compareFunc;
  };

  bool insert(T data) {
    try {
      if (head != NULL) {
        Node<I, T> *newNode;
        newNode = new Node<I, T>(data);
        std::cout << "Inserted vals "
                  << " data " << newNode->data << " id " << newNode->id << " left " << newNode->left << " right " << newNode->right << '\n';
        return insert(head, newNode);
      } else {
        head = new Node<I, T>(data);
        std::cout << "Inserted head vals "
                  << " data " << head->data << " id " << head->id << " left " << head->left << " right " << head->right << '\n';
        nodes++;
        sum += head->id;
        return true;
      }
    } catch (std::exception &e) {
      std::cerr << "Error in BinIdTree<T>::insert(T data) " << e.what() << '\n';
      return false;
    }
  }

  bool includes(T id) {
    try {
      return includes(head, id);
    } catch (std::exception &e) {
      std::cerr << "Error in BinIdTree<T>::includes(T data) " << e.what() << '\n';
      return false;
    }
  }

  void stats() {
    std::cout << "Sum " << sum << '\n';
    std::cout << "Nodes " << nodes << '\n';
    std::cout << "Head id " << head->id << '\n';
    std::cout << "Head data " << head->data << '\n';
  }
};
