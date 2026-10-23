#define STB_CONTAINERS_IMPLEMENTATION
#include "../stb_containers.h"
#include <stdio.h>
int main() {
  // int
  sc_vector_t vec_int;
  int tmp;
  sc_vector_init(&vec_int, sizeof(int));

  tmp = 1;
  sc_vector_push_back(&vec_int, &tmp);
  tmp = 2;
  sc_vector_push_back(&vec_int, &tmp);
  tmp = 3;
  sc_vector_push_back(&vec_int, &tmp);
  assert(vec_int.size == 3);
  sc_vector_get(&vec_int, &tmp, 1);
  assert(tmp == 2);
  sc_vector_set(&vec_int, &tmp, 2);
  tmp = 0;
  sc_vector_get(&vec_int, &tmp, 2);
  assert(tmp == 2);
  tmp = 0;
  sc_vector_pop_back(&vec_int, &tmp);
  assert(tmp == 2);
  assert(vec_int.size == 2);

  sc_vector_destroy(&vec_int);
  printf("ALL TESTS PASSED!\n");
  return 0;
}
