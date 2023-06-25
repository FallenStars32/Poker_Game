#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* random_index();


struct Card
{
    int color, value; 
};

typedef struct Card card; 

struct function_results
{
    int value, high_play_card, high_card;
};

typedef struct function_results function_results;


function_results pair(card* hand, int amount);


card* create_deck(void)
{
    card* deck = malloc(sizeof(card) * 52 + sizeof(int));

    deck[0].color = 0;
    deck[0].value = 52;
    deck++;

    int cardIndex = 0;

    for (int color = 1; color <= 4; color++)
    
    {
        for (int value = 1; value <=13; value++)
        {
            deck[cardIndex].color = color;
            deck[cardIndex].value = value;
            cardIndex++;
        }
    }

    return deck;


}

card* shuffle_deck(card* deck)
{    

    
    int* index_numbers = malloc(sizeof(int) * 2000);

    random_index(index_numbers, 2000);


    for (int i = 0; i < 2000; i++)
    {
        int index1 = index_numbers[i];
        int index2 = index_numbers[i+1000];
        card temp = deck[index1];
        deck[index1] = deck[index2];
        deck[index2] = temp;
    }

    return deck; 
}


// This function is used to generate a random number
int* random_index(int* index_numbers, int amount)
{ 

    srand(time(NULL));
    for (int i = 0; i < amount; i ++)
    {
        index_numbers[i] = (rand() % 51) + 1;
        
    
    }

    return 0; 

}




//This section takes in a hand and returns the card value 

int find_high_card(card* hand)
{

    int size = hand[-1].value;
    
    int high_card = 0;
    for (int i = 0; i < size; i++)
    {
        card cur = hand[i];
        if (high_card < cur.value)
        {
            high_card = cur.value;
        }

    }

    return high_card;

}

// Pair 

function_results pair(card* hand, int goal_amount)
{
    int size = hand[-1].value;
    function_results result;

    result.value = 0;
    result.high_card = 0;
    result.high_play_card = 0;
    int pre_amount = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = size; j < size; j--)
        {
            card cr1 = hand[i];
            card cr2 = hand[j];
            if (cr1.value == cr2.value)
            {
                pre_amount++;
                if (cr1.value > result.high_play_card)
                {
                    result.high_play_card = cr1.value; 
                }

                if (cr1.value >= cr2.value)
                {
                    result.high_play_card = cr1.value;
                }
                continue;
            }

            if (result.high_card < cr1.value)
            {

                result.high_card = cr1.value;

            }

        }
    }

    int amount = pre_amount / (size * size);

    if (amount >= goal_amount)
        {
            
            result.value = goal_amount;
        }

    return result;


}


    
   
    



int main(void)
{
    card* deck = malloc(sizeof(card) * 4 + sizeof(int));
    card card1;
    card card2;
    card card3;
    card card4;

    card1.color = 1;
    card2.color = 2;
    card3.color = 3;
    card4.color = 4;
    card1.value = 1;
    card2.value = 1;
    card3.value = 2;
    card4.value = 2;

    
    card card0;
    card0.color = 0;
    card0.value = 4;
    deck[0] = card0;
    deck++;

    shuffle_deck(deck);

    printf("%d", pair(deck, 1).value);
}