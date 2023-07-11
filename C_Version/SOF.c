#include <stdlib.h>
#include <stdio.h>
#include "depnecinces.h"
#include "extra.h"



// o(n^2) + o(1) = o(n^2 * 1) = o(n^2)
int pair(Card array[], int size)
{
    //This runs in 0(1)

    int length = size;
    int copies = 0;

    // This runs in 0(n^2)
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if ((array[i]).value == array[j].value)
            {
                copies += 1; 
            }
        }
    }

    int top = power(size, 2);

    return top / copies;
    
    
}

int main(void)
{
    Card card1;
    Card card2;
    Card card3; 
    Card card4;

    card1.value = 3;
    card1.color = 1;
    card1.place = 0;

    card2.value = 3;
    card2.color = 1;
    card2.place = 0;

    card3.value = 4;
    card3.color = 1;
    card3.place = 0;

    card4.value = 4;
    card4.color = 1;
    card4.place = 0;





    Card array[] = {card1, card2, card3, card4};

    printf("%d", pair(array, 4));

}