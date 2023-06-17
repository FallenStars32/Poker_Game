from deck import create_deck
from hand_organise import offset_hand, check_reapeats
from Value_Tracker import high_card


def Straight(hand):
    hand = sorted(hand)
    included = []
    unincluded = []
    amount = 0
    
    OF_Hand = offset_hand(hand)
    for i in range(len(hand) - 1):
        if hand[i] + 1 == hand[i+1]:
            amount += 1
            included.append(hand[i])
            if amount >= 4:
                included = sorted(included)
                HV = included[-1] + 1
                HC = max(set(hand) - set(included))
                return [True, [5, HV, HC]]
            else:
                unincluded.append(hand[i])
        else:
            amount = 0
            included = []
    
    
    return [False]

def Flush(hand):
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
    
print(Straight([1, 2, 4, 5, 6, 3, 10]))
    

   