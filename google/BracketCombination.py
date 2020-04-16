arr = []

def bracket(left, right, string):

	#arr = []

	if left == 0 and right == 0:
		arr.append(string)

	if left > 0:
		bracket(left-1, right+1, string+"(")

	if right > 0:
		bracket(left, right-1, string+")")
