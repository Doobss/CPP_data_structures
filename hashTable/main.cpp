#include "hashTable.cpp"

int main() {
  typedef int data_type;
  Hash_table<data_type> ht;
  std::string test_key = "hello";
  ht.set(test_key, 1);
  // std::string test_key = "hello";
  ht.set(test_key, 2);
  test_key = "hello2";
  ht.set(test_key, 1);
  test_key = "hello3";
  ht.set(test_key, 345);
  test_key = "hell234322";
  ht.set(test_key, 342);
  test_key = "he2342";
  ht.set(test_key, 5236);
  test_key = "1234o2";
  ht.set(test_key, 234);
  test_key = "hel235o2";
  ht.set(test_key, 23);
  test_key = "12345l o2";
  ht.set(test_key, 53463);
  test_key = "hello";
  data_type get_res;
  get_res = ht.get(test_key);
  std::cout << "get_res " << get_res << '\n';
  test_key = "hel235o2";
  get_res = ht.get(test_key);
  std::cout << "get_res " << get_res << '\n';

  test_key = "sdfsfsd";
  get_res = ht.get(test_key);
  std::cout << "get_res " << get_res << '\n';
  bool remove_res;
  test_key = "hello";
  remove_res = ht.remove(test_key);
  std::cout << "test_key = " << test_key << "   remove_res " << remove_res << '\n';
};