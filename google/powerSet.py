import math

def powerSet(array):
    powerSet = []
    total = int(math.pow(2, len(array)))

    for i in range(0, total):
        temporarySet = []
        numbers = "{0:b}".format(i)

        while len(numbers) < len(array):
            numbers = "0" + numbers

        for j in range(0, len(numbers)):
            if numbers[j] == "1":
                temporarySet.append(array[j])

        powerSet.append(temporarySet)

    return powerSet

'''
0 = 000
1 = 001
2 = 010
3 = 011
4 = 100
5 = 101
6 = 110
7 = 111
'''


'''
000 = [exclude, exclude, exclude] = []
001 = [exclude, exclude, include] = [3]
010 = [exclude, include, exclude] = [2]
011 = [exclude, include, include] = [2, 3]
100 = [include, exclude, exclude] = [1]
101 = [include, exclude, include] = [1, 3]
110 = [include, include, exclude] = [1, 2]
111 = [include, include, include] = [1, 2, 3]
'''
