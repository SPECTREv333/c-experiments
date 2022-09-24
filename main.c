#include <stdio.h>
#include <stdlib.h>
#include "dynarr.h"

typedef unsigned int uint;

int main() {

    // Create
    //Array* array = dynarr.init(10);
    Array* array = dy_init(10);

    // Access
    array->data[0] = 1;
    // or
    //*dynarr.get(array, array->size-1) = 2;
    *dy_ref_get(array, array->size-1) = 2;
    // utility macro for already de-referenced value
    printf("%d\n", dy_val_get(array, 1));

    // Managed size
    printf("Size: %d\n", array->size);

    // Append (auto expansion)
    //dynarr.append(array, 15);
    dy_append(array, 15);

    uint arr_sz = array->size;

    printf("Size: %d\n", arr_sz);

    for( int i = 0; i<array->size; i++){
        printf("Element #%d: %d\n", i, dy_val_get(array, i));
    }

    // Easy de-allocation
    //dynarr.destroy(array);
    dy_destroy(array);

    // Checked with valgrind.

    return 0;
}
