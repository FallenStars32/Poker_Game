#include <stdio.h>
#include <stdlib.h>

typedef struct Card 
{
    int value;
    int color; 

} Card;

Card * create_deck()
{
    Card deck[52];

    for (int x = 0; x < 4; x++)
    {
        for (int y = 2; y < 13; y++)
        {
            int i = 0;  
            deck[i].color = x;
            deck[i].value = y;
            i++;

        }
    }

    Card * deck1 = deck;

    return deck1;

}

int main()
{
    Card * deck = create_deck();
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", deck[i].color);
    }
    return 0;
}
