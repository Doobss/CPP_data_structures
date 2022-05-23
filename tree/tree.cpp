// #include "node.cpp"
#include "doublyLinked.cpp"

template <typename F>
bool default_tree_filter(F *a, F *b) {
  return a->data == b->data && a->id == b->id;
};

template <typename F>
F *default_gather(F *a) {
  if (a->data > 2) {
    return a;
  } else {
    return NULL;
  }
};

template <typename D, typename I>
class Tree {
  typedef Tree<D, I> Tree_type;
  typedef Tree_type *Tree_ref_type;
  typedef Tree_ref_type (*gather_func_type)(Tree_ref_type a);
  typedef bool (*tree_filter_type)(Tree_ref_type a, Tree_ref_type b);
  typedef DoublyLinked<Tree_type> *children_type;

 public:
  I id;
  D data;
  Tree_ref_type parent;
  children_type children;
  Tree(D new_data, I tree_id = 0, Tree_ref_type tree_parent = NULL, children_type tree_children = new DoublyLinked<Tree_type>) {
    data = new_data;
    id = tree_id;
    parent = tree_parent;
    children = tree_children;
  }

  Tree_type addChild(D new_data) {
    I new_id = id + 1 + children->length();
    Tree_ref_type child = new Tree<D, I>(new_data, new_id, this);
    children->push(child);
    return *child;
  }

  bool includes(Tree_ref_type search_data, tree_filter_type tree_filter = default_tree_filter<Tree_type>) {
    return children->includes(search_data, tree_filter);
  }

  children_type gather(gather_func_type gather_func = default_gather<Tree_type>) {
    return children->gather(gather_func);
  }

  void print() {
    std::cout << '\n';
    std::cout << "TREE id  " << id << '\n';
    std::cout << "tree data  " << data << '\n';
    std::cout << "tree number children  " << children->length() << '\n';
    if (parent) {
      std::cout << "tree parent id  " << parent->id << '\n';
    } else {
      std::cout << "tree has no parent  " << '\n';
    }
    std::cout << '\n';
  }
};