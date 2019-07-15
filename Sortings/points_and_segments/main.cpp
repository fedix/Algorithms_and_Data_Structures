#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LEFT = -1;
const int POINT = 0;
const int RIGHT = 1;

struct Point {
    int x;
    int type;
    int index;

    Point(int x, int type, int index) : x(x), type(type), index(index) {}
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<Point> points;
    vector<int> ans(m);
    for (auto i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        points.push_back(Point(a, LEFT, -1));
        points.push_back(Point(b, RIGHT, -1));
    }

    for (auto i = 0; i < m; i++) {
        int x;
        cin >> x;
        points.push_back(Point(x, POINT, i));
    }

    sort(points.begin(), points.end(), [](const Point &left, const Point &right) {
        if (left.x != right.x) {
            return left.x < right.x;
        } else {
            return left.type < right.type;
        }
    });

    int count = 0;
    for (auto p : points) {
        if (p.type == LEFT)
            count++;
        else if (p.type == RIGHT)
            count--;
        else if (p.type == POINT)
            ans[p.index] = count;
    }

    for (auto p: ans)
        cout << p << " ";
    return 0;
}