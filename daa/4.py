def knapsack_dp(W, wt, val, n):
    # Create a 2D array K, where K[i][w] represents the maximum value for the first i items with a capacity of w.
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]

    # Build the K table using dynamic programming
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i - 1] <= w:
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]

    return K[n][W]  # The maximum possible profit is in K[n][W]

val = [60, 100, 120]
wt = [10, 20, 30]
W = 50  # Weight capacity
n = len(val)

# Call the knapsack_dp function to find the maximum possible profit
print("Maximum possible profit =", 
knapsack_dp(W, wt, val, n))
