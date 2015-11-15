#include "vector.h"

// Private

const size_t INIT_VEC_SIZE = 16;
/**
* vector_init(v): returns a vector v
*
* param[in]: v, a vector
* pre@: v is a valid vector
**/
void vector_init(vector*);

/**
* vector_init_with_size(v, i): returns a vector v with
* preallocated size of i elements
*
* advantage over vector_init is that if we know the size
* we won't have to make multiple calls to malloc!
*
* param[in]: v, a vector
* pre@: v is a valid vector
**/
bool vector_init_with_size(vector*, size_t);
size_t vector_size(vector*);

vector* vector_create(void) {
    vector* v = calloc(1, sizeof(vector));;
    if(v == NULL) {
        return NULL;
    }
    vector_init(v);
    return v;
}

vector* vector_create_with_size(size_t s) {
    vector* v = calloc(1, sizeof(vector));
    if (v == NULL)
    {
        return NULL;
    }

    if(vector_init_with_size(v, s) == NULL) {
        free(v);
        return NULL;
    }
    return v;
}


void vector_init(vector *v){
    v->data = NULL;  // array to track data
    v->size = 0;     // size of the vector
    v->count = 0;    // number of elements in vector
}

bool vector_init_with_size(vector *v, size_t i) {
    void * ptr = calloc(i,sizeof(void*));  // array to track data
    if (ptr == NULL) {
        return false;
    }
    v->data = ptr;
    v->size = i;     // size of the vector
    v->count = 0;    // number of elements in vector
    return true;
}

size_t vector_count(vector *v) {
    if (v == NULL) {
        return 0;
    }
    return v->count;
}

size_t vector_size(vector *v) {
    if (v == NULL) {
        return 0;
    }
    return v->size;
}

void vector_push(vector *v, void *e) {
    if (v == NULL) {
        return;
    }

    if (v->size == 0) {
        void** ptr = calloc(INIT_VEC_SIZE, sizeof(void *));
        if (ptr == NULL) {
            return;
        }
        v->data = ptr;
        v->size = INIT_VEC_SIZE;
    }

    // condition to increase v->data:
    // last slot exhausted
    if (v->size == v->count) {
        void ** ptr = realloc(v->data, sizeof(void *) * v->size * 2);
        if(ptr == NULL){
            return;
        }
        v->size *= 2;
        v->data = ptr;
    }

    v->data[v->count] = e;
    v->count++;
}

void vector_set(vector * v, size_t index, void * e) {
    // safety check to access only within the vector size
    if (v == NULL || index >= v->count) {
        return;
    }
    v->data[index] = e;
}

void * vector_get(vector *v, size_t index){
    // safety check to access only within the vector size
    if (index >= v->count) {
        return NULL;
    }
    return v->data[index];
}

void vector_delete(vector * v, size_t index) {
    // if index exceeds vector count, return
    if (index >= v->count) {
        return;
    }

    // else, we want to just delete the element and shift the
    // rest of the elements down
    /*@
     loop invariant index <= i < (v->count - 1);
     loop assigns i,v->data[index .. i];
     */
    for (size_t i = index; i < v->count - 1; ++i) {
        v->data[i] = v->data[i + 1];
    }
    // set last element as NULL and decrement count
    v->data[v->count - 1] = NULL;
    v->count--;
}

void vector_free(vector * v){
    if (v != NULL) {
        if (v->data) {
            free(v->data);
        }
        free(v);
    }
}
