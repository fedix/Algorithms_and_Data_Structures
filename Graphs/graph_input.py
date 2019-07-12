# input format
# n, m - число вершин и ребер
# A B - ребро
# B C - ребро
# ... - и т.д.


def read_to_matrix():
    '''
    осуществляет считывание в матрицу смежности
    возвращает матрицу смежности
    '''
    n, m = [int(x) for x in input().split()]
    # V = []  # список вершин
    # index = {}  # словарь {имя вершины -> ее индекс}
    A = [[0] * n for i in range(n)]  # матрица смежности

    # если списки заданы именами(строками)
    for i in range(m):
        v1, v2 = [int(x) for x in input().split()]
        # for v in v1, v2:
        #     if v not in index:
        #         V.append(v)
        #         index[v] = len(V) - 1
        # v1_i = index[v1]
        # v2_i = index[v2]
        # A[v1_i][v2_i] = 1
        # A[v2_i][v1_i] = 1
        A[v1][v2] = 1
        A[v2][v1] = 1
    return A


def read_to_adj_list():
    '''
    считывание в список смежности
    :return: список смежности
    '''
    n, m = [int(x) for x in input().split()]
    G = {}
    for i in range(m):
        v1, v2 = input().split()
        for v, u in (v1, v2), (v2, v1):
            if v not in G:
                G[v] = {u}
            else:
                G[v].add(u)
    return G


def main():
    A = read_to_adj_list()
    for v in A:
        print('{} : {}'.format(v, A[v]))


if __name__ == '__main__':
    main()
