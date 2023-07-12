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
    for i in range((len(deck) - 1)-len_han): #EXP 52 - 5 = 47
        cur_hand = []
        for h in hand:
            cur_hand.append(h)  
        for j in range(emppty - 1): #7
            cur_hand.append(deck[i + j])
            
        pos_hands.append(cur_hand)
        
    return pos_hands

def odds(hand):
    
    #Added to combat 0 error still needs to be fixed
    if len(hand) == 0:
        return [0.423, 0.0475, 0.0211, 0.00392, 0.00197, 0.00144, 0.000240, 0.0000139, 0.000154]
        
    else:
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
                
        
        pair_odds = a /b 
        two_pair_odds = c / b
        three_kind_odds = d / b
        straight_odds = e / b
        flush_odds = f / b
        full_house_odds = g / b
        four_kind_odds = h / b
        striaght_flush_odds = x / b
        royal_flush_odds = j / b
        
        pair_odds = pair_odds + three_kind_odds + four_kind_odds
        three_kind_odds = three_kind_odds + four_kind_odds
        
        return [pair_odds,two_pair_odds, three_kind_odds, straight_odds, flush_odds, full_house_odds, four_kind_odds, striaght_flush_odds, royal_flush_odds]

def odds_losing(middle, hand):
    hands = odds(hand)
    op_odds = odds(middle)
    
    for i, j in hands, op_odds:
        return 0
                  
        
        

        
        
        
        
        
    
    
"""

Color 
1 = Spades
2 = Clubs
3 = Dimandos
4 = Hearts

"""



