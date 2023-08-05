import cards


"""Eveyrhting has to return the following 

Hand Value 
HC in Play Cards
HC outside Play Cards

"""

def count_duplicates(arr):
    # Create a dictionary to store the occurrences of each element
    occurrences = {}

    # Loop through the array
    for item in arr:
        # If the item is already in the dictionary, increment its count
        if item in occurrences:
            occurrences[item] += 1
        else:
            # If the item is not in the dictionary, add it with count 1
            occurrences[item] = 1

    # Sort the dictionary by keys and convert it to a list of tuples
    sorted_occurrences = sorted(occurrences.items())

    return sorted_occurrences

def convert_value(hand):
    output = []
    for i in hand:
        output.append(i.value)
    return output

def two_kind(hand):
    new_hand = convert_value(hand)
    result = count_duplicates(new_hand)
    x = False
    IHC = -1
    max = 0 
    for i in result:
            if i[1] == 2:
                if (IHC == -1):
                    IHC = i[0]
                else:
                    if IHC > max:
                        max = IHC
                    IHC = i[0]
                x = True
            else:
                if i[0] >= max:
                    max = i[0]
                    
    if x == True:
        return [2, IHC, max]
    
    else:
        return [0, 0, max]
                
                
            
            

    
    
card1 = cards.Card(1, 4)
card2 = cards.Card(2, 5)
card3 = cards.Card(3, 6)
card4 = cards.Card(1, 5)
card5 = cards.Card(1, 6)

hand = [card1, card2, card3, card4, card5]

print(two_kind(hand))






