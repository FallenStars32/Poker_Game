from hand_organise import offset_hand, check_reapeats
def deck_value(*args):
    hand = []
    for arg in args:
        hand.append(arg)
        
    OFF_Hand = offset_hand(hand)
    reapets = check_reapeats(OFF_Hand)
    return 0 
    
def high_card(hand, A = None):
    if len(hand) == 0:
        HV = 0
    else:
        OF_Hand = offset_hand(hand)
        HV = sorted(OF_Hand)[-1]
    # Added because some functions need to see the [Result, [Value_Hand, Hand_Hight_Value, High_Card]] form 
    if A != None:
        return [True, [0, HV, HV]]
    return HV

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
    
def royal_flush(hand):
    OFF_hand = offset_hand(hand)
    if flush(hand) is True:
        if [1, 10, 11, 12, 13] in OFF_hand:
            return [True, [13, 13, 13]]
        
        else:
            OFF_hand = sorted(OFF_hand)
            if OFF_hand[0] == 1:
                if OFF_hand[1] == 10:
                    if OFF_hand[2] == 11:
                        if OFF_hand[3] == 12:
                            if OFF_hand[4] == 13:
                                return [True, [13, 13, 13]]
            return [False, [0, 0, 0]]
        
    return [False, [0, 0, 0]]








