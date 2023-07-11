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


int power(int num, int power)
{
    int total = 1;
    for (int i = 0; i < power; i++)
    {
        total = total * num;
    }

    return total;
}


