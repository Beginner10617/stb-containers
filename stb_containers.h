#ifndef STB_CONTAINERS
#define STB_CONTAINERS
#include <cstddef>
#include <stdlib.h>

// Dynamic array - `vector`
typedef struct sc_vector_s sc_vector_t;
void sc_vector_init(sc_vector_t *vec, size_t elem_size);
void sc_vector_push_back(sc_vector_t *vec, void *src);
void sc_vector_pop_back(sc_vector_t *vec, void *dst);
void sc_vector_insert(sc_vector_t *vec, void *src, size_t index);
void sc_vector_remove(sc_vector_t *vec, void *dst, size_t index);
void sc_vector_destroy(sc_vector_t *vec);

// Queue
typedef struct sc_queue_s sc_queue_t;
void sc_queue_init(sc_queue_t *que, size_t elem_size);
void sc_queue_enque(sc_queue_t *que, void *elem);
void sc_queue_front(sc_queue_t *que, void *dst);
void sc_queue_deque(sc_queue_t *que, void *dst);
void sc_queue_destroy(sc_queue_t *que);

// Stack
typedef struct sc_stack_s sc_stack_t;
void sc_stack_init(sc_stack_t *stk, size_t elem_size);
void sc_stack_push(sc_stack_t *stk, void *src);
void sc_stack_top(sc_stack_t *stk, void *dst);
void sc_stack_pop(sc_stack_t *stk, void *dst);
void sc_stack_destroy(sc_stack_t *stk);

// Hash table - `unordered_map` / `unordered_set`
typedef size_t (*HashFunc)(const void *key);
typedef struct sc_hashmap_s sc_hashmap_t;
void sc_hashmap_init(sc_hashmap_t *map, HashFunc func, size_t key_size,
                     size_t elem_size);
void sc_hashmap_read(sc_hashmap_t *map, void *key, void *dst);
void sc_hashmap_write(sc_hashmap_t *map, void *key, void *src);
void sc_hashmap_destroy(sc_hashmap_t *map);

// Deque / circular buffer

// Heap / priority queue

// Doubly linked list - `list`

// Balanced search tree - `map` / `set`

// Bitset

#endif
