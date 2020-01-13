def solve(s, k):
    chSet = set()
    chSet.add(s[0])
    first = 0
    charCount = 1
    max = -1
    for i, ch in enumerate(s[1:]):
        if ch in chSet:
            charCount += 1
            if max < charCount:
                max = charCount
            continue
        if len(chSet) < k:
            chSet.add(ch)
            charCount += 1
            if max < charCount:
                max = charCount
            continue
        for j in range(i, first - 1 , -1):
            if s[j] == s[first]:
                break
        if j == first:
            chSet.remove(s[first])
            chSet.add(ch)
            first += 1
        else:
            chSet = {ch}
            charCount = 1
            for p in range(i, j, -1):
                chSet.add(s[p])
                charCount += 1
            first = j+1
    return max

if __name__ == '__main__':
    s = 'ababcdddccbba'
    k = 3

    print(solve(s,k))