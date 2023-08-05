import random


class Card:
    def __init__(self, color, value):
        self.color = color
        self.value = value

class Hand:
    def __init__(self, value, hand):
        self.value = value
        self.hand = hand
        
    def calc_value(self):
        return 30
        
        
        
class Deck:
    
    
    def __init__(self, deck):
         self.deck = deck
         
    def add_cards(self):
        new_deck = []

        for i in range(4):
            for j in range(13):
                new_deck.append(Card(i, j+2))
                
        self.deck = new_deck
        
    def print_Deck(self):
        for i in self.deck:
            print(i.value)
            
    def shuffle_deck(self):
        for i in range(100):
            a = random.randint(0, len(self.deck) - 1)
            b = random.randint(0, len(self.deck) - 1)
            
            while a == b:
                b = random.randint(0, len(self.deck) - 1)
                
            self.deck[a], self.deck[b] = self.deck[b], self.deck[a]
            
    def remove_top_card(self):
        card = self.deck[0]
        self.deck.pop(0)
        return card
    
    

            
            

        
                



                
        