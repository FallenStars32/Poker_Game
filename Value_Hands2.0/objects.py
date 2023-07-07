import random

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


#"This creates a object that repersents card"
class Cards:
    def __init__(self, color, value):
        self.color = color 
        self.value = value 
        



    
    
    