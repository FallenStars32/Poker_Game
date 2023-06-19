from SAF import Straight, Flush, straight_flush
from kind import kind_checker, full_house, two_pair
from Value_Tracker import high_card, royal_flush



def hand_value(hand):
    Values = [0] * 11
    Values[0] = high_card(hand,True)[1]
    Values[1] = [0, 0, 0]
    Values[2] = kind_checker(hand, 2)[1]
    Values[3] = two_pair(hand)[1]
    Values[4] = kind_checker(hand, 3)[1]
    Values[5] = Straight(hand)[1]
    Values[6] = Flush(hand)[1]
    Values[7] = full_house(hand)[1]
    Values[8] = kind_checker(hand, 4)[1]
    Values[9] = straight_flush(hand)[1]
    Values[10] = royal_flush(hand)[1]
    
    print(Values)
    
    
    
    
