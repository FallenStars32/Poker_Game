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
    # Sets up the different groups
    group = [[], [], [], []]
    #Finds the Highest Value group
    HV = 0
    for i in hand:
        if 13 >= i > 0:
            group[0].append(i)
        elif 26 >= i > 13:
            group[1].append(i)
        elif 39 >= i > 26:
            group[2].append(i)
        elif 52 >= i > 13:
            group[3].append(i)
    for i in range(len(group)):
        LEN = len(group[i])
        if LEN >= 5:
            playing_hand = sorted(group[i])
            HV = playing_hand[4]
            for i in range(5):
                i = playing_hand[i]
                if i in hand:
                    hand.remove(i)
            HC = high_card(hand)
            return [True, [5, HV, HC]]
        else:
            continue
        
    return [False]

def straight_flush(hand):
    A = Flush(hand)
    B = Straight(hand)
    if A[0] == True and B[0] == True:
        return [True, [B[1][0], B[1][1], B[1][2]]]
    else:
        return [False]
    
print(straight_flush([1, 2, 3, 4, 5, 6, 7]))