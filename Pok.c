#include <stdio.h>
#include <stdlib.h>

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
        New_Card.place = i;
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
    

}

int main(void) {
    Card * deck = create_deck();
    for (int i = 0; i < 52; i++) {
        printf("%d \n", deck[i].value);
    }
}

