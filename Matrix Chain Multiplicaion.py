import sys

def matrixMultiplyRec(matrix, i, j):

    __min = sys.maxsize

    if i == j:
        return 0
    for k in range(i, j):
        count = matrixMultiplyRec(matrix, i, k) + matrixMultiplyRec(matrix, k+1, j) + matrix[i-1]*matrix[k]*matrix[j]

    if count < __min:
        __min = count

    return __min

def matrixMultiply(matrix):

    n = len(matrix)-1
    table1 = [[0 for x in range(n)] for x in range(n)]
    table2 = [[0 for x in range(n-1)] for x in range(n-1)]