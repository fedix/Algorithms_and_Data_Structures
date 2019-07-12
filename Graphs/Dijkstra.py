from collections import deque


def Dijkstra(G, start):
    distance = {}
    q = deque()
    parents = [None] * len(G)
    q.append(start)
    distance[start] = 0
    while q:
        v = q.popleft()
        for u in G[v]:
            if u not in distance or distance[v] + G[v][u] < distance[u]:
                distance[u] = distance[v] + G[v][u]
                q.append(u)
                parents[u] = v
    return distance, parents


def Dijkstra2(G, start):
    # using list of distances instead of dict - less "pythonic"
    distance = [None] * len(G)
    q = deque()
    parents = [None] * len(G)
    q.append(start)
    distance[start] = 0
    while q:
        v = q.popleft()
        for u in G[v]:
            if distance[u] is None or distance[v] + G[v][u] < distance[u]:
                distance[u] = distance[v] + G[v][u]
                q.append(u)
                parents[u] = v
    return distance, parents


def restore_path(G, parents, destination):
    path = [destination]
    parent = parents[destination]
    while parent is not None:
        path.append(parent)
        parent = parents[parent]
    return path[::-1]


def find_shortest_path(G, start, destination):
    _, parents = Dijkstra(G, start)
    return restore_path(G, parents, destination)


def main():
    G = {
        0: {1: 2, 6: 15},
        1: {0: 2, 2: 5, 3: 1},
        2: {1: 5, 3: 3, 4: 4, 7: 6},
        3: {1: 1, 2: 3, 4: 2, 5: 1},
        4: {2: 4, 3: 2, 5: 1, 6: 3, 7: 7},
        5: {3: 1, 4: 1},
        6: {0: 15, 4: 3, 8: 12},
        7: {2: 6, 4: 7, 8: 2},
        8: {6: 12, 7: 2}
    }
    start, destination = 0, 8
    distances, parents = Dijkstra(G, start)
    for i in range(len(distances)):
        print('{}: {}'.format(i, distances[i]))

    path = restore_path(G, parents, destination)
    print(path)

    print(find_shortest_path(G, 2, 0))

    distances, parents = Dijkstra2(G, start)
    for i in range(len(distances)):
        print('{}: {}'.format(i, distances[i]))


if __name__ == '__main__':
    main()
