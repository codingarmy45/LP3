#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapSack_DP(int W, vector<int>& wt, vector<int>& val, int n) {
    // Create a 2D vector to store the maximum value that can be obtained
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    // Build the K table in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0; // Base case: no items or weight 0
            } else if (wt[i - 1] <= w) {
                // Max of including the item or excluding it
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                // Cannot include the item
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // The last cell of the table contains the maximum value
    return K[n][W];
}

int main() {
    vector<int> val = {60, 100, 120}; // Values of items
    vector<int> wt = {10, 20, 30};    // Weights of items
    int W = 50;                       // Maximum weight capacity
    int n = val.size();               // Number of items

    cout << "Maximum value in Knapsack = " << knapSack_DP(W, wt, val, n) << endl;

    return 0;
}