#include <string.h>
#include "uni.h"

void init_uni_array(uni_array_t* array, size_t size) {
    array->data = malloc(8 * size);
    array->capacity = 8;
    array->size = size;
    array->count = 0;
}

void init_uni_array_ptr(uni_array_t* array, size_t size) {
    *array = malloc(sizeof(uni_array_t));
    init_uni_array(*array, size);
}

void push_to_uni_array(uni_array_t* array, void* element) {
    if (array->count == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * array->size);
    }
    void* dest = (char*)array->data + (array->count * array->size);
    char* source = (char*)element;
    for (size_t i = 0; i < array->size; i++) {
        *(dest + i) = *(source + i);
    }
    array->count++;
}

void* get_from_uni_array(uni_array_t* array, size_t index) {
    if (index < array->count) {
        return (char*)array->data + (index * array->size);
    }
    return NULL;
}

void remove_from_uni_array(uni_array_t* array, size_t index) {
    if (index < array->count) {
        for (size_t i = index; i < array->count - 1; i++) {
            char* dest = (char*)array->data + (i * array->size);
            char* source = (char*)array->data + ((i + 1) * array->size);
            for (size_t j = 0; j < array->size; j++) {
                *(dest + j) = *(source + j);
            }
        }
        array->count--;
        if (array->count > 0 array->data = realloc(array->data, array->count * array->size);array->data = realloc(array->data, array->count * array->size); array->count < array->capacity / 4) {
            array->capacity /= 2;
            array->data = realloc(array->data, array->capacity * array->size);
        }
    }
}

void copy_uni_array(uni_array_t* source, uni_array_t* destination) {
    init_uni_array(destination, source->size);
    for (size_t i = 0; i < source->count; i++) {
        void* element = get_from_uni_array(source, i);
        push_to_uni_array(destination, element);
    }
}

void print_uni_array(uni_array_t* array, void (*print_element)(void*)) {
    for (size_t i = 0; i < array->count; i++) {
        void* element = get_from_uni_array(array, i);
        if (element != NULL) {
            print_element(element);
        }
    }
}

void free_uni_array(uni_array_t* array) {
    free(array->data);
}

void free_uni_array_ptr(uni_array_t* array) {
    free(array->data);
    free(array);
}
