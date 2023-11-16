#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0-1 knapsack problem using dynamic programming
int knapsack(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();

    // Initialize a 2D array to store the maximum value for each subproblem
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp array
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is stored in the bottom-right cell of the dp array
    return dp[n][capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Solve the 0-1 knapsack problem using dynamic programming
    int maxValue = knapsack(capacity, weights, values);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
