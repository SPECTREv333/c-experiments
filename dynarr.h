//
// Created by leonardo on 23/09/22.
//

#ifndef UNTITLED_DYNARR_H
#define UNTITLED_DYNARR_H

#ifndef TYPE
#define TYPE char
#endif

typedef struct Array_ Array;

typedef struct Array_interface_ {
    Array (*init)(size_t initial_size);
    void (*push)(Array* self, TYPE value);
    void (*append)(Array* self, TYPE* array, size_t array_size);
    TYPE* (*get_ref)(Array* self, size_t index);
    void (*destroy)(Array* self);
} Array_interface;

struct Array_ {
    size_t size;
    TYPE *data;
};

extern Array_interface dynarr;

#endif //UNTITLED_DYNARR_H
