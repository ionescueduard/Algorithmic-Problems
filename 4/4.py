

def reformat(v):
    firstNeg = len(v) - 1
    while firstNeg > -1 and v[firstNeg] < 0:
        firstNeg -= 1
    if firstNeg == -1:
        return -1

    i = 0
    while i < firstNeg:
        while v[i] >= 0 and i < firstNeg:
            i += 1
        if i == firstNeg:
            return i + 1

        tmp = v[firstNeg]
        v[firstNeg] = v[i]
        v[i] = tmp
        i += 1
        firstNeg -= 1

    return i



def getFirstIntPos(v):
    pos = reformat(v)
    if pos == -1:
        return 1
    v = v[0:pos]

    for i in range(pos):
        if abs(v[i]) < pos:
            v[abs(v[i]) - 1] *= -1

    for i, el in enumerate(v):
        if el > 0:
            return i + 1

    return pos + 1


if __name__ == '__main__':
    v = [3, 4, 8, -1, 1, 5, 2, 9, 6, 7]

    print(getFirstIntPos(v))