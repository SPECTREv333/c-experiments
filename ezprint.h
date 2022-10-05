//
// Created by leonardo on 05/10/22.
//

#ifndef UNTITLED_EZPRINT_H
#define UNTITLED_EZPRINT_H

#define fmt_for(x) _Generic((x), \
        unsigned char: "%uc\n",\
        char: "%c\n",\
        signed char: "%c\n",\
        short int: "%d\n",\
        unsigned short int: "%du\n",\
        int: "%d\n",\
        unsigned int: "%lu\n",\
        long int: "%l\n",\
        unsigned long int: "%lu\n",\
        long long int: "%ll\n",\
        unsigned long long int: "%llu\n",\
        float: "%f\n",\
        double: "%f\n",\
        long double: "%ld\n",\
        char *: "%s\n",\
        default: "%d\n")

#define print(x) printf(fmt_for(x), (x))

#endif //UNTITLED_EZPRINT_H
