//
// Created by leonardo on 23/09/22.
//

#include <stdlib.h>
#include <memory.h>
#include "dynarr.h"

#define METHOD(NAME) .NAME = NAME

Array init(size_t initial_size){
    Array array = { .size = initial_size, .data = NULL };
    array.data = (TYPE*)malloc(initial_size * sizeof (TYPE));
    array.size = initial_size;
    return array;
}

void push(Array* self, TYPE value){
    size_t new_size = self->size + 1;

    TYPE* new_ptr = (TYPE *)realloc(self->data, new_size * sizeof(TYPE));

    if (new_ptr!=NULL){
        self->data = new_ptr;
        self->size++;
    } else {
        free(self->data);
    }

    self->data[self->size-1] = value;
}

void append(Array* self, TYPE* array, size_t array_size){
    TYPE* new_ptr = (TYPE *) realloc(self->data, (self->size + array_size) * sizeof(TYPE));
    if (new_ptr == NULL) {
        free(new_ptr);
        return;
    }
    memcpy(new_ptr + self->size, array, array_size * sizeof(TYPE));
    self->data = new_ptr;
    self->size = self->size + array_size;
}

TYPE* get_ref(Array* self, size_t index){
   if (index >= self->size){
       return NULL;
   } else {
       return &self->data[index];
   }
}

void destroy(Array* self){
    free(self->data);
}

Array_interface dynarr = {
        METHOD(init),
        METHOD(push),
        METHOD(append),
        METHOD(get_ref),
        METHOD(destroy),
};
