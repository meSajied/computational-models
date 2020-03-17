from itertools import permutations

class PermuteIter:
    def byIter(self):
        for i in list(permutations(["A", "B", "C"])):
        	  print(i)

#PermuteIter.byIter()

class PermuteCode:

    def toString(list):
       return "".join(list)

    def permute(string, lower, upper):
       if lower == upper:
          print(PermuteCode.toString(string))

       else:
          for i in range(lower, upper+1):
              string[lower], string[i] = string[i], string[lower]
              PermuteCode.permute(string, lower+1, upper)
              string[lower], string[i] = string[i], string[lower]


def main(self=None):
    PermuteIter.byIter(self)
    string = "ABC"
    n = len(string)
    a = list(string)
    PermuteCode.permute(a, 0, n-1)

main()