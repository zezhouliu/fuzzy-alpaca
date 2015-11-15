#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "utils.h"

#define MAX_VEC_SIZE = SIZE_MAX / 16;

typedef struct vector_ {
    void** data;
    size_t size;
    size_t count;
} vector;

/* * * * * * * * * *
* vector_create()
*
* @brief: creates a new vector
*
* @return a new vector
* * * * * * * * * */
vector* vector_create(void);

/* * * * * * * * * *
* vector_create_with_size(s)
*
* @brief: creates a new vector with size s
*
* @param[in]: s, capacity of vector
*
* @return a new vector with capacity s
* * * * * * * * * */
vector* vector_create_with_size(size_t s);

/**
* vector_count(v): returns size of v
*
* param[in]: v, a vector
* pre@: v is a valid vector
**/
size_t vector_count(vector*);

/**
* vector_push(v, e): pushes e to the back of v
*
* param[in]: v, a vector
* param[in]: e is valid element
* @pre: v is a valid vector
* @pre: 0 <= index < v.size()
* @post: pushes an element into v
**/
void vector_push(vector*, void*);

/**
* vector_set(v, index): sets element at index from vector v
*
* param[in]: v, a vector
* param[in]: index into v
* pre@: v is a valid vector
* pre@: 0 <= index < v.size()
* post@: sets the element at index i
**/
void vector_set(vector*, size_t, void*);

/**
* vector_get(v, index): gets element at index from vector v
*
* param[in]: v, a vector
* param[in]: index into v
* pre@: v is a valid vector
* pre@: 0 <= index < v.size()
* post@: returns element at index
**/
void *vector_get(vector*, size_t);

/**
* vector_delete(v, index): deletes element at index from vector v
*
* param[in]: v, a vector
* param[in]: index into v
* pre@: v is a valid vector
* pre@: 0 <= index < v.size()
* post@: returns vector with element at index i removed
**/
void vector_delete(vector*, size_t);

/**
* vector_free(v): frees vector v
*
* param[in]: v, a vector
* pre@: v is a valid vector
* post@: frees relevant data in v
**/
void vector_free(vector*);
#endif /* __VECTOR_H__ */

