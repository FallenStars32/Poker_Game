from objects import Cards 
import random 
import Error_Casses

"""This section deals with what a hand can do"""

#This creates a list of 52 cards which repersent a deck
def create_deck():
    deck = []
    for i in range(4):
        for j in range(2, 14):
            deck.append(Cards(i, j))
            
    return deck

#This shuffles that list
def shuffle_deck(deck):
    for i in range(50):
        card1 = random.randint(0, 51)
        card2 = random.randint(0, 51)
        deck[card1], deck[card2] = deck[card2, deck[card1]]
    return deck

#This cuts the deck in half
def cut_deck(deck, place):
    deck1 = deck[:place]
    deck2 = deck[place:] 
    return deck2 + deck1 


"""This section has to do with passing the hand to players"""

def deal_preflop(players, deck): 
    if (Error_Casses.pre_flop_erros_check(players, deck) != 0):
        return Error_Casses.pre_flop_erros_check(players, deck)
    
    deck = shuffle_deck(deck)
    deck = shuffle_deck(deck)
    deck = shuffle_deck(deck)
    

    