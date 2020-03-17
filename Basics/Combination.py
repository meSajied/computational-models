from itertools import combinations

class CombinIter:
	def byIter(self=None):
		for i in list(combinations(["A", "B", "C"], 2)):
			print(i)

def main():
	CombinIter.byIter()




main()