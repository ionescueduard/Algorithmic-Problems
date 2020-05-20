def clean(vec):
	if len(vec) < 2:
		return 
	while vec[-1] > vec[0]:
		vec.pop(0)

def maxOfWindows(input, k):
	rez = []
	tmp = []
	for x in input[:k]:
		tmp.append(x)
		clean(tmp)
	rez.append(tmp[0])

	for x in input[k:]:
		if len(tmp) == k:
			tmp = tmp[1:]
		tmp.append(x)
		clean(tmp)
		rez.append(tmp[0])
	return rez	
        
if __name__ == '__main__':
	print(maxOfWindows([10, 5, 2, 7, 6, 8, 7], 3))
	print(maxOfWindows([10, 9, 8, 7, 6, 5, 4, 3], 3))