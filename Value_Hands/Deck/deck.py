import random



def create_deck():
    deck = []

    for i in range(1, 53):
        deck.append(i)
        
    deck = shuffle_deck(deck)
    if has_duplicates(deck) == True:
        create_deck
    return deck

def shuffle_deck(deck):
    H = len(deck) - 1
    for i in range(0, 10000):
        x = random.randint(0, H)
        y = random.randint(0, H)
        
        deck[x], deck[y] = deck[y], deck[x]
        
    return deck
        

def has_duplicates(arr):
    return len(set(arr)) != len(arr)





def cut(deck, split_point):
    
    result = deck[:] #Creates a shallow copy
    top = []
    for i in range(split_point):
        a = deck[i]
        top.append(a)
        result.remove(a)
        
    result += top
    return result





    

    
    

    








        
        