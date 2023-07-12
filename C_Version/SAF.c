#include "depnecinces.h"
#include "extra.h"


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

int main(void)
{
    Card card1;
    Card card2;
    Card card3;
    Card card4;
    Card card5;
    Card card6;
    card1.value = 10; 
    card2.value = 11;
    card3.value = 12;
    card4.value = 13;
    card5.value = 5;
    card6.value = 6;

    card1.color = 1;
    card2.color = 1;
    card3.color = 1;
    card4.color = 1;
    card5.color =1;

    Card hand[] = {card1, card2, card3, card4, card5, card6};

    printf("%d", check_RF(hand, 6)); 
}