#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int cost;
};

int KnapsackWithoutReps(int capacity, vector<Item> items) {
    vector<vector<int>> D(items.size(), vector<int>(capacity + 1));
    for (auto i = 0; i < items.size(); i++) {
        D[i][0] = 0;
    }
    for (auto w = 0; w < capacity; ++w) {
        D[0][w] = 0;
    }

    for (auto i = 1; i < items.size(); i++) {
        for (auto w = 1; w <= capacity; ++w) {
            D[i][w] = D[i - 1][w];
            if (items[i].weight <= w) {
                D[i][w] = max(D[i - 1][w], D[i - 1][w - items[i].weight] + items[i].cost);
            }
        }
    }
    return D[items.size() - 1][capacity];


}

int main() {
    int capacity, n_items;
    cin >> capacity >> n_items;
    vector<Item> items;
    items.push_back(Item{0, 0});
    for (auto i = 1; i <= n_items; i++) {
        int weight, cost;
        cin >> weight >> cost;
        items.push_back(Item{weight, cost});
    }

    cout << KnapsackWithoutReps(capacity, items);


    return 0;
}