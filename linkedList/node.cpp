

template <typename N>

struct Node {
  N value;
  struct Node<N> *next;
};
