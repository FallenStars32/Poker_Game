#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* random_index();

struct Card
{
    int color, value; 
};

typedef struct Card card; 




card* create_deck(void)
{
    card* deck = malloc(sizeof(card) * 52);

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

int* random_index(int* index_numbers, int amount)
{ 

    srand(time(NULL));
    for (int i = 0; i < amount; i ++)
    {
        index_numbers[i] = (rand() % 51) + 1;
        
    
    }

    return 0; 

}
