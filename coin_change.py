def recursive_coin_change(solution, coins, target):

    
    if target == 0:
        return 1


    if target < 0:
        return 0

    if coins <= 0 and target >= 1:
        return 0

    return recursive_coin_change(solution, coins - 1, target) + recursive_coin_change(solution, coins, target-solution[coins-1])

def Dynamic_coin_change(solution, coins, target):

    table = [[0 for x in range(coins)] for x in range(target+1)]

    for i in range(coins):
        table[0][i] = 1

    for i in range(1, target+1):
        for j in range(coins):
            x = table[i - solution[j]][j] if i-solution[j] >= 0 else 0
            y = table[i][j-1] if j >= 1 else 0
            table[i][j] = x + y

    return table[target][coins-1]


'''arr = [1, 2, 3]
coins = len(arr)
print(recursive_coin_change(arr, coins, 4))
'''
def main():

    i = 1

    coins = list()
    test = int(input())
    #print(test)

    while i <= test:

        #print(i)
        num_coin = int(input())
        target = int(input())
        #print(num_coin, target)
        #print(target)

        for j in range(num_coin):
            x = int(input())
            coins.insert(j, x)
            j += 1
        #print(coins)

        #coinLength = len(coins)
        #print(coinLength)
        print("Case ", i, ": ", recursive_coin_change(coins, num_coin, target), Dynamic_coin_change(coins, num_coin, target))
        i += 1


main()