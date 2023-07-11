

import objects
import Calc
import POK

"""Cards are on a scale of 2-13
2 = Two 
3 = Three
4 = four
5 = five
6  = six
7 = eight 
9 = nine
10 = ten
11 = Jacks
12 = Queens
13 = Kings
14 = Aces

Color 
1 = Spades
2 = Clubs
3 = Dimandos
4 = Hearts

Hand values are determined by the following 
1. Hand Value 
2. High Card in Hand 
3. High Card
4. Split
"""




card1 = objects.Cards(4, 13,  0)
card2 = objects.Cards(4, 2,  0)
card3 = objects.Cards(2, 13, 0)
card4 = objects.Cards(2, 5, 0)
card5 = objects.Cards(4, 12, 0)
card6 = objects.Cards(1, 13, 0)


hand = [card1, card2]

middle = [card3, card4, card5, card6]

print(Calc.odds(hand + middle))

print(Calc.odds(middle))
            
            
#Create a forumula to calcute odds 

#Make this forumula more efficent