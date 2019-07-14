def mergeSort(A):
    n = len(A)
    if n <= 1:
        return A
    middle = n // 2
    L = mergeSort(A[:middle])
    R = mergeSort(A[middle:])
    return merge(L, R)


def merge(left, right):
    res = []
    i, j = 0, 0
    while i < len(left) or j < len(right):
        if j == len(right) or (i < len(left) and left[i] < right[j]):
            res.append(left[i])
            i += 1
        else:
            res.append((right[j]))
            j += 1
    return res


def main():
    A = [2, 7, 6, 3, 5, 4, 1]
    print(A)
    print(mergeSort(A))


if __name__ == "__main__":
    main()
