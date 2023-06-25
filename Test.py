import ctypes
import time
from Value_Hands.Deck.deck import create_deck

class Card(ctypes.Structure):
    _fields_ = [
        ("color", ctypes.c_int),
        ("value", ctypes.c_int)
    ]

lib = ctypes.CDLL('test.so')

lib.create_deck.argtypes = []
lib.create_deck.restype = ctypes.POINTER(Card)


start_time = time.time()

for i in range(0, 100):
    deck = lib.create_deck()

end_time = time.time()
time_length = end_time - start_time

print(f"C did it in {time_length} seconds")

start_time = time.time()

for i in range(0, 100):
    deck = create_deck()

end_time = time.time()
time_length = end_time - start_time

print(f"Python did it in {time_length} seconds")

