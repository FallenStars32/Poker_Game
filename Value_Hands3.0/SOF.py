import deck_hand
import objects

#Checks for a straight
def straight(hand):
    num_hand = deck_hand.get_value(hand)
    x = 0 
    #playing_hand = [] implemnt for tiebrakers 
    #reg_cards = [] implement for tiebrakers
    for i in range(len(num_hand) - 1):
        if (num_hand[i] + 1) == num_hand[i+1]:
            x += 1
        else:
            x = 0
    
    if x == 4:
        return True
    else:
        return False

#Checks for a flush
def flush(hand):
    color_hand = deck_hand.get_color(hand)
    a = 0
    b = 0
    c = 0
    d = 0
    for i in color_hand:
        if i == 1:
            a += 1
        elif i == 2:
            b += 1
        elif i == 3:
            c += 1
        elif i == 4:
            d += 1
            
    if a >= 5 or b >= 5 or c >= 5 or d >= 5: #Fixe it so that this was greater then for the probibility system
        return True
    else:
        return False 
    
#Checks for a straight flush    
def straight_flush(hand):
    if flush(hand) == True:
        if straight(hand) == True:
            return True
    
    return False
#Checks for a royal flush    
def royal_flush(hand):
    value_hand = deck_hand.get_value(hand)
    if 10 in value_hand:
        if 11 in value_hand:
            if 12 in value_hand:
                if 13 in value_hand:
                    if 14 in value_hand:
                        if flush(hand) == True:
                            return True
                    
                    
    return False
            
        
    

    
    

    


