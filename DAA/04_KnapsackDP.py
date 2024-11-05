def knapSack_DP(W, wt, val, n):
    # Create a 2D array K to store the maximum value for each subproblem
    K = [[0 for w in range(W + 1)] for i in range(n + 1)]
    
    # Build the DP table K[][] in a bottom-up manner
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0  # Initialize the first row and first column with 0
            elif wt[i - 1] <= w:
                # Include the item and exclude the item, take max of both
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w])
            else:
                # If item cannot be included, inherit value from above cell
                K[i][w] = K[i - 1][w]
    
    return K[n][W]  # Return the maximum value for the full capacity and all items

# Example usage
val = [60, 100, 120]  # Values of items
wt = [10, 20, 30]     # Weights of items
W = 50                # Knapsack capacity
n = len(val)          # Number of items

print("Maximum value in the knapsack:", knapSack_DP(W, wt, val, n))
