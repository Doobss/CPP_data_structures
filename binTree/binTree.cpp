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
  long nodes;
  T (*comparison)
  (T a, T b);

  bool insert(Node<T> *base, Node<T> *added)
  {
    try
    {
      Node<T> *left = base->left;
      Node<T> *right = base->right;
      // std::cout << "base data " << base->data << " added data " << added->data << '\n';

      T compareValue = (*comparison)(base->data, added->data);
      if (compareValue > 0)
      {
        if (right != NULL)
        {
          // std::cout << "trav right " << '\n';
          return insert(right, added);
        }
        else
        {
          base->right = added;
          nodes++;
          sum += added->data;
          // std::cout << "ADDED right " << added->data << '\n';
          return true;
        }
      }
      if (compareValue < 0)
      {
        if (left != NULL)
        {
          // std::cout << "trav left " << '\n';
          return insert(left, added);
        }
        else
        {
          base->left = added;
          nodes++;
          sum += added->data;
          // std::cout << "ADDED left " << added->data << '\n';
          return true;
        }
      }

      // std::cout << "EQUAL not added " << added->data << '\n'
      // << '\n';
      return false;
    }
    catch (std::logic_error &e)
    {
      std::cerr << "LOGIC Error in BinTree<T>::insert(Node<T> *base, Node<T> *added)" << e.what() << '\n';
      return false;
    }
    catch (std::runtime_error &e)
    {
      std::cerr << "RUNTIME Error in BinTree<T>::insert(Node<T> *base, Node<T> *added)" << e.what() << '\n';
      return false;
    }
    catch (std::exception &e)
    {
      std::cerr << "Error in BinTree<T>::insert(Node<T> *base, Node<T> *added)" << e.what() << '\n';
      return false;
    }
  };

  bool includes(Node<T> *searchNode, T data)
  {
    try
    {
      std::cout << "Node data " << searchNode->data << " search Value " << data << '\n';
      if (data == searchNode->data)
      {
        return true;
      }
      else
      {
        int compareValue = (*comparison)(searchNode->data, data);
        if (compareValue > 0)
        {
          if (searchNode->right)
          {
            return includes(searchNode->right, data);
          }
          else
          {
            return false;
          }
        }
        else
        {
          if (searchNode->left)
          {
            return includes(searchNode->left, data);
          }
          else
          {
            return false;
          }
        }
      }
    }
    catch (std::logic_error &e)
    {
      std::cerr << "LOGIC Error in BinTree<T>::includes(Node<T> *searchNode, T data)" << e.what() << '\n';
      return false;
    }
    catch (std::runtime_error &e)
    {
      std::cerr << "RUNTIME Error in BinTree<T>::includes(Node<T> *searchNode, T data)" << e.what() << '\n';
      return false;
    }
    catch (std::exception &e)
    {
      std::cerr << "Error in BinTree<T>::includes(Node<T> *searchNode, T data)" << e.what() << '\n';
      return false;
    }
  };

public:
  BinTree(int (*compareFunc)(T a, T b) = compare<T>)
  {
    head = NULL;
    sum = 0;
    nodes = 0;
    comparison = compareFunc;
  };

  bool insert(T data)
  {
    try
    {
      if (head != NULL)
      {
        // std::cout << '\n'
        //           << "Begin Insert " << '\n'
        //           << '\n';
        Node<T> *newNode;
        newNode = new Node<T>;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return insert(head, newNode);
      }
      else
      {

        head = new Node<T>;
        head->data = data;
        head->left = NULL;
        head->right = NULL;
        nodes++;
        sum += head->data;
        return true;
      }
    }
    catch (std::exception &e)
    {
      std::cerr << "Error in BinTree<T>::insert(T data) " << e.what() << '\n';
      return false;
    }
  }

  bool includes(T data)
  {
    try
    {
      return includes(head, data);
    }
    catch (std::exception &e)
    {
      std::cerr << "Error in BinTree<T>::includes(T data) " << e.what() << '\n';
      return false;
    }
  }

  void stats()
  {
    std::cout << "Sum " << sum << '\n';
    std::cout << "Nodes " << nodes << '\n';
    std::cout << "Head val " << head->data << '\n';
  }
};
