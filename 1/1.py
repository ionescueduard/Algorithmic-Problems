def isPair(v, k):
    elmementsSet = set()
    for el in v:
        if el in elmementsSet:
            return True
        if el >= k:
            continue
        elmementsSet.add(k - el)
    return False


if __name__ == '__main__':
    t1 = ([13, 5, 7, 10], 17)
    t2 = ([], 0)
    t3 = ([13, 5, 7, 10, 11, 6, 23], 35)

    for (v,k) in [t1, t2, t3]:
        print(isPair(v, k))