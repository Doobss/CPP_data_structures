#include <cmath>

#include "../linkedList/linkedList.cpp"
#include "node.cpp"

template <typename C>
C compare(C a, C b) {
  return a - b;
};

template <typename N>
bool defaultGather(N *a) {
  return 500 > a->id;
};

// auto f = [](int a, int b) -> int { return a + b; };

template <typename N>
auto manageMemoryGather(int gatherValue) {
  return [gatherValue](N *a) -> N * {
    if (gatherValue > a->id) {
      return a;
    }
    return NULL;
  };
};

template <typename T>

class BinTree {
  typedef BinNode<T> BN;
  typedef BinNode<T> *BNP;
  typedef bool (*gatherFuncType)(BNP a);
  typedef T (*compareFuncType)(T a, T b);
  BNP head;
  long nodes;
  long long int nodeSum;
  int maxId;

  compareFuncType comparison;

  bool insert(BNP base, BNP inserted) {
    if (inserted->id > maxId) {
      maxId = inserted->id;
    }
    bool inRange = false;
    std::cout << '\n';
    std::cout << "base id  " << base->id << " inserted id " << inserted->id << '\n';
    int averageId = (nodeSum + inserted->id) / (nodes + 1);
    int rightLeftDif = 0;
    bool unquieInserted = true;
    if (base->right != NULL && base->left != NULL) {
      rightLeftDif = base->right->id - base->left->id;
      unquieInserted = base->right->id != inserted->id && base->left->id != inserted->id;
    }
    if (base->right != NULL && base->left == NULL) {
      rightLeftDif = base->right->id;
      unquieInserted = base->right->id != inserted->id;
    }
    if (base->right == NULL && base->left != NULL) {
      rightLeftDif = -base->left->id;
      unquieInserted = base->left->id != inserted->id;
    }
    int baseDif = std::abs(base->id - rightLeftDif);
    int insertedDif = std::abs(inserted->id - rightLeftDif);
    // int aveBaseDif = std::abs(base->id - averageId);
    // int aveInsertedDif = std::abs(inserted->id - averageId);
    int aveBaseDif = std::abs(base->id - (maxId / 2));
    int aveInsertedDif = std::abs(inserted->id - (maxId / 2));

    std::cout << "baseDif " << baseDif << " insertedDef " << insertedDif << " rightleftDif " << rightLeftDif << '\n';
    std::cout << "aveBaseDif " << aveBaseDif << " aveInsertedDif " << aveInsertedDif << " averageId " << averageId << '\n';
    // if (baseDif > insertedDif && aveBaseDif > aveInsertedDif) {
    if (baseDif >= insertedDif && unquieInserted) {
      BNP tmpNode = base->clone();
      base->id = inserted->id;
      base->data = inserted->data;

      inserted->id = tmpNode->id;
      inserted->data = tmpNode->data;
      delete tmpNode;
      std::cout << "SWAPPED base id  " << base->id << " SWAPPED inserted id " << inserted->id << '\n';
      // return insert(base, inserted);
      // return insert(head, inserted);
    }

    int compareValue = comparison(base->id, inserted->id);

    if (compareValue > 0) {  // base is larger than inserted

      if (base->left != NULL) {
        return insert(base->left, inserted);
      } else {
        std::cout << "NEW LEFT base id  " << base->id << " NEW inserted id " << inserted->id << '\n';
        base->left = inserted;
        nodes++;
        nodeSum += inserted->id;
        return true;
      }
    }
    if (compareValue < 0) {  // base is smaller base 5 inserted 7

      if (base->right != NULL) {
        return insert(base->right, inserted);

      } else {
        base->right = inserted;
        nodes++;
        nodeSum += inserted->id;
        std::cout << "NEW RIGHT base id  " << base->id << " NEW inserted id " << inserted->id << '\n';
        return true;
      }
    }
    std::cout << "BREAK ALEADY INSERTED  " << base->id << " inserted id " << inserted->id << '\n';
    return false;
  };

  BNP find(int id, BNP searchNode, bool returnClosest = false, int ignoreId = -1) {
    std::cout << "Node id " << searchNode->id << " search Value " << id << " return " << returnClosest << '\n';
    if (id == searchNode->id && searchNode->id != ignoreId) {
      return searchNode;
    } else {
      int compareValue = comparison(searchNode->id, id);
      if (compareValue > 0) {
        if (searchNode->left) {
          if (searchNode->left->id != ignoreId) {
            return find(id, searchNode->left, returnClosest, ignoreId);
          }
          return searchNode;
        } else {
          if (returnClosest) {
            return searchNode;
          }
          return NULL;
        }
      } else {
        if (searchNode->right) {
          if (searchNode->right->id != ignoreId) {
            return find(id, searchNode->right, returnClosest, ignoreId);
          }
          return searchNode;
        } else {
          if (returnClosest) {
            return searchNode;
          }
          return NULL;
        }
      }
    }
  };

  // void gather(BNP node, bool (*gatherFunc)(BNP a), LinkedList<T> *gatheredData) {
  void gather(BNP node, auto gatherFunc, LinkedList<T> *gatheredData) {
    bool gatherNode = gatherFunc(node);
    if (gatherNode) {
      gatheredData->push(node->id);
    }
    if (node->left) {
      gather(node->left, gatherFunc, gatheredData);
    }
    if (node->right) {
      gather(node->right, gatherFunc, gatheredData);
    }
  };

 public:
  BinTree(compareFuncType compareFunc = compare<int>) {
    head = NULL;
    nodes = 0;
    nodeSum = 0;
    maxId = 0;
    comparison = compareFunc;
  };

  bool insert(T data) {
    std::cout << '\n' << "Inserting " << data << '\n';
    bool returned;
    BNP newNode = new BinNode<T>(data);
    if (head != NULL) {
      returned = insert(head, newNode);
    } else {
      head = newNode;
      maxId = head->id;
      nodes++;
      nodeSum += head->id;
      returned = true;
    }
    // manageTree();
    return returned;
  }

  bool includes(int nodeId) {
    BNP node = find(nodeId, head);
    if (node) {
      return true;
    }
    return false;
  };

  BNP find(int nodeId) {
    std::cout << '\n';
    return find(nodeId, head);
  };

  LinkedList<T> *gather(std::function<bool(BNP)> gatherFunc) {
    // auto gather(auto gatherFunc = defaultGather<BinNode<T>>) {
    LinkedList<T> *newGatheredData = new LinkedList<T>;
    gather(head, gatherFunc, newGatheredData);
    return newGatheredData;
  };

  LinkedList<T> *gather(gatherFuncType gatherFunc = defaultGather<BinNode<T>>) {
    LinkedList<T> *newGatheredData = new LinkedList<T>;
    gather(head, gatherFunc, newGatheredData);
    return newGatheredData;
  };

  void stats() {
    long int averageNodeId = nodeSum / nodes;
    std::cout << "Nodes " << nodes << '\n';
    std::cout << "Node sum " << nodeSum << '\n';
    std::cout << "Head val " << head->id << '\n';
    std::cout << "Average node Id " << averageNodeId << '\n';
  }
};

// std::function<bool(BinNode<T> *)> gatherFunc = [&](BinNode<T> *a) -> bool {
//   if (gatherValue > a->id) {
//     return true;
//   }
//   return false;
// };
// LinkedList<T> *gatheredValues = gather(gatherFunc);
// std::cout << "Gathered values, there are  " << gatheredValues->length() << " values " << '\n';
// delete head;
// head = newHead;
// auto listNode = gatheredValues->head;
// while (listNode != NULL) {
//   std::cout << "Inserting value " << listNode->value << '\n';
//   insert(listNode->value);
//   listNode = listNode->next;
// }

// BinNode<T> *findAndUpdateNode(BinNode<T> *node) {
//   T id = node->id;
//   BinNode<T> *newNode = new BinNode<T>(id);

//   std::cout << '\n' << "updating node " << id << '\n';
//   BinNode<T> *newRight = find(id + 1, head, true, id);
//   std::cout << "FOUND Right node id " << newRight->id << '\n';
//   if (newRight->id > id) {
//     newNode->right = newRight;
//     // newNode->right = findAndUpdateNode(newRight);
//   }

//   BinNode<T> *newLeft = find(id - 1, head, true, id);
//   std::cout << "FOUND Left node id " << newLeft->id << '\n';
//   if (newLeft->id < id) {
//     newNode->left = newLeft;
//     // newNode->left = findAndUpdateNode(newLeft);
//   }
//   std::cout << '\n';
//   std::cout << "newNode id " << newNode->id << '\n';
//   if (newNode->right) {
//     std::cout << "newNode right id " << newNode->right->id << '\n';
//   } else {
//     std::cout << "No newNode right " << '\n';
//   }
//   if (newNode->left) {
//     std::cout << "newNode left id " << newNode->left->id << '\n';
//   } else {
//     std::cout << "No newNode left " << '\n';
//   }
//   return newNode;
// }

// bool manageTree() {
//   long int averageNodeId = nodeSum / nodes;
//   long int aveNodeHeadDifference = averageNodeId - head->id;
//   // if (aveNodeHeadDifference > 25 ) {  // 300 is an arbitrary testing num currently
//   if (nodes >= 10) {  // 300 is an arbitrary testing num currently

//     std::cout << "Managing memory " << '\n';
//     std::cout << "averageNodeId " << averageNodeId << '\n';
//     std::cout << "aveNodeHeadDifference " << aveNodeHeadDifference << '\n';
//     BinNode<T> *newHead = find(averageNodeId, head, true);
//     std::cout << "Found new head " << newHead->id << '\n';
//     // delete head;
//     newHead = findAndUpdateNode(newHead);
//     std::cout << "New Head id " << head->id << '\n';
//     head = newHead;
//     return true;
//   }
//   return true;
// }
