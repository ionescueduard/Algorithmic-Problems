
def isSubsetSum(vect ,n ,totalSum):
    mat = [[False for _ in range(totalSum + 1)] for _ in range(n + 1)]

    for i in range(n + 1):
        mat[i][0] = True

    for i in range(1, n + 1):
        for sum in range(1, totalSum + 1):
            if vect[i-1] > sum:
                mat[i][sum] = mat[i-1][sum]
            else:
                mat[i][sum] = mat[i-1][sum] or mat[i-1][totalSum - sum]
    return mat[n][totalSum]

def isTwoEqualSubSets(vect):
    elementsSum = sum(vect)

    # if the sum is not divisible by 2, there doesn't exist any 2 equal value subsets
    if elementsSum / 2 != elementsSum // 2:
        return False
    return isSubsetSum(vect, len(vect), elementsSum // 2)


if __name__ == '__main__':
    v1 = [2, 7, 11, 3, 9, 3, 5]       # True
    v2 = [2, 7, 11, 3, 9, 3]          # False
    v3 = [15, 5, 20, 10, 35, 15, 10]  # True
    v4 = [15, 5, 20, 10, 35]          # False

    for vect, groundTruth in [[v1,True], [v2, False], [v3, True], [v4, False]]:
        print(groundTruth, end='  -->  ')
        print(isTwoEqualSubSets(vect))


