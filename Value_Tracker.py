

from deck import create_deck
def deck_value(card1, card2, card3=None,card4=None, card5=None):
    pass
    


def amount_matching(card1=1, card2=14, card3=27, card4=41):
    hand = sorted([card1, card2, card3, card4])
    total = []
    for a in range(0, 4):
        amount = 0
        for i in hand:
            for j in [13, 26, 39]:
                if hand[a] + j == i:
                    amount += 1
        total.append(amount)
    return max(total) + 1
    

def offset_hand(hand):
    for i in range(len(hand)):
        if 13 >= i > 0:
            hand[i] = hand[i]
        if 26 >= hand[i] > 13:
            hand[i] = hand[i] - 13
        if 39 >= hand[i] > 13:
            hand[i] = hand[i] - 26
        if 52 >= hand[i] > 26:
            hand[i] = hand[i] - 39
    return hand

def check_reapeats(hand):
    total = []
    for i in hand:
        amount = 0
        for j in range(len(hand)):
            if i == hand[j]:
                amount += 1
        total.append(amount)
    return total

def two_pair(total):
    amount = 0
    for i in total: 
        if i == 2:
            amount += 1
    if amount >= 2:
        return True 
    else:
        return False
    
def high_card(offset_hand):
    return sorted(offset_hand)[-1]

def pair(reapets):
    amount = 0 
    for i in reapets:
        if i == 2:
            amount += 1
    if amount == 2:
        return True
    else:
        return False
    
def three_of_a_kind(reapets):
    amount = 0
    for i in reapets:
        if i == 3:
            amount += 1
    if amount == 3:
        return True
    else:
        return False
    
def straight(hand):
    hand = sorted(hand) 
    amount = 0
    
    for i in range(0, 5):
        if hand[0] + i in hand:
            amount += 1
    if amount == 4:
        return True
    else:
        print(amount)
        return False
    
def flush(hand):
    amount = [0, 0, 0, 0]
    for i in hand:
        if 13 >= i > 0:
            amount[0] += 1
        elif 26 >= i > 13:
            amount[1] += 1
        elif 39 >= i > 26:
            amount[2] += 1
        elif 52 >= i > 13:
            amount[3] += 1
    if max(amount) == 4:
        return True
    else:
        return False
    
def full_house(reapets):
    amount1 = 0
    amount2 = 0
    for i in reapets:
        if i == 2:
            amount1 += 1
        if i == 3:
            amount2 += 1
    if amount1 == 2 and amount2 == 3:
        return True
    else:
        return False
    
def four_of_kind(reapets):
    for i in reapets:
        if i == 4:
            return True
    return False

def straight_flush(hand):
    if flush(hand) == True and straight(hand) == True:
        return True
    else:
        return False
    
def royal_flush(hand, offset_hand):
    if flush(hand) is True:
        if [1, 10, 11, 12, 13] in offset_hand:
            return True
        
        else:
            offset_hand = sorted(offset_hand)
            if offset_hand[0] == 1:
                if offset_hand[1] == 10:
                    if offset_hand[2] == 11:
                        if offset_hand[3] == 12:
                            if offset_hand[4] == 13:
                                return True
            return False








    