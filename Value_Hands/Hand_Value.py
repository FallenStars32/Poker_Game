from SAF import Straight, Flush, straight_flush
from kind import kind_checker, full_house, two_pair
from Value_Tracker import high_card, royal_flush
from Deck import deck


def hand_value(hand):
    hand = sorted(hand)
    Values = [0] * 10
    Values[0] = high_card(hand,True)[1]
    Values[1] = kind_checker(hand, 2)[1]
    Values[2] = two_pair(hand)[1] # Bug: If you enter in one value this returns an Error 
    Values[3] = kind_checker(hand, 3)[1]
    Values[4] = Straight(hand)[1]
    Values[5] = Flush(hand)[1]
    Values[6] = full_house(hand)[1]
    Values[7] = kind_checker(hand, 4)[1]
    Values[8] = straight_flush(hand)[1]
    Values[9] = royal_flush(hand)[1]
    
    
    
    return Values
    
    

deck = deck.create_deck()


print(two_pair(deck))
