// #include "node.cpp"
#include "doublyLinked.cpp"

template <typename F>
bool defaultTreeFilter(F *a, F *b)
{
  return a->data == b->data && a->id == b->id;
};

template <typename F>
F *defaultGather(F *a)
{
  if (a->data > 2)
  {
    return a;
  }
  else
  {
    return NULL;
  }
};

template <typename D, typename I>
class Tree
{
public:
  I id;
  D data;
  Tree<D, I> *parent;
  DoublyLinked<Tree<D, I>> *children;
  Tree(D newData, I treeId = 0, Tree<D, I> *treeParent = NULL, DoublyLinked<Tree<D, I>> *treeChildren = NULL)
  {
    data = newData;
    id = treeId;
    parent = treeParent;
    if (treeChildren)
    {
      children = treeChildren;
    }
    else
    {
      children = new DoublyLinked<Tree<D, I>>;
    }
  }

  Tree<D, I> addChild(D newData)
  {
    I newId = id + 1 + children->length();
    Tree<D, I> *child = new Tree<D, I>(newData, newId, this);
    children->push(child);
    return *child;
  }

  bool includes(Tree<D, I> *searchData, bool (*treeFilter)(Tree<D, I> *a, Tree<D, I> *b) = defaultTreeFilter<Tree<D, I>>)
  {
    return children->includes(searchData, treeFilter);
  }

  DoublyLinked<Tree<D, I>> *gather(Tree<D, I> *(gatherFunc)(Tree<D, I> *a) = defaultGather<Tree<D, I>>)
  {
    return children->gather(gatherFunc);
  }

  void print()
  {
    std::cout << '\n';
    std::cout << "TREE id  " << id << '\n';
    std::cout << "tree data  " << data << '\n';
    std::cout << "tree number children  " << children->length() << '\n';
    if (parent)
    {
      std::cout << "tree parent id  " << parent->id << '\n';
    }
    else
    {
      std::cout << "tree has no parent  " << '\n';
    }
    std::cout << '\n';
  }
};