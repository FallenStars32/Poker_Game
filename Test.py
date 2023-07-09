import ctypes
import time
from Value_Hands.Deck.deck import create_deck

class Card(ctypes.Structure):
    _fields_ = [
        ("color", ctypes.c_int),
        ("value", ctypes.c_int)
    ]

lib = ctypes.CDLL('test.so')

# This creates the function used in the deck
lib.create_deck.argtypes = []
lib.create_deck.restype = ctypes.POINTER(Card)


lib.shuffle_deck.argtypes = [ctypes.POINTER(Card)]
lib.shuffle_deck.restype = ctypes.POINTER(Card)


deck = lib.create_deck()

shuffled_deck = lib.shuffle_deck(deck).contents






