#include <stdlib.h>
#include <stdio.h>
#include <time.h>



int * random_generator(int amount) {

    int * array = malloc(sizeof(int) * amount);

    srand(time(0));
    for (int i = 0; i < amount; i++) {
        array[i] = rand() % 53;
    }
    return array;
}


int power(int base, int power)
{
    int total = 1;
    for (int i = 0; i < power; i++)
    {
        total = total * base;
    }

    return total;
}

int* create_empty_array(int size)
{
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL)
    {
        // Error: failed to allocate memory
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }

    return array;
}






