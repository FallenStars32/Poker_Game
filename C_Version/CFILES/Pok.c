#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


// These are the strcuture for this file
typedef struct Card {
    int value;
    int color;
    int place;
} Card;

typedef struct Output {
    int HP;
    int HOP;
    int HC;
}  Output;

typedef struct Player 
{
    int money;
    Card * hand;
    int hand_value;
    int player_in; 
    int big_blind;
    int small_bind;
} Player;

// This function proints any card
void printCard(Card card)
{
    char value_output[10];
    char color_output[10];
    int value = 0;
    if (card.place <= 10) value = card.value; 
    else if (card.place == 11) strcpy(value_output, "J");

    else if (card.place == 12) strcpy(value_output, "Q");

    else if (card.place == 13) strcpy(value_output, "K");

    else if (card.place == 14) strcpy(value_output, "A");

    if (card.color == 1) strcpy(color_output, "HEARTS");

    else if (card.color == 2) strcpy(color_output, "DIAMONDS");

    else if (card.color == 3) strcpy(color_output, "SPADES");

    else if (card.color == 4) strcpy(color_output, "CLUBS");
    if (value == 0) printf("%s ", value_output); 

    else printf("%d ", card.value); 

    printf("%s\n", color_output);
}

const Card card_N = {0, 0, 0};

//This is the flush straight flushes and other sections 
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


//This section is just for extra functions
int * random_generator(int amount) {

    int * array = malloc(sizeof(int) * amount);

    srand(time(0));
    for (int i = 0; i < amount; i++) {
        array[i] = rand() % 53;
    }
    return array;
}

//This takes an input and sqaurss it
int power(int base, int power)
{
    int total = 1;
    for (int i = 0; i < power; i++)
    {
        total = total * base;
    }

    return total;
}


//These functions are for array managment in C
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







//This section creates the deck 
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






int Check_Straight(Card hand[], int size)
{

    int *  arr_value = create_empty_array(size); 

    for (int i = 0; i < size; i++)
    {
        arr_value[i] = hand[i].value;
    }

    qsort(arr_value, size, sizeof(int), compare);

    int x = 0;

    int * array_straight = create_empty_array(size); //These are the cards inside the array

    int * out_straight = create_empty_array(size); //These are the cards that are outside the striaght



    for (int i = 0; i < size - 1; i++)
    {
        if ((arr_value[i] + 1 ) == arr_value[i+1])
        {
            array_straight[x] = arr_value[i];
            x += 1;
        }

        for (int j = 0; j < size; j ++)
        {
            if (array_straight[j] != 0)
            {
                out_straight[j] = *array_straight;
                array_straight[j] = 0;
            }
        }

        out_straight[i] = arr_value[i]; 
        
    }

    qsort(array_straight, size, sizeof(int), compare);

    qsort(out_straight, size, sizeof(int), compare); 

    Output output; 

   

    if (x >= 4)
    {
        output.HC = out_straight[size];
        output.HOP = array_straight[size]; 
        output.HP = 5;

        free(array_straight);
        free(out_straight);
        free(arr_value);
        return 1;
    }

    output.HC = out_straight[size];

    return 0;

}

int Check_Flush(Card hand[], int size)
{
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    int x4 = 0;

    for (int i = 0; i < size; i++)
    {
        if (hand[i].color == 1) x1+=1; 

        else if (hand[i].color == 2) x2+=1; 

        else if (hand[i].color == 3) x3+=1; 

        else if (hand[i].color == 4) x4+=1; 

        if (x1 >= 5 || x2 >= 5 || x3 >= 5 || x4 >= 5) return 1;
        
    }

    return 0;

}

int Check_SF(Card hand[], int size)
{
    if (Check_Flush(hand, size) == 1 && Check_Straight(hand,size) == 1) return 1;

    return 0; 
}

int check_RF(Card hand[], int size)
{
    if (Check_Flush(hand, size) == 0) return 1; 

    int x10 = 0;
    int x11 = 0;
    int x12 = 0; 
    int x13 = 0;


    for (int i = 0; i < size; i++)
    {
        if (hand[i].value == 10) x10 += 1;

        else if (hand[i].value == 11) x11 += 1; 

        else if (hand[i].value == 12) x12 += 1;
        
        else if (hand[i].value == 13) x13 += 1;
    }

    if (x10 >= 1 && x11 >= 1 && x12 >= 1 && x13 >= 1) return 1;

    return 0;
}


//This is for kinds and pairs


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

int two_pair(Card hand[], int size)
{
    if (pair(hand, size) >= 2) return 1;

    return 0;
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

int two_kind(Card hand[], int size)
{
    if (kinds(hand, size)[0] >= 2) return 1;
    return 0;
}

int three_kind(Card hand[], int size)
{
    if (kinds(hand, size)[0] >= 3) return 1;
    return 0;
}

int four_kind(Card hand[], int size)
{
    if (kinds(hand, size)[0] >= 4) return 1;
    return 0;
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

//This section deals with evluating a hand

int eval(Card hand[], int size)
{
    int hand_value[] = {0, 0, 0, 0, 0, 0, 0, 0}; 

    if (two_kind(hand, size) == 1) hand_value[0] = 1;

    if (two_pair(hand, size) == 1) hand_value[1] = 1;

    if (three_kind(hand, size) == 1) hand_value[2] = 1;

    if (Check_Straight(hand, size) == 1) hand_value[3] = 1;

    if (Check_Flush(hand, size) == 1) hand_value[4] = 1;

    if (four_kind(hand, size) == 1) hand_value[5] = 1;

    if (Check_SF(hand, size) == 1) hand_value[6] = 1;

    if (check_RF(hand, size) == 1) hand_value[7] = 1;

    for (int i = 7; i > 0; i--)
    {
        if (hand_value[i] == 1) return i + 1;
    }

    return 0;

}

int compare_hands(Card hand[], Card hand2[], int size)
{
    int x = eval(hand, size);
    int y = eval(hand2, size);

    if (x > y) return -1; //Inputer loses

    if (x == y) return 0; // A tie occured

    if (y > x) return 1; //Inputer Wins

    return -100; 
}

//This is the part where the game happens



//These are test function
void printDeck(Card * deck, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (deck[i].color == 0) continue;
        printf("The card value is %d and the color is %d \n", deck[i].value, deck[i].color);
    }
}


Card ** preFLop(Card * deck, int players)
{

    Card ** All_Hands = malloc(sizeof(Card *) * 7);

    int deck_index = 0;

    

    for (int i = 0; i < players; i++)
    {
        while (deck[deck_index].color == 0) deck_index += 1; 

        Card * player_hand = malloc(sizeof(Card) * 7); 

        player_hand[0] = deck[deck_index]; 
        player_hand[1] = deck[deck_index + 1];
        deck[deck_index] = card_N;
        deck[deck_index + 1] =card_N; 
        All_Hands[i] = player_hand;
    }

    return All_Hands; 

}

Card ** Flop(Card * deck, int player, Card ** All_Hands)
{

    int deck_index = 0;
    
    while (deck[deck_index].color == 0) deck_index += 1;

    Card middle[3] = {deck[deck_index], deck[deck_index + 1], deck[deck_index + 2]}; 

    deck[deck_index] = card_N;

    deck[deck_index + 1] = card_N;

    deck[deck_index + 2] = card_N;

    for (int i = 0; i < player; i++)
    {
        All_Hands[i][2] = middle[0];
        All_Hands[i][3] = middle[1];
        All_Hands[i][4] = middle[2];
    }

    return All_Hands;
 }

Card ** Run(Card * deck, int player, Card ** All_Hands)
{

    int deck_index = 0;
    
    while (deck[deck_index].color == 0) deck_index += 1;

    Card middle = deck[deck_index];

    deck[deck_index] = card_N;

    for (int i = 0; i < player; i++)
    {
        All_Hands[i][5] = middle;
    }

    return All_Hands;
 }

Card ** river(Card * deck, int player, Card ** All_Hands)
{

    int deck_index = 0;
    
    while (deck[deck_index].color == 0) deck_index += 1;

    Card middle = deck[deck_index];

    deck[deck_index] = card_N;

    for (int i = 0; i < player; i++)
    {
        All_Hands[i][6] = middle;
    }

    return All_Hands;
 }

 Card * deal_two(Card * deck)
 {
    int deck_index = 0;
    while (deck[deck_index].color == 0) deck_index += 1;

    Card * deal_two = malloc(sizeof(Card) * 2);

    deal_two[0] = deck[deck_index];
    deal_two[1] = deck[deck_index + 1]; 

    deck[deck_index] = card_N;
    deck[deck_index + 1] = card_N;
    return deal_two;
 }

Player ** create_game(int players, int money, Card * deck)
 {
    Player ** player_hands = malloc(sizeof(Player *) * players);

    for (int i = 0; i < players; i++)
    {
        Player * player = malloc(sizeof(Player)); 
        player->hand = deal_two(deck);
        player->money = money / players;
        player->hand_value = eval(player->hand, 2);
        player->player_in = 1;
        player_hands[i] = player;

    }

    //This is where the betting round takes place
    
    for (int i = 0; i < players; i++)
    {
        Card * cur_hand = player_hands[0]->hand;

        

        for (int i = 0; i < 2; i++) printCard(cur_hand[i]); 

        printf("Are you in or out: ");

        int a;
        scanf("%d", &a);

        if (a == 0) player_hands[i]->player_in = 0;

        if (player_hands[i]->player_in == 1) player_hands[i]->money -= 500;
    }


    return player_hands;

 }

 //This part runs the simulation
float SIM_Array(Card * hand, int size)
{

    Card * deck = create_deck();
    shuffle_deck(deck);
    


}


int main(void)
{
    Card card1;
    Card card2;
    Card card3;
    Card card4;
    Card card5;
    Card card6;
    Card card7;

    card1.value = 2;
    card2.value = 1;
    card3.value = 1;
    card4.value = 1;
    card5.value = 5;
    card6.value = 6;
    card7.value = 7;

    card1.color = 1;
    card2.color = 1;
    card3.color = 1;
    card4.color = 1;
    card5.color = 1;
    card6.color = 1;
    card7.color = 1;

    
    

    Card * deck = create_deck();
    
    Player ** player = create_game(2, 30000, deck);

    printf("%d", player[0]->hand->value);



}


    




