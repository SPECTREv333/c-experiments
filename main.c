#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynarr.h"

typedef unsigned int uint;

int main() {

    Array array = dynarr.init(0);

    char* test = "Hello string";

    printf("%lu\n", strlen(test));

    dynarr.append(&array, test, strlen(test)+1);

    char* test2 = "Ciao dueeeeeee";

    dynarr.append(&array, test2, strlen(test2)+1);

    printf("'%s'\n", array.data);

    dynarr.destroy(&array);

    return 0;
}
