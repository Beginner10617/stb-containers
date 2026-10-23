#ifndef STB_CONTAINERS
#define STB_CONTAINERS
#include <stdlib.h>
#include <assert.h>
#include <string.h>
// API Conventions:
//
// Given any container say a vector (name=vector), the following holds true:
// Initialization : [name] v; sc_[name]_init(&v, sizeof([dtype])); 
// Destroy : sc_[name]_destroy(&v);
// dtype = datatype of elements
//
// Containers where sizes are well-defined (vector, stack, queue), v.size attribute
// store the size, note that size here refers to the count of elements, not the total
// size in the memory (total size in memory = count * element size + metadata size)
//
// assert() will be used to make sure intended behaviour in the implementations
// (like assert([pointer]) after an allocation)

// Dynamic array - `vector`
typedef struct sc_vector_s sc_vector_t;
void sc_vector_init(sc_vector_t *vec, size_t elem_size);
void sc_vector_push_back(sc_vector_t *vec, void *src);
void sc_vector_pop_back(sc_vector_t *vec, void *dst);
void sc_vector_set(sc_vector_t *vec, void *src, size_t index);
void sc_vector_get(sc_vector_t *vec, void *dst, size_t index);
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
void sc_hashmap_get(sc_hashmap_t *map, void *key, void *dst);
void sc_hashmap_write(sc_hashmap_t *map, void *key, void *src);
void sc_hashmap_destroy(sc_hashmap_t *map);

// Deque / circular buffer

// Heap / priority queue

// Doubly linked list - `list`

// Balanced search tree - `map` / `set`

// Bitset

#ifdef STB_CONTAINERS_IMPLEMENTATION

// Dynamic array - `vector`
struct sc_vector_s{
	void *arr;
	size_t cap, size, elem_size;
};
void sc_vector_init(sc_vector_t *vec, size_t elem_size){
	assert(vec);
	vec->cap = 1;
	vec->size = 0;
	vec->elem_size = elem_size;
	vec->arr = malloc(vec->elem_size * vec->cap);
	assert(vec->arr);
}
void sc_vector_push_back(sc_vector_t *vec, void *src){
	assert(src && vec);
	if(vec->size == vec->cap){
		size_t new_cap = 2 * vec->cap;
		void *tmp = realloc(vec->arr, new_cap * vec->elem_size);
		assert(tmp);
		vec->arr = tmp;
		vec->cap = new_cap;
	}
	memcpy(vec->arr + vec->size * vec->elem_size, src, vec->elem_size);
	vec->size++;
}
void sc_vector_pop_back(sc_vector_t *vec, void *dst){
	assert(vec);
	assert(vec->size);
	vec->size--;
	if(dst) memcpy(dst, vec->arr + vec->size * vec->elem_size, vec->elem_size);
}
void sc_vector_set(sc_vector_t *vec, void *src, size_t index){
	assert(vec && src);
	assert(vec->size > index);
	memcpy(vec->arr + index * vec->elem_size, src, vec->elem_size);
}
void sc_vector_get(sc_vector_t *vec, void *dst, size_t index){
	assert(vec && dst);
	assert(vec->size > index);
	memcpy(dst, vec->arr + index * vec->elem_size, vec->elem_size);
}
void sc_vector_destroy(sc_vector_t *vec){
	assert(vec);
	free(vec->arr);
}
/*
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
void sc_hashmap_get(sc_hashmap_t *map, void *key, void *dst);
void sc_hashmap_write(sc_hashmap_t *map, void *key, void *src);
void sc_hashmap_destroy(sc_hashmap_t *map);

*/
#endif
#endif
