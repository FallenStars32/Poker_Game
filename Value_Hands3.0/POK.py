import deck_hand
import objects



def two_kind(hand):
    num_hand = deck_hand.get_value(hand)
    num_counts = []
    for i in range(len(num_hand)):
        num_counts.append(num_hand.count(num_hand[i]))
        
    x2 = 0      
    for i in num_counts:
        if i == 2:
            x2+=1
    
    if x2 >= 2:
        return True   
    return False

def two_pair(hand):
    num_hand = deck_hand.get_value(hand)
    num_counts = []
    for i in range(len(num_hand)):
        num_counts.append(num_hand.count(num_hand[i]))
        
    x2 = 0      
    for i in num_counts:
        if i == 2:
            x2+=1
    if x2 >= 4:
        return True   
    return False

def three_kind(hand):
    num_hand = deck_hand.get_value(hand)
    num_counts = []
    for i in range(len(num_hand)):
        num_counts.append(num_hand.count(num_hand[i]))
        
    x2 = 0      
    for i in num_counts:
        if i == 3:
            x2+=1
    
    if x2 >= 3:
        return True   
    return False

def four_kind(hand):
    num_hand = deck_hand.get_value(hand)
    num_counts = []
    for i in range(len(num_hand)):
        num_counts.append(num_hand.count(num_hand[i]))
        
    x2 = 0      
    for i in num_counts:
        if i == 4:
            x2+=1
    
    if x2 >= 4:
        return True   
    return False

def full_house(hand):
    if three_kind(hand) == True:
        if two_kind(hand) == True:
            return True
    return False
    
            
    

card1 = objects.Cards(4, 14, 1)
card2 = objects.Cards(4, 14, 1)
card3 = objects.Cards(4, 10, 1)
card4 = objects.Cards(4, 12, 1)
card5 = objects.Cards(4, 12, 1)

hand = [card1, card2, card3, card4, card5]




