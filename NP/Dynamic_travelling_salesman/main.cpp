#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1000000;

int findCheapestCycle(vector<vector<int>> &A) {
    int n = A.size();
    vector<vector<int>> d((1 << n), vector<int>(n, INF));
    d[0][0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (d[mask][i] == INF)
                continue;
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j)))
                    d[mask ^ (1 << j)][j] = min(d[mask ^ (1 << j)][j], d[mask][i] + A[i][j]);
            }
        }
    }
    int length = d[(1 << n) - 1][0];
    int i = 0;
    int mask = (1 << n) - 1;
    vector<int> path{0};
    while (mask - pow(2, i) != 0) {
        for (int j = 0; j < n; j++) {
            if ((A[j][i]) && (mask & (1 << j)) && (d[mask][i] == d[mask - pow(2, i)][j] + A[j][i])) {
                path.push_back(j);
                mask -= pow(2, i);
                i = j;
                break;
            }
        }
    }
    reverse(begin(path), end(path));
    for (auto i : path)
        cout << i << " ";
    cout << endl;
    return length;
}

int main() {
    vector<vector<int>> A{
            {0,  1, 15, 6},
            {2,  0, 7,  3},
            {9,  6, 0,  12},
            {10, 4, 8,  0}
    };
    cout << findCheapestCycle(A);

    return 0;
}