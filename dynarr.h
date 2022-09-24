//
// Created by leonardo on 23/09/22.
//

#ifndef UNTITLED_DYNARR_H
#define UNTITLED_DYNARR_H

#define dy_init(initial_size) dynarr.init((initial_size))
#define dy_val_get(array, index) *dynarr.get(array, index)
#define dy_ref_get(array, index) dynarr.get(array, index)
#define dy_append(array, value) dynarr.append(array, value)
#define dy_destroy(array) dynarr.destroy(array)
typedef struct Array_ Array;

typedef struct Array_interface_ {
    Array* (*init)(unsigned int initial_size);
    void (*append)(Array* self, int value);
    int* (*get)(Array* self, unsigned int index);
    void (*destroy)(Array* self);
} Array_interface;

struct Array_ {
    unsigned int size;
    int *data;
};

extern Array_interface dynarr;

#endif //UNTITLED_DYNARR_H
