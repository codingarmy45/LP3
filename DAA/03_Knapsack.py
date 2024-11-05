class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight

def compare(item):
    # Returns the value-to-weight ratio for sorting
    return item.value / item.weight

def fractional_knapsack(capacity, items):
    # Step 1: Sort items by value-to-weight ratio in descending order
    items.sort(key=compare, reverse=True)

    total_value = 0.0  # Total value accumulated in the knapsack
    current_weight = 0  # Current weight in the knapsack

    # Step 2: Iterate through the sorted items
    for item in items:
        if current_weight + item.weight <= capacity:
            # If the whole item can fit, take it
            current_weight += item.weight
            total_value += item.value
        else:
            # If only part of the item can fit, take the fraction
            remaining_capacity = capacity - current_weight
            total_value += item.value * (remaining_capacity / item.weight)
            break  # Knapsack is full

    return total_value

# Test case
capacity = 50  # Capacity of the knapsack
items = [
    Item(60, 10),
    Item(100, 20),
    Item(120, 30)
]

# Calculate the maximum value for the knapsack capacity
max_value = fractional_knapsack(capacity, items)
print("Maximum value in the knapsack =", max_value)
