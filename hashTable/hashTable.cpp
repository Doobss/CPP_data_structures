#include <iostream>

#include "../linkedList/linkedList.cpp"

auto hash_key(std::string key) {
  std::hash<std::string> hash_obj;
  return hash_obj(key);
};

template <typename K, typename D>
class Tuple {
 public:
  K key;
  D data;
  Tuple(K new_key, D new_data) {
    key = new_key;
    data = new_data;
  }
};

template <typename T>
class Hash_table {
  typedef std::string hash_key_type;
  typedef Tuple<hash_key_type, T> *tuple_type;
  typedef Node<tuple_type> *list_node_type;
  typedef LinkedList<tuple_type> *bucket_type;
  typedef std::function<void(list_node_type)> each_callback;
  typedef std::function<bool(list_node_type)> filter_callback;
  int size;
  int buckets;
  int min_size;
  bucket_type *store;



 public:
  Hash_table(int init_size = 256, int init_min_size = 64) {
    size = init_size;
    buckets = 0;
    min_size = init_min_size;
    store = new bucket_type[size];
  }

  bool set(hash_key_type new_key, T data) {
    size_t hash_index = hash_key(new_key);
    int adjusted_index = hash_index % size;
    bucket_type store_bucket = store[adjusted_index];
    if (store_bucket == NULL) {
      store_bucket = new LinkedList<tuple_type>;
    }
    tuple_type new_tuple = new Tuple(new_key, data);
    bool tuple_not_in_bucket = true;

    each_callback for_each = [&](list_node_type node) {
      if (new_tuple->key == node->value->key) {
        tuple_not_in_bucket = false;
        node->value->data = new_tuple->data;
      }
    };
    store_bucket->each(for_each);

    if (tuple_not_in_bucket) {
      store_bucket->push(new_tuple);
    }
    store[adjusted_index] = store_bucket;
    buckets++;
    return true;
  }

  T get(hash_key_type search_key) {
    size_t hash_index = hash_key(search_key);
    int adjusted_index = hash_index % size;
    bucket_type store_bucket = store[adjusted_index];
    if (store_bucket == NULL) {
      store_bucket = new LinkedList<tuple_type>;
    }
    T bucket_data;
    each_callback for_each = [&](list_node_type node) {
      if (search_key == node->value->key) {
        bucket_data = node->value->data;
      }
    };
    store_bucket->each(for_each);
    return bucket_data;
  }

  bool remove(hash_key_type remove_key) {
    size_t hash_index = hash_key(remove_key);
    int adjusted_index = hash_index % size;
    bucket_type store_bucket = store[adjusted_index];
    if (store_bucket == NULL) {
      store_bucket = new LinkedList<tuple_type>;
    }
    bool removed = false;
    filter_callback filter_func = [&](list_node_type node) {
      bool push_to_new_list = true;
      if (remove_key == node->value->key) {
        push_to_new_list = false;
        removed = true;
      }
      return push_to_new_list;
    };
    bucket_type new_bucket;
    new_bucket = store_bucket->filter(filter_func);
    delete store_bucket;
    store[adjusted_index] = new_bucket;
    if (removed) {
      buckets--;
    }
    return removed;
  }
};
