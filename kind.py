from deck import create_deck
from hand_organise import offset_hand, check_reapeats
from Value_Tracker import high_card


def full_house(hand):
    A = kind_checker(hand, 3)
    B = kind_checker(hand, 2)
    if A[0] and B[0] == True:
        if A[1][1] > B[1][1]:
            HV = A[1][1]
        else:
            HV = B[1][1]
        HC = A[1][2]
        return [True, [7, HV, HC]]
            
    
def kind_checker(hand, type):
    # Sorts the hand in ord EXP [1, 1, 3, 5, 6] and makes a duplicate for the pop function
    hand = sorted(hand)
    dup_hand = sorted(hand)
    #Offsets the hand to put it in the 1-13 range and then checks for repets should convert to [1, 1, 3, 5, 6] --> [1, 1, 3, 5, 6] --> [2, 2, 0, 0, 0]
    rep = check_reapeats(offset_hand(hand))
    #Sets HV to 0 and amount to 0
    HV, amount = 0, 0
    # Begins for loop to check repitatios
    for i in range(len(rep)):
        #Checks to see if there are two of those in the list
        if rep[i] == type:
            #If true adds one to amount 
            amount += 1
            #Checks to see if the one included is the newest HV
            if hand[i] > HV:
                #If True it becomes the new high value
                HV = hand[i]
            #Changes the hand place to 0 if used
            dup_hand[i] = 0
    #If there are two points where the number is found twice then it comes out as True and return True and the formula 
    if amount == type:
        HC = high_card(dup_hand)
        if type == 3:
            V = type + 1
        elif type == 4:
            V = 8
        else:
            V = type
        return [True, [V, HV, HC]]
    else:
        return [False]
    

print(full_house([1, 1, 1, 3, 3]))