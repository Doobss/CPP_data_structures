#include "node.cpp"

template <typename C>
C compare(C a, C b)
{
  return a - b;
};

template <typename T>

class BinTree
{
  Node<T> *head;

  T sum;
  int nodes;
  T(*comparison)
  (T a, T b);

  void traverse(Node<T> *base, Node<T> *added)
  {
    Node<T> *left = base->left;
    Node<T> *right = base->right;
    std::cout << "base data " << base->data << " added data " << added->data << '\n';

    T compareValue = (*comparison)(base->data, added->data);
    if (compareValue > 0)
    {
      if (right != NULL)
      {
        std::cout << "trav right " << '\n';
        traverse(right, added);
      }
      else
      {
        base->right = added;
        std::cout << "ADDED right " << added->data << '\n';
      }
    }
    if (compareValue < 0)
    {
      if (left != NULL)
      {
        std::cout << "trav left " << '\n';
        traverse(left, added);
      }
      else
      {
        base->left = added;
        std::cout << "ADDED left " << added->data << '\n';
      }
    }
    if (compareValue == 0)
    {
      std::cout << '\n'
                << "EQUAL not added " << added->data << '\n';
    };
  };

public:
  BinTree(int (*compareFunc)(T a, T b) = compare<T>)
  {
    head = NULL;
    sum = 0;
    nodes = 0;
    comparison = compareFunc;
  };

  void insert(T data)
  {
    if (head != NULL)
    {
      Node<T> *newNode;
      newNode = new Node<T>;
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
      std::cout << '\n'
                << "Begin Insert " << '\n'
                << '\n';
      traverse(head, newNode);
      std::cout << '\n'
                << "End Insert " << '\n'
                << '\n';
      nodes++;
      sum += data;
    }
    else
    {
      head = new Node<T>;
      head->data = data;
      head->left = NULL;
      head->right = NULL;
      nodes++;
      sum += data;
    }
  };
};