import sys

class MatrixChainMultiplication:
    def recursive(self, matrix:list, i:int, j:int)->int:
        __min = sys.maxsize
        if i == j:
            return 0

        for k in range(i, j):
            count = self.recursive(matrix, i, k) + self.recursive(matrix, 
                                                            k+1, j) + matrix[i-1]*matrix[k]*matrix[j]

        if count < __min:
            __min = count

        return __min

    def dynamic(self, matrix:int)->int:
        n = len(matrix)
        minCost = [[0 for x in range(n)] for x in range(n)]

        for i in range(1, n):
            minCost[i][i] = 0

        for chainLength in range(2, n):
            for i in range(1, n-chainLength+1):
                j = i + chainLength - 1
                minCost[i][j] = sys.maxsize
                for k in range(i, j):
                    count = minCost[i][k] + minCost[k+1][j] + matrix[i-1]*matrix[k]*matrix[j]
                    if count < minCost[i][j]:
                        minCost[i][j] = count
                        print(minCost[i][j])

        return minCost[i][j]

    def parenthesize(self, numMatrices):
        if numMatrices == 1:
            return
            
        for k in range(2, numMatrices-1):
            parenthesize(k)*parenthesize(numMatrices-k)