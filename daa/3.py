def fractional_knapsack():
    weights = [10, 20, 30]
    values = [60, 100, 120]
    capacity = 50
    res = 0

    # Create a list of pairs [Weight, Value] and sort it in descending order of value-to-weight ratio
    sorted_items = sorted(zip(weights, values), key=lambda x: x[1] / x[0], reverse=True)

    for pair in sorted_items:
        if capacity <= 0:
            # Capacity completed - Bag fully filled
            break
        if pair[0] > capacity:
            # Current item's weight with the highest value/weight ratio exceeds available capacity
            res += int(capacity * (pair[1] / pair[0]))  # Take a fraction of the item
            capacity = 0
        elif pair[0] <= capacity:
            # Take the whole item
            res += pair[1]
            capacity -= pair[0]

    print(res)

if __name__ == "__main__":
    fractional_knapsack()

