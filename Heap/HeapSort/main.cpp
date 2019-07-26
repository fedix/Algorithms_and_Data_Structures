#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void siftUp(vector<int> &heap, int i) {
    int parent = (i - 1) / 2;
    while (i > 0 && heap[i] > heap[parent]) {
        swap(heap[i], heap[parent]);
        i = parent;
        parent = floor((i - 1) / 2);
    }
}

void siftDown(vector<int> &heap, int i) {
    while (2 * i + 1 < heap.size()) {
        int max = i,
                left = 2 * i + 1, right = 2 * i + 2;
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

//void buildHeap(vector<int> &A) {
//    for (int i = floor((A.size() - 2)/2); i >= 0; i--) {
//        siftDown(A, i);
//    }
//
//}
//
//void heapSort(vector<int> &A) {
//    buildHeap(A);
//    int size = A.size() - 1;
//    for (int i = 1; i < A.size(); i++) {
//        swap(A[0], A[size]);
//        size--;
//        siftDown(A, 0);
//    }
//}


void heapSort(vector<int> &A) {
    vector<int> heap;
    for (auto i : A)
        insert(heap, i);
    for (auto i : heap)
        cout << i << " ";
    cout << endl;
    for (int i = A.size() - 1; i >= 0; i--)
        A[i] = extractMax(heap);

}

int main() {
    int n;
    vector<int> numbers{7, 6, 2, 3, 4, 5, 1, 3, 5};
    heapSort(numbers);
//    buildHeap(numbers);
    for (auto i : numbers) {
        cout << i << " ";

    }
    cout << endl;
    return 0;
}

