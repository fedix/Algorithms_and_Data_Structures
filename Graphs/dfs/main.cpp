#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void DFS(vector<vector<int>> g, int v, vector<bool> &visited) {
    visited[v] = true;
    cout << "in " << v << endl;
    for (auto i = g[v].begin(); i != g[v].end(); ++i) {
        if (!visited[*i])
            DFS(g, *i, visited);
    }
    cout << "out " << v << endl;
}

int main() {
    vector<vector<int>> graph{
            {1, 2, 3},
            {0, 2, 4},
            {0, 1, 3},
            {0, 2},
            {1, 3}
    };
    vector<bool> visited(5);
    DFS(graph, 0, visited);

    return 0;
}