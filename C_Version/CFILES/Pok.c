#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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


//This section is just for extra functions
int * random_generator(int amount) {

    int * array = malloc(sizeof(int) * amount);

    srand(time(0));
    for (int i = 0; i < amount; i++) {
        array[i] = rand() % 53;
    }
    return array;
}


int power(int base, int power)
{
    int total = 1;
    for (int i = 0; i < power; i++)
    {
        total = total * base;
    }

    return total;
}

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



//This is the flush straight flushes and other sections 
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
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

    for (int i = 0; i < size - 1; i++)
    {
        if ((arr_value[i] + 1 ) == arr_value[i+1])
        {
            x += 1;
        }
        
    }

    if (x >= 4)
    {
        return 1;
    }


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

int compare_hands(Card hand[], Card o_hand, int size)
{
    int x = eval(hand, size);
    int y = eval(o_hand, size);

    if (x > y) return 1; //Inputer loses

    if (y > x) return 0; //Inputer Wins

    return -1; //TIe
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

    card1.value = 1;
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

    Card hand[] = {card1, card2, card3, card4, card5, card6, card7};

    int size = 7;

    printf("%d", eval(hand, size));

    

    


}


    





