class coin_change:
    def recursive_change(self, coins, num_coin, target):
        if target == 0:
            return 1
        if target < 0:
            return 0
        if num_coin <= 0 and target >= 1:
            return 0

        return recursive_change(coins, num_coin - 1, target) + recursive_change(coins, 
                                                                num_coin, target-coins[num_coin-1])

    def Dynamic_change(self, coins, num_coin, target):
        table = [[0 for x in range(num_coin)] for x in range(target+1)]

        for i in range(num_coin):
            table[0][i] = 1

        for i in range(1, target+1):
            for j in range(num_coin):
                x = table[i - coins[j]][j] if i-coins[j] >= 0 else 0
                y = table[i][j-1] if j >= 1 else 0
                table[i][j] = x + y

        return table[target][num_coin-1]


'''arr = [1, 2, 3]
coins = len(arr)
print(recursive_change(arr, coins, 4))
'''
def main():
    x = coin_change()
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
        print("Case ", i, ": ", x.recursive_change(coins, num_coin, target), x.Dynamic_change(coins, 
                                                                                        num_coin, target))
        i += 1

if __name__ == "__main__":
    main()