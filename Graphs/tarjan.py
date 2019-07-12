def tarjan(G):
    def dfs(G, v, visited, ans):
        visited[v] = True
        for neighbour in G[v]:
            if not visited[neighbour]:
                dfs(G, neighbour, visited, ans)
        ans.append(v)

    ans = []
    visited = [False] * len(G)
    for vertex in G:
        if not visited[vertex]:
            dfs(G, vertex, visited, ans)
    ans = ans[::-1]
    return ans


def main():
    G = {
        0: {1, 4, 7},
        1: {2, 5},
        2: {3},
        3: {6},
        4: {5},
        5: {3},
        6: {},
        7: {8},
        8: {6}
    }
    sequence = tarjan(G)
    print(sequence)
    for i in sequence:
        print('{} -> {}'.format(i, sequence.index(i)))


if __name__ == '__main__':
    main()