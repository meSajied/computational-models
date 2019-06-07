import math

def powerSet(array):

    # the final power set...
    powerSet = []

    # the total number of sets that the power set will contain
    total = int(math.pow(2, len(array)))

    # loop through each value from 0 to 2^n
    for i in range(0, total):

        # temporary set that will add to total
        temporarySet = []

        # convert the integer to binary
        numbers = "{0:b}".format(i)

        # pad the binary number so 1 becomes 001 for example
        while len(numbers) < len(array):
            numbers = "0" + numbers

        # build the set that matches the 1's in the binary number
        for j in range(0, len(numbers)):

            if numbers[j] == "1":
                temporarySet.append(array[j])

        powerSet.append(temporarySet)

    return powerSet


def main():

    print(powerSet([1, 2, 3]))

main()

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