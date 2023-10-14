#ifndef __UNI_ARRAY_H__
#define __UNI_ARRAY_H__

#include "uni.h"

/* Enum and Structure */
typedef struct {
    void* data;
    size_t size;
    size_t count;
} uni_array_t;


/* Functions */
void init_uni_array(uni_array_t* array, size_t size);
void init_uni_array_ptr(uni_array_t* array, size_t size);
void push_to_uni_array(uni_array_t* array, void* element);
void* get_from_uni_array(uni_array_t* array, size_t index);
void remove_from_uni_array(uni_array_t* array, size_t index);
void free_uni_array(uni_array_t* array);
void free_uni_array_ptr(uni_array_t* array);

#endif // __UNI_ARRAY_H__
