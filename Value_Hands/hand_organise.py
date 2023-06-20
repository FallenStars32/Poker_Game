def amount_matching(card1=1, card2=14, card3=27, card4=41):
    hand = sorted([card1, card2, card3, card4])
    total = []
    for a in range(0, 4):
        amount = 0
        for i in hand:
            for j in [13, 26, 39]:
                if hand[a] + j == i:
                    amount += 1
        total.append(amount)
    return max(total) + 1
    

def offset_hand(hand):
    for i in range(len(hand)):
        if 13 >= i > 0:
            hand[i] = hand[i]
        elif 26 >= hand[i] > 13:
            hand[i] = hand[i] - 13
        elif 39 >= hand[i] > 13:
            hand[i] = hand[i] - 26
        elif 52 >= hand[i] > 26:
            hand[i] = hand[i] - 39
    return hand

def check_reapeats(hand):
    total = []
    for i in hand:
        amount = 0
        for j in range(len(hand)):
            if i == hand[j]:
                amount += 1
        total.append(amount)
    return total