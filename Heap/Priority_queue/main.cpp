#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void siftUp(vector<int> &heap, int i) {
	int parent = (i - 1)/2;
	while (i > 0 && heap[i] > heap[parent]) {
		swap(heap[i], heap[parent]);
		i = parent;
		parent = (i - 1)/2;
	}
}

void siftDown(vector<int> &heap, int i) {
	while (2*i + 1 < heap.size()) {
		int max = i,
		left = 2*i + 1, right = 2*i + 2;
		if (heap[left] > heap[max])
			max = left;
		if (right < heap.size() && heap[right] > heap[max])
			max = right;
		if (i == max)
			break;
		swap(heap[i], heap[max]);
		i = max;
	}
}

void insert(vector<int> &heap, int key) {
	heap.push_back(key);
	siftUp(heap, heap.size() - 1);
}

int extractMax(vector<int> &heap) {
	int result = heap[0];
	heap[0] = heap.back();
	heap.erase(heap.begin() + heap.size() - 1);
	siftDown(heap, 0);
	return result;
}

int main() {
	int n;
	vector<int> heap;
	cin >> n;
	for (auto i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "Insert") {
			int key;
			cin >> key;
			insert(heap, key);
		}
		else
			cout << extractMax(heap) << endl;
	}
	return 0;
}

