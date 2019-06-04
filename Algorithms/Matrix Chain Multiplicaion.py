import sys

def matrixMultiplyRec(matrix, i, j):

    __min = sys.maxsize

    if i == j:
        return 0
    for k in range(i, j):
        count = matrixMultiplyRec(matrix, i, k) + matrixMultiplyRec(matrix, k+1, j) + matrix[i-1]*matrix[k]*matrix[j]

    if count < __min:
        min = count

    return __min

def matrixMultiply(matrix):
    pass