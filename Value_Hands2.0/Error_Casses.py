
"""This file is for managaiging and dealing with possible errors."""

"""deck_hand section 1000"""


def pre_flop_erros_check(deck, players):
    #1000
    if (len(deck) > 50):
        return 1100
    if (players < 0):
        return 1101
    return 0

