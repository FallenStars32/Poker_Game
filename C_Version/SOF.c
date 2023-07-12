#include <stdlib.h>
#include <stdio.h>
#include "depnecinces.h"
#include "extra.h"



// o(n^2) + o(1) = o(n^2 * 1) = o(n^2)
int pair(Card array[], int size)
{
    //This runs in 0(1)


    int card[52]; // This creates an array length 52

    for (int e = 0; e < 52; e++)
    {
        card[e] = 0;
    }

    int length = size; // This takes the size of the hand 

    // This runs in 0(n^2)
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if ((array[i]).value == array[j].value)
            {
                
                card[array[i].value] += 1;
            }
        }
    }


    int top = power(size, 2);

    for (int i = 0; i < 52; i++)
    {
        card[i] = top / card[i];
    }

    int pairs = 0;

   

    for (int i = 0; i < 52; i++)
    {
        if ((top / card[i]) >= 2)
        {
            pairs += 1;
        }

    }

    if (pairs == 1)
    {
        return 1;
    }

    else if ( pairs == 2)
    {
        return 2;
    }

    else
    {
        return 0;
    }
    
    
}


int kinds(Card hand[], int size)
{

    //This creates a deck of cards that is then set to 0 moved to dependcies 
    int * cards = create_empty_array(52);


    for (int i = 0;i < size; i++)
    {
        for (int j =0; j < size; j++)
        {
            if (hand[i].value == hand[j].value)
            {
                cards[hand[i].value] += 1; 
            }
        }

    }


    int highest = 0;
    int a;

    int top = size * 2; // An error is caused here in which the thing doesn't work

    for (int i = 0; i < 52; i++)
    {
        a = cards[i];
        cards[i]= top / a;

        if (cards[i] > highest)
        {
            highest = cards[i];
        }

    }

    return highest;    
}





int main(void)
{
    Card card1;
    Card card2;
    Card card3; 
    Card card4;

    card1.value = 2;
    card1.color = 1;
    card1.place = 0;
    

    card2.value = 2;
    card2.color = 1;
    card2.place = 0;

    card3.value = 2;
    card3.color = 1;
    card3.place = 0;

    card4.value = 3;
    card4.color = 1;
    card4.place = 0;





    Card array[] = {card1, card2, card3, card4};

    printf("%d \n", pair(array, 4));

    printf("%d \n", kinds(array, 4));

}