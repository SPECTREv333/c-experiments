//
// Created by leonardo on 23/09/22.
//

#include <stdlib.h>
#include "stdio.h"
#include "dynarr.h"

Array* init(unsigned int initial_size){
    Array* array = (Array *) calloc(1, sizeof(Array));
    array->data = calloc(initial_size, sizeof (int));
    if (!array->data){
        printf("Unable to malloc(), commiting suicide...");
        exit(1);
    }
    array->size = initial_size;
    return array;
}

void append(Array* self, int value){
    unsigned int new_size = self->size + 1;

    int* new_ptr = (int *)realloc(self->data, new_size * sizeof(int));

    if (new_ptr!=NULL){
        self->data = new_ptr;
        self->size++;
    } else {
        free(self->data);
        printf("Unable to realloc(), exiting...");
        exit(1);
    }

    self->data[self->size-1] = value;

}

int* get(Array* self, unsigned int index){
   if (index >= self->size){
       return NULL;
   } else {
       return &self->data[index];
   }
}

void destroy(Array* self){
    free(self->data);
    free(self);
}

Array_interface dynarr = {
        .init = init,
        .append = append,
        .get = get,
        .destroy = destroy,
};
