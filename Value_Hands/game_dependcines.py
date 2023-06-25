from Deck.deck import create_deck, shuffle_deck, cut


# This simulates a shuffle like a casino
def shuffle1(deck, cut_point):
    # Three Shuffles
    deck = shuffle_deck(deck)
    deck = shuffle_deck(deck)
    deck = shuffle_deck(deck)
    #Followed by a Cut which will be choosen by the USER
    deck = cut(deck, cut_point)
    return deck

# This creates the players using a list to store their deck 
''''Note for GUI each number will be attached to a different image'''
def create_players(player_amount):
    player = []
    for i in range(player_amount):
        player.append([0, 0, 0, 0, 0, 0, 0])
        
    return player

# This is the first deal where the deck is shuffled and then every player gets two cards and then the deck is made
def deal_card1(deck, cut_point, player_amount):
    deck = shuffle1(deck, cut_point)
    players = create_players(player_amount)
    for i in range(2):
        for j in range(len(players)):
            players[j][i] = deck[0]
            deck.pop(0)  
    return players

#This the the tradintal flop delt out  
def deal_flop1(deck, players):
    deck.pop(0) # Burn Card 
    for i in range(2, 5): # This gives every player the same card rather then having a seperate varibale. We will test this out later
        for j in range(len(players)):
            players[j][i] = deck[0]
        deck.pop(0)
    return players # Returns the players hand 

def deal_flop2(deck, players):
    deck.pop(0)
    for i in range(6): # This gives every player the same card rather then having a seperate varibale. We will test this out later
        for j in range(len(players)):
            players[j][i] = deck[0]
        deck.pop(0)
    return players # Returns the players hand 

def deal_flop3(deck,players):
    deck.pop(0)
    for i in range(7): # This gives every player the same card rather then having a seperate varibale. We will test this out later
        for j in range(len(players)):
            players[j][i] = deck[0]
        deck.pop(0)
    return players # Returns the players hand 
    

def deal_card2(deck, players):
    deck.pop(0)
    
def blue_print_game():
    deck = create_deck()
    shuffle1(deck, 5)
    players = deal_card1(deck, 10, 10)
    deal_flop1(deck, players)
    deal_flop2(deck, players)
    deal_flop3(deck, players)
    print(players) 
    return True 
    
    
blue_print_game()
    

    
    
    
    
