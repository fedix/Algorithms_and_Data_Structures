from collections import deque


def bfs(G, start):
    distances = [None] * len(G)
    distances[start] = 0
    parents = [None] * len(G)
    q = deque([start])
    q.append(start)
    while q:
        cur_v = q.popleft()
        for neigbour in G[cur_v]:
            if distances[neigbour] is None:
                distances[neigbour] = distances[start] + 1
                q.append(neigbour)
                parents[neigbour] = cur_v
    return distances, parents


def restore_path(parents, destination):
    path = [destination]
    parent = parents[destination]
    while parent is not None:
        path.append(parent)
        parent = parents[parent]
    path = path[::-1]
    return path


def find_shortest_path(G, start, destination):
    _, parents = bfs(G, start)
    path = restore_path(parents, destination)
    return path


def main():
    G = {
        0: {1, 2, 4, 5, 8},
        1: {0, 9},
        2: {0, 3},
        3: {2, 4},
        4: {0, 3, 5, 6},
        5: {0, 4, 7},
        6: {4, 7, 10},
        7: {5, 6, 8, 10},
        8: {0, 7},
        9: {1},
        10: {6, 7}
    }
    start, end = 0, 10
    distances, parents = bfs(G, start)
    path = restore_path(parents, end)
    print(distances)
    print(parents)
    print(path)
    print(find_shortest_path(G, 3, 8))


if __name__ == '__main__':
    main()
