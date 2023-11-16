#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

// Comparison function for sorting items based on value per weight in descending order
bool compareItems(const Item& a, const Item& b) {
    return (static_cast<double>(a.value) / a.weight) > (static_cast<double>(b.value) / b.weight);
}

double fractionalKnapsack(int capacity, const vector<Item>& items) {
    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : sortedItems) {
        if (currentWeight + item.weight <= capacity) {
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            double remainingWeight = capacity - currentWeight;
            totalValue += remainingWeight * (static_cast<double>(item.value) / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
