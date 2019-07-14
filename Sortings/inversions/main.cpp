#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
vector<T> merge(vector<T> L, vector<T> R, unsigned long &inversions) {
    vector<T> res;
    int i = 0, j = 0;
    while (i < L.size() || j < R.size()) {
        if (j == R.size() || (i < L.size() && L[i] <= R[j])) {
            res.push_back(L[i]);
            i++;
        } else {
            res.push_back(R[j]);
            j++;
            if (i < L.size())
                inversions += L.size() - i;
        }
    }
    return res;
}

template<typename T>
vector<T> mergeSort(vector<T> A, unsigned long &inversions) {
    int n = A.size();

    if (n <= 1)
        return A;
    int middle = floor(n / 2);
    vector<T> L, R;

    for (auto i = 0; i < middle; ++i)
        L.push_back(A[i]);
    for (auto i = middle; i < n; ++i)
        R.push_back(A[i]);

    L = mergeSort(L, inversions);
    R = mergeSort(R, inversions);
    return merge(L, R, inversions);
}


int main() {
    vector<int> A{7, 6, 5, 4, 3, 2, 1};
    unsigned long inversions = 0;
    A = mergeSort(A, inversions);

    cout << inversions << endl;
    return 0;
}