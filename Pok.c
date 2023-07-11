#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "depnecinces.h"

typedef struct Card {
    int value;
    int color;
    int place;
} Card;

Card * create_deck() {
    Card * deck = malloc(sizeof(Card) * 52);
    if (deck == NULL) {
        return NULL;
    }
    for (int i = 0; i < 52; i++) {
        Card New_Card;
        New_Card.place = i + 1;
        if (i <= 13) {
            New_Card.color = 1;
            New_Card.value = i + 2;
        } else if (i <= 26) {
            New_Card.color = 2;
            New_Card.value = i - 13 + 2;
        } else if (i <= 39) {
            New_Card.color = 3;
            New_Card.value = i - 26 + 2;
        } else if (i <= 52) {
            New_Card.color = 4;
            New_Card.value = i -39 + 2;
        }
        deck[i] = New_Card;
    }
    return deck;
}

Card * shuffle_deck(Card * deck)
{

    int amount = 100;
    int * numbers = random_generator(amount); 
    Card temp;
    Card flip;
    for (int i = 0; i < (amount - 1); i++)
    {
        temp = deck[numbers[i]];
        flip = deck[numbers[i+1]];

        deck[numbers[i]] = flip;
        deck[numbers[i+1]] = temp;
        
    }

    return deck;


}

int main(void) {
    Card * deck = create_deck();
    shuffle_deck(deck);
    for (int i = 0; i < 52; i++) {
        printf("%d \n", deck[i].place);
    }
}

