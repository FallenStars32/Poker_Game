import random
from Deck.generate_random import generate_random_numbers


def create_deck():
    deck = []

    for i in range(1, 53):
        deck.append(i)
        
    deck = shuffle_deck(deck)
    if has_duplicates(deck) == True:
        create_deck
    return deck

def shuffle_deck(deck):
    for i in range(0, 10000):
        x = random.randint(0, 51)
        y = random.randint(0, 51)
        
        deck[x], deck[y] = deck[y], deck[x]
        
    return deck

def has_duplicates(arr):
    return len(set(arr)) != len(arr)

    








        
        