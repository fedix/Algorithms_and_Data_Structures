from graph_input import read_to_adj_list


def dfs(v, G, visited):
    '''
    :param v: вершина, с которой начинается поиск
    :param G: граф
    :param visited: множество посещенных вершин
    '''
    visited.add(v)
    for neighbour in G[v]:
        if neighbour not in visited:
            dfs(neighbour, G, visited)


G = {
    0: {1, 2, 4},
    1: {0, 2},
    2: {0, 1},
    3: {4},
    4: {0, 3},
    5: {6},
    6: {5}
}


def main():
    visited = set()
    N = 0
    for vertex in G:
        if vertex not in visited:
            dfs(vertex, G, visited)
            N += 1
    print('Количество компонент связности:', N)


if __name__ == '__main__':
    main()
