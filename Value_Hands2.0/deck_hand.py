from objects import Cards 
import random 
import Error_Casses

"""This section deals with what a hand can do"""

#This creates a list of 52 cards which repersent a deck
def create_deck():
    x = 1
    deck = []
    for i in range(1, 5):
        for j in range(2, 15):
            deck.append(Cards(i, j, x))
            x+=1
            
    return deck

#This shuffles that list
def shuffle_deck(deck):
    for i in range(50):
        card1 = random.randint(0, 50)
        card2 = random.randint(0, 50)
        deck[card1], deck[card2] = deck[card2], deck[card1]
    return deck

#This cuts the deck in half
def cut_deck(deck, place):
    deck1 = deck[:place]
    deck2 = deck[place:] 
    return deck2 + deck1 


"""This section has to do with passing the hand to players"""

def deal_preflop(players, deck): 
    #if (Error_Casses.pre_flop_erros_check(players, deck) != 0):
        #return Error_Casses.pre_flop_erros_check(players, deck)
    
    #Three shuffles 
    deck = shuffle_deck(deck)
    deck = shuffle_deck(deck)
    deck = shuffle_deck(deck)
    
    #Add the cut part later 
    
    player_hands = []
    
    for i in range(players):
        player_hands.append([])
    
    for a in range(2):
        for i in range(players):
            player_hands[i].append(deck[0])
            deck.pop(0)
            
            
    return player_hands


    

#This gets the value of a card between 1-13
def get_value(hand):
    new_hand = []
    for i in hand:
        new_hand.append(i.value)
        
    return new_hand


# Gets the color of a card
def get_color(hand):
    new_hand = []
    for i in hand:
        new_hand.append(i.color)
        
    return new_hand



            
        
        
    

    