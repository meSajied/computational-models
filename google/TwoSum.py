# our two sum function which will return
# all pairs in the list that sum up to S

def twoSum(array, S):

    sums = []

    # check each element in array

    for i in range(0, len(array)):
        # check each other element in the array
        for j in range(i+1, len(array)):
            # determine if these two elements sum to S
            if(array[i] + array[j] == S):
                sums.append(array[i], array[j])

    return sums

def main():

    print(twoSum([3, 5, 2, -4, 8, 11], 7))

main()