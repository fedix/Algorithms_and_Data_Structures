#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const unsigned int INF = 10000;

pair<vector<int>, vector<int>> bfs(vector<vector<int>>& g, int start) {
    vector<int> distances(g.size(), INF), parents(g.size());
    distances[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto i = g[v].begin(); i < g[v].end(); i++) {
            if (distances[*i] == INF) {
                distances[*i] = distances[v] + 1;
                q.push(*i);
                parents[*i] = v;
            }
        }
    }
    return make_pair(distances, parents);
}

vector<int> restore_path(vector<int> parents, int start, int destination) {
    vector<int> path;
    path.push_back(destination);
    int parent = parents[destination];
    while (parent != start) {
        path.push_back(parent);
        parent = parents[parent];
    }
    path.push_back(start);
    reverse(begin(path), end(path));
    return path;
}


void find_shortest_path(vector<vector<int>>& g, int start, int destination) {
    auto[distances, parents] = bfs(g, start);
    vector<int> path = restore_path(parents, start, destination);
    cout << "Path: ";
    for (auto v : path)
        cout << v << (v == path.back() ? "\n" : " -> ");
}


int main() {
    vector<vector<int>> graph{
            {1, 2, 4, 5, 8},
            {0, 9},
            {0, 3},
            {2, 4},
            {0, 3, 5, 6},
            {0, 4, 7},
            {4, 7, 10},
            {5, 6, 8, 10},
            {0, 7},
            {1},
            {6, 7}
    };
    auto[distances, parents] = bfs(graph, 0);
    for (auto i : distances)
        cout << i << " ";
    cout << endl;
    for (auto i : parents)
        cout << i << " ";
    cout << endl;
    find_shortest_path(graph, 0, 6);
    return 0;
}