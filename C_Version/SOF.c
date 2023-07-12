#include <stdlib.h>
#include <stdio.h>
#include "depnecinces.h"
#include "extra.h"
#include <math.h>



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


int * kinds(Card hand[], int size)
{

    //This creates a deck of cards that is then set to 0 moved to dependcies 
    int * cards = create_empty_array(52);

    
    
   

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (hand[i].value == hand[j].value)
            {
                cards[hand[i].value] += 1; 
            }
        }

    }

    cards[0] = 0;
    
    int highest = 0;

    int highest2 = 0;

    int highest3 = 0; // This has been addded in case we get 2 3 of a kinds because hands are techincally 7 long

    
    int cur = 0; 


   for (int i = 0; i < 52; i++) 
   
   {
   
   cur = cards[i];
   cur = sqrt(cur); 

   if (cur > highest) highest = cur; 


   
   else if (cur > highest2) highest2 = cur;

   else if (cur > highest3) highest3 = cur; 


  
    

   
   }
   int outputs[3] = {highest, highest2, highest3};
   int * result = outputs;
   return result;
}

int full_house(Card hand[], int size)
{
    int * array = kinds(hand, size);

    if (array[0] >= 3 && array[1] == 2)
    {
        return 1;
    }

    return 0; 
}

    





int main(void)
{
    Card card1; 
    Card card2; 
    Card card3;  
    Card card4; 
    Card card5;

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

    card5.value = 3;
    card5.color = 1;
    card5.place = 0;

    Card card6;
    card6.value = 0;


    





    Card array[] = {card1, card2, card3, card4, card5, card6};

    //printf("%d \n", pair(array, 4));

    printf("%d \n", full_house(array, 6));

}