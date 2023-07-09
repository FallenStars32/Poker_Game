import deck_hand
import objects
import POK
import SOF


#Tests every card to see whats needed to create a pair 

#Get the car and push them to the


def possible_hands(hand):
    len_han = len(hand)
    emppty = 7 - len(hand)
    
    deck = deck_hand.create_deck()
    
    for i in range(len(deck)):
        for j in range(len(hand)):
            if (hand[j] == deck[i]):
                deck.pop(i)
    
    
    pos_hands = []
      
    #This loops through the deck and accounts for len_hand which ads itself  
    for i in range(len(deck)-len_han): #EXP 52 - 5 = 47
        cur_hand = []
        for h in hand:
            cur_hand.append(h)  
        for j in range(emppty): #7
            cur_hand.append(deck[i + j])
            
        pos_hands.append(cur_hand)
        
    return pos_hands

def odds(hand):
    possible_hand = possible_hands(hand)
    
    b = len(possible_hand)
    
    #The amount of pair hands = a and the amount of hands = b. 
    
    a, c, d, e, f, g, h, x, j = 0, 0, 0, 0, 0, 0, 0, 0, 0
    
    odds = [a, c, d, e, f, g, h, x, j]
    
    for i in possible_hand:
        if POK.two_kind(i) == True:
            a += 1
        if POK.two_pair(i) == True:
            c += 1
        if POK.three_kind(i) == True:
            d += 1
            
        if SOF.straight(i) == True:
            e += 1
        if SOF.flush(i) == True:
            f += 1
        if POK.full_house(i) == True:
            g += 1
        if POK.four_kind(i) == True:
            h += 1
        if SOF.straight_flush(i) == True:
            x += 1
        if SOF.royal_flush(i) == True:
            j += 1
      
          
            
    return [a / b, c / b, d / b, e/ b, f / b, g / b, h / b, x / b, j / b]
                  
        
        

        
        
        
        
        
    
    
"""

Color 
1 = Spades
2 = Clubs
3 = Dimandos
4 = Hearts

"""

card1 = objects.Cards(1, 1, 1)
#card2 = objects.Cards(1, 2, 2)
#card3 = objects.Cards(1, 3, 3)
#card4 = objects.Cards(1, 4, 4)
#card5 = objects.Cards(1, 5, 5)

#card6 = objects.Cards(1, 5, 5)
#card7 = objects.Cards(1, 5, 5)

hand = [card1, card2]

print(odds(hand))


