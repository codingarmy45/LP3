#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item with value and weight
struct Item {
    int value;
    int weight;

    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value-to-weight ratio
bool compare(const Item& a, const Item& b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;  // Descending order
}

// Function to calculate the maximum value for the knapsack capacity
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Step 1: Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // Total value of the knapsack
    int currentWeight = 0;     // Current weight in the knapsack

    // Step 2: Iterate through the sorted items
    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // If the entire item can fit, take it
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // If only part of the item can fit, take the fraction
            int remainingCapacity = capacity - currentWeight;
            totalValue += item.value * ((double)remainingCapacity / item.weight);
            break;  // The knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;  // Capacity of the knapsack

    // List of items (value, weight)
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    // Calculate the maximal value of fractions that fit into the knapsack
    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value in the knapsack = " << maxValue << endl;
    return 0;
}
