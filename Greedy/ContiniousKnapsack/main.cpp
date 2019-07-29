#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Item{
	double value, weight;
};

int main() {
	int n, capacity;
	double sum = 0;
	cin >> n >> capacity;
	vector<Item> items(n);
	for (auto i = 0; i < n; i++){
		cin >> items[i].value >> items[i].weight;
	}
	sort(items.begin(), items.end(), [](auto &a, auto &b){
		return b.value/b.weight < a.value/a.weight;
	});

	for (auto i : items) {
		if (capacity > i.weight && capacity > 0){
			sum += i.value;
			capacity -= i.weight;
		} else {
			sum += i.value * (static_cast <double>(capacity) / i.weight);
			capacity = 0;
			break;
		}
	}

	cout << fixed << setprecision(3) << sum << endl;
 	return 0;
}

